/******************************************************************************

                               Copyright (c) 2011
                            Lantiq Deutschland GmbH
                     Am Campeon 3; 85579 Neubiberg, Germany

  For licensing information, see the file 'LICENSE' in the root folder of
  this software module.

******************************************************************************/


#ifndef _VDSL2_DMTSCOPE_MSG_H_
#define _VDSL2_DMTSCOPE_MSG_H_

/** \file

*/

#ifndef __PACKED__
   #if defined (__GNUC__) || defined (__GNUG__)
      /* GNU C or C++ compiler */
      #define __PACKED__ __attribute__ ((packed))
   #else
      /* Byte alignment adjustment */
      #pragma pack(1)
      #define __PACKED__      /* nothing */
   #endif
   #define __PACKED_DEFINED__ 1
#endif

#ifndef MEI_DRV_OS_BYTE_ORDER
#error "missing byte order define, include drv_mei_cpe_os.h before"
#endif

/** @defgroup _VDSL2_DMTSCOPE_MSG_ DMT Scope
 *  @{
 */

#ifdef __cplusplus
   extern "C" {
#endif


/* ----- Include section ----- */
/* ----- Include section (End) ----- */

/* ----- Define section ----- */
/* ----- Define section (End) ----- */

/* ----- Constants Definition section ----- */
#define  CMD_SystemIF_LoopControl_NO_LOOP  0x00000000
#define  CMD_SystemIF_LoopControl_INGRESS_LOOP  0x00000001
#define  CMD_SystemIF_LoopControl_EGRESS_LOOP  0x00000002
#define  CMD_TC_LayerLoopControl_NO_LOOP  0x00000000
#define  CMD_TC_LayerLoopControl_INGRESS_LOOP  0x00000001
#define  CMD_TC_LayerLoopControl_EGRESS_LOOP  0x00000002
#define  CMD_TEST_AFE_LoopControl_NO_LOOP  0x00000000
#define  CMD_TEST_AFE_LoopControl_ALOOP  0x00000001
#define  CMD_TEST_TxControlSet_SEND_QUIET  0
#define  CMD_TEST_TxControlSet_SEND_REVERB  1
#define  CMD_TEST_TxControlSet_SEND_SEGUE  2
#define  CMD_TEST_TxControlSet_SEND_MEDLEY  3
#define  CMD_TEST_RxControlSet_MEASURE_PSD  14
#define  CMD_TEST_RxControlSet_FDQ_TRAINING  16
#define  CMD_TEST_RxControlSet_MEASURE_SNR  17
#define  CMD_TEST_RxControlSet_PGA_TRAINING  19
#define  CMD_TEST_RxPSD_MeasureModeSet_AVERAGE  0x00000000
#define  CMD_TEST_RxPSD_MeasureModeSet_PEAKHOLD  0x00000001
#define  CMD_TEST_RxPSD_MeasureModeSet_BOTTOMHOLD  0x00000002
#define  CMD_TEST_RxGainControl_DEFGAIN  0x00000000
#define  CMD_TEST_RxGainControl_MAXGAIN  0x00000001
/* ----- Constants Definition section (End) ----- */

/** Message ID for CMD_SystemIF_LoopControl */
#define CMD_SYSTEMIF_LOOPCONTROL 0x0751

/**
   The message is used to set up a loop within the TPS-TC at the system interface (for
   Utopia interface, POSPHY interface, MII interface). It is effective "per port", also
   in VINAX V2.x.
*/
typedef struct CMD_SystemIF_LoopControl CMD_SystemIF_LoopControl_t;

/** Message ID for ACK_SystemIF_LoopControl */
#define ACK_SYSTEMIF_LOOPCONTROL 0x0751

/**
   This message acknowledges the message CMD_SystemIF_LoopControl.
*/
typedef struct ACK_SystemIF_LoopControl ACK_SystemIF_LoopControl_t;

/** Message ID for CMD_TC_LayerLoopControl */
#define CMD_TC_LAYERLOOPCONTROL 0x0951

/**
   This message can be used to enable or disable the loop within the xTC block. If the
   system interface side (INGRESS_LOOP) is selected, data are looped back in the
   TC-FIFO. In case of the line-sided loop (EGRESS_LOOP) in VINAX V1.x, data are looped
   back within the ATM-OAM or MAC block instead.
   In VINAX V2.x the loop can only be switched for all ports of a die, therefor
   CMD_SystemIF_LoopControl shall be used here instead.
*/
typedef struct CMD_TC_LayerLoopControl CMD_TC_LayerLoopControl_t;

/** Message ID for ACK_TC_LayerLoopControl */
#define ACK_TC_LAYERLOOPCONTROL 0x0951

/**
   This message acknowledges the message CMD_TC_LayerLoopControl.
*/
typedef struct ACK_TC_LayerLoopControl ACK_TC_LayerLoopControl_t;

/** Message ID for CMD_TEST_AFE_LoopControl */
#define CMD_TEST_AFE_LOOPCONTROL 0x0156

/**
   This message can be used to enable or disable the (analog) loop within the Analog
   Front-End (AFE) to loop back data from the transmit to the receive part.
*/
typedef struct CMD_TEST_AFE_LoopControl CMD_TEST_AFE_LoopControl_t;

/** Message ID for ACK_TEST_AFE_LoopControl */
#define ACK_TEST_AFE_LOOPCONTROL 0x0156

/**
   This message acknowledges the message CMD_TEST_AFE_LoopControl.
   For TEST state only!
*/
typedef struct ACK_TEST_AFE_LoopControl ACK_TEST_AFE_LoopControl_t;

/** Message ID for CMD_TEST_TxControlSet */
#define CMD_TEST_TXCONTROLSET 0x0844

/**
   The message controls the transmit signal in TEST state. Each setting is valid until
   either another value is set with this message that requires the previous setting to
   be overwritten or until TEST state is left.
*/
typedef struct CMD_TEST_TxControlSet CMD_TEST_TxControlSet_t;

/** Message ID for ACK_TEST_TxControlSet */
#define ACK_TEST_TXCONTROLSET 0x0844

/**
   Acknowledgement for message CMD_TEST_TxControlSet.
*/
typedef struct ACK_TEST_TxControlSet ACK_TEST_TxControlSet_t;

/** Message ID for CMD_TEST_CarrierMaskingTxSet */
#define CMD_TEST_CARRIERMASKINGTXSET 0x0256

/**
   Masks out every 100th subcarrier starting from an arbitrary index number 1...99.
   The carrier-mask is applied to signals in the frequency domain ("Send REVERB" and
   "Send MEDLEY"). The signal must be activated before!
*/
typedef struct CMD_TEST_CarrierMaskingTxSet CMD_TEST_CarrierMaskingTxSet_t;

/** Message ID for ACK_TEST_CarrierMaskingTxSet */
#define ACK_TEST_CARRIERMASKINGTXSET 0x0256

/**
   Acknowledgement for message CMD_TEST_CarrierMaskingTxSet.
*/
typedef struct ACK_TEST_CarrierMaskingTxSet ACK_TEST_CarrierMaskingTxSet_t;

/** Message ID for CMD_TEST_RxControlSet */
#define CMD_TEST_RXCONTROLSET 0x0944

/**
   The message triggers measurements of the receive signal.
*/
typedef struct CMD_TEST_RxControlSet CMD_TEST_RxControlSet_t;

/** Message ID for ACK_TEST_RxControlSet */
#define ACK_TEST_RXCONTROLSET 0x0944

/**
   Acknowledgement for message CMD_TEST_RxControlSet.
*/
typedef struct ACK_TEST_RxControlSet ACK_TEST_RxControlSet_t;

/** Message ID for CMD_TEST_RxPSD_TableEntriesGet */
#define CMD_TEST_RXPSD_TABLEENTRIESGET 0x5403

/**
   The message requests information about the receive PSD per subcarrier available at
   the near-end side, which means for upstream direction at the CO side and for
   downstream direction at the CPE. It is the hosts responsibility to select the tone
   indices accordingly.
*/
typedef struct CMD_TEST_RxPSD_TableEntriesGet CMD_TEST_RxPSD_TableEntriesGet_t;

/** Message ID for ACK_TEST_RxPSD_TableEntriesGet */
#define ACK_TEST_RXPSD_TABLEENTRIESGET 0x5403

/**
   Returns information about the receive PSD per subcarrier available at the near-end
   side, which means for upstream direction at the CO side and for downstream direction
   at the CPE.
*/
typedef struct ACK_TEST_RxPSD_TableEntriesGet ACK_TEST_RxPSD_TableEntriesGet_t;

/** Message ID for CMD_TEST_RxPSD_Calibrate */
#define CMD_TEST_RXPSD_CALIBRATE 0x0356

/**
   Sets the board specific calibration factor necessary to calculate the absolute PSD
   value per subcarrier.
   Attention: The command needs to be applied only once after power-up for a
   calibration value determined according to the sequence described
   below ("Getting the calibration value:"). Applying the command a
   second time requires another determination of the calibration value
   too, because the shift is always relative to the current values.
*/
typedef struct CMD_TEST_RxPSD_Calibrate CMD_TEST_RxPSD_Calibrate_t;

/** Message ID for ACK_TEST_RxPSD_Calibrate */
#define ACK_TEST_RXPSD_CALIBRATE 0x0356

/**
   Acknowledgement to CMD_TEST_RxPSD_Calibrate.
*/
typedef struct ACK_TEST_RxPSD_Calibrate ACK_TEST_RxPSD_Calibrate_t;

/** Message ID for CMD_TEST_RxPSD_MeasureModeSet */
#define CMD_TEST_RXPSD_MEASUREMODESET 0x0456

/**
   Configures options for the measurement of the PSD value per subcarrier.
*/
typedef struct CMD_TEST_RxPSD_MeasureModeSet CMD_TEST_RxPSD_MeasureModeSet_t;

/** Message ID for ACK_TEST_RxPSD_MeasureModeSet */
#define ACK_TEST_RXPSD_MEASUREMODESET 0x0456

/**
   Acknowledgement to CMD_TEST_RxPSD_MeasureModeSet.
*/
typedef struct ACK_TEST_RxPSD_MeasureModeSet ACK_TEST_RxPSD_MeasureModeSet_t;

/** Message ID for CMD_TEST_RxGainControl */
#define CMD_TEST_RXGAINCONTROL 0x0556

/**
   Sets the gains in the receive path (AGC, ACE, PREFI).
*/
typedef struct CMD_TEST_RxGainControl CMD_TEST_RxGainControl_t;

/** Message ID for ACK_TEST_RxGainControl */
#define ACK_TEST_RXGAINCONTROL 0x0556

/**
   Acknowledgement to CMD_TEST_RxGainControl.
*/
typedef struct ACK_TEST_RxGainControl ACK_TEST_RxGainControl_t;

/** Message ID for CMD_TEST_SRAM_Test */
#define CMD_TEST_SRAM_TEST 0x0616

/**
   Triggers an SRAM test as described above and requests the test results.
*/
typedef struct CMD_TEST_SRAM_Test CMD_TEST_SRAM_Test_t;

/** Message ID for ACK_TEST_SRAM_Test */
#define ACK_TEST_SRAM_TEST 0x0616

/**
   Acknowledgement to a CMD_TEST_SRAM_Test command. This is a just formal
   acknowledgement without data. Data will be provided with NFC_TEST_SRAM_Test later on
   after finishing the test.
*/
typedef struct ACK_TEST_SRAM_Test ACK_TEST_SRAM_Test_t;

/** Message ID for NFC_TEST_SRAM_Test */
#define NFC_TEST_SRAM_TEST 0x0616

/**
   This autonomous message provides the result of the memory test triggered by
   CMD_TEST_SRAM_Test.
*/
typedef struct NFC_TEST_SRAM_Test NFC_TEST_SRAM_Test_t;

/**
   The message is used to set up a loop within the TPS-TC at the system interface (for
   Utopia interface, POSPHY interface, MII interface). It is effective "per port", also
   in VINAX V2.x.
*/
struct CMD_SystemIF_LoopControl
{
#if MEI_DRV_OS_BYTE_ORDER == MEI_DRV_OS_BIG_ENDIAN
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Link Number */
   IFX_uint32_t LinkNo;
   /** Control */
   IFX_uint32_t Control;
#else
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Link Number */
   IFX_uint32_t LinkNo;
   /** Control */
   IFX_uint32_t Control;
#endif
} __PACKED__ ;


/**
   This message acknowledges the message CMD_SystemIF_LoopControl.
*/
struct ACK_SystemIF_LoopControl
{
#if MEI_DRV_OS_BYTE_ORDER == MEI_DRV_OS_BIG_ENDIAN
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
#else
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
#endif
} __PACKED__ ;


/**
   This message can be used to enable or disable the loop within the xTC block. If the
   system interface side (INGRESS_LOOP) is selected, data are looped back in the
   TC-FIFO. In case of the line-sided loop (EGRESS_LOOP) in VINAX V1.x, data are looped
   back within the ATM-OAM or MAC block instead.
   In VINAX V2.x the loop can only be switched for all ports of a die, therefor
   CMD_SystemIF_LoopControl shall be used here instead.
*/
struct CMD_TC_LayerLoopControl
{
#if MEI_DRV_OS_BYTE_ORDER == MEI_DRV_OS_BIG_ENDIAN
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Link Number */
   IFX_uint32_t LinkNo;
   /** Control */
   IFX_uint32_t Control;
#else
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Link Number */
   IFX_uint32_t LinkNo;
   /** Control */
   IFX_uint32_t Control;
#endif
} __PACKED__ ;


/**
   This message acknowledges the message CMD_TC_LayerLoopControl.
*/
struct ACK_TC_LayerLoopControl
{
#if MEI_DRV_OS_BYTE_ORDER == MEI_DRV_OS_BIG_ENDIAN
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
#else
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
#endif
} __PACKED__ ;


/**
   This message can be used to enable or disable the (analog) loop within the Analog
   Front-End (AFE) to loop back data from the transmit to the receive part.
*/
struct CMD_TEST_AFE_LoopControl
{
#if MEI_DRV_OS_BYTE_ORDER == MEI_DRV_OS_BIG_ENDIAN
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** AFE Loop Control */
   IFX_uint32_t loopControl;
#else
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** AFE Loop Control */
   IFX_uint32_t loopControl;
#endif
} __PACKED__ ;


/**
   This message acknowledges the message CMD_TEST_AFE_LoopControl.
   For TEST state only!
*/
struct ACK_TEST_AFE_LoopControl
{
#if MEI_DRV_OS_BYTE_ORDER == MEI_DRV_OS_BIG_ENDIAN
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
#else
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
#endif
} __PACKED__ ;


/**
   The message controls the transmit signal in TEST state. Each setting is valid until
   either another value is set with this message that requires the previous setting to
   be overwritten or until TEST state is left.
*/
struct CMD_TEST_TxControlSet
{
#if MEI_DRV_OS_BYTE_ORDER == MEI_DRV_OS_BIG_ENDIAN
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** TEST State’s Transmit Signal Control */
   IFX_uint16_t TxControl;
#else
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** TEST State’s Transmit Signal Control */
   IFX_uint16_t TxControl;
#endif
} __PACKED__ ;


/**
   Acknowledgement for message CMD_TEST_TxControlSet.
*/
struct ACK_TEST_TxControlSet
{
#if MEI_DRV_OS_BYTE_ORDER == MEI_DRV_OS_BIG_ENDIAN
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
#else
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
#endif
} __PACKED__ ;


/**
   Masks out every 100th subcarrier starting from an arbitrary index number 1...99.
   The carrier-mask is applied to signals in the frequency domain ("Send REVERB" and
   "Send MEDLEY"). The signal must be activated before!
*/
struct CMD_TEST_CarrierMaskingTxSet
{
#if MEI_DRV_OS_BYTE_ORDER == MEI_DRV_OS_BIG_ENDIAN
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** First Masked Tone */
   IFX_uint32_t MaskTone0;
#else
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** First Masked Tone */
   IFX_uint32_t MaskTone0;
#endif
} __PACKED__ ;


/**
   Acknowledgement for message CMD_TEST_CarrierMaskingTxSet.
*/
struct ACK_TEST_CarrierMaskingTxSet
{
#if MEI_DRV_OS_BYTE_ORDER == MEI_DRV_OS_BIG_ENDIAN
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
#else
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
#endif
} __PACKED__ ;


/**
   The message triggers measurements of the receive signal.
*/
struct CMD_TEST_RxControlSet
{
#if MEI_DRV_OS_BYTE_ORDER == MEI_DRV_OS_BIG_ENDIAN
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** TEST State’s Receive Control */
   IFX_uint16_t RxControl;
#else
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** TEST State’s Receive Control */
   IFX_uint16_t RxControl;
#endif
} __PACKED__ ;


/**
   Acknowledgement for message CMD_TEST_RxControlSet.
*/
struct ACK_TEST_RxControlSet
{
#if MEI_DRV_OS_BYTE_ORDER == MEI_DRV_OS_BIG_ENDIAN
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
#else
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
#endif
} __PACKED__ ;


/**
   The message requests information about the receive PSD per subcarrier available at
   the near-end side, which means for upstream direction at the CO side and for
   downstream direction at the CPE. It is the hosts responsibility to select the tone
   indices accordingly.
*/
struct CMD_TEST_RxPSD_TableEntriesGet
{
#if MEI_DRV_OS_BYTE_ORDER == MEI_DRV_OS_BIG_ENDIAN
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
#else
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
#endif
} __PACKED__ ;


/**
   Returns information about the receive PSD per subcarrier available at the near-end
   side, which means for upstream direction at the CO side and for downstream direction
   at the CPE.
*/
struct ACK_TEST_RxPSD_TableEntriesGet
{
#if MEI_DRV_OS_BYTE_ORDER == MEI_DRV_OS_BIG_ENDIAN
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Receive PSD */
   IFX_uint16_t PSDps[128];
#else
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Receive PSD */
   IFX_uint16_t PSDps[128];
#endif
} __PACKED__ ;


/**
   Sets the board specific calibration factor necessary to calculate the absolute PSD
   value per subcarrier.
   Attention: The command needs to be applied only once after power-up for a
   calibration value determined according to the sequence described
   below ("Getting the calibration value:"). Applying the command a
   second time requires another determination of the calibration value
   too, because the shift is always relative to the current values.
*/
struct CMD_TEST_RxPSD_Calibrate
{
#if MEI_DRV_OS_BYTE_ORDER == MEI_DRV_OS_BIG_ENDIAN
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** RxPSD Calibration Value */
   IFX_uint32_t calibration;
#else
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** RxPSD Calibration Value */
   IFX_uint32_t calibration;
#endif
} __PACKED__ ;


/**
   Acknowledgement to CMD_TEST_RxPSD_Calibrate.
*/
struct ACK_TEST_RxPSD_Calibrate
{
#if MEI_DRV_OS_BYTE_ORDER == MEI_DRV_OS_BIG_ENDIAN
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
#else
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
#endif
} __PACKED__ ;


/**
   Configures options for the measurement of the PSD value per subcarrier.
*/
struct CMD_TEST_RxPSD_MeasureModeSet
{
#if MEI_DRV_OS_BYTE_ORDER == MEI_DRV_OS_BIG_ENDIAN
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** RxPSD Measurement Mode */
   IFX_uint32_t MeasureMode;
   /** Number of Frames */
   IFX_uint32_t numOfFrames;
#else
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** RxPSD Measurement Mode */
   IFX_uint32_t MeasureMode;
   /** Number of Frames */
   IFX_uint32_t numOfFrames;
#endif
} __PACKED__ ;


/**
   Acknowledgement to CMD_TEST_RxPSD_MeasureModeSet.
*/
struct ACK_TEST_RxPSD_MeasureModeSet
{
#if MEI_DRV_OS_BYTE_ORDER == MEI_DRV_OS_BIG_ENDIAN
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
#else
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
#endif
} __PACKED__ ;


/**
   Sets the gains in the receive path (AGC, ACE, PREFI).
*/
struct CMD_TEST_RxGainControl
{
#if MEI_DRV_OS_BYTE_ORDER == MEI_DRV_OS_BIG_ENDIAN
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Rx Gain Level */
   IFX_uint32_t RxGainLevel;
#else
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Rx Gain Level */
   IFX_uint32_t RxGainLevel;
#endif
} __PACKED__ ;


/**
   Acknowledgement to CMD_TEST_RxGainControl.
*/
struct ACK_TEST_RxGainControl
{
#if MEI_DRV_OS_BYTE_ORDER == MEI_DRV_OS_BIG_ENDIAN
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
#else
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
#endif
} __PACKED__ ;


/**
   Triggers an SRAM test as described above and requests the test results.
*/
struct CMD_TEST_SRAM_Test
{
#if MEI_DRV_OS_BYTE_ORDER == MEI_DRV_OS_BIG_ENDIAN
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Maximum Test Address */
   IFX_uint32_t maxAddr;
#else
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Maximum Test Address */
   IFX_uint32_t maxAddr;
#endif
} __PACKED__ ;


/**
   Acknowledgement to a CMD_TEST_SRAM_Test command. This is a just formal
   acknowledgement without data. Data will be provided with NFC_TEST_SRAM_Test later on
   after finishing the test.
*/
struct ACK_TEST_SRAM_Test
{
#if MEI_DRV_OS_BYTE_ORDER == MEI_DRV_OS_BIG_ENDIAN
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
#else
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
#endif
} __PACKED__ ;


/**
   This autonomous message provides the result of the memory test triggered by
   CMD_TEST_SRAM_Test.
*/
struct NFC_TEST_SRAM_Test
{
#if MEI_DRV_OS_BYTE_ORDER == MEI_DRV_OS_BIG_ENDIAN
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Maximum Test Address */
   IFX_uint32_t maxAddr;
   /** SRAM Test Result */
   IFX_uint32_t Result;
   /** SRAM Fail Address */
   IFX_uint32_t FailAddr;
   /** WriteValue */
   IFX_uint32_t WriteValue;
   /** ReadValue */
   IFX_uint32_t ReadValue;
   /** XDMA Error */
   IFX_uint32_t XdmaError;
#else
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Maximum Test Address */
   IFX_uint32_t maxAddr;
   /** SRAM Test Result */
   IFX_uint32_t Result;
   /** SRAM Fail Address */
   IFX_uint32_t FailAddr;
   /** WriteValue */
   IFX_uint32_t WriteValue;
   /** ReadValue */
   IFX_uint32_t ReadValue;
   /** XDMA Error */
   IFX_uint32_t XdmaError;
#endif
} __PACKED__ ;


#ifdef __cplusplus
}
#endif

#ifdef __PACKED_DEFINED__
   #if !(defined (__GNUC__) || defined (__GNUG__))
      #pragma pack()
   #endif
   #undef __PACKED_DEFINED__
#endif /* __PACKED_DEFINED__ */

/** @} */
#endif

