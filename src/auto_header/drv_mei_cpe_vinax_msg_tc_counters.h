/******************************************************************************

                               Copyright (c) 2011
                            Lantiq Deutschland GmbH
                     Am Campeon 3; 85579 Neubiberg, Germany

  For licensing information, see the file 'LICENSE' in the root folder of
  this software module.

******************************************************************************/


#ifndef _VDSL2_FWDES_TC_COUNTERS_MSG_H_
#define _VDSL2_FWDES_TC_COUNTERS_MSG_H_

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

/** @defgroup _VDSL2_FWDES_TC_COUNTERS_MSG_ Messages for Performance Monitoring
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
/* ----- Constants Definition section (End) ----- */

/** Message ID for CMD_DataPathFailuresAlarmConfigure */
#define CMD_DATAPATHFAILURESALARMCONFIGURE 0x2051

/**
   Enables/Disables the generation of ALARM messages (ALM) for specific data-path
   failures. If the corresponding Enable bit for a failure is set, then the modem
   firmware will send an autonomous message ALM_DataPathFailuresGet if this failure
   occurs.
*/
typedef struct CMD_DataPathFailuresAlarmConfigure CMD_DataPathFailuresAlarmConfigure_t;

/** Message ID for ACK_DataPathFailuresAlarmConfigure */
#define ACK_DATAPATHFAILURESALARMCONFIGURE 0x2051

/**
   Acknowledgement to CMD_DataPathFailuresAlarmConfigure.
*/
typedef struct ACK_DataPathFailuresAlarmConfigure ACK_DataPathFailuresAlarmConfigure_t;

/** Message ID for CMD_DataPathFailuresGet */
#define CMD_DATAPATHFAILURESGET 0x2013

/**
   Requests the near-end data-path failure status.
*/
typedef struct CMD_DataPathFailuresGet CMD_DataPathFailuresGet_t;

/** Message ID for ACK_DataPathFailuresGet */
#define ACK_DATAPATHFAILURESGET 0x2013

/**
   Provides the near-end line failure status requested by the command
   CMD_DataPathFailuresGet.
*/
typedef struct ACK_DataPathFailuresGet ACK_DataPathFailuresGet_t;

/** Message ID for ALM_DataPathFailuresGet */
#define ALM_DATAPATHFAILURESGET 0x2013

/**
   This autonomous message reports the data-path failure status. It is sent only if the
   message generation was enabled for the corresponding failure with
   CMD_DataPathFailuresAlarmConfigure.
*/
typedef struct ALM_DataPathFailuresGet ALM_DataPathFailuresGet_t;

/** Message ID for CMD_Clause30_StatsLineGet */
#define CMD_CLAUSE30_STATSLINEGET 0x0113

/**
   Requests performance counter values for the xDSL side as specified in clause 30 of
   IEEE 802.3ae [13]. The data retrieval is implemented in a non-time-critical task.
   The acknowledgement ACK_Clause30_StatsLineGet is a just formal immediate response
   without data. The requested data will be delivered afterwards with
   NFC_Clause30_StatsLineGet.
*/
typedef struct CMD_Clause30_StatsLineGet CMD_Clause30_StatsLineGet_t;

/** Message ID for ACK_Clause30_StatsLineGet */
#define ACK_CLAUSE30_STATSLINEGET 0x0113

/**
   Acknowledgement to a CMD_Clause30_StatsLineGet command. This is a just formal
   acknowledgement without data. Data will be provided afterwards with
   NFC_Clause30_StatsLineGet.
*/
typedef struct ACK_Clause30_StatsLineGet ACK_Clause30_StatsLineGet_t;

/** Message ID for NFC_Clause30_StatsLineGet */
#define NFC_CLAUSE30_STATSLINEGET 0x0113

/**
   This autonomous message delivers the counter data requested by
   CMD_Clause30_StatsLineGet. All counters are non-resettable wrap-around counters. For
   a description of the individual counters see IEEE 802.3 clause 30 [12].
*/
typedef struct NFC_Clause30_StatsLineGet NFC_Clause30_StatsLineGet_t;

/** Message ID for CMD_Clause30_StatsSysGet */
#define CMD_CLAUSE30_STATSSYSGET 0x0213

/**
   Requests performance counter values for the system interface side as specified in
   clause 30 of IEEE 802.3ae [13]. The data retrieval is implemented in a
   non-time-critical task. The acknowledgement ACK_Clause30_StatsSysGet is a just
   formal immediate response without data. The requested data will be delivered
   afterwards with NFC_Clause30_StatsSysGet.
*/
typedef struct CMD_Clause30_StatsSysGet CMD_Clause30_StatsSysGet_t;

/** Message ID for ACK_Clause30_StatsSysGet */
#define ACK_CLAUSE30_STATSSYSGET 0x0213

/**
   Acknowledgement to a CMD_Clause30_StatsSysGet command. This is a just formal
   acknowledgement without data. Data will be provided afterwards with
   NFC_Clause30_StatsSysGet.
*/
typedef struct ACK_Clause30_StatsSysGet ACK_Clause30_StatsSysGet_t;

/** Message ID for NFC_Clause30_StatsSysGet */
#define NFC_CLAUSE30_STATSSYSGET 0x0213

/**
   This autonomous message delivers the data requested by CMD_Clause30_StatsSysGet. All
   counters are non-resettable wrap-around counters. For a description of the counters
   see IEEE 802.3 clause 30 [12].
*/
typedef struct NFC_Clause30_StatsSysGet NFC_Clause30_StatsSysGet_t;

/** Message ID for CMD_G997_PTM_StatsGet */
#define CMD_G997_PTM_STATSGET 0x3313

/**
   Requests the values of the PTM data path performance counters as defined in G.997.1
   (Section 7.2.5.1. of [11]).
*/
typedef struct CMD_G997_PTM_StatsGet CMD_G997_PTM_StatsGet_t;

/** Message ID for ACK_G997_PTM_StatsGet */
#define ACK_G997_PTM_STATSGET 0x3313

/**
   Delivers the counter values requested by CMD_G997_PTM_StatsGet: TPS-TC CRC error and
   TPS-TC coding violation counters. (Section 7.2.5.1. of [11])
*/
typedef struct ACK_G997_PTM_StatsGet ACK_G997_PTM_StatsGet_t;

/** Message ID for CMD_G997_PTM_StatsSet */
#define CMD_G997_PTM_STATSSET 0x3953

/**
   Writes the TPS-TC CRC error and TPS-TC coding violation counters (Section 7.2.5.1.
   of G.997.1 [11]).
   Note: Why writing these counters? For "automoding", meaning modems configured to
   support both ADSL and VDLS with automatic mode selection. The first retrain
   is always done with an ADSL FW independent of what was loaded before.
   Therefore, the counters must be saved by the host before destroying them by
   the FW download and are written back before the next link start of a FW
   that supports PTM.
*/
typedef struct CMD_G997_PTM_StatsSet CMD_G997_PTM_StatsSet_t;

/** Message ID for ACK_G997_PTM_StatsSet */
#define ACK_G997_PTM_STATSSET 0x3953

/**
   Acknowledgement for the message CMD_G997_PTM_StatsSet.
*/
typedef struct ACK_G997_PTM_StatsSet ACK_G997_PTM_StatsSet_t;

/** Message ID for CMD_G997_PTM_StatsThreshSet */
#define CMD_G997_PTM_STATSTHRESHSET 0x3253

/**
   The message configures the threshold values for PTM TPS-TC counters. If any of the
   configured thresholds is exceeded within a 15-min TR1 period and the threshold
   supervision was enabled for it, this is indicated to the host by an autonomous
   message.
*/
typedef struct CMD_G997_PTM_StatsThreshSet CMD_G997_PTM_StatsThreshSet_t;

/** Message ID for ACK_G997_PTM_StatsThreshSet */
#define ACK_G997_PTM_STATSTHRESHSET 0x3253

/**
   Acknowledgement to message CMD_G997_PTM_StatsThreshSet.
*/
typedef struct ACK_G997_PTM_StatsThreshSet ACK_G997_PTM_StatsThreshSet_t;

/** Message ID for CMD_Clause45_StatsGet */
#define CMD_CLAUSE45_STATSGET 0x3013

/**
   Requests performance counter values defined in clause 45 of IEEE 802.3ah [14]. This
   includes TPS-TC counters that are non-PAF related (TC CRC error register and the
   TPS-TC coding violations counter) as well as PAF related counters. The counters are
   reset on read. In the case of overflow the corresponding counter is held at its
   maximum value.
*/
typedef struct CMD_Clause45_StatsGet CMD_Clause45_StatsGet_t;

/** Message ID for ACK_Clause45_StatsGet */
#define ACK_CLAUSE45_STATSGET 0x3013

/**
   Delivers the counter values requested by CMD_Clause45_StatsGet.
   The counters are reset on read. In the case of overflow the corresponding counter is
   held at its maximum value.
   Note: In VINAX 1.x, PAF is not used and therefore the PAF related counters
   (Parameters 5 to 12) contain zero.
*/
typedef struct ACK_Clause45_StatsGet ACK_Clause45_StatsGet_t;

/** Message ID for CMD_MiscPTM_StatsGet */
#define CMD_MISCPTM_STATSGET 0x3413

/**
   Requests the counter values of miscellaneous PTM performance counters.
*/
typedef struct CMD_MiscPTM_StatsGet CMD_MiscPTM_StatsGet_t;

/** Message ID for ACK_MiscPTM_StatsGet */
#define ACK_MISCPTM_STATSGET 0x3413

/**
   Delivers the counter values requested by CMD_MiscPTM_StatsGet.
*/
typedef struct ACK_MiscPTM_StatsGet ACK_MiscPTM_StatsGet_t;

/** Message ID for CMD_G997_ATM_StatsGet */
#define CMD_G997_ATM_STATSGET 0x3513

/**
   This command is used to request the data-path performance counters for an ATM-TC
   link as defined in Section 7.2.4. of G.997.1 [11].
*/
typedef struct CMD_G997_ATM_StatsGet CMD_G997_ATM_StatsGet_t;

/** Message ID for ACK_G997_ATM_StatsGet */
#define ACK_G997_ATM_STATSGET 0x3513

/**
   This acknowledgement contains the ATM-TC performance monitoring counters requested
   by the command CMD_G997_ATM_StatsGet. The behaviour of the counters depends on the
   configuration of the TR1 15 minute counting. The behaviour is configured with
   CMD_TR1ControlSet. When the TR1 supervision period is disabled, then the "previous
   period" counters are meaningless and the "current period" counters will just count
   in a modulo32 manner. When TR1 supervision is enabled, then the counters will count
   for the specified time interval. When the time interval expires, the "current
   counters" will be copied to the "previous counters" block.
*/
typedef struct ACK_G997_ATM_StatsGet ACK_G997_ATM_StatsGet_t;

