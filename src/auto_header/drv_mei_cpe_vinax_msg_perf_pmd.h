/******************************************************************************

                               Copyright (c) 2011
                            Lantiq Deutschland GmbH
                     Am Campeon 3; 85579 Neubiberg, Germany

  For licensing information, see the file 'LICENSE' in the root folder of
  this software module.

******************************************************************************/


#ifndef _VDSL2_FWDES_PERF_PMD_H_
#define _VDSL2_FWDES_PERF_PMD_H_

/** \file
   This chapter contains messages used to get performance data such as failure
   counters.
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

/** @defgroup _VDSL2_FWDES_PERF_PMD_ Messages for Performance Monitoring
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
#define  CMD_TR1ControlSet_NOT_USED  0
#define  CMD_TR1ControlSet_RESET_NOW  1
#define  CMD_TR1ControlSet_RESET_EVER  2
#define  CMD_TR1ControlSet_RESET_TR1  3
#define  CMD_TR1ControlSet_SHORTEN  4
#define  CMD_TR1ControlSet_COPY  5
#define  CMD_TimeControl_READ_TIME  2
#define  ACK_TimeGet_PROG  1
/* ----- Constants Definition section (End) ----- */

/** Message ID for CMD_TR1ControlSet */
#define CMD_TR1CONTROLSET 0x004A

/**
   Controls the behaviour of the performance counters.
*/
typedef struct CMD_TR1ControlSet CMD_TR1ControlSet_t;

/** Message ID for ACK_TR1ControlSet */
#define ACK_TR1CONTROLSET 0x004A

/**
   Acknowledgement for message CMD_TR1ControlSet.
*/
typedef struct ACK_TR1ControlSet ACK_TR1ControlSet_t;

/** Message ID for EVT_TR1Expiry */
#define EVT_TR1EXPIRY 0x8002

/**
   Autonomous message indicating the expiry of a TR1 period.
*/
typedef struct EVT_TR1Expiry EVT_TR1Expiry_t;

/** Message ID for CMD_G997_PMD_StatsThreshSet */
#define CMD_G997_PMD_STATSTHRESHSET 0x014A

/**
   The message configures the thresholds for the "current period" PMD counters. If any
   of the configured thresholds is met within a 15-min TR1 period, an autonomous
   message ALM_TR1CounterThreshHit is sent to the host, provided the ALM generation was
   enabled for it with CMD_TR1ThreshAlarmConfigure.
   (See section 7.3.1.8 of G997.1 [11])
*/
typedef struct CMD_G997_PMD_StatsThreshSet CMD_G997_PMD_StatsThreshSet_t;

/** Message ID for ACK_G997_PMD_StatsThreshSet */
#define ACK_G997_PMD_STATSTHRESHSET 0x014A

/**
   Acknowledgement for message CMD_G997_PMD_StatsThreshSet.
*/
typedef struct ACK_G997_PMD_StatsThreshSet ACK_G997_PMD_StatsThreshSet_t;

/** Message ID for CMD_G997_PMD_StatsThreshGet */
#define CMD_G997_PMD_STATSTHRESHGET 0x010A

/**
   Requests the configured threshold values for the PMD counters. (Chapter 7.3.1.8 of
   G.997.1 [11])
*/
typedef struct CMD_G997_PMD_StatsThreshGet CMD_G997_PMD_StatsThreshGet_t;

/** Message ID for ACK_G997_PMD_StatsThreshGet */
#define ACK_G997_PMD_STATSTHRESHGET 0x010A

/**
   The message reports the thresholds configured for the "current period" PMD counters.
   (see also )
*/
typedef struct ACK_G997_PMD_StatsThreshGet ACK_G997_PMD_StatsThreshGet_t;

/** Message ID for CMD_TR1ThreshAlarmConfigure */
#define CMD_TR1THRESHALARMCONFIGURE 0x0749

/**
   Enables/Disables the generation of ALARM messages (ALM) for specific performance
   counters with TR1 threshold supervision. If the corresponding Enable bit for a
   counter is set, then the modem firmware will send an autonomous message
   ALM_TR1CounterThreshHit if the "current period" counter meets its configured
   threshold.
*/
typedef struct CMD_TR1ThreshAlarmConfigure CMD_TR1ThreshAlarmConfigure_t;

/** Message ID for ACK_TR1ThreshAlarmConfigure */
#define ACK_TR1THRESHALARMCONFIGURE 0x0749

/**
   Acknowledgement to CMD_TR1ThreshAlarmConfigure.
*/
typedef struct ACK_TR1ThreshAlarmConfigure ACK_TR1ThreshAlarmConfigure_t;

/** Message ID for ALM_TR1CounterThreshHit */
#define ALM_TR1COUNTERTHRESHHIT 0x0207

/**
   Autonomous message that reports when TR1 thresholds are reached. It is sent if at
   least one of the "current TR1 period" performance counters with enabled threshold
   supervision met its configured threshold.
*/
typedef struct ALM_TR1CounterThreshHit ALM_TR1CounterThreshHit_t;

/** Message ID for CMD_TR1CounterThreshHit */
#define CMD_TR1COUNTERTHRESHHIT 0x0207

/**
   Requests the threshold exceedance status of the TR1 performance counters.
*/
typedef struct CMD_TR1CounterThreshHit CMD_TR1CounterThreshHit_t;

/** Message ID for ACK_TR1CounterThreshHit */
#define ACK_TR1COUNTERTHRESHHIT 0x0207

/**
   Reports which TR1 performance counters reached or exceeded their individually
   configurable thresholds.
*/
typedef struct ACK_TR1CounterThreshHit ACK_TR1CounterThreshHit_t;

/** Message ID for ALM_LineFailureNE_Get */
#define ALM_LINEFAILURENE_GET 0x0007

/**
   This autonomous message indicates near-end line failures.
*/
typedef struct ALM_LineFailureNE_Get ALM_LineFailureNE_Get_t;

/** Message ID for CMD_LineFailureNE_Get */
#define CMD_LINEFAILURENE_GET 0x0007

/**
   Requests the near-end line failure status.
*/
typedef struct CMD_LineFailureNE_Get CMD_LineFailureNE_Get_t;

/** Message ID for ACK_LineFailureNE_Get */
#define ACK_LINEFAILURENE_GET 0x0007

/**
   Provides the near-end line failure status requested by the command
   CMD_LineFailureNE_Get.
*/
typedef struct ACK_LineFailureNE_Get ACK_LineFailureNE_Get_t;

/** Message ID for ALM_LineFailureFE_Get */
#define ALM_LINEFAILUREFE_GET 0x0107

/**
   This autonomous message indicates far-end line failures.
*/
typedef struct ALM_LineFailureFE_Get ALM_LineFailureFE_Get_t;

/** Message ID for CMD_LineFailureFE_Get */
#define CMD_LINEFAILUREFE_GET 0x0107

/**
   Requests the far-end line failure status.
*/
typedef struct CMD_LineFailureFE_Get CMD_LineFailureFE_Get_t;

/** Message ID for ACK_LineFailureFE_Get */
#define ACK_LINEFAILUREFE_GET 0x0107

/**
   Provides the far-end line failure status requested by the command
   CMD_LineFailureFE_Get.
*/
typedef struct ACK_LineFailureFE_Get ACK_LineFailureFE_Get_t;

/** Message ID for CMD_LinePerfCountNE_Get */
#define CMD_LINEPERFCOUNTNE_GET 0x030A

/**
   Requests near-end line performance counter values (Section 7.2.1.1 of G.997.1) for
   the current and for the previous 15-min-TR1 period.
*/
typedef struct CMD_LinePerfCountNE_Get CMD_LinePerfCountNE_Get_t;

/** Message ID for ACK_LinePerfCountNE_Get */
#define ACK_LINEPERFCOUNTNE_GET 0x030A

/**
   Provides near-end line performance counter values requested by
   CMD_LinePerfCountNE_Get (Section 7.2.1.1 of G.997.1). Contains counter values for
   the current and for the previous 15-min-TR1 interval.
*/
typedef struct ACK_LinePerfCountNE_Get ACK_LinePerfCountNE_Get_t;

/** Message ID for CMD_LinePerfCountFE_Get */
#define CMD_LINEPERFCOUNTFE_GET 0x050A

/**
   Requests far-end line performance counter values (Section 7.2.1.2 of G.997.1) for
   the current and for the previous 15-min-TR1 period.
*/
typedef struct CMD_LinePerfCountFE_Get CMD_LinePerfCountFE_Get_t;

/** Message ID for ACK_LinePerfCountFE_Get */
#define ACK_LINEPERFCOUNTFE_GET 0x050A

/**
   Provides far-end line performance counter values requested by
   CMD_LinePerfCountFE_Get (Section 7.2.1.2 of G.997.1). Contains counter values for
   the current and for the previous 15-min-TR1 interval.
*/
typedef struct ACK_LinePerfCountFE_Get ACK_LinePerfCountFE_Get_t;

/** Message ID for CMD_LineInitCountGet */
#define CMD_LINEINITCOUNTGET 0x070A

/**
   Requests line initialization performance counter values (Section 7.2.1.3 of G.997.1)
   for the current and previous 15-min-TR1 period.
*/
typedef struct CMD_LineInitCountGet CMD_LineInitCountGet_t;

/** Message ID for ACK_LineInitCountGet */
#define ACK_LINEINITCOUNTGET 0x070A

/**
   Provides line initialization performance counter values requested by
   CMD_LineInitCountGet (Section 7.2.1.3 of G.997.1). Contains counter values for the
   current and for the previous 15-min-TR1 interval. The counters are not reset at link
   re-initialization.
   Full Inits Count: Counter of the number of initialization attempts. The counter
   increments each time the modem tries to initialize the line when entering the
   "FULL_INIT" state or - if Loop Diagnostic Mode is run- when entering
   "DIAGMODE".Failed Inits Count: The counter increments when the criteria for an
   "initialization attempt" is met (see above) but STEADY_STATE or DIAG_COMPLETE are
   not reached AND if this was not due to an administrational change (like setting the
   modem FSM explicitely to RESET).
*/
typedef struct ACK_LineInitCountGet ACK_LineInitCountGet_t;

/** Message ID for CMD_CRC_StatsNE_Get */
#define CMD_CRC_STATSNE_GET 0x090A

/**
   Requests near-end CRC counter values.
*/
typedef struct CMD_CRC_StatsNE_Get CMD_CRC_StatsNE_Get_t;

/** Message ID for ACK_CRC_StatsNE_Get */
#define ACK_CRC_STATSNE_GET 0x090A

/**
   Returns near-end CRC counter values. (Section 7.2.2.1.1 of G997.1)
   Note: In VINAX V1.x the "LP1/Fast Path" parameters are fed only in ADSL1 mode
   with selected fast path.
*/
typedef struct ACK_CRC_StatsNE_Get ACK_CRC_StatsNE_Get_t;

/** Message ID for CMD_CRC_StatsFE_Get */
#define CMD_CRC_STATSFE_GET 0x0D0A

/**
   Requests far-end CRC counter values.
*/
typedef struct CMD_CRC_StatsFE_Get CMD_CRC_StatsFE_Get_t;

/** Message ID for ACK_CRC_StatsFE_Get */
#define ACK_CRC_STATSFE_GET 0x0D0A

/**
   Returns far-end CRC counter values. (Section 7.2.2.2.1 of G997.1)
   Note: In VINAX V1.x the "LP1/Fast Path" parameters are fed only in ADSL1 mode
   with selected fast path.
*/
typedef struct ACK_CRC_StatsFE_Get ACK_CRC_StatsFE_Get_t;

/** Message ID for CMD_FEC_StatsNE_Get */
#define CMD_FEC_STATSNE_GET 0x0B0A

/**
   Requests near-end FEC counter values.
*/
typedef struct CMD_FEC_StatsNE_Get CMD_FEC_StatsNE_Get_t;

/** Message ID for ACK_FEC_StatsNE_Get */
#define ACK_FEC_STATSNE_GET 0x0B0A

/**
   Returns near-end FEC counter values. (Section 7.2.2.1.2 of G997.1)
   Note: In VINAX V1.x the "LP1/Fast Path" parameters are fed only in ADSL1 mode
   with selected fast path.
*/
typedef struct ACK_FEC_StatsNE_Get ACK_FEC_StatsNE_Get_t;

/** Message ID for CMD_FEC_StatsFE_Get */
#define CMD_FEC_STATSFE_GET 0x0F0A

/**
   Requests far-end FEC counter values.
*/
typedef struct CMD_FEC_StatsFE_Get CMD_FEC_StatsFE_Get_t;

/** Message ID for ACK_FEC_StatsFE_Get */
#define ACK_FEC_STATSFE_GET 0x0F0A

/**
   Returns the far-end FEC counter values requested by CMD_FEC_StatsFE_Get.(Section
   7.2.2.2.2 of G997.1)
   Note: In VINAX V1.x the "LP1/Fast Path" parameters are fed only in ADSL1 mode
   with selected fast path.
*/
typedef struct ACK_FEC_StatsFE_Get ACK_FEC_StatsFE_Get_t;

/** Message ID for CMD_SOS_StatsNE_Get */
#define CMD_SOS_STATSNE_GET 0x290A

/**
   Requests the near-end 15 minutes SOS TR1 counter values.
*/
typedef struct CMD_SOS_StatsNE_Get CMD_SOS_StatsNE_Get_t;

/** Message ID for ACK_SOS_StatsNE_Get */
#define ACK_SOS_STATSNE_GET 0x290A

/**
   Returns near-end SOS counter values. (Section 7.2.1.6.1 of G997.1)
*/
typedef struct ACK_SOS_StatsNE_Get ACK_SOS_StatsNE_Get_t;

/** Message ID for CMD_SOS_StatsFE_Get */
#define CMD_SOS_STATSFE_GET 0x2A0A

/**
   Requests the far-end 15 minutes SOS TR1 counter values.
*/
typedef struct CMD_SOS_StatsFE_Get CMD_SOS_StatsFE_Get_t;

/** Message ID for ACK_SOS_StatsFE_Get */
#define ACK_SOS_STATSFE_GET 0x2A0A

/**
   Returns far-end SOS TR1 counter values. (Section 7.2.1.7.1 of G997.1)
*/
typedef struct ACK_SOS_StatsFE_Get ACK_SOS_StatsFE_Get_t;

/** Message ID for CMD_LinePerfCountNE_Set */
#define CMD_LINEPERFCOUNTNE_SET 0x034A

/**
   Writes near-end line performance counter values (Section 7.2.1.1 of G.997.1) for the
   current and for the previous 15-min-TR1 period.
*/
typedef struct CMD_LinePerfCountNE_Set CMD_LinePerfCountNE_Set_t;

/** Message ID for ACK_LinePerfCountNE_Set */
#define ACK_LINEPERFCOUNTNE_SET 0x034A

/**
   Provides near-end line performance counter values requested by
   CMD_LinePerfCountNE_Set (Section 7.2.1.1 of G.997.1). Contains counter values for
   the current and for the previous 15-min-TR1 interval.
*/
typedef struct ACK_LinePerfCountNE_Set ACK_LinePerfCountNE_Set_t;

/** Message ID for CMD_LinePerfCountFE_Set */
#define CMD_LINEPERFCOUNTFE_SET 0x054A

/**
   Writes far-end line performance counter values (Section 7.2.1.2 of G.997.1) for the
   current and for the previous 15-min-TR1 period.
*/
typedef struct CMD_LinePerfCountFE_Set CMD_LinePerfCountFE_Set_t;

/** Message ID for ACK_LinePerfCountFE_Set */
#define ACK_LINEPERFCOUNTFE_SET 0x054A

/**
   Acknowledgement for the message CMD_LinePerfCountFE_Set.

*/
typedef struct ACK_LinePerfCountFE_Set ACK_LinePerfCountFE_Set_t;

/** Message ID for CMD_LineInitCountSet */
#define CMD_LINEINITCOUNTSET 0x074A

/**
   Writes line initialization performance counter values (Section 7.2.1.3 of G.997.1)
   for the current and previous 15-min-TR1 period.
*/
typedef struct CMD_LineInitCountSet CMD_LineInitCountSet_t;

/** Message ID for ACK_LineInitCountSet */
#define ACK_LINEINITCOUNTSET 0x074A

/**
   Acknowledgement for the message CMD_LineInitCountSet.
*/
typedef struct ACK_LineInitCountSet ACK_LineInitCountSet_t;

/** Message ID for CMD_CRC_StatsNE_Set */
#define CMD_CRC_STATSNE_SET 0x094A

/**
   Writes the near-end CRC counter values (Section 7.2.2.1.1 of G997.1)
   Note: In VINAX V1.x the "LP1/Fast Path" parameters are used only in ADSL1 mode
   with selected "Fast Path".
*/
typedef struct CMD_CRC_StatsNE_Set CMD_CRC_StatsNE_Set_t;

/** Message ID for ACK_CRC_StatsNE_Set */
#define ACK_CRC_STATSNE_SET 0x094A

/**
   Acknowledgement for the message CMD_CRC_StatsNE_Set.
*/
typedef struct ACK_CRC_StatsNE_Set ACK_CRC_StatsNE_Set_t;

/** Message ID for CMD_CRC_StatsFE_Set */
#define CMD_CRC_STATSFE_SET 0x0D4A

/**
   Writes the far-end CRC counter values (Section 7.2.2.2.1 of G997.1)
   Note: In VINAX V1.x the "LP1/Fast Path" parameters are fed only in ADSL1 mode
   with selected fast path.
*/
typedef struct CMD_CRC_StatsFE_Set CMD_CRC_StatsFE_Set_t;

/** Message ID for ACK_CRC_StatsFE_Set */
#define ACK_CRC_STATSFE_SET 0x0D4A

/**
   Acknowledgement for the message CMD_CRC_StatsFE_Set.
*/
typedef struct ACK_CRC_StatsFE_Set ACK_CRC_StatsFE_Set_t;

/** Message ID for CMD_FEC_StatsNE_Set */
#define CMD_FEC_STATSNE_SET 0x0B4A

/**
   Writes near-end FEC counter values. (Section 7.2.2.1.2 of G997.1)
   Note: In VINAX V1.x the "LP1/Fast Path" parameters are used only in ADSL1 mode
   with selected "Fast Path".
*/
typedef struct CMD_FEC_StatsNE_Set CMD_FEC_StatsNE_Set_t;

