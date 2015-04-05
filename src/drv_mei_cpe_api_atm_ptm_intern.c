/******************************************************************************

                               Copyright (c) 2011
                            Lantiq Deutschland GmbH
                     Am Campeon 3; 85579 Neubiberg, Germany

  For licensing information, see the file 'LICENSE' in the root folder of
  this software module.

******************************************************************************/

/* ==========================================================================
   Description : VINAX Driver internal function interface
   ========================================================================== */

/* ============================================================================
   Includes
   ========================================================================= */

/* get at first the driver configuration */
#include "drv_mei_cpe_config.h"

#if (MEI_EXPORT_INTERNAL_API == 1) && (MEI_DRV_ATM_PTM_INTERFACE_ENABLE == 1)

#include "ifx_types.h"
#include "drv_mei_cpe_os.h"

#ifdef LINUX
   #include <asm/ifx/ifx_atm.h>
#else
   #error "ATM/PTM internal interface is only supported for Linux!"
#endif

/** get interface and configuration */
#include "drv_mei_cpe_interface.h"
#include "drv_mei_cpe_api.h"
#include "drv_mei_cpe_api_atm_ptm_intern.h"
#include "drv_mei_cpe_download.h"

static unsigned int g_tx_link_rate[MEI_MAX_DFE_CHAN_DEVICES][2] = {{0}};
void *g_xdata_addr[MEI_MAX_DFE_CHAN_DEVICES] = {NULL};


#if (MEI_MAX_DFE_CHAN_DEVICES > 1)
#undef MEI_MAX_DFE_CHAN_DEVICES
#define MEI_MAX_DFE_CHAN_DEVICES 1
#endif /*TEMPORARY SOLUTION, TO BE REMOVED!!!*/

/* ============================================================================
   Exported functions
   ========================================================================= */

#if (MEI_MAX_DFE_CHAN_DEVICES > 1)
int (*ifx_mei_atm_showtime_line_enter)(unsigned char line_num, struct port_cell_info *, void *) = NULL;
int (*ifx_mei_atm_showtime_line_exit)(unsigned char line_num) = NULL;

#define MEI_ATM_SHOWTIME_ENTER_FN   ifx_mei_atm_showtime_line_enter
#define MEI_ATM_SHOWTIME_EXIT_FN    ifx_mei_atm_showtime_line_exit

#define MEI_ATM_SHOWTIME_ENTER(line, cell, xdata) \
           ifx_mei_atm_showtime_line_enter(line, cell, xdata)

#define MEI_ATM_SHOWTIME_EXIT(line) \
           ifx_mei_atm_showtime_line_exit(line)

#else

#define MEI_ATM_SHOWTIME_ENTER_FN   ifx_mei_atm_showtime_enter
#define MEI_ATM_SHOWTIME_EXIT_FN    ifx_mei_atm_showtime_exit

int (*ifx_mei_atm_showtime_enter)(struct port_cell_info *, void *) = NULL;
int (*ifx_mei_atm_showtime_exit)(void) = NULL;
#define MEI_ATM_SHOWTIME_ENTER(line, cell, xdata) \
           line == 0 ? \
           ifx_mei_atm_showtime_enter(cell, xdata) : \
           ((void)0)

#define MEI_ATM_SHOWTIME_EXIT(line) \
           line == 0 ? \
           ifx_mei_atm_showtime_exit() : \
           ((void)0)

#endif /* #if (MEI_MAX_DFE_CHAN_DEVICES > 1)*/



