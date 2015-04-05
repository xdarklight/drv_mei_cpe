/******************************************************************************

                               Copyright (c) 2011
                            Lantiq Deutschland GmbH
                     Am Campeon 3; 85579 Neubiberg, Germany

  For licensing information, see the file 'LICENSE' in the root folder of
  this software module.

******************************************************************************/

/* ==========================================================================
   Description : VINAX Firmware Download function (CodeSwap).
   ========================================================================== */


/* ============================================================================
   Inlcudes
   ========================================================================= */

/* get at first the driver configuration */
#include "drv_mei_cpe_config.h"

#if (MEI_SUPPORT_DEVICE_VINAX == 1)

#include "ifx_types.h"
#include "drv_mei_cpe_os.h"
#include "drv_mei_cpe_dbg.h"

#include "drv_mei_cpe_dbg_driver.h"

/* ==========================================================================
   Support firmware download (DMA/MEI Dbg and CodeSwap)
   ========================================================================== */

#if ((MEI_SUPPORT_ROM_CODE == 1) && (MEI_SUPPORT_DL_DMA_CS == 1))

#include "drv_mei_cpe_interface.h"
#include "drv_mei_cpe_mei_interface.h"
#include "drv_mei_cpe_api.h"


/* ROM code interface functions */
#include "drv_mei_cpe_rom_handler_if.h"
#include "drv_mei_cpe_rom_handler.h"

/* device boot code messages */
#include "user_if_vdsl2_boot_messages.h"

/* CMV messages */
#include "cmv_message_format.h"

#include "drv_mei_cpe_download.h"
#include "drv_mei_cpe_msg_process.h"

#if (MEI_SUPPORT_DRV_MODEM_TESTS == 1)
#include "drv_mei_cpe_modem_test.h"
#endif


/* ==========================================================================
   Global Variable Definitions
   ========================================================================== */

/**
   Firmware image for download
*/
MEI_FW_IMAGE_T ChipFwImage[MEI_MAX_FW_IMAGES] =
 {
   { 0 }
#if MEI_MAX_FW_IMAGES > 1
   ,{ 0 }
#endif
#if MEI_MAX_FW_IMAGES > 2
#error More than 2 firmware images not supported!
#endif
 };

/* ==========================================================================
   Local variables
   ========================================================================== */

/*
   Memory Map validation
*/
MEI_MEM_MAP_T   MEI_memMapRev1x[] =
{
   /* Start       End        boot only                   */
   {0x00025DC0, 0x00025FFF, IFX_TRUE,  "ROM Dyn"  },     /* ROM Code dynamic data - 576 byte */
   {0x00026140, 0x00029FFF, IFX_FALSE, "Resv 1"   },     /* Reserved block 1     */
   {0x0002E000, 0x0002FFFF, IFX_FALSE, "Resv 2"   },     /* Reserved block 2     */
   {0x000B7000, 0x000BFFFF, IFX_FALSE, "Resv 3"   },     /* Reserved block 3     */
   {0x000C0000, 0x000DBFFF, IFX_FALSE, "xTC Reg"  },     /* xTC register block   */
   {0x000DC000, 0x000DFFFF, IFX_FALSE, "Resv 4"   },     /* Reserved block 4     */
   {0x000E0000, 0x000EFFFF, IFX_FALSE, "Periph"   },     /* Peripheral modules   */
   {0x000F0000, 0x000F3FFF, IFX_FALSE, "InsRom"   },     /* Instruction ROM      */
   {0x000F4000, 0x000FDFFF, IFX_FALSE, "Resv 5"   },     /* Reserved block 5     */

   {0x00000000, 0x00000000, IFX_FALSE, NULL}             /* indicates last entry */
};


/* ==========================================================================
   Local function declarations
   ========================================================================== */

static IFX_int32_t MEI_WritePage( MEI_DEV_T *pMeiDev,
                                    IFX_uint32_t pageIndex,
                                    IFX_boolean_t  bData,
                                    IFX_uint32_t destAddr);

static IFX_int32_t MEI_DoDmaBootFwDl(MEI_DEV_T *pMeiDev);

static IFX_int32_t MEI_Do_CMD_ONLINESTATEACTIVATE(MEI_DEV_T *pMeiDev);

static IFX_int32_t MEI_FwDlDmaStateMachine( MEI_DEV_T *pMeiDev );

static IFX_void_t MEI_FDShowImageDir(
                        MEI_FW_IMAGE_T        *pFwImage,
                        IFX_boolean_t           bHostOrder);

static IFX_int32_t MEI_ValidateImage(
                        MEI_FW_IMAGE_T        *pFwImage);

static IFX_int32_t MEI_ValidatPage(
                        IFX_uint32_t      pageIndex,
                        IFX_boolean_t     bCodePage,
                        IFX_boolean_t     bBootPage,
                        IFX_uint32_t      startAddr,
                        IFX_uint32_t      endAddr,
                        MEI_MEM_MAP_T   *pMemMap);

static IFX_int32_t MEI_FDSwapImage(
                        MEI_FW_IMAGE_T        *pFwImage,
                        MEI_DRV_BOOT_MODES_E  drvBootMode);

static IFX_int32_t MEI_StartFwDownload(
                        MEI_DYN_CNTRL_T *pMeiDynCntrl,
                        IFX_int32_t       imageId);


/* ==========================================================================
   Local function definitions
   ========================================================================== */

/**
   Check a page and write it to the VINAX via DMA / MEI Dbg.

\param
   pMeiDev     points to the current VINAX channel device.
\param
   pageIndex   Index of the requested page within the image.
\param
   bData       IFX_FALSE: check the corresponding data page
               IFX_TRUE:  check the corresponding code page

\return
   IFX_SUCCESS:   Write page successfull.
   IFX_ERROR:     Invalid page.

\attention
   - Called on int-level
*/
static IFX_int32_t MEI_WritePage( MEI_DEV_T *pMeiDev,
                                    IFX_uint32_t pageIndex,
                                    IFX_boolean_t  bData,
                                    IFX_uint32_t destAddr)
{
   IFX_int32_t  pageSize_word, ret;
   IFX_uint32_t *pPageAddr_32bit;
   MEI_FW_IMAGE_PAGE_T *pPageDir = pMeiDev->fwDl.pPageDir;

   if ( (pageSize_word = MEI_CheckCsPage(pMeiDev, pageIndex, bData)) > 0 )
   {
      /* download page via DMA */

      pPageAddr_32bit =
         (IFX_uint32_t *)( (bData) ?
               ( pMeiDev->fwDl.pDfeImage + pPageDir[pageIndex].dataOffset_Byte ) :
               ( pMeiDev->fwDl.pDfeImage + pPageDir[pageIndex].codeOffset_Byte ) );

      if (destAddr == 0xFFFFFFFF)
      {
         /* static CodeSwap - take dest address from the image header */
         destAddr = ((bData) ? (pPageDir[pageIndex].dataDestAddr):
                                     (pPageDir[pageIndex].codeDestAddr) );
      }

      PRN_DBG_INT( MEI_ROM, MEI_DRV_PRN_LEVEL_LOW, MEI_DRV_LINENUM_GET(pMeiDev),
           ( "MEI_DRV[%02d]: BM-7 CS: write page[%d] <%s>  dest 0x%08X size 0x%X [word]" MEI_DRV_CRLF,
             MEI_DRV_LINENUM_GET(pMeiDev),
             pageIndex, (bData ? "data" : "code"),
             destAddr,  pageSize_word ));

#if (MEI_BM7_CODESWAP_MEIDBG == 1)

      ret = MEI_WriteDbg( &pMeiDev->meiDrvCntrl,
                          destAddr, ME_DBG_DECODE_DEBUG_DEC_LDST,
                          pageSize_word, pPageAddr_32bit);

      if ((IFX_uint32_t)ret != (IFX_uint32_t)pageSize_word)
      {
         PRN_ERR_INT_NL( MEI_ROM, MEI_DRV_PRN_LEVEL_ERR,
              ( "MEI_DRV[%02d]: ERROR - "
                "DMA Download, write MEI Dbg <%s> page[%d] ret = %d" MEI_DRV_CRLF,
                 MEI_DRV_LINENUM_GET(pMeiDev), (bData ? "data" : "code"), pageIndex, ret));

         return IFX_ERROR;
      }
#else
      ret = MEI_WriteDma16Bit( &pMeiDev->meiDrvCntrl,
                          destAddr,
                          (IFX_uint16_t *)pPageAddr_32bit,
                          (IFX_uint32_t)pageSize_word * 2,
                          MEI_PROTECTED_MEI_DMA_RETRY_CNT_CS /* disable check and no retry count */ );

      if ((IFX_uint32_t)ret != (IFX_uint32_t)pageSize_word * 2)
      {
         PRN_ERR_INT_NL( MEI_ROM, MEI_DRV_PRN_LEVEL_ERR,
              ( "MEI_DRV[%02d]: ERROR - "
                "DMA Download, write DMA <%s> page[%d] ret = %d" MEI_DRV_CRLF,
                 MEI_DRV_LINENUM_GET(pMeiDev), (bData ? "data" : "code"), pageIndex, ret));

         return IFX_ERROR;
      }
#endif

      return IFX_SUCCESS;
   }
   else
   {
      /* check for empty pages */
      if (pageSize_word == 0)
      {
         PRN_DBG_INT( MEI_ROM, MEI_DRV_PRN_LEVEL_NORMAL, MEI_DRV_LINENUM_GET(pMeiDev),
              ( "MEI_DRV[%02d]: BM-7 CS: EMPTY <%s> page[%d] found - skipped" MEI_DRV_CRLF,
                 MEI_DRV_LINENUM_GET(pMeiDev), (bData ? "data" : "code"), pageIndex) );

         return IFX_SUCCESS;
      }
   }

   PRN_ERR_INT_NL( MEI_ROM, MEI_DRV_PRN_LEVEL_ERR,
        ("MEI_DRV[%02d]: ERROR - invalid  %s page[%d] (max %d), size %d (max %d)" MEI_DRV_CRLF,
          MEI_DRV_LINENUM_GET(pMeiDev), ((bData) ? "data" : "code"),
          pageIndex, pMeiDev->fwDl.pImageCtrl->imageNumOfPages,
          ((bData) ? pPageDir[pageIndex].dataPageSize_32Bit : pPageDir[pageIndex].codePageSize_32Bit),
          ((bData) ? MEI_MAX_DATA_PAGESIZE_WORD : MEI_MAX_CODE_PAGESIZE_WORD) ));

   return IFX_ERROR;
}



