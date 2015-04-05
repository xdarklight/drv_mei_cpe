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

#if (MEI_EXPORT_INTERNAL_API == 1)

#include "ifx_types.h"
#include "drv_mei_cpe_os.h"
#include "drv_mei_cpe_dbg.h"
#include "drv_mei_cpe_dbg_driver.h"

/** get interface and configuration */
#include "drv_mei_cpe_interface.h"
#include "drv_mei_cpe_api.h"
#include "drv_mei_cpe_msg_process.h"

#include "drv_mei_cpe_dbg_access.h"
#include "drv_mei_cpe_download.h"

#if (MEI_DRV_ATM_OAM_ENABLE == 1)
#include "drv_mei_cpe_atmoam_common.h"
#endif

#if (MEI_DRV_CLEAR_EOC_ENABLE == 1)
#include "drv_mei_cpe_clear_eoc_common.h"
#endif

/* ============================================================================
   Exported functions
   ========================================================================= */

IFX_int32_t MEI_InternalInitDevice(
                              MEI_DYN_CNTRL_T     *pMeiDynCntrl,
                              IOCTL_MEI_devInit_t *pArgInitDev)
{
   IFX_int32_t    retVal = IFX_SUCCESS;

   if ( (retVal = MEI_CheckIoctlCmdInitState(
                              pMeiDynCntrl,
                              (IFX_uint32_t)FIO_MEI_DEV_INIT ))
        != IFX_SUCCESS )
   {
      pArgInitDev->ictl.retCode = (int)retVal;
      return retVal;
   }

   retVal = MEI_IoctlInitDevice(pMeiDynCntrl, pArgInitDev);
   pArgInitDev->ictl.retCode = (int)retVal;

   return retVal;
}

IFX_int32_t MEI_InternalDrvVersionGet(
                              MEI_DYN_CNTRL_T        *pMeiDynCntrl,
                              IOCTL_MEI_drvVersion_t *pArgDrvVersion_out)
{
   IFX_int32_t    retVal = IFX_SUCCESS;

   retVal = MEI_IoctlDrvVersionGet(pMeiDynCntrl, pArgDrvVersion_out, IFX_TRUE);
   pArgDrvVersion_out->ictl.retCode = (int)retVal;

   return retVal;
}

/**
   Internal Interface - Set the VINAX Driver debug level.
\param
   pMeiDynCntrl    points to the dynamic control struct.
\param
   pArgDbgLevel      points to the debug level struct.

\return
   0 (IFX_SUCCESS) if success
   negative value in case of error
*/
IFX_int32_t MEI_InternalDebugLevelSet(
                              MEI_DYN_CNTRL_T       *pMeiDynCntrl,
                              IOCTL_MEI_dbgLevel_t  *pArgDbgLevel)
{
   IFX_int32_t    retVal = IFX_SUCCESS;

   retVal = MEI_IoctlDebugLevelSet(pMeiDynCntrl, pArgDbgLevel);
   pArgDbgLevel->ictl.retCode = (int)retVal;

   return retVal;
}


IFX_int32_t MEI_InternalDevReset(
                              MEI_DYN_CNTRL_T    *pMeiDynCntrl,
                              IOCTL_MEI_reset_t  *pArgRstArgs,
                              IFX_int32_t          rstSrc)
{
   IFX_int32_t    retVal = IFX_SUCCESS;

   if ( (retVal = MEI_CheckIoctlCmdInitState(
                              pMeiDynCntrl,
                              (IFX_uint32_t)FIO_MEI_RESET ))
        != IFX_SUCCESS )
   {

      pArgRstArgs->ictl.retCode = (int)retVal;
      return retVal;
   }

   retVal =  MEI_DrvAndDevReset(
                             pMeiDynCntrl->pMeiDev
                           , pArgRstArgs->rstMode
                           , pArgRstArgs->rstSelMask
                           , rstSrc);

   pArgRstArgs->ictl.retCode = (int)retVal;

   return retVal;
}

