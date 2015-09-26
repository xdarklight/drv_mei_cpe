/******************************************************************************

                              Copyright (c) 2014
                            Lantiq Deutschland GmbH

  For licensing information, see the file 'LICENSE' in the root folder of
  this software module.

******************************************************************************/

/* ==========================================================================
   Description : VR9/VR10/AR9 device specific functions for the MEI CPE Driver
   ========================================================================== */

/* ============================================================================
   Includes
   ========================================================================= */

/* get at first the driver configuration */
#include "drv_mei_cpe_config.h"

#include "ifx_types.h"
#include "drv_mei_cpe_os.h"
#include "drv_mei_cpe_dbg.h"

#include "drv_mei_cpe_interface.h"
#include "drv_mei_cpe_mei_interface.h"
#include "drv_mei_cpe_api.h"

#if defined(LINUX)
#  if (LINUX_VERSION_CODE < KERNEL_VERSION(3,10,0))
#    if (MEI_SUPPORT_DEVICE_VR10_320 != 1)
#       include "ifx_pcie.h"
#    else
#       include "../drivers/net/ethernet/lantiq/lantiq_pcie.h"
#    endif
#  else
#    include "lantiq_pcie.h"
#  endif
#endif /* #if defined(LINUX)*/

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
   Read the Chip Info Register from the VRX devcie.
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

/**
   Check for correct entity value

\param
   nEntityNum:    device number - identify the given device.

\return
   IFX_SUCCESS    Success
   IFX_ERROR      in case of error
*/
IFX_int32_t MEI_VR10_PcieEntitiesCheck(IFX_uint8_t nEntityNum)
{
   IFX_uint32_t pcie_entitiesNum;

   /* get information from pcie driver */
#if (MEI_SUPPORT_DEVICE_VR10_320 != 1)
   if (ifx_pcie_ep_dev_num_get(&pcie_entitiesNum))
#else
   if (ltq_pcie_ep_dev_num_get(&pcie_entitiesNum))
#endif
   {
      PRN_ERR_USR_NL( MEI_DRV, MEI_DRV_PRN_LEVEL_ERR,
         ("PCIe: failed to get total device number" MEI_DRV_CRLF));

      return IFX_ERROR;
   }
   if (nEntityNum >= pcie_entitiesNum)
   {
      PRN_ERR_USR_NL( MEI_DRV, MEI_DRV_PRN_LEVEL_ERR,
             ("PCIe: - invalid device num %d, max pcie devices attached %d"
              MEI_DRV_CRLF, nEntityNum, pcie_entitiesNum));

      return IFX_ERROR;
   }

   return IFX_SUCCESS;
}

/**
   Init pcie related info (membase, irq number)

\param
   pMeiDrvCntrl:   points to the MEI interface register set.

\return
   IFX_SUCCESS    Success
   IFX_ERROR      in case of error
*/
IFX_int32_t MEI_VR10_PcieEntityInit(MEI_MEI_DRV_CNTRL_T *pMeiDrvCntrl)
{
   IFX_uint8_t entityNum;
#if (MEI_SUPPORT_DEVICE_VR10_320 != 1)
   ifx_pcie_ep_dev_t MEI_pcie_ep_dev;
#else
   ltq_pcie_ep_dev_t MEI_pcie_ep_dev;
#endif

   entityNum = MEI_GET_ENTITY_FROM_DEVNUM(pMeiDrvCntrl->dslLineNum);

#if (MEI_SUPPORT_DEVICE_VR10_320 != 1)
   if (ifx_pcie_ep_dev_info_req(entityNum, IFX_PCIE_EP_INT_MEI, &MEI_pcie_ep_dev))
#else
   if (ltq_pcie_ep_dev_info_req(entityNum, IFX_PCIE_EP_INT_MEI, &MEI_pcie_ep_dev))
#endif
   {
      PRN_ERR_USR_NL( MEI_DRV, MEI_DRV_PRN_LEVEL_ERR,
         ("PCIe: failed to get EP device %i information" MEI_DRV_CRLF, entityNum));

      return IFX_ERROR;
   }

   PRN_DBG_USR_NL( MEI_DRV, MEI_DRV_PRN_LEVEL_LOW,
      ("PCIe: EP device %i, irq %i, physical membase 0x%08x, virtual membase 0x%08x" MEI_DRV_CRLF,
      entityNum, MEI_pcie_ep_dev.irq, MEI_pcie_ep_dev.phy_membase, MEI_pcie_ep_dev.membase));

   pMeiDrvCntrl->MEI_pcie_phy_membase = (IFX_uint32_t)MEI_pcie_ep_dev.phy_membase;
   pMeiDrvCntrl->MEI_pcie_virt_membase = (IFX_uint32_t)MEI_pcie_ep_dev.membase;
   /* Use active polling mode for VRX320 */
   if (MEI_DEVICE_CFG_IS_PLATFORM(e_MEI_DEV_PLATFORM_CONFIG_VR10_320))
   {
      pMeiDrvCntrl->MEI_pcie_irq = 99;
   }
   else
   {
      pMeiDrvCntrl->MEI_pcie_irq = MEI_pcie_ep_dev.irq;
   }

   return IFX_SUCCESS;
}