/**
   Do the firmware download via DMA.
   - Download the boot pages to the VINAX via DMA

\param
   pMeiDev     points to the current VINAX device.

*/
static IFX_int32_t MEI_DoDmaBootFwDl(MEI_DEV_T *pMeiDev)
{
   IFX_uint32_t  pageIndex, codePages = 0, dataPages = 0;
   MEI_FW_IMAGE_PAGE_T *pPageDir = pMeiDev->fwDl.pPageDir;

   /* size without image Size and Check Sum field */

   if (pMeiDev->fwDl.pImageCtrl->imageSize_Bytes !=
         ( pMeiDev->fwDl.size_byte - sizeof(pMeiDev->fwDl.pImageCtrl->imageCheckSum)
                                   - sizeof(pMeiDev->fwDl.pImageCtrl->imageSize_Bytes) ))
   {
      PRN_ERR_USR_NL( MEI_ROM, MEI_DRV_PRN_LEVEL_ERR,
             ("MEI_DRV[%02d]: ERROR - ImageCntrl size (%d) != FW Image size (%d - 8)" MEI_DRV_CRLF,
               MEI_DRV_LINENUM_GET(pMeiDev),
               pMeiDev->fwDl.pImageCtrl->imageSize_Bytes,
               pMeiDev->fwDl.size_byte));

      return IFX_ERROR;
   }

   /*
      Write Code/Data pages via DMA
      - Protect device DMA access
   */
   MEI_DRV_GET_UNIQUE_ACCESS(pMeiDev);

   for (pageIndex = 0; pageIndex < pMeiDev->fwDl.pImageCtrl->imageNumOfPages; pageIndex++)
   {
      if (pPageDir[pageIndex].codePageSize_32Bit  & MEI_BOOT_FLAG)
      {

         if ( (MEI_WritePage( pMeiDev, pageIndex, IFX_FALSE, 0xFFFFFFFF)) != IFX_SUCCESS)
         {
            PRN_ERR_USR_NL( MEI_ROM, MEI_DRV_PRN_LEVEL_ERR,
                   ( "MEI_DRV[%02d]: ERROR - DMA Download, write boot code page[%d]" MEI_DRV_CRLF,
                     MEI_DRV_LINENUM_GET(pMeiDev), pageIndex));

            goto MEI_DO_DMA_BOOT_FWDL_ERROR;
         }

         codePages++;
      }     /* if (... & MEI_BOOT_FLAG) { code page } */

      /* check data page for download */
      if (pPageDir[pageIndex].dataPageSize_32Bit  & MEI_BOOT_FLAG)
      {
         if ( (MEI_WritePage( pMeiDev, pageIndex, IFX_TRUE, 0xFFFFFFFF)) != IFX_SUCCESS)
         {
            PRN_ERR_USR_NL( MEI_ROM, MEI_DRV_PRN_LEVEL_ERR,
                   ( "MEI_DRV[%02d]: ERROR - DMA Download, write boot data page[%d]" MEI_DRV_CRLF,
                     MEI_DRV_LINENUM_GET(pMeiDev), pageIndex));

            goto MEI_DO_DMA_BOOT_FWDL_ERROR;
         }

         dataPages++;
      }     /* if (... & MEI_BOOT_FLAG) { code page } */
   }     /* for (pageCount; ..; ..) */

   MEI_FWDL_DMA_SET_STATE( &pMeiDev->fwDl.cntrlFwDlDmaCs,
                                 e_MEI_FWDL_DMA_BOOT_DL_DONE);

   MEI_DRV_RELEASE_UNIQUE_ACCESS(pMeiDev);

   PRN_DBG_USR( MEI_ROM, MEI_DRV_PRN_LEVEL_NORMAL, MEI_DRV_LINENUM_GET(pMeiDev),
          ("MEI_DRV[%02d]: DMA Download done - pagecount code %d, data %d" MEI_DRV_CRLF,
            MEI_DRV_LINENUM_GET(pMeiDev), codePages, dataPages));

   PRN_DBG_USR( MEI_ROM, MEI_DRV_PRN_LEVEL_LOW, MEI_DRV_LINENUM_GET(pMeiDev),
          ("MEI_DRV[%02d]: DownLoad --> next state <DMACS_BOOT_DL_DONE> (%d)" MEI_DRV_CRLF,
            MEI_DRV_LINENUM_GET(pMeiDev), e_MEI_FWDL_DMA_BOOT_DL_DONE));

   return IFX_SUCCESS;

MEI_DO_DMA_BOOT_FWDL_ERROR:
   MEI_DRV_RELEASE_UNIQUE_ACCESS(pMeiDev);

   return IFX_ERROR;
}


/**
   Trigger the ROM Handler to start the image.
*/
static IFX_int32_t MEI_Do_CMD_ONLINESTATEACTIVATE(MEI_DEV_T *pMeiDev)
{
   IFX_uint32_t      msg_size;
   MEI_Mailbox_t   bootMsg;

   /*
      setup the boot message
   */
   bootMsg.MbxCode = MEI_MBOX_CODE_BOOT;
   bootMsg.FctCode = 0x8000;
   bootMsg.MessageID = CMD_ONLINESTATEACTIVATE;
   bootMsg.Size = 0;
   bootMsg.ResWord4 = 0x0000;
   bootMsg.ResWord5 = 0x0000;

   /*
      mailbox message size: payload + header
   */
   msg_size = MEI_BOOT_HEADER_16BIT_SIZE * sizeof(IFX_uint16_t);

   /* setup timeout counter for the next state */
   MEI_SET_TIMEOUT_CNT( pMeiDev,
                          MEI_MaxWaitDfeResponce_ms / MEI_MIN_MAILBOX_POLL_TIME_MS);

   MEI_FWDL_DMA_SET_STATE( &pMeiDev->fwDl.cntrlFwDlDmaCs,
                                 e_MEI_FWDL_DMA_WAIT_ACK_GOONLINE);

   PRN_DBG_USR( MEI_ROM, MEI_DRV_PRN_LEVEL_NORMAL, MEI_DRV_LINENUM_GET(pMeiDev),
         ("MEI_DRV[%02d]: DMA DL --> <CMD_ONLINESTATEACTIVATE>" MEI_DRV_CRLF,
           MEI_DRV_LINENUM_GET(pMeiDev)));

   PRN_DBG_USR( MEI_ROM, MEI_DRV_PRN_LEVEL_NORMAL, MEI_DRV_LINENUM_GET(pMeiDev),
          ("MEI_DRV[%02d]: DMA DL --> next state <DMACS_WAIT_ACK_GOONLINE> (%d)" MEI_DRV_CRLF,
            MEI_DRV_LINENUM_GET(pMeiDev), e_MEI_FWDL_DMA_WAIT_ACK_GOONLINE));

   if ( (MEI_WriteRomBootMsg(pMeiDev, &bootMsg, msg_size)) == 0 )
   {
      /* error while send */
      PRN_ERR_USR_NL( MEI_ROM, MEI_DRV_PRN_LEVEL_ERR,
            ("MEI_DRV[%02d]: ERROR: send boot msg <CMD_ONLINESTATEACTIVATE>" MEI_DRV_CRLF,
              MEI_DRV_LINENUM_GET(pMeiDev)));

      MEI_FWDL_DMA_SET_STATE( &pMeiDev->fwDl.cntrlFwDlDmaCs,
                                    e_MEI_FWDL_DMA_ABORT);

      return IFX_ERROR;
   }

   return IFX_SUCCESS;
}

/**
   State Machine - boot message firmware download.

\param
   pMeiDev: points to the VINAX device struct.

*/
static IFX_int32_t MEI_FwDlDmaStateMachine( MEI_DEV_T *pMeiDev )
{
   MEI_FWDL_DMACS_CONTROL_T *pCntrlFwDlDma = &pMeiDev->fwDl.cntrlFwDlDmaCs;

   IFX_int32_t ret = IFX_ERROR;

   switch( MEI_FWDL_DMA_GET_STATE(pCntrlFwDlDma) )
   {
      case e_MEI_FWDL_DMA_INIT:
         /* set the image informations */
         pMeiDev->fwDl.pImageCtrl = (MEI_FW_IMAGE_CNTRL_T *)pMeiDev->fwDl.pDfeImage;
         pMeiDev->fwDl.pPageDir   =
            (MEI_FW_IMAGE_PAGE_T *)( pMeiDev->fwDl.pDfeImage +
                                           sizeof(MEI_FW_IMAGE_CNTRL_T) );

         PRN_DBG_USR( MEI_ROM, MEI_DRV_PRN_LEVEL_LOW, MEI_DRV_LINENUM_GET(pMeiDev),
                ("MEI_DRV[%02d]: DownLoad --> next state <DMACS_DO_BOOT_DL> (%d)" MEI_DRV_CRLF,
                  MEI_DRV_LINENUM_GET(pMeiDev), e_MEI_FWDL_DMA_DO_BOOT_DL));


         MEI_FWDL_DMA_SET_STATE(pCntrlFwDlDma, e_MEI_FWDL_DMA_DO_BOOT_DL);
         break;

      case e_MEI_FWDL_DMA_DO_BOOT_DL:
         /* download boot code */
         if ( (ret = MEI_DoDmaBootFwDl(pMeiDev)) != IFX_SUCCESS)
         {
            MEI_FWDL_DMA_SET_STATE(pCntrlFwDlDma, e_MEI_FWDL_DMA_ABORT);
         }

         break;


      case e_MEI_FWDL_DMA_BOOT_DL_DONE:
         /* the boot code download done --> send GOONLINE command */
         ret = MEI_Do_CMD_ONLINESTATEACTIVATE(pMeiDev);
         break;


      case e_MEI_FWDL_DMA_WAIT_ACK_GOONLINE:
         /* wait: for an ACK response from the VINAX boot loader */
         MEI_PollIntPerVnxLine(pMeiDev, e_MEI_DEV_ACCESS_MODE_PASSIV_POLL);

         if (MEI_DRV_MAILBOX_STATE_GET(pMeiDev) != e_MEI_MB_FREE)
         {

            if ( MEI_WaitForMailbox(pMeiDev) != IFX_SUCCESS)
            {
               /* timeout */
               PRN_ERR_USR_NL( MEI_ROM, MEI_DRV_PRN_LEVEL_ERR,
                     ("MEI_DRV[%02d]: DL DMACS timeout <Wait for VINAX> - DL state = %d" MEI_DRV_CRLF,
                       MEI_DRV_LINENUM_GET(pMeiDev), MEI_FWDL_DMA_GET_STATE(pCntrlFwDlDma) ));

               /* protect the driver against delayed acks while changing the state */
               MEI_DRV_GET_UNIQUE_ACCESS(pMeiDev);

               MEI_FWDL_DMA_SET_STATE(pCntrlFwDlDma, e_MEI_FWDL_DMA_ABORT);

               MEI_DRV_RELEASE_UNIQUE_ACCESS(pMeiDev);
            }
            else
               ret = IFX_SUCCESS;
         }
         break;

      case e_MEI_FWDL_DMA_FINISHED:
         /* now it's time to go online */
         ret = IFX_SUCCESS;
         break;

      default:
         break;
   }

   return ret;
}