/** Message ID for CMD_G997_ATM_StatsSet */
#define CMD_G997_ATM_STATSSET 0x3853

/**
   Writes the data-path performance counters for an ATM-TC link (Section 7.2.4. of
   G.997.1 [11]).
   Note: If TR1 supervision is disabled (or "not supported"), then the "previous
   period" counters are meaningless and the "current period" counters will
   just count in a modulo32 manner.
   Note: Why writing counters? a) The ADSL-CPE FW of the VINAX destroys the
   performance counters at the beginning of a re-initialization since it
   starts with a FW download. Therefore the host has to save the counters in
   FAIL state before triggering a re-init. When reconfiguring the system in
   RESET state, the host writes the saved values as start values back into the
   counters. To do this for the ATM-TC counters, this message is used.b) For
   "automoding" meaning modems configured to support both ADSL and VDLS with
   automatic mode selection. Here the counters are saved by the host before a
   retrain and are written back after it, provided the modem ends up in the
   same DSL mode as before.
*/
typedef struct CMD_G997_ATM_StatsSet CMD_G997_ATM_StatsSet_t;

/** Message ID for ACK_G997_ATM_StatsSet */
#define ACK_G997_ATM_STATSSET 0x3853

/**
   Acknowledgement for the message CMD_G997_ATM_StatsSet.
*/
typedef struct ACK_G997_ATM_StatsSet ACK_G997_ATM_StatsSet_t;

/** Message ID for CMD_G997_ATM_StatsThreshSet */
#define CMD_G997_ATM_STATSTHRESHSET 0x3653

/**
   This command sets the alarm thresholds for the ATM performance counters. The alarm
   thresholds are only relevant, when the TR1 supervision is enabled via
   CMD_TR1ControlSet. The generation of autonomous alarm messages on theshold
   exceedance can be individually enabled/disabled with CMD_TR1ThreshAlarmConfigure.
   When the threshold of a counter is reached and the autonomous alarm messages are
   enabled, then this will be notified via the ALM_TR1CounterThreshHit alarm message.
   The alarm status can also be read using CMD_TR1CounterThreshHit. The currently set
   thresholds can be read with CMD_G997_ATM_StatsThreshGet.
   The thresholds are according to G.997.1, Chapter 7.3.4.2.
*/
typedef struct CMD_G997_ATM_StatsThreshSet CMD_G997_ATM_StatsThreshSet_t;

/** Message ID for ACK_G997_ATM_StatsThreshSet */
#define ACK_G997_ATM_STATSTHRESHSET 0x3653

/**
   This acknowledgement for the the CMD_G997_ATM_StatsThreshSet message.
*/
typedef struct ACK_G997_ATM_StatsThreshSet ACK_G997_ATM_StatsThreshSet_t;

/** Message ID for CMD_G997_ATM_StatsThreshGet */
#define CMD_G997_ATM_STATSTHRESHGET 0x3713

/**
   The message reads the settings of the ATM performance counter thresholds. These
   thresholds are set with CMD_G997_ATM_StatsThreshSet.
*/
typedef struct CMD_G997_ATM_StatsThreshGet CMD_G997_ATM_StatsThreshGet_t;

/** Message ID for ACK_G997_ATM_StatsThreshGet */
#define ACK_G997_ATM_STATSTHRESHGET 0x3713

/**
   This command is the acknowledgement for CMD_G997_ATM_StatsThreshGet and delivers the
   alarm thresholds of the ATM performance counters.
*/
typedef struct ACK_G997_ATM_StatsThreshGet ACK_G997_ATM_StatsThreshGet_t;

/** Message ID for CMD_ATM_TxStatsGet */
#define CMD_ATM_TXSTATSGET 0x3A13

/**
   Requests near-end ATM datapath performance transmit counters.
*/
typedef struct CMD_ATM_TxStatsGet CMD_ATM_TxStatsGet_t;

/** Message ID for ACK_ATM_TxStatsGet */
#define ACK_ATM_TXSTATSGET 0x3A13

/**
   This acknowledgement contains the ATM-TC performance monitoring counters requested
   by the command CMD_ATM_TxStatsGet. The behaviour of the counters depends on the
   configuration of the TR1 15 minute counting. The behaviour is configured with
   CMD_TR1ControlSet. When the TR1 supervision period is disabled, then the "previous
   period" counters are meaningless and the "current period" counters will just count
   in a modulo32 manner. When TR1 supervision is enabled, then the counters will count
   for the specified time interval. When the time interval expires, the "current
   counters" will be copied to the "previous counters" block.
*/
typedef struct ACK_ATM_TxStatsGet ACK_ATM_TxStatsGet_t;

/** Message ID for CMD_ATM_TxStatsSet */
#define CMD_ATM_TXSTATSSET 0x3B53

/**
   Writes the transmit data-path counters for an ATM-TC link.
   Note: For "Why writing performance counters" see Page1017.
*/
typedef struct CMD_ATM_TxStatsSet CMD_ATM_TxStatsSet_t;

/** Message ID for ACK_ATM_TxStatsSet */
#define ACK_ATM_TXSTATSSET 0x3B53

/**
   Acknowledgement for the message CMD_ATM_TxStatsSet.
*/
typedef struct ACK_ATM_TxStatsSet ACK_ATM_TxStatsSet_t;

/** Message ID for CMD_AAL5_SegmentationStatsGet */
#define CMD_AAL5_SEGMENTATIONSTATSGET 0x0313

/**
   Requests near-end performance counter values for AAL5 segmentation statistics.
*/
typedef struct CMD_AAL5_SegmentationStatsGet CMD_AAL5_SegmentationStatsGet_t;

/** Message ID for ACK_AAL5_SegmentationStatsGet */
#define ACK_AAL5_SEGMENTATIONSTATSGET 0x0313

/**
   Acknowledgement to a CMD_AAL5_SegmentationStatsGet command. Provides the requested
   near-end counter values for AAL5 segmentation statistics.
*/
typedef struct ACK_AAL5_SegmentationStatsGet ACK_AAL5_SegmentationStatsGet_t;

/** Message ID for CMD_AAL5_ReassemblyStats1Get */
#define CMD_AAL5_REASSEMBLYSTATS1GET 0x0413

/**
   For CO side only!
   Requests performance counter values for AAL5 reassembly statistics.
*/
typedef struct CMD_AAL5_ReassemblyStats1Get CMD_AAL5_ReassemblyStats1Get_t;

/** Message ID for ACK_AAL5_ReassemblyStats1Get */
#define ACK_AAL5_REASSEMBLYSTATS1GET 0x0413

/**
   Acknowledgement to a CMD_AAL5_ReassemblyStats1Get command.
*/
typedef struct ACK_AAL5_ReassemblyStats1Get ACK_AAL5_ReassemblyStats1Get_t;

/** Message ID for CMD_AAL5_ReassemblyStats2Get */
#define CMD_AAL5_REASSEMBLYSTATS2GET 0x0513

/**
   Requests performance counter values for AAL5 reassembly statistics.
*/
typedef struct CMD_AAL5_ReassemblyStats2Get CMD_AAL5_ReassemblyStats2Get_t;

/** Message ID for ACK_AAL5_ReassemblyStats2Get */
#define ACK_AAL5_REASSEMBLYSTATS2GET 0x0513

/**
   Acknowledgement to a CMD_AAL5_ReassemblyStats2Get command. Provides the performance
   counter values for AAL5 reassembly statistics.
*/
typedef struct ACK_AAL5_ReassemblyStats2Get ACK_AAL5_ReassemblyStats2Get_t;

/** Message ID for CMD_VersionInfoGet */
#define CMD_VERSIONINFOGET 0x0010

/**
   Requests version information from the VDSL2-Modem.
*/
typedef struct CMD_VersionInfoGet CMD_VersionInfoGet_t;

/** Message ID for ACK_VersionInfoGet */
#define ACK_VERSIONINFOGET 0x0010

/**
   Provides version information about hardware and firmware. The FW version numbering
   scheme differs for VINAX Rev. 1.x (Table542) and Rev. 2.x (Table545). Additionally,
   a short form of the Firmware Version number is defined for both (Rev. 1.x: Table543
   and Rev. 2.x: Table546).
   Note: The Online Firmware numbering scheme for VINAX Rev. 1.x changed with FW
   version 1.4.3.2 to the format listed in Table542.
   Note: The VINAX 1.x "old" numbering Revision scheme (Table544) is still valid for
   the ROM Code Version number.
*/
typedef struct ACK_VersionInfoGet ACK_VersionInfoGet_t;

/**
   Enables/Disables the generation of ALARM messages (ALM) for specific data-path
   failures. If the corresponding Enable bit for a failure is set, then the modem
   firmware will send an autonomous message ALM_DataPathFailuresGet if this failure
   occurs.
*/
struct CMD_DataPathFailuresAlarmConfigure
{
#if MEI_DRV_OS_BYTE_ORDER == MEI_DRV_OS_BIG_ENDIAN
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Link Number (=Bearer Channel Number) */
   IFX_uint32_t LinkNo;
   /** Reserved */
   IFX_uint32_t Res03 : 10;
   /** LCD Failure FE */
   IFX_uint32_t LCD_FE : 1;
   /** NCD Failure FE */
   IFX_uint32_t NCD_FE : 1;
   /** Reserved */
   IFX_uint32_t Res06 : 3;
   /** OOS Failure FE */
   IFX_uint32_t OOS_FE : 1;
   /** Reserved */
   IFX_uint32_t Res08 : 10;
   /** LCD Failure NE */
   IFX_uint32_t LCD_NE : 1;
   /** NCD Failure NE */
   IFX_uint32_t NCD_NE : 1;
   /** Reserved */
   IFX_uint32_t Res11 : 3;
   /** OOS Failure NE */
   IFX_uint32_t OOS_NE : 1;
#else
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Link Number (=Bearer Channel Number) */
   IFX_uint32_t LinkNo;
   /** OOS Failure NE */
   IFX_uint32_t OOS_NE : 1;
   /** Reserved */
   IFX_uint32_t Res11 : 3;
   /** NCD Failure NE */
   IFX_uint32_t NCD_NE : 1;
   /** LCD Failure NE */
   IFX_uint32_t LCD_NE : 1;
   /** Reserved */
   IFX_uint32_t Res08 : 10;
   /** OOS Failure FE */
   IFX_uint32_t OOS_FE : 1;
   /** Reserved */
   IFX_uint32_t Res06 : 3;
   /** NCD Failure FE */
   IFX_uint32_t NCD_FE : 1;
   /** LCD Failure FE */
   IFX_uint32_t LCD_FE : 1;
   /** Reserved */
   IFX_uint32_t Res03 : 10;
#endif
} __PACKED__ ;