/** Message ID for ACK_FEC_StatsNE_Set */
#define ACK_FEC_STATSNE_SET 0x0B4A

/**
   Acknowledgement for the message CMD_FEC_StatsNE_Set.
*/
typedef struct ACK_FEC_StatsNE_Set ACK_FEC_StatsNE_Set_t;

/** Message ID for CMD_FEC_StatsFE_Set */
#define CMD_FEC_STATSFE_SET 0x0F4A

/**
   Writes near-end FEC counter values. (Section 7.2.2.2.2 of G997.1)
   Note: In VINAX V1.x the "LP1/Fast Path" parameters are used only in ADSL1 mode
   with selected "Fast Path".
*/
typedef struct CMD_FEC_StatsFE_Set CMD_FEC_StatsFE_Set_t;

/** Message ID for ACK_FEC_StatsFE_Set */
#define ACK_FEC_STATSFE_SET 0x0F4A

/**
   Acknowledgement for the message CMD_FEC_StatsFE_Set.
*/
typedef struct ACK_FEC_StatsFE_Set ACK_FEC_StatsFE_Set_t;

/** Message ID for CMD_LinePerfCountNE_NoTR1Get */
#define CMD_LINEPERFCOUNTNE_NOTR1GET 0x020A

/**
   Requests near-end line performance counter values (Section 7.2.1.1 of G.997.1).
   These are wrap-around counters which are not affected by the TR1-period.
*/
typedef struct CMD_LinePerfCountNE_NoTR1Get CMD_LinePerfCountNE_NoTR1Get_t;

/** Message ID for ACK_LinePerfCountNE_NoTR1Get */
#define ACK_LINEPERFCOUNTNE_NOTR1GET 0x020A

/**
   Provides near-end line performance counter values requested by
   CMD_LinePerfCountNE_NoTR1Get (Section 7.2.1.1 of G.997.1). These are wrap-around
   counters which are not affected by the TR1-period.
*/
typedef struct ACK_LinePerfCountNE_NoTR1Get ACK_LinePerfCountNE_NoTR1Get_t;

/** Message ID for CMD_LinePerfCountFE_NoTR1Get */
#define CMD_LINEPERFCOUNTFE_NOTR1GET 0x040A

/**
   Requests far-end line performance counter values (Section 7.2.1.2 of G.997.1). These
   are wrap-around counters which are not affected by the TR1-period.
*/
typedef struct CMD_LinePerfCountFE_NoTR1Get CMD_LinePerfCountFE_NoTR1Get_t;

/** Message ID for ACK_LinePerfCountFE_NoTR1Get */
#define ACK_LINEPERFCOUNTFE_NOTR1GET 0x040A

/**
   Provides far-end line performance counter values requested by
   CMD_LinePerfCountFE_NoTR1Get (Section 7.2.1.2 of G.997.1). These are wrap-around
   counters which are not affected by the TR1-period.
*/
typedef struct ACK_LinePerfCountFE_NoTR1Get ACK_LinePerfCountFE_NoTR1Get_t;

/** Message ID for CMD_CRC_StatsNE_NoTR1Get */
#define CMD_CRC_STATSNE_NOTR1GET 0x080A

/**
   Requests near-end CRC counter values. These are wrap-around counters which are not
   affected by the TR1-period.
*/
typedef struct CMD_CRC_StatsNE_NoTR1Get CMD_CRC_StatsNE_NoTR1Get_t;

/** Message ID for ACK_CRC_StatsNE_NoTR1Get */
#define ACK_CRC_STATSNE_NOTR1GET 0x080A

/**
   Returns near-end CRC counter values. (Section 7.2.2.1.1 of G997.1). These are
   wrap-around counters which are not affected by the TR1-period.
*/
typedef struct ACK_CRC_StatsNE_NoTR1Get ACK_CRC_StatsNE_NoTR1Get_t;

/** Message ID for CMD_CRC_StatsFE_NoTR1Get */
#define CMD_CRC_STATSFE_NOTR1GET 0x0C0A

/**
   Requests far-end CRC counter values. These are wrap-around counters which are not
   affected by the TR1-period.
*/
typedef struct CMD_CRC_StatsFE_NoTR1Get CMD_CRC_StatsFE_NoTR1Get_t;

/** Message ID for ACK_CRC_StatsFE_NoTR1Get */
#define ACK_CRC_STATSFE_NOTR1GET 0x0C0A

/**
   Returns far-end CRC counter values. (Section 7.2.2.2.1 of G997.1). These are
   wrap-around counters which are not affected by the TR1-period.
*/
typedef struct ACK_CRC_StatsFE_NoTR1Get ACK_CRC_StatsFE_NoTR1Get_t;

/** Message ID for CMD_FEC_StatsNE_NoTR1Get */
#define CMD_FEC_STATSNE_NOTR1GET 0x0A0A

/**
   Requests near-end FEC counter values. These are wrap-around counters which are not
   affected by the TR1-period.
*/
typedef struct CMD_FEC_StatsNE_NoTR1Get CMD_FEC_StatsNE_NoTR1Get_t;

/** Message ID for ACK_FEC_StatsNE_NoTR1Get */
#define ACK_FEC_STATSNE_NOTR1GET 0x0A0A

/**
   Returns near-end FEC counter values (Section 7.2.2.1.2 of G997.1). These are
   wrap-around counters which are not affected by the TR1-period.
*/
typedef struct ACK_FEC_StatsNE_NoTR1Get ACK_FEC_StatsNE_NoTR1Get_t;

/** Message ID for CMD_FEC_StatsFE_NoTR1Get */
#define CMD_FEC_STATSFE_NOTR1GET 0x0E0A

/**
   Requests far-end FEC counter values. These are wrap-around counters which are not
   affected by the TR1-period.
*/
typedef struct CMD_FEC_StatsFE_NoTR1Get CMD_FEC_StatsFE_NoTR1Get_t;

/** Message ID for ACK_FEC_StatsFE_NoTR1Get */
#define ACK_FEC_STATSFE_NOTR1GET 0x0E0A

/**
   Returns far-end FEC counter values (Section 7.2.2.2.2 of G997.1). These are
   wrap-around counters which are not affected by the TR1-period.
*/
typedef struct ACK_FEC_StatsFE_NoTR1Get ACK_FEC_StatsFE_NoTR1Get_t;

/** Message ID for CMD_LinePerfCountNE_NoTR1Set */
#define CMD_LINEPERFCOUNTNE_NOTR1SET 0x024A

/**
   Writes near-end line performance counter values (Section 7.2.1.1 of G.997.1). These
   are wrap-around counters which are not affected by the TR1-period.
*/
typedef struct CMD_LinePerfCountNE_NoTR1Set CMD_LinePerfCountNE_NoTR1Set_t;

/** Message ID for ACK_LinePerfCountNE_NoTR1Set */
#define ACK_LINEPERFCOUNTNE_NOTR1SET 0x024A

/**
   Acknowledgement for message CMD_LinePerfCountNE_NoTR1Set.
*/
typedef struct ACK_LinePerfCountNE_NoTR1Set ACK_LinePerfCountNE_NoTR1Set_t;

/** Message ID for CMD_CRC_StatsNE_NoTR1Set */
#define CMD_CRC_STATSNE_NOTR1SET 0x084A

/**
   Writes near-end CRC counter values. (Section 7.2.2.1.1 of G997.1). These are
   wrap-around counters which are not affected by the TR1-period.
*/
typedef struct CMD_CRC_StatsNE_NoTR1Set CMD_CRC_StatsNE_NoTR1Set_t;

/** Message ID for ACK_CRC_StatsNE_NoTR1Set */
#define ACK_CRC_STATSNE_NOTR1SET 0x084A

/**
   Acknowledgement for message CMD_CRC_StatsNE_NoTR1Set.
*/
typedef struct ACK_CRC_StatsNE_NoTR1Set ACK_CRC_StatsNE_NoTR1Set_t;

/** Message ID for CMD_FEC_StatsNE_NoTR1Set */
#define CMD_FEC_STATSNE_NOTR1SET 0x0A4A

/**
   Writes near-end FEC counter values (Section 7.2.2.1.2 of G997.1). These are
   wrap-around counters which are not affected by the TR1-period.
*/
typedef struct CMD_FEC_StatsNE_NoTR1Set CMD_FEC_StatsNE_NoTR1Set_t;

/** Message ID for ACK_FEC_StatsNE_NoTR1Set */
#define ACK_FEC_STATSNE_NOTR1SET 0x0A4A

/**
   Acknowledgement for message CMD_FEC_StatsNE_NoTR1Set.
*/
typedef struct ACK_FEC_StatsNE_NoTR1Set ACK_FEC_StatsNE_NoTR1Set_t;

/** Message ID for CMD_TimeControl */
#define CMD_TIMECONTROL 0x0E49

/**
   Controls the "Set-Time" and "Read-Time" EOC messages to either synchronize or read
   the time of the xTU-R.
   Note: Modifying the Time does not affect the TR1 supervision period and the
   TR1-counters.
*/
typedef struct CMD_TimeControl CMD_TimeControl_t;

/** Message ID for ACK_TimeControl */
#define ACK_TIMECONTROL 0x0E49

/**
   Acknowledgement for message CMD_TimeControl.
*/
typedef struct ACK_TimeControl ACK_TimeControl_t;

/** Message ID for CMD_TimeSet */
#define CMD_TIMESET 0x6143

/**
   Sets the time.
   To synchronize the time of the xTU-C and xTU-R, the xTU-C sets the far-end time
   parameter and then triggers the sending of the EOC time command to transfer the
   configured value to the opposite side using CMD_TimeControl.
   Note: Modifying the Time does not affect the TR1 supervision period and the
   TR1-counters.
*/
typedef struct CMD_TimeSet CMD_TimeSet_t;

/** Message ID for ACK_TimeSet */
#define ACK_TIMESET 0x6143

/**
   Acknowledgement for message CMD_TimeSet.
*/
typedef struct ACK_TimeSet ACK_TimeSet_t;

/** Message ID for CMD_TimeGet */
#define CMD_TIMEGET 0x6103

/**
   Requests the status of the "Set Time and Read Time" EOC messages.
*/
typedef struct CMD_TimeGet CMD_TimeGet_t;

/** Message ID for ACK_TimeGet */
#define ACK_TIMEGET 0x6103

/**
   Provides the status of the "Set Time and Read Time" EOC messages.
*/
typedef struct ACK_TimeGet ACK_TimeGet_t;

/**
   Controls the behaviour of the performance counters.
*/
struct CMD_TR1ControlSet
{
#if MEI_DRV_OS_BYTE_ORDER == MEI_DRV_OS_BIG_ENDIAN
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** TR1 Period */
   IFX_uint16_t period;
   /** Reserved */
   IFX_uint16_t Res03 : 13;
   /** TR1 Counter Inhibiting Enable */
   IFX_uint16_t CntInhibitEnable : 1;
   /** TR1 EVT Enable */
   IFX_uint16_t TR1_EVT_Enable : 1;
   /** TR1 Enable */
   IFX_uint16_t TR1enable : 1;
   /** Reserved */
   IFX_uint16_t Res07 : 13;
   /** TR1 Control */
   IFX_uint16_t TR1Control : 3;
   /** TR1 Adjust */
   IFX_uint16_t TR1Adjust;
#else
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** TR1 Period */
   IFX_uint16_t period;
   /** TR1 Enable */
   IFX_uint16_t TR1enable : 1;
   /** TR1 EVT Enable */
   IFX_uint16_t TR1_EVT_Enable : 1;
   /** TR1 Counter Inhibiting Enable */
   IFX_uint16_t CntInhibitEnable : 1;
   /** Reserved */
   IFX_uint16_t Res03 : 13;
   /** TR1 Control */
   IFX_uint16_t TR1Control : 3;
   /** Reserved */
   IFX_uint16_t Res07 : 13;
   /** TR1 Adjust */
   IFX_uint16_t TR1Adjust;
#endif
} __PACKED__ ;


/**
   Acknowledgement for message CMD_TR1ControlSet.
*/
struct ACK_TR1ControlSet
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
   Autonomous message indicating the expiry of a TR1 period.
*/
struct EVT_TR1Expiry
{
#if MEI_DRV_OS_BYTE_ORDER == MEI_DRV_OS_BIG_ENDIAN
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Reserved */
   IFX_uint16_t Res02;
#else
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Reserved */
   IFX_uint16_t Res02;
#endif
} __PACKED__ ;


/**
   The message configures the thresholds for the "current period" PMD counters. If any
   of the configured thresholds is met within a 15-min TR1 period, an autonomous
   message ALM_TR1CounterThreshHit is sent to the host, provided the ALM generation was
   enabled for it with CMD_TR1ThreshAlarmConfigure.
   (See section 7.3.1.8 of G997.1 [11])
*/
struct CMD_G997_PMD_StatsThreshSet
{
#if MEI_DRV_OS_BYTE_ORDER == MEI_DRV_OS_BIG_ENDIAN
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Threshold FECS NE */
   IFX_uint16_t threshFECS_NE;
   /** Threshold ES NE */
   IFX_uint16_t threshES_NE;
   /** Threshold SES NE */
   IFX_uint16_t threshSES_NE;
   /** Threshold LOSS NE */
   IFX_uint16_t threshLOSS_NE;
   /** Threshold UAS NE */
   IFX_uint16_t threshUAS_NE;
   /** Threshold CRC NE LP0, LSW */
   IFX_uint16_t threshCVI_NE_LSW;
   /** Threshold CRC NE LP0, MSW */
   IFX_uint16_t threshCVI_NE_MSW;
   /** Threshold FEC NE LP0, LSW */
   IFX_uint16_t threshECI_NE_LSW;
   /** Threshold FEC NE LP0, MSW */
   IFX_uint16_t threshECI_NE_MSW;
   /** Reserved */
   IFX_uint16_t Res11;
   /** Threshold FECS FE */
   IFX_uint16_t threshFECS_FE;
   /** Threshold ES FE */
   IFX_uint16_t threshES_FE;
   /** Threshold SES FE */
   IFX_uint16_t threshSES_FE;
   /** Threshold LOSS FE */
   IFX_uint16_t threshLOSS_FE;
   /** Threshold UAS FE */
   IFX_uint16_t threshUAS_FE;
   /** Threshold CRC FE LP0, LSW */
   IFX_uint16_t threshCVI_FE_LSW;
   /** Threshold CRC FE LP0, MSW */
   IFX_uint16_t threshCVI_FE_MSW;
   /** Threshold FEC FE LP0, LSW */
   IFX_uint16_t threshECI_FE_LSW;
   /** Threshold FEC FE LP0, MSW */
   IFX_uint16_t threshECI_FE_MSW;
#else
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Threshold FECS NE */
   IFX_uint16_t threshFECS_NE;
   /** Threshold ES NE */
   IFX_uint16_t threshES_NE;
   /** Threshold SES NE */
   IFX_uint16_t threshSES_NE;
   /** Threshold LOSS NE */
   IFX_uint16_t threshLOSS_NE;
   /** Threshold UAS NE */
   IFX_uint16_t threshUAS_NE;
   /** Threshold CRC NE LP0, LSW */
   IFX_uint16_t threshCVI_NE_LSW;
   /** Threshold CRC NE LP0, MSW */
   IFX_uint16_t threshCVI_NE_MSW;
   /** Threshold FEC NE LP0, LSW */
   IFX_uint16_t threshECI_NE_LSW;
   /** Threshold FEC NE LP0, MSW */
   IFX_uint16_t threshECI_NE_MSW;
   /** Reserved */
   IFX_uint16_t Res11;
   /** Threshold FECS FE */
   IFX_uint16_t threshFECS_FE;
   /** Threshold ES FE */
   IFX_uint16_t threshES_FE;
   /** Threshold SES FE */
   IFX_uint16_t threshSES_FE;
   /** Threshold LOSS FE */
   IFX_uint16_t threshLOSS_FE;
   /** Threshold UAS FE */
   IFX_uint16_t threshUAS_FE;
   /** Threshold CRC FE LP0, LSW */
   IFX_uint16_t threshCVI_FE_LSW;
   /** Threshold CRC FE LP0, MSW */
   IFX_uint16_t threshCVI_FE_MSW;
   /** Threshold FEC FE LP0, LSW */
   IFX_uint16_t threshECI_FE_LSW;
   /** Threshold FEC FE LP0, MSW */
   IFX_uint16_t threshECI_FE_MSW;
#endif
} __PACKED__ ;


/**
   Acknowledgement for message CMD_G997_PMD_StatsThreshSet.
*/
struct ACK_G997_PMD_StatsThreshSet
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
   Requests the configured threshold values for the PMD counters. (Chapter 7.3.1.8 of
   G.997.1 [11])
*/
struct CMD_G997_PMD_StatsThreshGet
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
   The message reports the thresholds configured for the "current period" PMD counters.
   (see also )
