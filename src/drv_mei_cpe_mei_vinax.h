#ifndef _DRV_MEI_CPE_MEI_VINAX_H
#define _DRV_MEI_CPE_MEI_VINAX_H
/******************************************************************************

                               Copyright (c) 2011
                            Lantiq Deutschland GmbH
                     Am Campeon 3; 85579 Neubiberg, Germany

  For licensing information, see the file 'LICENSE' in the root folder of
  this software module.

******************************************************************************/

/* ==========================================================================
   Description : MEI driver - MEI definitions for the VINAX device
   Remarks:
   ========================================================================== */

#ifdef __cplusplus
extern "C"
{
#endif

/* ============================================================================
   Includes
   ========================================================================= */


/* ============================================================================
   Macros
   ========================================================================= */

#ifndef __PACKED__

#if defined (__GNUC__) || defined (__GNUG__)
/* GNU C or C++ compiler */
#define __PACKED__ __attribute__ ((packed))
#elif !defined (__PACKED__)
#define __PACKED__ /* nothing */
#endif
#endif


/* ============================================================================
   Macros - Interface definitions
   ========================================================================= */

#define MEI_BIT0     (1 << 0)
#define MEI_BIT1     (1 << 1)
#define MEI_BIT2     (1 << 2)
#define MEI_BIT3     (1 << 3)
#define MEI_BIT4     (1 << 4)
#define MEI_BIT5     (1 << 5)
#define MEI_BIT6     (1 << 6)
#define MEI_BIT7     (1 << 7)
#define MEI_BIT8     (1 << 8)
#define MEI_BIT9     (1 << 9)
#define MEI_BIT10    (1 << 10)
#define MEI_BIT11    (1 << 11)
#define MEI_BIT12    (1 << 12)
#define MEI_BIT13    (1 << 13)
#define MEI_BIT14    (1 << 14)
#define MEI_BIT15    (1 << 15)


/* ============================================================================
   Macros - MEI register set
   ========================================================================= */

/** Chip Version Number Register */
#define MEI_REG_OFF_ME_VERSION         0x00
/** ARC4 to ME Interrupt Status Register */
#define MEI_REG_OFF_ME_ARC2ME_STAT     0x01
/** ARC4 to ME Interrupt Mask Register */
#define MEI_REG_OFF_ME_ARC2ME_MASK     0x02
/** Reset Control Register */
#define MEI_REG_OFF_ME_RST_CTRL        0x03
/** Configuration Register */
#define MEI_REG_OFF_ME_CONFIG          0x04
/** ME to ARC4 Interrupt Register */
#define MEI_REG_OFF_ME_ME2ARC_INT      0x05
/** ME to ARC4 Interrupt Status Register */
#define MEI_REG_OFF_ME_ME2ARC_STAT     0x06
/** Debug Decode Register */
#define MEI_REG_OFF_ME_DBG_DECODE      0x07
/** Debug Write Address Register Low */
#define MEI_REG_OFF_ME_DBG_WR_AD_LO    0x08
/** Debug Write Address Register High */
#define MEI_REG_OFF_ME_DBG_WR_AD_HI    0x09
/** Debug Read Address Register Low */
#define MEI_REG_OFF_ME_DBG_RD_AD_LO    0x0A
/** Debug Read Address Register High */
#define MEI_REG_OFF_ME_DBG_RD_AD_HI    0x0B
/** Debug Data Register Low */
#define MEI_REG_OFF_ME_DBG_DATA_LO     0x0C
/** Debug Data Register High */
#define MEI_REG_OFF_ME_DBG_DATA_HI     0x0D
/** Debug Master Register */
#define MEI_REG_OFF_ME_DBG_MASTER      0x0E
/** Clock Control Register */
#define MEI_REG_OFF_ME_CLK_CTRL        0x0F
/** Data Transfer Address Register Low  */
#define MEI_REG_OFF_ME_DX_AD_LO        0x10
/** Data Transfer Address Register High */
#define MEI_REG_OFF_ME_DX_AD_HI        0x11
/** Data Transfer Data Register */
#define MEI_REG_OFF_ME_DX_DATA         0x12
/** Data Transfer Status Register */
#define MEI_REG_OFF_ME_DX_STAT         0x13
/** General Purpose Register from ARC */
#define MEI_REG_OFF_ME_ARC_GP_STAT     0x14
/** Memory wait states allowed for data transfer accesses. */
#define MEI_REG_OFF_ME_DX_MWS          0x15

/** not used */
#define MEI_REG_OFF_NOT_USED_016       0x16
#define MEI_REG_OFF_NOT_USED_017       0x17
/** reserved for broadcast */
#define MEI_REG_OFF_RES_BCAST_018      0x18
#define MEI_REG_OFF_RES_BCAST_01A      0x1A

/** Broadcast Clock Control Register */
#define MEI_REG_OFF_BC_CLK_CTRL        0x1B
/** Broadcast ME to ARC4 Interrupt Register */
#define MEI_REG_OFF_BC_ME2ARC_INT      0x1C
/** Broadcast Data Transfer Address Register Low */
#define MEI_REG_OFF_BC_DX_AD_LO        0x1D
/** Broadcast Data Transfer Address Register High */
#define MEI_REG_OFF_BC_DX_AD_HI        0x1E
/** Broadcast Data Transfer Data Register  */
#define MEI_REG_OFF_BC_DX_DATA         0x1F

/** first MEI regsiter set offset */
#define MEI_REG_OFFSET_FIRST           0x00
/** last MEI regsiter set offset */
#define MEI_REG_OFFSET_LAST            0x1F

/** first MEI regsiter set offset not used / reserved */
#define MEI_REG_OFFSET_FIRST_FREE      0x16
/** last MEI regsiter set offset not used / reserved */
#define MEI_REG_OFFSET_LAST_FREE       0x1A



/* =============================================================
   MEI register definitions
*/
/* Definition:  Chip Version Number Register ========== */
#define MEI_ME_VERSION_REV             0x00FF
#define MEI_ME_VERSION_JTAG_REV        0xFF00

/* Definition: ARC4 to ME Interrupt Status Register === */
#define ME_ARC2ME_STAT_ARC_MSGAV       MEI_BIT0
#define ME_ARC2ME_STAT_ARC_GP_INT0     MEI_BIT1
#define ME_ARC2ME_STAT_ARC_GP_INT1     MEI_BIT2
#define ME_ARC2ME_STAT_DBG_DONE        MEI_BIT3
#define ME_ARC2ME_STAT_DBG_ERR         MEI_BIT4

/** Definition of the interrupt mask ARC to ME */
#define ME_ARC2ME_INTERRUPT_ALL        (   ME_ARC2ME_STAT_ARC_MSGAV \
                                         | ME_ARC2ME_STAT_ARC_GP_INT0 \
                                         | ME_ARC2ME_STAT_ARC_GP_INT1 \
                                         | ME_ARC2ME_STAT_DBG_DONE \
                                         | ME_ARC2ME_STAT_DBG_ERR )



