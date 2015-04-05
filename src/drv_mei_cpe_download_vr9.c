/******************************************************************************

                               Copyright (c) 2011
                            Lantiq Deutschland GmbH
                     Am Campeon 3; 85579 Neubiberg, Germany

  For licensing information, see the file 'LICENSE' in the root folder of
  this software module.

******************************************************************************/

/* ==========================================================================
   Description : VR9/AR9 Firmware Download function .
   ========================================================================== */


/* ============================================================================
   Inlcudes
   ========================================================================= */

/* get at first the driver configuration */
#include "drv_mei_cpe_config.h"

#if (MEI_SUPPORT_DEVICE_VR9 == 1) || (MEI_SUPPORT_DEVICE_AR9 == 1)

#include "ifx_types.h"
#include "drv_mei_cpe_os.h"
#include "drv_mei_cpe_dbg.h"

#include "drv_mei_cpe_dbg_driver.h"

#include "drv_mei_cpe_interface.h"
#include "drv_mei_cpe_mei_interface.h"
#include "drv_mei_cpe_api.h"
#include "drv_mei_cpe_mei_access.h"

/* CMV messages */
#include "cmv_message_format.h"

#include "drv_mei_cpe_download.h"
#include "drv_mei_cpe_msg_process.h"

#if (MEI_SUPPORT_DRV_MODEM_TESTS == 1)
#include "drv_mei_cpe_modem_test.h"
#endif

#if (MEI_EXPORT_INTERNAL_API == 1) && (MEI_DRV_ATM_PTM_INTERFACE_ENABLE == 1)
extern void *g_xdata_addr[];
#endif

static IFX_int32_t MEI_VR9_ImageChunkFree(
                                 MEI_FW_DOWNLOAD_CNTRL_T *pFwDlCtrl,
                                 IFX_uint32_t chunkIdx);

/* ==========================================================================
   Global Variable Definitions
   ========================================================================== */

/* ==========================================================================
   Local variables
   ========================================================================== */


/* ==========================================================================
   Local function definitions
   ========================================================================== */
static IFX_void_t MEI_VR9_ChunksInfoShow(MEI_DEV_T *pMeiDev)
{
   IFX_uint32_t i;
   MEI_FW_IMAGE_CHUNK_CTRL_T *pChunk = pMeiDev->fwDl.imageChunkCtrl;

   PRN_DBG_USR_NL( MEI_DRV, MEI_DRV_PRN_LEVEL_NORMAL,
         (MEI_DRV_CRLF "================= FW IMAGE CHUNKS=================" MEI_DRV_CRLF));

   for (i=0; i<MEI_FW_IMAGE_MAX_CHUNK_COUNT; i++)
   {
      if (pChunk[i].eImageChunkType == eMEI_FW_IMAGE_CHUNK_UNDEFINED)
         continue;

      PRN_DBG_USR_NL( MEI_DRV, MEI_DRV_PRN_LEVEL_NORMAL,
            ("chunk[%02d]: addr = 0x%08X (0x%08X), size = %5d [byte], type = %d" MEI_DRV_CRLF,
            i, pChunk[i].pImageChunk_aligned, pChunk[i].pImageChunk_allocated,
            pChunk[i].imageChunkSize_byte, pChunk[i].eImageChunkType));

   }

   PRN_DBG_USR_NL( MEI_DRV, MEI_DRV_PRN_LEVEL_NORMAL,
         (MEI_DRV_CRLF "==================================================" MEI_DRV_CRLF));
}

static IFX_int32_t MEI_VR9_ArcFromHaltRelease(MEI_DEV_T *pMeiDev)
{
   IFX_uint32_t arc_status = 0;

   PRN_ERR_USR_NL( MEI_DRV, MEI_DRV_PRN_LEVEL_LOW,
      ("MEI_DRV: Starting to release ARC from the HALT state"MEI_DRV_CRLF));

   /* Get ARC_STATUS register*/
   if (MEI_ReadDbg(&(pMeiDev->meiDrvCntrl), MEI_REG_ARC_STATUS,
         ME_DBG_DECODE_DEBUG_DEC_AUX, 1, &arc_status) != 1)
   {
      PRN_ERR_USR_NL( MEI_DRV, MEI_DRV_PRN_LEVEL_ERR,
         ("MEI_DRV: ARC_STATUS read failed!" MEI_DRV_CRLF));
      return (IFX_int32_t)IFX_ERROR;
   }

   /* Clear 25th (HALT) bit*/
   arc_status &= ~(1 << 25);

   if (MEI_WriteDbg(&(pMeiDev->meiDrvCntrl), MEI_REG_ARC_STATUS,
         ME_DBG_DECODE_DEBUG_DEC_AUX, 1, &arc_status) != 1)
   {
      PRN_ERR_USR_NL( MEI_DRV, MEI_DRV_PRN_LEVEL_ERR,
         ("MEI_DRV: ARC_STATUS write failed!" MEI_DRV_CRLF));
      return (IFX_int32_t)IFX_ERROR;
   }

   PRN_ERR_USR_NL( MEI_DRV, MEI_DRV_PRN_LEVEL_LOW,
      ("MEI_DRV: ARC released from the HALT state"MEI_DRV_CRLF));

   return (IFX_int32_t)IFX_SUCCESS;
}

#if (MEI_SUPPORT_PCI_SLAVE_FW_DOWNLOAD == 1)
MEI_PCI_SLAVE_POOL_T* MEI_VR9_PciSlavePoolCreate(
                                 IFX_uint8_t *pPciStart,
                                 IFX_uint8_t *pDdrStart,
                                 IFX_uint32_t pool_size_byte)
{
   MEI_PCI_SLAVE_POOL_T *pPool;

   if (!pPciStart || !pDdrStart || !pool_size_byte)
   {
      return IFX_NULL;
   }

   if (((IFX_uint32_t)pDdrStart) & (~MEI_FW_IMAGE_CHUNK_ADDR_MASK))
   {
      PRN_ERR_USR_NL( MEI_DRV, MEI_DRV_PRN_LEVEL_ERR,
         ("MEI_DRV: PCI slave DDR pool address not aligned!" MEI_DRV_CRLF));

      return IFX_NULL;
   }

   /* Allocate pool memory*/
   pPool = (MEI_PCI_SLAVE_POOL_T*)MEI_DRVOS_Malloc(sizeof(MEI_PCI_SLAVE_POOL_T));

   if (!pPool)
   {
      PRN_ERR_USR_NL( MEI_DRV, MEI_DRV_PRN_LEVEL_ERR,
         ("MEI_DRV: no memory for PCI slave pool size!" MEI_DRV_CRLF));

      return IFX_NULL;
   }

   /* Initialize pool*/
   memset(pPool, 0x0, sizeof(MEI_PCI_SLAVE_POOL_T));

   pPool->pPciStart      = pPciStart;
   pPool->pDdrStart      = pDdrStart;
   pPool->pool_size_byte = pool_size_byte;

   return pPool;
}

IFX_void_t MEI_VR9_PciSlavePoolDelete(
                                 MEI_PCI_SLAVE_POOL_T *pPool)
{
   MEI_PCI_SLAVE_POOL_ELEMENT_T *pElement, *pNextElement = IFX_NULL;

   if (!pPool)
      return;

   pElement = pPool->Head.pNext;

   while(pElement)
   {
      pNextElement = pElement;

      MEI_DRVOS_Free(pElement);
      
      pElement = pNextElement;
   }

   MEI_DRVOS_Free(pPool);

   return;
}

static IFX_uint8_t* MEI_VR9_PciSlavePoolElementAlloc(
                                 MEI_PCI_SLAVE_POOL_T *pPool,
                                 IFX_uint32_t size)
{
   IFX_uint8_t *pAlloc = IFX_NULL;
   MEI_PCI_SLAVE_POOL_ELEMENT_T *pElement = &(pPool->Head),
                                *pElementPrev = &(pPool->Head);
   
   if (size > pPool->pool_size_byte)
   {
      return IFX_NULL;
   }

   while(1)
   {
      if (pElement == IFX_NULL)
      { /* Create new pool element*/
         pElement =
            (MEI_PCI_SLAVE_POOL_ELEMENT_T*)MEI_DRVOS_Malloc(sizeof(MEI_PCI_SLAVE_POOL_ELEMENT_T));
         
         if (!pElement)
         {
            PRN_ERR_USR_NL( MEI_DRV, MEI_DRV_PRN_LEVEL_ERR,
               ("MEI_DRV: no memory for PCI slave pool element!" MEI_DRV_CRLF));
            return IFX_NULL;
         }

         memset(pElement, 0x0, sizeof(MEI_PCI_SLAVE_POOL_ELEMENT_T));
         pElementPrev->pNext = pElement;
      }

      if (!pElement->bUsed)
      { /* Current element is not used*/
         if (pElement->element_size_byte == 0)
         { /* New Element*/
            if (size <= pPool->pool_size_byte - pPool->fill_offset)
            { /* we have some free space, add element to the pool's end*/
                /* Mark new element as Used*/
               pElement->bUsed = IFX_TRUE;
               /* Set allocated pointer*/
               pAlloc = pPool->pDdrStart + pPool->fill_offset;
               /* Update element offset*/
               pElement->element_offset = pPool->fill_offset;
               /* Update pool offset*/
               pPool->fill_offset += size;
               /* Set current element size*/
               pElement->element_size_byte = size;

               return pAlloc;
            }
         }
         else if (size <= pElement->element_size_byte)
         { /* Requested size fits to the available element size*/
            /* Mark existing element as Used*/
            pElement->bUsed = IFX_TRUE;

            pAlloc = pPool->pDdrStart + pElement->element_offset;
            return pAlloc;
         }
      }

      if (size > pPool->pool_size_byte - pElement->element_offset)
      { /* No memory left in the pool, we reached the last pool element*/
         return IFX_NULL;
      }

      /* Switch to the next element*/     
      pElementPrev = pElement;
      pElement     = pElement->pNext;
   }
}

static IFX_void_t MEI_VR9_PciSlavePoolElementFree(
                                 MEI_PCI_SLAVE_POOL_T *pPool,
                                 IFX_uint8_t *addr)
{
   MEI_PCI_SLAVE_POOL_ELEMENT_T *pElement = &(pPool->Head);

   while (pElement)
   {
      if (addr == (pPool->pDdrStart + pElement->element_offset))
      {
         if (!pElement->bUsed)
         {
            PRN_ERR_USR_NL( MEI_DRV, MEI_DRV_PRN_LEVEL_ERR,
               ("MEI_DRV: attempt to free not used PCI pool element!" MEI_DRV_CRLF));
         }

         pElement->bUsed = IFX_FALSE;

         break;
      }

      pElement = pElement->pNext;
   }

   return;
}

static IFX_uint8_t* MEI_VR9_PciSlavePciAddrGet(
                                 MEI_PCI_SLAVE_POOL_T *pPool,
                                 IFX_uint8_t *ddr_addr)
{
   IFX_uint8_t *pci_addr;

   pci_addr = pPool->pPciStart + (ddr_addr - pPool->pDdrStart);

   return pci_addr >= pPool->pPciStart ? pci_addr : pPool->pPciStart;
}
#endif /* #if (MEI_SUPPORT_PCI_SLAVE_FW_DOWNLOAD == 1)*/