IFX_int32_t MEI_InternalRequestConfig(
                              MEI_DYN_CNTRL_T    *pMeiDynCntrl,
                              IOCTL_MEI_reqCfg_t *pArgDevCfg_out)
{
   IFX_int32_t    retVal = IFX_SUCCESS;

   if ( (retVal = MEI_CheckIoctlCmdInitState(
                              pMeiDynCntrl,
                              (IFX_uint32_t)FIO_MEI_REQ_CONFIG ))
        != IFX_SUCCESS )
   {
      pArgDevCfg_out->ictl.retCode = (int)retVal;
      return retVal;
   }

   MEI_IoctlRequestConfig(pMeiDynCntrl, pArgDevCfg_out);

   pArgDevCfg_out->ictl.retCode = IFX_SUCCESS;
   return retVal;
}

#if (MEI_SUPPORT_VDSL2_ADSL_SWAP == 1)
IFX_int32_t MEI_InternalDevCfgFwModeSwap(
                              MEI_DYN_CNTRL_T    *pMeiDynCntrl,
                              IOCTL_MEI_fwMode_t *pArgFwMode)
{
   IFX_int32_t    retVal = IFX_SUCCESS;

   if ( (retVal = MEI_CheckIoctlCmdInitState(
                              pMeiDynCntrl,
                              (IFX_uint32_t)FIO_MEI_FW_MODE_SELECT ))
        != IFX_SUCCESS )
   {
      pArgFwMode->ictl.retCode = (int)retVal;
      return retVal;
   }

   if ( (retVal = MEI_CheckIoctlCmdSendState(
                              pMeiDynCntrl,
                              (IFX_uint32_t)FIO_MEI_FW_MODE_SELECT ))
        != IFX_SUCCESS )
   {
      pArgFwMode->ictl.retCode = (int)retVal;
      return retVal;
   }

   retVal = MEI_IoctlDevCfgFwModeSwap(pMeiDynCntrl, pArgFwMode);

   pArgFwMode->ictl.retCode = (int)retVal;
   return retVal;
}
#endif

#if (MEI_SUPPORT_STATISTICS == 1)
IFX_int32_t MEI_InternalRequestStat(
                              MEI_DYN_CNTRL_T       *pMeiDynCntrl,
                              IOCTL_MEI_statistic_t *pArgDevStat_out )
{
   IFX_int32_t    retVal = IFX_SUCCESS;

   if ( (retVal = MEI_CheckIoctlCmdInitState(
                              pMeiDynCntrl,
                              (IFX_uint32_t)FIO_MEI_REQ_STAT ))
        != IFX_SUCCESS )
   {
      pArgDevStat_out->ictl.retCode = (int)retVal;
      return retVal;
   }

   MEI_IoctlRequestStat(pMeiDynCntrl, pArgDevStat_out);

   pArgDevStat_out->ictl.retCode = (int)retVal;
   return retVal;
}
#endif


IFX_int32_t MEI_InternalNfcCallBackDataSet(
                              MEI_DYN_CNTRL_T    *pMeiDynCntrl,
                              MEI_InternalMsgRecvCallBack pCallBackFunc,
                              IFX_void_t                    *pNfcCallBackData)
{
   return MEI_NfcCallBackSet(pMeiDynCntrl, pCallBackFunc, pNfcCallBackData);
}

IFX_int32_t MEI_InternalNfcEnable(
                              MEI_DYN_CNTRL_T    *pMeiDynCntrl)
{
   IFX_int32_t    retVal = IFX_SUCCESS;

   if ( (retVal = MEI_CheckIoctlCmdInitState(
                              pMeiDynCntrl,
                              (IFX_uint32_t)FIO_MEI_MBOX_NFC_ENABLE ))
        != IFX_SUCCESS )
   {
      return retVal;
   }

   if (pMeiDynCntrl->pInstDynNfc == IFX_NULL)
   {
      retVal = MEI_IoctlNfcEnable(pMeiDynCntrl, 0, 0);
      pMeiDynCntrl->pInstDynNfc->msgProcessCtrl = MEI_MSG_CNTRL_MODEM_MSG_MASK_DEFAULT;
   }

   return retVal;

}

IFX_int32_t MEI_InternalNfcDisable(
                              MEI_DYN_CNTRL_T    *pMeiDynCntrl)
{
   IFX_int32_t    retVal = IFX_SUCCESS;

   if ( (retVal = MEI_CheckIoctlCmdInitState(
                              pMeiDynCntrl,
                              (IFX_uint32_t)FIO_MEI_MBOX_NFC_DISABLE ))
        != IFX_SUCCESS )
   {
      return retVal;
   }

   retVal = MEI_IoctlNfcDisable(pMeiDynCntrl);

   return retVal;
}