/* Definition: ARC4 to ME Interrupt Mask Register ===== */
#define ME_ARC2ME_MASK_ARC_MSGAV_ENA      MEI_BIT0
#define ME_ARC2ME_MASK_ARC_GP_INT0_ENA    MEI_BIT1
#define ME_ARC2ME_MASK_ARC_GP_INT1_ENA    MEI_BIT2
#define ME_ARC2ME_MASK_DBG_DONE_ENA       MEI_BIT3
#define ME_ARC2ME_MASK_DBG_ERR_ENA        MEI_BIT4


/** Definition of the interrupt mask ARC to ME */
#define ME_ARC2ME_INTERRUPT_MASK_ALL      (   ME_ARC2ME_STAT_ARC_MSGAV \
                                            | ME_ARC2ME_STAT_ARC_GP_INT0 \
                                            | ME_ARC2ME_STAT_ARC_GP_INT1 \
                                            | ME_ARC2ME_STAT_DBG_DONE \
                                            | ME_ARC2ME_MASK_DBG_ERR_ENA )

/** Definition of the interrupt un-mask ARC to ME
   \Note the Debug Done and Debug Error will be handled via polling
*/
#define ME_ARC2ME_INTERRUPT_UNMASK_ALL    (   ME_ARC2ME_STAT_ARC_MSGAV \
                                            | ME_ARC2ME_STAT_ARC_GP_INT1 )

/*                                            | ME_ARC2ME_STAT_ARC_GP_INT0 \ */