static IFX_int32_t MEI_VR9_ImageChunkAlloc(
                                 MEI_FW_DOWNLOAD_CNTRL_T *pFwDlCtrl,
                                 IFX_uint32_t chunkIdx,
                                 IFX_uint32_t chunkSize_byte)
{
   IFX_int32_t ret = 0;
   IFX_uint8_t *pImageChunk_allocated = NULL;
   MEI_FW_IMAGE_CHUNK_CTRL_T *pImageChunkCtrl = pFwDlCtrl->imageChunkCtrl;

   if ( ((chunkSize_byte > MEI_FW_IMAGE_CHUNK_SIZE_BYTE) &&
         (chunkIdx != MEI_FW_IMAGE_MAX_CHUNK_COUNT - 1)) ||
         (chunkIdx > MEI_FW_IMAGE_MAX_CHUNK_COUNT - 1) )
   {
      PRN_ERR_USR_NL( MEI_DRV, MEI_DRV_PRN_LEVEL_ERR,
         ("MEI_DRV: chunk[%d] size %d incorrect!" MEI_DRV_CRLF,
         chunkIdx, chunkSize_byte));
      return IFX_ERROR;
   }

   /* Check for the last chunk*/
   if (chunkIdx == MEI_FW_IMAGE_MAX_CHUNK_COUNT - 1)
   {
      /* Release last chunk since it's size could vary. Will be allocated
         with a new size below. */
      MEI_VR9_ImageChunkFree(pFwDlCtrl, chunkIdx);
   }

   /* Check if for a released chunk*/
   if (!(pImageChunkCtrl[chunkIdx].pImageChunk_allocated))
   {
#if (MEI_SUPPORT_PCI_SLAVE_FW_DOWNLOAD == 1)
      if (pFwDlCtrl->bPciSlave)
      {
         pImageChunk_allocated = MEI_VR9_PciSlavePoolElementAlloc(
                                    pFwDlCtrl->pPool, chunkSize_byte);
      }
      else
#endif /* #if (MEI_SUPPORT_PCI_SLAVE_FW_DOWNLOAD == 1)*/
      {
         /* Allocate chunk memory with the specified chunk size*/
         pImageChunk_allocated = MEI_DRVOS_Malloc(chunkSize_byte);
      }

      if (!pImageChunk_allocated)
      {
         PRN_ERR_USR_NL( MEI_DRV, MEI_DRV_PRN_LEVEL_ERR,
            ("MEI_DRV: no memory for chunk[%d] size %d." MEI_DRV_CRLF,
            chunkIdx, chunkSize_byte));

         ret = -e_MEI_ERR_NO_MEM;
         return ret;
      }

      /* Check if the allocated chunk is not aligned*/
      if ( (((IFX_uint32_t)pImageChunk_allocated) & (~MEI_FW_IMAGE_CHUNK_ADDR_MASK)) 
#if (MEI_SUPPORT_PCI_SLAVE_FW_DOWNLOAD == 1)
           && !(pFwDlCtrl->bPciSlave)
#endif /* #if (MEI_SUPPORT_PCI_SLAVE_FW_DOWNLOAD == 1)*/
         )
      {
         /* Free current allocated chunk which is not aligned*/
         MEI_DRVOS_Free(pImageChunk_allocated);

         /* Allocate chunk memory for further alignment*/
         pImageChunk_allocated = MEI_DRVOS_Malloc(
                              MEI_FW_IMAGE_CHUNK_ALIGNED_SIZE_BYTE(chunkSize_byte) );

         if (!pImageChunk_allocated)
         {
            PRN_ERR_USR_NL( MEI_DRV, MEI_DRV_PRN_LEVEL_ERR,
               ("MEI_DRV: no memory for aligned chunk[%d] size %d." MEI_DRV_CRLF,
               chunkIdx, MEI_FW_IMAGE_CHUNK_ALIGNED_SIZE_BYTE(chunkSize_byte)));

            ret = -e_MEI_ERR_NO_MEM;
            return ret;
         }

         /* Assign chunk aligned address*/
         pImageChunkCtrl[chunkIdx].pImageChunk_aligned =
            MEI_FW_IMAGE_CHUNK_ALIGNED_ADDR_GET(pImageChunk_allocated);
      }
      else
      {
         /* Assign chunk allocated address*/
         pImageChunkCtrl[chunkIdx].pImageChunk_aligned = pImageChunk_allocated;
      }

#if (MEI_SUPPORT_PCI_SLAVE_FW_DOWNLOAD == 1)
      if (pFwDlCtrl->bPciSlave)
      {
         pImageChunkCtrl[chunkIdx].pBARx = MEI_VR9_PciSlavePciAddrGet(
                                             pFwDlCtrl->pPool,
                                             pImageChunkCtrl[chunkIdx].pImageChunk_aligned);
      }
      else
#endif /* #if (MEI_SUPPORT_PCI_SLAVE_FW_DOWNLOAD == 1)*/
      {
         pImageChunkCtrl[chunkIdx].pBARx = pImageChunkCtrl[chunkIdx].pImageChunk_aligned;
      }

      /* Assign chunk allocated address*/
      pImageChunkCtrl[chunkIdx].pImageChunk_allocated = pImageChunk_allocated;
      /* Assign chunk size*/
      pImageChunkCtrl[chunkIdx].imageChunkSize_byte = chunkSize_byte;
   }

   /* Assign chunk type*/
   if (chunkIdx == MEI_FW_IMAGE_DATA_CHUNK_INDEX)
   {
#if (MEI_EXPORT_INTERNAL_API == 1) && (MEI_DRV_ATM_PTM_INTERFACE_ENABLE == 1)
      /* Place this assignment here only as a workaround to profide
         DATA address to the ATM/PTM drivers*/
      g_xdata_addr[pFwDlCtrl->line_num] = (void*)pImageChunkCtrl[chunkIdx].pImageChunk_allocated;
#endif
      pImageChunkCtrl[chunkIdx].eImageChunkType = eMEI_FW_IMAGE_CHUNK_DATA;
   }
   else
   {
      pImageChunkCtrl[chunkIdx].eImageChunkType =
         (chunkIdx*chunkSize_byte < pFwDlCtrl->cachedRegionSize_byte) ?
            eMEI_FW_IMAGE_CHUNK_CACHED : eMEI_FW_IMAGE_CHUNK_REALLOC;
   }

   return ret;
}

static IFX_int32_t MEI_VR9_ImageChunkFree(
                                 MEI_FW_DOWNLOAD_CNTRL_T *pFwDlCtrl,
                                 IFX_uint32_t chunkIdx)
{
   MEI_FW_IMAGE_CHUNK_CTRL_T *pImageChunkCtrl = pFwDlCtrl->imageChunkCtrl;

   if (chunkIdx > MEI_FW_IMAGE_MAX_CHUNK_COUNT - 1)
   {
      PRN_ERR_USR_NL( MEI_DRV, MEI_DRV_PRN_LEVEL_ERR,
         ("MEI_DRV: chunk index %d incorrect!" MEI_DRV_CRLF, chunkIdx));
      return IFX_ERROR;
   }

   if (pImageChunkCtrl[chunkIdx].pImageChunk_allocated)
   {
#if (MEI_SUPPORT_PCI_SLAVE_FW_DOWNLOAD == 1)
      if (pFwDlCtrl->bPciSlave)
      {
         MEI_VR9_PciSlavePoolElementFree(
            pFwDlCtrl->pPool,
            pImageChunkCtrl[chunkIdx].pImageChunk_allocated);
      }
      else
#endif /* #if (MEI_SUPPORT_PCI_SLAVE_FW_DOWNLOAD == 1)*/
      {
         MEI_DRVOS_Free(pImageChunkCtrl[chunkIdx].pImageChunk_allocated);
      }
      pImageChunkCtrl[chunkIdx].pImageChunk_allocated = NULL;
      pImageChunkCtrl[chunkIdx].pImageChunk_aligned   = NULL;
      pImageChunkCtrl[chunkIdx].imageChunkSize_byte   = 0;
      pImageChunkCtrl[chunkIdx].eImageChunkType =
         eMEI_FW_IMAGE_CHUNK_UNDEFINED;
   }

#if (MEI_EXPORT_INTERNAL_API == 1) && (MEI_DRV_ATM_PTM_INTERFACE_ENABLE == 1)
   /* Place this assignment here only as a workaround to profide
      DATA address to the ATM/PTM drivers*/
   if (chunkIdx == MEI_FW_IMAGE_DATA_CHUNK_INDEX)
   {
      g_xdata_addr[pFwDlCtrl->line_num] = IFX_NULL;
   }
#endif

   return IFX_SUCCESS;
}

/**
   Fill temporary Xpage with the code/data words.

\param
   pMeiDrvCntrl:   points to the MEI interface register set
\param
   pChunkCtrl  points to chunk control structure.
\param
   pXpageInfo  points to current X page info header.

\return
   IFX_SUCCESS
   IFX_ERROR
*/
static IFX_int32_t MEI_VR9_XpageWrite(
                                 MEI_MEI_DRV_CNTRL_T *pMeiDrvCntrl,
                                 MEI_FW_IMAGE_CHUNK_CTRL_T *pChunkCtrl,
                                 MEI_FW_IMAGE_PAGE_T *pXpageInfo,
                                 IFX_boolean_t bData)
{
   IFX_int32_t ret = 0;
   IFX_uint32_t chunkIdx, page_offset_bytes, wordCount, *pChunkPageData = NULL;
   IFX_uint32_t destAddr, pageSize_32Bit, cnt, pageWord = 0;

   /* Get code/data Page destination address*/
   destAddr = bData ? pXpageInfo->dataDestAddr :
                              pXpageInfo->codeDestAddr;
   /* Get code/data Page size [32bit]*/
   pageSize_32Bit = (bData ? pXpageInfo->dataPageSize_32Bit :
                                    pXpageInfo->codePageSize_32Bit) & (~MEI_BOOT_FLAG);
   /* Get code/data Page offset within image [bytes]*/
   page_offset_bytes = bData ? pXpageInfo->dataOffset_Byte :
                               pXpageInfo->codeOffset_Byte;

   /* Check if page offset is within the last large chunk*/
   if (page_offset_bytes >= (MEI_FW_IMAGE_MAX_CHUNK_COUNT-2)*MEI_FW_IMAGE_CHUNK_SIZE_BYTE)
   {
      chunkIdx = MEI_FW_IMAGE_MAX_CHUNK_COUNT - 1;
   }
   else
   {
      /* Get chunk index*/
      chunkIdx = page_offset_bytes / MEI_FW_IMAGE_CHUNK_SIZE_BYTE;
   }

   if (chunkIdx > (MEI_FW_IMAGE_MAX_CHUNK_COUNT - 1))
   {
      PRN_ERR_USR_NL( MEI_DRV, MEI_DRV_PRN_LEVEL_ERR,
         ("MEI_DRV: Out of boundaries chunk[%d] detected while preparing Xpage"
         " with offset %d bytes!"
         MEI_DRV_CRLF, chunkIdx, page_offset_bytes));

      return IFX_ERROR;
   }

   /* Skip DATA chunk*/
   chunkIdx = chunkIdx == MEI_FW_IMAGE_DATA_CHUNK_INDEX ? chunkIdx + 1 : chunkIdx;

   /* Check for a valid chunk*/
   if (pChunkCtrl[chunkIdx].eImageChunkType == eMEI_FW_IMAGE_CHUNK_UNDEFINED)
   {
      PRN_ERR_USR_NL( MEI_DRV, MEI_DRV_PRN_LEVEL_ERR,
         ("MEI_DRV: Undefined chunk[%d] detected while trying to fill Xpage!"
         MEI_DRV_CRLF, chunkIdx));

      return IFX_ERROR;
   }

   /* Get relative page offset*/
   page_offset_bytes = page_offset_bytes % pChunkCtrl[chunkIdx].imageChunkSize_byte;

   pChunkPageData = (IFX_uint32_t*)(pChunkCtrl[chunkIdx].pImageChunk_aligned + page_offset_bytes);

   /* Fill Xpage*/
   for (wordCount=0; wordCount<pageSize_32Bit; wordCount++)
   {
      if (wordCount*4 + page_offset_bytes >= pChunkCtrl[chunkIdx].imageChunkSize_byte)
      {
         /* Move to the next chunk, skip DATA chunk if necessary*/
         chunkIdx += (chunkIdx == MEI_FW_IMAGE_DATA_CHUNK_INDEX ? 2 : 1);

         if (chunkIdx > (MEI_FW_IMAGE_MAX_CHUNK_COUNT - 1))
         {
            PRN_ERR_USR_NL( MEI_DRV, MEI_DRV_PRN_LEVEL_ERR,
               ("MEI_DRV: Undefined chunk[%d] detected while trying to fill Xpage!"
               MEI_DRV_CRLF, chunkIdx));

            ret = IFX_ERROR;
            break;
         }

         /* Check for a valid chunk*/
         if (pChunkCtrl[chunkIdx].eImageChunkType == eMEI_FW_IMAGE_CHUNK_UNDEFINED)
         {
            PRN_ERR_USR_NL( MEI_DRV, MEI_DRV_PRN_LEVEL_ERR,
               ("MEI_DRV: Undefined chunk[%d] detected while trying to fill Xpage!"
               MEI_DRV_CRLF, chunkIdx));

            ret = IFX_ERROR;
            break;
         }

         /* Reset relative offset*/
         page_offset_bytes = 0;
         /* ...and now data starts directly from the 1st chunk address*/
         pChunkPageData = (IFX_uint32_t*)(pChunkCtrl[chunkIdx].pImageChunk_aligned);
      }

      /* Copy Page data from chunks*/
      pageWord = *pChunkPageData++;

      /* Write one 32-bit word*/
      cnt = MEI_WriteDma32Bit(
               pMeiDrvCntrl, destAddr, &pageWord, 1, 0);

      if (cnt != 1)
      {
         ret = IFX_ERROR;
         break;
      }

      destAddr += 4;
   }

   return ret;
}