IFX_int32_t MEI_InternalAutoMsgCtlSet(
                              MEI_DYN_CNTRL_T         *pMeiDynCntrl,
                              IOCTL_MEI_autoMsgCtrl_t *pArgAutoMsgCtrl)
{
   IFX_int32_t    retVal = IFX_SUCCESS;

   if ( (retVal = MEI_CheckIoctlCmdInitState(
                              pMeiDynCntrl,
                              (IFX_uint32_t)FIO_MEI_AUTO_MSG_CTRL_SET ))
        != IFX_SUCCESS )
   {
      pArgAutoMsgCtrl->ictl.retCode = (int)retVal;
      return retVal;
   }

   retVal = MEI_IoctlAutoMsgCtlSet(pMeiDynCntrl, pArgAutoMsgCtrl);

   pArgAutoMsgCtrl->ictl.retCode = (int)retVal;
   return retVal;
}


IFX_int32_t MEI_InternalAutoMsgCtlGet(
                              MEI_DYN_CNTRL_T         *pMeiDynCntrl,
                              IOCTL_MEI_autoMsgCtrl_t *pArgAutoMsgCtrl)
{
   IFX_int32_t    retVal = IFX_SUCCESS;

   if ( (retVal = MEI_CheckIoctlCmdInitState(
                              pMeiDynCntrl,
                              (IFX_uint32_t)FIO_MEI_AUTO_MSG_CTRL_GET ))
        != IFX_SUCCESS )
   {
      pArgAutoMsgCtrl->ictl.retCode = (int)retVal;
      return retVal;
   }

   retVal = MEI_IoctlAutoMsgCtlGet(pMeiDynCntrl, pArgAutoMsgCtrl);

   pArgAutoMsgCtrl->ictl.retCode = (int)retVal;
   return retVal;
}


IFX_int32_t MEI_InternalCmdMsgWrite(
                              MEI_DYN_CNTRL_T       *pMeiDynCntrl,
                              IOCTL_MEI_message_t   *pArgMsg)
{
   IFX_int32_t    retVal = IFX_SUCCESS;

   if ( (retVal = MEI_CheckIoctlCmdInitState(
                              pMeiDynCntrl,
                              (IFX_uint32_t)FIO_MEI_MBOX_MSG_WR ))
        != IFX_SUCCESS )
   {
      pArgMsg->ictl.retCode = (int)retVal;
      return retVal;
   }

   if ( (retVal = MEI_CheckIoctlCmdSendState(
                              pMeiDynCntrl,
                              (IFX_uint32_t)FIO_MEI_MBOX_MSG_WR ))
        != IFX_SUCCESS )
   {
      pArgMsg->ictl.retCode = (int)retVal;
      return retVal;
   }

   MEI_DRVOS_SemaphoreLock(&pMeiDynCntrl->pInstanceRWlock);

   retVal = MEI_IoctlCmdMsgWrite(
                           pMeiDynCntrl, pArgMsg, IFX_TRUE);

   MEI_DRVOS_SemaphoreUnlock(&pMeiDynCntrl->pInstanceRWlock);

   pArgMsg->ictl.retCode = (int)retVal;
   return retVal;
}

IFX_int32_t MEI_InternalAckMsgRead(
                              MEI_DYN_CNTRL_T       *pMeiDynCntrl,
                              IOCTL_MEI_message_t   *pArgMsg)
{
   IFX_int32_t    retVal = IFX_SUCCESS;

   if ( (retVal = MEI_CheckIoctlCmdInitState(
                              pMeiDynCntrl,
                              (IFX_uint32_t)FIO_MEI_MBOX_ACK_RD ))
        != IFX_SUCCESS )
   {
      pArgMsg->ictl.retCode = (int)retVal;
      return retVal;
   }

   if ( (retVal = MEI_CheckIoctlCmdSendState(
                              pMeiDynCntrl,
                              (IFX_uint32_t)FIO_MEI_MBOX_ACK_RD ))
        != IFX_SUCCESS )
   {
      pArgMsg->ictl.retCode = (int)retVal;
      return retVal;
   }

   MEI_DRVOS_SemaphoreLock(&pMeiDynCntrl->pInstanceRWlock);
   retVal = MEI_IoctlAckMsgRead(
                           pMeiDynCntrl, pArgMsg, IFX_TRUE);

   MEI_DRVOS_SemaphoreUnlock(&pMeiDynCntrl->pInstanceRWlock);

   if (retVal < 0)
   {
      pArgMsg->paylSize_byte = 0;
   }

   pArgMsg->ictl.retCode = (int)retVal;
   return retVal;
}