/**
   Acknowledgement to CMD_DataPathFailuresAlarmConfigure.
*/
struct ACK_DataPathFailuresAlarmConfigure
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
   Requests the near-end data-path failure status.
*/
struct CMD_DataPathFailuresGet
{
#if MEI_DRV_OS_BYTE_ORDER == MEI_DRV_OS_BIG_ENDIAN
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Link Number (=Bearer Channel Number) */
   IFX_uint32_t LinkNo;
#else
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Link Number (=Bearer Channel Number) */
   IFX_uint32_t LinkNo;
#endif
} __PACKED__ ;


/**
   Provides the near-end line failure status requested by the command
   CMD_DataPathFailuresGet.
*/
struct ACK_DataPathFailuresGet
{
#if MEI_DRV_OS_BYTE_ORDER == MEI_DRV_OS_BIG_ENDIAN
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Link Number (=Bearer Channel Number) */
   IFX_uint32_t LinkNo;
   /** Reserved */
   IFX_uint32_t Res03 : 15;
   /** OOS Failure FE */
   IFX_uint32_t OOS_FE : 1;
   /** Reserved */
   IFX_uint32_t Res05 : 15;
   /** OOS Failure NE */
   IFX_uint32_t OOS_NE : 1;
   /** Reserved */
   IFX_uint32_t Res07 : 10;
   /** LCD Failure FE */
   IFX_uint32_t LCD_FE : 1;
   /** NCD Failure FE */
   IFX_uint32_t NCD_FE : 1;
   /** Reserved */
   IFX_uint32_t Res10 : 4;
   /** Reserved */
   IFX_uint32_t Res11 : 10;
   /** LCD Failure NE */
   IFX_uint32_t LCD_NE : 1;
   /** NCD Failure NE */
   IFX_uint32_t NCD_NE : 1;
   /** Reserved */
   IFX_uint32_t Res14 : 4;
#else
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Link Number (=Bearer Channel Number) */
   IFX_uint32_t LinkNo;
   /** OOS Failure NE */
   IFX_uint32_t OOS_NE : 1;
   /** Reserved */
   IFX_uint32_t Res05 : 15;
   /** OOS Failure FE */
   IFX_uint32_t OOS_FE : 1;
   /** Reserved */
   IFX_uint32_t Res03 : 15;
   /** Reserved */
   IFX_uint32_t Res14 : 4;
   /** NCD Failure NE */
   IFX_uint32_t NCD_NE : 1;
   /** LCD Failure NE */
   IFX_uint32_t LCD_NE : 1;
   /** Reserved */
   IFX_uint32_t Res11 : 10;
   /** Reserved */
   IFX_uint32_t Res10 : 4;
   /** NCD Failure FE */
   IFX_uint32_t NCD_FE : 1;
   /** LCD Failure FE */
   IFX_uint32_t LCD_FE : 1;
   /** Reserved */
   IFX_uint32_t Res07 : 10;
#endif
} __PACKED__ ;


/**
   This autonomous message reports the data-path failure status. It is sent only if the
   message generation was enabled for the corresponding failure with
   CMD_DataPathFailuresAlarmConfigure.
*/
struct ALM_DataPathFailuresGet
{
#if MEI_DRV_OS_BYTE_ORDER == MEI_DRV_OS_BIG_ENDIAN
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Link Number (=Bearer Channel Number) */
   IFX_uint32_t LinkNo;
   /** Reserved */
   IFX_uint32_t Res03 : 15;
   /** OOS Failure FE */
   IFX_uint32_t OOS_FE : 1;
   /** Reserved */
   IFX_uint32_t Res05 : 15;
   /** OOS Failure NE */
   IFX_uint32_t OOS_NE : 1;
   /** Reserved */
   IFX_uint32_t Res07 : 10;
   /** LCD Failure FE */
   IFX_uint32_t LCD_FE : 1;
   /** NCD Failure FE */
   IFX_uint32_t NCD_FE : 1;
   /** Reserved */
   IFX_uint32_t Res10 : 4;
   /** Reserved */
   IFX_uint32_t Res11 : 10;
   /** LCD Failure NE */
   IFX_uint32_t LCD_NE : 1;
   /** NCD Failure NE */
   IFX_uint32_t NCD_NE : 1;
   /** Reserved */
   IFX_uint32_t Res14 : 4;
#else
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Link Number (=Bearer Channel Number) */
   IFX_uint32_t LinkNo;
   /** OOS Failure NE */
   IFX_uint32_t OOS_NE : 1;
   /** Reserved */
   IFX_uint32_t Res05 : 15;
   /** OOS Failure FE */
   IFX_uint32_t OOS_FE : 1;
   /** Reserved */
   IFX_uint32_t Res03 : 15;
   /** Reserved */
   IFX_uint32_t Res14 : 4;
   /** NCD Failure NE */
   IFX_uint32_t NCD_NE : 1;
   /** LCD Failure NE */
   IFX_uint32_t LCD_NE : 1;
   /** Reserved */
   IFX_uint32_t Res11 : 10;
   /** Reserved */
   IFX_uint32_t Res10 : 4;
   /** NCD Failure FE */
   IFX_uint32_t NCD_FE : 1;
   /** LCD Failure FE */
   IFX_uint32_t LCD_FE : 1;
   /** Reserved */
   IFX_uint32_t Res07 : 10;
#endif
} __PACKED__ ;


/**
   Requests performance counter values for the xDSL side as specified in clause 30 of
   IEEE 802.3ae [13]. The data retrieval is implemented in a non-time-critical task.
   The acknowledgement ACK_Clause30_StatsLineGet is a just formal immediate response
   without data. The requested data will be delivered afterwards with
   NFC_Clause30_StatsLineGet.
*/
struct CMD_Clause30_StatsLineGet
{
#if MEI_DRV_OS_BYTE_ORDER == MEI_DRV_OS_BIG_ENDIAN
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Link Number (=Bearer Channel Number) */
   IFX_uint32_t LinkNo;
#else
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Link Number (=Bearer Channel Number) */
   IFX_uint32_t LinkNo;
#endif
} __PACKED__ ;


/**
   Acknowledgement to a CMD_Clause30_StatsLineGet command. This is a just formal
   acknowledgement without data. Data will be provided afterwards with
   NFC_Clause30_StatsLineGet.
*/
struct ACK_Clause30_StatsLineGet
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
   This autonomous message delivers the counter data requested by
   CMD_Clause30_StatsLineGet. All counters are non-resettable wrap-around counters. For
   a description of the individual counters see IEEE 802.3 clause 30 [12].
*/
struct NFC_Clause30_StatsLineGet
{
#if MEI_DRV_OS_BYTE_ORDER == MEI_DRV_OS_BIG_ENDIAN
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Link Number (=Bearer Channel Number) */
   IFX_uint32_t LinkNo;
   /** aFramesTransmittedOK (Line) */
   IFX_uint32_t Counter0;
   /** aFramesReceivedOK (Line) */
   IFX_uint32_t Counter1;
   /** aFrameCheckSequenceErrors (Line) */
   IFX_uint32_t Counter2;
   /** aAlignmentErrors (Line) */
   IFX_uint32_t Counter3;
   /** aOctetsTransmittedOK (Line) */
   IFX_uint32_t Counter4;
   /** Reserved */
   IFX_uint32_t Res08;
   /** aOctetsReceivedOK (Line) */
   IFX_uint32_t Counter6;
   /** Reserved */
   IFX_uint32_t Res10;
   /** aFramesLostDueToIntMACXmitError (Line) */
   IFX_uint32_t Counter8;
   /** aFramesLostDueToIntMACRcvError (Line) */
   IFX_uint32_t Counter9;
   /** aPAUSEMACControlFramesTransmitted (Line) */
   IFX_uint32_t Counter10;
   /** aPAUSEMACControlFramesReceived (Line) */
   IFX_uint32_t Counter11;
   /** aFrameTooLongErrors (Line) */
   IFX_uint32_t Counter12;
   /** aFrameTooShortErrors (Line) */
   IFX_uint32_t Counter13;
   /** Reserved */
   IFX_uint32_t Res17[9];
#else
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Link Number (=Bearer Channel Number) */
   IFX_uint32_t LinkNo;
   /** aFramesTransmittedOK (Line) */
   IFX_uint32_t Counter0;
   /** aFramesReceivedOK (Line) */
   IFX_uint32_t Counter1;
   /** aFrameCheckSequenceErrors (Line) */
   IFX_uint32_t Counter2;
   /** aAlignmentErrors (Line) */
   IFX_uint32_t Counter3;
   /** aOctetsTransmittedOK (Line) */
   IFX_uint32_t Counter4;
   /** Reserved */
   IFX_uint32_t Res08;
   /** aOctetsReceivedOK (Line) */
   IFX_uint32_t Counter6;
   /** Reserved */
   IFX_uint32_t Res10;
   /** aFramesLostDueToIntMACXmitError (Line) */
   IFX_uint32_t Counter8;
   /** aFramesLostDueToIntMACRcvError (Line) */
   IFX_uint32_t Counter9;
   /** aPAUSEMACControlFramesTransmitted (Line) */
   IFX_uint32_t Counter10;
   /** aPAUSEMACControlFramesReceived (Line) */
   IFX_uint32_t Counter11;
   /** aFrameTooLongErrors (Line) */
   IFX_uint32_t Counter12;
   /** aFrameTooShortErrors (Line) */
   IFX_uint32_t Counter13;
   /** Reserved */
   IFX_uint32_t Res17[9];
#endif
} __PACKED__ ;


/**
   Requests performance counter values for the system interface side as specified in
   clause 30 of IEEE 802.3ae [13]. The data retrieval is implemented in a
   non-time-critical task. The acknowledgement ACK_Clause30_StatsSysGet is a just
   formal immediate response without data. The requested data will be delivered
   afterwards with NFC_Clause30_StatsSysGet.
*/
struct CMD_Clause30_StatsSysGet
{
#if MEI_DRV_OS_BYTE_ORDER == MEI_DRV_OS_BIG_ENDIAN
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Link Number (=Bearer Channel Number) */
   IFX_uint32_t LinkNo;
#else
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Link Number (=Bearer Channel Number) */
   IFX_uint32_t LinkNo;
#endif
} __PACKED__ ;


/**
   Acknowledgement to a CMD_Clause30_StatsSysGet command. This is a just formal
   acknowledgement without data. Data will be provided afterwards with
   NFC_Clause30_StatsSysGet.
*/
struct ACK_Clause30_StatsSysGet
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
   This autonomous message delivers the data requested by CMD_Clause30_StatsSysGet. All
   counters are non-resettable wrap-around counters. For a description of the counters
   see IEEE 802.3 clause 30 [12].
