#ifndef _DRV_MEI_CPE_INTERFACE_H
#define _DRV_MEI_CPE_INTERFACE_H
/******************************************************************************

                               Copyright (c) 2011
                            Lantiq Deutschland GmbH
                     Am Campeon 3; 85579 Neubiberg, Germany

  For licensing information, see the file 'LICENSE' in the root folder of
  this software module.

******************************************************************************/

/* ==========================================================================
   Description : Interface to user application of the MEI CPE Driver
   ========================================================================== */

/** \defgroup MEI_INTERFACE MEI CPE Driver Interface
    Lists the entire interface of the MEI CPE Driver
*/

/** \defgroup MEI_COMMON Common Functions
    This Group contains all the commonly used functions to setup and communicate
    with the device.
    \ingroup MEI_INTERFACE
    */

/**
   \defgroup MEI_COMMON_IOCTL IOCtl's
   \ingroup MEI_COMMON
*/

/** \defgroup MEI_COMMON_INTERN Common Functions (for driver layer usage)
    This Group contains all the commonly used functions to setup and communicate
    with the device.
    \attention In opposite to the functions (IOCtl's) that are included within
               \ref MEI_COMMON group this functions expect that the arguments
               and data are already in kernel space.
    \ingroup MEI_INTERFACE
*/

/** \defgroup MEI_DEBUG Debug Functions
    This Group contains the additional debug functionalities, low level access
    and special functions not needed by the standard user
    \ingroup MEI_INTERFACE
*/

/**
   \defgroup MEI_DEBUG_IOCTL IOCtl's
   \ingroup MEI_DEBUG
*/

/** \defgroup MEI_ATMOAM Common Functions For ATM OAM Handling
    This Group contains all the commonly used functions to setup and communicate
    with the remote device via ATM OAM.
    \ingroup MEI_INTERFACE
*/

/**
   \defgroup MEI_ATMOAM_IOCTL IOCtl's
   \ingroup MEI_ATMOAM
*/

/** \defgroup MEI_CEOC Common Functions For Clear EOC Handling
    This Group contains all the commonly used functions to setup and communicate
    with the remote device via Clear EOC.
    \ingroup MEI_INTERFACE
*/

/**
   \defgroup MEI_CEOC_IOCTL IOCtl's
   \ingroup MEI_CEOC
*/

/**
    \defgroup MEI_ERROR_CODES Error Codes
    Defines all possible error codes returned by the DSL API library
    \ingroup MEI_INTERFACE
*/


/* ==========================================================================
   Driver features
   ========================================================================== */

/** The driver supports driver autonomous messages */
#define MEI_DRV_IF_HAVE_DRV_EVT_MSG                 1

/** The driver supports parallel firmware download */
#define MEI_DRV_IF_HAVE_PARALLEL_FW_DL              1

/** The driver supports ATM OAM cell insert / extract */
#define MEI_DRV_IF_HAVE_ATM_OAM_INSERT_EXTRACT      1

/** The driver supports Clear EOC frame insert / extract */
#define MEI_DRV_IF_HAVE_CLEAR_EOC_INSERT_EXTRACT    1


/* ==========================================================================
   ioctl commands (MEI CPE device)
   ========================================================================== */

/** magic number */
#define MEI_IOC_MAGIC 'Q'

/** This changes the level of debug outputs.
   This service is non-blocking.

   \param IOCTL_MEI_dbgLevel_t* The parameter points to a
          \ref IOCTL_MEI_dbgLevel_t structure

   \return
      0 if successful, otherwise -1

   \remarks
   The error code is always returned via the param struct.

   \remark debug_level is one of MEI_DRV_PRN_LEVEL_LOW, MEI_DRV_PRN_LEVEL_NORMAL,
      MEI_DRV_PRN_LEVEL_HIGH, MEI_DRV_PRN_LEVEL_OFF

   \code
     IOCTL_MEI_dbgLevel_t dbgLevel;

     memset(&dbgLevel, 0x00, sizeof(IOCTL_MEI_dbgLevel_t));
     dbgLevel.valLevel = MEI_DRV_PRN_LEVEL_LOW;
     ret = ioctl(fd, FIO_MEI_DEBUGLEVEL, &dbgLevel)
   \endcode

   \ingroup MEI_DEBUG_IOCTL */
#define FIO_MEI_DEBUGLEVEL             _IO(MEI_IOC_MAGIC, 1)

/** This returns the version information.

   \param IOCTL_MEI_drvVersion_t* The parameter points to a
          \ref IOCTL_MEI_drvVersion_t structure

   \return
      - 0 if successful, otherwise -1

   \remarks
   The return code is always returned via the param struct.

   \remarks
   The version string consists of "major.minor.step.type"

   \code
     char version[80];
     IOCTL_MEI_drvVersion_t drvVersion;

     memset(&drvVersion, 0x00, sizeof(IOCTL_MEI_drvVersion_t));
     drvVersion.strSize = 80;
     drvVersion.pVersionStr = version;

     ret = ioctl(fd, FIO_MEI_VERSION_GET, &drvVersion);
   \endcode

   \ingroup MEI_COMMON_IOCTL                        */
#define FIO_MEI_VERSION_GET            _IO(MEI_IOC_MAGIC, 2)

/** This sets the basic driver settings (baseaddress, IRQ, mailbox address).

   \param IOCTL_MEI_devInit_t* The parameter points to a
          \ref IOCTL_MEI_devInit_t structure

   \return
      - 0 if successful, otherwise -1

   \remarks
   The error code is always returned via the param struct.
      - e_MEI_ERR_DEV_DOWN if MEI interface is down
      - e_MEI_ERR_ALREADY_DONE if init already done
      - != 0 further errors

   \remarks This call has to be done right after the open call, to
      make the driver ready for read and write to the MEI.

   \code
     IOCTL_MEI_devInit_t DevInit;

     memset(&DevInit, 0x00, sizeof(IOCTL_MEI_devInit_t));
     DevInit.meiBaseAddr = 0xc0100000;
     DevInit.usedIRQ = 1;
     ret = ioctl(fd, FIO_MEI_DEV_INIT, &DevInit)
   \endcode
   \ingroup MEI_COMMON_IOCTL              */
#define FIO_MEI_DEV_INIT               _IO(MEI_IOC_MAGIC, 3)


/** This sets the basic driver settings (boot params, timeout behavior).

   \param IOCTL_MEI_drvInit_t* The parameter points to a
          \ref IOCTL_MEI_drvInit_t structure

   \return
      - 0 if successful, otherwise -1

   \remarks
   The return code is always returned via the param struct.

   \remarks
   This call requires no previous FIO_MEI_DEV_INIT.
   Providing a "0" value means keep the default value.

   \code
     IOCTL_MEI_drvInit_t DrvInit;

     memset(&DrvInit, 0x00, sizeof(IOCTL_MEI_drvInit_t));

     DrvInit.blockTimeout       = 0;
     DrvInit.waitModemMsg_ms    = 1000;
     DrvInit.waitFirstResp_ms   = 1000;
     DrvInit.bmWaitForDl_ms     = 1000;
     DrvInit.bmWaitDlInit_ms    = 1000;
     DrvInit.bmWaitNextBlk_ms   = 1000;
     DrvInit.bmDatawidth        = 16;
     DrvInit.bmWaitStates       = 12;

     ret = ioctl(fd, FIO_MEI_DRV_INIT, &DrvInit);
   \endcode
   \ingroup MEI_COMMON_IOCTL              */
#define FIO_MEI_DRV_INIT               _IO(MEI_IOC_MAGIC, 4)


/** This service resets the MEI CPE Device Driver and optional the
    device blocks via MEI register.

   \param IOCTL_MEI_reset_t* The parameter points to a
          \ref IOCTL_MEI_reset_t structure

   \return
      - 0 if successful, otherwise -1

   \remarks
   The error code is always returned via the param struct.
   - e_MEI_ERR_OP_FAILED in case of an error

   \code
     IOCTL_MEI_reset_t reset;

     memset(&reset, 0x00, sizeof(IOCTL_MEI_reset_t));

     reset.rstMode = e_MEI_RESET;
     reset.rstSelMask = MEI_IOCTL_HW_RST_MASK_ALL;

     ret = ioctl(fd, FIO_MEI_RESET, &reset);
   \endcode
   \ingroup MEI_COMMON_IOCTL
*/
#define FIO_MEI_RESET                  _IO(MEI_IOC_MAGIC, 11)


/** This service requests the MEI CPE Driver config.

   \param IOCTL_MEI_reqCfg_t* The parameter points to a
          \ref IOCTL_MEI_reqCfg_t structure

   \return
      - 0 if successful, otherwise -1

   \remarks
   The return code is always returned via the param struct.
      - e_MEI_ERR_INVAL_STATE invalid state (missing init)

   \remarks This call is only valid after a previous init call.
            Unknown or still not available Cfg values are returned with
            default settings.

   \code
     IOCTL_MEI_reqCfg_t reqCfg;
     memset(&reqCfg, 0x00, sizeof(IOCTL_MEI_reqCfg_t));
     ret = ioctl(fd, FIO_MEI_REQ_CONFIG, &reqCfg)
   \endcode
   \ingroup MEI_COMMON_IOCTL              */
#define FIO_MEI_REQ_CONFIG             _IO(MEI_IOC_MAGIC, 16)


/** This service requests the MEI CPE Driver channel statistic.

   \param IOCTL_MEI_statistic_t* The parameter points to a
          \ref IOCTL_MEI_statistic_t structure

   \return
      - 0 if successful, otherwise -1

   \remarks
   The return code is always returned via the param struct.
      - e_MEI_ERR_INVAL_STATE invalid state (missing init)

   \remarks This call is only valid after a previous init call.
            Also this call is only valid if the statistic feature is enabled.
   \code
     IOCTL_MEI_statistic_t reqStat;
     memset(&reqStat, 0x00, sizeof(IOCTL_MEI_statistic_t));
     ret = ioctl(fd, FIO_MEI_REQ_STAT, &reqStat)
   \endcode
   \ingroup MEI_COMMON_IOCTL              */
#define FIO_MEI_REQ_STAT               _IO(MEI_IOC_MAGIC, 17)

/** This service executes the firmware download to the MEI device.

   \param IOCTL_MEI_fwDownLoad_t* The parameter points to a
          \ref IOCTL_MEI_fwDownLoad_t structure

   \return
      - 0 if successful, otherwise -1

   \remarks
   The return code is always returned via the param struct.
      - e_MEI_ERR_INVAL_STATE invalid state (missing init)
      - e_MEI_ERR_INVAL_CONFIG invalid FW download config
      - e_MEI_ERR_DEV_NO_RESP  no response from device
      - e_MEI_ERR_INVAL_STATE invalid state for download
      - e_MEI_ERR_NO_MEM not enough memory
      - e_MEI_ERR_GET_ARG error while get user data
      - e_MEI_ERR_INVAL_CONFIG invalid bootmode
      - e_MEI_ERR_OP_FAILED download failed

   \code
     IOCTL_MEI_fwDownLoad_t MEI_FwDl;
     MEI_FwDl.pFwImage = pFirmwareFileBuffer;
     MEI_FwDl.size_byte = filesize;
     ret = ioctl(fd, FIO_MEI_FW_DL, &MEI_FwDl)
   \endcode
   \ingroup MEI_COMMON_IOCTL                        */
#define FIO_MEI_FW_DL                  _IO(MEI_IOC_MAGIC, 21)

/** This service executes the optimized firmware download to the
    VR9 device.

   \param IOCTL_MEI_fwOptDownLoad_t* The parameter points to a
          \ref IOCTL_MEI_fwOptDownLoad_t structure

   \return
      - 0 if successful, otherwise -1

   \remarks
   The return code is always returned via the param struct.
      - e_MEI_ERR_INVAL_STATE invalid state (missing init)
      - e_MEI_ERR_INVAL_CONFIG invalid FW download config
      - e_MEI_ERR_DEV_NO_RESP  no response from device
      - e_MEI_ERR_INVAL_STATE invalid state for download
      - e_MEI_ERR_NO_MEM not enough memory
      - e_MEI_ERR_GET_ARG error while get user data
      - e_MEI_ERR_INVAL_CONFIG invalid bootmode
      - e_MEI_ERR_OP_FAILED download failed

   \code
     IOCTL_MEI_fwOptDownLoad_t MEI_FwDl;
     IFX_int_t i, chunk_num;
     chunk_num
     for (i=0; i<chunk_num; i++)
     {
        MEI_FwDl.pFwImageChunk = ;
        MEI_FwDl.size_byte = ;
        MEI_FwDl.chunk_num = i;
        MEI_FwDl.bLastChunk = i < (chunk_num-1) ? 0 : 1;

        ret = ioctl(fd, FIO_MEI_OPT_FW_DL, &MEI_FwDl);
        if (ret < 0)
           break;
      }
   \endcode
   \ingroup MEI_COMMON_IOCTL                        */
#define FIO_MEI_OPT_FW_DL                  _IO(MEI_IOC_MAGIC, 65)

/** This service selects the firmware mode (VDSL2 / ADSL) and start.

   \param IOCTL_MEI_fwMode_t* The parameter points to a
          \ref IOCTL_MEI_fwMode_t structure

   \remarks FW mode parameter
      - 0: VDSL2 mode (default)
      - 1: ADSL mode

   \return
      - 0 if successful, otherwise -1

   \remarks
   The return code is always returned via the param struct.
      - e_MEI_ERR_INVAL_STATE invalid state (missing init)
      - e_MEI_ERR_OP_FAILED in case of operation errors.

   \remarks This call is only valid after a previous init call.
            Unknown or still not available Cfg values are returned with
            default settings.

   \code
     IOCTL_MEI_fwMode_t fwMode;

     fwMode.fwMode = MEI_IOCTL_FW_MODE_VDSL2;
     ret = ioctl(fd, FIO_MEI_FW_MODE_SELECT, &fwMode);
   \endcode
   \ingroup MEI_COMMON_IOCTL                        */
#define FIO_MEI_FW_MODE_SELECT         _IO(MEI_IOC_MAGIC, 22)