IFX_int32_t MEI_InternalMsgSend(
                              MEI_DYN_CNTRL_T          *pMeiDynCntrl,
                              IOCTL_MEI_messageSend_t  *pArgMsgs)
{
   IFX_int32_t    retVal = IFX_SUCCESS;

   if ( (retVal = MEI_CheckIoctlCmdInitState(
                              pMeiDynCntrl,
                              (IFX_uint32_t)FIO_MEI_MBOX_MSG_SEND ))
        != IFX_SUCCESS )
   {
      pArgMsgs->ictl.retCode = (int)retVal;
      return retVal;
   }

   if ( (retVal = MEI_CheckIoctlCmdSendState(
                              pMeiDynCntrl,
                              (IFX_uint32_t)FIO_MEI_MBOX_MSG_SEND ))
        != IFX_SUCCESS )
   {
      pArgMsgs->ictl.retCode = (int)retVal;
      return retVal;
   }

   retVal = MEI_IoctlMsgSend(pMeiDynCntrl, pArgMsgs, IFX_TRUE);

   pArgMsgs->ictl.retCode = (int)retVal;
   return retVal;
}

IFX_int32_t MEI_InternalNfcMsgRead(
                              MEI_DYN_CNTRL_T       *pMeiDynCntrl,
                              IOCTL_MEI_message_t   *pArgMsg)
{
   IFX_int32_t    retVal = IFX_SUCCESS;

   if ( (retVal = MEI_CheckIoctlCmdInitState(
                              pMeiDynCntrl,
                              (IFX_uint32_t)FIO_MEI_MBOX_NFC_RD ))
        != IFX_SUCCESS )
   {
      pArgMsg->ictl.retCode = (int)retVal;
      return retVal;
   }

   if ( (retVal = MEI_CheckIoctlCmdSendState(
                              pMeiDynCntrl,
                              (IFX_uint32_t)FIO_MEI_MBOX_NFC_RD ))
        != IFX_SUCCESS )
   {
      pArgMsg->ictl.retCode = (int)retVal;
      return retVal;
   }

   retVal = MEI_IoctlNfcMsgRead(
                        pMeiDynCntrl, pArgMsg, IFX_TRUE);

   pArgMsg->ictl.retCode = (int)retVal;
   return retVal;
}


#if (MEI_SUPPORT_REGISTER == 1)
IFX_int32_t MEI_InternalSetRegister(
                              MEI_DYN_CNTRL_T       *pMeiDynCntrl,
                              IOCTL_MEI_regInOut_t  *pArgRegInOut)
{
   IFX_int32_t    retVal = IFX_SUCCESS;

   if ( (retVal = MEI_CheckIoctlCmdInitState(
                              pMeiDynCntrl,
                              (IFX_uint32_t)FIO_MEI_REG_SET ))
        != IFX_SUCCESS )
   {
      pArgRegInOut->ictl.retCode = (int)retVal;
      return retVal;
   }

   if( MEI_Set_Register( pMeiDynCntrl->pMeiDev,
                           pArgRegInOut->addr,
                           pArgRegInOut->value)
       != IFX_SUCCESS )
   {
      pArgRegInOut->ictl.retCode = -e_MEI_ERR_OP_FAILED;
      return IFX_ERROR;
   }

   pArgRegInOut->ictl.retCode = IFX_SUCCESS;
   return IFX_SUCCESS;

}

IFX_int32_t MEI_InternalGetRegister(
                              MEI_DYN_CNTRL_T       *pMeiDynCntrl,
                              IOCTL_MEI_regInOut_t  *pArgRegInOut)
{
   IFX_int32_t    retVal = IFX_SUCCESS;

   if ( (retVal = MEI_CheckIoctlCmdInitState(
                              pMeiDynCntrl,
                              (IFX_uint32_t)FIO_MEI_REG_GET ))
        != IFX_SUCCESS )
   {
      pArgRegInOut->ictl.retCode = (int)retVal;
      return retVal;
   }

   if( MEI_Get_Register( pMeiDynCntrl->pMeiDev,
                           pArgRegInOut->addr,
                           (IFX_uint32_t*)&pArgRegInOut->value)
       != IFX_SUCCESS )
   {
      pArgRegInOut->ictl.retCode = -e_MEI_ERR_OP_FAILED;
      return IFX_ERROR;
   }

   pArgRegInOut->ictl.retCode = IFX_SUCCESS;
   return IFX_SUCCESS;
}
#endif /* MEI_SUPPORT_REGISTER */