*/
struct NFC_Clause30_StatsSysGet
{
#if MEI_DRV_OS_BYTE_ORDER == MEI_DRV_OS_BIG_ENDIAN
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Link Number (=Bearer Channel Number) */
   IFX_uint32_t LinkNo;
   /** aFramesTransmittedOK (System) */
   IFX_uint32_t Counter0;
   /** aSingleCollisionFrames */
   IFX_uint32_t Counter1;
   /** aMultipleCollisionFrames */
   IFX_uint32_t Counter2;
   /** aFramesReceivedOK (System) */
   IFX_uint32_t Counter3;
   /** aFrameCheckSequenceErrors (System) */
   IFX_uint32_t Counter4;
   /** aAlignmentErrors (System) */
   IFX_uint32_t Counter5;
   /** aOctetsTransmittedOK (System) */
   IFX_uint32_t Counter6;
   /** Reserved */
   IFX_uint32_t Res10;
   /** aOctetsReceivedOK (System) */
   IFX_uint32_t Counter8;
   /** Reserved */
   IFX_uint32_t Res12;
   /** aFramesLostDueToIntMACXmitError (System) */
   IFX_uint32_t Counter10;
   /** aFramesLostDueToIntMACRcvError (System) */
   IFX_uint32_t Counter11;
   /** aPAUSEMACControlFramesTransmitted (System) */
   IFX_uint32_t Counter12;
   /** aPAUSEMACControlFramesReceived (System) */
   IFX_uint32_t Counter13;
   /** aFrameTooLongErrors (System) */
   IFX_uint32_t Counter14;
   /** aFrameTooShortErrors (System) */
   IFX_uint32_t Counter15;
   /** Reserved */
   IFX_uint32_t Res19[13];
#else
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Link Number (=Bearer Channel Number) */
   IFX_uint32_t LinkNo;
   /** aFramesTransmittedOK (System) */
   IFX_uint32_t Counter0;
   /** aSingleCollisionFrames */
   IFX_uint32_t Counter1;
   /** aMultipleCollisionFrames */
   IFX_uint32_t Counter2;
   /** aFramesReceivedOK (System) */
   IFX_uint32_t Counter3;
   /** aFrameCheckSequenceErrors (System) */
   IFX_uint32_t Counter4;
   /** aAlignmentErrors (System) */
   IFX_uint32_t Counter5;
   /** aOctetsTransmittedOK (System) */
   IFX_uint32_t Counter6;
   /** Reserved */
   IFX_uint32_t Res10;
   /** aOctetsReceivedOK (System) */
   IFX_uint32_t Counter8;
   /** Reserved */
   IFX_uint32_t Res12;
   /** aFramesLostDueToIntMACXmitError (System) */
   IFX_uint32_t Counter10;
   /** aFramesLostDueToIntMACRcvError (System) */
   IFX_uint32_t Counter11;
   /** aPAUSEMACControlFramesTransmitted (System) */
   IFX_uint32_t Counter12;
   /** aPAUSEMACControlFramesReceived (System) */
   IFX_uint32_t Counter13;
   /** aFrameTooLongErrors (System) */
   IFX_uint32_t Counter14;
   /** aFrameTooShortErrors (System) */
   IFX_uint32_t Counter15;
   /** Reserved */
   IFX_uint32_t Res19[13];
#endif
} __PACKED__ ;


/**
   Requests the values of the PTM data path performance counters as defined in G.997.1
   (Section 7.2.5.1. of [11]).
*/
struct CMD_G997_PTM_StatsGet
{
#if MEI_DRV_OS_BYTE_ORDER == MEI_DRV_OS_BIG_ENDIAN
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Link Number */
   IFX_uint32_t LinkNo;
#else
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Link Number */
   IFX_uint32_t LinkNo;
#endif
} __PACKED__ ;


/**
   Delivers the counter values requested by CMD_G997_PTM_StatsGet: TPS-TC CRC error and
   TPS-TC coding violation counters. (Section 7.2.5.1. of [11])
*/
struct ACK_G997_PTM_StatsGet
{
#if MEI_DRV_OS_BYTE_ORDER == MEI_DRV_OS_BIG_ENDIAN
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Link Number */
   IFX_uint32_t LinkNo;
   /** TPS-TC CRC Error Counter NE (CRC-P), Current Period */
   IFX_uint32_t cntCRC_NE;
   /** TPS-TC Coding Violations Counter NE (CV-P), Current Period */
   IFX_uint32_t cntCVC_NE;
   /** Reserved */
   IFX_uint32_t Res05[2];
   /** TPS-TC CRC Error Counter NE (CRC-P), Previous Period */
   IFX_uint32_t cntCRC_NEprev;
   /** TPS-TC Coding Violations Counter NE (CV-P), Previous Period */
   IFX_uint32_t cntCVC_NEprev;
   /** Reserved */
   IFX_uint32_t Res1[2];
#else
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Link Number */
   IFX_uint32_t LinkNo;
   /** TPS-TC CRC Error Counter NE (CRC-P), Current Period */
   IFX_uint32_t cntCRC_NE;
   /** TPS-TC Coding Violations Counter NE (CV-P), Current Period */
   IFX_uint32_t cntCVC_NE;
   /** Reserved */
   IFX_uint32_t Res05[2];
   /** TPS-TC CRC Error Counter NE (CRC-P), Previous Period */
   IFX_uint32_t cntCRC_NEprev;
   /** TPS-TC Coding Violations Counter NE (CV-P), Previous Period */
   IFX_uint32_t cntCVC_NEprev;
   /** Reserved */
   IFX_uint32_t Res1[2];
#endif
} __PACKED__ ;


/**
   Writes the TPS-TC CRC error and TPS-TC coding violation counters (Section 7.2.5.1.
   of G.997.1 [11]).
   Note: Why writing these counters? For "automoding", meaning modems configured to
   support both ADSL and VDLS with automatic mode selection. The first retrain
   is always done with an ADSL FW independent of what was loaded before.
   Therefore, the counters must be saved by the host before destroying them by
   the FW download and are written back before the next link start of a FW
   that supports PTM.
*/
struct CMD_G997_PTM_StatsSet
{
#if MEI_DRV_OS_BYTE_ORDER == MEI_DRV_OS_BIG_ENDIAN
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Link Number */
   IFX_uint32_t LinkNo;
   /** TPS-TC CRC Error Counter NE (CRC-P), Current Period */
   IFX_uint32_t cntCRC_NE;
   /** TPS-TC Coding Violations Counter NE (CV-P), Current Period */
   IFX_uint32_t cntCVC_NE;
   /** Reserved */
   IFX_uint32_t Res05[2];
   /** TPS-TC CRC Error Counter NE (CRC-P), Previous Period */
   IFX_uint32_t cntCRC_NEprev;
   /** TPS-TC Coding Violations Counter NE (CV-P), Previous Period */
   IFX_uint32_t cntCVC_NEprev;
   /** Reserved */
   IFX_uint32_t Res1[2];
#else
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Link Number */
   IFX_uint32_t LinkNo;
   /** TPS-TC CRC Error Counter NE (CRC-P), Current Period */
   IFX_uint32_t cntCRC_NE;
   /** TPS-TC Coding Violations Counter NE (CV-P), Current Period */
   IFX_uint32_t cntCVC_NE;
   /** Reserved */
   IFX_uint32_t Res05[2];
   /** TPS-TC CRC Error Counter NE (CRC-P), Previous Period */
   IFX_uint32_t cntCRC_NEprev;
   /** TPS-TC Coding Violations Counter NE (CV-P), Previous Period */
   IFX_uint32_t cntCVC_NEprev;
   /** Reserved */
   IFX_uint32_t Res1[2];
#endif
} __PACKED__ ;


/**
   Acknowledgement for the message CMD_G997_PTM_StatsSet.
*/
struct ACK_G997_PTM_StatsSet
{
#if MEI_DRV_OS_BYTE_ORDER == MEI_DRV_OS_BIG_ENDIAN
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Link Number */
   IFX_uint32_t LinkNo;
#else
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Link Number */
   IFX_uint32_t LinkNo;
#endif
} __PACKED__ ;


/**
   The message configures the threshold values for PTM TPS-TC counters. If any of the
   configured thresholds is exceeded within a 15-min TR1 period and the threshold
   supervision was enabled for it, this is indicated to the host by an autonomous
   message.
*/
struct CMD_G997_PTM_StatsThreshSet
{
#if MEI_DRV_OS_BYTE_ORDER == MEI_DRV_OS_BIG_ENDIAN
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Link Number */
   IFX_uint32_t LinkNo;
   /** Threshold for TPS-TC CRC NE (CRC-P) */
   IFX_uint32_t CRC_ThreshNE;
   /** Threshold for TPS-TC CV NE (CV-P) */
   IFX_uint32_t CV_ThreshNE;
   /** Reserved */
   IFX_uint32_t Res05[2];
#else
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Link Number */
   IFX_uint32_t LinkNo;
   /** Threshold for TPS-TC CRC NE (CRC-P) */
   IFX_uint32_t CRC_ThreshNE;
   /** Threshold for TPS-TC CV NE (CV-P) */
   IFX_uint32_t CV_ThreshNE;
   /** Reserved */
   IFX_uint32_t Res05[2];
#endif
} __PACKED__ ;


/**
   Acknowledgement to message CMD_G997_PTM_StatsThreshSet.
*/
struct ACK_G997_PTM_StatsThreshSet
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
   Requests performance counter values defined in clause 45 of IEEE 802.3ah [14]. This
   includes TPS-TC counters that are non-PAF related (TC CRC error register and the
   TPS-TC coding violations counter) as well as PAF related counters. The counters are
   reset on read. In the case of overflow the corresponding counter is held at its
   maximum value.
*/
struct CMD_Clause45_StatsGet
{
#if MEI_DRV_OS_BYTE_ORDER == MEI_DRV_OS_BIG_ENDIAN
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Link Number */
   IFX_uint32_t LinkNo;
#else
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Link Number */
   IFX_uint32_t LinkNo;
#endif
} __PACKED__ ;