/** This service sets xDSL/DualPort mode control.

   \param IOCTL_MEI_FwModeCtrlSet_t* The parameter points to a
          \ref IOCTL_MEI_FwModeCtrlSet_t structure

   \return
      - 0 if successful, otherwise -1

   \remarks
   The return code is always returned via the param struct.
      - e_MEI_ERR_INVAL_STATE invalid state (missing init)
      - e_MEI_ERR_OP_FAILED in case of operation errors.

   \remarks This call is only valid after a previous init call.
            Unknown or still not available Cfg values are returned with
            default settings.

   \code
     IOCTL_MEI_FwModeCtrlSet_t fwModeSelect;

     fwModeSelect.bMultiLineModeLock = IFX_FALSE;
     fwModeSelect.eMultiLineModePreferred = e_MEI_MULTI_LINEMODE_SINGLE;
     fwModeSelect.bXdslModeLock = IFX_FALSE
     fwModeSelect.eXdslModePreferred = e_MEI_XDSLMODE_VDSL;
     ret = ioctl(fd, FIO_MEI_FW_MODE_SELECT, &fwMode);
   \endcode
   \ingroup MEI_COMMON_IOCTL                        */
#define FIO_MEI_FW_MODE_CTRL_SET       _IO(MEI_IOC_MAGIC, 66)

/** This service gets xDSL/DualPort mode control status.

   \param IOCTL_MEI_FwModeStatGet_t* The parameter points to a
          \ref IOCTL_MEI_FwModeStatGet_t structure

   \return
      - 0 if successful, otherwise -1

   \remarks
   The return code is always returned via the param struct.
      - e_MEI_ERR_INVAL_STATE invalid state (missing init)
      - e_MEI_ERR_OP_FAILED in case of operation errors.


   \code
     IOCTL_MEI_FwModeStatGet_t fwModeStatus;

     ret = ioctl(fd, FIO_MEI_FW_MODE_STAT_GET, &fwModeStatus);
   \endcode
   \ingroup MEI_COMMON_IOCTL                        */
#define FIO_MEI_FW_MODE_STAT_GET       _IO(MEI_IOC_MAGIC, 67)

/** This service sets an MEI register.

   \param IOCTL_MEI_regInOut_t* The parameter is points to a
          \ref IOCTL_MEI_regInOut_t structure

   \return
      - 0 if successful, otherwise -1

   \remarks
   The return code is always returned via the param struct.
      - e_MEI_ERR_INVAL_STATE invalid state (missing init)
      - e_MEI_ERR_OP_FAILED in case of an error

   \code
     IOCTL_MEI_regInOut_t reg_io;
     reg_io.addr  = 4;
     reg_io.value = 0x1234;
     ret = ioctl(fd, FIO_MEI_REG_SET, &reg_io);
   \endcode
   \ingroup MEI_DEBUG_IOCTL                        */
#define FIO_MEI_REG_SET                _IO(MEI_IOC_MAGIC, 13)

/** This service reads an MEI register.

   \param IOCTL_MEI_regInOut_t* The parameter is points to a
          \ref IOCTL_MEI_regInOut_t structure

   \return
      - 0 if successful, otherwise -1

   \remarks
   The return code is always returned via the param struct.
      - e_MEI_ERR_INVAL_STATE invalid state (missing init)
      - e_MEI_ERR_OP_FAILED in case of an error

   \remarks

   \code
     IOCTL_MEI_regInOut_t reg_io;
     reg_io.addr  = 4;
     ret = ioctl(fd, FIO_MEI_REG_GET, &reg_io);
     printf ("value 0x%X\n", reg_io.value);
   \endcode
   \ingroup MEI_DEBUG_IOCTL                        */
#define FIO_MEI_REG_GET                _IO(MEI_IOC_MAGIC, 14)

/** General Purpose Access Write to the target.
   Internal memory or AUX register contents can be written.

   \param IOCTL_MEI_GPA_accessInOut_t* The parameter points to a
          \ref IOCTL_MEI_GPA_accessInOut_t structure

   \return
      - 0 if successful, otherwise -1

   \remarks
   The return code is always returned via the param struct.
      - e_MEI_ERR_INVAL_ARG invalid argument
      - e_MEI_ERR_DEV_NO_RESOURCE no first response from the device
      - e_MEI_ERR_INVAL_STATE not in the correct state
      - e_MEI_ERR_OP_FAILED operation failed
      - e_MEI_ERR_DEV_TIMEOUT timeout from device

   \code
     IOCTL_MEI_GPA_accessInOut_t MEI_GpaAccessIo;
     MEI_GpaAccessIo.addr   = (unsigned int)addr;
     MEI_GpaAccessIo.value  = (unsigned int)value;
     MEI_GpaAccessIo.dest   = MEI_IOCTL_GPA_DEST_MEM;
     ret = ioctl(fd, FIO_MEI_GPA_WRITE, &MEI_GpaAccessIo);
   \endcode
   \ingroup MEI_DEBUG_IOCTL */
#define FIO_MEI_GPA_WRITE              _IO(MEI_IOC_MAGIC, 30)

/** General Purpose Access Read to the target.
   Internal memory or AUX register contents can be read.

   \param IOCTL_MEI_GPA_accessInOut_t* The parameter points to a
          \ref IOCTL_MEI_GPA_accessInOut_t structure

   \return
      - 0 if successful, otherwise -1

   \remarks
   The return code is always returned via the param struct.
      - e_MEI_ERR_INVAL_ARG invalid argument
      - e_MEI_ERR_DEV_NO_RESOURCE no first response from the device
      - e_MEI_ERR_INVAL_STATE not in the correct state
      - e_MEI_ERR_OP_FAILED operation failed
      - e_MEI_ERR_DEV_TIMEOUT timeout from device

   \code
     IOCTL_MEI_GPA_accessInOut_t MEI_GpaAccessIo;
     MEI_GpaAccessIo.addr   = (unsigned int)addr;
     MEI_GpaAccessIo.dest   = MEI_IOCTL_GPA_DEST_MEM;
     ret = ioctl(fd, FIO_MEI_GPA_READ, &MEI_GpaAccessIo);
     printf ("value 0x%X\n", MEI_GpaAccessIo.value);
   \endcode
   \ingroup MEI_DEBUG_IOCTL */
#define FIO_MEI_GPA_READ               _IO(MEI_IOC_MAGIC, 31)


/** DMA write access to the internal device memory.
   \param IOCTL_MEI_DMA_access_t* The parameter points to a
          \ref IOCTL_MEI_DMA_access_t structure

   \return
      - 0 if successful, otherwise -1

   \remarks
   The return code is always returned via the param struct.
      - e_MEI_ERR_INVAL_ARG invalid argument
      - e_MEI_ERR_NO_MEM no memory
      - e_MEI_ERR_RETURN_ARG Return Arguments error

   \code
     IOCTL_MEI_DMA_access_t MEI_DmaAccess;
     MEI_DmaAccess.dmaAddr = (unsigned int)addr;
     MEI_DmaAccess.count_32bit = (unsigned int)count;
     ret = ioctl(fd, FIO_MEI_DMA_READ, &MEI_DmaAccess);
   \endcode
   \ingroup MEI_DEBUG_IOCTL */
#define FIO_MEI_DMA_WRITE              _IO(MEI_IOC_MAGIC, 32)

/** DMA read access to the internal device memory.

   \param IOCTL_MEI_DMA_access_t* The parameter points to a
          \ref IOCTL_MEI_DMA_access_t structure

   \return
      - 0 if successful, otherwise -1

   \remarks
   The return code is always returned via the param struct.
      - e_MEI_ERR_INVAL_ARG invalid argument
      - e_MEI_ERR_NO_MEM no memory
      - e_MEI_ERR_RETURN_ARG Return Arguments error

   \code
     IOCTL_MEI_DMA_access_t MEI_DmaAccess;
     MEI_DmaAccess.dmaAddr = (unsigned int)addr;
     MEI_DmaAccess.count_32bit = (unsigned int)count;
     MEI_DmaAccess.pData_32 = (unsigned int*)pData;
     ret = ioctl(fd, FIO_MEI_DMA_READ, &MEI_DmaAccess);
   \endcode
   \ingroup MEI_DEBUG_IOCTL */
#define FIO_MEI_DMA_READ               _IO(MEI_IOC_MAGIC, 33)

/** Write to the device via MEI (debug write)

   \param IOCTL_MEI_dbgAccess_t* points to a
      \ref IOCTL_MEI_dbgAccess_t structure

   \return
      - 0 if successful, otherwise -1

   \remarks
   The return code is always returned via the param struct.
      - e_MEI_ERR_INVAL_STATE device still not init
      - e_MEI_ERR_OP_FAILED operation failed

   \remarks    dbgDest is one out of MEI_IOCTL_DEBUG_AUX,
      MEI_IOCTL_DEBUG_LDST, MEI_IOCTL_DEBUG_CORE

   \code
   IOCTL_MEI_dbgAccess_t MEI_dbg_access;
   MEI_dbg_access.count     = count;
   MEI_dbg_access.dbgAddr   = offset;
   MEI_dbg_access.dbgDest   = des;
   MEI_dbg_access.pData_32  = (unsigned int*) buffer;
   ret = ioctl(fd, FIO_MEI_DBG_WRITE, &MEI_dbg_access);
   \endcode
   \ingroup MEI_DEBUG_IOCTL */
#define FIO_MEI_DBG_WRITE              _IO(MEI_IOC_MAGIC, 34)

/** Read from the device via MEI (debug read)

   \param IOCTL_MEI_dbgAccess_t* points to a
      \ref IOCTL_MEI_dbgAccess_t structure

   \return
      - 0 if successful, otherwise -1

   \remarks
   The return code is always returned via the param struct.
       - e_MEI_ERR_INVAL_STATE device still not init
       - e_MEI_ERR_OP_FAILED operation failed

   \remarks    dbgDest is one out of MEI_IOCTL_DEBUG_AUX,
      MEI_IOCTL_DEBUG_LDST, MEI_IOCTL_DEBUG_CORE

   \code
   IOCTL_MEI_dbgAccess_t MEI_dbg_access;
   MEI_dbg_access.count     = count;
   MEI_dbg_access.dbgAddr   = offset;
   MEI_dbg_access.dbgDest   = des;
   MEI_dbg_access.pData_32  = (unsigned int*) buffer;
   ret = ioctl(fd, FIO_MEI_DBG_READ, &MEI_dbg_access);
   \endcode
   \ingroup MEI_DEBUG_IOCTL */
#define FIO_MEI_DBG_READ               _IO(MEI_IOC_MAGIC, 35)

/** Write to the device AUX space via MEI (debug write)

   \param IOCTL_MEI_dbgAccess_t* points to a
      \ref IOCTL_MEI_dbgAccess_t structure

   \return
      - 0 if successful, otherwise -1

   \remarks
   The return code is always returned via the param struct.
      - e_MEI_ERR_INVAL_STATE device still not init
      - e_MEI_ERR_OP_FAILED operation failed

   \remarks    This is the same as \ref FIO_MEI_DBG_WRITE with
      dbgDest = MEI_IOCTL_DEBUG_AUX

   \code
   IOCTL_MEI_dbgAccess_t MEI_dbg_access;
   MEI_dbg_access.count     = count;
   MEI_dbg_access.dbgAddr   = offset;
   MEI_dbg_access.pData_32  = (unsigned int*) buffer;
   ret = ioctl(fd, FIO_MEI_DBG_AUX_WRITE, &MEI_dbg_access);
   \endcode
   \ingroup MEI_DEBUG_IOCTL */
#define FIO_MEI_DBG_AUX_WRITE          _IO(MEI_IOC_MAGIC, 36)

/** Read from the device AUX space via MEI (debug read)

   \param IOCTL_MEI_dbgAccess_t* points to a
      \ref IOCTL_MEI_dbgAccess_t structure

   \return
      - 0 if successful, otherwise -1

   \remarks
   The return code is always returned via the param struct.
      - e_MEI_ERR_INVAL_STATE device still not init
      - e_MEI_ERR_OP_FAILED operation failed

   \remarks    This is the same as \ref FIO_MEI_DBG_READ with
      dbgDest = MEI_IOCTL_DEBUG_AUX

   \code
   IOCTL_MEI_dbgAccess_t MEI_dbg_access;
   MEI_dbg_access.count     = count;
   MEI_dbg_access.dbgAddr   = offset;
   MEI_dbg_access.pData_32  = (unsigned int*) buffer;
   ret = ioctl(fd, FIO_MEI_DBG_AUX_READ, &MEI_dbg_access);
   \endcode
   \ingroup MEI_DEBUG_IOCTL */
#define FIO_MEI_DBG_AUX_READ           _IO(MEI_IOC_MAGIC, 37)

/** Write to the device CORE space via MEI (debug write)

   \param IOCTL_MEI_dbgAccess_t* points to a
      \ref IOCTL_MEI_dbgAccess_t structure

   \return
      - 0 if successful, otherwise -1

   \remarks
   The return code is always returned via the param struct.
      - e_MEI_ERR_INVAL_STATE device still not init
      - e_MEI_ERR_OP_FAILED operation failed

   \remarks    This is the same as \ref FIO_MEI_DBG_WRITE with
      dbgDest = MEI_IOCTL_DEBUG_CORE

   \code
   IOCTL_MEI_dbgAccess_t MEI_dbg_access;
   MEI_dbg_access.count     = count;
   MEI_dbg_access.dbgAddr   = offset;
   MEI_dbg_access.pData_32  = (unsigned int*) buffer;
   ret = ioctl(fd, FIO_MEI_DBG_CORE_WRITE, &MEI_dbg_access);
   \endcode
   \ingroup MEI_DEBUG_IOCTL */
#define FIO_MEI_DBG_CORE_WRITE         _IO(MEI_IOC_MAGIC, 38)

/** Read from the device CORE space via MEI (debug read)

   \param IOCTL_MEI_dbgAccess_t* points to a
      \ref IOCTL_MEI_dbgAccess_t structure

   \return
      - 0 if successful, otherwise -1

   \remarks
   The return code is always returned via the param struct.
      - e_MEI_ERR_INVAL_STATE device still not init
      - e_MEI_ERR_OP_FAILED operation failed

   \remarks    This is the same as \ref FIO_MEI_DBG_READ with
      dbgDest = MEI_IOCTL_DEBUG_CORE

   \code
   IOCTL_MEI_dbgAccess_t MEI_dbg_access;
   MEI_dbg_access.count     = count;
   MEI_dbg_access.dbgAddr   = offset;
   MEI_dbg_access.pData_32  = (unsigned int*) buffer;
   ret = ioctl(fd, FIO_MEI_DBG_CORE_READ, &MEI_dbg_access);
   \endcode
   \ingroup MEI_DEBUG_IOCTL */
#define FIO_MEI_DBG_CORE_READ          _IO(MEI_IOC_MAGIC, 39)