IFX_int32_t MEI_InternalXtmSwhowtimeEntrySignal(
                              MEI_DYN_CNTRL_T         *pMeiDynCntrl,
                              MEI_XTM_ShowtimeEnter_t *pArgXtm)
{
   IFX_int32_t retVal = IFX_SUCCESS;
   struct port_cell_info port_cell = {0};
   IFX_uint8_t dslLineNum;

   if (!pMeiDynCntrl || !pArgXtm)
      return -e_MEI_ERR_GET_ARG;

   /* Get line number*/
   dslLineNum = pMeiDynCntrl->pMeiDev->meiDrvCntrl.dslLineNum;

   if (pArgXtm->rate_fast)
   {
     g_tx_link_rate[dslLineNum][0] = pArgXtm->rate_fast / (53 * 8);
   }

   if (pArgXtm->rate_intl)
   {
      g_tx_link_rate[dslLineNum][1] = pArgXtm->rate_intl / (53 * 8);
   }

   if (g_tx_link_rate[dslLineNum][0] == 0 && g_tx_link_rate[dslLineNum][1] == 0)
   {
      retVal = -e_MEI_ERR_INVAL_CONFIG;
   }

   if (MEI_ATM_SHOWTIME_ENTER_FN)
   {
      port_cell.port_num = 2;
      port_cell.tx_link_rate[0] = g_tx_link_rate[dslLineNum][0];
      port_cell.tx_link_rate[1] = g_tx_link_rate[dslLineNum][1];

      MEI_ATM_SHOWTIME_ENTER(dslLineNum, &port_cell, g_xdata_addr[dslLineNum]);
   }
   else
   {
      retVal = -e_MEI_ERR_OP_FAILED;
   }

   return retVal;
}

IFX_int32_t MEI_InternalXtmSwhowtimeExitSignal(
                              MEI_DYN_CNTRL_T        *pMeiDynCntrl,
                              MEI_XTM_ShowtimeExit_t *pArgXtm)
{
   IFX_int32_t retVal = IFX_SUCCESS;
   IFX_uint8_t dslLineNum;

   if (!pMeiDynCntrl || !pArgXtm)
      return -e_MEI_ERR_GET_ARG;

   /* Get line number*/
   dslLineNum = pMeiDynCntrl->pMeiDev->meiDrvCntrl.dslLineNum;

   if (MEI_ATM_SHOWTIME_EXIT_FN)
   {
      MEI_ATM_SHOWTIME_EXIT(dslLineNum);
   }
   else
   {
      retVal = -e_MEI_ERR_OP_FAILED;
   }

   return retVal;
}

int ifx_mei_atm_showtime_check(
                              #if (MEI_MAX_DFE_CHAN_DEVICES > 1)
                              unsigned char line_num,
                              #endif /* #if (MEI_MAX_DFE_CHAN_DEVICES > 1)*/
                              int *is_showtime,
                              struct port_cell_info *port_cell,
                              void **xdata_addr)
{
   unsigned int i;
#if (MEI_MAX_DFE_CHAN_DEVICES == 1)
   unsigned char line_num = 0;
#endif /* #if (MEI_MAX_DFE_CHAN_DEVICES > 1)*/

   if (line_num >= MEI_MAX_DFE_CHAN_DEVICES)
   {
      return -1;
   }

   if (is_showtime)
   {
     *is_showtime = g_tx_link_rate[line_num][0] == 0 && g_tx_link_rate[line_num][1] == 0 ? 0 : 1;
   }

   if (port_cell)
   {
      for ( i = 0; i < port_cell->port_num && i < 2; i++ )
      {
         port_cell->tx_link_rate[i] = g_tx_link_rate[line_num][i];
      }
   }

   if (xdata_addr)
   {
      if (g_tx_link_rate[line_num][0] == 0 && g_tx_link_rate[line_num][1] == 0)
      {
         *xdata_addr = NULL;
      }
      else
      {
         *xdata_addr = g_xdata_addr[line_num];
      }
   }

   return 0;
}

int ifx_mei_atm_led_blink(void)
{
    return IFX_SUCCESS;
}

EXPORT_SYMBOL (MEI_InternalXtmSwhowtimeEntrySignal);
EXPORT_SYMBOL (MEI_InternalXtmSwhowtimeExitSignal);

EXPORT_SYMBOL(MEI_ATM_SHOWTIME_ENTER_FN);
EXPORT_SYMBOL(MEI_ATM_SHOWTIME_EXIT_FN);
EXPORT_SYMBOL(ifx_mei_atm_showtime_check);
EXPORT_SYMBOL(ifx_mei_atm_led_blink);

#endif      /* #if (MEI_EXPORT_INTERNAL_API == 1) && (MEI_DRV_ATM_PTM_INTERFACE_ENABLE == 1) */

