/******************************************************************************

                               Copyright (c) 2011
                            Lantiq Deutschland GmbH
                     Am Campeon 3; 85579 Neubiberg, Germany

  For licensing information, see the file 'LICENSE' in the root folder of
  this software module.

******************************************************************************/

/* ==========================================================================
   Description : VR9/AR9 device specific functions for the MEI CPE Driver
   ========================================================================== */

/* ============================================================================
   Includes
   ========================================================================= */

/* get at first the driver configuration */
#include "drv_mei_cpe_config.h"

#if (MEI_SUPPORT_DEVICE_VR9 == 1) || (MEI_SUPPORT_DEVICE_AR9 == 1)

#include "ifx_types.h"
#include "drv_mei_cpe_os.h"
#include "drv_mei_cpe_dbg.h"

#include "drv_mei_cpe_interface.h"
#include "drv_mei_cpe_mei_interface.h"
#include "drv_mei_cpe_api.h"

IFX_int32_t MEI_GPIntProcess(MEI_MeiRegVal_t processInt, MEI_DEV_T *pMeiDev)
{
   if (processInt & ME_ARC2ME_STAT_ARC_GP_INT0)
   {
      PRN_ERR_INT_NL( MEI_DRV, MEI_DRV_PRN_LEVEL_ERR,
           ("MEI_DRV[%02d]: - GP INT0 occurred --> FW generated" MEI_DRV_CRLF,
           MEI_DRV_LINENUM_GET(pMeiDev)));
   }

   return IFX_SUCCESS;
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
   PRN_ERR_USR_NL( MEI_DRV, MEI_DRV_PRN_LEVEL_WRN,
        ("MEI_DRV[%02d]: Boot mode (0x%02X) - autonomous" MEI_DRV_CRLF,
          MEI_DRV_LINENUM_GET(pMeiDev), pMeiDev->modemData.devBootMode));
   MEI_DRV_BOOTMODE_SET(pMeiDev, e_MEI_DRV_BOOT_MODE_AUTO);

   return IFX_SUCCESS;
}

#endif /* (MEI_SUPPORT_DEVICE_VR9 == 1) || (MEI_SUPPORT_DEVICE_AR9 == 1)*/