/** Write to the device LOAD/STORE space via MEI (debug write)

   \param IOCTL_MEI_dbgAccess_t* points to a
      \ref IOCTL_MEI_dbgAccess_t structure

   \return
      - 0 if successful, otherwise -1

   \remarks
   The return code is always returned via the param struct.
      - e_MEI_ERR_INVAL_STATE device still not init
      - e_MEI_ERR_OP_FAILED operation failed

   \remarks    This is the same as \ref FIO_MEI_DBG_WRITE with
      dbgDest = MEI_IOCTL_DEBUG_LDST

   \code
   IOCTL_MEI_dbgAccess_t MEI_dbg_access;
   MEI_dbg_access.count     = count;
   MEI_dbg_access.dbgAddr   = offset;
   MEI_dbg_access.pData_32  = (unsigned int*) buffer;
   ret = ioctl(fd, FIO_MEI_DBG_LS_WRITE, &MEI_dbg_access);
   \endcode
   \ingroup MEI_DEBUG_IOCTL */
#define FIO_MEI_DBG_LS_WRITE           _IO(MEI_IOC_MAGIC, 40)

/** Read from the device LOAD/STORE space via MEI (debug read)

   \param IOCTL_MEI_dbgAccess_t* points to a
      \ref IOCTL_MEI_dbgAccess_t structure

   \return
      - 0 if successful, otherwise -1

   \remarks
   The return code is always returned via the param struct.
      - e_MEI_ERR_INVAL_STATE device still not init
      - e_MEI_ERR_OP_FAILED operation failed

   \remarks    This is the same as \ref FIO_MEI_DBG_READ with
      dbgDest = MEI_IOCTL_DEBUG_LDST

   \code
     IOCTL_MEI_dbgAccess_t MEI_dbg_access;
     MEI_dbg_access.count     = count;
     MEI_dbg_access.dbgAddr   = offset;
     MEI_dbg_access.pData_32  = (unsigned int*) buffer;
     ret = ioctl(fd, FIO_MEI_DBG_LS_READ, &MEI_dbg_access);
   \endcode
   \ingroup MEI_DEBUG_IOCTL */
#define FIO_MEI_DBG_LS_READ            _IO(MEI_IOC_MAGIC, 41)

/** This service toggles the message loop within the driver.
   All sent messages are looped back to the receive queue
   without accessing the hardware.

   \param IOCTL_MEI_drvLoop_t* points to a
      \ref IOCTL_MEI_drvLoop_t structure

   \remarks
   0 for loop off, 1 for loop on

   \return
      - 0 if successful, otherwise -1

   \remarks
   The return code is always returned via the param struct.

   \code
     IOCTL_MEI_drvLoop_t drvLoop;

     drvLoop.loopEnDis     = 1;
     ret = ioctl(fd, FIO_MEI_DRV_LOOP, &drvLoop);
   \endcode
   \ingroup MEI_DEBUG_IOCTL */
#define FIO_MEI_DRV_LOOP               _IO(MEI_IOC_MAGIC, 15)

/** MEI CPE Mailbox: receive NFC's enable
   Init the receive NFC part for this open instance.
   - allocates the corresponding buffers and structs
   - add the buffer to the device NFC list.

   \param IOCTL_MEI_ioctl_t* points to a
      \ref IOCTL_MEI_ioctl_t structure


   \return
      - 0 if successful, otherwise -1

   \remarks
   The return code is always returned via the param struct.
      - e_MEI_ERR_INVAL_STATE device still not init
      - e_MEI_ERR_ALREADY_DONE feature already enabled
      - e_MEI_ERR_NO_MEM not enough memory

   \remarks
      To allow receiving notifications from the device the current
      driver instance must be able to handle and store the incoming messages.
      The required buffers must be set in a "per open instance" way.
      Therefore the device instance manages a list of all open instances which are
      enabled to receive incoming NFC's

      These function is also allowded before the device init ioctl(). So
      ensure that no MEI access will be done before the device init ioctl call.
      See: interrupt enable / disable

   \code
     IOCTL_MEI_ioctl_t drvIoCtl;
     ret = ioctl(fd, FIO_MEI_MBOX_NFC_ENABLE, &drvIoCtl);
   \endcode
   \ingroup MEI_COMMON_IOCTL */
#define FIO_MEI_MBOX_NFC_ENABLE        _IO(MEI_IOC_MAGIC, 50)

/** MEI CPE Mailbox: receive NFC's disable
   Cleanup the receive NFC part for this open instance.
      - remove the buffer from the device NFC list
      - free the corresponding buffers and structs

   \param IOCTL_MEI_ioctl_t* points to a
      \ref IOCTL_MEI_ioctl_t structure

   \return
      - 0 if successful, otherwise -1

   \remarks
   The return code is always returned via the param struct.

   \remarks
   To allow receiving notifications from the device the current
   driver instance must be able to handle and store the incoming messages.
   The required buffers must be set in a "per open instance" way.
   Therefore the device instance manages a list of all open instances which are
   enabled to receive incoming NFC's

   These function is also allowded before the device init ioctl(). So
   ensure that no MEI access will be done before the device init ioctl call.
   See: interrupt enable / disable

   \code
     IOCTL_MEI_ioctl_t drvIoCtl;
     ret = ioctl(fd, FIO_MEI_MBOX_NFC_DISABLE, &drvIoCtl);
   \endcode
   \ingroup MEI_COMMON_IOCTL */
#define FIO_MEI_MBOX_NFC_DISABLE       _IO(MEI_IOC_MAGIC, 51)


/** This sets the MEI CPE driver message control for autonomous messages.

   \param IOCTL_MEI_autoMsgCtrl_t* points to the
      \ref IOCTL_MEI_autoMsgCtrl_t control structure

   \return
      - 0 if successful, otherwise -1

   \remarks
   The return code is always returned via the param struct.


   \code
   IOCTL_MEI_autoMsgCtrl_t autoMsgCtrl;
   memset(&autoMsgCtrl, 0x00, sizeof(IOCTL_MEI_autoMsgCtrl_t));
   autoMsgCtrl.modemMsgMask  = MEI_DRV_MSG_CTRL_IF_MODEM_ALL_ON;
   autoMsgCtrl.driverMsgMask = MEI_DRV_MSG_CTRL_IF_DRIVER_ALL_OFF;
   ret = ioctl(fd, FIO_MEI_AUTO_MSG_CTRL_SET, &autoMsgCtrl);
   \endcode

   \ingroup MEI_COMMON_IOCTL
*/
#define FIO_MEI_AUTO_MSG_CTRL_SET      _IO(MEI_IOC_MAGIC, 70)


/** This returns the MEI CPE driver message control for autonomous messages.

   \param IOCTL_MEI_autoMsgCtrl_t* points to the
      \ref IOCTL_MEI_autoMsgCtrl_t control structure

   \return
      - 0 if successful, otherwise -1

   \remarks
   The return code is always returned via the param struct.
   The current settings are returned via the given argument.


   \code
   IOCTL_MEI_autoMsgCtrl_t autoMsgCtrl;
   memset(&autoMsgCtrl, 0x00, sizeof(IOCTL_MEI_autoMsgCtrl_t));
   ret = ioctl(fd, FIO_MEI_AUTO_MSG_CTRL_GET, &autoMsgCtrl);
   \endcode

   \ingroup MEI_COMMON_IOCTL
*/
#define FIO_MEI_AUTO_MSG_CTRL_GET      _IO(MEI_IOC_MAGIC, 71)

/** MEI CPE Mailbox: write message (see message catalog)

   \param IOCTL_MEI_message_t* points to the
      \ref IOCTL_MEI_message_t message structure

   \return
      - 0 if successful, otherwise -1

   \remarks
   The return code is always returned via the param struct.
      - e_MEI_ERR_INVAL_STATE invalid state for write messages
      - e_MEI_ERR_GET_ARG get user data
      - e_MEI_ERR_DEV_NO_RESP no response from device
      - e_MEI_ERR_MSG_PARAM invalid message parameter

   \code
   IOCTL_MEI_message_t message;
   message.msgClassifier = msg_classifier;
   message.msgId         = msg_ID;
   message.paylSize_byte = msg_payload_bytes;
   message.pPayload      = (unsigned char*)msg_Payload;
   ret = ioctl(fd, FIO_MEI_MBOX_MSG_WR, &message);
   \endcode

   \ingroup MEI_COMMON_IOCTL
*/
#define FIO_MEI_MBOX_MSG_WR            _IO(MEI_IOC_MAGIC, 52)

/** MEI CPE Mailbox: check for and read ACK message

   \param IOCTL_MEI_message_t* points to the
      \ref IOCTL_MEI_message_t message structure

   \return
      - length of msg if successful, otherwise
      - -e_MEI_ERR_INVAL_STATE invalid state for write messages
      - -e_MEI_ERR_RETURN_ARG return data to the user
      - -e_MEI_ERR_DEV_NEG_RESP negative response
      - -e_MEI_ERR_DEV_INVAL_RESP invalid response

   \remarks
   The number of payload bytes is set within the ioctl argument
   message.paylSize_byte field.

   \code
   IOCTL_MEI_message_t message;
   ret = ioctl(fd, FIO_MEI_MBOX_ACK_RD, &message);
   \endcode

   \ingroup MEI_COMMON_IOCTL */
#define FIO_MEI_MBOX_ACK_RD            _IO(MEI_IOC_MAGIC, 53)

/** MEI CPE Mailbox: send message and wait for ACK

   \param IOCTL_MEI_messageSend_t* points to the
      \ref IOCTL_MEI_messageSend_t message structure

   \return
      - length of msg if successful, otherwise
      - -e_MEI_ERR_INVAL_STATE invalid state for write messages
      - -e_MEI_ERR_OP_FAILED write operation failed
      - -e_MEI_ERR_RETURN_ARG return data to the user
      - -e_MEI_ERR_DEV_NO_RESP no response from device
      - -e_MEI_ERR_DEV_NEG_RESP negative response
      - -e_MEI_ERR_DEV_INVAL_RESP invalid response


   \code
   IOCTL_MEI_messageSend_t messageSend;
   messageSend.write_msg.msgClassifier = msg_classifier;
   messageSend.write_msg.msgId         = msg_ID;
   messageSend.write_msg.paylSize_byte = msg_payload_bytes;
   messageSend.write_msg.pPayload      = (unsigned char*)msg_Payload;
   ret = ioctl(fd, FIO_MEI_MBOX_MSG_SEND, &messageSend);
   \endcode

   \ingroup MEI_COMMON_IOCTL */
#define FIO_MEI_MBOX_MSG_SEND          _IO(MEI_IOC_MAGIC, 54)

/** MEI CPE Mailbox: check for and read NFC message

   \param IOCTL_MEI_message_t* points to the
      \ref IOCTL_MEI_message_t message structure

   \return
      - length of msg if successful, 0 if no message found, otherwise
      - -e_MEI_ERR_INVAL_STATE invalid state for write messages
      - -e_MEI_ERR_RETURN_ARG return data to the user
      - -e_MEI_ERR_DEV_NEG_RESP negative response

   \remarks
   The number of payload bytes is set within the ioctl argument
   message.paylSize_byte field.

   \code
   IOCTL_MEI_message_t message;
   ret = ioctl(fd, FIO_MEI_MBOX_NFC_RD, &message);
   \endcode

   \ingroup MEI_COMMON_IOCTL */
#define FIO_MEI_MBOX_NFC_RD            _IO(MEI_IOC_MAGIC, 55)


/*
   Note:
      RAW means the "CMV message" format
*/
/** MEI CPE Mailbox: write RAW message

   \param IOCTL_MEI_mboxMsg_t* points to the
      \ref IOCTL_MEI_mboxMsg_t message structure

   \return
      - 0 if successful, otherwise -1

   \remarks
   The return code is always returned via the param struct.
      - -e_MEI_ERR_INVAL_STATE invalid state for write messages
      - -e_MEI_ERR_GET_ARG get message from user
      - -e_MEI_ERR_MSG_PARAM invalid message parameter
      - -e_MEI_ERR_OP_FAILED write operation failed

   \code
   IOCTL_MEI_mboxMsg_t message;
   message.count     = cmv_message_bytes;
   message.pData_16  = (unsigned short*) cmv_message_data;
   ret = ioctl(fd, FIO_MEI_MBOX_MSG_RAW_WR, &message);
   \endcode
   \ingroup MEI_DEBUG_IOCTL */
#define FIO_MEI_MBOX_MSG_RAW_WR        _IO(MEI_IOC_MAGIC, 56)

/** MEI CPE Mailbox: check for and read RAW ACK message

   \param IOCTL_MEI_mboxMsg_t* points to the
      \ref IOCTL_MEI_mboxMsg_t message structure

   \return
      - number of read bytes
      - -e_MEI_ERR_INVAL_STATE invalid state for write messages
      - -e_MEI_ERR_RETURN_ARG return data to the user

   \remarks

   \code
   IOCTL_MEI_mboxMsg_t message;
   message.count     = cmv_message_buffer_bytes;
   message.pData_16  = (unsigned short*) cmv_message_data_buffer;
   ret = ioctl(fd, FIO_MEI_MBOX_ACK_RAW_RD, &message);
   \endcode
   \ingroup MEI_DEBUG_IOCTL */
#define FIO_MEI_MBOX_ACK_RAW_RD        _IO(MEI_IOC_MAGIC, 57)

/** MEI CPE Mailbox: send message and wait for RAW ACK

   \param IOCTL_MEI_mboxMsg_t* points to the
      \ref IOCTL_MEI_mboxMsg_t message structure

   \return
      - number of bytes read
      - -e_MEI_ERR_INVAL_STATE invalid state for write messages
      - -e_MEI_ERR_GET_ARG get message from user
      - -e_MEI_ERR_RETURN_ARG return data to the user
      - -e_MEI_ERR_MSG_PARAM invalid message parameter
      - -e_MEI_ERR_OP_FAILED write operation failed

   \remarks If successful the IOCTL_MEI_mboxMsg_t structure
      contains the acknowledge after return.

   \code
   IOCTL_MEI_mboxMsg_t message;
   message.count     = cmv_message_bytes;
   message.pData_16  = (unsigned short*) cmv_message_data;
   ret = ioctl(fd, FIO_MEI_MBOX_MSG_RAW_SEND, &message);
   \endcode
   \ingroup MEI_DEBUG_IOCTL */
#define FIO_MEI_MBOX_MSG_RAW_SEND      _IO(MEI_IOC_MAGIC, 58)