/* ==========================================================================
   Global function definitions
   ========================================================================== */

/**
   Check the given page info against some limits.

\param
   pMeiDev     points to the current VINAX device.
\param
   pageIndex   Index of the requested page within the image.
\param
   bData       IFX_FALSE: check the corresponding data page
               IFX_TRUE:  check the corresponding code page

\return
   IFX_ERROR: in case something is wrong.
   page size:  size of the requested page.
*/
IFX_int32_t MEI_CheckCsPage(
                        MEI_DEV_T *pMeiDev,
                        IFX_uint32_t pageIndex,
                        IFX_boolean_t  bData)
{
   IFX_uint32_t pageSize_word;
   MEI_FW_IMAGE_PAGE_T *pPageDir = pMeiDev->fwDl.pPageDir;

   if (pageIndex > pMeiDev->fwDl.pImageCtrl->imageNumOfPages)
   {
      return IFX_ERROR;
   }

   pageSize_word = (~MEI_BOOT_FLAG) &
      ((bData) ? pPageDir[pageIndex].dataPageSize_32Bit : pPageDir[pageIndex].codePageSize_32Bit);

   if ( pageSize_word > ( (bData) ? MEI_MAX_DATA_PAGESIZE_WORD : MEI_MAX_CODE_PAGESIZE_WORD ) )
   {
      return IFX_ERROR;
   }

   return (IFX_int32_t)(pageSize_word);
}




/**
   ACK - ACK_ONLINESTATEACTIVATE has been received by the VINAX.

   The ROM code will switch over to the online code.
   - Reread and set the new message box location.

\param
   pMeiDev     points to the current VINAX device.
\param
   pBootMsg    points to the received ACK_ONLINESTATEACTIVATE boot message

\return
   IFX_SUCCESS: valid boot message.
   IFX_ERROR:   corrupted or valid boot message.

\attention
   Reading these message out from the mailbox will trigger the ROM code
   to switch over to the online code.

\attention
   - Called on int-level
*/
IFX_int32_t MEI_FDOnAck_ONLINESTATEACTIVATE( MEI_DEV_T *pMeiDev,
                                                   MEI_Mailbox_t *pBootMsg )
{
   /* ACK received - free the mailbox status */
   MEI_DRV_MAILBOX_STATE_SET(pMeiDev, e_MEI_MB_FREE);

   /* ============================================
      !!! NOW SWITCH OVER TO ONLINE CODE !!!
      ============================================ */

   PRN_DBG_INT( MEI_ROM, MEI_DRV_PRN_LEVEL_NORMAL, MEI_DRV_LINENUM_GET(pMeiDev),
        ("MEI_DRV[%02d]: DownLoad --> <Ack_ONLINESTATEACTIVATE> recv" MEI_DRV_CRLF,
          MEI_DRV_LINENUM_GET(pMeiDev)));

   if ( (MEI_FWDL_DMA_GET_STATE(&pMeiDev->fwDl.cntrlFwDlDmaCs))
        == e_MEI_FWDL_DMA_WAIT_ACK_GOONLINE )
   {
      /* only go if the driver is in the correct state */
      MEI_FWDL_DMA_SET_STATE( &pMeiDev->fwDl.cntrlFwDlDmaCs,
                                e_MEI_FWDL_DMA_FINISHED);

      MEI_DRV_STATE_SET(pMeiDev, e_MEI_DRV_STATE_WAIT_FOR_FIRST_RESP);
   }
   else
   {
      PRN_ERR_INT_NL( MEI_ROM, MEI_DRV_PRN_LEVEL_ERR,
           ("MEI_DRV[%02d]: ERROR DL discard <Ack_ONLINESTATEACTIVATE> DL-State = %d, Drv-State = %d" MEI_DRV_CRLF,
             MEI_DRV_LINENUM_GET(pMeiDev),
             MEI_FWDL_DMA_GET_STATE(&pMeiDev->fwDl.cntrlFwDlDmaCs),
             MEI_DRV_STATE_GET(pMeiDev) ));
   }

   return IFX_SUCCESS;
}

/**
   CodeSwap statemachine.
   - start with the first CodeSwap request.
   - wait for Modem Ready message.

\param
   pMeiDev:    Points to the VINAX device struct.
\param
   pCmvCsMsg:  Points to the corresponding CS message.

\return
   IFX_SUCCESS: Code Swap processed successful.
   IFX_ERROR:   Error while Code Swap - Write Pages.

\attention
   - Called on int-level
*/
IFX_int32_t MEI_ProcessCodeSwapRequest( MEI_DEV_T *pMeiDev,
                                          CMV_MESSAGE_CS_T *pCmvCsMsg)
{
   IFX_uint32_t numOfPageReq, csReqIndex, pageIndex, csCodePage = 0, csDataPage = 0;
   IFX_uint16_t mbxCode;
   IFX_uint32_t destAddr = 0xFFFFFFFF; /* default addr, signals static cs */

   mbxCode = (IFX_uint16_t)pCmvCsMsg->header.mbxCode;

   switch (mbxCode)
   {
      case MEI_MBOX_CODE_CS_STAT_REQ:
         /* the length field contains the number of pages to be swapped */
         numOfPageReq = P_CMV_MSGHDR_LENGTH_GET(pCmvCsMsg);

         /* make some checks against size and max allowed pages */
         if (numOfPageReq > (IFX_uint32_t)(P_CMV_MSGHDR_PAYLOAD_SIZE_GET(pCmvCsMsg)) )
         {
            PRN_ERR_INT_NL( MEI_ROM, MEI_DRV_PRN_LEVEL_ERR,
                 ( "MEI_DRV[%02d]: WARNING - change num of CS(stat) pages, %d --> %d" MEI_DRV_CRLF,
                    MEI_DRV_LINENUM_GET(pMeiDev), numOfPageReq, P_CMV_MSGHDR_PAYLOAD_SIZE_GET(pCmvCsMsg)));

            numOfPageReq = P_CMV_MSGHDR_PAYLOAD_SIZE_GET(pCmvCsMsg);
         }
         break;
      case MEI_MBOX_CODE_CS_DYN_REQ:
         numOfPageReq = ((IFX_uint32_t)(P_CMV_MSGHDR_PAYLOAD_SIZE_GET(pCmvCsMsg))) / 3;
         /*
         FIX: the length field contains the real number of pages.
         numOfPageReq = (P_CMV_MSGHDR_LENGTH_GET(pCmvCsMsg)) / (sizeof(CMV_DYN_CODESWAP_PAGE_INFO_T) / 2) ;
         */

         break;
      default:
         return IFX_ERROR;
   }

   if (numOfPageReq > MEI_CMV_CODESWAP_MAX_PAGES)
   {
      PRN_ERR_INT_NL( MEI_ROM, MEI_DRV_PRN_LEVEL_ERR,
           ( "MEI_DRV[%02d]: WARNING - change num of CS(0x%X) pages, %d --> %d" MEI_DRV_CRLF,
              MEI_DRV_LINENUM_GET(pMeiDev), mbxCode, numOfPageReq, MEI_CMV_CODESWAP_MAX_PAGES));

      numOfPageReq = MEI_CMV_CODESWAP_MAX_PAGES;
   }

   PRN_DBG_INT( MEI_ROM, MEI_DRV_PRN_LEVEL_LOW, MEI_DRV_LINENUM_GET(pMeiDev),
        ( "MEI_DRV[%02d]: do CS(0x%X) pages, %d" MEI_DRV_CRLF,
           MEI_DRV_LINENUM_GET(pMeiDev), mbxCode, numOfPageReq));


   for (csReqIndex = 0; csReqIndex < numOfPageReq; csReqIndex++)
   {
      if (mbxCode == MEI_MBOX_CODE_CS_STAT_REQ)
      {
         pageIndex = pCmvCsMsg->params.csStaticParams.pageIdx[csReqIndex];
      }
      else
      {
         pageIndex = pCmvCsMsg->params.csDynParams.pageInfo[csReqIndex].pageIdx;
         destAddr  = (((IFX_uint32_t)pCmvCsMsg->params.csDynParams.pageInfo[csReqIndex].h_destAddr) << 16) |
                     ((IFX_uint32_t)pCmvCsMsg->params.csDynParams.pageInfo[csReqIndex].l_destAddr);
      }

      /*
         CodePage: write CodeSwap page via DMA
                   (allow also download of initial boot pages)
      */
      if ( (MEI_WritePage( pMeiDev, pageIndex, IFX_FALSE, destAddr)) != IFX_SUCCESS)
      {
         PRN_ERR_INT_NL( MEI_ROM, MEI_DRV_PRN_LEVEL_ERR,
              ( "MEI_DRV[%02d]: ERROR - DMA Download, write CS code page[%d]" MEI_DRV_CRLF,
                 MEI_DRV_LINENUM_GET(pMeiDev), pageIndex));

         return IFX_ERROR;
      }
      csCodePage++;

      /*
         DataPage: write CodeSwap page via DMA
                   (allow also download of initial boot pages)
      */
      if ( (MEI_WritePage( pMeiDev, pageIndex, IFX_TRUE, destAddr)) != IFX_SUCCESS)
      {
         PRN_ERR_INT_NL( MEI_ROM, MEI_DRV_PRN_LEVEL_ERR,
              ( "MEI_DRV[%02d]: ERROR - DMA Download, write CS data page[%d]" MEI_DRV_CRLF,
                 MEI_DRV_LINENUM_GET(pMeiDev), pageIndex));

         return IFX_ERROR;
      }
      csDataPage++;

#if (MEI_SUPPORT_DRV_MODEM_TESTS == 1)
      /* special tests while normal operation - only for testing */
      MEI_DTEST_VerifyCsPage(
            pMeiDev, pageIndex,
            ( (destAddr == 0xFFFFFFFF) ? pMeiDev->fwDl.pPageDir[pageIndex].codeDestAddr : destAddr),
            (  MEI_PROC_TEST_CNTRL_BUFFER_DMA_FLAG
             | MEI_PROC_TEST_CNTRL_BUFFER_MEI_FLAG
             | MEI_DRV_MODEM_TESTS_INT_LEVEL) );
#endif
   }     /* for (csReqIndex = 0; ...; ...) */

   PRN_DBG_INT( MEI_ROM, MEI_DRV_PRN_LEVEL_LOW, MEI_DRV_LINENUM_GET(pMeiDev),
        ( "MEI_DRV[%02d]: CodeSwap - %d/%d code/date pages processed" MEI_DRV_CRLF,
           MEI_DRV_LINENUM_GET(pMeiDev), csCodePage, csDataPage));

   return IFX_SUCCESS;
}