/**
   Delivers the counter values requested by CMD_Clause45_StatsGet.
   The counters are reset on read. In the case of overflow the corresponding counter is
   held at its maximum value.
   Note: In VINAX 1.x, PAF is not used and therefore the PAF related counters
   (Parameters 5 to 12) contain zero.
*/
struct ACK_Clause45_StatsGet
{
#if MEI_DRV_OS_BYTE_ORDER == MEI_DRV_OS_BIG_ENDIAN
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Link Number */
   IFX_uint32_t LinkNo;
   /** 10P/2B TC CRC Error Register */
   IFX_uint32_t TC_CRC;
   /** 10P/2B TPS-TC Coding Violations Counter */
   IFX_uint32_t TC_CV;
   /** 10P/2B PAF RX Error */
   IFX_uint32_t PAF_RxErrors;
   /** 10P/2B PAF Small Fragments */
   IFX_uint32_t PAF_SmallFrags;
   /** 10P/2B PAF Large Fragments */
   IFX_uint32_t PAF_LargeFrags;
   /** 10P/2B PAF Overflow */
   IFX_uint32_t PAF_Overflow;
   /** 10P/2B PAF Bad Fragment */
   IFX_uint32_t PAF_BadFrags;
   /** 10P/2B PAF Lost Fragment */
   IFX_uint32_t PAF_LostFrags;
   /** 10P/2B PAF Lost Start of Fragment */
   IFX_uint32_t PAF_LostFragStarts;
   /** 10P/2B PAF Lost End of Fragment */
   IFX_uint32_t PAF_LostFragEnds;
#else
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Link Number */
   IFX_uint32_t LinkNo;
   /** 10P/2B TC CRC Error Register */
   IFX_uint32_t TC_CRC;
   /** 10P/2B TPS-TC Coding Violations Counter */
   IFX_uint32_t TC_CV;
   /** 10P/2B PAF RX Error */
   IFX_uint32_t PAF_RxErrors;
   /** 10P/2B PAF Small Fragments */
   IFX_uint32_t PAF_SmallFrags;
   /** 10P/2B PAF Large Fragments */
   IFX_uint32_t PAF_LargeFrags;
   /** 10P/2B PAF Overflow */
   IFX_uint32_t PAF_Overflow;
   /** 10P/2B PAF Bad Fragment */
   IFX_uint32_t PAF_BadFrags;
   /** 10P/2B PAF Lost Fragment */
   IFX_uint32_t PAF_LostFrags;
   /** 10P/2B PAF Lost Start of Fragment */
   IFX_uint32_t PAF_LostFragStarts;
   /** 10P/2B PAF Lost End of Fragment */
   IFX_uint32_t PAF_LostFragEnds;
#endif
} __PACKED__ ;


/**
   Requests the counter values of miscellaneous PTM performance counters.
*/
struct CMD_MiscPTM_StatsGet
{
#if MEI_DRV_OS_BYTE_ORDER == MEI_DRV_OS_BIG_ENDIAN
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Link Number */
   IFX_uint32_t LinkNo;
#else
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Link Number */
   IFX_uint32_t LinkNo;
#endif
} __PACKED__ ;


/**
   Delivers the counter values requested by CMD_MiscPTM_StatsGet.
*/
struct ACK_MiscPTM_StatsGet
{
#if MEI_DRV_OS_BYTE_ORDER == MEI_DRV_OS_BIG_ENDIAN
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Link Number */
   IFX_uint32_t LinkNo;
   /** ExtractBufferOverflow (Line) */
   IFX_uint32_t Counter0;
   /** ExtractBufferOverflow (System) */
   IFX_uint32_t Counter1;
   /** Reserved */
   IFX_uint32_t Res05[8];
#else
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Link Number */
   IFX_uint32_t LinkNo;
   /** ExtractBufferOverflow (Line) */
   IFX_uint32_t Counter0;
   /** ExtractBufferOverflow (System) */
   IFX_uint32_t Counter1;
   /** Reserved */
   IFX_uint32_t Res05[8];
#endif
} __PACKED__ ;


/**
   This command is used to request the data-path performance counters for an ATM-TC
   link as defined in Section 7.2.4. of G.997.1 [11].
*/
struct CMD_G997_ATM_StatsGet
{
#if MEI_DRV_OS_BYTE_ORDER == MEI_DRV_OS_BIG_ENDIAN
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Link Number */
   IFX_uint32_t LinkNo;
#else
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Link Number */
   IFX_uint32_t LinkNo;
#endif
} __PACKED__ ;


/**
   This acknowledgement contains the ATM-TC performance monitoring counters requested
   by the command CMD_G997_ATM_StatsGet. The behaviour of the counters depends on the
   configuration of the TR1 15 minute counting. The behaviour is configured with
   CMD_TR1ControlSet. When the TR1 supervision period is disabled, then the "previous
   period" counters are meaningless and the "current period" counters will just count
   in a modulo32 manner. When TR1 supervision is enabled, then the counters will count
   for the specified time interval. When the time interval expires, the "current
   counters" will be copied to the "previous counters" block.
*/
struct ACK_G997_ATM_StatsGet
{
#if MEI_DRV_OS_BYTE_ORDER == MEI_DRV_OS_BIG_ENDIAN
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Link Number */
   IFX_uint32_t LinkNo;
   /** Near-end Hec Violation Count (HEC-P), Current Period */
   IFX_uint32_t hecp;
   /** Near-end Delineated Total Cell Count (CD-P), Current Period */
   IFX_uint32_t cdp;
   /** Near-end User Total Cell Count (CU-P), Current Period */
   IFX_uint32_t cup;
   /** Near-end Idle Cell Bit Error Count (IBE-P), Current Period */
   IFX_uint32_t ibep;
   /** Far-end Hec Violation Count (HEC-PFE), Current Period */
   IFX_uint32_t hecpfe;
   /** Far-end Delineated Total Cell Count (CD-PFE), Current Period */
   IFX_uint32_t cdpfe;
   /** Far-end User Total Cell Count (CU-PFE), Current Period */
   IFX_uint32_t cupfe;
   /** Far-end Idle Cell Bit Error Count (IBE-PFE), Current Period */
   IFX_uint32_t ibepfe;
   /** Near-end Hec Violation Count (HEC-P), Previous Period */
   IFX_uint32_t hecp_prev;
   /** Near-end Delineated Total Cell Count (CD-P), Previous Period */
   IFX_uint32_t cdp_prev;
   /** Near-end User Total Cell Count (CU-P), Previous Period */
   IFX_uint32_t cup_prev;
   /** Near-end Idle Cell Bit Error Count (IBE-P), Previous Period */
   IFX_uint32_t ibep_prev;
   /** Far-end Hec Violation Count (HEC-PFE), Previous Period */
   IFX_uint32_t hecpfe_prev;
   /** Far-end Delineated Total Cell Count (CD-PFE), Previous Period */
   IFX_uint32_t cdpfe_prev;
   /** Far-end User Total Cell Count (CU-PFE), Previous Period */
   IFX_uint32_t cupfe_prev;
   /** Far-end Idle Cell Bit Error Count (IBE-PFE), Previous Period */
   IFX_uint32_t ibepfe_prev;
#else
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Link Number */
   IFX_uint32_t LinkNo;
   /** Near-end Hec Violation Count (HEC-P), Current Period */
   IFX_uint32_t hecp;
   /** Near-end Delineated Total Cell Count (CD-P), Current Period */
   IFX_uint32_t cdp;
   /** Near-end User Total Cell Count (CU-P), Current Period */
   IFX_uint32_t cup;
   /** Near-end Idle Cell Bit Error Count (IBE-P), Current Period */
   IFX_uint32_t ibep;
   /** Far-end Hec Violation Count (HEC-PFE), Current Period */
   IFX_uint32_t hecpfe;
   /** Far-end Delineated Total Cell Count (CD-PFE), Current Period */
   IFX_uint32_t cdpfe;
   /** Far-end User Total Cell Count (CU-PFE), Current Period */
   IFX_uint32_t cupfe;
   /** Far-end Idle Cell Bit Error Count (IBE-PFE), Current Period */
   IFX_uint32_t ibepfe;
   /** Near-end Hec Violation Count (HEC-P), Previous Period */
   IFX_uint32_t hecp_prev;
   /** Near-end Delineated Total Cell Count (CD-P), Previous Period */
   IFX_uint32_t cdp_prev;
   /** Near-end User Total Cell Count (CU-P), Previous Period */
   IFX_uint32_t cup_prev;
   /** Near-end Idle Cell Bit Error Count (IBE-P), Previous Period */
   IFX_uint32_t ibep_prev;
   /** Far-end Hec Violation Count (HEC-PFE), Previous Period */
   IFX_uint32_t hecpfe_prev;
   /** Far-end Delineated Total Cell Count (CD-PFE), Previous Period */
   IFX_uint32_t cdpfe_prev;
   /** Far-end User Total Cell Count (CU-PFE), Previous Period */
   IFX_uint32_t cupfe_prev;
   /** Far-end Idle Cell Bit Error Count (IBE-PFE), Previous Period */
   IFX_uint32_t ibepfe_prev;
#endif
} __PACKED__ ;