*/
struct ACK_G997_PMD_StatsThreshGet
{
#if MEI_DRV_OS_BYTE_ORDER == MEI_DRV_OS_BIG_ENDIAN
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Threshold FECS NE */
   IFX_uint16_t threshFECS_NE;
   /** Threshold ES NE */
   IFX_uint16_t threshES_NE;
   /** Threshold SES NE */
   IFX_uint16_t threshSES_NE;
   /** Threshold LOSS NE */
   IFX_uint16_t threshLOSS_NE;
   /** Threshold UAS NE */
   IFX_uint16_t threshUAS_NE;
   /** Threshold CRC NE LP0, LSW */
   IFX_uint16_t threshCVI_NE_LSW;
   /** Threshold CRC NE LP0, MSW */
   IFX_uint16_t threshCVI_NE_MSW;
   /** Threshold FEC NE LP0, LSW */
   IFX_uint16_t threshECI_NE_LSW;
   /** Threshold FEC NE LP0, MSW */
   IFX_uint16_t threshECI_NE_MSW;
   /** Reserved */
   IFX_uint16_t Res11;
   /** Threshold FECS FE */
   IFX_uint16_t threshFECS_FE;
   /** Threshold ES FE */
   IFX_uint16_t threshES_FE;
   /** Threshold SES FE */
   IFX_uint16_t threshSES_FE;
   /** Threshold LOSS FE */
   IFX_uint16_t threshLOSS_FE;
   /** Threshold UAS FE */
   IFX_uint16_t threshUAS_FE;
   /** Threshold CRC FE LP0, LSW */
   IFX_uint16_t threshCVI_FE_LSW;
   /** Threshold CRC FE LP0, MSW */
   IFX_uint16_t threshCVI_FE_MSW;
   /** Threshold FEC FE LP0, LSW */
   IFX_uint16_t threshECI_FE_LSW;
   /** Threshold FEC FE LP0, MSW */
   IFX_uint16_t threshECI_FE_MSW;
#else
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Threshold FECS NE */
   IFX_uint16_t threshFECS_NE;
   /** Threshold ES NE */
   IFX_uint16_t threshES_NE;
   /** Threshold SES NE */
   IFX_uint16_t threshSES_NE;
   /** Threshold LOSS NE */
   IFX_uint16_t threshLOSS_NE;
   /** Threshold UAS NE */
   IFX_uint16_t threshUAS_NE;
   /** Threshold CRC NE LP0, LSW */
   IFX_uint16_t threshCVI_NE_LSW;
   /** Threshold CRC NE LP0, MSW */
   IFX_uint16_t threshCVI_NE_MSW;
   /** Threshold FEC NE LP0, LSW */
   IFX_uint16_t threshECI_NE_LSW;
   /** Threshold FEC NE LP0, MSW */
   IFX_uint16_t threshECI_NE_MSW;
   /** Reserved */
   IFX_uint16_t Res11;
   /** Threshold FECS FE */
   IFX_uint16_t threshFECS_FE;
   /** Threshold ES FE */
   IFX_uint16_t threshES_FE;
   /** Threshold SES FE */
   IFX_uint16_t threshSES_FE;
   /** Threshold LOSS FE */
   IFX_uint16_t threshLOSS_FE;
   /** Threshold UAS FE */
   IFX_uint16_t threshUAS_FE;
   /** Threshold CRC FE LP0, LSW */
   IFX_uint16_t threshCVI_FE_LSW;
   /** Threshold CRC FE LP0, MSW */
   IFX_uint16_t threshCVI_FE_MSW;
   /** Threshold FEC FE LP0, LSW */
   IFX_uint16_t threshECI_FE_LSW;
   /** Threshold FEC FE LP0, MSW */
   IFX_uint16_t threshECI_FE_MSW;
#endif
} __PACKED__ ;


/**
   Enables/Disables the generation of ALARM messages (ALM) for specific performance
   counters with TR1 threshold supervision. If the corresponding Enable bit for a
   counter is set, then the modem firmware will send an autonomous message
   ALM_TR1CounterThreshHit if the "current period" counter meets its configured
   threshold.
*/
struct CMD_TR1ThreshAlarmConfigure
{
#if MEI_DRV_OS_BYTE_ORDER == MEI_DRV_OS_BIG_ENDIAN
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** NE Enable Bit15 */
   IFX_uint16_t NE15 : 1;
   /** NE Enable Bit14 */
   IFX_uint16_t NE14 : 1;
   /** Reserved */
   IFX_uint16_t Res04 : 7;
   /** NE Enable Bit6 */
   IFX_uint16_t NE6 : 1;
   /** NE Enable Bit5 */
   IFX_uint16_t NE5 : 1;
   /** NE Enable Bit4 */
   IFX_uint16_t NE4 : 1;
   /** NE Enable Bit3 */
   IFX_uint16_t NE3 : 1;
   /** NE Enable Bit2 */
   IFX_uint16_t NE2 : 1;
   /** NE Enable Bit1 */
   IFX_uint16_t NE1 : 1;
   /** NE Enable Bit0 */
   IFX_uint16_t NE0 : 1;
   /** Reserved */
   IFX_uint16_t Res12 : 9;
   /** FE Enable Bit6 */
   IFX_uint16_t FE6 : 1;
   /** FE Enable Bit5 */
   IFX_uint16_t FE5 : 1;
   /** FE Enable Bit4 */
   IFX_uint16_t FE4 : 1;
   /** FE Enable Bit3 */
   IFX_uint16_t FE3 : 1;
   /** FE Enable Bit2 */
   IFX_uint16_t FE2 : 1;
   /** FE Enable Bit1 */
   IFX_uint16_t FE1 : 1;
   /** FE Enable Bit0 */
   IFX_uint16_t FE0 : 1;
   /** Reserved */
   IFX_uint16_t Res20 : 8;
   /** Near-End HEC-P Latency Path 1 */
   IFX_uint16_t hecp_l1 : 1;
   /** Near-End CD-P Latency Path 1 */
   IFX_uint16_t cdp_l1 : 1;
   /** Near-End CU-P Latency Path 1 */
   IFX_uint16_t cup_l1 : 1;
   /** Near-End IBE-P Latency Path 1 */
   IFX_uint16_t ibep_l1 : 1;
   /** Near-End HEC-P Latency Path 0 */
   IFX_uint16_t hecp_l0 : 1;
   /** Near-End CD-P Latency Path 0 */
   IFX_uint16_t cdp_l0 : 1;
   /** Near-End CU-P Latency Path 0 */
   IFX_uint16_t cup_l0 : 1;
   /** Near-End IBE-P Latency Path 0 */
   IFX_uint16_t ibep_l0 : 1;
   /** Reserved */
   IFX_uint16_t Res29 : 8;
   /** Far-End HEC-PFE Latency Path 1 */
   IFX_uint16_t hecpfe_l1 : 1;
   /** Far-End CD-PFE Latency Path 1 */
   IFX_uint16_t cdpfe_l1 : 1;
   /** Far-End CU-PFE Latency Path 1 */
   IFX_uint16_t cupfe_l1 : 1;
   /** Far-End IBE-PFE Latency Path 1 */
   IFX_uint16_t ibepfe_l1 : 1;
   /** Far-End HEC-PFE Latency Path 0 */
   IFX_uint16_t hecpfe_l0 : 1;
   /** Far-End CD-PFE Latency Path 0 */
   IFX_uint16_t cdpfe_l0 : 1;
   /** Far-End CU-PFE Latency Path 0 */
   IFX_uint16_t cupfe_l0 : 1;
   /** Far-End IBE-PFE Latency Path 0 */
   IFX_uint16_t ibepfe_l0 : 1;
#else
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** NE Enable Bit0 */
   IFX_uint16_t NE0 : 1;
   /** NE Enable Bit1 */
   IFX_uint16_t NE1 : 1;
   /** NE Enable Bit2 */
   IFX_uint16_t NE2 : 1;
   /** NE Enable Bit3 */
   IFX_uint16_t NE3 : 1;
   /** NE Enable Bit4 */
   IFX_uint16_t NE4 : 1;
   /** NE Enable Bit5 */
   IFX_uint16_t NE5 : 1;
   /** NE Enable Bit6 */
   IFX_uint16_t NE6 : 1;
   /** Reserved */
   IFX_uint16_t Res04 : 7;
   /** NE Enable Bit14 */
   IFX_uint16_t NE14 : 1;
   /** NE Enable Bit15 */
   IFX_uint16_t NE15 : 1;
   /** FE Enable Bit0 */
   IFX_uint16_t FE0 : 1;
   /** FE Enable Bit1 */
   IFX_uint16_t FE1 : 1;
   /** FE Enable Bit2 */
   IFX_uint16_t FE2 : 1;
   /** FE Enable Bit3 */
   IFX_uint16_t FE3 : 1;
   /** FE Enable Bit4 */
   IFX_uint16_t FE4 : 1;
   /** FE Enable Bit5 */
   IFX_uint16_t FE5 : 1;
   /** FE Enable Bit6 */
   IFX_uint16_t FE6 : 1;
   /** Reserved */
   IFX_uint16_t Res12 : 9;
   /** Near-End IBE-P Latency Path 0 */
   IFX_uint16_t ibep_l0 : 1;
   /** Near-End CU-P Latency Path 0 */
   IFX_uint16_t cup_l0 : 1;
   /** Near-End CD-P Latency Path 0 */
   IFX_uint16_t cdp_l0 : 1;
   /** Near-End HEC-P Latency Path 0 */
   IFX_uint16_t hecp_l0 : 1;
   /** Near-End IBE-P Latency Path 1 */
   IFX_uint16_t ibep_l1 : 1;
   /** Near-End CU-P Latency Path 1 */
   IFX_uint16_t cup_l1 : 1;
   /** Near-End CD-P Latency Path 1 */
   IFX_uint16_t cdp_l1 : 1;
   /** Near-End HEC-P Latency Path 1 */
   IFX_uint16_t hecp_l1 : 1;
   /** Reserved */
   IFX_uint16_t Res20 : 8;
   /** Far-End IBE-PFE Latency Path 0 */
   IFX_uint16_t ibepfe_l0 : 1;
   /** Far-End CU-PFE Latency Path 0 */
   IFX_uint16_t cupfe_l0 : 1;
   /** Far-End CD-PFE Latency Path 0 */
   IFX_uint16_t cdpfe_l0 : 1;
   /** Far-End HEC-PFE Latency Path 0 */
   IFX_uint16_t hecpfe_l0 : 1;
   /** Far-End IBE-PFE Latency Path 1 */
   IFX_uint16_t ibepfe_l1 : 1;
   /** Far-End CU-PFE Latency Path 1 */
   IFX_uint16_t cupfe_l1 : 1;
   /** Far-End CD-PFE Latency Path 1 */
   IFX_uint16_t cdpfe_l1 : 1;
   /** Far-End HEC-PFE Latency Path 1 */
   IFX_uint16_t hecpfe_l1 : 1;
   /** Reserved */
   IFX_uint16_t Res29 : 8;
#endif
} __PACKED__ ;


/**
   Acknowledgement to CMD_TR1ThreshAlarmConfigure.
*/
struct ACK_TR1ThreshAlarmConfigure
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
   Autonomous message that reports when TR1 thresholds are reached. It is sent if at
   least one of the "current TR1 period" performance counters with enabled threshold
   supervision met its configured threshold.
*/
struct ALM_TR1CounterThreshHit
{
#if MEI_DRV_OS_BYTE_ORDER == MEI_DRV_OS_BIG_ENDIAN
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** TC CRC NE */
   IFX_uint16_t NE15 : 1;
   /** TC CV NE */
   IFX_uint16_t NE14 : 1;
   /** Reserved */
   IFX_uint16_t Res04 : 7;
   /** FEC NE */
   IFX_uint16_t NE6 : 1;
   /** CRC NE */
   IFX_uint16_t NE5 : 1;
   /** UAS NE */
   IFX_uint16_t NE4 : 1;
   /** LOSS NE */
   IFX_uint16_t NE3 : 1;
   /** SES NE */
   IFX_uint16_t NE2 : 1;
   /** ES NE */
   IFX_uint16_t NE1 : 1;
   /** FECS NE */
   IFX_uint16_t NE0 : 1;
   /** Reserved */
   IFX_uint16_t Res12 : 9;
   /** FEC (ECI) FE */
   IFX_uint16_t FE6 : 1;
   /** FEC (CVI) FE */
   IFX_uint16_t FE5 : 1;
   /** UAS FE */
   IFX_uint16_t FE4 : 1;
   /** LOSS FE */
   IFX_uint16_t FE3 : 1;
   /** SES FE */
   IFX_uint16_t FE2 : 1;
   /** ES FE */
   IFX_uint16_t FE1 : 1;
   /** FECS FE */
   IFX_uint16_t FE0 : 1;
   /** Reserved */
   IFX_uint16_t Res20 : 8;
   /** Near-End HEC-P Latency Path 1 */
   IFX_uint16_t hecp_l1 : 1;
   /** Near-End CD-P Latency Path 1 */
   IFX_uint16_t cdp_l1 : 1;
   /** Near-End CU-P Latency Path 1 */
   IFX_uint16_t cup_l1 : 1;
   /** Near-End IBE-P Latency Path 1 */
   IFX_uint16_t ibep_l1 : 1;
   /** Near-End HEC-P Latency Path 0 */
   IFX_uint16_t hecp_l0 : 1;
   /** Near-End CD-P Latency Path 0 */
   IFX_uint16_t cdp_l0 : 1;
   /** Near-End CU-P Latency Path 0 */
   IFX_uint16_t cup_l0 : 1;
   /** Near-End IBE-P Latency Path 0 */
   IFX_uint16_t ibep_l0 : 1;
   /** Reserved */
   IFX_uint16_t Res29 : 8;
   /** Far-End HEC-PFE Latency Path 1 */
   IFX_uint16_t hecpfe_l1 : 1;
   /** Far-End CD-PFE Latency Path 1 */
   IFX_uint16_t cdpfe_l1 : 1;
   /** Far-End CU-PFE Latency Path 1 */
   IFX_uint16_t cupfe_l1 : 1;
   /** Far-End IBE-PFE Latency Path 1 */
   IFX_uint16_t ibepfe_l1 : 1;
   /** Far-End HEC-PFE Latency Path 0 */
   IFX_uint16_t hecpfe_l0 : 1;
   /** Far-End CD-PFE Latency Path 0 */
   IFX_uint16_t cdpfe_l0 : 1;
   /** Far-End CU-PFE Latency Path 0 */
   IFX_uint16_t cupfe_l0 : 1;
   /** Far-End IBE-PFE Latency Path 0 */
   IFX_uint16_t ibepfe_l0 : 1;
   /** Time Stamp */
   IFX_uint16_t timestamp;
#else
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** FECS NE */
   IFX_uint16_t NE0 : 1;
   /** ES NE */
   IFX_uint16_t NE1 : 1;
   /** SES NE */
   IFX_uint16_t NE2 : 1;
   /** LOSS NE */
   IFX_uint16_t NE3 : 1;
   /** UAS NE */
   IFX_uint16_t NE4 : 1;
   /** CRC NE */
   IFX_uint16_t NE5 : 1;
   /** FEC NE */
   IFX_uint16_t NE6 : 1;
   /** Reserved */
   IFX_uint16_t Res04 : 7;
   /** TC CV NE */
   IFX_uint16_t NE14 : 1;
   /** TC CRC NE */
   IFX_uint16_t NE15 : 1;
   /** FECS FE */
   IFX_uint16_t FE0 : 1;
   /** ES FE */
   IFX_uint16_t FE1 : 1;
   /** SES FE */
   IFX_uint16_t FE2 : 1;
   /** LOSS FE */
   IFX_uint16_t FE3 : 1;
   /** UAS FE */
   IFX_uint16_t FE4 : 1;
   /** FEC (CVI) FE */
   IFX_uint16_t FE5 : 1;
   /** FEC (ECI) FE */
   IFX_uint16_t FE6 : 1;
   /** Reserved */
   IFX_uint16_t Res12 : 9;
   /** Near-End IBE-P Latency Path 0 */
   IFX_uint16_t ibep_l0 : 1;
   /** Near-End CU-P Latency Path 0 */
   IFX_uint16_t cup_l0 : 1;
   /** Near-End CD-P Latency Path 0 */
   IFX_uint16_t cdp_l0 : 1;
   /** Near-End HEC-P Latency Path 0 */
   IFX_uint16_t hecp_l0 : 1;
   /** Near-End IBE-P Latency Path 1 */
   IFX_uint16_t ibep_l1 : 1;
   /** Near-End CU-P Latency Path 1 */
   IFX_uint16_t cup_l1 : 1;
   /** Near-End CD-P Latency Path 1 */
   IFX_uint16_t cdp_l1 : 1;
   /** Near-End HEC-P Latency Path 1 */
   IFX_uint16_t hecp_l1 : 1;
   /** Reserved */
   IFX_uint16_t Res20 : 8;
   /** Far-End IBE-PFE Latency Path 0 */
   IFX_uint16_t ibepfe_l0 : 1;
   /** Far-End CU-PFE Latency Path 0 */
   IFX_uint16_t cupfe_l0 : 1;
   /** Far-End CD-PFE Latency Path 0 */
   IFX_uint16_t cdpfe_l0 : 1;
   /** Far-End HEC-PFE Latency Path 0 */
   IFX_uint16_t hecpfe_l0 : 1;
   /** Far-End IBE-PFE Latency Path 1 */
   IFX_uint16_t ibepfe_l1 : 1;
   /** Far-End CU-PFE Latency Path 1 */
   IFX_uint16_t cupfe_l1 : 1;
   /** Far-End CD-PFE Latency Path 1 */
   IFX_uint16_t cdpfe_l1 : 1;
   /** Far-End HEC-PFE Latency Path 1 */
   IFX_uint16_t hecpfe_l1 : 1;
   /** Reserved */
   IFX_uint16_t Res29 : 8;
   /** Time Stamp */
   IFX_uint16_t timestamp;
#endif
} __PACKED__ ;


/**
   Requests the threshold exceedance status of the TR1 performance counters.
*/
struct CMD_TR1CounterThreshHit
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
   Reports which TR1 performance counters reached or exceeded their individually
   configurable thresholds.