/**
   Start the FW downlaod via DMA boot page transfer and CodeSwap.

   1. Download the boot pages via DMA
   2. handle the Code Swap requests form the VINAX

*/
IFX_int32_t MEI_StartDmaCsDl(MEI_DEV_T *pMeiDev)
{
   IFX_boolean_t runflag = IFX_TRUE;
   IFX_int32_t ret;
   MEI_FWDL_DMACS_CONTROL_T *pCntrlFwDlDma = &pMeiDev->fwDl.cntrlFwDlDmaCs;

   /* reset the download state machine */
   MEI_FWDL_DMA_SET_STATE( &pMeiDev->fwDl.cntrlFwDlDmaCs,
                                 e_MEI_FWDL_DMA_INIT);


   PRN_DBG_USR( MEI_ROM, MEI_DRV_PRN_LEVEL_NORMAL, MEI_DRV_LINENUM_GET(pMeiDev),
          ("MEI_DRV[%02d]: Start Download - DMA transfer" MEI_DRV_CRLF,
            MEI_DRV_LINENUM_GET(pMeiDev)));

   while(runflag)
   {
      /* call state maschine */
      ret =  MEI_FwDlDmaStateMachine( pMeiDev );

      /* check download state maschine */
      if ( (MEI_FWDL_DMA_GET_STATE(pCntrlFwDlDma) == e_MEI_FWDL_DMA_FINISHED) ||
           (MEI_FWDL_DMA_GET_STATE(pCntrlFwDlDma) == e_MEI_FWDL_DMA_ABORT) )
      {
         break;
      }

      /* check driver state maschine */
      if ( MEI_DRV_STATE_GET(pMeiDev) != e_MEI_DRV_STATE_BOOT_ROM_DL_PENDING )
      {
         /*
            Error occurred while Download
            - receive unexpected message
         */
         break;
      }
   }

   if ( MEI_FWDL_DMA_GET_STATE(pCntrlFwDlDma) == e_MEI_FWDL_DMA_FINISHED )
   {
      /* only wait for Code Swap complete */
      /*
         State already set when ack of ACTIVATE ONLINE has been received
         MEI_DRV_STATE_SET(pMeiDev, e_MEI_DRV_STATE_WAIT_FOR_FIRST_RESP);
      */

      PRN_DBG_USR( MEI_ROM, MEI_DRV_PRN_LEVEL_NORMAL, MEI_DRV_LINENUM_GET(pMeiDev),
             ("MEI_DRV[%02d]: DL/CS - Wait for 1. Response" MEI_DRV_CRLF,
               MEI_DRV_LINENUM_GET(pMeiDev)));


      /* ===================================================
         wait active for code swap (especially in poll mode)
         =================================================== */

      /* setup timeout counter for the next state */
      MEI_SET_TIMEOUT_CNT( pMeiDev,
            ((MEI_MaxWaitForModemReady_ms & ~MEI_CFG_DEF_WAIT_PROTECTION_FLAG) /
             MEI_MIN_MAILBOX_POLL_TIME_MS));

      runflag = IFX_TRUE;
      while(runflag)
      {
         MEI_PollIntPerVnxLine(pMeiDev, e_MEI_DEV_ACCESS_MODE_PASSIV_POLL);

         /* MODEM Ready still not received */
         if (MEI_DRV_STATE_GET(pMeiDev) == e_MEI_DRV_STATE_WAIT_FOR_FIRST_RESP)
         {
            /* Wait for Code Swap / Modem Ready request */
            if ( (ret = MEI_WaitForMailbox(pMeiDev)) == IFX_ERROR)
            {
               /* timeout */
               PRN_ERR_USR_NL( MEI_ROM, MEI_DRV_PRN_LEVEL_ERR,
                     ("MEI_DRV[%02d]: DL/CS wait for 1. response timeout - state = %d" MEI_DRV_CRLF,
                       MEI_DRV_LINENUM_GET(pMeiDev), MEI_DRV_STATE_GET(pMeiDev) ));

               /* ERROR timeout */
               break;
            }
         }
         else
         {
            /* state has changed */
            break;
         }
      }        /* while(runflag) */
   }     /* if ( STATE == e_MEI_FWDL_DMA_FINISHED ) */


   if (MEI_DRV_STATE_GET(pMeiDev) == e_MEI_DRV_STATE_DFE_READY)
   {
      PRN_DBG_USR( MEI_ROM, MEI_DRV_PRN_LEVEL_NORMAL, MEI_DRV_LINENUM_GET(pMeiDev),
             ("MEI_DRV[%02d]: DL/CS 1. response received - done" MEI_DRV_CRLF,
               MEI_DRV_LINENUM_GET(pMeiDev)));

      return IFX_SUCCESS;
   }

   PRN_DBG_USR( MEI_ROM, MEI_DRV_PRN_LEVEL_HIGH, MEI_DRV_LINENUM_GET(pMeiDev),
          ("MEI_DRV[%02d]: ERROR - DL/CS missing 1. response" MEI_DRV_CRLF,
            MEI_DRV_LINENUM_GET(pMeiDev)));

   return e_MEI_ERR_OP_FAILED;
}

#define MEI_REL_MBOX_WHILE_CS    IFX_FALSE

/**
   Receive a Code Swap Request message.

\param
   pMeiDev  points to the device sturct.

\return
   none

\attention
   - Called on int-level

*/
IFX_void_t MEI_Recv_CODE_SWAP_REQ(MEI_DEV_T *pMeiDev,  IFX_uint16_t mbCode)
{
   IFX_int32_t count;
   CMV_MESSAGE_CS_T tmpCsReq;

#if (MEI_SUPPORT_TIME_TRACE == 1)
   IFX_uint32_t start_ms, end_ms;
#endif

   if (MEI_DRV_BOOTMODE_GET(pMeiDev) !=  e_MEI_DRV_BOOT_MODE_7)
   {
      PRN_ERR_INT_NL( MEI_DRV, MEI_DRV_PRN_LEVEL_ERR,
           ("MEI_DRV[%02d]: FATAL ERROR - CodeSwap recv - invalid bootmode (%d)" MEI_DRV_CRLF,
            MEI_DRV_LINENUM_GET(pMeiDev), pMeiDev->modemData.devBootMode));

      /* MEI_ReleaseMailboxMsg(&pMeiDev->meiDrvCntrl); */

      return;
   }

   MEI_GET_TICK_MS_TIME_TRACE(start_ms);


   /*
      - check if the code swap is allowed.
      - process the code swap request.
      Note:
         The CodeSwap will be read out and acknowledged immediately
         but possible further requests will be defered.
   */
   if ( (MEI_DRV_STATE_GET(pMeiDev) != e_MEI_DRV_STATE_WAIT_FOR_FIRST_RESP) &&
        (MEI_DRV_STATE_GET(pMeiDev) != e_MEI_DRV_STATE_DFE_READY)  )
   {
      PRN_ERR_INT_NL( MEI_DRV, MEI_DRV_PRN_LEVEL_ERR,
           ("MEI_DRV[%02d]: ERROR - MEI_Recv_CODE_SWAP_REQ - invalid state = %d" MEI_DRV_CRLF,
             MEI_DRV_LINENUM_GET(pMeiDev), MEI_DRV_STATE_GET(pMeiDev)));

      /* signal code swap done */
      MEI_ReleaseMailboxMsg(&pMeiDev->meiDrvCntrl);

      return;
   }

   /* special tests while normal operation - only for testing */
#if (MEI_SUPPORT_DRV_MODEM_TESTS == 1)
   MEI_DTEST_ModemControllerStateCheck(pMeiDev, IFX_NULL, "CS Start");
   MEI_DTEST_IfStateCheck( pMeiDev,
                             (MEI_CHECK_ALL | MEI_DRV_MODEM_TESTS_INT_LEVEL),
                             0xFFFFFFFE, "CS Start");
#endif

   /* get the message */
   tmpCsReq.header.mbxCode = mbCode;

   count = MEI_GetMailBoxMsg( &pMeiDev->meiDrvCntrl,
                              pMeiDev->modemData.mBoxDescr.addrArc2Me,
                              (MEI_MEI_MAILBOX_T *)&tmpCsReq,
                              sizeof(CMV_MESSAGE_CS_T)/sizeof(IFX_uint16_t),
                              MEI_REL_MBOX_WHILE_CS);
   if (count < 0)
   {
      /* error receive mailbox message while init state */
      PRN_ERR_INT_NL( MEI_DRV, MEI_DRV_PRN_LEVEL_ERR,
           ("MEI_DRV[%02d]: ERROR MEI_Recv_CODE_SWAP_REQ - count = %d" MEI_DRV_CRLF,
             MEI_DRV_LINENUM_GET(pMeiDev), count));

      /* release the mailbox */
      if (!MEI_REL_MBOX_WHILE_CS)
         MEI_ReleaseMailboxMsg(&pMeiDev->meiDrvCntrl);

      return;
   }

   /* always a 16 bit message --> no swap required */
   MEI_LOG_CMV_MSG( pMeiDev, (CMV_STD_MESSAGE_T *)&tmpCsReq,
                          "CodeSwap Req", MEI_DRV_PRN_LEVEL_NORMAL);

   MEI_DBG_MSG_LOG_DUMP(pMeiDev, (CMV_STD_MESSAGE_T *)&tmpCsReq);

   /* process the codeswap request */
   count = MEI_ProcessCodeSwapRequest( pMeiDev, &tmpCsReq);

   /* release the mailbox */
   if (!MEI_REL_MBOX_WHILE_CS)
      MEI_ReleaseMailboxMsg(&pMeiDev->meiDrvCntrl);

   if (count != IFX_SUCCESS)
   {
      /* error receive mailbox message while init state */
      PRN_ERR_INT_NL( MEI_DRV, MEI_DRV_PRN_LEVEL_ERR,
           ("MEI_DRV[%02d]: ERROR MEI_Recv_CODE_SWAP_REQ - process Code Swap" MEI_DRV_CRLF,
             MEI_DRV_LINENUM_GET(pMeiDev)));
   }
   else
   {
      if (MEI_DRV_STATE_GET(pMeiDev) == e_MEI_DRV_STATE_WAIT_FOR_FIRST_RESP)
      {
         PRN_DBG_INT( MEI_DRV, MEI_DRV_PRN_LEVEL_NORMAL, MEI_DRV_LINENUM_GET(pMeiDev),
              ("MEI_DRV[%02d]: CODE_SWAP REQUEST(0x%X) done - "\
               "state: <wait for Modem Ready> notify target" MEI_DRV_CRLF,
                MEI_DRV_LINENUM_GET(pMeiDev), mbCode));
      }
      else
      {
         PRN_DBG_INT( MEI_DRV, MEI_DRV_PRN_LEVEL_NORMAL, MEI_DRV_LINENUM_GET(pMeiDev),
              ("MEI_DRV[%02d]: CODE_SWAP REQUEST(0x%X) done - "\
               "state: <Online> notify target" MEI_DRV_CRLF,
                MEI_DRV_LINENUM_GET(pMeiDev), mbCode));
      }

      /* signal code swap done */
      MEI_RegNotifyCodeSwapDone(&pMeiDev->meiDrvCntrl);
   }

   MEI_GET_TICK_MS_TIME_TRACE(end_ms);

#if (MEI_SUPPORT_TIME_TRACE == 1)
   {
      IFX_uint32_t tick_ms = MEI_TIME_TRACE_GET_TICK_MS(start_ms, end_ms);
      MEI_TIME_TRACE_CHECK_PROCESS_CS_MAX( pMeiDev->timeStat, tick_ms);

      if (tick_ms > MEI_MAX_TIME_CODESWAP_MS)
      {
         PRN_ERR_INT_NL( MEI_DRV, MEI_DRV_PRN_LEVEL_ERR,
              ("MEI_DRV[%02d]: WARNING  - CODE_SWAP REQ(0x%X) time exceeded  - %d ms" MEI_DRV_CRLF,
                MEI_DRV_LINENUM_GET(pMeiDev), mbCode, tick_ms));
      }
   }
#endif


   /* special tests while normal operation - only for testing */
#if (MEI_SUPPORT_DRV_MODEM_TESTS == 1)
   MEI_DTEST_ModemControllerStateCheck(pMeiDev, IFX_NULL, "CS DONE");
   MEI_DTEST_IfStateCheck(pMeiDev, MEI_CHECK_ALL,  0xFFFFFFFF, "CS DONE");
#endif

   return;
}