/**
   Get firmware Port Mode Control Structure.

\param
   pMeiDrvCntrl:   points to the MEI interface register set
\param
   pXpage:         points to the Port Mode Control Structure.

\return
   IFX_SUCCESS
   IFX_ERROR
*/
static IFX_int32_t MEI_VR9_PortModeControlStructureCurrentGet(
                                 MEI_DEV_T *pMeiDev,
                                 MEI_FW_PORT_MODE_CONTROL_DMA32_T *pPortModeCtrl)
{
   IFX_int32_t ret = 0;
   IFX_uint32_t cnt = 0;

   /* Protect device DMA access */
   MEI_DRV_GET_UNIQUE_ACCESS(pMeiDev);

   cnt = MEI_ReadDma32Bit(
            &(pMeiDev->meiDrvCntrl),
            MEI_FW_PORT_MODE_CONTROL_STRUCTURE_ADDR,
            (IFX_uint32_t*)pPortModeCtrl,
            sizeof(MEI_FW_PORT_MODE_CONTROL_DMA32_T)/sizeof(IFX_uint32_t));

   MEI_DRV_RELEASE_UNIQUE_ACCESS(pMeiDev);

   if (cnt != sizeof(MEI_FW_PORT_MODE_CONTROL_DMA32_T)/sizeof(IFX_uint32_t))
      ret = IFX_ERROR;

   return ret;
}

/**
   Set firmware Port Mode Control Structure.

\param
   pMeiDrvCntrl:   points to the MEI interface register set
\param
   pPortModeCtrl:         points to the Port Mode Control Structure.

\return
   IFX_SUCCESS
   IFX_ERROR
*/
static IFX_int32_t MEI_VR9_PortModeControlStructureCurrentSet(
                                 MEI_DEV_T *pMeiDev,
                                 MEI_FW_PORT_MODE_CONTROL_DMA32_T *pPortModeCtrl)
{
   IFX_int32_t ret = 0;
   IFX_uint32_t cnt = 0;

   /* Protect device DMA access */
   MEI_DRV_GET_UNIQUE_ACCESS(pMeiDev);

   cnt = MEI_WriteDma32Bit(
            &(pMeiDev->meiDrvCntrl),
            MEI_FW_PORT_MODE_CONTROL_STRUCTURE_ADDR,
            (IFX_uint32_t*)pPortModeCtrl,
            sizeof(MEI_FW_PORT_MODE_CONTROL_DMA32_T)/sizeof(IFX_uint32_t),
            0);

   MEI_DRV_RELEASE_UNIQUE_ACCESS(pMeiDev);

   if (cnt != sizeof(MEI_FW_PORT_MODE_CONTROL_DMA32_T)/sizeof(IFX_uint32_t))
      ret = IFX_ERROR;

   return ret;
}

static IFX_int32_t MEI_VR9_PortModeControlStructureDefaultSet(
                                 MEI_DEV_T *pMeiDev)
{
   IFX_int32_t ret = 0;
   MEI_FW_PORT_MODE_CONTROL_DMA32_T fwPortModeCtrl = {0};

   /* Get current FW Port Mode Control Structure*/
   ret = MEI_VR9_PortModeControlStructureCurrentGet(pMeiDev, &fwPortModeCtrl);
   if (ret != IFX_SUCCESS)
   {
      PRN_ERR_USR_NL( MEI_DRV, MEI_DRV_PRN_LEVEL_ERR,
            ("MEI_DRV[%02d]: FW Port Mode Control structure get failed!" MEI_DRV_CRLF,
              MEI_DRV_LINENUM_GET(pMeiDev) ));

      return (-e_MEI_ERR_OP_FAILED);
   }

   /* Overwrite values with defauls from the FW image header. These values are not set
      by the upper layer SW yet*/
   fwPortModeCtrl.afeInitState      = pMeiDev->fwDl.defaultPortModeCtrl.afeInitState;
   fwPortModeCtrl.afePowerUp        = pMeiDev->fwDl.defaultPortModeCtrl.afePowerUp;
   fwPortModeCtrl.bgDuration        = pMeiDev->fwDl.defaultPortModeCtrl.bgDuration;
   fwPortModeCtrl.bgPort            = pMeiDev->fwDl.defaultPortModeCtrl.bgPort;
   fwPortModeCtrl.bgPortSelRegValue = pMeiDev->fwDl.defaultPortModeCtrl.bgPortSelRegValue;
   fwPortModeCtrl.imageOffsetSRAM   = pMeiDev->fwDl.defaultPortModeCtrl.imageOffsetSRAM;
   fwPortModeCtrl.maxBgDuration     = pMeiDev->fwDl.defaultPortModeCtrl.maxBgDuration;

   /* Update current FW Port Mode Control Structure*/
   ret = MEI_VR9_PortModeControlStructureCurrentSet(pMeiDev, &fwPortModeCtrl);
   if (ret != IFX_SUCCESS)
   {
      PRN_ERR_USR_NL( MEI_DRV, MEI_DRV_PRN_LEVEL_ERR,
            ("MEI_DRV[%02d]: FW Port Mode Control structure set failed!" MEI_DRV_CRLF,
              MEI_DRV_LINENUM_GET(pMeiDev) ));

      return (-e_MEI_ERR_OP_FAILED);
   }

   return ret;
}

/**
   Setup and fill VR9 firmware chunks.


\param
   pFwDlCtrl   points to the FW dowmload control structure.
\param
   pFwImage    points to the FW binary image
\param
   bInternCall    - indicates if the call is form the internal interface
                    (image and data already in kernel space)

\return
   IFX_SUCCESS
   IFX_ERROR
*/
static IFX_int32_t MEI_VR9_ChunksFill(
                                 MEI_FW_DOWNLOAD_CNTRL_T *pFwDlCtrl,
                                 unsigned char *pFwImage,
                                 IFX_boolean_t bInternCall)
{
   IFX_int32_t ret = 0, chunkSize_byte;
   IFX_uint32_t chunkIdx, idx_32bit, copySize_byte;
   IFX_int32_t imageSize = (IFX_int32_t)pFwDlCtrl->size_byte;
   unsigned char *pImage = pFwImage;
   IFX_uint32_t *pNonCachedChunk;

   for (chunkIdx=0; chunkIdx<MEI_FW_IMAGE_MAX_CHUNK_COUNT && imageSize > 0;
        chunkIdx++)
   {
      if (chunkIdx == MEI_FW_IMAGE_DATA_CHUNK_INDEX)
         continue;

      /* Set chunk size [bytes]*/
      chunkSize_byte = (chunkIdx == MEI_FW_IMAGE_MAX_CHUNK_COUNT - 1) ?
                          imageSize : MEI_FW_IMAGE_CHUNK_SIZE_BYTE;

      /* Check for the maximum allowed chunk size*/
      if (chunkSize_byte > MEI_BAR16_SIZE_BYTE)
      {
         PRN_ERR_USR_NL( MEI_DRV, MEI_DRV_PRN_LEVEL_ERR,
            ("MEI_DRV: chunk[%d] invalid size %d!"MEI_DRV_CRLF,
            chunkIdx, chunkSize_byte));

         ret = IFX_ERROR;
         break;
      }

      /* Allocate chunk*/
      ret = MEI_VR9_ImageChunkAlloc(pFwDlCtrl, chunkIdx, chunkSize_byte);
      if (ret != 0)
      {
         PRN_ERR_USR_NL( MEI_DRV, MEI_DRV_PRN_LEVEL_ERR,
            ("MEI_DRV: chunk[%d] size %d allocation failed!"
            MEI_DRV_CRLF, chunkIdx, chunkSize_byte));

         break;
      }

      /* Get number of bytes to fill current chunk*/
      copySize_byte = imageSize > MEI_FW_IMAGE_CHUNK_SIZE_BYTE ?
                         MEI_FW_IMAGE_CHUNK_SIZE_BYTE : imageSize;

      pNonCachedChunk =
         (IFX_uint32_t*)MEI_DRVOS_NON_CACHED_MEM_ADDR(pFwDlCtrl->imageChunkCtrl[chunkIdx].pImageChunk_aligned);

      /* Fill chunk */
      if (bInternCall)
      {
         memcpy(pNonCachedChunk, pImage, copySize_byte);
      }
      else
      {
         /* copy data to kernel space */
         if ( MEI_DRVOS_CpyFromUser(pNonCachedChunk, pImage, copySize_byte) == IFX_NULL)
         {
            PRN_ERR_USR_NL( MEI_DRV, MEI_DRV_PRN_LEVEL_ERR,
                  ("MEI_DRV: copy_from_user(chunk[%d], size %d) failed"
                  MEI_DRV_CRLF, chunkIdx, copySize_byte));

            ret = -e_MEI_ERR_GET_ARG;
            break;
         }
      }

      /* Swap chunk to target order*/
      for (idx_32bit=0; idx_32bit<copySize_byte/sizeof(IFX_uint32_t); idx_32bit++)
      {
         pNonCachedChunk[idx_32bit] = SWAP32_BYTE_ORDER(pNonCachedChunk[idx_32bit]);
      }

      pImage    += copySize_byte;
      imageSize -= chunkSize_byte;
   }

   if (ret == 0)
   {
      /* Release all unused chunks*/
      for (chunkIdx=chunkIdx; chunkIdx<MEI_FW_IMAGE_MAX_CHUNK_COUNT; chunkIdx++)
      {
         if (chunkIdx == MEI_FW_IMAGE_DATA_CHUNK_INDEX)
            continue;

         MEI_VR9_ImageChunkFree(pFwDlCtrl, chunkIdx);
      }

      if (pFwDlCtrl->dataRegionSize_Byte)
      {
         /* Allocate chunk for external writable DATA region */
         ret = MEI_VR9_ImageChunkAlloc(
                  pFwDlCtrl, MEI_FW_IMAGE_DATA_CHUNK_INDEX,
                  pFwDlCtrl->dataRegionSize_Byte);

         if (ret != 0)
         {
            PRN_ERR_USR_NL( MEI_DRV, MEI_DRV_PRN_LEVEL_ERR,
               ("MEI_DRV: external DATA region chunk[%d] size %d allocation failed!"
               MEI_DRV_CRLF, chunkIdx, pFwDlCtrl->dataRegionSize_Byte));
         }
      }
   }

   if (ret != 0)
   {
      /* Release all chunks*/
      for (chunkIdx=0; chunkIdx<MEI_FW_IMAGE_MAX_CHUNK_COUNT; chunkIdx++)
         MEI_VR9_ImageChunkFree(pFwDlCtrl, chunkIdx);
   }

   return ret;
}