/** MEI CPE Mailbox: check for and read RAW NFC message

   \param IOCTL_MEI_mboxMsg_t* points to the
      \ref IOCTL_MEI_mboxMsg_t message structure

   \return
      - number of read bytes, otherwise
      - -e_MEI_ERR_INVAL_STATE invalid state for write messages
      - -e_MEI_ERR_RETURN_ARG return data to the user

   \remarks

   \code
   IOCTL_MEI_mboxMsg_t message;
   message.count     = cmv_message_buffer_bytes;
   message.pData_16  = (unsigned short*) cmv_message_data_buffer;
   ret = ioctl(fd, FIO_MEI_MBOX_NFC_RAW_RD, &message);
   \endcode
   \ingroup MEI_DEBUG_IOCTL */
#define FIO_MEI_MBOX_NFC_RAW_RD        _IO(MEI_IOC_MAGIC, 59)



/** For debug only: printout the MEI Register set
   \param IOCTL_MEI_ioctl_t* points to a
      \ref IOCTL_MEI_ioctl_t structure

   \return
      - 0 if successful, otherwise -1

   \remarks
   The return code is always returned via the param struct.

*/
#define FIO_MEI_MEI_REGS_SHOW          _IO(MEI_IOC_MAGIC, 60)

/** For debug only: printout the internal driver buffer
\attention
   Not further supported with driver version > 0.1.5.x
*/
#define FIO_MEI_DRV_BUF_SHOW           _IO(MEI_IOC_MAGIC, 61)

/** For debug only: make an DMA test */
#define FIO_MEI_DMA_TEST               _IO(MEI_IOC_MAGIC, 64)

/* ==========================================================================
   ioctl commands (MEI CPE ATM OAM Insert/Extract)
   ========================================================================== */
#define MEI_ATMOAM_IOC_MAGIC            'T'

/** This service makes the setup the ATM OAM feature on the device.
   \remark
   This call is required before any use of the ATM OAM feature. Internaly the
   driver allocates the required structures.

   \param IOCTL_MEI_ATMOAM_init_t* The parameter points to a
          \ref IOCTL_MEI_ATMOAM_init_t structure

   \return
      - 0 if successful, otherwise -1

   \remarks
   The return code is always returned via the param struct.
   Currently supported for the Vinax device only.

   \code
      IOCTL_MEI_ATMOAM_init_t atmOamInit;
      ret = ioctl(fd, FIO_MEI_ATMOAM_INIT, &atmOamInit);
   \endcode
   \ingroup MEI_ATMOAM_IOCTL
*/
#define FIO_MEI_ATMOAM_INIT             _IO(MEI_ATMOAM_IOC_MAGIC, 1)

/** This service enables the ATM OAM feature on the device.

   \param IOCTL_MEI_ATMOAM_cntrl_t* The parameter points to a
          \ref IOCTL_MEI_ATMOAM_cntrl_t structure

   \return
      - 0 if successful, otherwise -1

   \remarks
   The return code is always returned via the param struct.

   \remark
   ATM OAM Operation Mode:
      If "AUTO" mode is selected the driver setup the
      control and transparent settings internally.
      If "DIRECT" mode is selected the user has to setup the
      control and transparent settings manually.
   Currently supported for the Vinax device only.

   \code
      IOCTL_MEI_ATMOAM_cntrl_t atmOamCntrl;
      atmOamCntrl.direction = 0;
      atmOamCntrl.linkNo    = 0;

      atmOamCntrl.aoOpMode    = MEI_ATMOAM_OPERATION_MODE_AUTO;
      atmOamCntrl.aoTransMode = MEI_ATMOAM_INIT_TRANS_MODE_NONE;
      atmOamCntrl.aoCntrl     = MEI_ATMOAM_ENABLE_CNTRL_EVT_NONE;

      ret = ioctl(fd, FIO_MEI_ATMOAM_CNTRL, &atmOamCntrl);
   \endcode
   \ingroup MEI_ATMOAM_IOCTL
*/
#define FIO_MEI_ATMOAM_CNTRL            _IO(MEI_ATMOAM_IOC_MAGIC, 2)

/** This service requests the ATM OAM service counter from the Device.

   \param IOCTL_MEI_ATMOAM_counter_t* The parameter points to a
          \ref IOCTL_MEI_ATMOAM_counter_t structure

   \return
      - 0 if successful, otherwise -1

   \remarks
   The return code is always returned via the param struct.
   Currently supported for the Vinax device only.

   \code
      IOCTL_MEI_ATMOAM_counter_t atmOamDevCnt;
      ret = ioctl(fd, FIO_MEI_ATMOAM_REQ_DEV_COUNTER, &atmOamCntrl);
   \endcode
   \ingroup MEI_ATMOAM_IOCTL
*/
#define FIO_MEI_ATMOAM_REQ_DEV_COUNTER  _IO(MEI_ATMOAM_IOC_MAGIC, 3)


/** This service requests the ATM OAM service status (from the driver).

   \param IOCTL_MEI_ATMOAM_status_t* The parameter points to a
          \ref IOCTL_MEI_ATMOAM_status_t structure

   \return
      - 0 if successful, otherwise -1

   \remarks
   The return code is always returned via the param struct.
   Currently supported for the Vinax device only.

   \code

   \endcode
   \ingroup MEI_ATMOAM_IOCTL
*/
#define FIO_MEI_ATMOAM_REQ_DRV_STATUS   _IO(MEI_ATMOAM_IOC_MAGIC, 4)

/** This service inserts the given ATM OAM cells to the Device (line side)

   \param IOCTL_MEI_ATMOAM_drvAtmCells_t* The parameter points to a
          \ref IOCTL_MEI_ATMOAM_drvAtmCells_t structure
          Internally the raw cell buffer is from
          type of \ref IOCTL_MEI_ATMOAM_rawCell_t structure.

   \return
      - 0 if successful, otherwise -1

   \remarks
   The return code is always returned via the param struct.
   Currently supported for the Vinax device only.

   \code
      IOCTL_MEI_ATMOAM_drvAtmCells_t atmOamCells;
      atmOamCells.cellCount = <number_of_cells_in_the_buffer;
      memcpy(&atmOamCells.atmCells[0], <&your_cell[0]>;
      memcpy(&atmOamCells.atmCells[1], <&your_cell[1]>;
      memcpy(&atmOamCells.atmCells[2], <&your_cell[2]>;
      memcpy(&atmOamCells.atmCells[3], <&your_cell[3]>;
      ret = ioctl(fd, FIO_MEI_ATMOAM_CELL_INSERT, &atmOamCells);
   \endcode
   \ingroup MEI_ATMOAM_IOCTL
*/
#define FIO_MEI_ATMOAM_CELL_INSERT      _IO(MEI_ATMOAM_IOC_MAGIC, 10)


/* ==========================================================================
   ioctl commands (MEI CPE Clear EOC)
   ========================================================================== */

#define MEI_CEOC_IOC_MAGIC              'U'

/** This service makes the setup for the Clear EOC feature.
   \remark
   This call is required before any use of the Clear EOC feature. Internaly the
   driver allocates the required structures.

   \param IOCTL_MEI_CEOC_init_t* The parameter points to a
          \ref IOCTL_MEI_CEOC_init_t structure

   \return
      - 0 if successful, otherwise -1

   \remarks
   The return code is always returned via the param struct.

   \code

   \endcode
   \ingroup MEI_CEOC_IOCTL
*/
#define FIO_MEI_CEOC_INIT               _IO(MEI_CEOC_IOC_MAGIC, 1)


/** This service configures and enables the Clear EOC feature on
   the MEI CPE driver and device.

   \remark
   The driver offers some operation mode which should be used.
   - MEI_CEOC_OPERATION_MODE_AUTO
   - MEI_CEOC_OPERATION_MODE_AUTO_READ
   - MEI_CEOC_OPERATION_MODE_POLL_READ
   Depending on the selected mode the driver makes the internal setup and
   device configuration automatically.

   \param IOCTL_MEI_CEOC_cntrl_t* The parameter points to a
          \ref IOCTL_MEI_CEOC_cntrl_t structure

   \return
      - 0 if successful, otherwise -1

   \remarks
   The return code is always returned via the param struct.

   \code

   \endcode
   \ingroup MEI_CEOC_IOCTL
*/
#define FIO_MEI_CEOC_CNTRL              _IO(MEI_CEOC_IOC_MAGIC, 2)

/** This service requests the Clear EOC Statistics MEI CPE Driver.

   \param IOCTL_MEI_CEOC_statistic_t* The parameter points to a
          \ref IOCTL_MEI_CEOC_statistic_t structure

   \return
      - 0 if successful, otherwise -1

   \remarks
   The return code is always returned via the param struct.

   \code

   \endcode
   \ingroup MEI_CEOC_IOCTL
*/
#define FIO_MEI_CEOC_STATS              _IO(MEI_CEOC_IOC_MAGIC, 3)


/** This service inserts a given EOC frame to the Device.

   \param IOCTL_MEI_CEOC_frame_t* The parameter points to a
          \ref IOCTL_MEI_CEOC_frame_t structure

   \return
      - 0 if successful, otherwise -1

   \remarks
   The return code is always returned via the param struct.

   \code

   \endcode
   \ingroup MEI_CEOC_IOCTL
*/
#define FIO_MEI_CEOC_FRAME_WR           _IO(MEI_CEOC_IOC_MAGIC, 11)


/** This service reads a received EOC frame from the Device.

   \remark
   Depending on the configured mode the availablity of the EOC frame is
   signaled via an event or must be polled.

   \param IOCTL_MEI_CEOC_frame_t* The parameter points to a
          \ref IOCTL_MEI_CEOC_frame_t structure

   \return
      - 0 if successful, otherwise -1

   \remarks
   The return code is always returned via the param struct.

   \code

   \endcode
   \ingroup MEI_CEOC_IOCTL
*/
#define FIO_MEI_CEOC_FRAME_RD           _IO(MEI_CEOC_IOC_MAGIC, 12)

#define MEI_ETHER_IOC_MAGIC            'V'

/* ==========================================================================
   ioctl commands (MEI CPE entity)
   ========================================================================== */

/** magic number */
#define MEIX_IOC_MAGIC 'S'

/** This controls the channel specific debug trace via the entity control.
   The corresponding devices have to been selected via the modem mask.
   This service is non-blocking.

   \param IOCTL_MEIX_debugSet_t* points to the
      \ref IOCTL_MEIX_debugSet_t argument struct.


   \return
      - 0 if successful, otherwise -1
      - the corresponding flags within the modem mask will be cleared.

   \remarks
   The return code is always returned via the param struct.
   - In case of error the number of devices which has been not updated.
     Also the corresponding flags within the mask are not cleared.

   \code
   IOCTL_MEIX_debugSet_t debugSet;
   debugSet.dbgInfo = debugInfo;
   debugSet.dfemask[0]  = dfeDevices_00_31;
   debugSet.dfemask[1]  = dfeDevices_32_63;
   debugSet.dfemask[2]  = dfeDevices_64_95;
   debugSet.dfemask[3]  = dfeDevices_96_127;
   ret = ioctl(fd, FIO_MEIX_CH_TRACE_SET, &debugSet);
   \endcode
   \ingroup MEI_COMMON_IOCTL
*/
#define FIO_MEIX_CH_TRACE_SET          _IO(MEIX_IOC_MAGIC, 10)

/** This controls the channel specific debug trace via the entity control.
   The corresponding devices have to been selected via the modem mask.
   This service is non-blocking.

   \param IOCTL_MEIX_debugSet_t* points to the
      \ref IOCTL_MEIX_debugSet_t argument struct.


   \return
      - 0 if successful, otherwise -1
      - the corresponding flags within the modem mask will be cleared.

   \remarks
   The return code is always returned via the param struct.
   - In case of error the number of devices which has been not updated.
     Also the corresponding flags within the mask are not cleared.

   \code
   IOCTL_MEIX_debugSet_t debugSet;
   debugSet.dbgInfo = debugInfo;
   debugSet.dfemask[0]  = dfeDevices_00_31;
   debugSet.dfemask[1]  = dfeDevices_32_63;
   debugSet.dfemask[2]  = dfeDevices_64_95;
   debugSet.dfemask[3]  = dfeDevices_96_127;
   ret = ioctl(fd, FIO_MEIX_CH_LOG_SET, &debugSet);
   \endcode
   \ingroup MEI_COMMON_IOCTL
*/
#define FIO_MEIX_CH_LOG_SET            _IO(MEIX_IOC_MAGIC, 11)



/* ==========================================================================
   Argument structs for ioctl system call (MEI CPE device)
   ========================================================================== */

/** ioctl structure for IO control of the MEI CPE driver.
*/
typedef struct
{
   /** returns the ioctl error/return code */
   int            retCode;

} IOCTL_MEI_ioctl_t;


/**
   Define MEI CPE debug levels for ioctl interface
*/
#ifndef MEI_DRV_PRN_LEVEL_OFF
#define MEI_DBG_LEVEL_OFF     4
#else
#define MEI_DBG_LEVEL_OFF     MEI_DRV_PRN_LEVEL_OFF
#endif

#ifndef MEI_DRV_PRN_LEVEL_HIGH
#define MEI_DBG_LEVEL_HIGH    3
#else
#define MEI_DBG_LEVEL_HIGH    MEI_DRV_PRN_LEVEL_HIGH
#endif

#ifndef MEI_DRV_PRN_LEVEL_NORMAL
#define MEI_DBG_LEVEL_NORMAL  2
#else
#define MEI_DBG_LEVEL_NORMAL  MEI_DRV_PRN_LEVEL_NORMAL
#endif

#ifndef MEI_DRV_PRN_LEVEL_LOW
#define MEI_DBG_LEVEL_LOW     1
#else
#define MEI_DBG_LEVEL_LOW     MEI_DRV_PRN_LEVEL_LOW
#endif


/** ioctl structure for set the driver debug level.
*/
typedef struct
{
   /** control data of the ioctl */
   IOCTL_MEI_ioctl_t ictl;

   /** new debug level to set */
   unsigned int   valLevel;
} IOCTL_MEI_dbgLevel_t;


/** ioctl structure for get the driver version string.
*/
typedef struct
{
   /** control data of the ioctl */
   IOCTL_MEI_ioctl_t ictl;

   /** points to the user version string */
   char           *pVersionStr;
   /** size of the user version string */
   unsigned int   strSize;

   /** driver version id (hex) */
   unsigned int   versionId;
} IOCTL_MEI_drvVersion_t;