/**
   Writes the data-path performance counters for an ATM-TC link (Section 7.2.4. of
   G.997.1 [11]).
   Note: If TR1 supervision is disabled (or "not supported"), then the "previous
   period" counters are meaningless and the "current period" counters will
   just count in a modulo32 manner.
   Note: Why writing counters? a) The ADSL-CPE FW of the VINAX destroys the
   performance counters at the beginning of a re-initialization since it
   starts with a FW download. Therefore the host has to save the counters in
   FAIL state before triggering a re-init. When reconfiguring the system in
   RESET state, the host writes the saved values as start values back into the
   counters. To do this for the ATM-TC counters, this message is used.b) For
   "automoding" meaning modems configured to support both ADSL and VDLS with
   automatic mode selection. Here the counters are saved by the host before a
   retrain and are written back after it, provided the modem ends up in the
   same DSL mode as before.
*/
struct CMD_G997_ATM_StatsSet
{
#if MEI_DRV_OS_BYTE_ORDER == MEI_DRV_OS_BIG_ENDIAN
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Link Number */
   IFX_uint32_t LinkNo;
   /** Near-end Hec Violation Count (HEC-P), Current Period */
   IFX_uint32_t hecp;
   /** Near-end Delineated Total Cell Count (CD-P), Current Period */
   IFX_uint32_t cdp;
   /** Near-end User Total Cell Count (CU-P), Current Period */
   IFX_uint32_t cup;
   /** Near-end Idle Cell Bit Error Count (IBE-P), Current Period */
   IFX_uint32_t ibep;
   /** Far-end Hec Violation Count (HEC-PFE), Current Period */
   IFX_uint32_t hecpfe;
   /** Far-end Delineated Total Cell Count (CD-PFE), Current Period */
   IFX_uint32_t cdpfe;
   /** Far-end User Total Cell Count (CU-PFE), Current Period */
   IFX_uint32_t cupfe;
   /** Far-end Idle Cell Bit Error Count (IBE-PFE), Current Period */
   IFX_uint32_t ibepfe;
   /** Near-end Hec Violation Count (HEC-P), Previous Period */
   IFX_uint32_t hecp_prev;
   /** Near-end Delineated Total Cell Count (CD-P), Previous Period */
   IFX_uint32_t cdp_prev;
   /** Near-end User Total Cell Count (CU-P), Previous Period */
   IFX_uint32_t cup_prev;
   /** Near-end Idle Cell Bit Error Count (IBE-P), Previous Period */
   IFX_uint32_t ibep_prev;
   /** Far-end Hec Violation Count (HEC-PFE), Previous Period */
   IFX_uint32_t hecpfe_prev;
   /** Far-end Delineated Total Cell Count (CD-PFE), Previous Period */
   IFX_uint32_t cdpfe_prev;
   /** Far-end User Total Cell Count (CU-PFE), Previous Period */
   IFX_uint32_t cupfe_prev;
   /** Far-end Idle Cell Bit Error Count (IBE-PFE), Previous Period */
   IFX_uint32_t ibepfe_prev;
#else
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Link Number */
   IFX_uint32_t LinkNo;
   /** Near-end Hec Violation Count (HEC-P), Current Period */
   IFX_uint32_t hecp;
   /** Near-end Delineated Total Cell Count (CD-P), Current Period */
   IFX_uint32_t cdp;
   /** Near-end User Total Cell Count (CU-P), Current Period */
   IFX_uint32_t cup;
   /** Near-end Idle Cell Bit Error Count (IBE-P), Current Period */
   IFX_uint32_t ibep;
   /** Far-end Hec Violation Count (HEC-PFE), Current Period */
   IFX_uint32_t hecpfe;
   /** Far-end Delineated Total Cell Count (CD-PFE), Current Period */
   IFX_uint32_t cdpfe;
   /** Far-end User Total Cell Count (CU-PFE), Current Period */
   IFX_uint32_t cupfe;
   /** Far-end Idle Cell Bit Error Count (IBE-PFE), Current Period */
   IFX_uint32_t ibepfe;
   /** Near-end Hec Violation Count (HEC-P), Previous Period */
   IFX_uint32_t hecp_prev;
   /** Near-end Delineated Total Cell Count (CD-P), Previous Period */
   IFX_uint32_t cdp_prev;
   /** Near-end User Total Cell Count (CU-P), Previous Period */
   IFX_uint32_t cup_prev;
   /** Near-end Idle Cell Bit Error Count (IBE-P), Previous Period */
   IFX_uint32_t ibep_prev;
   /** Far-end Hec Violation Count (HEC-PFE), Previous Period */
   IFX_uint32_t hecpfe_prev;
   /** Far-end Delineated Total Cell Count (CD-PFE), Previous Period */
   IFX_uint32_t cdpfe_prev;
   /** Far-end User Total Cell Count (CU-PFE), Previous Period */
   IFX_uint32_t cupfe_prev;
   /** Far-end Idle Cell Bit Error Count (IBE-PFE), Previous Period */
   IFX_uint32_t ibepfe_prev;
#endif
} __PACKED__ ;


/**
   Acknowledgement for the message CMD_G997_ATM_StatsSet.
*/
struct ACK_G997_ATM_StatsSet
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
   This command sets the alarm thresholds for the ATM performance counters. The alarm
   thresholds are only relevant, when the TR1 supervision is enabled via
   CMD_TR1ControlSet. The generation of autonomous alarm messages on theshold
   exceedance can be individually enabled/disabled with CMD_TR1ThreshAlarmConfigure.
   When the threshold of a counter is reached and the autonomous alarm messages are
   enabled, then this will be notified via the ALM_TR1CounterThreshHit alarm message.
   The alarm status can also be read using CMD_TR1CounterThreshHit. The currently set
   thresholds can be read with CMD_G997_ATM_StatsThreshGet.
   The thresholds are according to G.997.1, Chapter 7.3.4.2.
*/
struct CMD_G997_ATM_StatsThreshSet
{
#if MEI_DRV_OS_BYTE_ORDER == MEI_DRV_OS_BIG_ENDIAN
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Link Number */
   IFX_uint32_t LinkNo;
   /** Threshold for Near-end HEC Violation Counter (HEC-P) */
   IFX_uint32_t hecp_thr;
   /** Threshold for Near-end Delineated Total Cell Counter (CD-P) */
   IFX_uint32_t cdp_thr;
   /** Threshold for Near-end User total Cell Counter (CU-P) */
   IFX_uint32_t cup_thr;
   /** Threshold for Near-end Idle Cell Bit Error Counter (IBE-P) */
   IFX_uint32_t ibep_thr;
   /** Threshold for Far-end HEC Violation Counter (HEC-PFE) */
   IFX_uint32_t hecpfe_thr;
   /** Threshold for Far-end Delineated Total Cell Counter (CD-PFE) */
   IFX_uint32_t cdpfe_thr;
   /** Threshold for Far-end User total Cell Counter (CU-PFE) */
   IFX_uint32_t cupfe_thr;
   /** Threshold for Far-end Idle Cell Bit Error Counter (IBE-PFE) */
   IFX_uint32_t ibepfe_thr;
#else
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Link Number */
   IFX_uint32_t LinkNo;
   /** Threshold for Near-end HEC Violation Counter (HEC-P) */
   IFX_uint32_t hecp_thr;
   /** Threshold for Near-end Delineated Total Cell Counter (CD-P) */
   IFX_uint32_t cdp_thr;
   /** Threshold for Near-end User total Cell Counter (CU-P) */
   IFX_uint32_t cup_thr;
   /** Threshold for Near-end Idle Cell Bit Error Counter (IBE-P) */
   IFX_uint32_t ibep_thr;
   /** Threshold for Far-end HEC Violation Counter (HEC-PFE) */
   IFX_uint32_t hecpfe_thr;
   /** Threshold for Far-end Delineated Total Cell Counter (CD-PFE) */
   IFX_uint32_t cdpfe_thr;
   /** Threshold for Far-end User total Cell Counter (CU-PFE) */
   IFX_uint32_t cupfe_thr;
   /** Threshold for Far-end Idle Cell Bit Error Counter (IBE-PFE) */
   IFX_uint32_t ibepfe_thr;
#endif
} __PACKED__ ;


/**
   This acknowledgement for the the CMD_G997_ATM_StatsThreshSet message.
*/
struct ACK_G997_ATM_StatsThreshSet
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
   The message reads the settings of the ATM performance counter thresholds. These
   thresholds are set with CMD_G997_ATM_StatsThreshSet.
*/
struct CMD_G997_ATM_StatsThreshGet
{
#if MEI_DRV_OS_BYTE_ORDER == MEI_DRV_OS_BIG_ENDIAN
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Link Number */
   IFX_uint32_t LinkNo;
#else
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Link Number */
   IFX_uint32_t LinkNo;
#endif
} __PACKED__ ;


/**
   This command is the acknowledgement for CMD_G997_ATM_StatsThreshGet and delivers the
   alarm thresholds of the ATM performance counters.
*/
struct ACK_G997_ATM_StatsThreshGet
{
#if MEI_DRV_OS_BYTE_ORDER == MEI_DRV_OS_BIG_ENDIAN
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Link Number */
   IFX_uint32_t LinkNo;
   /** Threshold for Near-end HEC Violation Counter (HEC-P) */
   IFX_uint32_t hecp_thr;
   /** Threshold for Near-end Delineated Total Cell Counter (CD-P) */
   IFX_uint32_t cdp_thr;
   /** Threshold for Near-end User total Cell Counter (CU-P) */
   IFX_uint32_t cup_thr;
   /** Threshold for Near-end Idle Cell Bit Error Counter (IBE-P) */
   IFX_uint32_t ibep_thr;
   /** Threshold for Far-end HEC Violation Counter (HEC-PFE) */
   IFX_uint32_t hecpfe_thr;
   /** Threshold for Far-end Delineated Total Cell Counter (CD-PFE) */
   IFX_uint32_t cdpfe_thr;
   /** Threshold for Far-end User total Cell Counter (CU-PFE) */
   IFX_uint32_t cupfe_thr;
   /** Threshold for Far-end Idle Cell Bit Error Counter (IBE-PFE) */
   IFX_uint32_t ibepfe_thr;
#else
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Link Number */
   IFX_uint32_t LinkNo;
   /** Threshold for Near-end HEC Violation Counter (HEC-P) */
   IFX_uint32_t hecp_thr;
   /** Threshold for Near-end Delineated Total Cell Counter (CD-P) */
   IFX_uint32_t cdp_thr;
   /** Threshold for Near-end User total Cell Counter (CU-P) */
   IFX_uint32_t cup_thr;
   /** Threshold for Near-end Idle Cell Bit Error Counter (IBE-P) */
   IFX_uint32_t ibep_thr;
   /** Threshold for Far-end HEC Violation Counter (HEC-PFE) */
   IFX_uint32_t hecpfe_thr;
   /** Threshold for Far-end Delineated Total Cell Counter (CD-PFE) */
   IFX_uint32_t cdpfe_thr;
   /** Threshold for Far-end User total Cell Counter (CU-PFE) */
   IFX_uint32_t cupfe_thr;
   /** Threshold for Far-end Idle Cell Bit Error Counter (IBE-PFE) */
   IFX_uint32_t ibepfe_thr;
#endif
} __PACKED__ ;


/**
   Requests near-end ATM datapath performance transmit counters.
*/
struct CMD_ATM_TxStatsGet
{
#if MEI_DRV_OS_BYTE_ORDER == MEI_DRV_OS_BIG_ENDIAN
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Link Number */
   IFX_uint32_t LinkNo;
#else
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Link Number */
   IFX_uint32_t LinkNo;
#endif
} __PACKED__ ;


/**
   This acknowledgement contains the ATM-TC performance monitoring counters requested
   by the command CMD_ATM_TxStatsGet. The behaviour of the counters depends on the
   configuration of the TR1 15 minute counting. The behaviour is configured with
   CMD_TR1ControlSet. When the TR1 supervision period is disabled, then the "previous
   period" counters are meaningless and the "current period" counters will just count
   in a modulo32 manner. When TR1 supervision is enabled, then the counters will count
   for the specified time interval. When the time interval expires, the "current
   counters" will be copied to the "previous counters" block.
*/
struct ACK_ATM_TxStatsGet
{
#if MEI_DRV_OS_BYTE_ORDER == MEI_DRV_OS_BIG_ENDIAN
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Link Number */
   IFX_uint32_t LinkNo;
   /** Near-end Tx User Cell Count (TxCU), Current Period */
   IFX_uint32_t TxCU;
   /** Near-end Tx Idle Cell Count (TxIdle), Current Period */
   IFX_uint32_t TxIdle;
   /** Reserved */
   IFX_uint32_t Res05[2];
   /** Near-end Tx User Cell Count (TxCU), Previous Period */
   IFX_uint32_t TxCU_prev;
   /** Near-end Tx Idle Cell Count (TxIdle), Previous Period */
   IFX_uint32_t TxIdle_prev;
   /** Reserved */
   IFX_uint32_t Res08[2];
#else
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Link Number */
   IFX_uint32_t LinkNo;
   /** Near-end Tx User Cell Count (TxCU), Current Period */
   IFX_uint32_t TxCU;
   /** Near-end Tx Idle Cell Count (TxIdle), Current Period */
   IFX_uint32_t TxIdle;
   /** Reserved */
   IFX_uint32_t Res05[2];
   /** Near-end Tx User Cell Count (TxCU), Previous Period */
   IFX_uint32_t TxCU_prev;
   /** Near-end Tx Idle Cell Count (TxIdle), Previous Period */
   IFX_uint32_t TxIdle_prev;
   /** Reserved */
   IFX_uint32_t Res08[2];
#endif
} __PACKED__ ;