*/
struct ACK_TR1CounterThreshHit
{
#if MEI_DRV_OS_BYTE_ORDER == MEI_DRV_OS_BIG_ENDIAN
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** TC CRC NE */
   IFX_uint16_t NE15 : 1;
   /** TC CV NE */
   IFX_uint16_t NE14 : 1;
   /** Reserved */
   IFX_uint16_t Res04 : 7;
   /** FEC NE */
   IFX_uint16_t NE6 : 1;
   /** CRC NE */
   IFX_uint16_t NE5 : 1;
   /** UAS NE */
   IFX_uint16_t NE4 : 1;
   /** LOSS NE */
   IFX_uint16_t NE3 : 1;
   /** SES NE */
   IFX_uint16_t NE2 : 1;
   /** ES NE */
   IFX_uint16_t NE1 : 1;
   /** FECS NE */
   IFX_uint16_t NE0 : 1;
   /** Reserved */
   IFX_uint16_t Res12 : 9;
   /** FEC (ECI) FE */
   IFX_uint16_t FE6 : 1;
   /** FEC (CVI) FE */
   IFX_uint16_t FE5 : 1;
   /** UAS FE */
   IFX_uint16_t FE4 : 1;
   /** LOSS FE */
   IFX_uint16_t FE3 : 1;
   /** SES FE */
   IFX_uint16_t FE2 : 1;
   /** ES FE */
   IFX_uint16_t FE1 : 1;
   /** FECS FE */
   IFX_uint16_t FE0 : 1;
   /** Reserved */
   IFX_uint16_t Res20 : 8;
   /** Near-End HEC-P Latency Path 1 */
   IFX_uint16_t hecp_l1 : 1;
   /** Near-End CD-P Latency Path 1 */
   IFX_uint16_t cdp_l1 : 1;
   /** Near-End CU-P Latency Path 1 */
   IFX_uint16_t cup_l1 : 1;
   /** Near-End IBE-P Latency Path 1 */
   IFX_uint16_t ibep_l1 : 1;
   /** Near-End HEC-P Latency Path 0 */
   IFX_uint16_t hecp_l0 : 1;
   /** Near-End CD-P Latency Path 0 */
   IFX_uint16_t cdp_l0 : 1;
   /** Near-End CU-P Latency Path 0 */
   IFX_uint16_t cup_l0 : 1;
   /** Near-End IBE-P Latency Path 0 */
   IFX_uint16_t ibep_l0 : 1;
   /** Reserved */
   IFX_uint16_t Res29 : 8;
   /** Far-End HEC-PFE Latency Path 1 */
   IFX_uint16_t hecpfe_l1 : 1;
   /** Far-End CD-PFE Latency Path 1 */
   IFX_uint16_t cdpfe_l1 : 1;
   /** Far-End CU-PFE Latency Path 1 */
   IFX_uint16_t cupfe_l1 : 1;
   /** Far-End IBE-PFE Latency Path 1 */
   IFX_uint16_t ibepfe_l1 : 1;
   /** Far-End HEC-PFE Latency Path 0 */
   IFX_uint16_t hecpfe_l0 : 1;
   /** Far-End CD-PFE Latency Path 0 */
   IFX_uint16_t cdpfe_l0 : 1;
   /** Far-End CU-PFE Latency Path 0 */
   IFX_uint16_t cupfe_l0 : 1;
   /** Far-End IBE-PFE Latency Path 0 */
   IFX_uint16_t ibepfe_l0 : 1;
   /** Time Stamp */
   IFX_uint16_t timestamp;
#else
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** FECS NE */
   IFX_uint16_t NE0 : 1;
   /** ES NE */
   IFX_uint16_t NE1 : 1;
   /** SES NE */
   IFX_uint16_t NE2 : 1;
   /** LOSS NE */
   IFX_uint16_t NE3 : 1;
   /** UAS NE */
   IFX_uint16_t NE4 : 1;
   /** CRC NE */
   IFX_uint16_t NE5 : 1;
   /** FEC NE */
   IFX_uint16_t NE6 : 1;
   /** Reserved */
   IFX_uint16_t Res04 : 7;
   /** TC CV NE */
   IFX_uint16_t NE14 : 1;
   /** TC CRC NE */
   IFX_uint16_t NE15 : 1;
   /** FECS FE */
   IFX_uint16_t FE0 : 1;
   /** ES FE */
   IFX_uint16_t FE1 : 1;
   /** SES FE */
   IFX_uint16_t FE2 : 1;
   /** LOSS FE */
   IFX_uint16_t FE3 : 1;
   /** UAS FE */
   IFX_uint16_t FE4 : 1;
   /** FEC (CVI) FE */
   IFX_uint16_t FE5 : 1;
   /** FEC (ECI) FE */
   IFX_uint16_t FE6 : 1;
   /** Reserved */
   IFX_uint16_t Res12 : 9;
   /** Near-End IBE-P Latency Path 0 */
   IFX_uint16_t ibep_l0 : 1;
   /** Near-End CU-P Latency Path 0 */
   IFX_uint16_t cup_l0 : 1;
   /** Near-End CD-P Latency Path 0 */
   IFX_uint16_t cdp_l0 : 1;
   /** Near-End HEC-P Latency Path 0 */
   IFX_uint16_t hecp_l0 : 1;
   /** Near-End IBE-P Latency Path 1 */
   IFX_uint16_t ibep_l1 : 1;
   /** Near-End CU-P Latency Path 1 */
   IFX_uint16_t cup_l1 : 1;
   /** Near-End CD-P Latency Path 1 */
   IFX_uint16_t cdp_l1 : 1;
   /** Near-End HEC-P Latency Path 1 */
   IFX_uint16_t hecp_l1 : 1;
   /** Reserved */
   IFX_uint16_t Res20 : 8;
   /** Far-End IBE-PFE Latency Path 0 */
   IFX_uint16_t ibepfe_l0 : 1;
   /** Far-End CU-PFE Latency Path 0 */
   IFX_uint16_t cupfe_l0 : 1;
   /** Far-End CD-PFE Latency Path 0 */
   IFX_uint16_t cdpfe_l0 : 1;
   /** Far-End HEC-PFE Latency Path 0 */
   IFX_uint16_t hecpfe_l0 : 1;
   /** Far-End IBE-PFE Latency Path 1 */
   IFX_uint16_t ibepfe_l1 : 1;
   /** Far-End CU-PFE Latency Path 1 */
   IFX_uint16_t cupfe_l1 : 1;
   /** Far-End CD-PFE Latency Path 1 */
   IFX_uint16_t cdpfe_l1 : 1;
   /** Far-End HEC-PFE Latency Path 1 */
   IFX_uint16_t hecpfe_l1 : 1;
   /** Reserved */
   IFX_uint16_t Res29 : 8;
   /** Time Stamp */
   IFX_uint16_t timestamp;
#endif
} __PACKED__ ;


/**
   This autonomous message indicates near-end line failures.
*/
struct ALM_LineFailureNE_Get
{
#if MEI_DRV_OS_BYTE_ORDER == MEI_DRV_OS_BIG_ENDIAN
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Reserved */
   IFX_uint16_t Res02 : 1;
   /** PRO Failure NE */
   IFX_uint16_t PRO_NE : 1;
   /** ESE Failure NE */
   IFX_uint16_t ESE_NE : 1;
   /** LOL Failure NE */
   IFX_uint16_t LOL_NE : 1;
   /** Reserved */
   IFX_uint16_t Res06 : 8;
   /** LOM Failure NE */
   IFX_uint16_t LOM_NE : 1;
   /** Reserved */
   IFX_uint16_t Res08 : 1;
   /** LOF Failure NE */
   IFX_uint16_t LOF_NE : 1;
   /** LOS Failure NE */
   IFX_uint16_t LOS_NE : 1;
#else
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** LOS Failure NE */
   IFX_uint16_t LOS_NE : 1;
   /** LOF Failure NE */
   IFX_uint16_t LOF_NE : 1;
   /** Reserved */
   IFX_uint16_t Res08 : 1;
   /** LOM Failure NE */
   IFX_uint16_t LOM_NE : 1;
   /** Reserved */
   IFX_uint16_t Res06 : 8;
   /** LOL Failure NE */
   IFX_uint16_t LOL_NE : 1;
   /** ESE Failure NE */
   IFX_uint16_t ESE_NE : 1;
   /** PRO Failure NE */
   IFX_uint16_t PRO_NE : 1;
   /** Reserved */
   IFX_uint16_t Res02 : 1;
#endif
} __PACKED__ ;


/**
   Requests the near-end line failure status.
*/
struct CMD_LineFailureNE_Get
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
   Provides the near-end line failure status requested by the command
   CMD_LineFailureNE_Get.
*/
struct ACK_LineFailureNE_Get
{
#if MEI_DRV_OS_BYTE_ORDER == MEI_DRV_OS_BIG_ENDIAN
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Reserved */
   IFX_uint16_t Res02 : 1;
   /** PRO Failure NE */
   IFX_uint16_t PRO_NE : 1;
   /** ESE Failure NE */
   IFX_uint16_t ESE_NE : 1;
   /** LOL Failure NE */
   IFX_uint16_t LOL_NE : 1;
   /** Reserved */
   IFX_uint16_t Res06 : 8;
   /** LOM Failure NE */
   IFX_uint16_t LOM_NE : 1;
   /** Reserved */
   IFX_uint16_t Res08 : 1;
   /** LOF Failure NE */
   IFX_uint16_t LOF_NE : 1;
   /** LOS Failure NE */
   IFX_uint16_t LOS_NE : 1;
#else
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** LOS Failure NE */
   IFX_uint16_t LOS_NE : 1;
   /** LOF Failure NE */
   IFX_uint16_t LOF_NE : 1;
   /** Reserved */
   IFX_uint16_t Res08 : 1;
   /** LOM Failure NE */
   IFX_uint16_t LOM_NE : 1;
   /** Reserved */
   IFX_uint16_t Res06 : 8;
   /** LOL Failure NE */
   IFX_uint16_t LOL_NE : 1;
   /** ESE Failure NE */
   IFX_uint16_t ESE_NE : 1;
   /** PRO Failure NE */
   IFX_uint16_t PRO_NE : 1;
   /** Reserved */
   IFX_uint16_t Res02 : 1;
#endif
} __PACKED__ ;


/**
   This autonomous message indicates far-end line failures.
*/
struct ALM_LineFailureFE_Get
{
#if MEI_DRV_OS_BYTE_ORDER == MEI_DRV_OS_BIG_ENDIAN
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Reserved */
   IFX_uint16_t Res02 : 2;
   /** ESE Failure FE */
   IFX_uint16_t ESE_FE : 1;
   /** Reserved */
   IFX_uint16_t Res04 : 9;
   /** LOM Failure FE */
   IFX_uint16_t LOM_FE : 1;
   /** LPR Failure FE */
   IFX_uint16_t LPR_FE : 1;
   /** LOF Failure FE */
   IFX_uint16_t LOF_FE : 1;
   /** LOS Failure FE */
   IFX_uint16_t LOS_FE : 1;
#else
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** LOS Failure FE */
   IFX_uint16_t LOS_FE : 1;
   /** LOF Failure FE */
   IFX_uint16_t LOF_FE : 1;
   /** LPR Failure FE */
   IFX_uint16_t LPR_FE : 1;
   /** LOM Failure FE */
   IFX_uint16_t LOM_FE : 1;
   /** Reserved */
   IFX_uint16_t Res04 : 9;
   /** ESE Failure FE */
   IFX_uint16_t ESE_FE : 1;
   /** Reserved */
   IFX_uint16_t Res02 : 2;
#endif
} __PACKED__ ;


/**
   Requests the far-end line failure status.
*/
struct CMD_LineFailureFE_Get
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
   Provides the far-end line failure status requested by the command
   CMD_LineFailureFE_Get.
*/
struct ACK_LineFailureFE_Get
{
#if MEI_DRV_OS_BYTE_ORDER == MEI_DRV_OS_BIG_ENDIAN
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Reserved */
   IFX_uint16_t Res02 : 2;
   /** ESE Failure FE */
   IFX_uint16_t ESE_FE : 1;
   /** Reserved */
   IFX_uint16_t Res04 : 9;
   /** LOM Failure FE */
   IFX_uint16_t LOM_FE : 1;
   /** LPR Failure FE */
   IFX_uint16_t LPR_FE : 1;
   /** LOF Failure FE */
   IFX_uint16_t LOF_FE : 1;
   /** LOS Failure FE */
   IFX_uint16_t LOS_FE : 1;
#else
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** LOS Failure FE */
   IFX_uint16_t LOS_FE : 1;
   /** LOF Failure FE */
   IFX_uint16_t LOF_FE : 1;
   /** LPR Failure FE */
   IFX_uint16_t LPR_FE : 1;
   /** LOM Failure FE */
   IFX_uint16_t LOM_FE : 1;
   /** Reserved */
   IFX_uint16_t Res04 : 9;
   /** ESE Failure FE */
   IFX_uint16_t ESE_FE : 1;
   /** Reserved */
   IFX_uint16_t Res02 : 2;
#endif
} __PACKED__ ;


/**
   Requests near-end line performance counter values (Section 7.2.1.1 of G.997.1) for
   the current and for the previous 15-min-TR1 period.
*/
struct CMD_LinePerfCountNE_Get
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
   Provides near-end line performance counter values requested by
   CMD_LinePerfCountNE_Get (Section 7.2.1.1 of G.997.1). Contains counter values for
   the current and for the previous 15-min-TR1 interval.
*/
struct ACK_LinePerfCountNE_Get
{
#if MEI_DRV_OS_BYTE_ORDER == MEI_DRV_OS_BIG_ENDIAN
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Near-End FECS Count, LSW, Current Period */
   IFX_uint16_t cntFECS_NE_LSW;
   /** Near-End FECS Count, MSW, Current Period */
   IFX_uint16_t cntFECS_NE_MSW;
   /** Near-End ES Count, LSW, Current Period */
   IFX_uint16_t cntES_NE_LSW;
   /** Near-End ES Count, MSW, Current Period */
   IFX_uint16_t cntES_NE_MSW;
   /** Near-End SES Count, LSW, Current Period */
   IFX_uint16_t cntSES_NE_LSW;
   /** Near-End SES Count, MSW, Current Period */
   IFX_uint16_t cntSES_NE_MSW;
   /** Near-End LOSS Count, LSW, Current Period */
   IFX_uint16_t cntLOSS_NE_LSW;
   /** Near-End LOSS Count, MSW, Current Period */
   IFX_uint16_t cntLOSS_NE_MSW;
   /** Near-End UAS Count, LSW, Current Period */
   IFX_uint16_t cntUAS_NE_LSW;
   /** Near-End UAS Count, MSW, Current Period */
   IFX_uint16_t cntUAS_NE_MSW;
   /** Near-End FECS Count, LSW, Previous Period */
   IFX_uint16_t cntFECS_NE_LSW_prev;
   /** Near-End FECS Count, MSW, Previous Period */
   IFX_uint16_t cntFECS_NE_MSW_prev;
   /** Near-End ES Count, LSW, Previous Period */
   IFX_uint16_t cntES_NE_LSW_prev;
   /** Near-End ES Count, MSW, Previous Period */
   IFX_uint16_t cntES_NE_MSW_prev;
   /** Near-End SES Count, LSW, Previous Period */
   IFX_uint16_t cntSES_NE_LSW_prev;
   /** Near-End SES Count, MSW, Previous Period */
   IFX_uint16_t cntSES_NE_MSW_prev;
   /** Near-End LOSS Count, LSW, Previous Period */
   IFX_uint16_t cntLOSS_NE_LSW_prev;
   /** Near-End LOSS Count, MSW, Previous Period */
   IFX_uint16_t cntLOSS_NE_MSW_prev;
   /** Near-End UAS Count, LSW, Previous Period */
   IFX_uint16_t cntUAS_NE_LSW_prev;
   /** Near-End UAS Count, MSW, Previous Period */
   IFX_uint16_t cntUAS_NE_MSW_prev;
#else
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Near-End FECS Count, LSW, Current Period */
   IFX_uint16_t cntFECS_NE_LSW;
   /** Near-End FECS Count, MSW, Current Period */
   IFX_uint16_t cntFECS_NE_MSW;
   /** Near-End ES Count, LSW, Current Period */
   IFX_uint16_t cntES_NE_LSW;
   /** Near-End ES Count, MSW, Current Period */
   IFX_uint16_t cntES_NE_MSW;
   /** Near-End SES Count, LSW, Current Period */
   IFX_uint16_t cntSES_NE_LSW;
   /** Near-End SES Count, MSW, Current Period */
   IFX_uint16_t cntSES_NE_MSW;
   /** Near-End LOSS Count, LSW, Current Period */
   IFX_uint16_t cntLOSS_NE_LSW;
   /** Near-End LOSS Count, MSW, Current Period */
   IFX_uint16_t cntLOSS_NE_MSW;
   /** Near-End UAS Count, LSW, Current Period */
   IFX_uint16_t cntUAS_NE_LSW;
   /** Near-End UAS Count, MSW, Current Period */
   IFX_uint16_t cntUAS_NE_MSW;
   /** Near-End FECS Count, LSW, Previous Period */
   IFX_uint16_t cntFECS_NE_LSW_prev;
   /** Near-End FECS Count, MSW, Previous Period */
   IFX_uint16_t cntFECS_NE_MSW_prev;
   /** Near-End ES Count, LSW, Previous Period */
   IFX_uint16_t cntES_NE_LSW_prev;
   /** Near-End ES Count, MSW, Previous Period */
   IFX_uint16_t cntES_NE_MSW_prev;
   /** Near-End SES Count, LSW, Previous Period */
   IFX_uint16_t cntSES_NE_LSW_prev;
   /** Near-End SES Count, MSW, Previous Period */
   IFX_uint16_t cntSES_NE_MSW_prev;
   /** Near-End LOSS Count, LSW, Previous Period */
   IFX_uint16_t cntLOSS_NE_LSW_prev;
   /** Near-End LOSS Count, MSW, Previous Period */
   IFX_uint16_t cntLOSS_NE_MSW_prev;
   /** Near-End UAS Count, LSW, Previous Period */
   IFX_uint16_t cntUAS_NE_LSW_prev;
   /** Near-End UAS Count, MSW, Previous Period */
   IFX_uint16_t cntUAS_NE_MSW_prev;
#endif
} __PACKED__ ;


/**
   Requests far-end line performance counter values (Section 7.2.1.2 of G.997.1) for
   the current and for the previous 15-min-TR1 period.
*/
struct CMD_LinePerfCountFE_Get
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
   Provides far-end line performance counter values requested by
   CMD_LinePerfCountFE_Get (Section 7.2.1.2 of G.997.1). Contains counter values for
   the current and for the previous 15-min-TR1 interval.
