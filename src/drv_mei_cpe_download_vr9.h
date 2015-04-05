/******************************************************************************

                               Copyright (c) 2011
                            Lantiq Deutschland GmbH
                     Am Campeon 3; 85579 Neubiberg, Germany

  For licensing information, see the file 'LICENSE' in the root folder of
  this software module.

******************************************************************************/
#ifndef _DRV_MEI_CPE_DOWNLOAD_VR9_H
#define _DRV_MEI_CPE_DOWNLOAD_VR9_H

/* ==========================================================================
   Description : VINAX Firmware Download definitions (ROM START).
   ========================================================================== */

#ifdef __cplusplus
extern "C"
{
#endif

/* get config */
#include "drv_mei_cpe_config.h"

/* ============================================================================
   Inlcudes
   ========================================================================= */

#include "ifx_types.h"

#if (MEI_SUPPORT_DEVICE_VR9 == 1)
#include "drv_mei_cpe_mei_vr9.h"
#else
#include "drv_mei_cpe_mei_ar9.h"
#endif

/* ==========================================================================
   Macro defs
   ========================================================================== */

#if (MEI_SUPPORT_PCI_SLAVE_FW_DOWNLOAD == 1)

# if (MEI_SUPPORT_PCI_SLAVE_ADDR_RANGE_ADTRAN == 1)
#  define MEI_PCI_SLAVE_DDR_POOL_START_ADDRESS   (0x81E00000)
#  define MEI_PCI_SLAVE_PCI_POOL_START_ADDRESS   (0x18000000)
# elif (MEI_SUPPORT_PCI_SLAVE_ADDR_RANGE_BONDING == 1)
#  define MEI_PCI_SLAVE_DDR_POOL_START_ADDRESS   (0x81C00000)
#  define MEI_PCI_SLAVE_PCI_POOL_START_ADDRESS   (0x18C00000)
# else
#  error "PCI Slave FW download address range type is not defined!"
# endif

# define MEI_PCI_SLAVE_POOL_SIZE_BYTE           (0x200000)
#endif /* #if (MEI_SUPPORT_PCI_SLAVE_FW_DOWNLOAD == 1)*/

/* VR9 FW image chunk size [bytes] */
#define MEI_FW_IMAGE_CHUNK_SIZE_BYTE            (64*1024)

#define MEI_FW_IMAGE_CHUNK_ZERO_BITS_COUNT      (5)
#define MEI_FW_IMAGE_CHUNK_OVERHEAD_SIZE_BYTE \
           (1 << MEI_FW_IMAGE_CHUNK_ZERO_BITS_COUNT)

#define MEI_FW_IMAGE_CHUNK_ADDR_MASK \
           (~(MEI_FW_IMAGE_CHUNK_OVERHEAD_SIZE_BYTE - 1))

#define MEI_FW_IMAGE_MAX_CHUNK_COUNT            MEI_TOTAL_BAR_REGISTER_COUNT

#define MEI_FW_IMAGE_DATA_CHUNK_INDEX           (15)

/* VR9 FW image header size [bytes] (including Page#0)*/
#define MEI_FW_IMAGE_HEADER_SIZE_BYTE  sizeof(MEI_FW_IMAGE_CNTRL_T)

/* VR9 FW Image maximum allowable size [bytes] */
#define MEI_FW_IMAGE_MAX_SIZE_BYTE \
   (MEI_FW_IMAGE_CHUNK_SIZE_BYTE * (MEI_FW_IMAGE_MAX_CHUNK_COUNT - 1) + \
    MEI_BAR16_SIZE_BYTE)

/* VR9 FW combined image unique Signature#0*/
#define MEI_FW_IMAGE_SIGNATURE0   (0x2468)

/* VR9 FW combined image unique Signature#1*/
#define MEI_FW_IMAGE_SIGNATURE1   (0xB11D)

/* VR9 FW Port Mode Control Structure address within ARC internal memory*/
#define MEI_FW_PORT_MODE_CONTROL_STRUCTURE_ADDR   (0x0080)

/* VR9 FW Page#3 offset in 32bit words*/
#define MEI_FW_IMAGE_PAGE3_OFFSET_32BIT   (21)

#define MEI_FW_XDSL_MODE_VDSL   (0x0)
#define MEI_FW_XDSL_MODE_ADSL   (0x1)

#define MEI_FW_PORT_MODE_SINGLE (0x0)
#define MEI_FW_PORT_MODE_DUAL   (0x1)

#define MEI_FW_XDSL_MODE_LOCK   (0x1)
#define MEI_FW_XDSL_MODE_UNLOCK (0x0)

#define MEI_FW_PORT_MODE_LOCK   (0x1)
#define MEI_FW_PORT_MODE_UNLOCK (0x0)


#define MEI_FW_BOOTLOADER_ERR_INVAL_IMAGE        (0xE1)
#define MEI_FW_BOOTLOADER_ERR_INVAL_MEMEXT_SEL   (0xE2)
#define MEI_FW_BOOTLOADER_ERR_XDMA_FAILURE       (0xE3)

/* ============================================================================
   Macros
   ========================================================================= */
#define MEI_FW_IMAGE_CHUNK_ALIGNED_SIZE_BYTE(size) \
           (size + MEI_FW_IMAGE_CHUNK_OVERHEAD_SIZE_BYTE)

#define MEI_FW_IMAGE_CHUNK_ALIGNED_ADDR_GET(addr) \
           (IFX_uint8_t*)(((((IFX_uint32_t)addr) + (MEI_FW_IMAGE_CHUNK_OVERHEAD_SIZE_BYTE-1)) & \
            MEI_FW_IMAGE_CHUNK_ADDR_MASK))

/* ============================================================================
   Type definitions
   ========================================================================= */
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
   Describes a single X (data or code) page within the firmware image.

\attention
   Bit 31 = 1 of the page size field (program and data)
   indicates that the page has to be loaded at boot time.
*/
typedef struct MEI_fw_image_pageX_s
{
   /** page[X] destination addr. within the target */
   IFX_uint32_t   destAddr;
   /** page[X] page size [32 bit words] */
   IFX_uint32_t   pageSize_32Bit;
   /** X page buffer*/
   IFX_uint32_t   *pXpage;
}  MEI_FW_IMAGE_PAGEX_T;

/**
   Describes Port Mode Control Structure.
*/
typedef struct MEI_fw_image_port_mode_control_s
{
   /**
      Offset 0, a hardcoded value of 0x2468*/
   IFX_uint16_t signature0;
   /**
      Offset 2, true/false that mode is locked by a port at the end of GHS*/
   IFX_uint8_t  dualPortModeLock;
   /**
      Offset 3, TBD */
   IFX_uint8_t  xDslModeLock;
   /**
      Offset 4, power-up default*/
   IFX_uint8_t  dualPortModePreffered;
   /**
      Offset 5, power-up default*/
   IFX_uint8_t  xDslModePreffered;
   /**
      Offset 6, being loaded, default - 0xFF*/
   IFX_uint8_t  dualPortModeCurrent;
   /**
      Offset 7, being loaded, default - 0xFF*/
   IFX_uint8_t  xDslModeCurrent;
   /**
      Offset 8, this will be used to communicate with driver if errors
      detected early in the boot process*/
   IFX_uint8_t  bootError;
   /**
      Offset 9, AFE_COLD_START = 0; AFE_WARM_START = 1*/
   IFX_uint8_t  afePowerUp;
   /**
      Offset 10, a hardcode value of 0xB11D*/
   IFX_uint16_t signature1;
   /**
      offset 12, set by the BootLoader based on info in .bin file */
   IFX_uint32_t imageOffsetSRAM;
   /**
      offset 16, TBD*/
   IFX_uint32_t bgPortSelRegValue;
   /**
      offset 20, TBD */
   IFX_uint8_t bgPort;
   /**
      offset 21, TBD*/
   IFX_uint8_t bgDuration;
   /**
      offset 22, TBD*/
   IFX_uint8_t maxBgDuration;
   /**
      offset 23; TBD*/
   IFX_uint8_t afeInitState;
}  MEI_FW_PORT_MODE_CONTROL_T;

/**
   Describes Port Mode Control Structure for 32-bit DMA transfers.
*/
typedef struct MEI_fw_image_port_mode_control_dma32_s
{
   /**
      Offset 3, TBD */
   IFX_uint8_t  xDslModeLock;
   /**
      Offset 2, true/false that mode is locked by a port at the end of GHS*/
   IFX_uint8_t  dualPortModeLock;
   /**
      Offset 0, a hardcoded value of 0x2468*/
   IFX_uint16_t signature0;
   /**
      Offset 7, being loaded, default - 0xFF*/
   IFX_uint8_t  xDslModeCurrent;
   /**
      Offset 6, being loaded, default - 0xFF*/
   IFX_uint8_t  dualPortModeCurrent;
   /**
      Offset 5, power-up default*/
   IFX_uint8_t  xDslModePreffered;
   /**
      Offset 4, power-up default*/
   IFX_uint8_t  dualPortModePreffered;
   /**
      Offset 10, a hardcode value of 0xB11D*/
   IFX_uint16_t signature1;
   /**
      Offset 9, AFE_COLD_START = 0; AFE_WARM_START = 1*/
   IFX_uint8_t  afePowerUp;
   /**
      Offset 8, this will be used to communicate with driver if errors
      detected early in the boot process*/
   IFX_uint8_t  bootError;
   /**
      offset 12, set by the BootLoader based on info in .bin file */
   IFX_uint32_t imageOffsetSRAM;
   /**
      offset 16, TBD*/
   IFX_uint32_t bgPortSelRegValue;
   /**
      offset 23; TBD*/
   IFX_uint8_t afeInitState;
   /**
      offset 22, TBD*/
   IFX_uint8_t maxBgDuration;
   /**
      offset 21, TBD*/
   IFX_uint8_t bgDuration;
   /**
      offset 20, TBD */
   IFX_uint8_t bgPort;
}  MEI_FW_PORT_MODE_CONTROL_DMA32_T;

typedef MEI_FW_PORT_MODE_CONTROL_T MEI_FW_IMAGE_PAGE0_T;

/**
   Describes xDSL FW image Page#3 (CACHE info).
*/
typedef struct MEI_fw_image_combined_page3_s
{
   IFX_uint32_t cache_offset_Byte;
   IFX_uint32_t reserved;
   IFX_uint32_t cachedRegionSize_Byte;
} MEI_FW_IMAGE_PAGE3_T;

/**
   MEI Firmware image control data.
*/
typedef struct MEI_fw_image_cntrl_s
{
   /** fw image size in bytes */
   IFX_uint32_t         imageSize_Bytes;
   /** fw image checksum */
   IFX_uint32_t         imageCheckSum;
   /** fw image number of pages */
   IFX_uint32_t         imageNumOfPages;
   /** fw image pages info */
   union
   {
      /** fw image Page#0. */
      MEI_FW_IMAGE_PAGE0_T          imagePage0;
      /** fw image Page#X*/
      MEI_FW_IMAGE_PAGE_T           imagePageX[1];
   }imagePage;
} MEI_FW_IMAGE_CNTRL_T;

typedef enum
{
   /** undefined image chunk*/
   eMEI_FW_IMAGE_CHUNK_UNDEFINED,
   /** cached image chunk*/
   eMEI_FW_IMAGE_CHUNK_CACHED,
   /** permanent data image chunk*/
   eMEI_FW_IMAGE_CHUNK_DATA,
   /** reallocatable image chunk*/
   eMEI_FW_IMAGE_CHUNK_REALLOC,
} MEI_FW_IMAGE_CHUNK_TYPE_E;

typedef struct
{
   /* FW image chunk size [byte]*/
   IFX_uint32_t              imageChunkSize_byte;
   /* FW image chunk type*/
   MEI_FW_IMAGE_CHUNK_TYPE_E eImageChunkType;
   /* Pointer to the FW image allocated chunk*/
   IFX_uint8_t               *pImageChunk_allocated;
   /* Pointer to the FW image address aligned chunk*/
   IFX_uint8_t               *pImageChunk_aligned;
   /* BARx content*/
   IFX_uint8_t               *pBARx;
} MEI_FW_IMAGE_CHUNK_CTRL_T;

#if (MEI_SUPPORT_PCI_SLAVE_FW_DOWNLOAD == 1)
typedef struct MEI_pci_slave_pool_element_s
{
   IFX_uint32_t  element_offset;
   IFX_uint32_t  element_size_byte;
   IFX_boolean_t bUsed;
   struct MEI_pci_slave_pool_element_s *pNext;
} MEI_PCI_SLAVE_POOL_ELEMENT_T;


typedef struct MEI_pci_slave_pool_s
{
   IFX_uint8_t *pPciStart;
   IFX_uint8_t *pDdrStart;
   IFX_uint32_t pool_size_byte;
   IFX_uint32_t fill_offset;
   MEI_PCI_SLAVE_POOL_ELEMENT_T Head;
} MEI_PCI_SLAVE_POOL_T;
#endif /* #if (MEI_SUPPORT_PCI_SLAVE_FW_DOWNLOAD == 1)*/

/**
   Firmware download control struct
*/
typedef struct MEI_fw_download_cntrl_s
{
   /** line number */
   IFX_uint8_t                line_num;
#if (MEI_SUPPORT_PCI_SLAVE_FW_DOWNLOAD == 1)
   /** PCI slave/master download*/
   IFX_boolean_t              bPciSlave;
   MEI_PCI_SLAVE_POOL_T       *pPool;
#endif /* #if (MEI_SUPPORT_PCI_SLAVE_FW_DOWNLOAD == 1)*/
   /** size of the firmware image [byte] */
   IFX_uint32_t               size_byte;
   /** size of the permanent CACHED region [byte] */
   IFX_uint32_t               cachedRegionSize_byte;
   /** size of external  writeable DATA region [bytes]  */
   IFX_uint32_t               dataRegionSize_Byte;
   /** Total number of swap pages*/
   IFX_uint32_t               imageNumOfPages;
   /** Default Port Mode Control Structure (extracted from the FW header)*/
   MEI_FW_PORT_MODE_CONTROL_T defaultPortModeCtrl;
   /** FW image chunk control data*/
   MEI_FW_IMAGE_CHUNK_CTRL_T  imageChunkCtrl[MEI_FW_IMAGE_MAX_CHUNK_COUNT];
} MEI_FW_DOWNLOAD_CNTRL_T;

/* ==========================================================================
   Global Variable Definitions
   ========================================================================== */


/* ============================================================================
   Exports
   ========================================================================= */

extern IFX_int32_t MEI_DEV_IoctlFirmwareDownload(
                              MEI_DYN_CNTRL_T        *pMeiDynCntrl,
                              IOCTL_MEI_fwDownLoad_t *pArgFwDl,
                              IFX_boolean_t            bInternCall);

#if (MEI_SUPPORT_PCI_SLAVE_FW_DOWNLOAD == 1)
MEI_PCI_SLAVE_POOL_T* MEI_VR9_PciSlavePoolCreate(
                                 IFX_uint8_t *pPciStart,
                                 IFX_uint8_t *pDdrStart,
                                 IFX_uint32_t pool_size_byte);

IFX_void_t MEI_VR9_PciSlavePoolDelete(
                                 MEI_PCI_SLAVE_POOL_T *pPool);
#endif /* #if (MEI_SUPPORT_PCI_SLAVE_FW_DOWNLOAD == 1)*/

#ifdef __cplusplus
/* extern "C" */
}
#endif

#endif   /* #ifndef _DRV_MEI_CPE_DOWNLOAD_VR9_H */