/**
   Update VR9/AR9 BAR registers.

\param
   pMeiDev     points to the current VR9/AR9 channel device.

\return
   IFX_SUCCESS
   IFX_ERROR
*/
static IFX_int32_t MEI_VR9_BarRegistersUpdate(
                                 MEI_DEV_T *pMeiDev)
{
   IFX_int32_t ret = 0;
   IFX_uint32_t chunkIdx;
   MEI_MEI_DRV_CNTRL_T *pMeiDrvCntrl = &(pMeiDev->meiDrvCntrl);
   MEI_FW_DOWNLOAD_CNTRL_T *pFwDlCtrl = &(pMeiDev->fwDl);
   MEI_FW_IMAGE_CHUNK_CTRL_T *pChunk = pFwDlCtrl->imageChunkCtrl;

   for (chunkIdx=0; chunkIdx<MEI_FW_IMAGE_MAX_CHUNK_COUNT; chunkIdx++)
   {
      /* Skip unused chunks*/
      if (pChunk[chunkIdx].eImageChunkType == eMEI_FW_IMAGE_CHUNK_UNDEFINED)
         continue;

      /* Write BARx register with the chunk address*/
      MEI_REG_ACCESS_ME_XMEM_BAR_SET(pMeiDrvCntrl, chunkIdx, pChunk[chunkIdx].pBARx);

      PRN_DBG_USR_NL( MEI_DRV, MEI_DRV_PRN_LEVEL_NORMAL,
            ("BAR[%d] = 0x%08X" MEI_DRV_CRLF, chunkIdx,
            MEI_REG_ACCESS_ME_XMEM_BAR_GET(pMeiDrvCntrl, chunkIdx)));
   }

   for (chunkIdx=0; chunkIdx<MEI_FW_IMAGE_MAX_CHUNK_COUNT; chunkIdx++)
   {
      /* Fill unused chunks*/
      if (pChunk[chunkIdx].eImageChunkType == eMEI_FW_IMAGE_CHUNK_UNDEFINED)
         /* Write unused BARx register with the BAR0 content*/
         MEI_REG_ACCESS_ME_XMEM_BAR_SET(pMeiDrvCntrl, chunkIdx, pChunk[0].pBARx);
   }


   /* Check for the valid DATA chunk*/
   if (pChunk[MEI_FW_IMAGE_DATA_CHUNK_INDEX].eImageChunkType != eMEI_FW_IMAGE_CHUNK_DATA)
   {
      PRN_ERR_USR_NL( MEI_DRV, MEI_DRV_PRN_LEVEL_WRN,
         ("MEI_DRV: external DATA region chunk[%d] not specified!"
         MEI_DRV_CRLF, MEI_FW_IMAGE_DATA_CHUNK_INDEX));
   }
   else
   {
      /* Write Shadow register with the DATA chunk address*/
      MEI_REG_ACCESS_ME_XDATA_BASE_SH_SET(pMeiDrvCntrl,
         pChunk[MEI_FW_IMAGE_DATA_CHUNK_INDEX].pBARx);

      PRN_DBG_USR_NL( MEI_DRV, MEI_DRV_PRN_LEVEL_NORMAL,
            ("XDATA_BASE_SH = 0x%08X" MEI_DRV_CRLF,
             MEI_REG_ACCESS_ME_XDATA_BASE_SH_GET(pMeiDrvCntrl)));
   }

   return ret;
}


/**
   Download VR9/AR9 initial boot pages.

\param
   pMeiDev     points to the current VR9/AR9 channel device.

\return
   IFX_SUCCESS
   IFX_ERROR
*/
static IFX_int32_t MEI_VR9_BootPagesDownload(
                                 MEI_DEV_T *pMeiDev)
{
   IFX_int32_t ret = 0;
   IFX_uint32_t pageIdx;
   MEI_MEI_DRV_CNTRL_T *pMeiDrvCntrl = &(pMeiDev->meiDrvCntrl);
   MEI_FW_DOWNLOAD_CNTRL_T *pFwDlCtrl = &(pMeiDev->fwDl);
   MEI_FW_IMAGE_CHUNK_CTRL_T *pChunk = pFwDlCtrl->imageChunkCtrl;
   MEI_FW_IMAGE_CNTRL_T *pFwImageHeader = NULL;

   /* Set Image Header pointer. By default Image Header is located in the
      1st chunk*/
   pFwImageHeader = (MEI_FW_IMAGE_CNTRL_T*)(pChunk->pImageChunk_aligned);

   if (!pFwImageHeader)
   {
      PRN_ERR_USR_NL( MEI_DRV, MEI_DRV_PRN_LEVEL_ERR,
         ("MEI_DRV: No chunk specified to extract FW image header!"
         MEI_DRV_CRLF));
      return IFX_ERROR;
   }

   /*
      All further handlings are performed on the swapped image
   */

   /* Check for the valid chunk#0 size*/
   if (pFwImageHeader->imageNumOfPages * sizeof(MEI_FW_IMAGE_PAGE_T) > pChunk->imageChunkSize_byte)
   {
      PRN_ERR_USR_NL( MEI_DRV, MEI_DRV_PRN_LEVEL_ERR,
         ("MEI_DRV: Chunk#0 size is not enough to extract FW image header info!"
         MEI_DRV_CRLF));
      return IFX_ERROR;
   }

   /*
      Write Code/Data pages via DMA
      - Protect device DMA access
   */
   MEI_DRV_GET_UNIQUE_ACCESS(pMeiDev);

   /* Skip dummy Page#0*/
   for (pageIdx=1; pageIdx<pFwImageHeader->imageNumOfPages; pageIdx++)
   {
      if (pFwImageHeader->imagePage.imagePageX[pageIdx].codePageSize_32Bit & MEI_BOOT_FLAG)
      {
         PRN_ERR_USR_NL( MEI_DRV, MEI_DRV_PRN_LEVEL_LOW,
            ("MEI_DRV: BOOT Code Page[%d] download, size = %5d [32-bit]"MEI_DRV_CRLF, pageIdx,
            (pFwImageHeader->imagePage.imagePageX[pageIdx].codePageSize_32Bit) & (~MEI_BOOT_FLAG)));

         /* Fill Xpage with the PROGRAM Memory Data*/
         ret = MEI_VR9_XpageWrite(
                  pMeiDrvCntrl, pChunk,
                  &(pFwImageHeader->imagePage.imagePageX[pageIdx]), IFX_FALSE);

         if (ret != 0)
            break;
      }
 
      if (pFwImageHeader->imagePage.imagePageX[pageIdx].dataPageSize_32Bit & MEI_BOOT_FLAG)
      {
         PRN_ERR_USR_NL( MEI_DRV, MEI_DRV_PRN_LEVEL_LOW,
            ("MEI_DRV: BOOT Data Page[%d] download, size = %5d [32-bit]"MEI_DRV_CRLF, pageIdx,
            (pFwImageHeader->imagePage.imagePageX[pageIdx].dataPageSize_32Bit) & (~MEI_BOOT_FLAG)));

         /* Fill Xpage with the DATA memory Data*/
         ret = MEI_VR9_XpageWrite(
                  pMeiDrvCntrl, pChunk,
                  &(pFwImageHeader->imagePage.imagePageX[pageIdx]), IFX_TRUE);

         if (ret != 0)
            break;
      }
   }

   PRN_ERR_USR_NL( MEI_DRV, MEI_DRV_PRN_LEVEL_LOW,
      ("MEI_DRV: BOOT pages loading finished, ret=%d"MEI_DRV_CRLF, ret));

   MEI_DRV_RELEASE_UNIQUE_ACCESS(pMeiDev);

   return ret;
}

static IFX_int32_t MEI_VR9_FinishFwDownload(
                                 MEI_DEV_T *pMeiDev)
{
   IFX_int32_t ret = 0;
   MEI_FW_PORT_MODE_CONTROL_DMA32_T portModeCtrl = {0};

#ifdef INCLUDE_VR9_EMULATION_WORKAROUNDS
   /* Delay ARC releasing from the HALT state. This is true at least for the
      VR9 emulation platform. This workaround has been figured out during
      debug sessions on the VR9 emulation platform.*/
   MEI_DRVOS_Wait_ms(1000);
#endif /* #ifdef INCLUDE_VR9_EMULATION_WORKAROUNDS*/

   /* Change driver state*/
   MEI_DRV_STATE_SET(pMeiDev, e_MEI_DRV_STATE_WAIT_FOR_FIRST_RESP);

   PRN_ERR_USR_NL( MEI_DRV, MEI_DRV_PRN_LEVEL_LOW,
      ("MEI_DRV: Driver state changed to e_MEI_DRV_STATE_WAIT_FOR_FIRST_RESP"MEI_DRV_CRLF));

   /* Release ARC from the HALT state*/
   if ((ret = MEI_VR9_ArcFromHaltRelease(pMeiDev)) != IFX_SUCCESS)
   {
      PRN_ERR_USR_NL( MEI_DRV, MEI_DRV_PRN_LEVEL_ERR,
         ("MEI_DRV: ARC release from HALT state failed!" MEI_DRV_CRLF));

      return ret;
   }

   PRN_ERR_USR_NL( MEI_DRV, MEI_DRV_PRN_LEVEL_LOW,
      ("MEI_DRV: enter MODEM_READY wait state"MEI_DRV_CRLF));

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


      /* Get Current Port Mode Control structure to check error codes*/
      if (MEI_VR9_PortModeControlStructureCurrentGet(
             pMeiDev, &portModeCtrl) != IFX_SUCCESS)
      {
         PRN_ERR_USR_NL( MEI_DRV, MEI_DRV_PRN_LEVEL_ERR,
            ("MEI_DRV: Current Port Mode Control Structure get failed!"
            MEI_DRV_CRLF));

         return (-e_MEI_ERR_OP_FAILED);
      }

      if (portModeCtrl.bootError)
      {
         PRN_ERR_USR_NL( MEI_DRV, MEI_DRV_PRN_LEVEL_ERR,
            ("MEI_DRV: BootLoader62 finished with error code 0x%02X"
            MEI_DRV_CRLF, portModeCtrl.bootError));

         return (portModeCtrl.bootError == MEI_FW_BOOTLOADER_ERR_INVAL_IMAGE) ?
            (-e_MEI_ERR_INVAL_FW_IMAGE) : (-e_MEI_ERR_OP_FAILED);
      }

      return (-e_MEI_ERR_OP_FAILED);
   }