IFX_void_t MEI_DlDataClear(MEI_DEV_T *pMeiDev)
{
   if (pMeiDev->fwDl.pDfeImage != NULL)
   {
      int imageId = pMeiDev->fwDl.imageId;

      memset(&pMeiDev->fwDl, 0x00, sizeof(MEI_FW_DOWNLOAD_CNTRL_T));

      /* FW image found - clear local data and free it */
      if ( ChipFwImage[imageId].useCount )
         ChipFwImage[imageId].useCount--;
   }
}

/**
   Display FW image infos.

\param
   pFwImage    points to the initial FW image.
\param
   bHostOrder  infos for display
               (normaly the Image will be in little endian order)

\return
   NONE
*/
static IFX_void_t MEI_FDShowImageDir(
                        MEI_FW_IMAGE_T        *pFwImage,
                        IFX_boolean_t           bHostOrder)
{
   IFX_uint32_t pageCount, imageNumOfPages;
   MEI_FW_IMAGE_CNTRL_T *pFwImageCntrl = (MEI_FW_IMAGE_CNTRL_T *)pFwImage->pImage;

   MEI_DRV_PRN_LOCAL_DBG_VAR_CREATE(
      MEI_FW_IMAGE_PAGE_T, *pFwImagePageInfo, (MEI_FW_IMAGE_PAGE_T *)(pFwImage->pImage + sizeof(MEI_FW_IMAGE_CNTRL_T)) );

   imageNumOfPages = (
      (bHostOrder) ?
      /*  host order */  pFwImageCntrl->imageNumOfPages :
      /* modem order */ (SWAP32_BYTE_ORDER(pFwImageCntrl->imageNumOfPages))
                     );

   PRN_DBG_USR_NL( MEI_DRV, MEI_DRV_PRN_LEVEL_NORMAL,
         (MEI_DRV_CRLF "=== IMAGE ==================================================" MEI_DRV_CRLF));

   PRN_DBG_USR_NL( MEI_DRV, MEI_DRV_PRN_LEVEL_NORMAL,
         ("Size = %d [byte], CheckSum = 0x%08X, NumOfPages = %d" MEI_DRV_CRLF,
           ( (!bHostOrder) ? (SWAP32_BYTE_ORDER(pFwImageCntrl->imageSize_Bytes)) :
                             (pFwImageCntrl->imageSize_Bytes) ),
           ( (!bHostOrder) ? (SWAP32_BYTE_ORDER(pFwImageCntrl->imageCheckSum)) :
               (pFwImageCntrl->imageCheckSum) ),
           imageNumOfPages ));

   for (pageCount = 0; pageCount < imageNumOfPages; pageCount++)
   {

      PRN_DBG_USR_NL( MEI_DRV, MEI_DRV_PRN_LEVEL_NORMAL,
            ("--- Page %02d ----------------------------------------------" MEI_DRV_CRLF,
             pageCount));


      PRN_DBG_USR_NL( MEI_DRV, MEI_DRV_PRN_LEVEL_NORMAL,
            ("Program: Offset = 0x%08X [Byte], Addr = 0x%08X, Size = 0x%08X [32 Bit]" MEI_DRV_CRLF,
               (!bHostOrder) ? (SWAP32_BYTE_ORDER(pFwImagePageInfo[pageCount].codeOffset_Byte)) :
                               (pFwImagePageInfo[pageCount].codeOffset_Byte),
               (!bHostOrder) ? (SWAP32_BYTE_ORDER(pFwImagePageInfo[pageCount].codeDestAddr)) :
                               (pFwImagePageInfo[pageCount].codeDestAddr),
               (!bHostOrder) ? (SWAP32_BYTE_ORDER(pFwImagePageInfo[pageCount].codePageSize_32Bit)) :
                               (pFwImagePageInfo[pageCount].codePageSize_32Bit) ));

      PRN_DBG_USR_NL( MEI_DRV, MEI_DRV_PRN_LEVEL_NORMAL,
            ("Data:    Offset = 0x%08X [Byte], Addr = 0x%08X, Size = 0x%08X [32 Bit]" MEI_DRV_CRLF,
               (!bHostOrder) ? (SWAP32_BYTE_ORDER(pFwImagePageInfo[pageCount].dataOffset_Byte)) :
                               (pFwImagePageInfo[pageCount].dataOffset_Byte),
               (!bHostOrder) ? (SWAP32_BYTE_ORDER(pFwImagePageInfo[pageCount].dataDestAddr)) :
                               (pFwImagePageInfo[pageCount].dataDestAddr),
               (!bHostOrder) ? (SWAP32_BYTE_ORDER(pFwImagePageInfo[pageCount].dataPageSize_32Bit)) :
                               (pFwImagePageInfo[pageCount].dataPageSize_32Bit) ));

      PRN_DBG_USR_NL( MEI_DRV, MEI_DRV_PRN_LEVEL_NORMAL,
            ("------------------------------------------------------------" MEI_DRV_CRLF));
   }

   return;
}

/**
   Check a given page destination range against the VINAX memory mapping.

\param
   pageIndex   - index of the memory page within the image [I].
\param
   bCodePage   - given page is a code (true) or a data (false) page [I].
\param
   bBootPage   - given page is a initial bootpage (true) [I].
\param
   startAddr   - destination start address of the page [I]
\param
   endAddr     - destination end address of the page [I]
\param
   pMemMap     - points to the memory map table [I].

\return
   IFX_SUCCESS - no violation found.
   IFX_ERROR   - memory map violation found.
*/
static IFX_int32_t MEI_ValidatPage(
                        IFX_uint32_t      pageIndex,
                        IFX_boolean_t     bCodePage,
                        IFX_boolean_t     bBootPage,
                        IFX_uint32_t      startAddr,
                        IFX_uint32_t      endAddr,
                        MEI_MEM_MAP_T   *pMemMap)
{
   IFX_int32_t    retVal = IFX_SUCCESS;
   IFX_int32_t    mapIndex = 0;

   if (startAddr >= endAddr)
   {
      return IFX_SUCCESS;
   }

   while(pMemMap[mapIndex].endAddr)
   {
      if ( pMemMap[mapIndex].bBootOnly && !bBootPage )
      {
         mapIndex++;
         continue;
      }

      if (startAddr <= pMemMap[mapIndex].endAddr)
      {
         if (endAddr >= pMemMap[mapIndex].startAddr)
         {
            PRN_ERR_USR_NL( MEI_DRV, MEI_DRV_PRN_LEVEL_ERR,
                   ("MEI_DRV: ERROR - MEM Map Violation, %s[%d] 0x%08X - 0x%08X overlap %s 0x%08X - 0x%08X" MEI_DRV_CRLF
                   , bCodePage ? "C-Page": "D-Page", pageIndex
                   , startAddr, endAddr
                   , (pMemMap[mapIndex].pDescStr) ? pMemMap[mapIndex].pDescStr : "RANGE"
                   , pMemMap[mapIndex].startAddr, pMemMap[mapIndex].endAddr  ));

            retVal = IFX_ERROR;
         }
      }
      mapIndex++;
   }

   return retVal;
}