#if (MEI_SUPPORT_DFE_DBG_ACCESS == 1)
IFX_int32_t MEI_InternalMeiDbgAccessWr(
                              MEI_DYN_CNTRL_T       *pMeiDynCntrl,
                              IOCTL_MEI_dbgAccess_t *pArgDbgAccessInOut)
{
   IFX_int32_t    retVal = IFX_SUCCESS;

   if ( (retVal = MEI_CheckIoctlCmdInitState(
                              pMeiDynCntrl,
                              (IFX_uint32_t)FIO_MEI_DBG_WRITE ))
        != IFX_SUCCESS )
   {
      pArgDbgAccessInOut->ictl.retCode = (int)retVal;
      return retVal;
   }

   retVal = MEI_IoctlMeiDbgAccessWr(pMeiDynCntrl, pArgDbgAccessInOut);
   pArgDbgAccessInOut->ictl.retCode = (int)retVal;

   return retVal;
}


IFX_int32_t MEI_InternalMeiDbgAccessRd(
                              MEI_DYN_CNTRL_T       *pMeiDynCntrl,
                              IOCTL_MEI_dbgAccess_t *pArgDbgAccessInOut)
{
   IFX_int32_t    retVal = IFX_SUCCESS;

   if ( (retVal = MEI_CheckIoctlCmdInitState(
                              pMeiDynCntrl,
                              (IFX_uint32_t)FIO_MEI_DBG_READ ))
        != IFX_SUCCESS )
   {
      pArgDbgAccessInOut->ictl.retCode = (int)retVal;
      return retVal;
   }

   retVal = MEI_IoctlMeiDbgAccessRd(pMeiDynCntrl, pArgDbgAccessInOut);
   pArgDbgAccessInOut->ictl.retCode = (int)retVal;

   return retVal;
}
#endif      /* #if (MEI_SUPPORT_DFE_DBG_ACCESS == 1) */

#if (MEI_SUPPORT_DFE_GPA_ACCESS == 1)
IFX_int32_t MEI_InternalGpaWrAccess(
                              MEI_DYN_CNTRL_T             *pMeiDynCntrl,
                              IOCTL_MEI_GPA_accessInOut_t *pArgGpaInOut)
{
   IFX_int32_t    retVal = IFX_SUCCESS;

   if ( (retVal = MEI_CheckIoctlCmdInitState(
                              pMeiDynCntrl,
                              (IFX_uint32_t)FIO_MEI_GPA_WRITE ))
        != IFX_SUCCESS )
   {
      pArgGpaInOut->ictl.retCode = (int)retVal;
      return retVal;
   }

   pArgGpaInOut->ictl.retCode =
            MEI_GpaWrAccess( pMeiDynCntrl,
                               pArgGpaInOut->dest,
                               pArgGpaInOut->addr,
                               pArgGpaInOut->value);

   return (pArgGpaInOut->ictl.retCode != IFX_SUCCESS) ? IFX_ERROR : IFX_SUCCESS;
}


IFX_int32_t MEI_InternalGpaRdAccess(
                              MEI_DYN_CNTRL_T             *pMeiDynCntrl,
                              IOCTL_MEI_GPA_accessInOut_t *pArgGpaInOut)
{
   IFX_int32_t    retVal = IFX_SUCCESS;

   if ( (retVal = MEI_CheckIoctlCmdInitState(
                              pMeiDynCntrl,
                              (IFX_uint32_t)FIO_MEI_GPA_READ ))
        != IFX_SUCCESS )
   {
      pArgGpaInOut->ictl.retCode = (int)retVal;
      return retVal;
   }

   pArgGpaInOut->ictl.retCode =
            MEI_GpaRdAccess( pMeiDynCntrl,
                               pArgGpaInOut->dest,
                               pArgGpaInOut->addr,
                               (IFX_uint32_t *)&pArgGpaInOut->value);

   return (pArgGpaInOut->ictl.retCode != IFX_SUCCESS) ? IFX_ERROR : IFX_SUCCESS;
}