#if (MEI_MAX_DFE_INSTANCE_PER_ENTITY != MEI_MAX_MEI_IF_PER_DEVICE)
   /* Populate data to the SLAVE line*/
   {
      MEIX_CNTRL_T *pXCntrl = NULL;
      MEI_DEV_T    *pMeiDevSlave = NULL;
      int entity;

      PRN_ERR_USR_NL( MEI_DRV, MEI_DRV_PRN_LEVEL_LOW,
         ("MEI_DRV: populate FW download data to the slave line"MEI_DRV_CRLF));

      entity = MEI_GET_ENTITY_FROM_DEVNUM(MEI_DRV_LINENUM_GET(pMeiDev));

      if ( (pXCntrl = MEIX_Cntrl[entity]) == NULL)
      {
         PRN_ERR_USR_NL( MEI_DRV, MEI_DRV_PRN_LEVEL_ERR,
               ("MEI_DRV[%02d]: ERROR Line Struct Allocate - "
                "missing MEIX[%d] entity struct" MEI_DRV_CRLF,
                MEI_DRV_LINENUM_GET(pMeiDev), entity));

         return -e_MEI_ERR_OP_FAILED;
      }

      if ( (pMeiDevSlave = pXCntrl->MeiDevice[1]) == NULL)
      {
         PRN_ERR_USR_NL( MEI_DRV, MEI_DRV_PRN_LEVEL_ERR,
               ("MEI_DRV[%02d]: SLAVE line not exists yet" MEI_DRV_CRLF,
               MEI_DRV_LINENUM_GET(pMeiDev)));

         return -e_MEI_ERR_OP_FAILED;
      }

      /* Copy Mbox descriptor from the MASTER line*/
      memcpy(&(pMeiDevSlave->modemData.mBoxDescr),
             &(pMeiDev->modemData.mBoxDescr),
             sizeof((pMeiDev->modemData.mBoxDescr)));

      /* Release SLAVE line MBox*/
      MEI_ReleaseMailboxMsg(&(pMeiDevSlave->meiDrvCntrl));

      /* Set SLAVE line state*/
      MEI_DRV_STATE_SET(pMeiDevSlave, MEI_DRV_STATE_GET(pMeiDev));
   }
#endif /* #if (MEI_MAX_DFE_INSTANCE_PER_ENTITY != MEI_MAX_MEI_IF_PER_DEVICE)*/

   return ret;
}

/**
   Start the FW download

\param
   pMeiDynCntrl: Points to the dynamic control struct.
\param
   pArgFwDl:     Points to the FW downlosd information data
\param
   bInternCall:  Indicates if the call is form the internal interface
                (image and data already in kernel space)

\return
   IFX_SUCCESS: if the FW was successful.
   negative value if something went wrong.

*/
static IFX_int32_t MEI_VR9_StartFwDownload(
                                 MEI_DYN_CNTRL_T        *pMeiDynCntrl,
                                 IOCTL_MEI_fwDownLoad_t *pArgFwDl,
                                 IFX_boolean_t            bInternCall)
{
   IFX_int32_t ret = 0;
   MEI_FW_DOWNLOAD_CNTRL_T *pFwDlCtrl = &(pMeiDynCntrl->pMeiDev->fwDl);
   MEI_DEV_T *pMeiDev = pMeiDynCntrl->pMeiDev;

   /* Low Level MEI init*/
   if ((ret = MEI_LowLevelInit(&(pMeiDev->meiDrvCntrl))) != IFX_SUCCESS)
   {
      PRN_ERR_USR_NL( MEI_DRV, MEI_DRV_PRN_LEVEL_ERR,
         ("MEI_DRV: Access port select failed!" MEI_DRV_CRLF));

      return ret;
   }

   /* Setup and Fill Fw download chunks*/
   ret = MEI_VR9_ChunksFill(pFwDlCtrl, pArgFwDl->pFwImage, bInternCall);
   if (ret != IFX_SUCCESS)
   {
      PRN_ERR_USR_NL( MEI_DRV, MEI_DRV_PRN_LEVEL_ERR,
         ("MEI_DRV: FW chunks setup/fill failed!" MEI_DRV_CRLF));

      return ret;
   }

   /* Display Chunks info*/
   MEI_VR9_ChunksInfoShow(pMeiDev);

   /* Update BAR registers*/
   if ((ret = MEI_VR9_BarRegistersUpdate(pMeiDev)) != IFX_SUCCESS)
   {
      PRN_ERR_USR_NL( MEI_DRV, MEI_DRV_PRN_LEVEL_ERR,
         ("MEI_DRV: BAR registers update failed!" MEI_DRV_CRLF));

      return ret;
   }

   /* Download Boot Pages*/
   if ((ret = MEI_VR9_BootPagesDownload(pMeiDev)) != IFX_SUCCESS)
   {
      PRN_ERR_USR_NL( MEI_DRV, MEI_DRV_PRN_LEVEL_ERR,
         ("MEI_DRV: FW Boot Pages download failed!" MEI_DRV_CRLF));

      return ret;
   }

   return ret;
}

/**
   Start Optimized FW download

\param
   pMeiDynCntrl: Points to the dynamic control struct.
\param
   pArgFwDl:     Points to the FW download information data
\param
   bInternCall:  Indicates if the call is form the internal interface
                (image and data already in kernel space)

\return
   IFX_SUCCESS: if the FW was successful.
   negative value if something went wrong.

*/
static IFX_int32_t MEI_VR9_StartOptFwDownload(
                                 MEI_DYN_CNTRL_T           *pMeiDynCntrl,
                                 IOCTL_MEI_fwOptDownLoad_t *pArgFwDl,
                                 IFX_boolean_t             bInternCall)
{
   IFX_int32_t ret = 0;
   IFX_uint32_t chunkIdx =
      pArgFwDl->chunk_num == MEI_FW_IMAGE_DATA_CHUNK_INDEX ?
      pArgFwDl->chunk_num + 1 : pArgFwDl->chunk_num;
   IFX_uint32_t idx_32bit;
   MEI_FW_DOWNLOAD_CNTRL_T *pFwDlCtrl = &(pMeiDynCntrl->pMeiDev->fwDl);
   MEI_DEV_T *pMeiDev = pMeiDynCntrl->pMeiDev;

   if (chunkIdx == 0)
   {
      /* Low Level MEI init*/
      if ((ret = MEI_LowLevelInit(&(pMeiDev->meiDrvCntrl))) != IFX_SUCCESS)
      {
         PRN_ERR_USR_NL( MEI_DRV, MEI_DRV_PRN_LEVEL_ERR,
            ("MEI_DRV: Access port select failed!" MEI_DRV_CRLF));

         return ret;
      }
   }

   /* Allocate chunk*/
   ret = MEI_VR9_ImageChunkAlloc(pFwDlCtrl, chunkIdx, pArgFwDl->size_byte);
   if (ret != 0)
   {
      PRN_ERR_USR_NL( MEI_DRV, MEI_DRV_PRN_LEVEL_ERR,
         ("MEI_DRV: chunk[%d] size %d allocation failed!"
         MEI_DRV_CRLF, chunkIdx, pArgFwDl->size_byte));

      return ret;
   }

   /* Fill chunk */
   if (bInternCall)
   {
      memcpy(
         pFwDlCtrl->imageChunkCtrl[chunkIdx].pImageChunk_aligned,
         pArgFwDl->pFwImageChunk, pArgFwDl->size_byte);
   }
   else
   {
      /* copy data to kernel space */
      if ( MEI_DRVOS_CpyFromUser(
               pFwDlCtrl->imageChunkCtrl[chunkIdx].pImageChunk_aligned,
               pArgFwDl->pFwImageChunk, pArgFwDl->size_byte) == IFX_NULL)
      {
         PRN_ERR_USR_NL( MEI_DRV, MEI_DRV_PRN_LEVEL_ERR,
               ("MEI_DRV: copy_from_user(chunk[%d], size %d) failed"
               MEI_DRV_CRLF, chunkIdx, pArgFwDl->size_byte));

         ret = -e_MEI_ERR_GET_ARG;
         return ret;
      }
   }

   /* Swap chunk to target order*/
   for (idx_32bit=0; idx_32bit<pArgFwDl->size_byte/sizeof(IFX_uint32_t); idx_32bit++)
   {
      ((IFX_uint32_t*)(pFwDlCtrl->imageChunkCtrl[chunkIdx].pImageChunk_aligned))[idx_32bit] =
         SWAP32_BYTE_ORDER(((IFX_uint32_t*)(pFwDlCtrl->imageChunkCtrl[chunkIdx].pImageChunk_aligned))[idx_32bit]);
   }

   if (pArgFwDl->bLastChunk)
   {
      if (pFwDlCtrl->dataRegionSize_Byte)
      {
         /* Allocate chunk for external writable DATA region */
         ret = MEI_VR9_ImageChunkAlloc(
                  pFwDlCtrl, MEI_FW_IMAGE_DATA_CHUNK_INDEX,
                  pFwDlCtrl->dataRegionSize_Byte);

         if (ret != 0)
         {
            PRN_ERR_USR_NL( MEI_DRV, MEI_DRV_PRN_LEVEL_ERR,
               ("MEI_DRV: external DATA region chunk[%d] size %d allocation failed!"
               MEI_DRV_CRLF, chunkIdx, pFwDlCtrl->dataRegionSize_Byte));
            return ret;
         }
      }

      /* Display Chunks info*/
      MEI_VR9_ChunksInfoShow(pMeiDev);

      /* Update BAR registers*/
      if ((ret = MEI_VR9_BarRegistersUpdate(pMeiDev)) != IFX_SUCCESS)
      {
         PRN_ERR_USR_NL( MEI_DRV, MEI_DRV_PRN_LEVEL_ERR,
            ("MEI_DRV: BAR registers update failed!" MEI_DRV_CRLF));

         return ret;
      }

      /* Download Boot Pages*/
      if ((ret = MEI_VR9_BootPagesDownload(pMeiDev)) != IFX_SUCCESS)
      {
         PRN_ERR_USR_NL( MEI_DRV, MEI_DRV_PRN_LEVEL_ERR,
            ("MEI_DRV: FW Boot Pages download failed!" MEI_DRV_CRLF));

         return ret;
      }
   }

   return ret;
}

IFX_void_t MEI_DEV_FirmwareDownloadResourcesRelease(
                                 MEI_DEV_T       *pMeiDev)
{
   IFX_uint32_t chunkIdx;

   MEI_DRVOS_SemaphoreLock(&pFwDlCntrlLock);

   /* Free FW chunks*/
   for (chunkIdx=0; chunkIdx < MEI_FW_IMAGE_MAX_CHUNK_COUNT - 1; chunkIdx++)
   {
      MEI_VR9_ImageChunkFree( &(pMeiDev->fwDl), chunkIdx);
   }

   MEI_DRVOS_SemaphoreUnlock(&pFwDlCntrlLock);

   /* mutex exist */
   MEI_DRVOS_SemaphoreDelete(&pFwDlCntrlLock);

#if (MEI_SUPPORT_PCI_SLAVE_FW_DOWNLOAD == 1)
   /* Delete PCI slave pool*/
   if (pMeiDev->fwDl.pPool)
   {
      MEI_VR9_PciSlavePoolDelete(pMeiDev->fwDl.pPool);
   }
#endif /* #if (MEI_SUPPORT_PCI_SLAVE_FW_DOWNLOAD == 1)*/
}