/**
   Swap the firmware image for the corresponding boot mode.
   ROM Download Handler:
   - the whole image: swap 16 bit word aligned
     0x1234 5678 --> 0x3412 7856 (for download via 16 bit DMA)

   DMA Download and CodeSwap:
   - the image header swap to host order
     0x12345678 --> 0x78563412 (keep it in host order for CodeSwap management)
   - the code pages swap 16 bit word aligned
     0x1234 5678 --> 0x3412 7856 (for download via 16 bit DMA)

\param
   pFwImage    points to the initial FW image.
\param
   bootMode    indentify the boot mode.

\return
   IFX_SUCCESS if swap was successful or image already in the correct order.
   IFX_ERROR   invalid / not supported boot mode.
*/
static IFX_int32_t MEI_FDSwapImage(
                              MEI_FW_IMAGE_T        *pFwImage,
                              MEI_DRV_BOOT_MODES_E  drvBootMode)
{
   IFX_uint32_t i;

#if (MEI_BM7_CODESWAP_MEIDBG != 1)
   IFX_uint16_t *pImage_16Bit = NULL;
#endif

#if (MEI_BM7_CODESWAP_MEIDBG == 1)
   IFX_uint32_t *pImage_32Bit = NULL;
#endif

   #if (MEI_SUPPORT_DL_DMA_CS == 1)
   IFX_uint32_t pageCount;

   MEI_FW_IMAGE_CNTRL_T *pFwImageCntrl = (MEI_FW_IMAGE_CNTRL_T *)pFwImage->pImage;
   MEI_FW_IMAGE_PAGE_T  *pFwImagePageInfo =
         (MEI_FW_IMAGE_PAGE_T *)(pFwImage->pImage + sizeof(MEI_FW_IMAGE_CNTRL_T));
   #endif

   if (pFwImage->hostOrder)
   {
      /* image already in host order */
      PRN_DBG_USR_NL( MEI_DRV, MEI_DRV_PRN_LEVEL_NORMAL,
             ("MEI_DRV: FW download image already swapped" MEI_DRV_CRLF) );

      return IFX_SUCCESS;
   }

   switch(drvBootMode)
   {
      #if (MEI_SUPPORT_DL_DMA_CS == 1)
      case e_MEI_DRV_BOOT_MODE_7:
         /*
            Swap code/data pages and the image header seperatly.
            Image Header:
               will be kept on host for download and codeswap
               --> swap to host order (swap 32 bit).
            Code/Data pages:
               swap for DMA 16 bit transfer.
         */
         pFwImageCntrl->imageSize_Bytes = SWAP32_BYTE_ORDER(pFwImageCntrl->imageSize_Bytes);
         pFwImageCntrl->imageCheckSum   = SWAP32_BYTE_ORDER(pFwImageCntrl->imageCheckSum);
         pFwImageCntrl->imageNumOfPages = SWAP32_BYTE_ORDER(pFwImageCntrl->imageNumOfPages);

         PRN_DBG_USR_NL( MEI_DRV, MEI_DRV_PRN_LEVEL_NORMAL,
                ("MEI_DRV: FW download swap header (CodeSwap)" MEI_DRV_CRLF) );

         PRN_DBG_USR_NL( MEI_DRV, MEI_DRV_PRN_LEVEL_LOW,
                ("MEI_DRV: Swap Header (size %d, CRC 0x%08X, pages) %d" MEI_DRV_CRLF,
                  pFwImageCntrl->imageSize_Bytes,
                  pFwImageCntrl->imageCheckSum,
                  pFwImageCntrl->imageNumOfPages) );


         PRN_DBG_USR_NL( MEI_DRV, MEI_DRV_PRN_LEVEL_LOW,
                ( "MEI_DRV: Image Range 0x%08X - 0x%08X" MEI_DRV_CRLF,
                  (IFX_uint32_t)pFwImage->pImage,
                  (IFX_uint32_t)pFwImage->pImage + pFwImageCntrl->imageSize_Bytes + 4 ));

         for (pageCount = 0; pageCount < pFwImageCntrl->imageNumOfPages; pageCount++)
         {
            /* swap header info */
            pFwImagePageInfo[pageCount].codeOffset_Byte =
                        SWAP32_BYTE_ORDER(pFwImagePageInfo[pageCount].codeOffset_Byte);
            pFwImagePageInfo[pageCount].codeDestAddr =
                        SWAP32_BYTE_ORDER(pFwImagePageInfo[pageCount].codeDestAddr);
            pFwImagePageInfo[pageCount].codePageSize_32Bit =
                        SWAP32_BYTE_ORDER(pFwImagePageInfo[pageCount].codePageSize_32Bit);
            pFwImagePageInfo[pageCount].dataOffset_Byte =
                        SWAP32_BYTE_ORDER(pFwImagePageInfo[pageCount].dataOffset_Byte);
            pFwImagePageInfo[pageCount].dataDestAddr =
                        SWAP32_BYTE_ORDER(pFwImagePageInfo[pageCount].dataDestAddr);
            pFwImagePageInfo[pageCount].dataPageSize_32Bit =
                        SWAP32_BYTE_ORDER(pFwImagePageInfo[pageCount].dataPageSize_32Bit);

            /* swap code pages */
         #if (MEI_BM7_CODESWAP_MEIDBG == 1)
            pImage_32Bit = (IFX_uint32_t *)(pFwImage->pImage + pFwImagePageInfo[pageCount].codeOffset_Byte);
            for ( i = 0;
                  i < (pFwImagePageInfo[pageCount].codePageSize_32Bit & (~MEI_BOOT_FLAG));
                  i++)
            {
               pImage_32Bit[i] = SWAP32_BYTE_ORDER(pImage_32Bit[i]);
            }

            /* swap data pages */
            pImage_32Bit = (IFX_uint32_t *)(pFwImage->pImage + pFwImagePageInfo[pageCount].dataOffset_Byte);
            for ( i = 0;
                  i < (pFwImagePageInfo[pageCount].dataPageSize_32Bit & (~MEI_BOOT_FLAG));
                  i++)
            {
               pImage_32Bit[i] = SWAP32_BYTE_ORDER(pImage_32Bit[i]);
            }
         #else
            pImage_16Bit = (IFX_uint16_t *)(pFwImage->pImage + pFwImagePageInfo[pageCount].codeOffset_Byte);
            for ( i = 0;
                  i < ( (pFwImagePageInfo[pageCount].codePageSize_32Bit & (~MEI_BOOT_FLAG))
                                                                  * sizeof(IFX_uint16_t));
                  i++)
            {
               pImage_16Bit[i] = SWAP16_BYTE_ORDER(pImage_16Bit[i]);
            }

            /* swap data pages */
            pImage_16Bit = (IFX_uint16_t *)(pFwImage->pImage + pFwImagePageInfo[pageCount].dataOffset_Byte);
            for ( i = 0;
                  i < ( (pFwImagePageInfo[pageCount].dataPageSize_32Bit & (~MEI_BOOT_FLAG))
                                                                  * sizeof(IFX_uint16_t));
                  i++)
            {
               pImage_16Bit[i] = SWAP16_BYTE_ORDER(pImage_16Bit[i]);
            }
         #endif      /* #if (MEI_BM7_CODESWAP_MEIDBG == 1) */

         }        /* for (..; pageCount < pFwImageCntrl->imageNumOfPages; ..) */
         break;
      #endif
      default:
         PRN_ERR_USR_NL( MEI_DRV, MEI_DRV_PRN_LEVEL_ERR,
                ("MEI_DRV: FW download swap image - boot mode (%d) not supported" MEI_DRV_CRLF,
                  drvBootMode) );

         return IFX_ERROR;
   }

   /* mark the image as swapped */
   pFwImage->hostOrder = IFX_TRUE;

   return IFX_SUCCESS;
}