*/
struct ACK_LinePerfCountFE_Get
{
#if MEI_DRV_OS_BYTE_ORDER == MEI_DRV_OS_BIG_ENDIAN
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Far-End FECS Count, LSW, Current Period */
   IFX_uint16_t cntFECS_FE_LSW;
   /** Far-End FECS Count, MSW, Current Period */
   IFX_uint16_t cntFECS_FE_MSW;
   /** Far-End ES Count, LSW, Current Period */
   IFX_uint16_t cntES_FE_LSW;
   /** Far-End ES Count, MSW, Current Period */
   IFX_uint16_t cntES_FE_MSW;
   /** Far-End SES Count, LSW, Current Period */
   IFX_uint16_t cntSES_FE_LSW;
   /** Far-End SES Count, MSW, Current Period */
   IFX_uint16_t cntSES_FE_MSW;
   /** Far-End LOSS Count, LSW, Current Period */
   IFX_uint16_t cntLOSS_FE_LSW;
   /** Far-End LOSS Count, MSW, Current Period */
   IFX_uint16_t cntLOSS_FE_MSW;
   /** Far-End UAS Count, LSW, Current Period */
   IFX_uint16_t cntUAS_FE_LSW;
   /** Far-End UAS Count, MSW, Current Period */
   IFX_uint16_t cntUAS_FE_MSW;
   /** Far-End FECS Count, LSW, Previous Period */
   IFX_uint16_t cntFECS_FE_LSW_prev;
   /** Far-End FECS Count, MSW, Previous Period */
   IFX_uint16_t cntFECS_FE_MSW_prev;
   /** Far-End ES Count, LSW, Previous Period */
   IFX_uint16_t cntES_FE_LSW_prev;
   /** Far-End ES Count, MSW, Previous Period */
   IFX_uint16_t cntES_FE_MSW_prev;
   /** Far-End SES Count, LSW, Previous Period */
   IFX_uint16_t cntSES_FE_LSW_prev;
   /** Far-End SES Count, MSW, Previous Period */
   IFX_uint16_t cntSES_FE_MSW_prev;
   /** Far-End LOSS Count, LSW, Previous Period */
   IFX_uint16_t cntLOSS_FE_LSW_prev;
   /** Far-End LOSS Count, MSW, Previous Period */
   IFX_uint16_t cntLOSS_FE_MSW_prev;
   /** Far-End UAS Count, LSW, Previous Period */
   IFX_uint16_t cntUAS_FE_LSW_prev;
   /** Far-End UAS Count, MSW, Previous Period */
   IFX_uint16_t cntUAS_FE_MSW_prev;
#else
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Far-End FECS Count, LSW, Current Period */
   IFX_uint16_t cntFECS_FE_LSW;
   /** Far-End FECS Count, MSW, Current Period */
   IFX_uint16_t cntFECS_FE_MSW;
   /** Far-End ES Count, LSW, Current Period */
   IFX_uint16_t cntES_FE_LSW;
   /** Far-End ES Count, MSW, Current Period */
   IFX_uint16_t cntES_FE_MSW;
   /** Far-End SES Count, LSW, Current Period */
   IFX_uint16_t cntSES_FE_LSW;
   /** Far-End SES Count, MSW, Current Period */
   IFX_uint16_t cntSES_FE_MSW;
   /** Far-End LOSS Count, LSW, Current Period */
   IFX_uint16_t cntLOSS_FE_LSW;
   /** Far-End LOSS Count, MSW, Current Period */
   IFX_uint16_t cntLOSS_FE_MSW;
   /** Far-End UAS Count, LSW, Current Period */
   IFX_uint16_t cntUAS_FE_LSW;
   /** Far-End UAS Count, MSW, Current Period */
   IFX_uint16_t cntUAS_FE_MSW;
   /** Far-End FECS Count, LSW, Previous Period */
   IFX_uint16_t cntFECS_FE_LSW_prev;
   /** Far-End FECS Count, MSW, Previous Period */
   IFX_uint16_t cntFECS_FE_MSW_prev;
   /** Far-End ES Count, LSW, Previous Period */
   IFX_uint16_t cntES_FE_LSW_prev;
   /** Far-End ES Count, MSW, Previous Period */
   IFX_uint16_t cntES_FE_MSW_prev;
   /** Far-End SES Count, LSW, Previous Period */
   IFX_uint16_t cntSES_FE_LSW_prev;
   /** Far-End SES Count, MSW, Previous Period */
   IFX_uint16_t cntSES_FE_MSW_prev;
   /** Far-End LOSS Count, LSW, Previous Period */
   IFX_uint16_t cntLOSS_FE_LSW_prev;
   /** Far-End LOSS Count, MSW, Previous Period */
   IFX_uint16_t cntLOSS_FE_MSW_prev;
   /** Far-End UAS Count, LSW, Previous Period */
   IFX_uint16_t cntUAS_FE_LSW_prev;
   /** Far-End UAS Count, MSW, Previous Period */
   IFX_uint16_t cntUAS_FE_MSW_prev;
#endif
} __PACKED__ ;


/**
   Requests line initialization performance counter values (Section 7.2.1.3 of G.997.1)
   for the current and previous 15-min-TR1 period.
*/
struct CMD_LineInitCountGet
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
   Provides line initialization performance counter values requested by
   CMD_LineInitCountGet (Section 7.2.1.3 of G.997.1). Contains counter values for the
   current and for the previous 15-min-TR1 interval. The counters are not reset at link
   re-initialization.
   Full Inits Count: Counter of the number of initialization attempts. The counter
   increments each time the modem tries to initialize the line when entering the
   "FULL_INIT" state or - if Loop Diagnostic Mode is run- when entering
   "DIAGMODE".Failed Inits Count: The counter increments when the criteria for an
   "initialization attempt" is met (see above) but STEADY_STATE or DIAG_COMPLETE are
   not reached AND if this was not due to an administrational change (like setting the
   modem FSM explicitely to RESET).
*/
struct ACK_LineInitCountGet
{
#if MEI_DRV_OS_BYTE_ORDER == MEI_DRV_OS_BIG_ENDIAN
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Full Init Count LSW, Current Period */
   IFX_uint16_t cntInit_LSW;
   /** Full Init Count MSW, Current Period */
   IFX_uint16_t cntInit_MSW;
   /** Failed Full Init Count LSW, Current Period */
   IFX_uint16_t cntInitFail_LSW;
   /** Failed Full Init Count MSW, Current Period */
   IFX_uint16_t cntInitFail_MSW;
   /** Reserved */
   IFX_uint16_t Res1[4];
   /** Full Init Count LSW, Previous Period */
   IFX_uint16_t cntInit_LSW_prev;
   /** Full Init Count MSW, Previous Period */
   IFX_uint16_t cntInit_MSW_prev;
   /** Failed Full Init Count LSW, Previous Period */
   IFX_uint16_t cntInitFail_LSW_prev;
   /** Failed Full Init Count MSW, Previous Period */
   IFX_uint16_t cntInitFail_MSW_prev;
   /** Reserved */
   IFX_uint16_t Res2[4];
#else
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Full Init Count LSW, Current Period */
   IFX_uint16_t cntInit_LSW;
   /** Full Init Count MSW, Current Period */
   IFX_uint16_t cntInit_MSW;
   /** Failed Full Init Count LSW, Current Period */
   IFX_uint16_t cntInitFail_LSW;
   /** Failed Full Init Count MSW, Current Period */
   IFX_uint16_t cntInitFail_MSW;
   /** Reserved */
   IFX_uint16_t Res1[4];
   /** Full Init Count LSW, Previous Period */
   IFX_uint16_t cntInit_LSW_prev;
   /** Full Init Count MSW, Previous Period */
   IFX_uint16_t cntInit_MSW_prev;
   /** Failed Full Init Count LSW, Previous Period */
   IFX_uint16_t cntInitFail_LSW_prev;
   /** Failed Full Init Count MSW, Previous Period */
   IFX_uint16_t cntInitFail_MSW_prev;
   /** Reserved */
   IFX_uint16_t Res2[4];
#endif
} __PACKED__ ;


/**
   Requests near-end CRC counter values.
*/
struct CMD_CRC_StatsNE_Get
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
   Returns near-end CRC counter values. (Section 7.2.2.1.1 of G997.1)
   Note: In VINAX V1.x the "LP1/Fast Path" parameters are fed only in ADSL1 mode
   with selected fast path.
*/
struct ACK_CRC_StatsNE_Get
{
#if MEI_DRV_OS_BYTE_ORDER == MEI_DRV_OS_BIG_ENDIAN
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Near-End CRC Count LP0, LSW, Current Period */
   IFX_uint16_t cntCVI_LSW;
   /** Near-End CRC Count LP0, MSW, Current Period */
   IFX_uint16_t cntCVI_MSW;
   /** Near-End CRC Count LP1, LSW, Current Period */
   IFX_uint16_t cntCVF_LSW;
   /** Near-End CRC Count LP1, MSW, Current Period */
   IFX_uint16_t cntCVF_MSW;
   /** Near-End CRC Count LP0, LSW, Previous Period */
   IFX_uint16_t cntCVI_LSW_prev;
   /** Near-End CRC Count LP0, MSW, Previous Period */
   IFX_uint16_t cntCVI_MSW_prev;
   /** Near-End CRC Count LP1, LSW, Previous Period */
   IFX_uint16_t cntCVF_LSW_prev;
   /** Near-End CRC Count LP1, MSW, Previous Period */
   IFX_uint16_t cntCVF_MSW_prev;
#else
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Near-End CRC Count LP0, LSW, Current Period */
   IFX_uint16_t cntCVI_LSW;
   /** Near-End CRC Count LP0, MSW, Current Period */
   IFX_uint16_t cntCVI_MSW;
   /** Near-End CRC Count LP1, LSW, Current Period */
   IFX_uint16_t cntCVF_LSW;
   /** Near-End CRC Count LP1, MSW, Current Period */
   IFX_uint16_t cntCVF_MSW;
   /** Near-End CRC Count LP0, LSW, Previous Period */
   IFX_uint16_t cntCVI_LSW_prev;
   /** Near-End CRC Count LP0, MSW, Previous Period */
   IFX_uint16_t cntCVI_MSW_prev;
   /** Near-End CRC Count LP1, LSW, Previous Period */
   IFX_uint16_t cntCVF_LSW_prev;
   /** Near-End CRC Count LP1, MSW, Previous Period */
   IFX_uint16_t cntCVF_MSW_prev;
#endif
} __PACKED__ ;


/**
   Requests far-end CRC counter values.
*/
struct CMD_CRC_StatsFE_Get
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
   Returns far-end CRC counter values. (Section 7.2.2.2.1 of G997.1)
   Note: In VINAX V1.x the "LP1/Fast Path" parameters are fed only in ADSL1 mode
   with selected fast path.
*/
struct ACK_CRC_StatsFE_Get
{
#if MEI_DRV_OS_BYTE_ORDER == MEI_DRV_OS_BIG_ENDIAN
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Far-End CRC Count LP0, LSW, Current Period */
   IFX_uint16_t cntCVI_LSW;
   /** Far-End CRC Count LP0, MSW, Current Period */
   IFX_uint16_t cntCVI_MSW;
   /** Far-End CRC Count LP1, LSW, Current Period */
   IFX_uint16_t cntCVF_LSW;
   /** Far-End CRC Count LP1, MSW, Current Period */
   IFX_uint16_t cntCVF_MSW;
   /** Far-End CRC Count LP0, LSW, Previous Period */
   IFX_uint16_t cntCVI_LSW_prev;
   /** Far-End CRC Count LP0, MSW, Previous Period */
   IFX_uint16_t cntCVI_MSW_prev;
   /** Far-End CRC Count LP1, LSW, Previous Period */
   IFX_uint16_t cntCVF_LSW_prev;
   /** Far-End CRC Count LP1, MSW, Previous Period */
   IFX_uint16_t cntCVF_MSW_prev;
#else
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Far-End CRC Count LP0, LSW, Current Period */
   IFX_uint16_t cntCVI_LSW;
   /** Far-End CRC Count LP0, MSW, Current Period */
   IFX_uint16_t cntCVI_MSW;
   /** Far-End CRC Count LP1, LSW, Current Period */
   IFX_uint16_t cntCVF_LSW;
   /** Far-End CRC Count LP1, MSW, Current Period */
   IFX_uint16_t cntCVF_MSW;
   /** Far-End CRC Count LP0, LSW, Previous Period */
   IFX_uint16_t cntCVI_LSW_prev;
   /** Far-End CRC Count LP0, MSW, Previous Period */
   IFX_uint16_t cntCVI_MSW_prev;
   /** Far-End CRC Count LP1, LSW, Previous Period */
   IFX_uint16_t cntCVF_LSW_prev;
   /** Far-End CRC Count LP1, MSW, Previous Period */
   IFX_uint16_t cntCVF_MSW_prev;
#endif
} __PACKED__ ;


/**
   Requests near-end FEC counter values.
*/
struct CMD_FEC_StatsNE_Get
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
   Returns near-end FEC counter values. (Section 7.2.2.1.2 of G997.1)
   Note: In VINAX V1.x the "LP1/Fast Path" parameters are fed only in ADSL1 mode
   with selected fast path.
*/
struct ACK_FEC_StatsNE_Get
{
#if MEI_DRV_OS_BYTE_ORDER == MEI_DRV_OS_BIG_ENDIAN
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Near-End FEC Count LP0, LSW, Current Period */
   IFX_uint16_t cntECI_LSW;
   /** Near-End FEC Count LP0, MSW, Current Period */
   IFX_uint16_t cntECI_MSW;
   /** Near-End FEC Count LP1, LSW, Current Period */
   IFX_uint16_t cntFEC_LSW;
   /** Near-End FEC Count LP1, MSW, Current Period */
   IFX_uint16_t cntFEC_MSW;
   /** Near-End FEC Uncorrectable Count LP0, LSW, Current Period */
   IFX_uint16_t cntECI_NoCorrLSW;
   /** Near-End FEC Uncorrectable Count LP0, MSW, Current Period */
   IFX_uint16_t cntECI_NoCorrMSW;
   /** Near-End FEC Uncorrectable Count LP1, LSW, Current Period */
   IFX_uint16_t cntECF_NoCorrLSW;
   /** Near-End FEC Uncorrectable Count LP1, MSW, Current Period */
   IFX_uint16_t cntECF_NoCorrMSW;
   /** Near-End Total RS CW Count LP0, LSW, Current Period */
   IFX_uint16_t cntECI_CW_LSW;
   /** Near-End Total RS CW Count LP0, MSW, Current Period */
   IFX_uint16_t cntECI_CW_MSW;
   /** Near-End Total RS CW Count LP1, LSW, Current Period */
   IFX_uint16_t cntECF_CW_LSW;
   /** Near-End Total RS CW Count LP1, MSW, Current Period */
   IFX_uint16_t cntECF_CW_MSW;
   /** Near-End FEC Count LP0, LSW, Previous Period */
   IFX_uint16_t cntECI_LSW_prev;
   /** Near-End FEC Count LP0, MSW, Previous Period */
   IFX_uint16_t cntECI_MSW_prev;
   /** Near-End FEC Count LP1, LSW, Previous Period */
   IFX_uint16_t cntECF_LSW_prev;
   /** Near-End FEC Count LP1, MSW, Previous Period */
   IFX_uint16_t cntECF_MSW_prev;
   /** Near-End FEC Uncorrectable Count LP0, LSW, Previous Period */
   IFX_uint16_t cntECI_NoCorrLSW_prev;
   /** Near-End FEC Uncorrectable Count LP0, MSW, Previous Period */
   IFX_uint16_t cntECI_NoCorrMSW_prev;
   /** Near-End FEC Uncorrectable Count LP1, LSW, Previous Period */
   IFX_uint16_t cntECF_NoCorrLSW_prev;
   /** Near-End FEC Uncorrectable Count LP1, MSW, Previous Period */
   IFX_uint16_t cntECF_NoCorrMSW_prev;
   /** Near-End Total RS CW Count LP0, LSW, Previous Period */
   IFX_uint16_t cntECI_CW_LSW_prev;
   /** Near-End Total RS CW Count LP0, MSW, Previous Period */
   IFX_uint16_t cntECI_CW_MSW_prev;
   /** Near-End Total RS CW Count LP1, LSW, Previous Period */
   IFX_uint16_t cntECF_CW_LSW_prev;
   /** Near-End Total RS CW Count LP1, MSW, Previous Period */
   IFX_uint16_t cntECF_CW_MSW_prev;
#else
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Near-End FEC Count LP0, LSW, Current Period */
   IFX_uint16_t cntECI_LSW;
   /** Near-End FEC Count LP0, MSW, Current Period */
   IFX_uint16_t cntECI_MSW;
   /** Near-End FEC Count LP1, LSW, Current Period */
   IFX_uint16_t cntFEC_LSW;
   /** Near-End FEC Count LP1, MSW, Current Period */
   IFX_uint16_t cntFEC_MSW;
   /** Near-End FEC Uncorrectable Count LP0, LSW, Current Period */
   IFX_uint16_t cntECI_NoCorrLSW;
   /** Near-End FEC Uncorrectable Count LP0, MSW, Current Period */
   IFX_uint16_t cntECI_NoCorrMSW;
   /** Near-End FEC Uncorrectable Count LP1, LSW, Current Period */
   IFX_uint16_t cntECF_NoCorrLSW;
   /** Near-End FEC Uncorrectable Count LP1, MSW, Current Period */
   IFX_uint16_t cntECF_NoCorrMSW;
   /** Near-End Total RS CW Count LP0, LSW, Current Period */
   IFX_uint16_t cntECI_CW_LSW;
   /** Near-End Total RS CW Count LP0, MSW, Current Period */
   IFX_uint16_t cntECI_CW_MSW;
   /** Near-End Total RS CW Count LP1, LSW, Current Period */
   IFX_uint16_t cntECF_CW_LSW;
   /** Near-End Total RS CW Count LP1, MSW, Current Period */
   IFX_uint16_t cntECF_CW_MSW;
   /** Near-End FEC Count LP0, LSW, Previous Period */
   IFX_uint16_t cntECI_LSW_prev;
   /** Near-End FEC Count LP0, MSW, Previous Period */
   IFX_uint16_t cntECI_MSW_prev;
   /** Near-End FEC Count LP1, LSW, Previous Period */
   IFX_uint16_t cntECF_LSW_prev;
   /** Near-End FEC Count LP1, MSW, Previous Period */
   IFX_uint16_t cntECF_MSW_prev;
   /** Near-End FEC Uncorrectable Count LP0, LSW, Previous Period */
   IFX_uint16_t cntECI_NoCorrLSW_prev;
   /** Near-End FEC Uncorrectable Count LP0, MSW, Previous Period */
   IFX_uint16_t cntECI_NoCorrMSW_prev;
   /** Near-End FEC Uncorrectable Count LP1, LSW, Previous Period */
   IFX_uint16_t cntECF_NoCorrLSW_prev;
   /** Near-End FEC Uncorrectable Count LP1, MSW, Previous Period */
   IFX_uint16_t cntECF_NoCorrMSW_prev;
   /** Near-End Total RS CW Count LP0, LSW, Previous Period */
   IFX_uint16_t cntECI_CW_LSW_prev;
   /** Near-End Total RS CW Count LP0, MSW, Previous Period */
   IFX_uint16_t cntECI_CW_MSW_prev;
   /** Near-End Total RS CW Count LP1, LSW, Previous Period */
   IFX_uint16_t cntECF_CW_LSW_prev;
   /** Near-End Total RS CW Count LP1, MSW, Previous Period */
   IFX_uint16_t cntECF_CW_MSW_prev;
#endif
} __PACKED__ ;