static IFX_int32_t MEI_DEV_FirmwareImageHeaderGet(
                                 MEI_DEV_T     *pMeiDev,
                                 IFX_uint8_t   *pFwImage,
                                 IFX_boolean_t bInternCall)
{
   IFX_int32_t ret = 0;
   MEI_FW_IMAGE_CNTRL_T fwImageCtrl;
   MEI_FW_IMAGE_PAGE3_T fwImagePage3;
   MEI_FW_PORT_MODE_CONTROL_DMA32_T fwPortModeCtrlCurrent = {0};

   /* Get Firmware Image header (including Page#0 info)*/
   if (bInternCall)
   {
      memcpy(&fwImageCtrl, pFwImage, sizeof(fwImageCtrl));
   }
   else
   {
      /* copy data to kernel space */
      if ( MEI_DRVOS_CpyFromUser( &fwImageCtrl, pFwImage,
                                   sizeof(fwImageCtrl)) == IFX_NULL)
      {
         PRN_ERR_USR_NL( MEI_DRV, MEI_DRV_PRN_LEVEL_ERR,
               ("MEI_DRV[0x%02X]: download - copy_from_user(image ctrl data) failed!" MEI_DRV_CRLF,
                MEI_DRV_LINENUM_GET(pMeiDev)));

         ret = -e_MEI_ERR_GET_ARG;
         return ret;
      }
   }

   /* Get total number of swap pages */
   pMeiDev->fwDl.imageNumOfPages =
      SWAP32_BYTE_ORDER(fwImageCtrl.imageNumOfPages);

   if (pMeiDev->fwDl.imageNumOfPages == 0)
   {
      PRN_ERR_USR_NL( MEI_DRV, MEI_DRV_PRN_LEVEL_ERR,
            ("MEI_DRV[0x%02X]: download - no FW swap pages detected!" MEI_DRV_CRLF,
             MEI_DRV_LINENUM_GET(pMeiDev)));

      ret = -e_MEI_ERR_GET_ARG;
      return ret;
   }

   /* Get FW size */
   pMeiDev->fwDl.size_byte =
      SWAP32_BYTE_ORDER(fwImageCtrl.imageSize_Bytes);

   if (pMeiDev->fwDl.size_byte == 0)
   {
      PRN_ERR_USR_NL( MEI_DRV, MEI_DRV_PRN_LEVEL_ERR,
            ("MEI_DRV[0x%02X]: download - FW header binary size is zero!"
            MEI_DRV_CRLF, MEI_DRV_LINENUM_GET(pMeiDev)));

      ret = -e_MEI_ERR_GET_ARG;
      return ret;
   }

   pMeiDev->fwDl.size_byte =
      SWAP32_BYTE_ORDER(fwImageCtrl.imageSize_Bytes) +
      sizeof(fwImageCtrl.imageSize_Bytes) + sizeof(fwImageCtrl.imageCheckSum);

   /*
      Get default Port Mode Control structure from the FW header Page#0
   */
   memcpy(&(pMeiDev->fwDl.defaultPortModeCtrl), &(fwImageCtrl.imagePage.imagePage0),
      sizeof(pMeiDev->fwDl.defaultPortModeCtrl));


   pMeiDev->fwDl.defaultPortModeCtrl.bgPortSelRegValue =
      SWAP32_BYTE_ORDER(pMeiDev->fwDl.defaultPortModeCtrl.bgPortSelRegValue);
   pMeiDev->fwDl.defaultPortModeCtrl.imageOffsetSRAM =
      SWAP32_BYTE_ORDER(pMeiDev->fwDl.defaultPortModeCtrl.imageOffsetSRAM);

   pMeiDev->fwDl.defaultPortModeCtrl.signature0 =
      SWAP16_BYTE_ORDER(pMeiDev->fwDl.defaultPortModeCtrl.signature0);

   /* Check Signature#0*/
   if (pMeiDev->fwDl.defaultPortModeCtrl.signature0 != MEI_FW_IMAGE_SIGNATURE0)
   {
      PRN_ERR_USR_NL( MEI_DRV, MEI_DRV_PRN_LEVEL_ERR,
            ("MEI_DRV[0x%02X]: download - wrong Signature0 = 0x%04X detected "
            "within the firmware binary!"
            MEI_DRV_CRLF, MEI_DRV_LINENUM_GET(pMeiDev),
            pMeiDev->fwDl.defaultPortModeCtrl.signature0));

      ret = -e_MEI_ERR_GET_ARG;
      return ret;
   }

   /* Get Firmware Image Page#3 info*/
   if (bInternCall)
   {
      memcpy(&fwImagePage3,
         pFwImage + MEI_FW_IMAGE_PAGE3_OFFSET_32BIT * sizeof(IFX_uint32_t),
         sizeof(fwImagePage3));
   }
   else
   {
      /* copy data to kernel space */
      if ( MEI_DRVOS_CpyFromUser(
              &fwImagePage3,
              pFwImage + MEI_FW_IMAGE_PAGE3_OFFSET_32BIT * sizeof(IFX_uint32_t),
              sizeof(fwImagePage3)) == IFX_NULL)
      {
         PRN_ERR_USR_NL( MEI_DRV, MEI_DRV_PRN_LEVEL_ERR,
               ("MEI_DRV[0x%02X]: download - copy_from_user(page#3 ctrl data) failed!" MEI_DRV_CRLF,
                MEI_DRV_LINENUM_GET(pMeiDev)));

         ret = -e_MEI_ERR_GET_ARG;
         return ret;
      }
   }

   /* Get size of the permanent CACHED region [bytes] */
   pMeiDev->fwDl.cachedRegionSize_byte =
      SWAP32_BYTE_ORDER(fwImagePage3.cachedRegionSize_Byte);

   /* Not defined yet in the VR9 MEI specification,
      set to the maximum size*/
   pMeiDev->fwDl.dataRegionSize_Byte = MEI_FW_IMAGE_CHUNK_SIZE_BYTE;

   PRN_DBG_USR_NL( MEI_DRV, MEI_DRV_PRN_LEVEL_NORMAL,
         (MEI_DRV_CRLF "================= FW IMAGE INFO ==================" MEI_DRV_CRLF));
   PRN_DBG_USR_NL( MEI_DRV, MEI_DRV_PRN_LEVEL_NORMAL,
         ("Size = %d [byte], CheckSum = 0x%08X, NumOfPages = %d" MEI_DRV_CRLF,
          pMeiDev->fwDl.size_byte, SWAP32_BYTE_ORDER(fwImageCtrl.imageCheckSum),
          pMeiDev->fwDl.imageNumOfPages));
   PRN_DBG_USR_NL( MEI_DRV, MEI_DRV_PRN_LEVEL_NORMAL,
         ("CACHED region size = %d [byte], DATA region size = %d [byte]" MEI_DRV_CRLF,
          pMeiDev->fwDl.cachedRegionSize_byte, pMeiDev->fwDl.dataRegionSize_Byte));
   PRN_DBG_USR_NL( MEI_DRV, MEI_DRV_PRN_LEVEL_NORMAL,
         (MEI_DRV_CRLF "========== Port Mode Control (default) ===========" MEI_DRV_CRLF));
   PRN_DBG_USR_NL( MEI_DRV, MEI_DRV_PRN_LEVEL_NORMAL,
         ("Dual Port Lock      : %s" MEI_DRV_CRLF,
          pMeiDev->fwDl.defaultPortModeCtrl.dualPortModeLock == 1 ? "LOCKED" : "UNLOCKED"));
   PRN_DBG_USR_NL( MEI_DRV, MEI_DRV_PRN_LEVEL_NORMAL,
         ("xDSL Mode Lock      : %s" MEI_DRV_CRLF,
          pMeiDev->fwDl.defaultPortModeCtrl.xDslModeLock == 1 ? "LOCKED" : "UNLOCKED"));
   PRN_DBG_USR_NL( MEI_DRV, MEI_DRV_PRN_LEVEL_NORMAL,
         ("Preferred Port Mode : %s" MEI_DRV_CRLF,
          pMeiDev->fwDl.defaultPortModeCtrl.dualPortModePreffered == 1 ? "DUAL" : "SINGLE"));
   PRN_DBG_USR_NL( MEI_DRV, MEI_DRV_PRN_LEVEL_NORMAL,
         ("Preferred xDSL Mode : %s" MEI_DRV_CRLF,
          pMeiDev->fwDl.defaultPortModeCtrl.xDslModePreffered == 1 ? "ADSL" : "VDSL"));
   PRN_DBG_USR_NL( MEI_DRV, MEI_DRV_PRN_LEVEL_NORMAL,
         ("Current Port Mode   : %s" MEI_DRV_CRLF,
          pMeiDev->fwDl.defaultPortModeCtrl.dualPortModeCurrent == 0 ? "SINGLE" :
          pMeiDev->fwDl.defaultPortModeCtrl.dualPortModeCurrent == 1 ? "DUAL" : "NONE"));
   PRN_DBG_USR_NL( MEI_DRV, MEI_DRV_PRN_LEVEL_NORMAL,
         ("Current xDSL Mode   : %s" MEI_DRV_CRLF,
          pMeiDev->fwDl.defaultPortModeCtrl.xDslModeCurrent == 0 ? "VDSL" :
          pMeiDev->fwDl.defaultPortModeCtrl.xDslModeCurrent == 1 ? "ADSL" : "NONE"));
   PRN_DBG_USR_NL( MEI_DRV, MEI_DRV_PRN_LEVEL_NORMAL,
         (MEI_DRV_CRLF "==================================================" MEI_DRV_CRLF));

   /* Get current Port Mode Control Structure*/
   if ( MEI_VR9_PortModeControlStructureCurrentGet(
           pMeiDev, &fwPortModeCtrlCurrent) != IFX_SUCCESS)
   {
      PRN_DBG_USR_NL( MEI_DRV, MEI_DRV_PRN_LEVEL_WRN,
            (MEI_DRV_CRLF "Current Port Mode Control Structure get failed!"
            MEI_DRV_CRLF));
      return ret;
   }
   else
   {
      if ( (fwPortModeCtrlCurrent.signature0 != MEI_FW_IMAGE_SIGNATURE0) ||
           (fwPortModeCtrlCurrent.signature1 != MEI_FW_IMAGE_SIGNATURE1) )
      {
         PRN_DBG_USR_NL( MEI_DRV, MEI_DRV_PRN_LEVEL_WRN,
               (MEI_DRV_CRLF "Current Port Mode Control Structure not "
               "initialized yet, bootloader will take the default structure"
               MEI_DRV_CRLF));
         return ret;
      }
   }

   PRN_DBG_USR_NL( MEI_DRV, MEI_DRV_PRN_LEVEL_NORMAL,
         (MEI_DRV_CRLF "========== Port Mode Control (current) ===========" MEI_DRV_CRLF));
   PRN_DBG_USR_NL( MEI_DRV, MEI_DRV_PRN_LEVEL_NORMAL,
         ("Dual Port Lock      : %s" MEI_DRV_CRLF,
          fwPortModeCtrlCurrent.dualPortModeLock == 1 ? "LOCKED" : "UNLOCKED"));
   PRN_DBG_USR_NL( MEI_DRV, MEI_DRV_PRN_LEVEL_NORMAL,
         ("xDSL Mode Lock      : %s" MEI_DRV_CRLF,
          fwPortModeCtrlCurrent.xDslModeLock == 1 ? "LOCKED" : "UNLOCKED"));
   PRN_DBG_USR_NL( MEI_DRV, MEI_DRV_PRN_LEVEL_NORMAL,
         ("Preferred Port Mode : %s" MEI_DRV_CRLF,
          fwPortModeCtrlCurrent.dualPortModePreffered == 1 ? "DUAL" : "SINGLE"));
   PRN_DBG_USR_NL( MEI_DRV, MEI_DRV_PRN_LEVEL_NORMAL,
         ("Preferred xDSL Mode : %s" MEI_DRV_CRLF,
          fwPortModeCtrlCurrent.xDslModePreffered == 1 ? "ADSL" : "VDSL"));
   PRN_DBG_USR_NL( MEI_DRV, MEI_DRV_PRN_LEVEL_NORMAL,
         ("Current Port Mode   : %s" MEI_DRV_CRLF,
          fwPortModeCtrlCurrent.dualPortModeCurrent == 0 ? "SINGLE" :
          fwPortModeCtrlCurrent.dualPortModeCurrent == 1 ? "DUAL" : "NONE"));
   PRN_DBG_USR_NL( MEI_DRV, MEI_DRV_PRN_LEVEL_NORMAL,
         ("Current xDSL Mode   : %s" MEI_DRV_CRLF,
          fwPortModeCtrlCurrent.xDslModeCurrent == 0 ? "VDSL" :
          fwPortModeCtrlCurrent.xDslModeCurrent == 1 ? "ADSL" : "NONE"));
   PRN_DBG_USR_NL( MEI_DRV, MEI_DRV_PRN_LEVEL_NORMAL,
         (MEI_DRV_CRLF "==================================================" MEI_DRV_CRLF));

   return ret;
}


