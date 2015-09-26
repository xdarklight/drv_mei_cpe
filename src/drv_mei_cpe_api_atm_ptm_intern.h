/******************************************************************************

                              Copyright (c) 2014
                            Lantiq Deutschland GmbH

  For licensing information, see the file 'LICENSE' in the root folder of
  this software module.

******************************************************************************/
#ifndef _DRV_MEI_CPE_API_ATM_PTM_INTERN_H
#define _DRV_MEI_CPE_API_ATM_PTM_INTERN_H

/* ============================================================================
   Description : MEI CPE Driver internal API for ATM/PTM kernel drivers
   ========================================================================= */

/* ==========================================================================
   includes
   ========================================================================== */
#include "ifx_types.h"

#include "drv_mei_cpe_config.h"
#include "drv_mei_cpe_interface.h"
#include <net/ppa_stack_al.h>

#if (MEI_EXPORT_INTERNAL_API == 1) && (MEI_DRV_ATM_PTM_INTERFACE_ENABLE == 1)

typedef struct {
   unsigned int rate_fast;
   unsigned int rate_intl;
} MEI_XTM_ShowtimeEnter_t;

typedef struct {
   unsigned int dummy;
} MEI_XTM_ShowtimeExit_t;

extern IFX_int32_t MEI_InternalXtmSwhowtimeEntrySignal(
                              MEI_DYN_CNTRL_T        *pMeiDynCntrl,
                              MEI_XTM_ShowtimeEnter_t *pArgXtm);

extern IFX_int32_t MEI_InternalXtmSwhowtimeExitSignal(
                              MEI_DYN_CNTRL_T        *pMeiDynCntrl,
                              MEI_XTM_ShowtimeExit_t *pArgXtm);

extern int ppa_callback_set(e_ltq_mei_cb_type type, void *func);
extern void* ppa_callback_get(e_ltq_mei_cb_type type);

int ltq_mei_atm_showtime_check(
                              const unsigned char line_idx,
                              int *is_showtime,
                              struct port_cell_info *port_cell,
                              void **xdata_addr);

#endif      /* #if (MEI_EXPORT_INTERNAL_API == 1) && (MEI_DRV_ATM_PTM_INTERFACE_ENABLE == 1) */

#endif      /* #ifndef _DRV_MEI_CPE_API_ATM_PTM_INTERN_H */