/**
   Release usage PCIe module by MEI driver

\param
   entityNum:    device number - identify the given device.

\return
   IFX_SUCCESS    Success
   IFX_ERROR      in case of error
*/
IFX_int32_t MEI_VR10_PcieEntityFree(IFX_uint8_t entityNum)
{
#if (MEI_SUPPORT_DEVICE_VR10_320 != 1)
   if (ifx_pcie_ep_dev_info_release(entityNum))
#else
   if (ltq_pcie_ep_dev_info_release(entityNum))
#endif
   {
      PRN_ERR_USR_NL( MEI_DRV, MEI_DRV_PRN_LEVEL_ERR,
         ("PCIe: failed to release EP device %i" MEI_DRV_CRLF, entityNum));

      return IFX_ERROR;
   }

   return IFX_SUCCESS;
}

/**
   Internal init device with info provided by pcie driver

\param
   pMeiDynCntrl   - private dynamic device data (per open instance)

\return
   IFX_SUCCESS    Success
   IFX_ERROR      in case of error
*/
IFX_int32_t MEI_VR10_InternalInitDevice(MEI_DYN_CNTRL_T *pMeiDynCntrl)
{
   IFX_int32_t         retVal;
   IOCTL_MEI_devInit_t InitDev;
   MEI_DEV_T           *pMeiDev = pMeiDynCntrl->pMeiDev;

   /* Init membase addresses and driver for the first usage */
   if (MEI_DRV_STATE_GET(pMeiDev) == e_MEI_DRV_STATE_NOT_INIT)
   {
      InitDev.usedIRQ = MEI_DRV_PCIE_IRQ_GET(&pMeiDev->meiDrvCntrl);
      InitDev.meiBaseAddr = MEI_DRV_PCIE_PHY_MEMBASE_GET(&pMeiDev->meiDrvCntrl)
                              + MEI_DSL_MEI_OFFSET;
      InitDev.PDBRAMaddr = MEI_DRV_PCIE_PHY_MEMBASE_GET(&pMeiDev->meiDrvCntrl)
                              + MEI_PDBRAM_OFFSET;

      if ((retVal = MEI_InternalInitDevice(pMeiDynCntrl, &InitDev)) != IFX_SUCCESS)
      {
         return retVal;
      }
   }

   /* Clear LIF bits (0, 3, 8) of P0_ALSEL0 and P0_ALSEL1 */
   *MEI_GPIO_U32REG(GPIO_P0_ALSEL0) &= ~((1 << 0) | (1 << 3) | (1 << 8));
   *MEI_GPIO_U32REG(GPIO_P0_ALSEL1) &= ~((1 << 0) | (1 << 3) | (1 << 8));

   return IFX_SUCCESS;
}

