/******************************************************************************

                               Copyright (c) 2011
                            Lantiq Deutschland GmbH
                     Am Campeon 3; 85579 Neubiberg, Germany

  For licensing information, see the file 'LICENSE' in the root folder of
  this software module.

******************************************************************************/

/* ==========================================================================
   Description : Vinax device specific functions for the MEI CPE Driver
   ========================================================================== */

/* ============================================================================
   Includes
   ========================================================================= */

/* get at first the driver configuration */
#include "drv_mei_cpe_config.h"

#if (MEI_SUPPORT_DEVICE_VINAX == 1)

#include "ifx_types.h"
#include "drv_mei_cpe_os.h"
#include "drv_mei_cpe_dbg.h"

#include "drv_mei_cpe_interface.h"
#include "drv_mei_cpe_mei_interface.h"
#include "drv_mei_cpe_api.h"

#include "drv_mei_cpe_mailbox.h"
#include "drv_mei_cpe_msg_process.h"
#include "drv_mei_cpe_device_cntrl.h"

#if (MEI_SUPPORT_ROM_CODE == 1)
#include "drv_mei_cpe_rom_handler_if.h"
#include "drv_mei_cpe_rom_handler.h"
#endif      /* MEI_SUPPORT_ROM_CODE */

#if (MEI_SUPPORT_DRIVER_MSG == 1)
#include "drv_mei_cpe_driver_msg.h"
#endif

/**
   Process the GP1 interrupt - ROM Code has been entered.
   - check HW availability
   - check current driver state
     --> reset driver structure if necessary

\param
   pDev  private device data

*/
static IFX_int32_t MEI_GP1IntProcess(MEI_DEV_T *pMeiDev)
{
   IFX_int32_t       ret = IFX_SUCCESS;
   MEI_DRV_STATE_E enterDrvState;

   enterDrvState = MEI_DRV_STATE_GET(pMeiDev);

   /*
      Check MEI HW register
   */
   if ( MEI_MeiRegisterDetect(pMeiDev) == IFX_SUCCESS )
   {
      /*
         MEI access successful - check state
      */

      if ( (enterDrvState == e_MEI_DRV_STATE_SW_INIT_DONE) ||
           (enterDrvState == e_MEI_DRV_STATE_BOOT_WAIT_ROM_ALIVE) )
      {
         /* do nothing - normal startup */
         PRN_DBG_INT( MEI_DRV, MEI_DRV_PRN_LEVEL_NORMAL, MEI_DRV_LINENUM_GET(pMeiDev),
              ("MEI_DRV[%02d]: GP INT1 occurred - %s" MEI_DRV_CRLF,
              MEI_DRV_LINENUM_GET(pMeiDev),
              (pMeiDev->bUsrRst)? "User Reset" : "Startup" ));

         ret = IFX_SUCCESS;
         goto MEI_GP1_INT_PROCESS_DONE;
      }
   }

   /*
      GP1 interrupt while normal processing - no startup
      - reset driver settings
   */

   MEI_DRV_STATE_SET(pMeiDev, e_MEI_DRV_STATE_DFE_RESET);

   /* reset the current driver struct */
   MEI_ResetDrvStruct( pMeiDev, 0); /* int level: do not free FW image */

   if (MEI_DRV_MEI_IF_STATE_GET(pMeiDev) == e_MEI_MEI_HW_STATE_UP)
   {
      /* FW failure */
      PRN_ERR_INT_NL( MEI_DRV, MEI_DRV_PRN_LEVEL_ERR,
           ("MEI_DRV[%02d]: GP INT1 occurred - RESET: FW Failure !!!" MEI_DRV_CRLF,
           MEI_DRV_LINENUM_GET(pMeiDev)));

      /* FW failure --> go back to init state */
      MEI_DRV_STATE_SET(pMeiDev, e_MEI_DRV_STATE_SW_INIT_DONE);

      ret = IFX_SUCCESS;
   }
   else
   {
      /* MEI HW interface is down - fatal error */
      ret = IFX_ERROR;
   }


MEI_GP1_INT_PROCESS_DONE:

   if (ret == IFX_SUCCESS)
   {
      /* Release Interrupt */
      MEI_ReleaseRomInt(&pMeiDev->meiDrvCntrl);
   }
   else
   {
      /* MEI HW failure */
      PRN_ERR_INT_NL( MEI_DRV, MEI_DRV_PRN_LEVEL_ERR,
           ("MEI_DRV[%02d]: GP INT1 occurred, RESET - MEI IF failure (mask Int)!!!" MEI_DRV_CRLF,
           MEI_DRV_LINENUM_GET(pMeiDev)));

      /* block all interrupts and stay in the reset state */
      MEI_DisableDeviceInt(pMeiDev);
   }

#if (MEI_SUPPORT_DRIVER_MSG == 1)
    MEI_DrvMsg_RomStartDistribute(pMeiDev, enterDrvState);
#endif

   /* User reset processed */
   pMeiDev->bUsrRst = IFX_FALSE;

   return ret;
}