/** ioctl structure for init the device.
\remark
   The INIT_DEV settings can be only set once after an open device and
   should be the first action.
   Without initial ioctl(..., FIO_MEI_DEV_INIT, ...) the device
   cannot work.

*/
typedef struct
{
   /** control data of the ioctl */
   IOCTL_MEI_ioctl_t ictl;

   /** used IRQ of the corresponding MEI */
   unsigned int  usedIRQ;
   /** base address of the corresponding MEI */
   unsigned int  meiBaseAddr;
} IOCTL_MEI_devInit_t;


/** ioctl structure for init the driver.
*/
typedef struct
{
   /** control data of the ioctl */
   IOCTL_MEI_ioctl_t ictl;

   /** set to "1" will block the driver timeouts between host and modem */
   unsigned int blockTimeout;
   /**  timeout [ms] for host modem communication - normal message handling */
   unsigned int waitModemMsg_ms;
   /**  timeout [ms] for first modem responce after startup (download) */
   unsigned int waitFirstResp_ms;
   /**  timeout [ms] for the first ROM code responce (bootmode 8/9 only) */
   unsigned int bmWaitForDl_ms;
   /**  timeout [ms] for the download setup done (bootmode 8/9 only) */
   unsigned int bmWaitDlInit_ms;
   /**  timeout [ms] download message flow control (bootmode 8/9 only) */
   unsigned int bmWaitNextBlk_ms;
   /**  Bus width for MEI CPE RAM Access (bootmode 8/9 only) */
   unsigned int bmDatawidth;
   /**  Wait States for MEI CPE RAM Access (bootmode 8/9 only) */
   unsigned int bmWaitStates;
} IOCTL_MEI_drvInit_t;


/** modem Driver Reset Modes */
typedef enum
{
   /** Reset activate and then deactivate */
   e_MEI_RESET = 0,
   /** Reset activate (not supported for VR9)*/
   e_MEI_RESET_ACTIVATE = 1,
   /** Reset deactivate (not supoprted for VR9)*/
   e_MEI_RESET_DEACTIVATE = 2
} IOCTL_MEI_resetMode_e;

/**
   ioctl flags for reset of the modem via MEI
   - bit 0: XMEM_RST - external mem controller.
   - bit 1: DSP_RST  - reset all of ALCMENE
                        (except external mem controller and MEI regs).
   - bit 2: XDSL_RST - XDSL accelerator SW controlled reset.
   - bit 3: SPI_RST  - Serial peripheral interface reset.
   - bit 4: PER_RST  - Peripheral reset
*/
#define MEI_IOCTL_HW_RST_MASK_ALL   0x1F

/** ioctl structure for reset control of the device and the driver.
*/
typedef struct
{
   /** control data of the ioctl */
   IOCTL_MEI_ioctl_t ictl;

   /** gives the reset mode (action) */
   IOCTL_MEI_resetMode_e rstMode;
   /** gives the select mask of the blocks for reset (ignored for VR9) */
   unsigned int rstSelMask;
} IOCTL_MEI_reset_t;


/** structure for request the driver config / setup */
typedef struct
{
   /** control data of the ioctl */
   IOCTL_MEI_ioctl_t ictl;

   /*-- driver config            --*/
   /** Device num */
   unsigned int devNum;
   /** Current open instances */
   unsigned int currOpenInst;
   /** Phy. base address */
   unsigned int phyBaseAddr;
   /** Virt. base address */
   unsigned int virtBaseAddr;
   /** Used IRQ (0: polling mode) */
   unsigned int usedIRQ;
   /** Driver max ARC2ME mailbox size */
   unsigned int drvArc2MeMbSize;
   /** Driver max ME2ARC mailbox size */
   unsigned int drvMe2ArcMbSize;

   /** Arc2Me Mailbox addr while boot */
   unsigned int Arc2MeBootMbAddr;
   /** Arc2Me Mailbox size while boot */
   unsigned int Arc2MeBootMbSize;
   /** Me2Arc Mailbox addr while boot */
   unsigned int Me2ArcBootMbAddr;
   /** Me2Arc Mailbox size while boot */
   unsigned int Me2ArcBootMbSize;

   /*-- chip config              --*/
   /** Chip Boot CFG - boot mode */
   unsigned int bootMode;
   /** Chip Boot CFG - chip id */
   unsigned int chipId;
   /** Arc2Me Mailbox addr while online */
   unsigned int Arc2MeOnlineMbAddr;
   /** Arc2Me Mailbox size while online */
   unsigned int Arc2MeOnlineMbSize;
   /** Me2Arc Mailbox addr while online */
   unsigned int Me2ArcOnlineMbAddr;
   /** Me2Arc Mailbox size while online */
   unsigned int Me2ArcOnlineMbSize;

   /*-- dynamic informations     --*/
   /** current driver state */
   unsigned int currDrvState;
   unsigned int currModemFsmState;

} IOCTL_MEI_reqCfg_t;


/**
   ioctl structure for MEI CPE interface statistic data.
*/
typedef struct
{
   /** control data of the ioctl */
   IOCTL_MEI_ioctl_t ictl;

   /** GP1 interrupt count - ROM code entered */
   unsigned int      dfeGp1IntCount;
   /** Message available interrupt count */
   unsigned int      dfeMsgAvIntCount;
   /** Codeswap count */
   unsigned int      dfeCodeSwapCount;

   /** recv msg count */
   unsigned int      recvMsgCount;
   /** recv msg error count */
   unsigned int      recvMsgErrCount;
   /** recv msg discard count */
   unsigned int      recvMsgDiscardCount;

   /** recv ACK count */
   unsigned int      recvAckCount;
   /** recv NFC count */
   unsigned int      recvNfcCount;
   /** discard NFC count - no waiting user */
   unsigned int      recvNfcDiscardCount;
   /** distribute NFC count */
   unsigned int      recvNfcDistCount;
   /** discard NFC count - while distribution (per instance) */
   unsigned int      recvNfcDistDiscardCount;

   /** discard NFC count - unkown msg type */
   unsigned int      recvNfcUnknownDiscardCount;

   /** send msg count */
   unsigned int      sendMsgCount;
   /** error count */
   unsigned int      errorCount;

   /** timing: max time wait for ack (recv) */
   unsigned int      maxRecvWaitForHwAck;
   /** timing: max time wait for ack (send) */
   unsigned int      maxSendWaitForHwAck;

   /** control: firmware download count */
   unsigned int      fwDlCount;
   /** control: firmware download error count */
   unsigned int      fwDlErrCount;

   /** control: drv reset count */
   unsigned int      drvSwRstCount;
   /** control: mei hw reset count */
   unsigned int      meiHwRstCount;

} IOCTL_MEI_statistic_t;


/**
   Download via ROM handler will be only possible if the
   CHIP_ID will match.
*/
#define MEI_DEF_DOWNLOAD_CHIPID  0x00

/** ioctl structure for MEI firmware download */
typedef struct
{
   /** control data of the ioctl */
   IOCTL_MEI_ioctl_t ictl;

   /** points to the MEI device firmware image */
   unsigned char *pFwImage;
   /** size of the firmware image [byte] */
   unsigned int  size_byte;
} IOCTL_MEI_fwDownLoad_t;

/** ioctl structure for MEI optimized firmware download */
typedef struct
{
   /** control data of the ioctl */
   IOCTL_MEI_ioctl_t ictl;

   /** points to the MEI device firmware image chunk*/
   unsigned char *pFwImageChunk;
   /** size of the firmware image chunk [byte] */
   unsigned int  size_byte;
   /** current chunk number [0... Last chunk] */
   unsigned int  chunk_num;
   /** Last Chunk indication flag. '0' - not a last chunk,
       everything else will indicate a last chunk */
   unsigned char bLastChunk;
} IOCTL_MEI_fwOptDownLoad_t;


/** start the firmware in VDSL2 mode (default) */
#define MEI_IOCTL_FW_MODE_VDSL2      0
/** start the firmware in ADSL mode */
#define MEI_IOCTL_FW_MODE_ADSL       1

/** ioctl structure for select the firmware mode (VDSL2 / ADSL).
*/
typedef struct
{
   /** control data of the ioctl */
   IOCTL_MEI_ioctl_t ictl;

   /** gives the select mask of the FW mode */
   unsigned int   fwMode;
} IOCTL_MEI_fwMode_t;

/**
   Definition of possible bonding mode selections. */
typedef enum
{
   /**
      Multi LineMode is not applicable.
      This means within context of configuration that no specific setting should
      be done. Within context of status it means no valid configuration is
      available so far. */
   e_MEI_MULTI_LINEMODE_NA = -1,
   /**
      Line mode configuration/status is Single. */
   e_MEI_MULTI_LINEMODE_SINGLE = 0,
   /**
      Line Mode configuration/status is Dual. */
   e_MEI_MULTI_LINEMODE_DUAL = 1,
   /**
      Delimiter only! */
   e_MEI_MULTI_LINEMODE_LAST = 2
} IOCTL_MEI_multiLineMode_t;

/**
   Definition of possible xDSL mode selections. */
typedef enum
{
   /**
      xDSL mode is not applicable.
      This means within context of configuration that no specific setting should
      be done. Within context of status it means no valid configuration is
      available so far. */
   e_MEI_XDSLMODE_NA = -1,
   /**
      xDSL mode configuration/status is VDSL. */
   e_MEI_XDSLMODE_VDSL = 0,
   /**
      xDSL mode configuration/status is ADSL. */
   e_MEI_XDSLMODE_ADSL = 1,
   /**
      Delimiter only! */
   e_MEI_XDSLMODE_LAST = 2
} IOCTL_MEI_xdslMode_t;

/**
   ioctl structure for firmware xDSL/DualPort mode control setup. Configuration
   has to be done before firmware download to specify which configuration shall
   be used for the next link activation.
*/
typedef struct
{
   /**
      control data of the ioctl */
   IOCTL_MEI_ioctl_t ictl;
   /**
      Lock mode for bonding applications.
      \note Bonding applications are currently not supported Therefore this
            parameter has no influence so far. */
   IFX_boolean_t bMultiLineModeLock;
   /**
      Defines the preferred number of lines to be used for bonding
      applications.
      \note Bonding applications are currently not supported Therefore this
            parameter has no influence so far. */
   IOCTL_MEI_multiLineMode_t eMultiLineModePreferred;
   /**
      Defines the current number of lines to be used for bonding
      applications.
      \note Bonding applications are currently not supported Therefore this
            parameter has no influence so far. It is set fixed and internally to
            IOCTL_MEI_multiLineMode_t::e_MEI_MULTI_LINEMODE_SINGLE. */
   IOCTL_MEI_multiLineMode_t eMultiLineModeCurrent;
   /**
      Lock mode for xDSL mode selection. */
   IFX_boolean_t bXdslModeLock;
   /**
      Defines the preferred xDSL mode to be used for next link activation.
      \note Currently not used*/
   IOCTL_MEI_xdslMode_t eXdslModePreferred;
   /**
      Defines the current xDSL mode to be used for next link activation. */
   IOCTL_MEI_xdslMode_t eXdslModeCurrent;
} IOCTL_MEI_FwModeCtrlSet_t;

/**
   ioctl structure for firmware xDSL/DualPort mode status.
*/
typedef struct
{
   /**
      Control data of the ioctl */
   IOCTL_MEI_ioctl_t ictl;
   /**
      Returns the current number of lines used for bonding applications.
      \note Bonding applications are currently not supported Therefore this
            parameter will be always
            IOCTL_MEI_multiLineMode_t::e_MEI_MULTI_LINEMODE_SINGLE so far. */
   IOCTL_MEI_multiLineMode_t eMultiLineModeCurrent;
   /**
      Returns the current xDSL mode used for link activation. */
   IOCTL_MEI_xdslMode_t eXdslModeCurrent;
} IOCTL_MEI_FwModeStatGet_t;

/** structure for Register ioctl's */
typedef struct
{
   /** control data of the ioctl */
   IOCTL_MEI_ioctl_t ictl;

   /** register address */
   unsigned int addr;
   /** register value */
   unsigned int value;
} IOCTL_MEI_regInOut_t;


/**
   Genaral Purpose Access destinations
*/
/** memory access */
#define MEI_IOCTL_GPA_DEST_MEM            0x0
/** aux register access */
#define MEI_IOCTL_GPA_DEST_AUX            0x1

/** structure for General Purpose Access ioctl's */
typedef struct
{
   /** control data of the ioctl */
   IOCTL_MEI_ioctl_t ictl;

   /** destination of the General Purpose Access */
   unsigned int dest;
   /** register address */
   unsigned int addr;
   /** register value */
   unsigned int value;
} IOCTL_MEI_GPA_accessInOut_t;


/*
   Max count of register within one ioctl DBG access call
*/
#define MEI_IOCTL_MAX_DBG_COUNT_32BIT     0x100
#define MEI_IOCTL_DEBUG_AUX               0x0
#define MEI_IOCTL_DEBUG_LDST              0x2
#define MEI_IOCTL_DEBUG_CORE              0x3

/** ioctl structure for read/write action via MEI (debug) */
typedef struct
{
   /** control data of the ioctl */
   IOCTL_MEI_ioctl_t ictl;

   /** debug destination/source address within the MEI CPE */
   unsigned int dbgAddr;
   /** address space within the MEI CPE (CORE, AUX, Load/Store) */
   unsigned int dbgDest;
   /** number of data units for read/write (32-Bit) */
   unsigned int count;
   /** points to the RD/WR user buffer or used for return if count = 1 */
   unsigned int *pData_32;
} IOCTL_MEI_dbgAccess_t;


/** ioctl structure for read/write action via MEI (debug) */
typedef struct
{
   /** control data of the ioctl */
   IOCTL_MEI_ioctl_t ictl;

   /** DMA destination/source address within the MEI CPE */
   unsigned int dmaAddr;
   /** number of data units for read/write (32-Bit) */
   unsigned int count_32bit;
   /** points to the RD/WR user buffer */
   unsigned int *pData_32;
} IOCTL_MEI_DMA_access_t;

/** ioctl structure for driver loop control of the MEI CPE driver.
*/
typedef struct
{
   /** control data of the ioctl */
   IOCTL_MEI_ioctl_t ictl;

   /** loop enable/ disable */
   unsigned int   loopEnDis;
} IOCTL_MEI_drvLoop_t;


/** value:
      ioctl (FIO_MEI_AUTO_MSG_CTRL_SET)
      - enable flag for autonomous modem NOTIFICATION message */
#define MEI_DRV_MSG_CTRL_IF_MODEM_NFC_ON               0x00000001
/** value:
      ioctl (FIO_MEI_AUTO_MSG_CTRL_SET)
      - enable flag for autonomous modem EVENT message */