/**
   Requests far-end FEC counter values.
*/
struct CMD_FEC_StatsFE_Get
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
   Returns the far-end FEC counter values requested by CMD_FEC_StatsFE_Get.(Section
   7.2.2.2.2 of G997.1)
   Note: In VINAX V1.x the "LP1/Fast Path" parameters are fed only in ADSL1 mode
   with selected fast path.
*/
struct ACK_FEC_StatsFE_Get
{
#if MEI_DRV_OS_BYTE_ORDER == MEI_DRV_OS_BIG_ENDIAN
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Far-End FEC Count LP0, LSW, Current Period */
   IFX_uint16_t cntECI_LSW;
   /** Far-End FEC Count LP0, MSW, Current Period */
   IFX_uint16_t cntECI_MSW;
   /** Far-End FEC Count LP1, LSW, Current Period */
   IFX_uint16_t cntFEC_LSW;
   /** Far-End FEC Count LP1, MSW, Current Period */
   IFX_uint16_t cntFEC_MSW;
   /** Reserved */
   IFX_uint16_t Res06[4];
   /** Far-End Total RS CW Count LP0, LSW, Current Period */
   IFX_uint16_t cntECI_CW_LSW;
   /** Far-End Total RS CW Count LP0, MSW, Current Period */
   IFX_uint16_t cntECI_CW_MSW;
   /** Far-End Total RS CW Count LP1, LSW, Current Period */
   IFX_uint16_t cntECF_CW_LSW;
   /** Far-End Total RS CW Count LP1, MSW, Current Period */
   IFX_uint16_t cntECF_CW_MSW;
   /** Far-End FEC Count LP0, LSW, Previous Period */
   IFX_uint16_t cntECI_LSW_prev;
   /** Far-End FEC Count LP0, MSW, Previous Period */
   IFX_uint16_t cntECI_MSW_prev;
   /** Far-End FEC Count LP1, LSW, Previous Period */
   IFX_uint16_t cntECF_LSW_prev;
   /** Far-End FEC Count LP1, MSW, Previous Period */
   IFX_uint16_t cntECF_MSW_prev;
   /** Reserved */
   IFX_uint16_t Res15[4];
   /** Far-End Total RS CW Count LP0, LSW, Previous Period */
   IFX_uint16_t cntECI_CW_LSW_prev;
   /** Far-End Total RS CW Count LP0, MSW, Previous Period */
   IFX_uint16_t cntECI_CW_MSW_prev;
   /** Far-End Total RS CW Count LP1, LSW, Previous Period */
   IFX_uint16_t cntECF_CW_LSW_prev;
   /** Far-End Total RS CW Count LP1, MSW, Previous Period */
   IFX_uint16_t cntECF_CW_MSW_prev;
#else
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Far-End FEC Count LP0, LSW, Current Period */
   IFX_uint16_t cntECI_LSW;
   /** Far-End FEC Count LP0, MSW, Current Period */
   IFX_uint16_t cntECI_MSW;
   /** Far-End FEC Count LP1, LSW, Current Period */
   IFX_uint16_t cntFEC_LSW;
   /** Far-End FEC Count LP1, MSW, Current Period */
   IFX_uint16_t cntFEC_MSW;
   /** Reserved */
   IFX_uint16_t Res06[4];
   /** Far-End Total RS CW Count LP0, LSW, Current Period */
   IFX_uint16_t cntECI_CW_LSW;
   /** Far-End Total RS CW Count LP0, MSW, Current Period */
   IFX_uint16_t cntECI_CW_MSW;
   /** Far-End Total RS CW Count LP1, LSW, Current Period */
   IFX_uint16_t cntECF_CW_LSW;
   /** Far-End Total RS CW Count LP1, MSW, Current Period */
   IFX_uint16_t cntECF_CW_MSW;
   /** Far-End FEC Count LP0, LSW, Previous Period */
   IFX_uint16_t cntECI_LSW_prev;
   /** Far-End FEC Count LP0, MSW, Previous Period */
   IFX_uint16_t cntECI_MSW_prev;
   /** Far-End FEC Count LP1, LSW, Previous Period */
   IFX_uint16_t cntECF_LSW_prev;
   /** Far-End FEC Count LP1, MSW, Previous Period */
   IFX_uint16_t cntECF_MSW_prev;
   /** Reserved */
   IFX_uint16_t Res15[4];
   /** Far-End Total RS CW Count LP0, LSW, Previous Period */
   IFX_uint16_t cntECI_CW_LSW_prev;
   /** Far-End Total RS CW Count LP0, MSW, Previous Period */
   IFX_uint16_t cntECI_CW_MSW_prev;
   /** Far-End Total RS CW Count LP1, LSW, Previous Period */
   IFX_uint16_t cntECF_CW_LSW_prev;
   /** Far-End Total RS CW Count LP1, MSW, Previous Period */
   IFX_uint16_t cntECF_CW_MSW_prev;
#endif
} __PACKED__ ;


/**
   Requests the near-end 15 minutes SOS TR1 counter values.
*/
struct CMD_SOS_StatsNE_Get
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
   Returns near-end SOS counter values. (Section 7.2.1.6.1 of G997.1)
*/
struct ACK_SOS_StatsNE_Get
{
#if MEI_DRV_OS_BYTE_ORDER == MEI_DRV_OS_BIG_ENDIAN
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Near-End SOS Success Count LP0, LSW, Current Period */
   IFX_uint16_t cntSOS_SUC_LSW;
   /** Near-End SOS Success Count LP0, MSW, Current Period */
   IFX_uint16_t cntSOS_SUC_MSW;
   /** Near-End SOS Success Count LP0, LSW, Previous Period */
   IFX_uint16_t cntSOS_SUC_LSW_prev;
   /** Near-End SOS Success Count LP0, MSW, Previous Period */
   IFX_uint16_t cntSOS_SUC_MSW_prev;
#else
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Near-End SOS Success Count LP0, LSW, Current Period */
   IFX_uint16_t cntSOS_SUC_LSW;
   /** Near-End SOS Success Count LP0, MSW, Current Period */
   IFX_uint16_t cntSOS_SUC_MSW;
   /** Near-End SOS Success Count LP0, LSW, Previous Period */
   IFX_uint16_t cntSOS_SUC_LSW_prev;
   /** Near-End SOS Success Count LP0, MSW, Previous Period */
   IFX_uint16_t cntSOS_SUC_MSW_prev;
#endif
} __PACKED__ ;


/**
   Requests the far-end 15 minutes SOS TR1 counter values.
*/
struct CMD_SOS_StatsFE_Get
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
   Returns far-end SOS TR1 counter values. (Section 7.2.1.7.1 of G997.1)
*/
struct ACK_SOS_StatsFE_Get
{
#if MEI_DRV_OS_BYTE_ORDER == MEI_DRV_OS_BIG_ENDIAN
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Far-End SOS Success Count LP0, LSW, Current Period */
   IFX_uint16_t cntSOS_SUC_LSW;
   /** Far-End SOS Success Count LP0, MSW, Current Period */
   IFX_uint16_t cntSOS_SUC_MSW;
   /** Far-End SOS Success Count LP0, LSW, Previous Period */
   IFX_uint16_t cntSOS_SUC_LSW_prev;
   /** Far-End SOS Success Count LP0, MSW, Previous Period */
   IFX_uint16_t cntSOS_SUC_MSW_prev;
#else
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Far-End SOS Success Count LP0, LSW, Current Period */
   IFX_uint16_t cntSOS_SUC_LSW;
   /** Far-End SOS Success Count LP0, MSW, Current Period */
   IFX_uint16_t cntSOS_SUC_MSW;
   /** Far-End SOS Success Count LP0, LSW, Previous Period */
   IFX_uint16_t cntSOS_SUC_LSW_prev;
   /** Far-End SOS Success Count LP0, MSW, Previous Period */
   IFX_uint16_t cntSOS_SUC_MSW_prev;
#endif
} __PACKED__ ;


/**
   Writes near-end line performance counter values (Section 7.2.1.1 of G.997.1) for the
   current and for the previous 15-min-TR1 period.
*/
struct CMD_LinePerfCountNE_Set
{
#if MEI_DRV_OS_BYTE_ORDER == MEI_DRV_OS_BIG_ENDIAN
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Near-End FECS Count, LSW, Current Period */
   IFX_uint16_t cntFECS_NE_LSW;
   /** Near-End FECS Count, MSW, Current Period */
   IFX_uint16_t cntFECS_NE_MSW;
   /** Near-End ES Count, LSW, Current Period */
   IFX_uint16_t cntES_NE_LSW;
   /** Near-End ES Count, MSW, Current Period */
   IFX_uint16_t cntES_NE_MSW;
   /** Near-End SES Count, LSW, Current Period */
   IFX_uint16_t cntSES_NE_LSW;
   /** Near-End SES Count, MSW, Current Period */
   IFX_uint16_t cntSES_NE_MSW;
   /** Near-End LOSS Count, LSW, Current Period */
   IFX_uint16_t cntLOSS_NE_LSW;
   /** Near-End LOSS Count, MSW, Current Period */
   IFX_uint16_t cntLOSS_NE_MSW;
   /** Near-End UAS Count, LSW, Current Period */
   IFX_uint16_t cntUAS_NE_LSW;
   /** Near-End UAS Count, MSW, Current Period */
   IFX_uint16_t cntUAS_NE_MSW;
   /** Near-End FECS Count, LSW, Previous Period */
   IFX_uint16_t cntFECS_NE_LSW_prev;
   /** Near-End FECS Count, MSW, Previous Period */
   IFX_uint16_t cntFECS_NE_MSW_prev;
   /** Near-End ES Count, LSW, Previous Period */
   IFX_uint16_t cntES_NE_LSW_prev;
   /** Near-End ES Count, MSW, Previous Period */
   IFX_uint16_t cntES_NE_MSW_prev;
   /** Near-End SES Count, LSW, Previous Period */
   IFX_uint16_t cntSES_NE_LSW_prev;
   /** Near-End SES Count, MSW, Previous Period */
   IFX_uint16_t cntSES_NE_MSW_prev;
   /** Near-End LOSS Count, LSW, Previous Period */
   IFX_uint16_t cntLOSS_NE_LSW_prev;
   /** Near-End LOSS Count, MSW, Previous Period */
   IFX_uint16_t cntLOSS_NE_MSW_prev;
   /** Near-End UAS Count, LSW, Previous Period */
   IFX_uint16_t cntUAS_NE_LSW_prev;
   /** Near-End UAS Count, MSW, Previous Period */
   IFX_uint16_t cntUAS_NE_MSW_prev;
#else
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Near-End FECS Count, LSW, Current Period */
   IFX_uint16_t cntFECS_NE_LSW;
   /** Near-End FECS Count, MSW, Current Period */
   IFX_uint16_t cntFECS_NE_MSW;
   /** Near-End ES Count, LSW, Current Period */
   IFX_uint16_t cntES_NE_LSW;
   /** Near-End ES Count, MSW, Current Period */
   IFX_uint16_t cntES_NE_MSW;
   /** Near-End SES Count, LSW, Current Period */
   IFX_uint16_t cntSES_NE_LSW;
   /** Near-End SES Count, MSW, Current Period */
   IFX_uint16_t cntSES_NE_MSW;
   /** Near-End LOSS Count, LSW, Current Period */
   IFX_uint16_t cntLOSS_NE_LSW;
   /** Near-End LOSS Count, MSW, Current Period */
   IFX_uint16_t cntLOSS_NE_MSW;
   /** Near-End UAS Count, LSW, Current Period */
   IFX_uint16_t cntUAS_NE_LSW;
   /** Near-End UAS Count, MSW, Current Period */
   IFX_uint16_t cntUAS_NE_MSW;
   /** Near-End FECS Count, LSW, Previous Period */
   IFX_uint16_t cntFECS_NE_LSW_prev;
   /** Near-End FECS Count, MSW, Previous Period */
   IFX_uint16_t cntFECS_NE_MSW_prev;
   /** Near-End ES Count, LSW, Previous Period */
   IFX_uint16_t cntES_NE_LSW_prev;
   /** Near-End ES Count, MSW, Previous Period */
   IFX_uint16_t cntES_NE_MSW_prev;
   /** Near-End SES Count, LSW, Previous Period */
   IFX_uint16_t cntSES_NE_LSW_prev;
   /** Near-End SES Count, MSW, Previous Period */
   IFX_uint16_t cntSES_NE_MSW_prev;
   /** Near-End LOSS Count, LSW, Previous Period */
   IFX_uint16_t cntLOSS_NE_LSW_prev;
   /** Near-End LOSS Count, MSW, Previous Period */
   IFX_uint16_t cntLOSS_NE_MSW_prev;
   /** Near-End UAS Count, LSW, Previous Period */
   IFX_uint16_t cntUAS_NE_LSW_prev;
   /** Near-End UAS Count, MSW, Previous Period */
   IFX_uint16_t cntUAS_NE_MSW_prev;
#endif
} __PACKED__ ;


/**
   Provides near-end line performance counter values requested by
   CMD_LinePerfCountNE_Set (Section 7.2.1.1 of G.997.1). Contains counter values for
   the current and for the previous 15-min-TR1 interval.
*/
struct ACK_LinePerfCountNE_Set
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
   Writes far-end line performance counter values (Section 7.2.1.2 of G.997.1) for the
   current and for the previous 15-min-TR1 period.
*/
struct CMD_LinePerfCountFE_Set
{
#if MEI_DRV_OS_BYTE_ORDER == MEI_DRV_OS_BIG_ENDIAN
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Far-End FECS Count, LSW, Current Period */
   IFX_uint16_t cntFECS_FE_LSW;
   /** Far-End FECS Count, MSW, Current Period */
   IFX_uint16_t cntFECS_FE_MSW;
   /** Far-End ES Count, LSW, Current Period */
   IFX_uint16_t cntES_FE_LSW;
   /** Far-End ES Count, MSW, Current Period */
   IFX_uint16_t cntES_FE_MSW;
   /** Far-End SES Count, LSW, Current Period */
   IFX_uint16_t cntSES_FE_LSW;
   /** Far-End SES Count, MSW, Current Period */
   IFX_uint16_t cntSES_FE_MSW;
   /** Far-End LOSS Count, LSW, Current Period */
   IFX_uint16_t cntLOSS_FE_LSW;
   /** Far-End LOSS Count, MSW, Current Period */
   IFX_uint16_t cntLOSS_FE_MSW;
   /** Far-End UAS Count, LSW, Current Period */
   IFX_uint16_t cntUAS_FE_LSW;
   /** Far-End UAS Count, MSW, Current Period */
   IFX_uint16_t cntUAS_FE_MSW;
   /** Far-End FECS Count, LSW, Previous Period */
   IFX_uint16_t cntFECS_FE_LSW_prev;
   /** Far-End FECS Count, MSW, Previous Period */
   IFX_uint16_t cntFECS_FE_MSW_prev;
   /** Far-End ES Count, LSW, Previous Period */
   IFX_uint16_t cntES_FE_LSW_prev;
   /** Far-End ES Count, MSW, Previous Period */
   IFX_uint16_t cntES_FE_MSW_prev;
   /** Far-End SES Count, LSW, Previous Period */
   IFX_uint16_t cntSES_FE_LSW_prev;
   /** Far-End SES Count, MSW, Previous Period */
   IFX_uint16_t cntSES_FE_MSW_prev;
   /** Far-End LOSS Count, LSW, Previous Period */
   IFX_uint16_t cntLOSS_FE_LSW_prev;
   /** Far-End LOSS Count, MSW, Previous Period */
   IFX_uint16_t cntLOSS_FE_MSW_prev;
   /** Far-End UAS Count, LSW, Previous Period */
   IFX_uint16_t cntUAS_FE_LSW_prev;
   /** Far-End UAS Count, MSW, Previous Period */
   IFX_uint16_t cntUAS_FE_MSW_prev;
#else
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Far-End FECS Count, LSW, Current Period */
   IFX_uint16_t cntFECS_FE_LSW;
   /** Far-End FECS Count, MSW, Current Period */
   IFX_uint16_t cntFECS_FE_MSW;
   /** Far-End ES Count, LSW, Current Period */
   IFX_uint16_t cntES_FE_LSW;
   /** Far-End ES Count, MSW, Current Period */
   IFX_uint16_t cntES_FE_MSW;
   /** Far-End SES Count, LSW, Current Period */
   IFX_uint16_t cntSES_FE_LSW;
   /** Far-End SES Count, MSW, Current Period */
   IFX_uint16_t cntSES_FE_MSW;
   /** Far-End LOSS Count, LSW, Current Period */
   IFX_uint16_t cntLOSS_FE_LSW;
   /** Far-End LOSS Count, MSW, Current Period */
   IFX_uint16_t cntLOSS_FE_MSW;
   /** Far-End UAS Count, LSW, Current Period */
   IFX_uint16_t cntUAS_FE_LSW;
   /** Far-End UAS Count, MSW, Current Period */
   IFX_uint16_t cntUAS_FE_MSW;
   /** Far-End FECS Count, LSW, Previous Period */
   IFX_uint16_t cntFECS_FE_LSW_prev;
   /** Far-End FECS Count, MSW, Previous Period */
   IFX_uint16_t cntFECS_FE_MSW_prev;
   /** Far-End ES Count, LSW, Previous Period */
   IFX_uint16_t cntES_FE_LSW_prev;
   /** Far-End ES Count, MSW, Previous Period */
   IFX_uint16_t cntES_FE_MSW_prev;
   /** Far-End SES Count, LSW, Previous Period */
   IFX_uint16_t cntSES_FE_LSW_prev;
   /** Far-End SES Count, MSW, Previous Period */
   IFX_uint16_t cntSES_FE_MSW_prev;
   /** Far-End LOSS Count, LSW, Previous Period */
   IFX_uint16_t cntLOSS_FE_LSW_prev;
   /** Far-End LOSS Count, MSW, Previous Period */
   IFX_uint16_t cntLOSS_FE_MSW_prev;
   /** Far-End UAS Count, LSW, Previous Period */
   IFX_uint16_t cntUAS_FE_LSW_prev;
   /** Far-End UAS Count, MSW, Previous Period */
   IFX_uint16_t cntUAS_FE_MSW_prev;
#endif
} __PACKED__ ;