/* ============================================================================
   Function definition (FW Download ioctl)
   ========================================================================= */

/**
   Do the firmware download for the current VR9 device.

\param
   pMeiDynCntrl - private dynamic comtrol data (per open instance)
\param
   pFwDl          - points to the FW download information data
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
                                 IFX_boolean_t            bInternCall)
{
   IFX_int32_t ret = 0;
   MEI_DEV_T *pMeiDev = pMeiDynCntrl->pMeiDev;

   PRN_DBG_USR( MEI_DRV, MEI_DRV_PRN_LEVEL_NORMAL, MEI_DRV_LINENUM_GET(pMeiDev),
         ("MEI_DRV[%02d]: start FW download -  entity %d" MEI_DRV_CRLF,
           MEI_DRV_LINENUM_GET(pMeiDev), MEI_GET_ENTITY_FROM_DEVNUM(MEI_DRV_LINENUM_GET(pMeiDev))));

#if (MEI_MAX_DFE_INSTANCE_PER_ENTITY != MEI_MAX_MEI_IF_PER_DEVICE)
   if (MEI_DRV_LINENUM_GET(pMeiDev) % MEI_MAX_DFE_INSTANCE_PER_ENTITY)
   {
      if (MEI_DRV_STATE_GET(pMeiDev) != e_MEI_DRV_STATE_DFE_READY)
      {
         PRN_ERR_USR_NL( MEI_DRV, MEI_DRV_PRN_LEVEL_ERR,
               ("MEI_DRV[%02d]: SLAVE line is not ready, download MASTER line FW first!"
               MEI_DRV_CRLF, MEI_DRV_LINENUM_GET(pMeiDev) ));
         return (-e_MEI_ERR_OP_FAILED);
      }
      else
      {
         return 0;
      }
   }
#endif /* #if (MEI_MAX_DFE_INSTANCE_PER_ENTITY != MEI_MAX_MEI_IF_PER_DEVICE)*/

   if (!pArgFwDl->pFwImage)
   {
      PRN_ERR_USR_NL( MEI_DRV, MEI_DRV_PRN_LEVEL_ERR,
            ("MEI_DRV[%02d]: missing FW image for download." MEI_DRV_CRLF,
              MEI_DRV_LINENUM_GET(pMeiDev) ));

      return (-e_MEI_ERR_INVAL_ARG);
   }

   /* Check for the minimum Image Size. At least one page should be available
      (excluding Page#0 which is a dummy page)*/
   if (pArgFwDl->size_byte <= MEI_FW_IMAGE_HEADER_SIZE_BYTE)
   {
      PRN_ERR_USR_NL( MEI_DRV, MEI_DRV_PRN_LEVEL_ERR,
         ("MEI_DRV: ERROR - Firmware Image size %d is too small!" MEI_DRV_CRLF,
         pArgFwDl->size_byte));

      return IFX_ERROR;
   }

   /* Check for the maximum Firmware Image size */
   if (pArgFwDl->size_byte > MEI_FW_IMAGE_MAX_SIZE_BYTE)
   {
      PRN_ERR_USR_NL( MEI_DRV, MEI_DRV_PRN_LEVEL_ERR,
         ("MEI_DRV: ERROR - Firmware Image size %d is too large!" MEI_DRV_CRLF,
         pArgFwDl->size_byte));

      return IFX_ERROR;
   }

   /* Check current driver state. */
   if (MEI_DRV_STATE_GET(pMeiDev) != e_MEI_DRV_STATE_SW_INIT_DONE)
   {
      PRN_ERR_USR_NL( MEI_DRV, MEI_DRV_PRN_LEVEL_ERR,
            ("MEI_DRV[%02d]: invalid state (%d) for load FW image." MEI_DRV_CRLF,
              MEI_DRV_LINENUM_GET(pMeiDev), MEI_DRV_STATE_GET(pMeiDev) ));

      return -e_MEI_ERR_INVAL_STATE;
   }

   MEI_DRVOS_SemaphoreLock(&pFwDlCntrlLock);

   /* Get FW Image Header info*/
   ret = MEI_DEV_FirmwareImageHeaderGet(pMeiDev, pArgFwDl->pFwImage, bInternCall);

   if (ret != 0)
   {
      PRN_ERR_USR_NL( MEI_DRV, MEI_DRV_PRN_LEVEL_ERR,
            ("MEI_DRV[0x%02X]: FW Image Header Info get failed!" MEI_DRV_CRLF,
             MEI_DRV_LINENUM_GET(pMeiDev)));

      goto ERROR_MEI_IOCTL_FWDL_LOAD_IMAGE;
   }

   /* Check Image size [bytes]*/
   if (pArgFwDl->size_byte != pMeiDev->fwDl.size_byte)
   {
      PRN_ERR_USR_NL( MEI_DRV, MEI_DRV_PRN_LEVEL_ERR,
            ("MEI_DRV[0x%02X]: FW Image size mismatch %u/%u!" MEI_DRV_CRLF,
             MEI_DRV_LINENUM_GET(pMeiDev), pArgFwDl->size_byte, pMeiDev->fwDl.size_byte));

      goto ERROR_MEI_IOCTL_FWDL_LOAD_IMAGE;
   }

   /* Merge Default Port Mode Control Structure*/
   ret = MEI_VR9_PortModeControlStructureDefaultSet(pMeiDev);

   if (ret != 0)
   {
      PRN_ERR_USR_NL( MEI_DRV, MEI_DRV_PRN_LEVEL_ERR,
            ("MEI_DRV[0x%02X]: Port Mode Control Structure Default set failed!" MEI_DRV_CRLF,
             MEI_DRV_LINENUM_GET(pMeiDev)));

      goto ERROR_MEI_IOCTL_FWDL_LOAD_IMAGE;
   }

   /* Start FW download*/
   ret = MEI_VR9_StartFwDownload(pMeiDynCntrl, pArgFwDl, bInternCall);

   PRN_DBG_USR( MEI_DRV, MEI_DRV_PRN_LEVEL_NORMAL, MEI_DRV_LINENUM_GET(pMeiDev),
         ("MEI_DRV[%02d]: FW download step 1 ready" MEI_DRV_CRLF,
           MEI_DRV_LINENUM_GET(pMeiDev)));

   /* Finish FW download*/
   if (ret == 0)
   {
      ret = MEI_VR9_FinishFwDownload(pMeiDev);
   }

   MEI_DRVOS_SemaphoreUnlock(&pFwDlCntrlLock);

   return ret;

ERROR_MEI_IOCTL_FWDL_LOAD_IMAGE:

   MEI_DRVOS_SemaphoreUnlock(&pFwDlCntrlLock);

   return ret;
}

/**
   Do the optimized firmware download (via chunks) for the current VR9 device.

\param
   pMeiDynCntrl - private dynamic comtrol data (per open instance)
\param
   pFwDl          - points to the FW download information data
\param
   bInternCall    - indicates if the call is form the internal interface
                    (image and data already in kernel space)
\return
   IFX_SUCCESS: if the FW was successful.
   negative value if something went wrong.

*/
IFX_int32_t MEI_IoctlOptFirmwareDownload(
                                 MEI_DYN_CNTRL_T           *pMeiDynCntrl,
                                 IOCTL_MEI_fwOptDownLoad_t *pArgFwDl,
                                 IFX_boolean_t             bInternCall)
{
   IFX_int32_t ret = 0;
   MEI_DEV_T *pMeiDev = pMeiDynCntrl->pMeiDev;

   PRN_DBG_USR( MEI_DRV, MEI_DRV_PRN_LEVEL_NORMAL, MEI_DRV_LINENUM_GET(pMeiDev),
         ("MEI_DRV[%02d]: Optimized FW download -  entity %d, chunk %d" MEI_DRV_CRLF,
           MEI_DRV_LINENUM_GET(pMeiDev), MEI_GET_ENTITY_FROM_DEVNUM(MEI_DRV_LINENUM_GET(pMeiDev)),
           pArgFwDl->chunk_num));

   if (!pArgFwDl->pFwImageChunk)
   {
      PRN_ERR_USR_NL( MEI_DRV, MEI_DRV_PRN_LEVEL_ERR,
            ("MEI_DRV[%02d]: missing FW image chunk for download." MEI_DRV_CRLF,
              MEI_DRV_LINENUM_GET(pMeiDev) ));

      return (-e_MEI_ERR_INVAL_ARG);
   }

   /* Check for the minimum Image Size. At least one page should be available
      (excluding Page#0 which is a dummy page)*/
   if ((pArgFwDl->size_byte <= MEI_FW_IMAGE_HEADER_SIZE_BYTE) &&
       (pArgFwDl->chunk_num == 0))
   {
      PRN_ERR_USR_NL( MEI_DRV, MEI_DRV_PRN_LEVEL_ERR,
         ("MEI_DRV: ERROR - Firmware Image chunk size %d is too small!" MEI_DRV_CRLF,
         pArgFwDl->size_byte));

      return IFX_ERROR;
   }

   /* Check for the correct chunk number*/
   if (pArgFwDl->chunk_num > MEI_FW_IMAGE_MAX_CHUNK_COUNT - 1)
   {
      PRN_ERR_USR_NL( MEI_DRV, MEI_DRV_PRN_LEVEL_ERR,
         ("MEI_DRV: ERROR - Firmware Image chunk number %d exceeds maximum allowed value %d!"
         MEI_DRV_CRLF, pArgFwDl->chunk_num, (MEI_FW_IMAGE_MAX_CHUNK_COUNT - 1)));

      return IFX_ERROR;
   }

   /* Check for the maximum chunk sizes*/
   if (pArgFwDl->chunk_num == (MEI_FW_IMAGE_MAX_CHUNK_COUNT - 1))
   {
      /* Check for the maximum Firmware Image chunk #16 size */
      if (pArgFwDl->size_byte > MEI_BAR16_SIZE_BYTE)
      {
         PRN_ERR_USR_NL( MEI_DRV, MEI_DRV_PRN_LEVEL_ERR,
            ("MEI_DRV: ERROR - Firmware Image chunk #16 size %d is too large!" MEI_DRV_CRLF,
            pArgFwDl->size_byte));

         return IFX_ERROR;
      }
   }
   else
   {
      /* Check for the maximum Firmware Image chunk size */
      if (pArgFwDl->size_byte > MEI_FW_IMAGE_CHUNK_SIZE_BYTE)
      {
         PRN_ERR_USR_NL( MEI_DRV, MEI_DRV_PRN_LEVEL_ERR,
            ("MEI_DRV: ERROR - Firmware Image chunk size %d is too large!" MEI_DRV_CRLF,
            pArgFwDl->size_byte));

         return IFX_ERROR;
      }
   }

   /* Check current driver state. */
   if (MEI_DRV_STATE_GET(pMeiDev) != e_MEI_DRV_STATE_SW_INIT_DONE)
   {
      PRN_ERR_USR_NL( MEI_DRV, MEI_DRV_PRN_LEVEL_ERR,
            ("MEI_DRV[%02d]: invalid state (%d) for load FW image." MEI_DRV_CRLF,
              MEI_DRV_LINENUM_GET(pMeiDev), MEI_DRV_STATE_GET(pMeiDev) ));

      return -e_MEI_ERR_INVAL_STATE;
   }

   MEI_DRVOS_SemaphoreLock(&pFwDlCntrlLock);

   /* Get Image Info only from the 1st chunk*/
   if (pArgFwDl->chunk_num == 0)
   {
      /* Get FW Image Header info*/
      ret = MEI_DEV_FirmwareImageHeaderGet(
               pMeiDev, pArgFwDl->pFwImageChunk, bInternCall);

      if (ret != 0)
      {
         PRN_ERR_USR_NL( MEI_DRV, MEI_DRV_PRN_LEVEL_ERR,
               ("MEI_DRV[0x%02X]: FW Image Header Info get failed!" MEI_DRV_CRLF,
                MEI_DRV_LINENUM_GET(pMeiDev)));

         goto ERROR_MEI_IOCTL_OPT_FWDL_LOAD_IMAGE;
      }
   }

   /* Start FW download*/
   ret = MEI_VR9_StartOptFwDownload(pMeiDynCntrl, pArgFwDl, bInternCall);

   /* Finish FW download*/
   if ((ret == 0) && pArgFwDl->bLastChunk)
   {
      ret = MEI_VR9_FinishFwDownload(pMeiDev);
   }

   MEI_DRVOS_SemaphoreUnlock(&pFwDlCntrlLock);

   return ret;

ERROR_MEI_IOCTL_OPT_FWDL_LOAD_IMAGE:

   MEI_DRVOS_SemaphoreUnlock(&pFwDlCntrlLock);

   return ret;
}