#define MEI_DRV_MSG_CTRL_IF_MODEM_EVT_ON               0x00000002
/** value:
      ioctl (FIO_MEI_AUTO_MSG_CTRL_SET)
      - enable flag for autonomous modem ALARM message */
#define MEI_DRV_MSG_CTRL_IF_MODEM_ALM_ON               0x00000004
/** value:
      ioctl (FIO_MEI_AUTO_MSG_CTRL_SET)
      - enable flag for autonomous modem debug message */
#define MEI_DRV_MSG_CTRL_IF_MODEM_DBG_ON               0x00000008
/** value:
      ioctl (FIO_MEI_AUTO_MSG_CTRL_SET)
      - enable flags for autonomous modem ALL message */
#define MEI_DRV_MSG_CTRL_IF_MODEM_ALL_ON               0x000000FF
/** value:
      ioctl (FIO_MEI_AUTO_MSG_CTRL_SET)
      - disable flag for autonomous modemmessage */
#define MEI_DRV_MSG_CTRL_IF_MODEM_ALL_OFF              0x00000000

/** value:
      ioctl (FIO_MEI_AUTO_MSG_CTRL_SET)
      - enable flags for autonomous modem eth frames */
#define MEI_DRV_MSG_CTRL_IF_MODEM_ETH_FRAME_ON         0x00001000
/** value:
      ioctl (FIO_MEI_AUTO_MSG_CTRL_SET)
      - enable flags for autonomous modem ATM OAM messages */
#define MEI_DRV_MSG_CTRL_IF_MODEM_ATMOAM_CELL_ON       0x00002000
/** value:
      ioctl (FIO_MEI_AUTO_MSG_CTRL_SET)
      - enable flags for autonomous modem EOC frames */
#define MEI_DRV_MSG_CTRL_IF_MODEM_EOC_FRAME_ON         0x00004000
/** value:
      ioctl (FIO_MEI_AUTO_MSG_CTRL_SET)
      - enable flags for autonomous modem extended ALL message */
#define MEI_DRV_MSG_CTRL_IF_MODEM_EXT_ALL_ON           0x00006000

/** value:
      ioctl (FIO_MEI_AUTO_MSG_CTRL_SET)
      - enable flag for autonomous driver messages - type EVENT */
#define MEI_DRV_MSG_CTRL_IF_DRIVER_TYPE_EVT_ON         0x00000002
/** value:
      ioctl (FIO_MEI_AUTO_MSG_CTRL_SET)
      - enable flag for autonomous driver messages - type ALARM */
#define MEI_DRV_MSG_CTRL_IF_DRIVER_TYPE_ALM_ON         0x00000004
/** value:
      ioctl (FIO_MEI_AUTO_MSG_CTRL_SET)
      - enable flag for autonomous driver messages - type ALL */
#define MEI_DRV_MSG_CTRL_IF_DRIVER_TYPE_ALL_ON         0x00000006

/** value:
      ioctl (FIO_MEI_AUTO_MSG_CTRL_SET)
      - enable flag for autonomous driver messages - module COMMON part */
#define MEI_DRV_MSG_CTRL_IF_DRIVER_MODULE_COM_ON       0x00000100
/** value:
      ioctl (FIO_MEI_AUTO_MSG_CTRL_SET)
      - enable flag for autonomous driver messages - module COMMON ControlX part */
#define MEI_DRV_MSG_CTRL_IF_DRIVER_MODULE_COMX_ON      0x00000200
/** value:
      ioctl (FIO_MEI_AUTO_MSG_CTRL_SET)
      - enable flag for autonomous driver messages - module ROM part */
#define MEI_DRV_MSG_CTRL_IF_DRIVER_MODULE_ROM_ON       0x00000400
/** value:
      ioctl (FIO_MEI_AUTO_MSG_CTRL_SET)
      - enable flag for autonomous driver messages - module Remote ATM OAM Access */
#define MEI_DRV_MSG_CTRL_IF_DRIVER_MODULE_REM_ATM_ON   0x00002000
/** value:
      ioctl (FIO_MEI_AUTO_MSG_CTRL_SET)
      - enable flag for autonomous driver messages - module Remote Clear EOC Access */
#define MEI_DRV_MSG_CTRL_IF_DRIVER_MODULE_REM_EOC_ON   0x00004000
/** value:
      ioctl (FIO_MEI_AUTO_MSG_CTRL_SET)
      - enable flag for autonomous driver messages - module ALL */
#define MEI_DRV_MSG_CTRL_IF_DRIVER_MODULE_ALL_ON       0x00001700
/** value:
      ioctl (FIO_MEI_AUTO_MSG_CTRL_SET)
      - enable flag for autonomous driver messages - module extended ALL */
#define MEI_DRV_MSG_CTRL_IF_DRIVER_MODULE_EXT_ALL_ON   0x00006000

/** value:
      ioctl (FIO_MEI_AUTO_MSG_CTRL_SET)
      - enable flags for autonomous driver messages - ALL */
#define MEI_DRV_MSG_CTRL_IF_DRIVER_ALL_ON          ((MEI_DRV_MSG_CTRL_IF_DRIVER_TYPE_ALL_ON) | \
                                                      (MEI_DRV_MSG_CTRL_IF_DRIVER_MODULE_ALL_ON))

/** value:
      ioctl (FIO_MEI_AUTO_MSG_CTRL_SET)
      - disable flags for autonomous driver messages - ALL */
#define MEI_DRV_MSG_CTRL_IF_DRIVER_ALL_OFF             0x00000000


/**
   ioctl structure for driver autonomous message control.
*/
typedef struct
{
   /** control data of the ioctl */
   IOCTL_MEI_ioctl_t ictl;

   /** autonomous modem message control mask */
   unsigned int   modemMsgMask;
   /** autonomous driver message control mask */
   unsigned int   driverMsgMask;
} IOCTL_MEI_autoMsgCtrl_t;


/**
   ioctl structure for MEI CPE mailbox write message (plain message).
   - check for mailbox busy, if free
   - write a msg to the device mailbox
*/
typedef struct
{
   /** control data of the ioctl */
   IOCTL_MEI_ioctl_t ictl;

   /** number of data units to write/read (16-Bit)
       - neg. value: signals an error
       - else: number of written/read data units */
   unsigned int   count_16bit;
   /** points to the RD/WR user buffer */
   unsigned short *pData_16;
} IOCTL_MEI_mboxMsg_t;

/**
   ioctl structure for MEI CPE mailbox send message (plain message).
   - check for mailbox busy, if free
   - write a msg to the device mailbox
   - wait and read the expected ACK.
*/
typedef struct
{
   /** control data of the ioctl */
   IOCTL_MEI_ioctl_t ictl;

   /** message to write to the mailbox */
   IOCTL_MEI_mboxMsg_t write_msg;
   /** message to read from the mailbox (normally expect ack) */
   IOCTL_MEI_mboxMsg_t ack_msg;
} IOCTL_MEI_mboxSend_t;


/** indicator for a device modem message */
#define MEI_MSG_CTRL_MODEM_MSG          0x00000000
/** indicator for a device Driver message */
#define MEI_MSG_CTRL_DRIVER_MSG         0x00010000

/** indicator for a device Ethernet Frame */
#define MEI_MSG_CTRL_CLEAR_ETH_FRAME    0x00001000
/** indicator for a device ATM OAM cell block */
#define MEI_MSG_CTRL_ATMOAM_CELL_MSG    0x00002000
/** indicator for a device Clear EOC Frame */
#define MEI_MSG_CTRL_CLEAR_EOC_FRAME    0x00004000


/**
   ioctl struct for MEI CPE mailbox write (message catalog)
   - generate the internal device mailbox message.
   - check for mailbox busy, if free
   - write the message to the device mailbox
*/
typedef struct
{
   /** control data of the ioctl */
   IOCTL_MEI_ioctl_t ictl;

   /** control information of the message */
   unsigned int   msgCtrl;
   /** classifier: EVT, NFC, ALM, DBG */
   unsigned short msgClassifier;
   /** msg id concerning the message catalog */
   unsigned short msgId;
   /** size of the payload (byte) */
   unsigned int   paylSize_byte;
   /** points to the message payload */
   unsigned char *pPayload;
} IOCTL_MEI_message_t;


/**
   ioctl structure for MEI CPE send message.
   - check for mailbox busy, if free
   - write a msg to the device mailbox
   - wait and read the expected ACK.
*/
typedef struct
{
   /** control data of the ioctl */
   IOCTL_MEI_ioctl_t ictl;

   /** message to write to the mailbox */
   IOCTL_MEI_message_t write_msg;
   /** message to read from the mailbox (normally expect ack) */
   IOCTL_MEI_message_t ack_msg;
} IOCTL_MEI_messageSend_t;


/**
   For debug only: ioctl structure for printout the internal driver buffer
                   FIO_MEI_SHOW_DRV_BUF
                    FIO_MEI_DRV_BUF_SHOW
\remark
   bufNum
   - bit 7: identify the direction
             0: read buffer.
             1: write buffer.
   - bit 0 .. 6: buffer number
             read:  max 2 (3).
             write: max 1.
*/
typedef struct
{
   /** control data of the ioctl */
   IOCTL_MEI_ioctl_t ictl;

    /** register address */
    unsigned int  bufNum;
    /** register value */
    unsigned int  count;
} IOCTL_MEI_drvBufShow_t;




/* ==========================================================================
   Argument structs for ioctl system call (MEI CPE ATM OAM Insert/Extract)
   ========================================================================== */


/** ATM OAM - Operation mode, manually config
   This setup allows a manual configuratin of the driver and the device.
   - manual setup of event behaviour (FW events and alarms)
      --> generate insert done events
      --> generate extract failure alarms
   - manual setup of the event processing
      --> forward transparent to the user or handled by the driver.
*/
#define MEI_ATMOAM_OPERATION_MODE_DIRECT         0x00000001

/** ATM OAM - Operation mode, autonomous mode
   Here the driver makes the following setup:
   - setup of event behaviour (FW events and alarms)
      --> insert done events enabled.
      --> extract failure alarms enabled.
   - setup event processing
      --> no forwarding of incoming events
          the driver handles insert done events
      --> no forwarding of incoming extract alarms
          the driver handles extract failure alarms
          (generate a driver message, update statistics)
*/
#define MEI_ATMOAM_OPERATION_MODE_AUTO           0x00000002



/** ATM OAM - Init driver transparent mode setup ALARM */
#define MEI_ATMOAM_INIT_TRANS_MODE_ALM_EXTR         0x00000001
/** ATM OAM - Init driver transparent mode setup TX indication */
#define MEI_ATMOAM_INIT_TRANS_MODE_EVT_TX           0x00000002
/** ATM OAM - Init driver transparent mode setup extract EVT */
#define MEI_ATMOAM_INIT_TRANS_MODE_CELL_EXTR        0x00000004

/** ATM OAM - Init driver transparent mode collect all */
#define MEI_ATMOAM_INIT_TRANS_MODE_ALL \
               (   MEI_ATMOAM_INIT_TRANS_MODE_ALM_EXTR \
                 | MEI_ATMOAM_INIT_TRANS_MODE_EVT_TX \
                 | MEI_ATMOAM_INIT_TRANS_MODE_CELL_EXTR )

/** ATM OAM - Init driver transparent mode none */
#define MEI_ATMOAM_INIT_TRANS_MODE_NONE             0x00000000

/** ATM OAM - Enable the ATM OAM Insert Extract feature */
#define MEI_ATMOAM_ENABLE_CNTRL_GL_EN_FLAG          0x00000001
/** ATM OAM - Enable the ATM OAM Alarm feature */
#define MEI_ATMOAM_ENABLE_CNTRL_ALM_EN_FLAG         0x00000002
/** ATM OAM - Enable the ATM OAM Event for TX buffer done */
#define MEI_ATMOAM_ENABLE_CNTRL_EVT_EN_FLAG         0x00000004

/** ATM OAM - Init devcie event handling, collect all */
#define MEI_ATMOAM_ENABLE_CNTRL_EVT_ALL \
               (   MEI_ATMOAM_ENABLE_CNTRL_GL_EN_FLAG \
                 | MEI_ATMOAM_ENABLE_CNTRL_ALM_EN_FLAG \
                 | MEI_ATMOAM_ENABLE_CNTRL_EVT_EN_FLAG )

/** ATM OAM - Init devcie event handling, none */
#define MEI_ATMOAM_ENABLE_CNTRL_EVT_NONE            0x00000000


/**
   ATM OAM - Basic definition of the raw ATM cell
*/
typedef struct {
   /** raw ATM cell buffer */
   unsigned char ATMcell[53];
   /** padding bytes for 32 bit alignment */
   unsigned char Res[3];
}  IOCTL_MEI_ATMOAM_rawCell_t;

/**
   ATM OAM - setup and configure the driver for ATM OAM.
*/
typedef struct {
   /** control data of the ioctl */
   IOCTL_MEI_ioctl_t ictl;

   /** control flags for the ATM OAM recevice messages
       - TX done notification
       - ATM OAM extract message
       - ATM OAM alarm message */
   unsigned int   transparentMode_old;
} IOCTL_MEI_ATMOAM_init_t;

/**
   ATM OAM - init insert / extract via ATM OAM
*/
typedef struct {
   /** control data of the ioctl */
   IOCTL_MEI_ioctl_t ictl;

   /** insert/extract direction - only line side */
   unsigned int   direction;
   /** link number = bearer channel */
   unsigned int   linkNo;

   /** select operation mode:
      - MEI_ATMOAM_OPERATION_MODE_DIRECT
      - MEI_ATMOAM_OPERATION_MODE_AUTO */
   unsigned int   aoOpMode;
   /** driver ATM OAM - transparent mode for modem events
       insert done evt, extract failure alm, ATM OAM cells */
   unsigned int   aoTransMode;
   /** control flags for the ATM OAM - enable feature, enable alarms */
   unsigned int   aoCntrl;

} IOCTL_MEI_ATMOAM_cntrl_t;


/**
   ATM OAM - MEI CPE driver ATM cells
   - max 4 cells per driver message
*/
typedef struct
{
   /** control data of the ioctl */
   IOCTL_MEI_ioctl_t ictl;

   /** number of ATM cells */
   unsigned int   cellCount;
   /** ATM cells */
   IOCTL_MEI_ATMOAM_rawCell_t atmCells[4];
} IOCTL_MEI_ATMOAM_drvAtmCells_t;