/**
   Start the FW download

\param
   pMeiDynCntrl: Points to the dynamic control struct.
\param
   imageId: index of the FW for download.

*/
static IFX_int32_t MEI_StartFwDownload(
                              MEI_DYN_CNTRL_T *pMeiDynCntrl,
                              IFX_int32_t       imageId)
{
   IFX_int32_t ret;
   MEI_DEV_T    *pMeiDev = pMeiDynCntrl->pMeiDev;
   MEI_FW_IMAGE_T *pFwImage = &ChipFwImage[imageId];

   PRN_DBG_USR( MEI_DRV, MEI_DRV_PRN_LEVEL_LOW, MEI_DRV_LINENUM_GET(pMeiDev),
          ("MEI_DRV [%02d-%02d]: Start FW download" MEI_DRV_CRLF,
           MEI_DRV_LINENUM_GET(pMeiDev), pMeiDynCntrl->openInstance) );

#if (MEI_SUPPORT_DL_DMA_CS == 1)
   /* set FW image within the driver device struct */
   pMeiDev->fwDl.pDfeImage = pFwImage->pImage;
   pMeiDev->fwDl.size_byte = pFwImage->size_byte;
   pMeiDev->fwDl.imageId = imageId;

   if (MEI_DRV_BOOTMODE_GET(pMeiDev) == e_MEI_DRV_BOOT_MODE_7)
   {
      MEI_FDShowImageDir(pFwImage, pFwImage->hostOrder);

      if (MEI_ValidateImage(pFwImage) != IFX_SUCCESS)
      {
         PRN_ERR_USR_NL( MEI_DRV, MEI_DRV_PRN_LEVEL_ERR,
                ("MEI_DRV: FATAL ERROR - FW image corrupted" MEI_DRV_CRLF) );

         return IFX_ERROR;
      }
      else
      {
         PRN_DBG_USR_NL( MEI_DRV, MEI_DRV_PRN_LEVEL_LOW,
                ("MEI_DRV: FW image - no violation found" MEI_DRV_CRLF) );
      }
   }
#endif

   /* call the ROM START Boot Loader - DL initial pages and codeswap */
   if (MEI_DRV_BOOTMODE_GET(pMeiDev) == e_MEI_DRV_BOOT_MODE_7)
   {
#if (MEI_SUPPORT_DL_DMA_CS == 1)
      if (MEI_FDSwapImage(pFwImage, e_MEI_DRV_BOOT_MODE_7) == IFX_SUCCESS)
      {
         MEI_DRV_STATE_SET(pMeiDev, e_MEI_DRV_STATE_BOOT_ROM_DL_PENDING);
         if ( (ret = MEI_StartDmaCsDl(pMeiDev)) == IFX_SUCCESS )
         {
            MEI_IF_STAT_INC_FWDL_COUNT(pMeiDev);
            PRN_DBG_USR( MEI_DRV, MEI_DRV_PRN_LEVEL_HIGH, MEI_DRV_LINENUM_GET(pMeiDev),
                   ("MEI_DRV [%02d-%02d]: FW download done (bm 7) - Wait Online" MEI_DRV_CRLF,
                    MEI_DRV_LINENUM_GET(pMeiDev), pMeiDynCntrl->openInstance ));
         }
         else
         {
            PRN_ERR_USR_NL( MEI_DRV, MEI_DRV_PRN_LEVEL_ERR,
                   ("MEI_DRV [%02d-%02d]: ERROR FW download BM-7 CS" MEI_DRV_CRLF,
                    MEI_DRV_LINENUM_GET(pMeiDev), pMeiDynCntrl->openInstance ));

            MEI_IF_STAT_INC_FWDL_ERR_COUNT(pMeiDev);
            MEI_DRV_STATE_SET(pMeiDev, e_MEI_DRV_STATE_BOOT_ROM_ALIVE);
         }
      }
      else
      {
         ret = e_MEI_ERR_INVAL_CONFIG;
      }
#else
      PRN_ERR_USR_NL( MEI_DRV, MEI_DRV_PRN_LEVEL_WRN,
             ("MEI_DRV[%02d]: ERROR - Start BOOTLOADER not supported" MEI_DRV_CRLF,
              MEI_DRV_LINENUM_GET(pMeiDev)));

      ret = e_MEI_ERR_INVAL_CONFIG;
#endif
   }
   else
   {
      PRN_ERR_USR_NL( MEI_DRV, MEI_DRV_PRN_LEVEL_ERR,
             ("MEI_DRV[%02d]: ERROR - FW Download - invalid boot mode" MEI_DRV_CRLF,
              MEI_DRV_LINENUM_GET(pMeiDev)));

      ret = e_MEI_ERR_INVAL_CONFIG;
   }


   if (ret != IFX_SUCCESS)
   {
      #if (MEI_SUPPORT_DL_DMA_CS == 1)
      /* Error: clear FW image within the driver device struct */
      pMeiDev->fwDl.pDfeImage = NULL;
      pMeiDev->fwDl.size_byte = 0;
      pMeiDev->fwDl.imageId = 0;
      #endif
   }
   else
   {
      if (MEI_DRV_STATE_GET(pMeiDev) == e_MEI_DRV_STATE_WAIT_FOR_FIRST_RESP)
      {
         MEI_SET_TIMEOUT_CNT( pMeiDev,
                  ((MEI_MaxWaitForModemReady_ms & ~MEI_CFG_DEF_WAIT_PROTECTION_FLAG) /
                    MEI_MIN_MAILBOX_POLL_TIME_MS));

         while(MEI_DRV_STATE_GET(pMeiDev) == e_MEI_DRV_STATE_WAIT_FOR_FIRST_RESP)
         {
            MEI_PollIntPerVnxLine(pMeiDev, e_MEI_DEV_ACCESS_MODE_PASSIV_POLL);

            /* check if modem read  */
            if ( MEI_DRV_STATE_GET(pMeiDev) == e_MEI_DRV_STATE_DFE_READY )
               break;
            else
            {
               if ( MEI_WaitForMailbox(pMeiDev) != IFX_SUCCESS )
                  break;
            }
         }
      }
   }

   /* check the current state */
   if ( MEI_DRV_STATE_GET(pMeiDev) != e_MEI_DRV_STATE_DFE_READY )
   {
      /* reset the driver state to "Init Done" */
      MEI_DRV_GET_UNIQUE_MAILBOX_ACCESS(pMeiDev);

      if ( MEI_DRV_STATE_GET(pMeiDev) != e_MEI_DRV_STATE_DFE_READY )
      {
         MEI_DRV_STATE_SET(pMeiDev, e_MEI_DRV_STATE_SW_INIT_DONE);
      }

      MEI_DRV_RELEASE_UNIQUE_MAILBOX_ACCESS(pMeiDev);

      return e_MEI_ERR_OP_FAILED;
   }

   return IFX_SUCCESS;
}

/**
   Check the memory location all pages against the VINAX internal memory map.

\param
   pFwImage    points to the initial FW image.

\return
   IFX_SUCCESS - MEM map if no violation was found
   IFX_ERROR   - MEM map violation was found

*/
static IFX_int32_t MEI_ValidateImage(
                        MEI_FW_IMAGE_T        *pFwImage)
{
   IFX_int32_t    memMapErr = 0, imgHdrErr = 0;
   IFX_int32_t    numOfPages, dirIndex;
   IFX_uint32_t   startAddr, endAddr, imageSize_Byte, binStartOffset_byte;
   IFX_boolean_t  bBootPage = IFX_FALSE;

   MEI_FW_IMAGE_CNTRL_T *pFwImageCntrl = (MEI_FW_IMAGE_CNTRL_T *)pFwImage->pImage;
   MEI_FW_IMAGE_PAGE_T  *pFwImageDir =
         (MEI_FW_IMAGE_PAGE_T *)(pFwImage->pImage + sizeof(MEI_FW_IMAGE_CNTRL_T));

   if (pFwImage->hostOrder)
   {
      /* image already swapped and validated - return */
      return IFX_SUCCESS;
   }

   numOfPages          = SWAP32_BYTE_ORDER(pFwImageCntrl->imageNumOfPages);
   imageSize_Byte      = SWAP32_BYTE_ORDER(pFwImageCntrl->imageSize_Bytes);
   binStartOffset_byte = numOfPages * sizeof(MEI_FW_IMAGE_PAGE_T) + sizeof(MEI_FW_IMAGE_CNTRL_T);

   for (dirIndex = 0; dirIndex < numOfPages; dirIndex++)
   {
      IFX_uint32_t pageSize_bytes, pageOff_bytes;

      /*
         Code Page
      */
      bBootPage      = ((SWAP32_BYTE_ORDER(pFwImageDir[dirIndex].codePageSize_32Bit)) & MEI_BOOT_FLAG) ? IFX_TRUE : IFX_FALSE;
      pageOff_bytes  =   SWAP32_BYTE_ORDER(pFwImageDir[dirIndex].codeOffset_Byte);
      pageSize_bytes = ((SWAP32_BYTE_ORDER(pFwImageDir[dirIndex].codePageSize_32Bit) & (~MEI_BOOT_FLAG)) * 4);
      startAddr      =   SWAP32_BYTE_ORDER(pFwImageDir[dirIndex].codeDestAddr);
      endAddr        = (pageSize_bytes) ? (startAddr + pageSize_bytes -1) : startAddr;

      if ( (pageOff_bytes < binStartOffset_byte) && pageSize_bytes)
      {
         PRN_ERR_USR_NL( MEI_DRV, MEI_DRV_PRN_LEVEL_ERR,
                ("MEI_DRV: ERROR - Invalid Image, C-Page[%d] Offset 0x%08X (size 0x%X) out of bin-range (start 0x%08X)" MEI_DRV_CRLF,
                  dirIndex, pageOff_bytes, pageSize_bytes, binStartOffset_byte ));
         imgHdrErr= 1;
      }

      if ( (pageOff_bytes + pageSize_bytes) > (imageSize_Byte + 8) )
      {
         PRN_ERR_USR_NL( MEI_DRV, MEI_DRV_PRN_LEVEL_ERR,
                ("MEI_DRV: ERROR - Invalid Image, C-Page[%d] Offset 0x%08X + Size 0x%X > Image Size 0x%X + 8" MEI_DRV_CRLF,
                  dirIndex, pageOff_bytes, pageSize_bytes, imageSize_Byte ));
         imgHdrErr= 1;
      }

      /*
         Check Code page against given ranges
      */
      if ( (MEI_ValidatPage(dirIndex, IFX_TRUE, bBootPage,
                              startAddr, endAddr,  MEI_memMapRev1x)) != IFX_SUCCESS )
      {
         memMapErr= 1;
      }

      /*
         Data Page
      */
      bBootPage      = ((SWAP32_BYTE_ORDER(pFwImageDir[dirIndex].dataPageSize_32Bit)) & MEI_BOOT_FLAG) ? IFX_TRUE : IFX_FALSE;
      pageOff_bytes  =   SWAP32_BYTE_ORDER(pFwImageDir[dirIndex].dataOffset_Byte);
      pageSize_bytes = ((SWAP32_BYTE_ORDER(pFwImageDir[dirIndex].dataPageSize_32Bit) & (~MEI_BOOT_FLAG)) * 4);
      startAddr      =   SWAP32_BYTE_ORDER(pFwImageDir[dirIndex].dataDestAddr);
      endAddr        = (pageSize_bytes) ? (startAddr + pageSize_bytes -1) : startAddr;

      if ( (pageOff_bytes < binStartOffset_byte) && pageSize_bytes)
      {
         PRN_ERR_USR_NL( MEI_DRV, MEI_DRV_PRN_LEVEL_ERR,
                ("MEI_DRV: ERROR - Invalid Image, D-Page[%d] Offset 0x%08X (size 0x%X) out of bin-range (start 0x%08X)" MEI_DRV_CRLF,
                  dirIndex, pageOff_bytes, pageSize_bytes, binStartOffset_byte ));
         imgHdrErr = 1;
      }

      if ( (pageOff_bytes + pageSize_bytes) > (imageSize_Byte + 8) )
      {
         PRN_ERR_USR_NL( MEI_DRV, MEI_DRV_PRN_LEVEL_ERR,
                ("MEI_DRV: ERROR - Invalid Image, D-Page[%d] Offset 0x%08X + Size 0x%X > Image Size 0x%X + 8" MEI_DRV_CRLF,
                  dirIndex, pageOff_bytes, pageSize_bytes, imageSize_Byte ));
         imgHdrErr = 1;
      }

      /*
         Check Data page against given ranges
      */
      if ( (MEI_ValidatPage(dirIndex, IFX_FALSE, bBootPage,
                              startAddr, endAddr,  MEI_memMapRev1x)) != IFX_SUCCESS )
      {
         memMapErr = 1;
      }
   }

   if ( imgHdrErr || memMapErr )
   {
      return IFX_ERROR;
   }
   else
   {
      return IFX_SUCCESS;
   }
}