/**
   Writes the transmit data-path counters for an ATM-TC link.
   Note: For "Why writing performance counters" see Page1017.
*/
struct CMD_ATM_TxStatsSet
{
#if MEI_DRV_OS_BYTE_ORDER == MEI_DRV_OS_BIG_ENDIAN
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Link Number */
   IFX_uint32_t LinkNo;
   /** Near-end Tx User Cell Count (TxCU), Current Period */
   IFX_uint32_t TxCU;
   /** Near-end Tx Idle Cell Count (TxIdle), Current Period */
   IFX_uint32_t TxIdle;
   /** Reserved */
   IFX_uint32_t Res05[2];
   /** Near-end Tx User Cell Count (TxCU), Previous Period */
   IFX_uint32_t TxCU_prev;
   /** Near-end Tx Idle Cell Count (TxIdle), Previous Period */
   IFX_uint32_t TxIdle_prev;
   /** Reserved */
   IFX_uint32_t Res08[2];
#else
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Link Number */
   IFX_uint32_t LinkNo;
   /** Near-end Tx User Cell Count (TxCU), Current Period */
   IFX_uint32_t TxCU;
   /** Near-end Tx Idle Cell Count (TxIdle), Current Period */
   IFX_uint32_t TxIdle;
   /** Reserved */
   IFX_uint32_t Res05[2];
   /** Near-end Tx User Cell Count (TxCU), Previous Period */
   IFX_uint32_t TxCU_prev;
   /** Near-end Tx Idle Cell Count (TxIdle), Previous Period */
   IFX_uint32_t TxIdle_prev;
   /** Reserved */
   IFX_uint32_t Res08[2];
#endif
} __PACKED__ ;


/**
   Acknowledgement for the message CMD_ATM_TxStatsSet.
*/
struct ACK_ATM_TxStatsSet
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
   Requests near-end performance counter values for AAL5 segmentation statistics.
*/
struct CMD_AAL5_SegmentationStatsGet
{
#if MEI_DRV_OS_BYTE_ORDER == MEI_DRV_OS_BIG_ENDIAN
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Link Number (=Bearer Channel Number) */
   IFX_uint32_t LinkNo;
#else
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Link Number (=Bearer Channel Number) */
   IFX_uint32_t LinkNo;
#endif
} __PACKED__ ;


/**
   Acknowledgement to a CMD_AAL5_SegmentationStatsGet command. Provides the requested
   near-end counter values for AAL5 segmentation statistics.
*/
struct ACK_AAL5_SegmentationStatsGet
{
#if MEI_DRV_OS_BYTE_ORDER == MEI_DRV_OS_BIG_ENDIAN
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Link Number (=Bearer Channel Number) */
   IFX_uint32_t LinkNo;
   /** Counter: ETH Frames Rx without VCC Matching */
   IFX_uint32_t segMAC_NoVCCmatch;
   /** Counter: ETH Frames Rx with Default VCC Matching */
   IFX_uint32_t segMAC_DefVCC;
   /** Counter: ETH Frames Rx for Segmentation in VCC0 */
   IFX_uint32_t segMAC_VCC0;
   /** Counter: ETH Frames Rx for Segmentation in VCC1 */
   IFX_uint32_t segMAC_VCC1;
   /** Counter: ETH Frames Rx for Segmentation in VCC2 */
   IFX_uint32_t segMAC_VCC2;
   /** Counter: ETH Frames Rx for Segmentation in VCC3 */
   IFX_uint32_t segMAC_VCC3;
   /** Counter: ETH Frames Rx for Segmentation in VCC4 */
   IFX_uint32_t segMAC_VCC4;
   /** Counter: ETH Frames Rx for Segmentation in VCC5 */
   IFX_uint32_t segMAC_VCC5;
   /** Counter: ETH Frames Rx for Segmentation in VCC6 */
   IFX_uint32_t segMAC_VCC6;
   /** Counter: ETH Frames Rx for Segmentation in VCC7 */
   IFX_uint32_t segMAC_VCC7;
   /** Counter: ATM Cell Default VCC */
   IFX_uint32_t segATM_DefVCC;
   /** Counter: ATM Cell VCC0 */
   IFX_uint32_t segATM_VCC0;
   /** Counter: ATM Cell VCC1 */
   IFX_uint32_t segATM_VCC1;
   /** Counter: ATM Cell VCC2 */
   IFX_uint32_t segATM_VCC2;
   /** Counter: ATM Cell VCC3 */
   IFX_uint32_t segATM_VCC3;
   /** Counter: ATM Cell VCC4 */
   IFX_uint32_t segATM_VCC4;
   /** Counter: ATM Cell VCC5 */
   IFX_uint32_t segATM_VCC5;
   /** Counter: ATM Cell VCC6 */
   IFX_uint32_t segATM_VCC6;
   /** Counter: ATM Cell VCC7 */
   IFX_uint32_t segATM_VCC7;
#else
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Link Number (=Bearer Channel Number) */
   IFX_uint32_t LinkNo;
   /** Counter: ETH Frames Rx without VCC Matching */
   IFX_uint32_t segMAC_NoVCCmatch;
   /** Counter: ETH Frames Rx with Default VCC Matching */
   IFX_uint32_t segMAC_DefVCC;
   /** Counter: ETH Frames Rx for Segmentation in VCC0 */
   IFX_uint32_t segMAC_VCC0;
   /** Counter: ETH Frames Rx for Segmentation in VCC1 */
   IFX_uint32_t segMAC_VCC1;
   /** Counter: ETH Frames Rx for Segmentation in VCC2 */
   IFX_uint32_t segMAC_VCC2;
   /** Counter: ETH Frames Rx for Segmentation in VCC3 */
   IFX_uint32_t segMAC_VCC3;
   /** Counter: ETH Frames Rx for Segmentation in VCC4 */
   IFX_uint32_t segMAC_VCC4;
   /** Counter: ETH Frames Rx for Segmentation in VCC5 */
   IFX_uint32_t segMAC_VCC5;
   /** Counter: ETH Frames Rx for Segmentation in VCC6 */
   IFX_uint32_t segMAC_VCC6;
   /** Counter: ETH Frames Rx for Segmentation in VCC7 */
   IFX_uint32_t segMAC_VCC7;
   /** Counter: ATM Cell Default VCC */
   IFX_uint32_t segATM_DefVCC;
   /** Counter: ATM Cell VCC0 */
   IFX_uint32_t segATM_VCC0;
   /** Counter: ATM Cell VCC1 */
   IFX_uint32_t segATM_VCC1;
   /** Counter: ATM Cell VCC2 */
   IFX_uint32_t segATM_VCC2;
   /** Counter: ATM Cell VCC3 */
   IFX_uint32_t segATM_VCC3;
   /** Counter: ATM Cell VCC4 */
   IFX_uint32_t segATM_VCC4;
   /** Counter: ATM Cell VCC5 */
   IFX_uint32_t segATM_VCC5;
   /** Counter: ATM Cell VCC6 */
   IFX_uint32_t segATM_VCC6;
   /** Counter: ATM Cell VCC7 */
   IFX_uint32_t segATM_VCC7;
#endif
} __PACKED__ ;


/**
   For CO side only!
   Requests performance counter values for AAL5 reassembly statistics.
*/
struct CMD_AAL5_ReassemblyStats1Get
{
#if MEI_DRV_OS_BYTE_ORDER == MEI_DRV_OS_BIG_ENDIAN
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Link Number (=Bearer Channel Number) */
   IFX_uint32_t LinkNo;
#else
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Link Number (=Bearer Channel Number) */
   IFX_uint32_t LinkNo;
#endif
} __PACKED__ ;


/**
   Acknowledgement to a CMD_AAL5_ReassemblyStats1Get command.
*/
struct ACK_AAL5_ReassemblyStats1Get
{
#if MEI_DRV_OS_BYTE_ORDER == MEI_DRV_OS_BIG_ENDIAN
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Link Number (=Bearer Channel Number) */
   IFX_uint32_t LinkNo;
   /** Counter: ATM Cell Drop due to invalid VCC */
   IFX_uint32_t reaATM_NoVCCmatch;
   /** Counter: ETH Frame Drop due to invalid LLC */
   IFX_uint32_t reaMAC_LLCinvalid;
   /** Counter: CRC Error in VCC0 */
   IFX_uint32_t reaCRC_VCC0;
   /** Counter: CRC Error in VCC1 */
   IFX_uint32_t reaCRC_VCC1;
   /** Counter: CRC Error in VCC2 */
   IFX_uint32_t reaCRC_VCC2;
   /** Counter: CRC Error in VCC3 */
   IFX_uint32_t reaCRC_VCC3;
   /** Counter: CRC Error in VCC4 */
   IFX_uint32_t reaCRC_VCC4;
   /** Counter: CRC Error in VCC5 */
   IFX_uint32_t reaCRC_VCC5;
   /** Counter: CRC Error in VCC6 */
   IFX_uint32_t reaCRC_VCC6;
   /** Counter: CRC Error in VCC7 */
   IFX_uint32_t reaCRC_VCC7;
   /** Counter: Reassembled ETH Frames Tx in VCC0 */
   IFX_uint32_t reaMAC_VCC0;
   /** Counter: Reassembled ETH Frames Tx in VCC1 */
   IFX_uint32_t reaMAC_VCC1;
   /** Counter: Reassembled ETH Frames Tx in VCC2 */
   IFX_uint32_t reaMAC_VCC2;
   /** Counter: Reassembled ETH Frames Tx in VCC3 */
   IFX_uint32_t reaMAC_VCC3;
   /** Counter: Reassembled ETH Frames Tx in VCC4 */
   IFX_uint32_t reaMAC_VCC4;
   /** Counter: Reassembled ETH Frames Tx in VCC5 */
   IFX_uint32_t reaMAC_VCC5;
   /** Counter: Reassembled ETH Frames Tx in VCC6 */
   IFX_uint32_t reaMAC_VCC6;
   /** Counter: Reassembled ETH Frames Tx in VCC7 */
   IFX_uint32_t reaMAC_VCC7;
#else
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Link Number (=Bearer Channel Number) */
   IFX_uint32_t LinkNo;
   /** Counter: ATM Cell Drop due to invalid VCC */
   IFX_uint32_t reaATM_NoVCCmatch;
   /** Counter: ETH Frame Drop due to invalid LLC */
   IFX_uint32_t reaMAC_LLCinvalid;
   /** Counter: CRC Error in VCC0 */
   IFX_uint32_t reaCRC_VCC0;
   /** Counter: CRC Error in VCC1 */
   IFX_uint32_t reaCRC_VCC1;
   /** Counter: CRC Error in VCC2 */
   IFX_uint32_t reaCRC_VCC2;
   /** Counter: CRC Error in VCC3 */
   IFX_uint32_t reaCRC_VCC3;
   /** Counter: CRC Error in VCC4 */
   IFX_uint32_t reaCRC_VCC4;
   /** Counter: CRC Error in VCC5 */
   IFX_uint32_t reaCRC_VCC5;
   /** Counter: CRC Error in VCC6 */
   IFX_uint32_t reaCRC_VCC6;
   /** Counter: CRC Error in VCC7 */
   IFX_uint32_t reaCRC_VCC7;
   /** Counter: Reassembled ETH Frames Tx in VCC0 */
   IFX_uint32_t reaMAC_VCC0;
   /** Counter: Reassembled ETH Frames Tx in VCC1 */
   IFX_uint32_t reaMAC_VCC1;
   /** Counter: Reassembled ETH Frames Tx in VCC2 */
   IFX_uint32_t reaMAC_VCC2;
   /** Counter: Reassembled ETH Frames Tx in VCC3 */
   IFX_uint32_t reaMAC_VCC3;
   /** Counter: Reassembled ETH Frames Tx in VCC4 */
   IFX_uint32_t reaMAC_VCC4;
   /** Counter: Reassembled ETH Frames Tx in VCC5 */
   IFX_uint32_t reaMAC_VCC5;
   /** Counter: Reassembled ETH Frames Tx in VCC6 */
   IFX_uint32_t reaMAC_VCC6;
   /** Counter: Reassembled ETH Frames Tx in VCC7 */
   IFX_uint32_t reaMAC_VCC7;
#endif
} __PACKED__ ;