/* Definition: Reset Control Register ================= */
#define ME_RST_CTRL_XMEM_RST           MEI_BIT0
#define ME_RST_CTRL_DSP_RST            MEI_BIT1
#define ME_RST_CTRL_XDSL_RST           MEI_BIT2
#define ME_RST_CTRL_SPI_RST            MEI_BIT3
#define ME_RST_CTRL_PER_RST            MEI_BIT4

/** reset all sub modules */
#define ME_RST_CTRL_ALL                (   ME_RST_CTRL_XMEM_RST \
                                         | ME_RST_CTRL_DSP_RST \
                                         | ME_RST_CTRL_XDSL_RST \
                                         | ME_RST_CTRL_SPI_RST \
                                         | ME_RST_CTRL_PER_RST )


/* Definition: Configuration Register ================= */
#define ME_CONFIG_INT_LEVEL            MEI_BIT0
/** Bus Master Indicator */
#define ME_CONFIG_BMSTR                MEI_BIT1
#define ME_CONFIG_CHIP_ID              MEI_BIT2 | MEI_BIT3 | MEI_BIT4 | MEI_BIT5 | MEI_BIT6
/** No data transfer access (except bulk) */
#define ME_CONFIG_NO_DX_ACC            MEI_BIT7

/* Definition: ME to ARC4 Interrupt Register ========== */
/** Mailbox Message Interrupt to ARC */
#define ME_ME2ARC_INT_ME_MSGAV         MEI_BIT0
/** General Purpose Interrupt to ARC */
#define ME_ME2ARC_INT_ME_GP_INT        MEI_BIT1
/** Code Swap Done Interrupt to ARC */
#define ME_ME2ARC_INT_ME_CS_DONE       MEI_BIT2

/* Definition: ME to ARC4 Interrupt Status Register === */
/** Mailbox Message Interrupt to ARC Status */
#define ME_ME2ARC_STAT_ME_MSGAV        MEI_BIT0
/** General Purpose Interrupt to ARC Status */
#define ME_ME2ARC_STAT_ME_GP_INT       MEI_BIT1
/** Code Swap Done Status */
#define ME_ME2ARC_STAT_ME_CS_DONE      MEI_BIT2

/* Definition: Debug Decode Register ================== */
/**
   DEBUG_DEC:
   - 00 = Auxiliary address01,
   - 10 = LD/ST address
   - 11 = Core address
*/
#define ME_DBG_DECODE_DEBUG_DEC        MEI_BIT0 | MEI_BIT1
#define ME_DBG_DECODE_DEBUG_DEC_AUX    0x0
#define ME_DBG_DECODE_DEBUG_DEC_LDST   0x2
#define ME_DBG_DECODE_DEBUG_DEC_CORE   0x3

/* Definition: Debug Master Register ================== */
/**
   HOST_MSTR:
   - If bit = 0: JTAG is master of host/debug bus.
   - If bit = 1: ME is master of host/debug bus.
*/
#define ME_DBG_MASTER_HOST_MSTR        MEI_BIT0

/**
   Definition: Data Transfer Status Register
*/
#define ME_DX_STAT_DX_ERR              MEI_BIT0


/* width of the MEI registers [16 bit] */
#define MEI_MEI_REGISTER_WIDTH    sizeof(IFX_uint16_t)

/* width of the DMA data access [16 bit] */
#define MEI_MEI_DMA_DATA_WIDTH    sizeof(IFX_uint16_t)


/* ============================================================================
   VINAX Rev1 Management Entity Interface (MEI) - register defintions
   ========================================================================= */

typedef IFX_vuint16_t MEI_MeiReg_t;
typedef IFX_uint16_t  MEI_MeiRegVal_t;