#endif /* #if (MEI_SUPPORT_DFE_GPA_ACCESS == 1) */


IFX_int32_t MEI_InternalFirmwareDownload(
                              MEI_DYN_CNTRL_T        *pMeiDynCntrl,
                              IOCTL_MEI_fwDownLoad_t *pArgFwDl)
{
   IFX_int32_t    retVal = IFX_SUCCESS;

   if ( (retVal = MEI_CheckIoctlCmdInitState(
                              pMeiDynCntrl,
                              (IFX_uint32_t)FIO_MEI_FW_DL ))
        != IFX_SUCCESS )
   {
      pArgFwDl->ictl.retCode = (int)retVal;
      return retVal;
   }

   retVal = MEI_IoctlFirmwareDownload(pMeiDynCntrl, pArgFwDl, IFX_TRUE);
   pArgFwDl->ictl.retCode = (int)retVal;

   return retVal;
}

#if (MEI_SUPPORT_DEVICE_VR9 == 1) || (MEI_SUPPORT_DEVICE_AR9 == 1)
IFX_int32_t MEI_InternalOptFirmwareDownload(
                              MEI_DYN_CNTRL_T           *pMeiDynCntrl,
                              IOCTL_MEI_fwOptDownLoad_t *pArgFwDl)
{
   IFX_int32_t    retVal = IFX_SUCCESS;

   if ( (retVal = MEI_CheckIoctlCmdInitState(
                              pMeiDynCntrl,
                              (IFX_uint32_t)FIO_MEI_OPT_FW_DL ))
        != IFX_SUCCESS )
   {
      pArgFwDl->ictl.retCode = (int)retVal;
      return retVal;
   }

   retVal = MEI_IoctlOptFirmwareDownload(pMeiDynCntrl, pArgFwDl, IFX_TRUE);
   pArgFwDl->ictl.retCode = (int)retVal;

   return retVal;
}
#endif /* (MEI_SUPPORT_DEVICE_VR9 == 1) || (MEI_SUPPORT_DEVICE_AR9 == 1)*/

#if (MEI_SUPPORT_DEVICE_VR9 == 1)
IFX_int32_t MEI_InternalFwModeCtrlSet(
                              MEI_DYN_CNTRL_T           *pMeiDynCntrl,
                              IOCTL_MEI_FwModeCtrlSet_t *pArgFwModeCtrl)
{
   IFX_int32_t    retVal = IFX_SUCCESS;

   if ( (retVal = MEI_CheckIoctlCmdInitState(
                              pMeiDynCntrl,
                              (IFX_uint32_t)FIO_MEI_FW_MODE_CTRL_SET ))
        != IFX_SUCCESS )
   {
      pArgFwModeCtrl->ictl.retCode = (int)retVal;
      return retVal;
   }

   retVal = MEI_IoctlFwModeCtrlSet(pMeiDynCntrl, pArgFwModeCtrl);
   pArgFwModeCtrl->ictl.retCode = (int)retVal;

   return retVal;
}

IFX_int32_t MEI_InternalFwModeStatGet(
                              MEI_DYN_CNTRL_T           *pMeiDynCntrl,
                              IOCTL_MEI_FwModeStatGet_t *pArgFwModeStat)
{
   IFX_int32_t    retVal = IFX_SUCCESS;

   if ( (retVal = MEI_CheckIoctlCmdInitState(
                              pMeiDynCntrl,
                              (IFX_uint32_t)FIO_MEI_FW_MODE_STAT_GET ))
        != IFX_SUCCESS )
   {
      pArgFwModeStat->ictl.retCode = (int)retVal;
      return retVal;
   }

   retVal = MEI_IoctlFwModeStatGet(pMeiDynCntrl, pArgFwModeStat);
   pArgFwModeStat->ictl.retCode = (int)retVal;

   return retVal;
}
#endif /* (MEI_SUPPORT_DEVICE_VR9 == 1)*/

#if (MEI_DRV_ATM_OAM_ENABLE == 1)