/**
   ATM OAM - insert / extract statistic counter.
*/
typedef struct
{
   /** control data of the ioctl */
   IOCTL_MEI_ioctl_t ictl;

   /** number of extracted cells */
   unsigned int extrCellCnt;
   /** number of extracted failed cells */
   unsigned int extrCellFailedCnt;
   /** number of forwarded cells - currently not supported */
   unsigned int forwardCellCnt;
   /** number of inserted cells */
   unsigned int insCellCnt;
} IOCTL_MEI_ATMOAM_counter_t;

/**
   ATM OAM - insert / extract statistics.
*/
typedef struct
{
   /** number of ATM OAM modem insert messages */
   unsigned int instMsgCnt;
   /** number of failed ATM OAM modem insert messages */
   unsigned int instMsgErrCnt;
   /** number of modem indication after a ATM OAM modem insert op */
   unsigned int instMsgNfcCnt;
   /** number of ATM OAM inserted cells */
   unsigned int instCellCnt;

   /** number of ATM OAM modem extract messages */
   unsigned int extrMsgCnt;
   /** number of ATM OAM extracted cells */
   unsigned int extrCellCnt;
   /** number of ATM OAM modem extract message errors */
   unsigned int extrMsgErrCnt;
   /** number of ATM OAM modem extract cell errors */
   unsigned int extrCellErrCnt;

   /** number of ATM OAM alarm messages */
   unsigned int almMsgCnt;
   /** number of ATM OAM extract failed cells */
   unsigned int almMsgExtrFailCellCnt;

} IOCTL_MEI_ATMOAM_statistics_t;


/**
   ATM OAM - insert / extract status.
*/
typedef struct
{
   /** control data of the ioctl */
   IOCTL_MEI_ioctl_t ictl;

   /** current ATM OAM operation mode */
   unsigned int   opMode;
   /** current device event setup */
   unsigned int   deviceCntrl;
   /** current driver transparent setup */
   unsigned int   transparentMode;

   /** current driver config state */
   unsigned int   drvCfgState;
   /** current device TX buffer state */
   unsigned int   devTxBufState;

   /** driver and device statistics */
   IOCTL_MEI_ATMOAM_statistics_t statistics;

} IOCTL_MEI_ATMOAM_status_t;


/* ==========================================================================
   Argument structs for ioctl system call (MEI CPE Clear EOC Insert/Extract)
   ========================================================================== */

/** Clear EOC - Operation mode, manually config
   This setup allows a manual configuratin of the driver and the device.
      - forward upcoming events transparently.
      - configure the device event control directly.
   --> the user must check the status manually for send allowed
   --> the driver expects EOC frames for send
   --> the user must check the status manually for available data
   --> the user must read via EOC frame read.
*/
#define MEI_CEOC_OPERATION_MODE_DIRECT       0x00000001

/** Clear EOC - Operation mode, autonomous mode
   Here the driver makes the following setup:
      - no event is in transparent mode, all modem messages catched by the driver.
      - enable TX Evt's, enable RX Data events
   --> the driver expects EOC frames for send
   --> the driver returns EOC frames via EOC frame events.
*/
#define MEI_CEOC_OPERATION_MODE_AUTO         0x00000002

/** Clear EOC - Operation mode, autonomous read mode
   Here the driver makes the following setup:
      - TX/RX state change events are enabled
        but only RX events are forwared to the user layer
      - RX Data events are disabled.
   --> the driver expects EOC frames for send
   --> the driver signals available EOC frames via a modem message event.
   --> the user must read via EOC frame read.
*/
#define MEI_CEOC_OPERATION_MODE_AUTO_READ    0x00000003

/** Clear EOC - Operation mode, poll read
   Here the driver makes the following setup:
      - TX state change events are enabled
      - RX Data events are disabled.
   --> the driver expects EOC frames for
   --> the user must poll for available EOC frames via the EOC frame read.
*/
#define MEI_CEOC_OPERATION_MODE_POLL_READ    0x00000004


/** Clear EOC - Init driver transparent mode for Evt EOC Data */
#define MEI_CEOC_INIT_TRANS_MODE_EVT_DATA    0x00000001
/** Clear EOC - Init driver transparent mode for Evt EOC RX Status */
#define MEI_CEOC_INIT_TRANS_MODE_EVT_RX_STAT 0x00000002
/** Clear EOC - Init driver transparent mode for Evt EOC TX Status */
#define MEI_CEOC_INIT_TRANS_MODE_EVT_TX_STAT 0x00000004

/** Clear EOC - transparent mode, collect all */
#define MEI_CEOC_INIT_TRANS_MODE_ALL \
                        (   MEI_CEOC_INIT_TRANS_MODE_EVT_DATA \
                          | MEI_CEOC_INIT_TRANS_MODE_EVT_RX_STAT \
                          | MEI_CEOC_INIT_TRANS_MODE_EVT_TX_STAT )


/** Clear EOC - Enable EOC Event: read data autonomous */
#define MEI_CEOC_CNTRL_FLAG_EVT_DATA_READ        0x00000001
/** Clear EOC - Enable EOC Event: rx status changed */
#define MEI_CEOC_CNTRL_FLAG_EVT_RX_STAT          0x00000002
/** Clear EOC - Enable EOC Event: tx status changed */
#define MEI_CEOC_CNTRL_FLAG_EVT_TX_STAT          0x00000004

/** Clear EOC - enable events, collect all */
#define MEI_CEOC_CNTRL_FLAG_EVT_ALL \
                        (   MEI_CEOC_CNTRL_FLAG_EVT_DATA_READ \
                          | MEI_CEOC_CNTRL_FLAG_EVT_RX_STAT \
                          | MEI_CEOC_CNTRL_FLAG_EVT_TX_STAT )


/** Max frame size of a EOC data block [byte] (without proto-ID) */
#define MEI_MAX_CEOC_DATA_SIZE_BYTE              508


/**
   Clear EOC - setup and configure the driver for Clear EOC.
*/
typedef struct {
   /** control data of the ioctl */
   IOCTL_MEI_ioctl_t ictl;

} IOCTL_MEI_CEOC_init_t;

/**
   Clear EOC - device setup/control
*/
typedef struct {
   /** control data of the ioctl */
   IOCTL_MEI_ioctl_t ictl;

   /** select operation mode:
      - MEI_CEOC_OPERATION_MODE_DIRECT
      - MEI_CEOC_OPERATION_MODE_AUTO
      - MEI_CEOC_OPERATION_MODE_AUTO_READ
      - MEI_CEOC_OPERATION_MODE_POLL_READ */
   unsigned int   opMode;
   /** driver Clear EOC - transparent mode for modem events */
   unsigned int   transMode;
   /** control flags Clear EOC - enable events for TX/RX Stat, read data */
   unsigned int   cntrl;
} IOCTL_MEI_CEOC_cntrl_t;

/**
   Clear EOC - statistics
*/
typedef struct {
   /** control data of the ioctl */
   IOCTL_MEI_ioctl_t ictl;

   /** number of written CEOC modem "write" messages */
   unsigned int wrMsgCnt;
   /** number of error written CEOC modem "write" messages */
   unsigned int wrMsgErrCnt;

   /** number of read CEOC modem "read" messages */
   unsigned int rdMsgCnt;
   /** number of error read CEOC modem "read" messages */
   unsigned int rdMsgErrCnt;

   /** number of read CEOC modem "event read" messages */
   unsigned int evtRdMsgCnt;
   /** number of error read CEOC modem "event read" messages */
   unsigned int evtRdMsgErrCnt;

   /** number of written CEOC frames */
   unsigned int wrFrameCnt;
   /** number of read CEOC frames */
   unsigned int rdFrameCnt;
   /** number of event read CEOC frames */
   unsigned int evtRdFrameCnt;
   /** number of received corrupted CEOC frames */
   unsigned int recvFrameErrCnt;

   /** number of TX trigger send */
   unsigned int sendTxTriggerCnt;

   /** number of timeout after TX trigger send (timeout insert frame) */
   unsigned int insertTimeoutCnt;

   /** number of RX status error */
   unsigned int rxStatErrCnt;
   /** number of TX status error */
   unsigned int txStatErrCnt;

} IOCTL_MEI_CEOC_statistic_t;


/**
   Clear EOC - Basic definition of the raw EOC Frame
*/
typedef struct {
   /** control data of the ioctl */
   IOCTL_MEI_ioctl_t ictl;

   /** size of the data block */
   unsigned int dataSize_byte;
   /** Protocol Identifier */
   unsigned int protIdent;
   /** points to the EOC Frame data block */
   unsigned char *pEocData;
}  IOCTL_MEI_CEOC_frame_t;


/** ioctl structure for channel specific Log/Trace level set via the entity control
   Therefore this IOCTL will execute the Set Trace/Log function per device.

\remark
   Only already existing devices can be processed.
   Existing devices are cleared from the mask after processing.
*/
typedef struct
{
   /** control data of the ioctl */
   IOCTL_MEI_ioctl_t xIctl;

   /** new trace/log level */
   unsigned int level;
   /** debug block mask (01 = com, 02 = MEI, 04 = rom, 08 = boot) */
   unsigned int blockMask;

   /** mask the single device */
   unsigned int dfeMask[4];
} IOCTL_MEIX_debugSet_t;

/* ==========================================================================
   Encapsulate all available ioctl data structs
   ========================================================================== */

/** encapsulate all ioctl command arguments (MEI CPE devices) */
typedef union
{
   IOCTL_MEI_ioctl_t           drv_ioctl;
   IOCTL_MEI_dbgLevel_t        dbg_level;
   IOCTL_MEI_drvVersion_t      drv_vers;
   IOCTL_MEI_devInit_t         init_dev;
   IOCTL_MEI_drvInit_t         init_drv;
   IOCTL_MEI_reset_t           rst;
   IOCTL_MEI_reqCfg_t          req_cfg;
   IOCTL_MEI_statistic_t       req_stat;
   IOCTL_MEI_fwDownLoad_t      fw_dl;
   IOCTL_MEI_fwOptDownLoad_t   fw_dl_opt;
   IOCTL_MEI_fwMode_t          fw_mode;
   IOCTL_MEI_FwModeCtrlSet_t   fw_mode_ctrl;
   IOCTL_MEI_FwModeStatGet_t   fw_mode_stat;

   IOCTL_MEI_regInOut_t        reg_io;
   IOCTL_MEI_GPA_accessInOut_t gpa_access;
   IOCTL_MEI_dbgAccess_t       dbg_access;
   IOCTL_MEIX_debugSet_t       debugSet;
   IOCTL_MEI_DMA_access_t      dma_access;
   IOCTL_MEI_drvLoop_t         drv_loop;

   IOCTL_MEI_autoMsgCtrl_t     autoMsgCtrl;
   IOCTL_MEI_mboxMsg_t         mbox_msg;
   IOCTL_MEI_mboxSend_t        mbox_send;
   IOCTL_MEI_message_t         ifx_msg;
   IOCTL_MEI_messageSend_t     ifx_msg_send;

   IOCTL_MEI_drvBufShow_t      show_drv_buf;

   IOCTL_MEI_ATMOAM_init_t        atmoam_init;
   IOCTL_MEI_ATMOAM_cntrl_t       atmoam_cntrl;
   IOCTL_MEI_ATMOAM_drvAtmCells_t atmoam_cells;
   IOCTL_MEI_ATMOAM_counter_t     atmoam_counter;
   IOCTL_MEI_ATMOAM_status_t      atmoam_status;

   IOCTL_MEI_CEOC_init_t          ceoc_init;
   IOCTL_MEI_CEOC_cntrl_t         ceoc_cntrl;
   IOCTL_MEI_CEOC_statistic_t     ceoc_statistic;
   IOCTL_MEI_CEOC_frame_t         ceoc_frame;

} IOCTL_MEI_arg_t;

/* ==========================================================================
   MEI CPE Device Driver - status and config definitions
   ========================================================================== */

/**
   Defines the MEI CPE device driver states.

\ingroup MEI_COMMON
*/
typedef enum
{
   /** uninitialized driver */
   e_MEI_DRV_STATE_NOT_INIT = 0,
   /** SW init done (mem map) */
   e_MEI_DRV_STATE_SW_INIT_DONE,
   /** wait for the 1. Boot msg */
   e_MEI_DRV_STATE_BOOT_WAIT_ROM_ALIVE,
   /** ROM handler is alive */
   e_MEI_DRV_STATE_BOOT_ROM_ALIVE,
   /** ROM handler Download ongoing */
   e_MEI_DRV_STATE_BOOT_ROM_DL_PENDING,
   /** wait for the first response
       - Modem Ready msg
       - code swap request */
   e_MEI_DRV_STATE_WAIT_FOR_FIRST_RESP,
   /** modem ready recieved, is alive */
   e_MEI_DRV_STATE_DFE_READY,
   /** driver is in reset state
       - forced by SW
       - forced by error / reboot */
   e_MEI_DRV_STATE_DFE_RESET,
   /** driver config error - base init error */
   e_MEI_DRV_STATE_CFG_ERROR,
   /** unused last state - for state machine control */
   e_MEI_DRV_STATE_STATE_LAST
}  MEI_DRV_STATE_E;



/* ==========================================================================
   MEI CPE Device Driver - driver message definitons
   ========================================================================== */

/**
   The current driver interface supports MEI CPE Driver messages

   The driver message ID hase the following structure:

   Bit[ 7.. 0]   message:     Message number
   Bit[15.. 8]   module:      0x01 = COMMON VINAX
                              0x02 = COMMON MEIX-Control
                              0x04 = ROM (DOWNLOAD)
                              0x10 = REM ACCESS
   Bit[22..16]   type:        EVT = 2, ALARM = 4
   Bit[23]       direction:   IN = 0, OUT = 1
   Bit[24..31]   Return Code

   Currently the following message numbers are supported:
   - 0x01 - ROM Start (Event | Alarm)

   - 0x10 - Remote Firmware download done (Event | Alarm)

*/

/** MEI CPE Driver Messages: mask for the message number field */
#define MEI_DRV_MSG_IF_MASK_MSG_NUM                 0x000000FF