typedef struct MEI_mei_register_set_s
{
   /** [00] Chip Version Number Register */
   IFX_vuint16_t ME_VERSION;
   /** [01] ARC4 to ME Interrupt Status Register */
   IFX_vuint16_t ME_ARC2ME_STAT;
   /** [02] ARC4 to ME Interrupt Mask Register */
   IFX_vuint16_t ME_ARC2ME_MASK;
   /** [03] Reset Control Register */
   IFX_vuint16_t ME_RST_CTRL;
   /** [04] Configuration Register */
   IFX_vuint16_t ME_CONFIG;
   /** [05] ME to ARC4 Interrupt Register */
   IFX_vuint16_t ME_ME2ARC_INT;
   /** [06] ME to ARC4 Interrupt Status Register */
   IFX_vuint16_t ME_ME2ARC_STAT;
   /** [07] Debug Decode Register */
   IFX_vuint16_t ME_DBG_DECODE;
   union
   {
      /** [--] Debug Write Address Register (32 bit) */
      IFX_vuint32_t ul_VAL;
      struct
      {
         /** [08] Debug Write Address Register Low */
         IFX_vuint16_t LO;
         /** [09] Debug Write Address Register High */
         IFX_vuint16_t HI;
      } us;
   } ME_DBG_WR_AD;
   union
   {
      /** [--] Debug Read Address Register (32 bit) */
      IFX_vuint32_t ul_VAL;
      struct
      {
         /** [0A] Debug Read Address Register Low */
         IFX_vuint16_t LO;
         /** [0B] Debug Read Address Register High */
         IFX_vuint16_t HI;
      } us;
   } ME_DBG_RD_AD;
   union
   {
      /** [--] Debug Data Register (32 bit) */
      IFX_vuint32_t ul_VAL;
      struct
      {
         /** [0C] Debug Data Register Low */
         IFX_vuint16_t LO;
         /** [0D] Debug Data Register High */
         IFX_vuint16_t HI;
      } us;
   } ME_DBG_DATA;
   /** [0E] Debug Master Register */
   IFX_vuint16_t ME_DBG_MASTER;
   /** [0F] Clock Control Register */
   IFX_vuint16_t ME_CLK_CTRL;
   union
   {
      /** [--] Data Transfer Address Register (32 bit) */
      IFX_vuint32_t ul_VAL;
      struct
      {
         /** [10] Data Transfer Address Register Low */
         IFX_vuint16_t LO;
         /** [11] Data Transfer Address Register High */
         IFX_vuint16_t HI;
      } us;
   } ME_DX_AD;
   /** [12] Data Transfer Data Register  */
   IFX_vuint16_t ME_DX_DATA;
   /** [13] Data Transfer Status Register */
   IFX_vuint16_t ME_DX_STAT;
   /** [14] General Purpose Register from ARC */
   IFX_vuint16_t ME_ARC_GP_STAT;
   /** [15] Memory wait states allowed for data transfer accesses */
   IFX_vuint16_t ME_DX_MWS;
   /** [16] Unused - Reserved for regular ME use */
   IFX_vuint16_t SPARE_0X16;
   /** [17] Unused - Reserved for regular ME use */
   IFX_vuint16_t SPARE_0X17;
   /** [18] Unused - Reserved for broadcast */
   IFX_vuint16_t SPARE_0X18;
   /** [19] Unused - Reserved for broadcast */
   IFX_vuint16_t SPARE_0X19;
   /** [1A] Unused - Reserved for broadcast */
   IFX_vuint16_t SPARE_0X1A;
   /** [1B] Broadcast Clock Control Register */
   IFX_vuint16_t BC_CLK_CTRL;
   /** [1C] Broadcast ME to ARC4 Interrupt Register */
   IFX_vuint16_t BC_ME2ARC_INT;
   union
   {
      /** [--] Broadcast Data Transfer Address Register (32 bit) */
      IFX_vuint32_t ul_VAL;
      struct
      {
         /** [1D] Broadcast Data Transfer Address Register Low */
         IFX_vuint16_t LO;
         /** [1E] Broadcast Data Transfer Address Register High */
         IFX_vuint16_t HI;
      } us;
   } BC_DX_AD;
   /** Broadcast Data Transfer Data Register */
   IFX_vuint16_t BC_DX_DATA;

} __PACKED__ MEI_MEI_REG_IF_T;

typedef union
{
   MEI_MEI_REG_IF_T    regStruct;
   IFX_vuint16_t         regRaw[sizeof(MEI_MEI_REG_IF_T)/2];
} MEI_MEI_REG_IF_U; /* old MEI_MEI_REGISTER_SET_T */


#ifdef __cplusplus
/* extern "C" */
}
#endif

#endif      /* #define _DRV_MEI_CPE_MEI_VINAX_H */