IFX_int32_t MEI_GPIntProcess(MEI_MeiRegVal_t processInt, MEI_DEV_T *pMeiDev)
{
   IFX_int32_t processCnt = 0;

   /* VINAX reset - startup / watchdog reset */
   if (processInt & ME_ARC2ME_STAT_ARC_GP_INT1)
   {
      processCnt++;

      MEI_IF_STAT_INC_GP1_INT_COUNT(pMeiDev);

#if ((MEI_SUPPORT_STATISTICS == 1) && 0)
      PRN_DBG_INT( MEI_DRV, MEI_DRV_PRN_LEVEL_NORMAL, MEI_DRV_LINENUM_GET(pMeiDev),
           ("MEI_DRV[%02d]: +++ GP1 count = %d +++\n\r",
            MEI_DRV_LINENUM_GET(pMeiDev), pMeiDev->statistics.dfeGp1IntCount));
#endif

      if ( MEI_GP1IntProcess(pMeiDev) != IFX_SUCCESS)
      {
         /* HW failure
            --> cancel the other interrupts
            --> interrupts are blocked
            --> driver is in reset state
         */
         return IFX_ERROR;
      }
   }

   if (processInt & ME_ARC2ME_STAT_ARC_GP_INT0)
   {
      PRN_ERR_INT_NL( MEI_DRV, MEI_DRV_PRN_LEVEL_ERR,
           ("MEI_DRV[%02d]: - GP INT0 occurred --> FW generated" MEI_DRV_CRLF,
           MEI_DRV_LINENUM_GET(pMeiDev)));
   }

   return processCnt;
}

/**
   Check the given device boot mode and set the corresponding setting
   within the driver.

\param
   T_MEIX_DEV *pDev  private device data

\return
   IFX_SUCCESS - valid mode is set else
   IFX_ERROR   - set the driver bootmode to invalid.

\remark
   Valid Driver bootmodes are:
      e_MEI_DRV_BOOT_MODE_AUTO
      e_MEI_DRV_BOOT_MODE_7
   No valid bootmode:
      e_MEI_DRV_BOOT_MODE_INVALID

*/
IFX_uint32_t MEI_SetDriverBootMode(
                                 MEI_DEV_T *pMeiDev)
{
   switch(pMeiDev->modemData.devBootMode)
   {
      case MEI_DEV_BOOT_MODE_FWDL_ROM_DMA_CS:
         MEI_DRV_BOOTMODE_SET(pMeiDev, e_MEI_DRV_BOOT_MODE_7);
         break;

      case MEI_DEV_BOOT_MODE_FWDL_ROM_START_SRAM:
      case MEI_DEV_BOOT_MODE_FWDL_ROM_START_EXT_RAM:
      case MEI_DEV_BOOT_MODE_FWDL_HOST:
         PRN_ERR_USR_NL( MEI_DRV, MEI_DRV_PRN_LEVEL_ERR,
              ("MEI_DRV[%02d]: ERROR - boot mode (0x%02X) not supported!" MEI_DRV_CRLF,
                MEI_DRV_LINENUM_GET(pMeiDev), pMeiDev->modemData.devBootMode));

         MEI_DRV_BOOTMODE_SET(pMeiDev, e_MEI_DRV_BOOT_MODE_INVALID);
         break;

      default:
         PRN_ERR_USR_NL( MEI_DRV, MEI_DRV_PRN_LEVEL_WRN,
              ("MEI_DRV[%02d]: Boot mode (0x%02X) - autonomous" MEI_DRV_CRLF,
                MEI_DRV_LINENUM_GET(pMeiDev), pMeiDev->modemData.devBootMode));
         MEI_DRV_BOOTMODE_SET(pMeiDev, e_MEI_DRV_BOOT_MODE_AUTO);
         break;
   }

   return (MEI_DRV_BOOTMODE_GET(pMeiDev) == e_MEI_DRV_BOOT_MODE_INVALID) ? IFX_ERROR : IFX_SUCCESS;
}