/**
   Acknowledgement for the message CMD_LinePerfCountFE_Set.

*/
struct ACK_LinePerfCountFE_Set
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
   Writes line initialization performance counter values (Section 7.2.1.3 of G.997.1)
   for the current and previous 15-min-TR1 period.
*/
struct CMD_LineInitCountSet
{
#if MEI_DRV_OS_BYTE_ORDER == MEI_DRV_OS_BIG_ENDIAN
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Full Init Count LSW, Current Period */
   IFX_uint16_t cntInit_LSW;
   /** Full Init Count MSW, Current Period */
   IFX_uint16_t cntInit_MSW;
   /** Failed Full Init Count LSW, Current Period */
   IFX_uint16_t cntInitFail_LSW;
   /** Failed Full Init Count MSW, Current Period */
   IFX_uint16_t cntInitFail_MSW;
   /** Reserved */
   IFX_uint16_t Res1[4];
   /** Full Init Count LSW, Previous Period */
   IFX_uint16_t cntInit_LSW_prev;
   /** Full Init Count MSW, Previous Period */
   IFX_uint16_t cntInit_MSW_prev;
   /** Failed Full Init Count LSW, Previous Period */
   IFX_uint16_t cntInitFail_LSW_prev;
   /** Failed Full Init Count MSW, Previous Period */
   IFX_uint16_t cntInitFail_MSW_prev;
   /** Reserved */
   IFX_uint16_t Res2[4];
#else
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Full Init Count LSW, Current Period */
   IFX_uint16_t cntInit_LSW;
   /** Full Init Count MSW, Current Period */
   IFX_uint16_t cntInit_MSW;
   /** Failed Full Init Count LSW, Current Period */
   IFX_uint16_t cntInitFail_LSW;
   /** Failed Full Init Count MSW, Current Period */
   IFX_uint16_t cntInitFail_MSW;
   /** Reserved */
   IFX_uint16_t Res1[4];
   /** Full Init Count LSW, Previous Period */
   IFX_uint16_t cntInit_LSW_prev;
   /** Full Init Count MSW, Previous Period */
   IFX_uint16_t cntInit_MSW_prev;
   /** Failed Full Init Count LSW, Previous Period */
   IFX_uint16_t cntInitFail_LSW_prev;
   /** Failed Full Init Count MSW, Previous Period */
   IFX_uint16_t cntInitFail_MSW_prev;
   /** Reserved */
   IFX_uint16_t Res2[4];
#endif
} __PACKED__ ;


/**
   Acknowledgement for the message CMD_LineInitCountSet.
*/
struct ACK_LineInitCountSet
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
   Writes the near-end CRC counter values (Section 7.2.2.1.1 of G997.1)
   Note: In VINAX V1.x the "LP1/Fast Path" parameters are used only in ADSL1 mode
   with selected "Fast Path".
*/
struct CMD_CRC_StatsNE_Set
{
#if MEI_DRV_OS_BYTE_ORDER == MEI_DRV_OS_BIG_ENDIAN
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Near-End CRC Count LP0, LSW, Current Period */
   IFX_uint16_t cntCVI_LSW;
   /** Near-End CRC Count LP0, MSW, Current Period */
   IFX_uint16_t cntCVI_MSW;
   /** Near-End CRC Count LP1, LSW, Current Period */
   IFX_uint16_t cntCVF_LSW;
   /** Near-End CRC Count LP1, MSW, Current Period */
   IFX_uint16_t cntCVF_MSW;
   /** Near-End CRC Count LP0, LSW, Previous Period */
   IFX_uint16_t cntCVI_LSW_prev;
   /** Near-End CRC Count LP0, MSW, Previous Period */
   IFX_uint16_t cntCVI_MSW_prev;
   /** Near-End CRC Count LP1, LSW, Previous Period */
   IFX_uint16_t cntCVF_LSW_prev;
   /** Near-End CRC Count LP1, MSW, Previous Period */
   IFX_uint16_t cntCVF_MSW_prev;
#else
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Near-End CRC Count LP0, LSW, Current Period */
   IFX_uint16_t cntCVI_LSW;
   /** Near-End CRC Count LP0, MSW, Current Period */
   IFX_uint16_t cntCVI_MSW;
   /** Near-End CRC Count LP1, LSW, Current Period */
   IFX_uint16_t cntCVF_LSW;
   /** Near-End CRC Count LP1, MSW, Current Period */
   IFX_uint16_t cntCVF_MSW;
   /** Near-End CRC Count LP0, LSW, Previous Period */
   IFX_uint16_t cntCVI_LSW_prev;
   /** Near-End CRC Count LP0, MSW, Previous Period */
   IFX_uint16_t cntCVI_MSW_prev;
   /** Near-End CRC Count LP1, LSW, Previous Period */
   IFX_uint16_t cntCVF_LSW_prev;
   /** Near-End CRC Count LP1, MSW, Previous Period */
   IFX_uint16_t cntCVF_MSW_prev;
#endif
} __PACKED__ ;


/**
   Acknowledgement for the message CMD_CRC_StatsNE_Set.
*/
struct ACK_CRC_StatsNE_Set
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
   Writes the far-end CRC counter values (Section 7.2.2.2.1 of G997.1)
   Note: In VINAX V1.x the "LP1/Fast Path" parameters are fed only in ADSL1 mode
   with selected fast path.
*/
struct CMD_CRC_StatsFE_Set
{
#if MEI_DRV_OS_BYTE_ORDER == MEI_DRV_OS_BIG_ENDIAN
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Far-End CRC Count LP0, LSW, Current Period */
   IFX_uint16_t cntCVI_LSW;
   /** Far-End CRC Count LP0, MSW, Current Period */
   IFX_uint16_t cntCVI_MSW;
   /** Far-End CRC Count LP1, LSW, Current Period */
   IFX_uint16_t cntCVF_LSW;
   /** Far-End CRC Count LP1, MSW, Current Period */
   IFX_uint16_t cntCVF_MSW;
   /** Far-End CRC Count LP0, LSW, Previous Period */
   IFX_uint16_t cntCVI_LSW_prev;
   /** Far-End CRC Count LP0, MSW, Previous Period */
   IFX_uint16_t cntCVI_MSW_prev;
   /** Far-End CRC Count LP1, LSW, Previous Period */
   IFX_uint16_t cntCVF_LSW_prev;
   /** Far-End CRC Count LP1, MSW, Previous Period */
   IFX_uint16_t cntCVF_MSW_prev;
#else
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Far-End CRC Count LP0, LSW, Current Period */
   IFX_uint16_t cntCVI_LSW;
   /** Far-End CRC Count LP0, MSW, Current Period */
   IFX_uint16_t cntCVI_MSW;
   /** Far-End CRC Count LP1, LSW, Current Period */
   IFX_uint16_t cntCVF_LSW;
   /** Far-End CRC Count LP1, MSW, Current Period */
   IFX_uint16_t cntCVF_MSW;
   /** Far-End CRC Count LP0, LSW, Previous Period */
   IFX_uint16_t cntCVI_LSW_prev;
   /** Far-End CRC Count LP0, MSW, Previous Period */
   IFX_uint16_t cntCVI_MSW_prev;
   /** Far-End CRC Count LP1, LSW, Previous Period */
   IFX_uint16_t cntCVF_LSW_prev;
   /** Far-End CRC Count LP1, MSW, Previous Period */
   IFX_uint16_t cntCVF_MSW_prev;
#endif
} __PACKED__ ;


/**
   Acknowledgement for the message CMD_CRC_StatsFE_Set.
*/
struct ACK_CRC_StatsFE_Set
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
   Writes near-end FEC counter values. (Section 7.2.2.1.2 of G997.1)
   Note: In VINAX V1.x the "LP1/Fast Path" parameters are used only in ADSL1 mode
   with selected "Fast Path".
*/
struct CMD_FEC_StatsNE_Set
{
#if MEI_DRV_OS_BYTE_ORDER == MEI_DRV_OS_BIG_ENDIAN
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Near-End FEC Count LP0, LSW, Current Period */
   IFX_uint16_t cntECI_LSW;
   /** Near-End FEC Count LP0, MSW, Current Period */
   IFX_uint16_t cntECI_MSW;
   /** Near-End FEC Count LP1, LSW, Current Period */
   IFX_uint16_t cntFEC_LSW;
   /** Near-End FEC Count LP1, MSW, Current Period */
   IFX_uint16_t cntFEC_MSW;
   /** Near-End FEC Uncorrectable Count LP0, LSW, Current Period */
   IFX_uint16_t cntECI_NoCorrLSW;
   /** Near-End FEC Uncorrectable Count LP0, MSW, Current Period */
   IFX_uint16_t cntECI_NoCorrMSW;
   /** Near-End FEC Uncorrectable Count LP1, LSW, Current Period */
   IFX_uint16_t cntECF_NoCorrLSW;
   /** Near-End FEC Uncorrectable Count LP1, MSW, Current Period */
   IFX_uint16_t cntECF_NoCorrMSW;
   /** Near-End Total RS CW Count LP0, LSW, Current Period */
   IFX_uint16_t cntECI_CW_LSW;
   /** Near-End Total RS CW Count LP0, MSW, Current Period */
   IFX_uint16_t cntECI_CW_MSW;
   /** Near-End Total RS CW Count LP1, LSW, Current Period */
   IFX_uint16_t cntECF_CW_LSW;
   /** Near-End Total RS CW Count LP1, MSW, Current Period */
   IFX_uint16_t cntECF_CW_MSW;
   /** Near-End FEC Count LP0, LSW, Previous Period */
   IFX_uint16_t cntECI_LSW_prev;
   /** Near-End FEC Count LP0, MSW, Previous Period */
   IFX_uint16_t cntECI_MSW_prev;
   /** Near-End FEC Count LP1, LSW, Previous Period */
   IFX_uint16_t cntECF_LSW_prev;
   /** Near-End FEC Count LP1, MSW, Previous Period */
   IFX_uint16_t cntECF_MSW_prev;
   /** Near-End FEC Uncorrectable Count LP0, LSW, Previous Period */
   IFX_uint16_t cntECI_NoCorrLSW_prev;
   /** Near-End FEC Uncorrectable Count LP0, MSW, Previous Period */
   IFX_uint16_t cntECI_NoCorrMSW_prev;
   /** Near-End FEC Uncorrectable Count LP1, LSW, Previous Period */
   IFX_uint16_t cntECF_NoCorrLSW_prev;
   /** Near-End FEC Uncorrectable Count LP1, MSW, Previous Period */
   IFX_uint16_t cntECF_NoCorrMSW_prev;
   /** Near-End Total RS CW Count LP0, LSW, Previous Period */
   IFX_uint16_t cntECI_CW_LSW_prev;
   /** Near-End Total RS CW Count LP0, MSW, Previous Period */
   IFX_uint16_t cntECI_CW_MSW_prev;
   /** Near-End Total RS CW Count LP1, LSW, Previous Period */
   IFX_uint16_t cntECF_CW_LSW_prev;
   /** Near-End Total RS CW Count LP1, MSW, Previous Period */
   IFX_uint16_t cntECF_CW_MSW_prev;
#else
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Near-End FEC Count LP0, LSW, Current Period */
   IFX_uint16_t cntECI_LSW;
   /** Near-End FEC Count LP0, MSW, Current Period */
   IFX_uint16_t cntECI_MSW;
   /** Near-End FEC Count LP1, LSW, Current Period */
   IFX_uint16_t cntFEC_LSW;
   /** Near-End FEC Count LP1, MSW, Current Period */
   IFX_uint16_t cntFEC_MSW;
   /** Near-End FEC Uncorrectable Count LP0, LSW, Current Period */
   IFX_uint16_t cntECI_NoCorrLSW;
   /** Near-End FEC Uncorrectable Count LP0, MSW, Current Period */
   IFX_uint16_t cntECI_NoCorrMSW;
   /** Near-End FEC Uncorrectable Count LP1, LSW, Current Period */
   IFX_uint16_t cntECF_NoCorrLSW;
   /** Near-End FEC Uncorrectable Count LP1, MSW, Current Period */
   IFX_uint16_t cntECF_NoCorrMSW;
   /** Near-End Total RS CW Count LP0, LSW, Current Period */
   IFX_uint16_t cntECI_CW_LSW;
   /** Near-End Total RS CW Count LP0, MSW, Current Period */
   IFX_uint16_t cntECI_CW_MSW;
   /** Near-End Total RS CW Count LP1, LSW, Current Period */
   IFX_uint16_t cntECF_CW_LSW;
   /** Near-End Total RS CW Count LP1, MSW, Current Period */
   IFX_uint16_t cntECF_CW_MSW;
   /** Near-End FEC Count LP0, LSW, Previous Period */
   IFX_uint16_t cntECI_LSW_prev;
   /** Near-End FEC Count LP0, MSW, Previous Period */
   IFX_uint16_t cntECI_MSW_prev;
   /** Near-End FEC Count LP1, LSW, Previous Period */
   IFX_uint16_t cntECF_LSW_prev;
   /** Near-End FEC Count LP1, MSW, Previous Period */
   IFX_uint16_t cntECF_MSW_prev;
   /** Near-End FEC Uncorrectable Count LP0, LSW, Previous Period */
   IFX_uint16_t cntECI_NoCorrLSW_prev;
   /** Near-End FEC Uncorrectable Count LP0, MSW, Previous Period */
   IFX_uint16_t cntECI_NoCorrMSW_prev;
   /** Near-End FEC Uncorrectable Count LP1, LSW, Previous Period */
   IFX_uint16_t cntECF_NoCorrLSW_prev;
   /** Near-End FEC Uncorrectable Count LP1, MSW, Previous Period */
   IFX_uint16_t cntECF_NoCorrMSW_prev;
   /** Near-End Total RS CW Count LP0, LSW, Previous Period */
   IFX_uint16_t cntECI_CW_LSW_prev;
   /** Near-End Total RS CW Count LP0, MSW, Previous Period */
   IFX_uint16_t cntECI_CW_MSW_prev;
   /** Near-End Total RS CW Count LP1, LSW, Previous Period */
   IFX_uint16_t cntECF_CW_LSW_prev;
   /** Near-End Total RS CW Count LP1, MSW, Previous Period */
   IFX_uint16_t cntECF_CW_MSW_prev;
#endif
} __PACKED__ ;


/**
   Acknowledgement for the message CMD_FEC_StatsNE_Set.
*/
struct ACK_FEC_StatsNE_Set
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
   Writes near-end FEC counter values. (Section 7.2.2.2.2 of G997.1)
   Note: In VINAX V1.x the "LP1/Fast Path" parameters are used only in ADSL1 mode
   with selected "Fast Path".
*/
struct CMD_FEC_StatsFE_Set
{
#if MEI_DRV_OS_BYTE_ORDER == MEI_DRV_OS_BIG_ENDIAN
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Far-End FEC Count LP0, LSW, Current Period */
   IFX_uint16_t cntECI_LSW;
   /** Far-End FEC Count LP0, MSW, Current Period */
   IFX_uint16_t cntECI_MSW;
   /** Far-End FEC Count LP1, LSW, Current Period */
   IFX_uint16_t cntFEC_LSW;
   /** Far-End FEC Count LP1, MSW, Current Period */
   IFX_uint16_t cntFEC_MSW;
   /** Reserved */
   IFX_uint16_t Res06[4];
   /** Far-End Total RS CW Count LP0, LSW, Current Period */
   IFX_uint16_t cntECI_CW_LSW;
   /** Far-End Total RS CW Count LP0, MSW, Current Period */
   IFX_uint16_t cntECI_CW_MSW;
   /** Far-End Total RS CW Count LP1, LSW, Current Period */
   IFX_uint16_t cntECF_CW_LSW;
   /** Far-End Total RS CW Count LP1, MSW, Current Period */
   IFX_uint16_t cntECF_CW_MSW;
   /** Far-End FEC Count LP0, LSW, Previous Period */
   IFX_uint16_t cntECI_LSW_prev;
   /** Far-End FEC Count LP0, MSW, Previous Period */
   IFX_uint16_t cntECI_MSW_prev;
   /** Far-End FEC Count LP1, LSW, Previous Period */
   IFX_uint16_t cntECF_LSW_prev;
   /** Far-End FEC Count LP1, MSW, Previous Period */
   IFX_uint16_t cntECF_MSW_prev;
   /** Reserved */
   IFX_uint16_t Res15[4];
   /** Far-End Total RS CW Count LP0, LSW, Previous Period */
   IFX_uint16_t cntECI_CW_LSW_prev;
   /** Far-End Total RS CW Count LP0, MSW, Previous Period */
   IFX_uint16_t cntECI_CW_MSW_prev;
   /** Far-End Total RS CW Count LP1, LSW, Previous Period */
   IFX_uint16_t cntECF_CW_LSW_prev;
   /** Far-End Total RS CW Count LP1, MSW, Previous Period */
   IFX_uint16_t cntECF_CW_MSW_prev;
#else
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Far-End FEC Count LP0, LSW, Current Period */
   IFX_uint16_t cntECI_LSW;
   /** Far-End FEC Count LP0, MSW, Current Period */
   IFX_uint16_t cntECI_MSW;
   /** Far-End FEC Count LP1, LSW, Current Period */
   IFX_uint16_t cntFEC_LSW;
   /** Far-End FEC Count LP1, MSW, Current Period */
   IFX_uint16_t cntFEC_MSW;
   /** Reserved */
   IFX_uint16_t Res06[4];
   /** Far-End Total RS CW Count LP0, LSW, Current Period */
   IFX_uint16_t cntECI_CW_LSW;
   /** Far-End Total RS CW Count LP0, MSW, Current Period */
   IFX_uint16_t cntECI_CW_MSW;
   /** Far-End Total RS CW Count LP1, LSW, Current Period */
   IFX_uint16_t cntECF_CW_LSW;
   /** Far-End Total RS CW Count LP1, MSW, Current Period */
   IFX_uint16_t cntECF_CW_MSW;
   /** Far-End FEC Count LP0, LSW, Previous Period */
   IFX_uint16_t cntECI_LSW_prev;
   /** Far-End FEC Count LP0, MSW, Previous Period */
   IFX_uint16_t cntECI_MSW_prev;
   /** Far-End FEC Count LP1, LSW, Previous Period */
   IFX_uint16_t cntECF_LSW_prev;
   /** Far-End FEC Count LP1, MSW, Previous Period */
   IFX_uint16_t cntECF_MSW_prev;
   /** Reserved */
   IFX_uint16_t Res15[4];
   /** Far-End Total RS CW Count LP0, LSW, Previous Period */
   IFX_uint16_t cntECI_CW_LSW_prev;
   /** Far-End Total RS CW Count LP0, MSW, Previous Period */
   IFX_uint16_t cntECI_CW_MSW_prev;
   /** Far-End Total RS CW Count LP1, LSW, Previous Period */
   IFX_uint16_t cntECF_CW_LSW_prev;
   /** Far-End Total RS CW Count LP1, MSW, Previous Period */
   IFX_uint16_t cntECF_CW_MSW_prev;
#endif
} __PACKED__ ;


