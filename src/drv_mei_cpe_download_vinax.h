/******************************************************************************

                               Copyright (c) 2011
                            Lantiq Deutschland GmbH
                     Am Campeon 3; 85579 Neubiberg, Germany

  For licensing information, see the file 'LICENSE' in the root folder of
  this software module.

******************************************************************************/
#ifndef _DRV_MEI_CPE_DOWNLOAD_VINAX_H
#define _DRV_MEI_CPE_DOWNLOAD_VINAX_H

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

#if (MEI_SUPPORT_ROM_CODE == 1)
/* get ROM handler definitions */
#include "drv_mei_cpe_rom_handler_if.h"
#endif

/* ============================================================================
   Type definitions
   ========================================================================= */

/**
   Descibes a entry for a Memory Map table
*/
typedef struct
{
   IFX_uint32_t   startAddr;
   IFX_uint32_t   endAddr;
   IFX_boolean_t  bBootOnly;
   IFX_char_t     *pDescStr;
} MEI_MEM_MAP_T;

/**
   MEI Firmware image control data.
*/
typedef struct MEI_fw_image_cntrl_s
{
   IFX_uint32_t   imageSize_Bytes;  /** fw image size in bytes */
   IFX_uint32_t   imageCheckSum;    /** fw image checksum */
   IFX_uint32_t   imageNumOfPages;  /** fw image number of pages */
} MEI_FW_IMAGE_CNTRL_T;


/**
   Describes a single page within the firmware image.

\attention
   Bit 31 = 1 of the page size field (program and data)
   indicates that the page has to be loaded at boot time.
*/
typedef struct MEI_fw_image_page_s
{
   /** page[X] program memory: offset [bytes] within the image */
   IFX_uint32_t   codeOffset_Byte;
   /** page[X] program memory: destination addr. within the target */
   IFX_uint32_t   codeDestAddr;
   /** page[X] program memory: page size [32 bit words] */
   IFX_uint32_t   codePageSize_32Bit;

   /** page[X] data memory: offset [bytes] within the image */
   IFX_uint32_t   dataOffset_Byte;
   /** page[X] data memory: destination addr. within the target */
   IFX_uint32_t   dataDestAddr;
   /** page[X] data memory: page size [32 bit words] */
   IFX_uint32_t   dataPageSize_32Bit;
}  MEI_FW_IMAGE_PAGE_T;

/**
   Firmware image infos
*/
typedef struct MEI_fw_image_s
{
   /** points to the firmware image */
   IFX_uint8_t    *pImage;
   IFX_uint32_t   size_byte;
   IFX_boolean_t  hostOrder;
   IFX_boolean_t  forceDl;
   IFX_uint32_t   useCount;
} MEI_FW_IMAGE_T;

/**
   Firmware download control struct
*/
typedef struct MEI_fw_download_cntrl_s
{
   /** line number */
   IFX_uint8_t                line_num;
   /** points to the firmware image */
   IFX_uint8_t     *pDfeImage;
   /** size of the firmware image [byte] */
   IFX_uint32_t    size_byte;
   /** local firmware image id */
   IFX_int32_t     imageId;
   /* required informations for the ROM download DMA and CodeSwap */
   MEI_FWDL_DMACS_CONTROL_T cntrlFwDlDmaCs;
   MEI_FW_IMAGE_CNTRL_T *pImageCtrl;
   MEI_FW_IMAGE_PAGE_T  *pPageDir;
} MEI_FW_DOWNLOAD_CNTRL_T;

#endif      /* MEI_SUPPORT_DL_DMA_CS */

#ifdef __cplusplus
/* extern "C" */
}
#endif

#endif   /* #ifndef _DRV_MEI_CPE_DOWNLOAD_VINAX_H */