IFX_void_t MEI_DEV_FirmwareDownloadResourcesRelease(
                                 MEI_DEV_T       *pMeiDev)
{
   IFX_uint32_t imageId;
   MEI_DRVOS_SemaphoreLock(&pFwDlCntrlLock);

   for (imageId=0; imageId<MEI_MAX_FW_IMAGES; imageId++)
   {
      /* check if the image is already in use */
      if (ChipFwImage[imageId].pImage)
      {
         /* image exists but not in use, free it
            --> replace it, if the new one also exists */
         MEI_DRVOS_VirtFree( (IFX_void_t*)ChipFwImage[imageId].pImage);
         ChipFwImage[imageId].pImage = NULL;
         ChipFwImage[imageId].size_byte = 0;
         ChipFwImage[imageId].hostOrder = IFX_FALSE;
      }
   }

   MEI_DRVOS_SemaphoreUnlock(&pFwDlCntrlLock);

   /* mutex exist */
   MEI_DRVOS_SemaphoreDelete(&pFwDlCntrlLock);
}

/* ============================================================================
   Function definition (FW Download ioctl)
   ========================================================================= */

/**
   Do the firmware download for the current VINAX.

\param
   pMeiDynCntrl - private dynamic comtrol data (per open instance)
\param
   pFwDl          - points to the FW downlosd information data
\param
   bInternCall    - indicates if the call is form the internal interface
                    (image and data already in kernel space)
\return
   IFX_SUCCESS: if the FW was successful.
   negative value if something went wrong.

*/
IFX_int32_t MEI_DEV_IoctlFirmwareDownload(
                                 MEI_DYN_CNTRL_T        *pMeiDynCntrl,
                                 IOCTL_MEI_fwDownLoad_t *pArgFwDl,
                                 IFX_boolean_t           bInternCall)
{
   int ret, imageId = 0;
   MEI_DEV_T    *pMeiDev = pMeiDynCntrl->pMeiDev;

   /* Check for the Vinax valid boot mode*/
   if (MEI_DRV_BOOTMODE_GET(pMeiDev) == e_MEI_DRV_BOOT_MODE_7)
   {
      /* check multiple FW images */
      imageId = (MEI_GET_ENTITY_FROM_DEVNUM(MEI_DRV_LINENUM_GET(pMeiDev))) % MEI_MAX_FW_IMAGES;
   }
   else
   {
      PRN_ERR_USR_NL( MEI_DRV, MEI_DRV_PRN_LEVEL_ERR,
             ("MEI_DRV[%02d]: ERROR - FW Download - "
              "BOOTMODE 0x%X does not allow FW download" MEI_DRV_CRLF,
              MEI_DRV_LINENUM_GET(pMeiDev), pMeiDev->modemData.devBootMode));
      return -e_MEI_ERR_INVAL_CONFIG;
   }

   /*
      Check current driver state.
      - INIT_DONE: start the device and wait for the first responce.
      - DL ROM Handler Alive: device already available.
   */
   switch (MEI_DRV_STATE_GET(pMeiDev))
   {
      case e_MEI_DRV_STATE_SW_INIT_DONE:
         /* Start the VINAX device with the corresponding boot mode */
         if ( (ret = MEI_StartupDevice(pMeiDev)) != 0)
         {
            PRN_ERR_USR_NL( MEI_DRV, MEI_DRV_PRN_LEVEL_ERR,
                   ("MEI_DRV[%02d]: ERROR - FW Download - Start device" MEI_DRV_CRLF,
                   MEI_DRV_LINENUM_GET(pMeiDev)));

            return -e_MEI_ERR_DEV_NO_RESP;
         }
         break;
      case e_MEI_DRV_STATE_BOOT_ROM_ALIVE:
         /* device already started (exp: by a previous GPA access */
         break;
      default:
         PRN_ERR_USR_NL( MEI_DRV, MEI_DRV_PRN_LEVEL_ERR,
               ("MEI_DRV[%02d]: invalid state (%d) for load FW image." MEI_DRV_CRLF,
                 MEI_DRV_LINENUM_GET(pMeiDev), MEI_DRV_STATE_GET(pMeiDev) ));

         return -e_MEI_ERR_INVAL_STATE;
   }

   PRN_DBG_USR( MEI_DRV, MEI_DRV_PRN_LEVEL_NORMAL, MEI_DRV_LINENUM_GET(pMeiDev),
         ("MEI_DRV[%02d]: start FW download -  entity %d, FW imageId %d." MEI_DRV_CRLF,
           MEI_DRV_LINENUM_GET(pMeiDev), MEI_GET_ENTITY_FROM_DEVNUM(MEI_DRV_LINENUM_GET(pMeiDev)), imageId));


   MEI_DRVOS_SemaphoreLock(&pFwDlCntrlLock);

   /* check if the image is already in use */
   if (ChipFwImage[imageId].pImage)
   {
      if ( (ChipFwImage[imageId].useCount == 0) && (pArgFwDl->pFwImage) )
      {
         /* image exists but not in use, free it
            --> replace it, if the new one also exists */
         MEI_DRVOS_VirtFree( (IFX_void_t*)ChipFwImage[imageId].pImage);
         ChipFwImage[imageId].pImage = NULL;
         ChipFwImage[imageId].size_byte = 0;
         ChipFwImage[imageId].hostOrder = IFX_FALSE;
      }
   }

   /* check if image already loaded */
   if (ChipFwImage[imageId].pImage == NULL)
   {
      /* copy image to the internal buffer */
      if (pArgFwDl->pFwImage)
      {
         ChipFwImage[imageId].pImage = MEI_DRVOS_VirtMalloc(pArgFwDl->size_byte);

         if (!ChipFwImage[imageId].pImage)
         {
            PRN_ERR_USR_NL( MEI_DRV, MEI_DRV_PRN_LEVEL_ERR,
                  ("MEI_DRV: no memory for load FW image - size %d." MEI_DRV_CRLF,
                    (unsigned int)pArgFwDl->size_byte));
            ret = -e_MEI_ERR_NO_MEM;
            goto ERROR_MEI_IOCTL_FWDL_LOAD_IMAGE;
         }

         if (bInternCall)
         {
            memcpy ( ChipFwImage[imageId].pImage,
                     pArgFwDl->pFwImage, pArgFwDl->size_byte);
         }
         else
         {
            /* copy data to kernel space */
            if ( (MEI_DRVOS_CpyFromUser( ChipFwImage[imageId].pImage,
                                         pArgFwDl->pFwImage,
                                         pArgFwDl->size_byte)) == IFX_NULL)
            {
               PRN_ERR_USR_NL( MEI_DRV, MEI_DRV_PRN_LEVEL_ERR,
                     ("MEI_DRV[0x%02X]: download - copy_from_user(image) failed!" MEI_DRV_CRLF,
                      MEI_DRV_LINENUM_GET(pMeiDev)));

               /* free the mem again */
               MEI_DRVOS_VirtFree((IFX_void_t*)ChipFwImage[imageId].pImage);
               ChipFwImage[imageId].pImage = NULL;
               ret = -e_MEI_ERR_GET_ARG;
               goto ERROR_MEI_IOCTL_FWDL_LOAD_IMAGE;
            }
         }
         ChipFwImage[imageId].size_byte = pArgFwDl->size_byte;
         ChipFwImage[imageId].hostOrder = IFX_FALSE;
         ChipFwImage[imageId].useCount  = 0;
         ChipFwImage[imageId].forceDl   = IFX_TRUE;
      }
      else
      {
         PRN_ERR_USR_NL( MEI_DRV, MEI_DRV_PRN_LEVEL_ERR,
               ("MEI_DRV[%02d]: missing FW image for download." MEI_DRV_CRLF,
                 MEI_DRV_LINENUM_GET(pMeiDev) ));

         ret = -e_MEI_ERR_INVAL_ARG;
         goto ERROR_MEI_IOCTL_FWDL_LOAD_IMAGE;
      }
   }
   else
   {
      PRN_DBG_USR( MEI_DRV, MEI_DRV_PRN_LEVEL_HIGH, MEI_DRV_LINENUM_GET(pMeiDev),
            ("MEI_DRV[0x%02X]: WARNING - FW image already loaded - use current one." MEI_DRV_CRLF,
             MEI_DRV_LINENUM_GET(pMeiDev)));
   }

   /* FW image used for this download */
   ChipFwImage[imageId].useCount++;

   MEI_DRVOS_SemaphoreUnlock(&pFwDlCntrlLock);

   /* now start the FW download */
   ret = MEI_StartFwDownload( pMeiDynCntrl, imageId);
   if (ret != IFX_SUCCESS)
   {
      PRN_ERR_USR_NL( MEI_DRV, MEI_DRV_PRN_LEVEL_ERR,
            ("MEI_DRV[0x%02X]: download - handler failed, FW image[%d]!" MEI_DRV_CRLF,
             MEI_DRV_LINENUM_GET(pMeiDev), imageId));
   }



   if (ret != IFX_SUCCESS)
   {
      MEI_DRVOS_SemaphoreLock(&pFwDlCntrlLock);
      ChipFwImage[imageId].useCount--;
      MEI_DRVOS_SemaphoreUnlock(&pFwDlCntrlLock);
   }

   return ret;

ERROR_MEI_IOCTL_FWDL_LOAD_IMAGE:

   MEI_DRVOS_SemaphoreUnlock(&pFwDlCntrlLock);

   PRN_ERR_USR_NL( MEI_DRV, MEI_DRV_PRN_LEVEL_ERR,
          ("MEI_DRV[0x%02X]: ERROR get FW image[%d], in use by %d user!" MEI_DRV_CRLF,
            MEI_DRV_LINENUM_GET(pMeiDev), imageId, ChipFwImage[imageId].useCount));

   return ret;
}

#endif   /* #if ((MEI_SUPPORT_ROM_CODE == 1) && (MEI_SUPPORT_DL_DMA_CS == 1)) */

#endif   /* #if (MEI_SUPPORT_DEVICE_VINAX == 1)*/

