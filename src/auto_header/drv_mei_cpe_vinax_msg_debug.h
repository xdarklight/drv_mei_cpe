/******************************************************************************

                               Copyright (c) 2011
                            Lantiq Deutschland GmbH
                     Am Campeon 3; 85579 Neubiberg, Germany

  For licensing information, see the file 'LICENSE' in the root folder of
  this software module.

******************************************************************************/


#ifndef _VDSL2_FWDES_DEBUGMSG_H_
#define _VDSL2_FWDES_DEBUGMSG_H_

/** \file
   This chapter describes the messages which are used for debug purposes.
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


/** @defgroup _VDSL2_FWDES_DEBUGMSG_ Debug Messages
 *  @{
 */

#ifdef __cplusplus
   extern "C" {
#endif


/* ----- Include section ----- */
/* ----- Include section (End) ----- */

/* ----- Define section ----- */
/* ----- Define section (End) ----- */

/**
   Constant Values for Mask_1
*/
/**  */
#define Mask_1_LOW 0x0000 0000
/**  */
#define Mask_1_HIGH 0xFFFF FFFD


/**
   Constant Values for Mask_2
*/
/**  */
#define Mask_2_LOW 0xAA00 0000
/**  */
#define Mask_2_HIGH 0xFFFF FFFF


/**
   Constant Values for Mask_3
*/
/**  */
#define Mask_3_ADSL_LOW 0x0000 007F
/**  */
#define Mask_3_XDSL2_LOW 0x0000 0192
/**  */
#define Mask_3_HIGH 0xFFFF FFFF


/**
   Constant Values for Mask_4
*/
/**  */
#define Mask_4_ADSL_LOW 0x0000 007F
/**  */
#define Mask_4_XDSL2_LOW 0x0000 C192
/**  */
#define Mask_4_HIGH 0x0000 FFFF


/**
   Constant Values for Mask_5 (VDSL SOC)
*/
/**  */
#define Mask_5_LOW 0x0000 0000
/**  */
#define Mask_5_VDSL_HIGH 0xCFFF CFFF
/** Just formal, the parameter is not used in ADSL/ADSL2 ("don’t care") */
#define Mask_5_ADSL1_2_HIGH 0x0000 0000


/* ----- Constants Definition section ----- */
#define  CMD_DBG_TC_BlockSelect_xTC  0x00000000
#define  CMD_DBG_TC_BlockSelect_Alphaeus  0x00000001
#define  CMD_DBG_EFM_StatsThreshSet_DISABLE  0x00000000
#define  CMD_DBG_EFM_StatsThreshSet_ENABLE  0x00000001
#define  CMD_DBG_EFM_StatsThreshSet_DO_NOTHING  0x0000FFFF
#define  CMD_DBG_CounterBlockRead_COUNTER_MEM1  0x00000001
#define  CMD_DBG_CounterBlockRead_COUNTER_MEM2  0x00000002
#define  NFC_DBG_CounterBlockRead_COUNTER_MEM1  0x00000001
#define  NFC_DBG_CounterBlockRead_COUNTER_MEM2  0x00000002
#define  CMD_DBG_DebugVisMuxConfigure_TX_IFFT_OUT  0
#define  CMD_DBG_DebugVisMuxConfigure_VFDF_RX_TDQ_IN  1
#define  CMD_DBG_DebugVisMuxConfigure_VFDF_RX_TDQ_OUT  2
#define  CMD_DBG_DebugVisMuxConfigure_RX_FDQ_OUT  3
#define  CMD_DBG_DebugVisMuxConfigure_DSP_DATA  4
#define  CMD_DBG_DebugVisMuxConfigure_FDF_RX_TDQ_IN  5
#define  CMD_DBG_DebugVisMuxConfigure_FDF_RX_TDQ_OUT  6
#define  CMD_DBG_DebugVisMuxConfigure_NO_FLAG  0
#define  CMD_DBG_DebugVisMuxConfigure_DSP_FLAG  1
#define  CMD_DBG_DebugVisMuxConfigure_FT_TX_FRAME  2
#define  CMD_DBG_DebugVisMuxConfigure_FT_RX_FRAME  3
#define  CMD_DBG_DebugVisMuxConfigure_QT_TX_GO  4
#define  CMD_DBG_DebugVisMuxConfigure_DBGVIS_SEO  5
#define  CMD_DBG_DebugVisFormatSet_EVEN  0x0
#define  CMD_DBG_DebugVisFormatSet_ODD  0x1
#define  CMD_DBG_DebugVisFormatSet_ALL  0x0
#define  CMD_DBG_DebugVisFormatSet_EVEN_ODD  0x1
#define  CMD_DBG_DebugVisFormatSet_WORD  0x0
#define  CMD_DBG_DebugVisFormatSet_BYTE  0x1
#define  CMD_DBG_DebugVisDspStart_RX_FRAME_START  0
#define  CMD_DBG_DebugVisDspStart_RX_QT_DONE  1
#define  CMD_DBG_DebugVisDspStart_RX_FC_DONE  2
#define  CMD_DBG_DebugVisDspStart_TX_FRAME_START  3
#define  CMD_DBG_DebugVisDspStart_RX_TIMER_DONE  4
#define  CMD_DBG_DebugVisDspStart_TX_TIMER_DONE  5
#define  CMD_DBG_DebugVisDspStart_TX_IFFT_DONE  6
#define  CMD_DBG_DebugVisDspStart_RX_FFT_DONE  7
#define  CMD_DBG_DebugVisDspStart_TX_FC_DONE  8
#define  CMD_DBG_DebugVisDspStart_TX_QT_DONE  9
#define  CMD_DBG_DebugVisDspStart_TX_PARR_DONE  10
#define  CMD_DBG_AFE_BandwidthSelect_PROF30A  0x00000000
#define  CMD_DBG_AFE_BandwidthSelect_PROF17  0x00000001
#define  CMD_DBG_AFE_BandwidthSelect_PROF12X  0x00000002
#define  CMD_DBG_AFE_BandwidthSelect_PROF8X  0x00000003
#define  CMD_DBG_xPTC_MessageTunnel_PP0  0
#define  CMD_DBG_xPTC_MessageTunnel_PP1  1
#define  ACK_DBG_xPTC_MessageTunnel_PP0  0
#define  ACK_DBG_xPTC_MessageTunnel_PP1  1
#define  EVT_DBG_DebugStream_NEXT_FRAGMENT  0
#define  EVT_DBG_DebugStream_FIRST_FRAGMENT  1
#define  EVT_DBG_DebugStream_LAST_FRAGMENT  2
#define  EVT_DBG_DebugStream_FULL_STREAM  3
/* ----- Constants Definition section (End) ----- */

/** Message ID for CMD_DBG_MemMapRead */
#define CMD_DBG_MEMMAPREAD 0xA033

/**
   This command requests the content of the address contained as parameter.
*/
typedef struct CMD_DBG_MemMapRead CMD_DBG_MemMapRead_t;

/** Message ID for ACK_DBG_MemMapRead */
#define ACK_DBG_MEMMAPREAD 0xA033

/**
   Acknowledgement carrying the info requested by CMD_DBG_MemMapRead (result value of
   one read access).
*/
typedef struct ACK_DBG_MemMapRead ACK_DBG_MemMapRead_t;

/** Message ID for CMD_DBG_MemMapWrite */
#define CMD_DBG_MEMMAPWRITE 0xA173

/**
   The command writes a configurable value to a single arbitrary address.
*/
typedef struct CMD_DBG_MemMapWrite CMD_DBG_MemMapWrite_t;

/** Message ID for ACK_DBG_MemMapWrite */
#define ACK_DBG_MEMMAPWRITE 0xA173

/**
   Acknowledgement to a CMD_DBG_MemMapWrite command.
*/
typedef struct ACK_DBG_MemMapWrite ACK_DBG_MemMapWrite_t;

/** Message ID for CMD_DBG_AuxRegisterRead */
#define CMD_DBG_AUXREGISTERREAD 0xA233

/**
   This command requests the content an the auxiliary register with the address
   contained as parameter.
*/
typedef struct CMD_DBG_AuxRegisterRead CMD_DBG_AuxRegisterRead_t;

/** Message ID for ACK_DBG_AuxRegisterRead */
#define ACK_DBG_AUXREGISTERREAD 0xA233

/**
   The message acknowledges CMD_DBG_AuxRegisterRead and delivers the requested data.
*/
typedef struct ACK_DBG_AuxRegisterRead ACK_DBG_AuxRegisterRead_t;

/** Message ID for CMD_DBG_AuxRegisterWrite */
#define CMD_DBG_AUXREGISTERWRITE 0xA373

/**
   This message is sent from the host to write to any auxiliary register in the
   controller subsystem.
*/
typedef struct CMD_DBG_AuxRegisterWrite CMD_DBG_AuxRegisterWrite_t;

/** Message ID for ACK_DBG_AuxRegisterWrite */
#define ACK_DBG_AUXREGISTERWRITE 0xA373

/**
   Acknowledgement to a CMD_DBG_AuxRegisterWrite command.
*/
typedef struct ACK_DBG_AuxRegisterWrite ACK_DBG_AuxRegisterWrite_t;

/** Message ID for CMD_DBG_TC_BlockSelect */
#define CMD_DBG_TC_BLOCKSELECT 0x0473

/**
   This message is used to select the TC layer block. It is either Infineon xTC or
   Aware TC Alphaeus. This message has to be sent during the initialization phase
   before training. The default setting is Infineon xTC.
*/
typedef struct CMD_DBG_TC_BlockSelect CMD_DBG_TC_BlockSelect_t;

/** Message ID for ACK_DBG_TC_BlockSelect */
#define ACK_DBG_TC_BLOCKSELECT 0x0473

/**
   This message acknowledges the message CMD_DBG_TC_BlockSelect.
*/
typedef struct ACK_DBG_TC_BlockSelect ACK_DBG_TC_BlockSelect_t;

/** Message ID for CMD_DBG_TC_LayerLoopControl */
#define CMD_DBG_TC_LAYERLOOPCONTROL 0x0173

/**
   This message can be used to enable or disable the loop within the xTC block at the
   TC layer. It is applicable just if the Infineon TC block was selected. (see
   CMD_DBG_TC_BlockSelect)
*/
typedef struct CMD_DBG_TC_LayerLoopControl CMD_DBG_TC_LayerLoopControl_t;

/** Message ID for ACK_DBG_TC_LayerLoopControl */
#define ACK_DBG_TC_LAYERLOOPCONTROL 0x0173

/**
   This message acknowledges the message CMD_DBG_TC_LayerLoopControl.
*/
typedef struct ACK_DBG_TC_LayerLoopControl ACK_DBG_TC_LayerLoopControl_t;

/** Message ID for CMD_DBG_UTOPIA_WatchdogControl */
#define CMD_DBG_UTOPIA_WATCHDOGCONTROL 0xB273

/**
   Switches on/off an additional "keep-alive" supervision mechanism for the UTOPIA
   interface.
*/
typedef struct CMD_DBG_UTOPIA_WatchdogControl CMD_DBG_UTOPIA_WatchdogControl_t;

/** Message ID for ACK_DBG_UTOPIA_WatchdogControl */
#define ACK_DBG_UTOPIA_WATCHDOGCONTROL 0xB273

/**
   Acknowledgement to a CMD_DBG_UTOPIA_WatchdogControl command.
*/
typedef struct ACK_DBG_UTOPIA_WatchdogControl ACK_DBG_UTOPIA_WatchdogControl_t;

/** Message ID for CMD_DBG_WatchdogControl */
#define CMD_DBG_WATCHDOGCONTROL 0xB373

/**
   Switches on/off the HW watchdog by affecting timer T2 of the processor subsystem.
*/
typedef struct CMD_DBG_WatchdogControl CMD_DBG_WatchdogControl_t;

/** Message ID for ACK_DBG_WatchdogControl */
#define ACK_DBG_WATCHDOGCONTROL 0xB373

/**
   Acknowledgement to a CMD_DBG_WatchdogControl command.
*/
typedef struct ACK_DBG_WatchdogControl ACK_DBG_WatchdogControl_t;

/** Message ID for CMD_DBG_EFM_StatsThreshSet */
#define CMD_DBG_EFM_STATSTHRESHSET 0x2073

/**
   The message enables and configures the threshold values for 5 supported EFM-counters
   and one register inside the xTC_ModemMonitor. If any of these configured thresholds
   is exceeded within a 15-min supervision period, an autonomous message
   ALM_DBG_EFM_StatsThresholdHit is generated. Each counter has its own supervision
   period that starts with threshold setting.
*/
typedef struct CMD_DBG_EFM_StatsThreshSet CMD_DBG_EFM_StatsThreshSet_t;

/** Message ID for ACK_DBG_EFM_StatsThreshSet */
#define ACK_DBG_EFM_STATSTHRESHSET 0x2073

/**
   Acknowledgement to a CMD_DBG_EFM_StatsThreshSet. It contains no payload.
*/
typedef struct ACK_DBG_EFM_StatsThreshSet ACK_DBG_EFM_StatsThreshSet_t;

/** Message ID for ALM_DBG_EFM_StatsThresholdHit */
#define ALM_DBG_EFM_STATSTHRESHOLDHIT 0x2133

/**
   This autonomous message is generated when a threshold value is exceeded for any of
   the EFM-Debug-Counters with enabled threshold supervision (see
   CMD_DBG_EFM_StatsThreshSet). It contains the counter values for all exceeded
   thresholds for the current 15-min supervision period. All other counter parameters
   are zero. (Parameters are the same as in CMD_DBG_EFM_StatsThreshSet, but values
   might be different.)
*/
typedef struct ALM_DBG_EFM_StatsThresholdHit ALM_DBG_EFM_StatsThresholdHit_t;

/** Message ID for CMD_DBG_CounterBlockRead */
#define CMD_DBG_COUNTERBLOCKREAD 0x1033

/**
   The message requests a complete counter block from counter memory. The execution of
   the message is implemented in a non-time-critical task. The acknowledgement
   ACK_DBG_CounterBlockRead is a just formal immediate response without data. The
   requested data will be delivered afterwards with NFC_DBG_CounterBlockRead.
*/
typedef struct CMD_DBG_CounterBlockRead CMD_DBG_CounterBlockRead_t;

/** Message ID for ACK_DBG_CounterBlockRead */
#define ACK_DBG_COUNTERBLOCKREAD 0x1033

/**
   Acknowledgement to a CMD_DBG_CounterBlockRead command. This is a just formal
   acknowledgement without data. Data will be provided afterwards with
   NFC_DBG_CounterBlockRead.
*/
typedef struct ACK_DBG_CounterBlockRead ACK_DBG_CounterBlockRead_t;

/** Message ID for NFC_DBG_CounterBlockRead */
#define NFC_DBG_COUNTERBLOCKREAD 0x1033

/**
   This autonomous message delivers the data requested by CMD_DBG_CounterBlockRead.
*/
typedef struct NFC_DBG_CounterBlockRead NFC_DBG_CounterBlockRead_t;

/** Message ID for CMD_DBG_DebugVisMuxConfigure */
#define CMD_DBG_DEBUGVISMUXCONFIGURE 0x4073

/**
   Selects the data source for the Debug Visibility Port.
*/
typedef struct CMD_DBG_DebugVisMuxConfigure CMD_DBG_DebugVisMuxConfigure_t;

/** Message ID for ACK_DBG_DebugVisMuxConfigure */
#define ACK_DBG_DEBUGVISMUXCONFIGURE 0x4073

/**
   Acknowledgement to a CMD_DBG_DebugVisMuxConfigure command.
*/
typedef struct ACK_DBG_DebugVisMuxConfigure ACK_DBG_DebugVisMuxConfigure_t;

/** Message ID for CMD_DBG_DebugVisFormatSet */
#define CMD_DBG_DEBUGVISFORMATSET 0x4173

/**
   Configures the format of the output data on the Debug Visibility Port.
*/
typedef struct CMD_DBG_DebugVisFormatSet CMD_DBG_DebugVisFormatSet_t;

/** Message ID for ACK_DBG_DebugVisFormatSet */
#define ACK_DBG_DEBUGVISFORMATSET 0x4173

/**
   Acknowledgement to a CMD_DBG_DebugVisFormatSet command.
*/
typedef struct ACK_DBG_DebugVisFormatSet ACK_DBG_DebugVisFormatSet_t;

/** Message ID for CMD_DBG_DebugVisDummyValSet */
#define CMD_DBG_DEBUGVISDUMMYVALSET 0x4273

/**
   Controls the use of dummy value replacement on the Debug Visibility Port.
*/
typedef struct CMD_DBG_DebugVisDummyValSet CMD_DBG_DebugVisDummyValSet_t;

/** Message ID for ACK_DBG_DebugVisDummyValSet */
#define ACK_DBG_DEBUGVISDUMMYVALSET 0x4273

/**
   Acknowledgement to a CMD_DBG_DebugVisDummyValSet command.
*/
typedef struct ACK_DBG_DebugVisDummyValSet ACK_DBG_DebugVisDummyValSet_t;

/** Message ID for CMD_DBG_DebugVisCoreStart */
#define CMD_DBG_DEBUGVISCORESTART 0x4373

/**
   Starts the data acquisition from the selected hardware port. The data source of the
   Debug Visibility Port must not be configured as DSP_DATA, any other value is allowed
   (see CMD_DBG_DebugVisMuxConfigure, parameter DataSelect).
*/
typedef struct CMD_DBG_DebugVisCoreStart CMD_DBG_DebugVisCoreStart_t;

/** Message ID for ACK_DBG_DebugVisCoreStart */
#define ACK_DBG_DEBUGVISCORESTART 0x4373

/**
   Acknowledgement to a CMD_DBG_DebugVisCoreStart command.
*/
typedef struct ACK_DBG_DebugVisCoreStart ACK_DBG_DebugVisCoreStart_t;

/** Message ID for CMD_DBG_DebugVisDspStart */
#define CMD_DBG_DEBUGVISDSPSTART 0x4473

/**
   Starts the data acquisition of data written to the Debug Visibility Port by the DFE
   controller. The data source of the Debug Visibility Port must be configured as
   DSP_DATA. (see CMD_DBG_DebugVisMuxConfigure, parameter DataSelect).
*/
typedef struct CMD_DBG_DebugVisDspStart CMD_DBG_DebugVisDspStart_t;

/** Message ID for ACK_DBG_DebugVisDspStart */
#define ACK_DBG_DEBUGVISDSPSTART 0x4473

/**
   Acknowledgement to a CMD_DBG_DebugVisDspStart command.
*/
typedef struct ACK_DBG_DebugVisDspStart ACK_DBG_DebugVisDspStart_t;

/** Message ID for CMD_DBG_DebugVisStop */
#define CMD_DBG_DEBUGVISSTOP 0x4573

/**
   Stops the data acquisition on Debug Visibility Port.
*/
typedef struct CMD_DBG_DebugVisStop CMD_DBG_DebugVisStop_t;

/** Message ID for ACK_DBG_DebugVisStop */
#define ACK_DBG_DEBUGVISSTOP 0x4573

/**
   Acknowledgement to a CMD_DBG_DebugVisStop command.
*/
typedef struct ACK_DBG_DebugVisStop ACK_DBG_DebugVisStop_t;

/** Message ID for CMD_DBG_AFE_Read */
#define CMD_DBG_AFE_READ 0xA433

/**
   The command reads any AFE register.
*/
typedef struct CMD_DBG_AFE_Read CMD_DBG_AFE_Read_t;

/** Message ID for ACK_DBG_AFE_Read */
#define ACK_DBG_AFE_READ 0xA433

/**
   Acknowledge to a CMD_DBG_AFE_Read command. The acknowledge is just a formal one (to
   not block the host), and data are contained in a subsequent NFC_DBG_AFE_Read.
*/
typedef struct ACK_DBG_AFE_Read ACK_DBG_AFE_Read_t;

/** Message ID for NFC_DBG_AFE_Read */
#define NFC_DBG_AFE_READ 0xA433

/**
   Autonomous message delivering the content of the register requested by
   CMD_DBG_AFE_Read command.
*/
typedef struct NFC_DBG_AFE_Read NFC_DBG_AFE_Read_t;

/** Message ID for CMD_DBG_AFE_Write */
#define CMD_DBG_AFE_WRITE 0xA573

/**
   This messages writes a register inside the AFE.
*/
typedef struct CMD_DBG_AFE_Write CMD_DBG_AFE_Write_t;

/** Message ID for ACK_DBG_AFE_Write */
#define ACK_DBG_AFE_WRITE 0xA573

/**
   This acknowledge to CMD_DBG_AFE_Write is just a formal one (to not block the host),
   and success is confirmed with a subsequent NFC_DBG_AFE_Write.
*/
typedef struct ACK_DBG_AFE_Write ACK_DBG_AFE_Write_t;

/** Message ID for NFC_DBG_AFE_Write */
#define NFC_DBG_AFE_WRITE 0xA573

/**
   Autonomous message confirming a CMD_DBG_AFE_Write command after a formal
   ACK_DBG_AFE_Write.
*/
typedef struct NFC_DBG_AFE_Write NFC_DBG_AFE_Write_t;

/** Message ID for CMD_DBG_AFE_BandwidthSelect */
#define CMD_DBG_AFE_BANDWIDTHSELECT 0x0773

/**
   This message selects the maximum utilized AFE bandwidth by selecting a profile
   according to the VDSL2 bandplan definition.
*/
typedef struct CMD_DBG_AFE_BandwidthSelect CMD_DBG_AFE_BandwidthSelect_t;

/** Message ID for ACK_DBG_AFE_BandwidthSelect */
#define ACK_DBG_AFE_BANDWIDTHSELECT 0x0773

/**
   Acknowledgement to a CMD_DBG_AFE_BandwidthSelect command.
*/
typedef struct ACK_DBG_AFE_BandwidthSelect ACK_DBG_AFE_BandwidthSelect_t;

/** Message ID for CMD_DBG_ErrorGenerationTimeRxSet */
#define CMD_DBG_ERRORGENERATIONTIMERXSET 0xB173

/**
   Generates errors of several error types in receive direction for a configurable
   period of time. The error generation can be enabled/disabled individually.
*/
typedef struct CMD_DBG_ErrorGenerationTimeRxSet CMD_DBG_ErrorGenerationTimeRxSet_t;

/** Message ID for ACK_DBG_ErrorGenerationTimeRxSet */
#define ACK_DBG_ERRORGENERATIONTIMERXSET 0xB173

/**
   Generates errors of several error types in receive direction for a configurable
   period of time. The error generation can be enabled/disabled individually.
*/
typedef struct ACK_DBG_ErrorGenerationTimeRxSet ACK_DBG_ErrorGenerationTimeRxSet_t;

/** Message ID for CMD_DBG_ARC_MailboxLoopback */
#define CMD_DBG_ARC_MAILBOXLOOPBACK 0xC073

/**
   This message requests the payload to be looped back with the Acknowledgment by the
   ARC mailbox.
*/
typedef struct CMD_DBG_ARC_MailboxLoopback CMD_DBG_ARC_MailboxLoopback_t;

/** Message ID for ACK_DBG_ARC_MailboxLoopback */
#define ACK_DBG_ARC_MAILBOXLOOPBACK 0xC073

/**
   Acknowledgement to CMD_DBG_ARC_MailboxLoopback looping back its payload.
*/
typedef struct ACK_DBG_ARC_MailboxLoopback ACK_DBG_ARC_MailboxLoopback_t;

/** Message ID for CMD_DBG_xPTC_MessageTunnel */
#define CMD_DBG_XPTC_MESSAGETUNNEL 0xC173

/**
   The message payload starting from Parameter 3 is simply forwarded from the ARC to
   the PP32 addressed with Parameter 2.
*/
typedef struct CMD_DBG_xPTC_MessageTunnel CMD_DBG_xPTC_MessageTunnel_t;

/** Message ID for ACK_DBG_xPTC_MessageTunnel */
#define ACK_DBG_XPTC_MESSAGETUNNEL 0xC173

/**
   Acknowledgement to CMD_DBG_xPTC_MessageTunnel.
*/
typedef struct ACK_DBG_xPTC_MessageTunnel ACK_DBG_xPTC_MessageTunnel_t;

/** Message ID for CMD_DBG_ARC_HaltControl */
#define CMD_DBG_ARC_HALTCONTROL 0xA673

/**
   The ARC can be halted on certain configurable conditions. The message
   enables/disables this possibility and configures the trigger conditions. To disable
   the feature, all triggers in Parameter 2 must be disabled.
*/
typedef struct CMD_DBG_ARC_HaltControl CMD_DBG_ARC_HaltControl_t;

/** Message ID for ACK_DBG_ARC_HaltControl */
#define ACK_DBG_ARC_HALTCONTROL 0xA673

/**
   Acknowledgement to CMD_DBG_ARC_HaltControl.
*/
typedef struct ACK_DBG_ARC_HaltControl ACK_DBG_ARC_HaltControl_t;

/** Message ID for ALM_DBG_ARC_Halt */
#define ALM_DBG_ARC_HALT 0xA733

/**
   The message indicates that the ARC has been halted due to a matching trigger
   condition as configured with CMD_DBG_ARC_HaltControl.
   After the occurrence of this ALM, debug data are to be retrieved via the MEI
   interfaceI.
*/
typedef struct ALM_DBG_ARC_Halt ALM_DBG_ARC_Halt_t;

/** Message ID for CMD_DBG_MIPS_StatusGet */
#define CMD_DBG_MIPS_STATUSGET 0xA833

/**
   This command requests MIPS status information (for this port).
*/
typedef struct CMD_DBG_MIPS_StatusGet CMD_DBG_MIPS_StatusGet_t;

/** Message ID for ACK_DBG_MIPS_StatusGet */
#define ACK_DBG_MIPS_STATUSGET 0xA833

/**
   Acknowledgement carrying the MIPS status info requested by CMD_DBG_MIPS_StatusGet.
*/
typedef struct ACK_DBG_MIPS_StatusGet ACK_DBG_MIPS_StatusGet_t;

/** Message ID for CMD_DBG_DebugStreamControl */
#define CMD_DBG_DEBUGSTREAMCONTROL 0xBA73

/**
   Enables/Disables the output of so-called "debug streams" with additional debug
   information (see also EVT_DBG_DebugStream).
*/
typedef struct CMD_DBG_DebugStreamControl CMD_DBG_DebugStreamControl_t;

/** Message ID for ACK_DBG_DebugStreamControl */
#define ACK_DBG_DEBUGSTREAMCONTROL 0xBA73

/**
   Acknowledgement for CMD_DBG_DebugStreamControl.
*/
typedef struct ACK_DBG_DebugStreamControl ACK_DBG_DebugStreamControl_t;

/** Message ID for CMD_DBG_DebugStreamConfigure */
#define CMD_DBG_DEBUGSTREAMCONFIGURE 0xBB73

/**
   Writes a bit mask to configure which messages are output in the debug stream.The
   mask parameters constitute a 160-bit mask for enabling different sub-streams that
   will contribute to the over-all debug-stream. All masks have to be sent at once. A
   pre-defined set of masks shall be used only (see Table25 to Table29). The bit
   position in the bitmask corresponds to the subtype number of the debug-(sub)stream
   according to Table30.
*/
typedef struct CMD_DBG_DebugStreamConfigure CMD_DBG_DebugStreamConfigure_t;

/** Message ID for ACK_DBG_DebugStreamConfigure */
#define ACK_DBG_DEBUGSTREAMCONFIGURE 0xBB73

/**
   Acknowledgement for CMD_DBG_DebugStreamConfigure.
*/
typedef struct ACK_DBG_DebugStreamConfigure ACK_DBG_DebugStreamConfigure_t;

/** Message ID for EVT_DBG_DebugStream */
#define EVT_DBG_DEBUGSTREAM 0xBC33

/**
   Provides debug information as configured with CMD_DBG_DebugStreamConfigure. The EVTs
   are generated only if streaming was enabled by CMD_DBG_DebugStreamControl. One EVT
   can contain a whole debug substream or only a fragment (see parameter SOF_EOF). For
   overflow situations a corresponding flag ("overflowPre") and a stream counter are
   contained.
   Note: The debug streams are queued in a debug FIFO and then moved to the host-IF
   mailbox (if bigger than the mailbox size, then in fragments). If a debug
   stream does not fit into the FIFO because it is too full, it is discarded
   completely and the overflow flag is set in the last fragment of the
   preceeding message. A stream is either delivered to the host completely or
   discarded completely, not just single fragments of it.
*/
typedef struct EVT_DBG_DebugStream EVT_DBG_DebugStream_t;

/**
   This command requests the content of the address contained as parameter.
*/
struct CMD_DBG_MemMapRead
{
#if MEI_DRV_OS_BYTE_ORDER == MEI_DRV_OS_BIG_ENDIAN
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Address */
   IFX_uint32_t Address;
#else
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Address */
   IFX_uint32_t Address;
#endif
} __PACKED__ ;


/**
   Acknowledgement carrying the info requested by CMD_DBG_MemMapRead (result value of
   one read access).
*/
struct ACK_DBG_MemMapRead
{
#if MEI_DRV_OS_BYTE_ORDER == MEI_DRV_OS_BIG_ENDIAN
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Address */
   IFX_uint32_t Address;
   /** ReadValue */
   IFX_uint32_t ReadValue;
#else
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Address */
   IFX_uint32_t Address;
   /** ReadValue */
   IFX_uint32_t ReadValue;
#endif
} __PACKED__ ;


/**
   The command writes a configurable value to a single arbitrary address.
*/
struct CMD_DBG_MemMapWrite
{
#if MEI_DRV_OS_BYTE_ORDER == MEI_DRV_OS_BIG_ENDIAN
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Address */
   IFX_uint32_t Address;
   /** WriteValue */
   IFX_uint32_t WriteValue;
#else
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Address */
   IFX_uint32_t Address;
   /** WriteValue */
   IFX_uint32_t WriteValue;
#endif
} __PACKED__ ;


/**
   Acknowledgement to a CMD_DBG_MemMapWrite command.
*/
struct ACK_DBG_MemMapWrite
{
#if MEI_DRV_OS_BYTE_ORDER == MEI_DRV_OS_BIG_ENDIAN
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Address */
   IFX_uint32_t Address;
#else
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Address */
   IFX_uint32_t Address;
#endif
} __PACKED__ ;


/**
   This command requests the content an the auxiliary register with the address
   contained as parameter.
*/
struct CMD_DBG_AuxRegisterRead
{
#if MEI_DRV_OS_BYTE_ORDER == MEI_DRV_OS_BIG_ENDIAN
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Register Number */
   IFX_uint32_t RegNo;
#else
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Register Number */
   IFX_uint32_t RegNo;
#endif
} __PACKED__ ;


/**
   The message acknowledges CMD_DBG_AuxRegisterRead and delivers the requested data.
*/
struct ACK_DBG_AuxRegisterRead
{
#if MEI_DRV_OS_BYTE_ORDER == MEI_DRV_OS_BIG_ENDIAN
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Register Number */
   IFX_uint32_t RegNo;
   /** Value */
   IFX_uint32_t Value;
#else
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Register Number */
   IFX_uint32_t RegNo;
   /** Value */
   IFX_uint32_t Value;
#endif
} __PACKED__ ;


/**
   This message is sent from the host to write to any auxiliary register in the
   controller subsystem.
*/
struct CMD_DBG_AuxRegisterWrite
{
#if MEI_DRV_OS_BYTE_ORDER == MEI_DRV_OS_BIG_ENDIAN
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Address */
   IFX_uint32_t Address;
   /** Value */
   IFX_uint32_t Value;
#else
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Address */
   IFX_uint32_t Address;
   /** Value */
   IFX_uint32_t Value;
#endif
} __PACKED__ ;


/**
   Acknowledgement to a CMD_DBG_AuxRegisterWrite command.
*/
struct ACK_DBG_AuxRegisterWrite
{
#if MEI_DRV_OS_BYTE_ORDER == MEI_DRV_OS_BIG_ENDIAN
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Address */
   IFX_uint32_t Address;
#else
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Address */
   IFX_uint32_t Address;
#endif
} __PACKED__ ;


/**
   This message is used to select the TC layer block. It is either Infineon xTC or
   Aware TC Alphaeus. This message has to be sent during the initialization phase
   before training. The default setting is Infineon xTC.
*/
struct CMD_DBG_TC_BlockSelect
{
#if MEI_DRV_OS_BYTE_ORDER == MEI_DRV_OS_BIG_ENDIAN
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** TC Block */
   IFX_uint32_t TC_Block;
#else
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** TC Block */
   IFX_uint32_t TC_Block;
#endif
} __PACKED__ ;


/**
   This message acknowledges the message CMD_DBG_TC_BlockSelect.
*/
struct ACK_DBG_TC_BlockSelect
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
   This message can be used to enable or disable the loop within the xTC block at the
   TC layer. It is applicable just if the Infineon TC block was selected. (see
   CMD_DBG_TC_BlockSelect)
*/
struct CMD_DBG_TC_LayerLoopControl
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
   This message acknowledges the message CMD_DBG_TC_LayerLoopControl.
*/
struct ACK_DBG_TC_LayerLoopControl
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
   Switches on/off an additional "keep-alive" supervision mechanism for the UTOPIA
   interface.
*/
struct CMD_DBG_UTOPIA_WatchdogControl
{
#if MEI_DRV_OS_BYTE_ORDER == MEI_DRV_OS_BIG_ENDIAN
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** UTOPIA Watchdog Control */
   IFX_uint32_t Control;
#else
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** UTOPIA Watchdog Control */
   IFX_uint32_t Control;
#endif
} __PACKED__ ;


/**
   Acknowledgement to a CMD_DBG_UTOPIA_WatchdogControl command.
*/
struct ACK_DBG_UTOPIA_WatchdogControl
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
   Switches on/off the HW watchdog by affecting timer T2 of the processor subsystem.
*/
struct CMD_DBG_WatchdogControl
{
#if MEI_DRV_OS_BYTE_ORDER == MEI_DRV_OS_BIG_ENDIAN
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** HW Watchdog Control */
   IFX_uint32_t Control;
#else
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** HW Watchdog Control */
   IFX_uint32_t Control;
#endif
} __PACKED__ ;


/**
   Acknowledgement to a CMD_DBG_WatchdogControl command.
*/
struct ACK_DBG_WatchdogControl
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
   The message enables and configures the threshold values for 5 supported EFM-counters
   and one register inside the xTC_ModemMonitor. If any of these configured thresholds
   is exceeded within a 15-min supervision period, an autonomous message
   ALM_DBG_EFM_StatsThresholdHit is generated. Each counter has its own supervision
   period that starts with threshold setting.
*/
struct CMD_DBG_EFM_StatsThreshSet
{
#if MEI_DRV_OS_BYTE_ORDER == MEI_DRV_OS_BIG_ENDIAN
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Slice number */
   IFX_uint32_t Slice;
   /** 10P/2B TC CRC error register */
   IFX_uint32_t Counter1_Th;
   /** 10P/2B TPS-TC coding violations counter */
   IFX_uint32_t Counter2_Th;
   /** 10P/2B TC indications register */
   IFX_uint32_t Counter3_Th;
   /** HDLC CRC error register */
   IFX_uint32_t Counter4_Th;
   /** MAC CRC error register */
   IFX_uint32_t Counter5_Th;
   /** MAC CRC error register */
   IFX_uint32_t Counter6_Th;
#else
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Slice number */
   IFX_uint32_t Slice;
   /** 10P/2B TC CRC error register */
   IFX_uint32_t Counter1_Th;
   /** 10P/2B TPS-TC coding violations counter */
   IFX_uint32_t Counter2_Th;
   /** 10P/2B TC indications register */
   IFX_uint32_t Counter3_Th;
   /** HDLC CRC error register */
   IFX_uint32_t Counter4_Th;
   /** MAC CRC error register */
   IFX_uint32_t Counter5_Th;
   /** MAC CRC error register */
   IFX_uint32_t Counter6_Th;
#endif
} __PACKED__ ;


/**
   Acknowledgement to a CMD_DBG_EFM_StatsThreshSet. It contains no payload.
*/
struct ACK_DBG_EFM_StatsThreshSet
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
   This autonomous message is generated when a threshold value is exceeded for any of
   the EFM-Debug-Counters with enabled threshold supervision (see
   CMD_DBG_EFM_StatsThreshSet). It contains the counter values for all exceeded
   thresholds for the current 15-min supervision period. All other counter parameters
   are zero. (Parameters are the same as in CMD_DBG_EFM_StatsThreshSet, but values
   might be different.)
*/
struct ALM_DBG_EFM_StatsThresholdHit
{
#if MEI_DRV_OS_BYTE_ORDER == MEI_DRV_OS_BIG_ENDIAN
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Slice number */
   IFX_uint32_t Slice;
   /** 10P/2B TC CRC error register */
   IFX_uint32_t Counter1;
   /** 10P/2B TPS-TC coding violations counter */
   IFX_uint32_t Counter2;
   /** 10P/2B TC indications register */
   IFX_uint32_t Counter3;
   /** HDLC CRC error register */
   IFX_uint32_t Counter4;
   /** MAC CRC error register */
   IFX_uint32_t Counter5;
   /** MAC CRC error register */
   IFX_uint32_t Counter6;
#else
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Slice number */
   IFX_uint32_t Slice;
   /** 10P/2B TC CRC error register */
   IFX_uint32_t Counter1;
   /** 10P/2B TPS-TC coding violations counter */
   IFX_uint32_t Counter2;
   /** 10P/2B TC indications register */
   IFX_uint32_t Counter3;
   /** HDLC CRC error register */
   IFX_uint32_t Counter4;
   /** MAC CRC error register */
   IFX_uint32_t Counter5;
   /** MAC CRC error register */
   IFX_uint32_t Counter6;
#endif
} __PACKED__ ;


/**
   The message requests a complete counter block from counter memory. The execution of
   the message is implemented in a non-time-critical task. The acknowledgement
   ACK_DBG_CounterBlockRead is a just formal immediate response without data. The
   requested data will be delivered afterwards with NFC_DBG_CounterBlockRead.
*/
struct CMD_DBG_CounterBlockRead
{
#if MEI_DRV_OS_BYTE_ORDER == MEI_DRV_OS_BIG_ENDIAN
   /** Index (=Offset) */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** CntrBlock */
   IFX_uint32_t CntrBlock;
   /** Slice number */
   IFX_uint32_t Slice;
#else
   /** Index (=Offset) */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** CntrBlock */
   IFX_uint32_t CntrBlock;
   /** Slice number */
   IFX_uint32_t Slice;
#endif
} __PACKED__ ;


/**
   Acknowledgement to a CMD_DBG_CounterBlockRead command. This is a just formal
   acknowledgement without data. Data will be provided afterwards with
   NFC_DBG_CounterBlockRead.
*/
struct ACK_DBG_CounterBlockRead
{
#if MEI_DRV_OS_BYTE_ORDER == MEI_DRV_OS_BIG_ENDIAN
   /** Index (=Offset) */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
#else
   /** Index (=Offset) */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
#endif
} __PACKED__ ;


/**
   This autonomous message delivers the data requested by CMD_DBG_CounterBlockRead.
*/
struct NFC_DBG_CounterBlockRead
{
#if MEI_DRV_OS_BYTE_ORDER == MEI_DRV_OS_BIG_ENDIAN
   /** Index (=Offset) */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** CntrBlock */
   IFX_uint32_t CntrBlock;
   /** Slice number */
   IFX_uint32_t Slice;
   /** CounterValue */
   IFX_uint32_t CounterValue[62];
#else
   /** Index (=Offset) */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** CntrBlock */
   IFX_uint32_t CntrBlock;
   /** Slice number */
   IFX_uint32_t Slice;
   /** CounterValue */
   IFX_uint32_t CounterValue[62];
#endif
} __PACKED__ ;


/**
   Selects the data source for the Debug Visibility Port.
*/
struct CMD_DBG_DebugVisMuxConfigure
{
#if MEI_DRV_OS_BYTE_ORDER == MEI_DRV_OS_BIG_ENDIAN
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** DataSelect */
   IFX_uint32_t DataSelect;
   /** FlagSelect */
   IFX_uint32_t FlagSelect;
#else
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** DataSelect */
   IFX_uint32_t DataSelect;
   /** FlagSelect */
   IFX_uint32_t FlagSelect;
#endif
} __PACKED__ ;


/**
   Acknowledgement to a CMD_DBG_DebugVisMuxConfigure command.
*/
struct ACK_DBG_DebugVisMuxConfigure
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
   Configures the format of the output data on the Debug Visibility Port.
*/
struct CMD_DBG_DebugVisFormatSet
{
#if MEI_DRV_OS_BYTE_ORDER == MEI_DRV_OS_BIG_ENDIAN
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Reserved */
   IFX_uint32_t Res02 : 28;
   /** EnableSelectToggle */
   IFX_uint32_t EnableSelToggle : 1;
   /** EvenOddSelect */
   IFX_uint32_t EvenOddSel : 1;
   /** EvenOddMode */
   IFX_uint32_t EvenOddMode : 1;
   /** DataWidth */
   IFX_uint32_t DataWidth : 1;
#else
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** DataWidth */
   IFX_uint32_t DataWidth : 1;
   /** EvenOddMode */
   IFX_uint32_t EvenOddMode : 1;
   /** EvenOddSelect */
   IFX_uint32_t EvenOddSel : 1;
   /** EnableSelectToggle */
   IFX_uint32_t EnableSelToggle : 1;
   /** Reserved */
   IFX_uint32_t Res02 : 28;
#endif
} __PACKED__ ;


/**
   Acknowledgement to a CMD_DBG_DebugVisFormatSet command.
*/
struct ACK_DBG_DebugVisFormatSet
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
   Controls the use of dummy value replacement on the Debug Visibility Port.
*/
struct CMD_DBG_DebugVisDummyValSet
{
#if MEI_DRV_OS_BYTE_ORDER == MEI_DRV_OS_BIG_ENDIAN
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Enable Dummy Value replacement */
   IFX_uint32_t EnableDummy;
   /** Dummy Value */
   IFX_uint32_t DummyValue;
   /** Replace Value */
   IFX_uint32_t ReplaceValue;
#else
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Enable Dummy Value replacement */
   IFX_uint32_t EnableDummy;
   /** Dummy Value */
   IFX_uint32_t DummyValue;
   /** Replace Value */
   IFX_uint32_t ReplaceValue;
#endif
} __PACKED__ ;


/**
   Acknowledgement to a CMD_DBG_DebugVisDummyValSet command.
*/
struct ACK_DBG_DebugVisDummyValSet
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
   Starts the data acquisition from the selected hardware port. The data source of the
   Debug Visibility Port must not be configured as DSP_DATA, any other value is allowed
   (see CMD_DBG_DebugVisMuxConfigure, parameter DataSelect).
*/
struct CMD_DBG_DebugVisCoreStart
{
#if MEI_DRV_OS_BYTE_ORDER == MEI_DRV_OS_BIG_ENDIAN
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Data Count */
   IFX_uint32_t DataCount;
#else
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Data Count */
   IFX_uint32_t DataCount;
#endif
} __PACKED__ ;


/**
   Acknowledgement to a CMD_DBG_DebugVisCoreStart command.
*/
struct ACK_DBG_DebugVisCoreStart
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
   Starts the data acquisition of data written to the Debug Visibility Port by the DFE
   controller. The data source of the Debug Visibility Port must be configured as
   DSP_DATA. (see CMD_DBG_DebugVisMuxConfigure, parameter DataSelect).
*/
struct CMD_DBG_DebugVisDspStart
{
#if MEI_DRV_OS_BYTE_ORDER == MEI_DRV_OS_BIG_ENDIAN
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Memory Location */
   IFX_uint32_t MemLoc;
   /** Trigger */
   IFX_uint32_t Trigger;
   /** Count */
   IFX_uint32_t Count;
#else
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Memory Location */
   IFX_uint32_t MemLoc;
   /** Trigger */
   IFX_uint32_t Trigger;
   /** Count */
   IFX_uint32_t Count;
#endif
} __PACKED__ ;


/**
   Acknowledgement to a CMD_DBG_DebugVisDspStart command.
*/
struct ACK_DBG_DebugVisDspStart
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
   Stops the data acquisition on Debug Visibility Port.
*/
struct CMD_DBG_DebugVisStop
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
   Acknowledgement to a CMD_DBG_DebugVisStop command.
*/
struct ACK_DBG_DebugVisStop
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
   The command reads any AFE register.
*/
struct CMD_DBG_AFE_Read
{
#if MEI_DRV_OS_BYTE_ORDER == MEI_DRV_OS_BIG_ENDIAN
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Address */
   IFX_uint32_t Address;
#else
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Address */
   IFX_uint32_t Address;
#endif
} __PACKED__ ;


/**
   Acknowledge to a CMD_DBG_AFE_Read command. The acknowledge is just a formal one (to
   not block the host), and data are contained in a subsequent NFC_DBG_AFE_Read.
*/
struct ACK_DBG_AFE_Read
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
   Autonomous message delivering the content of the register requested by
   CMD_DBG_AFE_Read command.
*/
struct NFC_DBG_AFE_Read
{
#if MEI_DRV_OS_BYTE_ORDER == MEI_DRV_OS_BIG_ENDIAN
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Address */
   IFX_uint32_t Address;
   /** ReadValue */
   IFX_uint32_t ReadValue;
#else
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Address */
   IFX_uint32_t Address;
   /** ReadValue */
   IFX_uint32_t ReadValue;
#endif
} __PACKED__ ;


/**
   This messages writes a register inside the AFE.
*/
struct CMD_DBG_AFE_Write
{
#if MEI_DRV_OS_BYTE_ORDER == MEI_DRV_OS_BIG_ENDIAN
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Address */
   IFX_uint32_t Address;
   /** WriteValue */
   IFX_uint32_t WriteValue;
#else
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Address */
   IFX_uint32_t Address;
   /** WriteValue */
   IFX_uint32_t WriteValue;
#endif
} __PACKED__ ;


/**
   This acknowledge to CMD_DBG_AFE_Write is just a formal one (to not block the host),
   and success is confirmed with a subsequent NFC_DBG_AFE_Write.
*/
struct ACK_DBG_AFE_Write
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
   Autonomous message confirming a CMD_DBG_AFE_Write command after a formal
   ACK_DBG_AFE_Write.
*/
struct NFC_DBG_AFE_Write
{
#if MEI_DRV_OS_BYTE_ORDER == MEI_DRV_OS_BIG_ENDIAN
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Address */
   IFX_uint32_t Address;
#else
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Address */
   IFX_uint32_t Address;
#endif
} __PACKED__ ;


/**
   This message selects the maximum utilized AFE bandwidth by selecting a profile
   according to the VDSL2 bandplan definition.
*/
struct CMD_DBG_AFE_BandwidthSelect
{
#if MEI_DRV_OS_BYTE_ORDER == MEI_DRV_OS_BIG_ENDIAN
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Profile */
   IFX_uint32_t Profile;
#else
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Profile */
   IFX_uint32_t Profile;
#endif
} __PACKED__ ;


/**
   Acknowledgement to a CMD_DBG_AFE_BandwidthSelect command.
*/
struct ACK_DBG_AFE_BandwidthSelect
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
   Generates errors of several error types in receive direction for a configurable
   period of time. The error generation can be enabled/disabled individually.
*/
struct CMD_DBG_ErrorGenerationTimeRxSet
{
#if MEI_DRV_OS_BYTE_ORDER == MEI_DRV_OS_BIG_ENDIAN
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Reserved */
   IFX_uint32_t Res02 : 30;
   /** Enable Bit1 */
   IFX_uint32_t E1 : 1;
   /** Enable Bit0 */
   IFX_uint32_t E0 : 1;
   /** OOS Error Period for PTM, BC0 */
   IFX_uint32_t OOS_TimeBC0;
   /** OOS Error Period for PTM, BC1 */
   IFX_uint32_t OOS_TimeBC1;
#else
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Enable Bit0 */
   IFX_uint32_t E0 : 1;
   /** Enable Bit1 */
   IFX_uint32_t E1 : 1;
   /** Reserved */
   IFX_uint32_t Res02 : 30;
   /** OOS Error Period for PTM, BC0 */
   IFX_uint32_t OOS_TimeBC0;
   /** OOS Error Period for PTM, BC1 */
   IFX_uint32_t OOS_TimeBC1;
#endif
} __PACKED__ ;


/**
   Generates errors of several error types in receive direction for a configurable
   period of time. The error generation can be enabled/disabled individually.
*/
struct ACK_DBG_ErrorGenerationTimeRxSet
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
   This message requests the payload to be looped back with the Acknowledgment by the
   ARC mailbox.
*/
struct CMD_DBG_ARC_MailboxLoopback
{
#if MEI_DRV_OS_BYTE_ORDER == MEI_DRV_OS_BIG_ENDIAN
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Data */
   IFX_uint32_t data[64];
#else
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Data */
   IFX_uint32_t data[64];
#endif
} __PACKED__ ;


/**
   Acknowledgement to CMD_DBG_ARC_MailboxLoopback looping back its payload.
*/
struct ACK_DBG_ARC_MailboxLoopback
{
#if MEI_DRV_OS_BYTE_ORDER == MEI_DRV_OS_BIG_ENDIAN
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Data */
   IFX_uint32_t data[64];
#else
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Data */
   IFX_uint32_t data[64];
#endif
} __PACKED__ ;


/**
   The message payload starting from Parameter 3 is simply forwarded from the ARC to
   the PP32 addressed with Parameter 2.
*/
struct CMD_DBG_xPTC_MessageTunnel
{
#if MEI_DRV_OS_BYTE_ORDER == MEI_DRV_OS_BIG_ENDIAN
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** PP32 selection */
   IFX_uint32_t PP_select;
   /** xPTC Message */
   IFX_uint32_t PP_msgIn[63];
#else
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** PP32 selection */
   IFX_uint32_t PP_select;
   /** xPTC Message */
   IFX_uint32_t PP_msgIn[63];
#endif
} __PACKED__ ;


/**
   Acknowledgement to CMD_DBG_xPTC_MessageTunnel.
*/
struct ACK_DBG_xPTC_MessageTunnel
{
#if MEI_DRV_OS_BYTE_ORDER == MEI_DRV_OS_BIG_ENDIAN
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** PP32 selection */
   IFX_uint32_t PP_select;
   /** xPTC Message */
   IFX_uint32_t PP_msgOut[63];
#else
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** PP32 selection */
   IFX_uint32_t PP_select;
   /** xPTC Message */
   IFX_uint32_t PP_msgOut[63];
#endif
} __PACKED__ ;


/**
   The ARC can be halted on certain configurable conditions. The message
   enables/disables this possibility and configures the trigger conditions. To disable
   the feature, all triggers in Parameter 2 must be disabled.
*/
struct CMD_DBG_ARC_HaltControl
{
#if MEI_DRV_OS_BYTE_ORDER == MEI_DRV_OS_BIG_ENDIAN
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Reserved */
   IFX_uint32_t Res02 : 29;
   /** Register Value Trigger */
   IFX_uint32_t trigRegValue : 1;
   /** "ACK Error" Trigger */
   IFX_uint32_t trigAckError : 1;
   /** Fail State Trigger */
   IFX_uint32_t trigFailState : 1;
   /** Register Address */
   IFX_uint32_t regAddr;
   /** Register Value */
   IFX_uint32_t regValue;
   /** Register Mask */
   IFX_uint32_t regMask;
#else
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Fail State Trigger */
   IFX_uint32_t trigFailState : 1;
   /** "ACK Error" Trigger */
   IFX_uint32_t trigAckError : 1;
   /** Register Value Trigger */
   IFX_uint32_t trigRegValue : 1;
   /** Reserved */
   IFX_uint32_t Res02 : 29;
   /** Register Address */
   IFX_uint32_t regAddr;
   /** Register Value */
   IFX_uint32_t regValue;
   /** Register Mask */
   IFX_uint32_t regMask;
#endif
} __PACKED__ ;


/**
   Acknowledgement to CMD_DBG_ARC_HaltControl.
*/
struct ACK_DBG_ARC_HaltControl
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
   The message indicates that the ARC has been halted due to a matching trigger
   condition as configured with CMD_DBG_ARC_HaltControl.
   After the occurrence of this ALM, debug data are to be retrieved via the MEI
   interfaceI.
*/
struct ALM_DBG_ARC_Halt
{
#if MEI_DRV_OS_BYTE_ORDER == MEI_DRV_OS_BIG_ENDIAN
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Reserved */
   IFX_uint32_t Res02 : 29;
   /** HALT Reason: Register Value Trigger, Bit 2 */
   IFX_uint32_t trigRegValue : 1;
   /** HALT Reason: "ACK Error" Trigger, Bit 1 */
   IFX_uint32_t trigAckError : 1;
   /** HALT Reason: Fail State Trigger, Bit 0 */
   IFX_uint32_t trigFailState : 1;
   /** Trigger Dependant Information */
   IFX_uint32_t trigDetails;
#else
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** HALT Reason: Fail State Trigger, Bit 0 */
   IFX_uint32_t trigFailState : 1;
   /** HALT Reason: "ACK Error" Trigger, Bit 1 */
   IFX_uint32_t trigAckError : 1;
   /** HALT Reason: Register Value Trigger, Bit 2 */
   IFX_uint32_t trigRegValue : 1;
   /** Reserved */
   IFX_uint32_t Res02 : 29;
   /** Trigger Dependant Information */
   IFX_uint32_t trigDetails;
#endif
} __PACKED__ ;


/**
   This command requests MIPS status information (for this port).
*/
struct CMD_DBG_MIPS_StatusGet
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
   Acknowledgement carrying the MIPS status info requested by CMD_DBG_MIPS_StatusGet.
*/
struct ACK_DBG_MIPS_StatusGet
{
#if MEI_DRV_OS_BYTE_ORDER == MEI_DRV_OS_BIG_ENDIAN
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Maximum Foreground ARC Cycle Count */
   IFX_uint32_t MaxFgCycles;
   /** Maximum Total ARC Cycle Count */
   IFX_uint32_t MaxTotalCycles;
#else
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Maximum Foreground ARC Cycle Count */
   IFX_uint32_t MaxFgCycles;
   /** Maximum Total ARC Cycle Count */
   IFX_uint32_t MaxTotalCycles;
#endif
} __PACKED__ ;


/**
   Enables/Disables the output of so-called "debug streams" with additional debug
   information (see also EVT_DBG_DebugStream).
*/
struct CMD_DBG_DebugStreamControl
{
#if MEI_DRV_OS_BYTE_ORDER == MEI_DRV_OS_BIG_ENDIAN
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Reserved */
   IFX_uint32_t Res02 : 31;
   /** Enable/Disable Output of Debug-Stream */
   IFX_uint32_t control : 1;
#else
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Enable/Disable Output of Debug-Stream */
   IFX_uint32_t control : 1;
   /** Reserved */
   IFX_uint32_t Res02 : 31;
#endif
} __PACKED__ ;


/**
   Acknowledgement for CMD_DBG_DebugStreamControl.
*/
struct ACK_DBG_DebugStreamControl
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
   Writes a bit mask to configure which messages are output in the debug stream.The
   mask parameters constitute a 160-bit mask for enabling different sub-streams that
   will contribute to the over-all debug-stream. All masks have to be sent at once. A
   pre-defined set of masks shall be used only (see Table25 to Table29). The bit
   position in the bitmask corresponds to the subtype number of the debug-(sub)stream
   according to Table30.
*/
struct CMD_DBG_DebugStreamConfigure
{
#if MEI_DRV_OS_BYTE_ORDER == MEI_DRV_OS_BIG_ENDIAN
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Mask_1 */
   IFX_uint32_t Mask_1;
   /** Mask_2 */
   IFX_uint32_t Mask_2;
   /** Mask_3 */
   IFX_uint32_t Mask_3;
   /** Mask_4 */
   IFX_uint32_t Mask_4;
   /** Mask_5 (SOC) */
   IFX_uint32_t Mask_5;
#else
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Mask_1 */
   IFX_uint32_t Mask_1;
   /** Mask_2 */
   IFX_uint32_t Mask_2;
   /** Mask_3 */
   IFX_uint32_t Mask_3;
   /** Mask_4 */
   IFX_uint32_t Mask_4;
   /** Mask_5 (SOC) */
   IFX_uint32_t Mask_5;
#endif
} __PACKED__ ;


/**
   Acknowledgement for CMD_DBG_DebugStreamConfigure.
*/
struct ACK_DBG_DebugStreamConfigure
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
   Provides debug information as configured with CMD_DBG_DebugStreamConfigure. The EVTs
   are generated only if streaming was enabled by CMD_DBG_DebugStreamControl. One EVT
   can contain a whole debug substream or only a fragment (see parameter SOF_EOF). For
   overflow situations a corresponding flag ("overflowPre") and a stream counter are
   contained.
   Note: The debug streams are queued in a debug FIFO and then moved to the host-IF
   mailbox (if bigger than the mailbox size, then in fragments). If a debug
   stream does not fit into the FIFO because it is too full, it is discarded
   completely and the overflow flag is set in the last fragment of the
   preceeding message. A stream is either delivered to the host completely or
   discarded completely, not just single fragments of it.
*/
struct EVT_DBG_DebugStream
{
#if MEI_DRV_OS_BYTE_ORDER == MEI_DRV_OS_BIG_ENDIAN
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Debug Stream Subtype */
   IFX_uint16_t Subtype;
   /** Stream Counter */
   IFX_uint8_t streamCount;
   /** Reserved */
   IFX_uint32_t Res04 : 5;
   /** Overflow Pre-Indication */
   IFX_uint32_t overflowPre : 1;
   /** Start / End Indication */
   IFX_uint32_t SOF_EOF : 2;
   /** Debug Stream Data */
   IFX_uint32_t Data[63];
#else
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Start / End Indication */
   IFX_uint32_t SOF_EOF : 2;
   /** Overflow Pre-Indication */
   IFX_uint32_t overflowPre : 1;
   /** Reserved */
   IFX_uint32_t Res04 : 5;
   /** Stream Counter */
   IFX_uint8_t streamCount;
   /** Debug Stream Subtype */
   IFX_uint16_t Subtype;
   /** Debug Stream Data */
   IFX_uint32_t Data[63];
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

