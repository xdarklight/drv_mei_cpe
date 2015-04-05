/******************************************************************************

                               Copyright (c) 2011
                            Lantiq Deutschland GmbH
                     Am Campeon 3; 85579 Neubiberg, Germany

  For licensing information, see the file 'LICENSE' in the root folder of
  this software module.

******************************************************************************/
#ifndef _DRV_MEI_CPE_DOWNLOAD_VINAX_COMMON_H
#define _DRV_MEI_CPE_DOWNLOAD_VINAX_COMMON_H

/* ==========================================================================
   Description : VINAX Firmware Download definitions (ROM START).
   ========================================================================== */

#ifdef __cplusplus
extern "C"
{
#endif

/* get config */
#include "drv_mei_cpe_config.h"
#if (MEI_SUPPORT_DL_DMA_CS == 1)

/* ============================================================================
   Inlcudes
   ========================================================================= */

#include "ifx_types.h"
#include "drv_mei_cpe_api.h"


/* ============================================================================
   Macros
   ========================================================================= */

#define MEI_MAX_CODE_PAGESIZE_WORD 0x8000
#define MEI_MAX_DATA_PAGESIZE_WORD 0x8000

#define MEI_MAX_TIME_CODESWAP_MS   75


/**
   set new state within the VINAX download control struct (DMA, CS).
*/
#define MEI_FWDL_DMA_SET_STATE(p_vnx_dl_cntrl, new_state) \
                        (p_vnx_dl_cntrl)->fwDlState = new_state

/**
   get current state within the VINAX download control struct (DMA, CS).
*/
#define MEI_FWDL_DMA_GET_STATE(p_vnx_dl_cntrl) (p_vnx_dl_cntrl)->fwDlState

/* ============================================================================
   Exports
   ========================================================================= */
extern MEI_FW_IMAGE_T ChipFwImage[];

extern IFX_void_t MEI_DlDataClear(MEI_DEV_T *pMeiDev);

extern IFX_int32_t MEI_CheckCsPage(
                              MEI_DEV_T    *pMeiDev,
                              IFX_uint32_t   pageIndex,
                              IFX_boolean_t  bData);

extern IFX_int32_t MEI_FDOnAck_ONLINESTATEACTIVATE(
                              MEI_DEV_T       *pMeiDev,
                              MEI_Mailbox_t   *pBootMsg );

extern IFX_int32_t MEI_ProcessCodeSwapRequest(
                              MEI_DEV_T       *pMeiDev,
                              CMV_MESSAGE_CS_T  *pCmvCsMsg);

extern IFX_int32_t MEI_StartDmaCsDl(
                              MEI_DEV_T *pMeiDev);

extern IFX_void_t MEI_Recv_CODE_SWAP_REQ(
                              MEI_DEV_T *pMeiDev,
                              IFX_uint16_t mbCode);

extern IFX_void_t MEI_DEV_FirmwareDownloadResourcesRelease(
                                 MEI_DEV_T       *pMeiDev);


extern IFX_int32_t MEI_DEV_IoctlFirmwareDownload(
                              MEI_DYN_CNTRL_T        *pMeiDynCntrl,
                              IOCTL_MEI_fwDownLoad_t *pArgFwDl,
                              IFX_boolean_t            bInternCall);

#endif      /* MEI_SUPPORT_DL_DMA_CS */

#ifdef __cplusplus
/* extern "C" */
}
#endif

#endif   /* #ifndef _DRV_MEI_CPE_DOWNLOAD_VINAX_COMMON_H */