/** MEI CPE Driver Messages: flag indicates the MODULE - COMMON */
#define MEI_DRV_MSG_IF_FLAG_MODULE_COMMON           0x00000100
/** MEI CPE Driver Messages: flag indicates the MODULE - COMMON Control */
#define MEI_DRV_MSG_IF_FLAG_MODULE_COMMON_X         0x00000200
/** MEI CPE Driver Messages: flag indicates the MODULE - ROM */
#define MEI_DRV_MSG_IF_FLAG_MODULE_ROM              0x00000400
/** MEI CPE Driver Messages: flag indicates the MODULE - Remote Access */
#define MEI_DRV_MSG_IF_FLAG_MODULE_REM_ACCESS       0x00001000
/** MEI CPE Driver Messages: flag indicates the MODULE - Remote ATM OAM Access */
#define MEI_DRV_MSG_IF_FLAG_MODULE_REM_ATM_ACCESS   0x00002000
/** MEI CPE Driver Messages: flag indicates the MODULE - Remote Clear EOC Access */
#define MEI_DRV_MSG_IF_FLAG_MODULE_REM_EOC_ACCESS   0x00004000

/** MEI CPE Driver Messages: flag indicates the TYPE - Event */
#define MEI_DRV_MSG_IF_FLAG_TYPE_EVT                0x00020000
/** MEI CPE Driver Messages: flag indicates the TYPE - Alarm */
#define MEI_DRV_MSG_IF_FLAG_TYPE_ALARM              0x00040000

/** MEI CPE Driver Messages: flag indicates the DIRECTION - out */
#define MEI_DRV_MSG_IF_FLAG_DIR_OUT                 0x00800000

/** MEI CPE Driver Messages: mask for the retrun code field */
#define MEI_DRV_MSG_IF_MASK_RET_CODE                0xFF000000



/**
   MEI CPE Driver Message: ROM Start
   The device enters the ROM code
   - user controlled after startup, user reset
*/
#define MEI_DRV_MSG_IF_ROM_START                    0x00000001

/**
   MEI CPE Driver Event: ROM Start (0x00820101)
*/
#define MEI_DRV_MSG_IF_ROM_START_EVT             (  MEI_DRV_MSG_IF_ROM_START \
                                                    | MEI_DRV_MSG_IF_FLAG_MODULE_COMMON \
                                                    | MEI_DRV_MSG_IF_FLAG_TYPE_EVT \
                                                    | MEI_DRV_MSG_IF_FLAG_DIR_OUT )

/**
   MEI CPE Driver ALARM: ROM Start (0x00840101)
*/
#define MEI_DRV_MSG_IF_ROM_START_ALM             (  MEI_DRV_MSG_IF_ROM_START \
                                                    | MEI_DRV_MSG_IF_FLAG_MODULE_COMMON \
                                                    | MEI_DRV_MSG_IF_FLAG_TYPE_ALARM \
                                                    | MEI_DRV_MSG_IF_FLAG_DIR_OUT )



/**
   MEI CPE Driver Message: Remote Firmare Download done
   The Remote firmware download is finished.

\remarks
   You get this device driver event (per selected line) if you use the
   "Parallel Remote Firmware Download".
*/
#define MEI_DRV_MSG_IF_REM_DL_DONE                  0x00000010

/**
   MEI CPE Driver EVENT: Remote Firmare Download done (0x00821010)
   The Remote firmware download is finished.
*/
#define MEI_DRV_MSG_IF_REM_DL_DONE_EVT           (  MEI_DRV_MSG_IF_REM_DL_DONE \
                                                    | MEI_DRV_MSG_IF_FLAG_MODULE_REM_ACCESS \
                                                    | MEI_DRV_MSG_IF_FLAG_TYPE_EVT \
                                                    | MEI_DRV_MSG_IF_FLAG_DIR_OUT )

/**
   MEI CPE Driver ALARM: Remote Firmare Download done (0x00841010)
   The Remote firmware download failed
*/
#define MEI_DRV_MSG_IF_REM_DL_DONE_ALM           (  MEI_DRV_MSG_IF_REM_DL_DONE \
                                                    | MEI_DRV_MSG_IF_FLAG_MODULE_REM_ACCESS \
                                                    | MEI_DRV_MSG_IF_FLAG_TYPE_ALARM \
                                                    | MEI_DRV_MSG_IF_FLAG_DIR_OUT )

/**
   MEI CPE Driver Message: Remote ATM OAM Extract
   The device signals an alarm for extract ATM OAM cells failed.

\remarks
   You get this device driver alarm (per selected line) if you have enabled
   "ATM OAM" remote interface and also enabled the corresponding driver msg.
*/
#define MEI_DRV_MSG_IF_REM_ATM_OAM_EXTR             0x00000020

/**
   MEI CPE Driver ALARM: Remote ATM OAM Extract (0x00841010)
   Remote ATM OAM Extract failed
*/
#define MEI_DRV_MSG_IF_REM_ATM_OAM_EXTR_ALM      (  MEI_DRV_MSG_IF_REM_ATM_OAM_EXTR \
                                                    | MEI_DRV_MSG_IF_FLAG_MODULE_REM_ATM_ACCESS \
                                                    | MEI_DRV_MSG_IF_FLAG_TYPE_ALARM \
                                                    | MEI_DRV_MSG_IF_FLAG_DIR_OUT )


/**
   MEI CPE Driver Messages - message header

*/
typedef struct {
   /** identify driver msg */
   unsigned int   id;
   /** identify the line which sends the message */
   unsigned int   lineNum;
} MEI_DRV_MSG_Header_t;


/** MEI CPE Driver Message - ROM Start: reason is "startup" */
#define MEI_DRV_MSG_IF_ROM_START_REASON_STARTUP        0x00000001

/** MEI CPE Driver Message - ROM Start: reason is "user reset" */
#define MEI_DRV_MSG_IF_ROM_START_REASON_USR_RESET      0x00000002

/** MEI CPE Driver Message - ROM Start: reason is "device reset" */
#define MEI_DRV_MSG_IF_ROM_START_REASON_DEV_RESET      0x00000004

/**
   MEI CPE Driver messages - ROM Start
*/
typedef struct {
   /** message header of a device driver message */
   MEI_DRV_MSG_Header_t  hdr;
   /** Current driver state */
   unsigned int   reason;

   /** Current driver state */
   unsigned int   newDrvState;
   /** Previous driver state */
   unsigned int   prevDrvState;

} MEI_DRV_MSG_RomStart_t;


/** MEI CPE Driver Message - Rem FW DL: OP result success */
#define MEI_DRV_MSG_IF_REM_DL_DONE_OP_RESULT_SUCCESS         0x00000000

/** MEI CPE Driver Message - Rem FW DL: OP result ERROR invalid state */
#define MEI_DRV_MSG_IF_REM_DL_DONE_OP_RESULT_ERR_INVAL_STATE 0x00000001

/** MEI CPE Driver Message - Rem FW DL: OP result ERROR setup */
#define MEI_DRV_MSG_IF_REM_DL_DONE_OP_RESULT_ERR_SETUP       0x00000002

/** MEI CPE Driver Message - Rem FW DL: OP result ERROR busy */
#define MEI_DRV_MSG_IF_REM_DL_DONE_OP_RESULT_ERR_BUSY        0x00000004

/** MEI CPE Driver Message - Rem FW DL: OP result ERROR TFTP OP */
#define MEI_DRV_MSG_IF_REM_DL_DONE_OP_RESULT_ERR_TFTP_OP     0x00000010

/** MEI CPE Driver Message - Rem FW DL: OP result ERROR unknown */
#define MEI_DRV_MSG_IF_REM_DL_DONE_OP_RESULT_ERR_UNKNOWN     0xFFFFFFFF

/**
   MEI CPE Driver messages - Remote Firmware Download
*/
typedef struct {
   /** message header of a device driver message */
   MEI_DRV_MSG_Header_t  hdr;

   /** result of the remote operation */
   unsigned int      opResult;
   /** session ID of the remote TFTP operation */
   unsigned int      sessionId;
   /** number of transferd bytes */
   unsigned int      sendBytes;
   /** elapsed operation time */
   unsigned int      elapsedTime_ms;
   /** points to the result string buffer (from user) */
   char              resStr[32];
} MEI_DRV_MSG_RemFwDownload_t;


/**
   MEI CPE Driver messages - Remote ATM OAM
*/
typedef struct {
   /** message header of a device driver message */
   MEI_DRV_MSG_Header_t  hdr;

   /** identify the link no (bearer channel) */
   unsigned int      linkNo;
   /** actual number of failed extracted cells */
   unsigned int      extrCellFailedCnt;
   /** collected number of all failed extract cells for this line */
   unsigned int      extrCellFailedAllCnt;
   /** collected number of all extract failed alarms for this line */
   unsigned int      extrFailedAlmAllCnt;

} MEI_DRV_MSG_RemAtmOam_t;



/**
   Union of all available device driver messages.
*/
typedef union {
   /** empty driver message - header only */
   MEI_DRV_MSG_Header_t        hdr;
   /** driver message - ROM Start event */
   MEI_DRV_MSG_RomStart_t      romStart;
   /** driver message - Remote Firmware Download event */
   MEI_DRV_MSG_RemFwDownload_t remFwDl;
   /** driver message - Remote ATM OAM alarm */
   MEI_DRV_MSG_RemAtmOam_t     remAtmOam;
} MEI_DRV_MSG_all_t;



/* ==========================================================================
   Return and Error Codes of the device Driver
   ========================================================================== */

/** \addtogroup MEI_ERROR_CODES
 @{ */

/**
   This value defines the return ERROR code start value.
*/
#define MEI_ERROR_CODE_BASE      1000

/**
   This enumeration type contains the driver return ERROR codes.
*/
typedef enum {
   /** Start of error codes
      Refer to \ref MEI_ERROR_CODE_BASE */
   e_MEI_ERR_START             = MEI_ERROR_CODE_BASE,

   /** ERROR - Device Busy */
   e_MEI_ERR_DEV_BUSY          = MEI_ERROR_CODE_BASE +  1,
   /** ERROR - Device Down */
   e_MEI_ERR_DEV_DOWN          = MEI_ERROR_CODE_BASE +  2,
   /** ERROR - Device not exists */
   e_MEI_ERR_DEV_NOT_EXIST     = MEI_ERROR_CODE_BASE +  3,
   /** ERROR - Device no resource */
   e_MEI_ERR_DEV_NO_RESOURCE   = MEI_ERROR_CODE_BASE +  4,
   /** ERROR - Device Init */
   e_MEI_ERR_DEV_INIT          = MEI_ERROR_CODE_BASE +  5,
   /** ERROR - Device in Reset */
   e_MEI_ERR_DEV_RESET         = MEI_ERROR_CODE_BASE +  6,

   /** ERROR - Device no response */
   e_MEI_ERR_DEV_NO_RESP       = MEI_ERROR_CODE_BASE +  7,
   /** ERROR - Device negative response */
   e_MEI_ERR_DEV_NEG_RESP      = MEI_ERROR_CODE_BASE +  8,
   /** ERROR - Device invalid response */
   e_MEI_ERR_DEV_INVAL_RESP    = MEI_ERROR_CODE_BASE +  9,
   /** ERROR - Device not responding */
   e_MEI_ERR_DEV_TIMEOUT       = MEI_ERROR_CODE_BASE + 10,

   /** ERROR - No Memory */
   e_MEI_ERR_NO_MEM            = MEI_ERROR_CODE_BASE + 11,
   /** ERROR - Device IOREMAP */
   e_MEI_ERR_DEV_IO_MAP        = MEI_ERROR_CODE_BASE + 12,

   /** ERROR - Get Arguments */
   e_MEI_ERR_GET_ARG           = MEI_ERROR_CODE_BASE + 13,
   /** ERROR - Return Arguments */
   e_MEI_ERR_RETURN_ARG        = MEI_ERROR_CODE_BASE + 14,

   /** ERROR - Operation already done */
   e_MEI_ERR_ALREADY_DONE      = MEI_ERROR_CODE_BASE + 15,
   /** ERROR - Operation not complete */
   e_MEI_ERR_NOT_COMPLETE      = MEI_ERROR_CODE_BASE + 16,
   /** ERROR - Operation failed */
   e_MEI_ERR_OP_FAILED         = MEI_ERROR_CODE_BASE + 17,

   /** ERROR - Invalid Command */
   e_MEI_ERR_INVAL_CMD         = MEI_ERROR_CODE_BASE + 18,
   /** ERROR - Unknown Command */
   e_MEI_ERR_UNKNOWN_CMD       = MEI_ERROR_CODE_BASE + 19,
   /** ERROR - Invalid Argument */
   e_MEI_ERR_INVAL_ARG         = MEI_ERROR_CODE_BASE + 20,
   /** ERROR - Invalid State */
   e_MEI_ERR_INVAL_STATE       = MEI_ERROR_CODE_BASE + 21,
   /** ERROR - Invalid Config */
   e_MEI_ERR_INVAL_CONFIG      = MEI_ERROR_CODE_BASE + 22,

   /** ERROR - Invalid Msg */
   e_MEI_ERR_MSG_PARAM         = MEI_ERROR_CODE_BASE + 23,

   /** ERROR - Invalid Base Init configuration (RIP IRQ) */
   e_MEI_ERR_INVAL_BASE_CFG    = MEI_ERROR_CODE_BASE + 24,

   /** ERROR - Invalid FW image */
   e_MEI_ERR_INVAL_FW_IMAGE    = MEI_ERROR_CODE_BASE + 25,

   /** End of error codes */
   e_MEI_ERR_END
} MEI_ERROR_CODES;


/**
   This value defines the device remote return ERROR code start value.
*/
#define MEI_ERROR_CODE_BASE_REMOTE   1200


/**
   This enumeration type contains the device driver remote return ERROR codes.
*/
typedef enum {

   /** Start of remote error codes */
   e_MEI_ERR_REM_START               = MEI_ERROR_CODE_BASE_REMOTE,

   /** ERROR - invalid line state for remote write messages */
   e_MEI_ERR_REM_INVAL_LINE_STATE    = MEI_ERROR_CODE_BASE_REMOTE + 1,
   /** ERROR - no response from remote device */
   e_MEI_ERR_REM_DEV_NO_RESP         = MEI_ERROR_CODE_BASE_REMOTE + 2,
   /** ERROR - fault from remote device */
   e_MEI_ERR_REM_DEV_FAULT           = MEI_ERROR_CODE_BASE_REMOTE + 3,
   /** ERROR - Remote connection setup */
   e_MEI_ERR_REM_SETUP               = MEI_ERROR_CODE_BASE_REMOTE + 4,

   /** End of error codes */
   e_MEI_ERR_REM_END

} MEI_ERROR_CODES_REMOTE_e;


/** @} MEI_ERROR_CODES */

#endif      /* #ifndef _DRV_MEI_CPE_INTERFACE_H */