IFX_int32_t MEI_InternalAtmOamInit(
                              MEI_DYN_CNTRL_T          *pMeiDynCntrl,
                              IOCTL_MEI_ATMOAM_init_t  *pArgAtmOamInit)
{
   IFX_int32_t    retVal = IFX_SUCCESS;

   if ( (retVal = MEI_CheckIoctlCmdInitState(
                              pMeiDynCntrl,
                              (IFX_uint32_t)FIO_MEI_ATMOAM_INIT ))
        != IFX_SUCCESS )
   {
      pArgAtmOamInit->ictl.retCode = (int)retVal;
      return retVal;
   }

   retVal = MEI_ATMOAM_IoctlDrvInit(pMeiDynCntrl, pArgAtmOamInit);
   pArgAtmOamInit->ictl.retCode = (int)retVal;

   return retVal;
}


IFX_int32_t MEI_InternalAtmOamCntrl(
                              MEI_DYN_CNTRL_T          *pMeiDynCntrl,
                              IOCTL_MEI_ATMOAM_cntrl_t *pArgAtmOamCntrl)
{
   IFX_int32_t    retVal = IFX_SUCCESS;

   if ( (retVal = MEI_CheckIoctlCmdInitState(
                              pMeiDynCntrl,
                              (IFX_uint32_t)FIO_MEI_ATMOAM_CNTRL ))
        != IFX_SUCCESS )
   {
      pArgAtmOamCntrl->ictl.retCode = (int)retVal;
      return retVal;
   }

   retVal = MEI_ATMOAM_IoctlCntrl(pMeiDynCntrl, pArgAtmOamCntrl);
   pArgAtmOamCntrl->ictl.retCode = (int)retVal;

   return retVal;
}


IFX_int32_t MEI_InternalAtmOamCounterGet(
                              MEI_DYN_CNTRL_T            *pMeiDynCntrl,
                              IOCTL_MEI_ATMOAM_counter_t *pArgAtmOamCounter)
{
   IFX_int32_t    retVal = IFX_SUCCESS;

   if ( (retVal = MEI_CheckIoctlCmdInitState(
                              pMeiDynCntrl,
                              (IFX_uint32_t)FIO_MEI_ATMOAM_REQ_DEV_COUNTER))
        != IFX_SUCCESS )
   {
      pArgAtmOamCounter->ictl.retCode = (int)retVal;
      return retVal;
   }

   retVal = MEI_ATMOAM_IoctlCounterGet(pMeiDynCntrl, pArgAtmOamCounter);
   pArgAtmOamCounter->ictl.retCode = (int)retVal;

   return retVal;
}


IFX_int32_t MEI_InternalAtmOamStatusGet(
                              MEI_DYN_CNTRL_T             *pMeiDynCntrl,
                              IOCTL_MEI_ATMOAM_status_t   *pArgAtmOamStatus)
{
   IFX_int32_t    retVal = IFX_SUCCESS;

   if ( (retVal = MEI_CheckIoctlCmdInitState(
                              pMeiDynCntrl,
                              (IFX_uint32_t)FIO_MEI_ATMOAM_REQ_DRV_STATUS))
        != IFX_SUCCESS )
   {
      pArgAtmOamStatus->ictl.retCode = (int)retVal;
      return retVal;
   }

   retVal = MEI_ATMOAM_IoctlStatusGet(pMeiDynCntrl, pArgAtmOamStatus);
   pArgAtmOamStatus->ictl.retCode = (int)retVal;

   return retVal;
}


IFX_int32_t MEI_InternalAtmOamCellInsert(
                              MEI_DYN_CNTRL_T                *pMeiDynCntrl,
                              IOCTL_MEI_ATMOAM_drvAtmCells_t *pArgAtmOamCells)
{
   IFX_int32_t    retVal = IFX_SUCCESS;

   if ( (retVal = MEI_CheckIoctlCmdInitState(
                              pMeiDynCntrl,
                              (IFX_uint32_t)FIO_MEI_ATMOAM_CELL_INSERT))
        != IFX_SUCCESS )
   {
      pArgAtmOamCells->ictl.retCode = (int)retVal;
      return retVal;
   }

   retVal = MEI_ATMOAM_IoctlCellInsert(pMeiDynCntrl, pArgAtmOamCells);
   pArgAtmOamCells->ictl.retCode = (int)retVal;

   return retVal;
}

#endif      /* #if (MEI_DRV_ATM_OAM_ENABLE == 1) */



#if (MEI_DRV_CLEAR_EOC_ENABLE == 1)