/**
   Set FW xDSL/DualPort mode control.

\param
   pMeiDynCntrl - private dynamic comtrol data (per open instance)
\param
   pArgFwModeCtrl - points to the xDSL/DualPort mode control data

\return
   IFX_SUCCESS: if the FW Mode Control setting was successful.
   negative value if something went wrong.
*/
IFX_int32_t MEI_IoctlFwModeCtrlSet(
                                 MEI_DYN_CNTRL_T           *pMeiDynCntrl,
                                 IOCTL_MEI_FwModeCtrlSet_t *pArgFwModeCtrl)
{
   IFX_int32_t ret = 0;
   MEI_DEV_T *pMeiDev = pMeiDynCntrl->pMeiDev;
   MEI_FW_PORT_MODE_CONTROL_DMA32_T fwPortModeCtrl = {0};

   /* Check current driver state. */
   if (MEI_DRV_STATE_GET(pMeiDev) != e_MEI_DRV_STATE_SW_INIT_DONE)
   {
      PRN_ERR_USR_NL( MEI_DRV, MEI_DRV_PRN_LEVEL_ERR,
            ("MEI_DRV[%02d]: invalid state (%d) for setting FW mode!" MEI_DRV_CRLF,
              MEI_DRV_LINENUM_GET(pMeiDev), MEI_DRV_STATE_GET(pMeiDev) ));

      return -e_MEI_ERR_INVAL_STATE;
   }

   /* Get current FW Port Mode Control Structure*/
   ret = MEI_VR9_PortModeControlStructureCurrentGet(pMeiDev, &fwPortModeCtrl);
   if (ret != IFX_SUCCESS)
   {
      PRN_ERR_USR_NL( MEI_DRV, MEI_DRV_PRN_LEVEL_ERR,
            ("MEI_DRV[%02d]: FW Port Mode Control structure get failed!" MEI_DRV_CRLF,
              MEI_DRV_LINENUM_GET(pMeiDev) ));

      return (-e_MEI_ERR_OP_FAILED);
   }

   /* Overwrite signatures*/
   fwPortModeCtrl.signature0 = MEI_FW_IMAGE_SIGNATURE0;
   fwPortModeCtrl.signature1 = MEI_FW_IMAGE_SIGNATURE1;

   /* Set Locks*/
   fwPortModeCtrl.dualPortModeLock = pArgFwModeCtrl->bMultiLineModeLock ?
      MEI_FW_PORT_MODE_LOCK : MEI_FW_PORT_MODE_UNLOCK;
   fwPortModeCtrl.xDslModeLock     = pArgFwModeCtrl->bXdslModeLock ?
      MEI_FW_XDSL_MODE_LOCK : MEI_FW_XDSL_MODE_UNLOCK;

   /* Set Line mode (Single/Dual)*/
   switch(pArgFwModeCtrl->eMultiLineModeCurrent)
   {
   case e_MEI_MULTI_LINEMODE_NA:
      /* nothing to change*/
      break;
   case e_MEI_MULTI_LINEMODE_SINGLE:
      fwPortModeCtrl.dualPortModeCurrent = fwPortModeCtrl.dualPortModePreffered =
         MEI_FW_PORT_MODE_SINGLE;
      break;
   case e_MEI_MULTI_LINEMODE_DUAL:
      fwPortModeCtrl.dualPortModeCurrent = fwPortModeCtrl.dualPortModePreffered =
         MEI_FW_PORT_MODE_DUAL;
      break;
   default:
      PRN_ERR_USR_NL( MEI_DRV, MEI_DRV_PRN_LEVEL_ERR,
            ("MEI_DRV[%02d]: Invalid eMultiLineModePreferred=%d specified!" MEI_DRV_CRLF,
              MEI_DRV_LINENUM_GET(pMeiDev), pArgFwModeCtrl->eMultiLineModePreferred));

      return (-e_MEI_ERR_INVAL_ARG);
   }

   /* Set xDSL Mode (VDSL/ADSL)*/
   switch(pArgFwModeCtrl->eXdslModeCurrent)
   {
   case e_MEI_XDSLMODE_NA:
      /* nothing to change*/
      break;
   case e_MEI_XDSLMODE_VDSL:
      fwPortModeCtrl.xDslModeCurrent = fwPortModeCtrl.xDslModePreffered =
         MEI_FW_XDSL_MODE_VDSL;
      break;
   case e_MEI_XDSLMODE_ADSL:
      fwPortModeCtrl.xDslModeCurrent = fwPortModeCtrl.xDslModePreffered =
         MEI_FW_XDSL_MODE_ADSL;
      break;
   default:
      PRN_ERR_USR_NL( MEI_DRV, MEI_DRV_PRN_LEVEL_ERR,
            ("MEI_DRV[%02d]: Invalid eXdslModePreferred=%d specified!" MEI_DRV_CRLF,
              MEI_DRV_LINENUM_GET(pMeiDev), pArgFwModeCtrl->eXdslModePreferred));

      return (-e_MEI_ERR_INVAL_ARG);
   }

   /* Set current FW Port Mode Control Structure*/
   ret = MEI_VR9_PortModeControlStructureCurrentSet(pMeiDev, &fwPortModeCtrl);
   if (ret != IFX_SUCCESS)
   {
      PRN_ERR_USR_NL( MEI_DRV, MEI_DRV_PRN_LEVEL_ERR,
            ("MEI_DRV[%02d]: FW Port Mode Control structure set failed!" MEI_DRV_CRLF,
              MEI_DRV_LINENUM_GET(pMeiDev) ));

      return (-e_MEI_ERR_OP_FAILED);
   }

   return ret;
}

/**
   Get FW xDSL/DualPort mode control status.

\param
   pMeiDynCntrl - private dynamic comtrol data (per open instance)
\param
   pArgFwModeStat - points to the xDSL/DualPort mode control data

\return
   IFX_SUCCESS: if the FW Mode Control status get was successful.
   negative value if something went wrong.
*/
IFX_int32_t MEI_IoctlFwModeStatGet(
                                 MEI_DYN_CNTRL_T           *pMeiDynCntrl,
                                 IOCTL_MEI_FwModeStatGet_t *pArgFwModeStat)
{
   IFX_int32_t ret = 0;
   MEI_DEV_T *pMeiDev = pMeiDynCntrl->pMeiDev;
   MEI_FW_PORT_MODE_CONTROL_DMA32_T fwPortModeCtrl = {0};

   /* Get current FW Port Mode Control Structure*/
   ret = MEI_VR9_PortModeControlStructureCurrentGet(pMeiDev, &fwPortModeCtrl);
   if (ret != IFX_SUCCESS)
   {
      PRN_ERR_USR_NL( MEI_DRV, MEI_DRV_PRN_LEVEL_ERR,
            ("MEI_DRV[%02d]: FW Port Mode Control structure get failed!" MEI_DRV_CRLF,
              MEI_DRV_LINENUM_GET(pMeiDev) ));

      return (-e_MEI_ERR_OP_FAILED);
   }

   /* Check for a valid signatures*/
   if ( (fwPortModeCtrl.signature0 != MEI_FW_IMAGE_SIGNATURE0) ||
        (fwPortModeCtrl.signature1 != MEI_FW_IMAGE_SIGNATURE1))
   {
      PRN_ERR_USR_NL( MEI_DRV, MEI_DRV_PRN_LEVEL_WRN,
            ("MEI_DRV[%02d]: No valid FW Port Mode Control structure detected!" MEI_DRV_CRLF,
              MEI_DRV_LINENUM_GET(pMeiDev) ));

      pArgFwModeStat->eXdslModeCurrent = e_MEI_XDSLMODE_NA;
      pArgFwModeStat->eMultiLineModeCurrent = e_MEI_MULTI_LINEMODE_NA;
   }
   else
   {
      /* Set Current xDSL mode*/
      pArgFwModeStat->eXdslModeCurrent =
         fwPortModeCtrl.xDslModeCurrent == MEI_FW_XDSL_MODE_VDSL ? e_MEI_XDSLMODE_VDSL :
         fwPortModeCtrl.xDslModeCurrent == MEI_FW_XDSL_MODE_ADSL ? e_MEI_XDSLMODE_ADSL :
         e_MEI_XDSLMODE_NA;

      /* Set current Multi Port mode*/
      pArgFwModeStat->eMultiLineModeCurrent =
         fwPortModeCtrl.dualPortModeCurrent == MEI_FW_PORT_MODE_SINGLE ? e_MEI_MULTI_LINEMODE_SINGLE :
         fwPortModeCtrl.dualPortModeCurrent == MEI_FW_PORT_MODE_DUAL ? e_MEI_MULTI_LINEMODE_DUAL :
         e_MEI_MULTI_LINEMODE_NA;
   }

   return ret;
}

#endif   /* #if (MEI_SUPPORT_DEVICE_VR9 == 1) || (MEI_SUPPORT_DEVICE_AR9 == 1)*/