/**
   Requests performance counter values for AAL5 reassembly statistics.
*/
struct CMD_AAL5_ReassemblyStats2Get
{
#if MEI_DRV_OS_BYTE_ORDER == MEI_DRV_OS_BIG_ENDIAN
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Link Number (=Bearer Channel Number) */
   IFX_uint32_t LinkNo;
#else
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Link Number (=Bearer Channel Number) */
   IFX_uint32_t LinkNo;
#endif
} __PACKED__ ;


/**
   Acknowledgement to a CMD_AAL5_ReassemblyStats2Get command. Provides the performance
   counter values for AAL5 reassembly statistics.
*/
struct ACK_AAL5_ReassemblyStats2Get
{
#if MEI_DRV_OS_BYTE_ORDER == MEI_DRV_OS_BIG_ENDIAN
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Link Number (=Bearer Channel Number) */
   IFX_uint32_t LinkNo;
   /** Counter: ETH Frame Length Mismatch for VCC0 */
   IFX_uint32_t reaMaxSDU_VCC0;
   /** Counter: ETH Frame Length Mismatch for VCC1 */
   IFX_uint32_t reaMaxSDU_VCC1;
   /** Counter: ETH Frame Length Mismatch for VCC2 */
   IFX_uint32_t reaMaxSDU_VCC2;
   /** Counter: ETH Frame Length Mismatch for VCC3 */
   IFX_uint32_t reaMaxSDU_VCC3;
   /** Counter: ETH Frame Length Mismatch for VCC4 */
   IFX_uint32_t reaMaxSDU_VCC4;
   /** Counter: ETH Frame Length Mismatch for VCC5 */
   IFX_uint32_t reaMaxSDU_VCC5;
   /** Counter: ETH Frame Length Mismatch for VCC6 */
   IFX_uint32_t reaMaxSDU_VCC6;
   /** Counter: ETH Frame Length Mismatch for VCC7 */
   IFX_uint32_t reaMaxSDU_VCC7;
   /** Counter: ETH Zero-Length Packet Count for VCC0 */
   IFX_uint32_t reaLen0_VCC0;
   /** Counter: ETH Zero-Length Packet Count for VCC1 */
   IFX_uint32_t reaLen0_VCC1;
   /** Counter: ETH Zero-Length Packet Count for VCC2 */
   IFX_uint32_t reaLen0_VCC2;
   /** Counter: ETH Zero-Length Packet Count for VCC3 */
   IFX_uint32_t reaLen0_VCC3;
   /** Counter: ETH Zero-Length Packet Count for VCC4 */
   IFX_uint32_t reaLen0_VCC4;
   /** Counter: ETH Zero-Length Packet Count for VCC5 */
   IFX_uint32_t reaLen0_VCC5;
   /** Counter: ETH Zero-Length Packet Count for VCC6 */
   IFX_uint32_t reaLen0_VCC6;
   /** Counter: ETH Zero-Length Packet Count for VCC7 */
   IFX_uint32_t reaLen0_VCC7;
   /** Counter: ETH Frame Rx Length Mismatch for VCC0 */
   IFX_uint32_t reaLenErr_VCC0;
   /** Counter: ETH Frame Rx Length Mismatch for VCC1 */
   IFX_uint32_t reaLenErr_VCC1;
   /** Counter: ETH Frame Rx Length Mismatch for VCC2 */
   IFX_uint32_t reaLenErr_VCC2;
   /** Counter: ETH Frame Rx Length Mismatch for VCC3 */
   IFX_uint32_t reaLenErr_VCC3;
   /** Counter: ETH Frame Rx Length Mismatch for VCC4 */
   IFX_uint32_t reaLenErr_VCC4;
   /** Counter: ETH Frame Rx Length Mismatch for VCC5 */
   IFX_uint32_t reaLenErr_VCC5;
   /** Counter: ETH Frame Rx Length Mismatch for VCC6 */
   IFX_uint32_t reaLenErr_VCC6;
   /** Counter: ETH Frame Rx Length Mismatch for VCC7 */
   IFX_uint32_t reaLenErr_VCC7;
#else
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Link Number (=Bearer Channel Number) */
   IFX_uint32_t LinkNo;
   /** Counter: ETH Frame Length Mismatch for VCC0 */
   IFX_uint32_t reaMaxSDU_VCC0;
   /** Counter: ETH Frame Length Mismatch for VCC1 */
   IFX_uint32_t reaMaxSDU_VCC1;
   /** Counter: ETH Frame Length Mismatch for VCC2 */
   IFX_uint32_t reaMaxSDU_VCC2;
   /** Counter: ETH Frame Length Mismatch for VCC3 */
   IFX_uint32_t reaMaxSDU_VCC3;
   /** Counter: ETH Frame Length Mismatch for VCC4 */
   IFX_uint32_t reaMaxSDU_VCC4;
   /** Counter: ETH Frame Length Mismatch for VCC5 */
   IFX_uint32_t reaMaxSDU_VCC5;
   /** Counter: ETH Frame Length Mismatch for VCC6 */
   IFX_uint32_t reaMaxSDU_VCC6;
   /** Counter: ETH Frame Length Mismatch for VCC7 */
   IFX_uint32_t reaMaxSDU_VCC7;
   /** Counter: ETH Zero-Length Packet Count for VCC0 */
   IFX_uint32_t reaLen0_VCC0;
   /** Counter: ETH Zero-Length Packet Count for VCC1 */
   IFX_uint32_t reaLen0_VCC1;
   /** Counter: ETH Zero-Length Packet Count for VCC2 */
   IFX_uint32_t reaLen0_VCC2;
   /** Counter: ETH Zero-Length Packet Count for VCC3 */
   IFX_uint32_t reaLen0_VCC3;
   /** Counter: ETH Zero-Length Packet Count for VCC4 */
   IFX_uint32_t reaLen0_VCC4;
   /** Counter: ETH Zero-Length Packet Count for VCC5 */
   IFX_uint32_t reaLen0_VCC5;
   /** Counter: ETH Zero-Length Packet Count for VCC6 */
   IFX_uint32_t reaLen0_VCC6;
   /** Counter: ETH Zero-Length Packet Count for VCC7 */
   IFX_uint32_t reaLen0_VCC7;
   /** Counter: ETH Frame Rx Length Mismatch for VCC0 */
   IFX_uint32_t reaLenErr_VCC0;
   /** Counter: ETH Frame Rx Length Mismatch for VCC1 */
   IFX_uint32_t reaLenErr_VCC1;
   /** Counter: ETH Frame Rx Length Mismatch for VCC2 */
   IFX_uint32_t reaLenErr_VCC2;
   /** Counter: ETH Frame Rx Length Mismatch for VCC3 */
   IFX_uint32_t reaLenErr_VCC3;
   /** Counter: ETH Frame Rx Length Mismatch for VCC4 */
   IFX_uint32_t reaLenErr_VCC4;
   /** Counter: ETH Frame Rx Length Mismatch for VCC5 */
   IFX_uint32_t reaLenErr_VCC5;
   /** Counter: ETH Frame Rx Length Mismatch for VCC6 */
   IFX_uint32_t reaLenErr_VCC6;
   /** Counter: ETH Frame Rx Length Mismatch for VCC7 */
   IFX_uint32_t reaLenErr_VCC7;
#endif
} __PACKED__ ;


/**
   Requests version information from the VDSL2-Modem.
*/
struct CMD_VersionInfoGet
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
   Provides version information about hardware and firmware. The FW version numbering
   scheme differs for VINAX Rev. 1.x (Table542) and Rev. 2.x (Table545). Additionally,
   a short form of the Firmware Version number is defined for both (Rev. 1.x: Table543
   and Rev. 2.x: Table546).
   Note: The Online Firmware numbering scheme for VINAX Rev. 1.x changed with FW
   version 1.4.3.2 to the format listed in Table542.
   Note: The VINAX 1.x "old" numbering Revision scheme (Table544) is still valid for
   the ROM Code Version number.
*/
struct ACK_VersionInfoGet
{
#if MEI_DRV_OS_BYTE_ORDER == MEI_DRV_OS_BIG_ENDIAN
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Hardware Version Number */
   IFX_uint32_t HW_Version;
   /** ROM Code Version Number (VINAX Rev. 1.x only) */
   IFX_uint32_t ROM_Version;
   /** Firmware Version Number (Long) */
   IFX_uint32_t FW_Version;
#else
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Hardware Version Number */
   IFX_uint32_t HW_Version;
   /** ROM Code Version Number (VINAX Rev. 1.x only) */
   IFX_uint32_t ROM_Version;
   /** Firmware Version Number (Long) */
   IFX_uint32_t FW_Version;
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