IFX_int32_t MEI_InternalCEocInit(
                              MEI_DYN_CNTRL_T        *pMeiDynCntrl,
                              IOCTL_MEI_CEOC_init_t  *pArgCEocInit)
{
   IFX_int32_t    retVal = IFX_SUCCESS;

   if ( (retVal = MEI_CheckIoctlCmdInitState(
                              pMeiDynCntrl,
                              (IFX_uint32_t)FIO_MEI_CEOC_INIT ))
        != IFX_SUCCESS )
   {
      pArgCEocInit->ictl.retCode = (int)retVal;
      return retVal;
   }

   retVal = MEI_CEOC_IoctlDrvInit(pMeiDynCntrl, pArgCEocInit);
   pArgCEocInit->ictl.retCode = (int)retVal;

   return retVal;
}


IFX_int32_t MEI_InternalCEocCntrl(
                              MEI_DYN_CNTRL_T        *pMeiDynCntrl,
                              IOCTL_MEI_CEOC_cntrl_t *pArgCEocCntrl)
{
   IFX_int32_t    retVal = IFX_SUCCESS;

   if ( (retVal = MEI_CheckIoctlCmdInitState(
                              pMeiDynCntrl,
                              (IFX_uint32_t)FIO_MEI_CEOC_CNTRL ))
        != IFX_SUCCESS )
   {
      pArgCEocCntrl->ictl.retCode = (int)retVal;
      return retVal;
   }

   retVal = MEI_CEOC_IoctlCntrl(pMeiDynCntrl, pArgCEocCntrl);
   pArgCEocCntrl->ictl.retCode = (int)retVal;

   return retVal;
}


IFX_int32_t MEI_InternalCEocStats(
                              MEI_DYN_CNTRL_T            *pMeiDynCntrl,
                              IOCTL_MEI_CEOC_statistic_t *pArgCEocStats)
{
   IFX_int32_t    retVal = IFX_SUCCESS;

   if ( (retVal = MEI_CheckIoctlCmdInitState(
                              pMeiDynCntrl,
                              (IFX_uint32_t)FIO_MEI_CEOC_STATS ))
        != IFX_SUCCESS )
   {
      pArgCEocStats->ictl.retCode = (int)retVal;
      return retVal;
   }

   retVal = MEI_CEOC_IoctlStatusGet(pMeiDynCntrl, pArgCEocStats);
   pArgCEocStats->ictl.retCode = (int)retVal;

   return retVal;
}


IFX_int32_t MEI_InternalCEocFrameWr(
                              MEI_DYN_CNTRL_T        *pMeiDynCntrl,
                              IOCTL_MEI_CEOC_frame_t *pArgCEocFrame)
{
   IFX_int32_t    retVal = IFX_SUCCESS;

   if ( (retVal = MEI_CheckIoctlCmdInitState(
                              pMeiDynCntrl,
                              (IFX_uint32_t)FIO_MEI_CEOC_FRAME_WR ))
        != IFX_SUCCESS )
   {
      pArgCEocFrame->ictl.retCode = (int)retVal;
      return retVal;
   }

   retVal = MEI_CEOC_IoctlFrameWrite(pMeiDynCntrl, pArgCEocFrame, IFX_TRUE);
   pArgCEocFrame->ictl.retCode = (int)retVal;

   return retVal;
}


IFX_int32_t MEI_InternalCEocFrameRd(
                              MEI_DYN_CNTRL_T        *pMeiDynCntrl,
                              IOCTL_MEI_CEOC_frame_t *pArgCEocFrame)
{
   IFX_int32_t    retVal = IFX_SUCCESS;

   if ( (retVal = MEI_CheckIoctlCmdInitState(
                              pMeiDynCntrl,
                              (IFX_uint32_t)FIO_MEI_CEOC_FRAME_RD ))
        != IFX_SUCCESS )
   {
      pArgCEocFrame->ictl.retCode = (int)retVal;
      return retVal;
   }

   retVal = MEI_CEOC_IoctlFrameRead(pMeiDynCntrl, pArgCEocFrame, IFX_TRUE);
   pArgCEocFrame->ictl.retCode = (int)retVal;

   return retVal;
}

#endif      /* #if (MEI_DRV_CLEAR_EOC_ENABLE == 1) */

#endif      /* #if (MEI_EXPORT_INTERNAL_API == 1) */