/**
   Acknowledgement for the message CMD_FEC_StatsFE_Set.
*/
struct ACK_FEC_StatsFE_Set
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
   Requests near-end line performance counter values (Section 7.2.1.1 of G.997.1).
   These are wrap-around counters which are not affected by the TR1-period.
*/
struct CMD_LinePerfCountNE_NoTR1Get
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
   Provides near-end line performance counter values requested by
   CMD_LinePerfCountNE_NoTR1Get (Section 7.2.1.1 of G.997.1). These are wrap-around
   counters which are not affected by the TR1-period.
*/
struct ACK_LinePerfCountNE_NoTR1Get
{
#if MEI_DRV_OS_BYTE_ORDER == MEI_DRV_OS_BIG_ENDIAN
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Near-End FECS Count, LSW */
   IFX_uint16_t cntFECS_LSW;
   /** Near-End FECS Count, MSW */
   IFX_uint16_t cntFECS_MSW;
   /** Near-End ES Count, LSW */
   IFX_uint16_t cntES_LSW;
   /** Near-End ES Count, MSW */
   IFX_uint16_t cntES_MSW;
   /** Near-End SES Count, LSW */
   IFX_uint16_t cntSES_LSW;
   /** Near-End SES Count, MSW */
   IFX_uint16_t cntSES_MSW;
   /** Near-End LOSS Count, LSW */
   IFX_uint16_t cntLOSS_LSW;
   /** Near-End LOSS Count, MSW */
   IFX_uint16_t cntLOSS_MSW;
   /** Reserved */
   IFX_uint16_t Res10[2];
#else
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Near-End FECS Count, LSW */
   IFX_uint16_t cntFECS_LSW;
   /** Near-End FECS Count, MSW */
   IFX_uint16_t cntFECS_MSW;
   /** Near-End ES Count, LSW */
   IFX_uint16_t cntES_LSW;
   /** Near-End ES Count, MSW */
   IFX_uint16_t cntES_MSW;
   /** Near-End SES Count, LSW */
   IFX_uint16_t cntSES_LSW;
   /** Near-End SES Count, MSW */
   IFX_uint16_t cntSES_MSW;
   /** Near-End LOSS Count, LSW */
   IFX_uint16_t cntLOSS_LSW;
   /** Near-End LOSS Count, MSW */
   IFX_uint16_t cntLOSS_MSW;
   /** Reserved */
   IFX_uint16_t Res10[2];
#endif
} __PACKED__ ;


/**
   Requests far-end line performance counter values (Section 7.2.1.2 of G.997.1). These
   are wrap-around counters which are not affected by the TR1-period.
*/
struct CMD_LinePerfCountFE_NoTR1Get
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
   Provides far-end line performance counter values requested by
   CMD_LinePerfCountFE_NoTR1Get (Section 7.2.1.2 of G.997.1). These are wrap-around
   counters which are not affected by the TR1-period.
*/
struct ACK_LinePerfCountFE_NoTR1Get
{
#if MEI_DRV_OS_BYTE_ORDER == MEI_DRV_OS_BIG_ENDIAN
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Far-End FECS Count, LSW */
   IFX_uint16_t cntFECS_LSW;
   /** Far-End FECS Count, MSW */
   IFX_uint16_t cntFECS_MSW;
   /** Far-End ES Count, LSW */
   IFX_uint16_t cntES_LSW;
   /** Far-End ES Count, MSW */
   IFX_uint16_t cntES_MSW;
   /** Far-End SES Count, LSW */
   IFX_uint16_t cntSES_LSW;
   /** Far-End SES Count, MSW */
   IFX_uint16_t cntSES_MSW;
   /** Far-End LOSS Count, LSW */
   IFX_uint16_t cntLOSS_LSW;
   /** Far-End LOSS Count, MSW */
   IFX_uint16_t cntLOSS_MSW;
   /** Reserved */
   IFX_uint16_t Res10[2];
#else
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Far-End FECS Count, LSW */
   IFX_uint16_t cntFECS_LSW;
   /** Far-End FECS Count, MSW */
   IFX_uint16_t cntFECS_MSW;
   /** Far-End ES Count, LSW */
   IFX_uint16_t cntES_LSW;
   /** Far-End ES Count, MSW */
   IFX_uint16_t cntES_MSW;
   /** Far-End SES Count, LSW */
   IFX_uint16_t cntSES_LSW;
   /** Far-End SES Count, MSW */
   IFX_uint16_t cntSES_MSW;
   /** Far-End LOSS Count, LSW */
   IFX_uint16_t cntLOSS_LSW;
   /** Far-End LOSS Count, MSW */
   IFX_uint16_t cntLOSS_MSW;
   /** Reserved */
   IFX_uint16_t Res10[2];
#endif
} __PACKED__ ;


/**
   Requests near-end CRC counter values. These are wrap-around counters which are not
   affected by the TR1-period.
*/
struct CMD_CRC_StatsNE_NoTR1Get
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
   Returns near-end CRC counter values. (Section 7.2.2.1.1 of G997.1). These are
   wrap-around counters which are not affected by the TR1-period.
*/
struct ACK_CRC_StatsNE_NoTR1Get
{
#if MEI_DRV_OS_BYTE_ORDER == MEI_DRV_OS_BIG_ENDIAN
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Near-End CRC Count LP0, LSW */
   IFX_uint16_t cntCVI_LSW;
   /** Near-End CRC Count LP0, MSW */
   IFX_uint16_t cntCVI_MSW;
   /** Reserved */
   IFX_uint16_t Res04;
   /** Reserved */
   IFX_uint16_t Res05;
#else
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Near-End CRC Count LP0, LSW */
   IFX_uint16_t cntCVI_LSW;
   /** Near-End CRC Count LP0, MSW */
   IFX_uint16_t cntCVI_MSW;
   /** Reserved */
   IFX_uint16_t Res04;
   /** Reserved */
   IFX_uint16_t Res05;
#endif
} __PACKED__ ;


/**
   Requests far-end CRC counter values. These are wrap-around counters which are not
   affected by the TR1-period.
*/
struct CMD_CRC_StatsFE_NoTR1Get
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
   Returns far-end CRC counter values. (Section 7.2.2.2.1 of G997.1). These are
   wrap-around counters which are not affected by the TR1-period.
*/
struct ACK_CRC_StatsFE_NoTR1Get
{
#if MEI_DRV_OS_BYTE_ORDER == MEI_DRV_OS_BIG_ENDIAN
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Far-End CRC Count LP0, LSW */
   IFX_uint16_t cntCVI_LSW;
   /** Far-End CRC Count LP0, MSW */
   IFX_uint16_t cntCVI_MSW;
   /** Reserved */
   IFX_uint16_t Res04[2];
#else
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Far-End CRC Count LP0, LSW */
   IFX_uint16_t cntCVI_LSW;
   /** Far-End CRC Count LP0, MSW */
   IFX_uint16_t cntCVI_MSW;
   /** Reserved */
   IFX_uint16_t Res04[2];
#endif
} __PACKED__ ;


/**
   Requests near-end FEC counter values. These are wrap-around counters which are not
   affected by the TR1-period.
*/
struct CMD_FEC_StatsNE_NoTR1Get
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
   Returns near-end FEC counter values (Section 7.2.2.1.2 of G997.1). These are
   wrap-around counters which are not affected by the TR1-period.
*/
struct ACK_FEC_StatsNE_NoTR1Get
{
#if MEI_DRV_OS_BYTE_ORDER == MEI_DRV_OS_BIG_ENDIAN
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Near-End FEC Count LP0, LSW */
   IFX_uint16_t cntECI_LSW;
   /** Near-End FEC Count LP0, MSW */
   IFX_uint16_t cntECI_MSW;
   /** Reserved */
   IFX_uint16_t Res1[2];
   /** Reserved */
   IFX_uint16_t Res2[8];
#else
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Near-End FEC Count LP0, LSW */
   IFX_uint16_t cntECI_LSW;
   /** Near-End FEC Count LP0, MSW */
   IFX_uint16_t cntECI_MSW;
   /** Reserved */
   IFX_uint16_t Res1[2];
   /** Reserved */
   IFX_uint16_t Res2[8];
#endif
} __PACKED__ ;


/**
   Requests far-end FEC counter values. These are wrap-around counters which are not
   affected by the TR1-period.
*/
struct CMD_FEC_StatsFE_NoTR1Get
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
   Returns far-end FEC counter values (Section 7.2.2.2.2 of G997.1). These are
   wrap-around counters which are not affected by the TR1-period.
*/
struct ACK_FEC_StatsFE_NoTR1Get
{
#if MEI_DRV_OS_BYTE_ORDER == MEI_DRV_OS_BIG_ENDIAN
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Far-End FEC Count LP0, LSW */
   IFX_uint16_t cntECI_LSW;
   /** Far-End FEC Count LP0, MSW */
   IFX_uint16_t cntECI_MSW;
   /** Reserved */
   IFX_uint16_t Res1[2];
   /** Reserved */
   IFX_uint16_t Res2[8];
#else
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Far-End FEC Count LP0, LSW */
   IFX_uint16_t cntECI_LSW;
   /** Far-End FEC Count LP0, MSW */
   IFX_uint16_t cntECI_MSW;
   /** Reserved */
   IFX_uint16_t Res1[2];
   /** Reserved */
   IFX_uint16_t Res2[8];
#endif
} __PACKED__ ;


/**
   Writes near-end line performance counter values (Section 7.2.1.1 of G.997.1). These
   are wrap-around counters which are not affected by the TR1-period.
*/
struct CMD_LinePerfCountNE_NoTR1Set
{
#if MEI_DRV_OS_BYTE_ORDER == MEI_DRV_OS_BIG_ENDIAN
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Near-End FECS Count, LSW */
   IFX_uint16_t cntFECS_LSW;
   /** Near-End FECS Count, MSW */
   IFX_uint16_t cntFECS_MSW;
   /** Near-End ES Count, LSW */
   IFX_uint16_t cntES_LSW;
   /** Near-End ES Count, MSW */
   IFX_uint16_t cntES_MSW;
   /** Near-End SES Count, LSW */
   IFX_uint16_t cntSES_LSW;
   /** Near-End SES Count, MSW */
   IFX_uint16_t cntSES_MSW;
   /** Near-End LOSS Count, LSW */
   IFX_uint16_t cntLOSS_LSW;
   /** Near-End LOSS Count, MSW */
   IFX_uint16_t cntLOSS_MSW;
   /** Near-End UAS Count, LSW */
   IFX_uint16_t cntUAS_LSW;
   /** Near-End UAS Count, MSW */
   IFX_uint16_t cntUAS_MSW;
#else
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Near-End FECS Count, LSW */
   IFX_uint16_t cntFECS_LSW;
   /** Near-End FECS Count, MSW */
   IFX_uint16_t cntFECS_MSW;
   /** Near-End ES Count, LSW */
   IFX_uint16_t cntES_LSW;
   /** Near-End ES Count, MSW */
   IFX_uint16_t cntES_MSW;
   /** Near-End SES Count, LSW */
   IFX_uint16_t cntSES_LSW;
   /** Near-End SES Count, MSW */
   IFX_uint16_t cntSES_MSW;
   /** Near-End LOSS Count, LSW */
   IFX_uint16_t cntLOSS_LSW;
   /** Near-End LOSS Count, MSW */
   IFX_uint16_t cntLOSS_MSW;
   /** Near-End UAS Count, LSW */
   IFX_uint16_t cntUAS_LSW;
   /** Near-End UAS Count, MSW */
   IFX_uint16_t cntUAS_MSW;
#endif
} __PACKED__ ;


/**
   Acknowledgement for message CMD_LinePerfCountNE_NoTR1Set.
*/
struct ACK_LinePerfCountNE_NoTR1Set
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
   Writes near-end CRC counter values. (Section 7.2.2.1.1 of G997.1). These are
   wrap-around counters which are not affected by the TR1-period.
*/
struct CMD_CRC_StatsNE_NoTR1Set
{
#if MEI_DRV_OS_BYTE_ORDER == MEI_DRV_OS_BIG_ENDIAN
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Near-End CRC Count LP0, LSW */
   IFX_uint16_t cntCVI_LSW;
   /** Near-End CRC Count LP0, MSW */
   IFX_uint16_t cntCVI_MSW;
   /** Reserved */
   IFX_uint16_t Res04;
   /** Reserved */
   IFX_uint16_t Res05;
#else
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Near-End CRC Count LP0, LSW */
   IFX_uint16_t cntCVI_LSW;
   /** Near-End CRC Count LP0, MSW */
   IFX_uint16_t cntCVI_MSW;
   /** Reserved */
   IFX_uint16_t Res04;
   /** Reserved */
   IFX_uint16_t Res05;
#endif
} __PACKED__ ;


/**
   Acknowledgement for message CMD_CRC_StatsNE_NoTR1Set.
*/
struct ACK_CRC_StatsNE_NoTR1Set
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
   Writes near-end FEC counter values (Section 7.2.2.1.2 of G997.1). These are
   wrap-around counters which are not affected by the TR1-period.
*/
struct CMD_FEC_StatsNE_NoTR1Set
{
#if MEI_DRV_OS_BYTE_ORDER == MEI_DRV_OS_BIG_ENDIAN
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Near-End FEC Count LP0, LSW */
   IFX_uint16_t cntECI_LSW;
   /** Near-End FEC Count LP0, MSW */
   IFX_uint16_t cntECI_MSW;
   /** Reserved */
   IFX_uint16_t Res1[2];
   /** Reserved */
   IFX_uint16_t Res2[8];
#else
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Near-End FEC Count LP0, LSW */
   IFX_uint16_t cntECI_LSW;
   /** Near-End FEC Count LP0, MSW */
   IFX_uint16_t cntECI_MSW;
   /** Reserved */
   IFX_uint16_t Res1[2];
   /** Reserved */
   IFX_uint16_t Res2[8];
#endif
} __PACKED__ ;


/**
   Acknowledgement for message CMD_FEC_StatsNE_NoTR1Set.
*/
struct ACK_FEC_StatsNE_NoTR1Set
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
   Controls the "Set-Time" and "Read-Time" EOC messages to either synchronize or read
   the time of the xTU-R.
   Note: Modifying the Time does not affect the TR1 supervision period and the
   TR1-counters.
*/
struct CMD_TimeControl
{
#if MEI_DRV_OS_BYTE_ORDER == MEI_DRV_OS_BIG_ENDIAN
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Reserved */
   IFX_uint16_t Res02 : 13;
   /** Reserved */
   IFX_uint16_t Res1 : 1;
   /** Status of Set Time */
   IFX_uint16_t TimeControl : 2;
#else
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Status of Set Time */
   IFX_uint16_t TimeControl : 2;
   /** Reserved */
   IFX_uint16_t Res1 : 1;
   /** Reserved */
   IFX_uint16_t Res02 : 13;
#endif
} __PACKED__ ;


/**
   Acknowledgement for message CMD_TimeControl.
*/
struct ACK_TimeControl
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
   Sets the time.
   To synchronize the time of the xTU-C and xTU-R, the xTU-C sets the far-end time
   parameter and then triggers the sending of the EOC time command to transfer the
   configured value to the opposite side using CMD_TimeControl.
   Note: Modifying the Time does not affect the TR1 supervision period and the
   TR1-counters.
*/
struct CMD_TimeSet
{
#if MEI_DRV_OS_BYTE_ORDER == MEI_DRV_OS_BIG_ENDIAN
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Reserved */
   IFX_uint16_t Res02;
   /** FE Time */
   VNX_TIME_t timeFE;
   /** NE Time */
   VNX_TIME_t timeNE;
#else
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Reserved */
   IFX_uint16_t Res02;
   /** NE Time */
   VNX_TIME_t timeNE;
   /** FE Time */
   VNX_TIME_t timeFE;
#endif
} __PACKED__ ;


/**
   Acknowledgement for message CMD_TimeSet.
*/
struct ACK_TimeSet
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
   Requests the status of the "Set Time and Read Time" EOC messages.
*/
struct CMD_TimeGet
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
   Provides the status of the "Set Time and Read Time" EOC messages.
*/
struct ACK_TimeGet
{
#if MEI_DRV_OS_BYTE_ORDER == MEI_DRV_OS_BIG_ENDIAN
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Reserved */
   IFX_uint16_t Res02 : 14;
   /** Status of Read Time */
   IFX_uint16_t statusTimeMsg : 2;
   /** FE Time */
   VNX_TIME_t timeFE;
   /** NE Time */
   VNX_TIME_t timeNE;
#else
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Status of Read Time */
   IFX_uint16_t statusTimeMsg : 2;
   /** Reserved */
   IFX_uint16_t Res02 : 14;
   /** NE Time */
   VNX_TIME_t timeNE;
   /** FE Time */
   VNX_TIME_t timeFE;
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