/**
   Read the Chip Info Register from the VINAX devcie.
   - Register offset 0x40 CHIPCFG
   - baseaddress: 0x000E2000 - 0x000E20FF

\param
   pMeiDev  points to the device data

\return
   IFX_SUCCESS - CHIP info available and valid.
   IFX_ERROR   - invalid/not supported bootmode.
*/
IFX_int32_t MEI_GetChipInfo(MEI_DEV_T *pMeiDev)
{
   IFX_uint32_t chipCfg;

   /* read 32 bit DMA */
   MEI_ReadDma32Bit( &pMeiDev->meiDrvCntrl,
                     (MEI_PERIPHERAL_CONFIG_OFF + MEI_CHIPCFG_REG_OFF),
                     &chipCfg, 1);

   pMeiDev->modemData.chipId      = (IFX_uint8_t)MEI_CHIPCFG_CHIP_ID_GET(chipCfg);
   pMeiDev->modemData.devBootMode = (IFX_uint8_t)MEI_CHIPCFG_BTCFG_GET(chipCfg);
   pMeiDev->modemData.hwVersion   = (IFX_uint8_t)MEI_CHIPCFG_HW_VER_GET(chipCfg);

   PRN_DBG_USR( MEI_DRV, MEI_DRV_PRN_LEVEL_NORMAL, MEI_DRV_LINENUM_GET(pMeiDev),
          ( "MEI_DRV[%02d]: ChipInfo (0x%08X) - "
            "CHIP_ID = 0x%02X, BTCFG = 0x%02X, ME_MODE = 0x%02X" MEI_DRV_CRLF,
            MEI_DRV_LINENUM_GET(pMeiDev), chipCfg,
            pMeiDev->modemData.chipId, pMeiDev->modemData.devBootMode,
            MEI_CHIPCFG_MEMODE_GET(chipCfg) ));

   /* update with driver settings if highest bit is set */
   if (MEI_BootMode & 0x80)
   {
      pMeiDev->modemData.devBootMode = MEI_BootMode & 0x7F;

      PRN_DBG_USR( MEI_DRV, MEI_DRV_PRN_LEVEL_NORMAL, MEI_DRV_LINENUM_GET(pMeiDev),
             ( "MEI_DRV[%02d]: !!! change bootmode --> 0x%02X to local settings !!" MEI_DRV_CRLF,
               MEI_DRV_LINENUM_GET(pMeiDev), pMeiDev->modemData.devBootMode ));
   }

   if (MEI_SetDriverBootMode(pMeiDev) == IFX_SUCCESS)
   {
      if (MEI_DRV_BOOTMODE_GET(pMeiDev) == e_MEI_DRV_BOOT_MODE_7)
      {
         if ( !(MEI_MaxWaitForModemReady_ms & MEI_CFG_DEF_WAIT_PROTECTION_FLAG) )
         {
            /* for bootmode 7 - increase the waittime for the modem ready message */
            MEI_MaxWaitForModemReady_ms = MEI_CFG_DEF_WAIT_FOR_MODEM_READY_BM7_SEC;
         }
         else
         {
            PRN_DBG_USR( MEI_DRV, MEI_DRV_PRN_LEVEL_NORMAL, MEI_DRV_LINENUM_GET(pMeiDev),
                ( "MEI_DRV[%02d]: BM7 keep Modem Ready timeout = 0x%X !!\n\r",
                  MEI_DRV_LINENUM_GET(pMeiDev), MEI_MaxWaitForModemReady_ms ));
         }
      }
   }
   else
   {
      return IFX_ERROR;
   }

   return IFX_SUCCESS;
}

#endif /* (MEI_SUPPORT_DEVICE_VINAX == 1)*/

