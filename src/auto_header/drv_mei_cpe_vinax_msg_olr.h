/******************************************************************************

                               Copyright (c) 2011
                            Lantiq Deutschland GmbH
                     Am Campeon 3; 85579 Neubiberg, Germany

  For licensing information, see the file 'LICENSE' in the root folder of
  this software module.

******************************************************************************/


#ifndef _VDSL2_FWDES_DIAGSCLEOCOLR_H_
#define _VDSL2_FWDES_DIAGSCLEOCOLR_H_

/** \file
   This chapter lists messages that provide detailed information about the chosen
   configuration, especially information that is available per tone, like
   bits-per-tone, fine-gains etc.
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

/** @defgroup _VDSL2_FWDES_DIAGSCLEOCOLR_ Messages for Bit-/Gain-/SNR Tables
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
#define  CMD_TestParamsFE_Request_TRIGGER  0x1
#define  CMD_TestParamsFE_Request_ABORT  0x0
#define  ACK_TestParamsFE_Poll_ONGOING  0x1
#define  CMD_ClearEOC_TxTrigger_IDLE  0
#define  CMD_ClearEOC_TxTrigger_START  1
#define  ACK_ClearEOCStatusGet_IDLE  0
#define  ACK_ClearEOCStatusGet_TXPROG  1
#define  ACK_ClearEOCStatusGet_Reserved  2
#define  ACK_ClearEOCStatusGet_TXERR  3
#define  ACK_ClearEOCStatusGet_RXPROG  1
#define  ACK_ClearEOCStatusGet_RXDONE  2
#define  ACK_ClearEOCStatusGet_RXERR  3
#define  EVT_ClearEOCStatusGet_IDLE  0
#define  EVT_ClearEOCStatusGet_TXPROG  1
#define  EVT_ClearEOCStatusGet_TXDONE  2
#define  EVT_ClearEOCStatusGet_TXERR  3
#define  EVT_ClearEOCStatusGet_RXPROG  1
#define  EVT_ClearEOCStatusGet_RXDONE  2
#define  EVT_ClearEOCStatusGet_RXERR  3
#define  CMD_ClearEOCStatusSet_IDLE  0
#define  CMD_SOS_DS_Configure_TONE_ALL  0
#define  CMD_SOS_DS_Configure_TONE_256  2
#define  CMD_SOS_DS_Configure_TONE_512  3
#define  CMD_SOS_DS_Configure_TONE_1024  4
#define  CMD_SOS_US_Configure_TONE_ALL  0
#define  CMD_SOS_US_Configure_TONE_256  2
#define  CMD_SOS_US_Configure_TONE_512  3
#define  CMD_SOS_US_Configure_TONE_1024  4
#define  ACK_RA_ModeDS_Get_MANUAL  1
#define  ACK_RA_ModeDS_Get_AT_INIT  2
#define  ACK_RA_ModeDS_Get_DYNAMIC  3
#define  ACK_RA_ModeDS_Get_SOS  4
#define  ACK_RA_ModeUS_Get_MANUAL  1
#define  ACK_RA_ModeUS_Get_AT_INIT  2
#define  ACK_RA_ModeUS_Get_DYNAMIC  3
#define  ACK_RA_ModeUS_Get_SOS  4
#define  CMD_DebugTrailControl_CYCLIC_ON  1
#define  CMD_SELT_Configure_FLOATINGP  1
/* ----- Constants Definition section (End) ----- */

/** Message ID for CMD_BAT_TableEntriesGet */
#define CMD_BAT_TABLEENTRIESGET 0x1703

/**
   Requests information about the bit-allocation per subcarrier in VDSL mode. The
   values for all subcarriers of both directions can be retrieved.
   (For ADSL use CMD_ADSL_BAT_DS_Get and CMD_ADSL_BAT_US_Get).
*/
typedef struct CMD_BAT_TableEntriesGet CMD_BAT_TableEntriesGet_t;

/** Message ID for ACK_BAT_TableEntriesGet */
#define ACK_BAT_TABLEENTRIESGET 0x1703

/**
   Returns information about the bit-allocation per tone for the chosen range of
   subcarriers.(Section 7.5.1.29.1-2 of G997.1)
*/
typedef struct ACK_BAT_TableEntriesGet ACK_BAT_TableEntriesGet_t;

/** Message ID for CMD_GainTableEntriesGet */
#define CMD_GAINTABLEENTRIESGET 0x1903

/**
   Requests information about the Gains per subcarrier. The values for all subcarriers
   of both directions can be retrieved.
   (For ADSL use CMD_ADSL_GainTableDS_Get and CMD_ADSL_GainTableUS_Get).
*/
typedef struct CMD_GainTableEntriesGet CMD_GainTableEntriesGet_t;

/** Message ID for ACK_GainTableEntriesGet */
#define ACK_GAINTABLEENTRIESGET 0x1903

/**
   Returns information about the Gain-per-tone for the chosen range of
   subcarriers.(Section 7.5.1.29.3-4 of G997.1)
*/
typedef struct ACK_GainTableEntriesGet ACK_GainTableEntriesGet_t;

/** Message ID for CMD_SNR_NE_TableEntriesGet */
#define CMD_SNR_NE_TABLEENTRIESGET 0x0B03

/**
   The message requests information about the SNR per subcarrier available at the
   near-end side , which means for upstream direction at the CO side and for downstream
   direction at the CPE. It is the hosts responsibility to select the tone indices
   accordingly.
*/
typedef struct CMD_SNR_NE_TableEntriesGet CMD_SNR_NE_TableEntriesGet_t;

/** Message ID for ACK_SNR_NE_TableEntriesGet */
#define ACK_SNR_NE_TABLEENTRIESGET 0x0B03

/**
   Returns information about the SNR per subcarrier available at the near-end side,
   which means for upstream direction at the CO side and for downstream direction at
   the CPE.
*/
typedef struct ACK_SNR_NE_TableEntriesGet ACK_SNR_NE_TableEntriesGet_t;

/** Message ID for CMD_ADSL_BAT_DS_Get */
#define CMD_ADSL_BAT_DS_GET 0x070E

/**
   Requests information about the downstream bit-allocation per subcarrier in ADSL
   mode.
*/
typedef struct CMD_ADSL_BAT_DS_Get CMD_ADSL_BAT_DS_Get_t;

/** Message ID for ACK_ADSL_BAT_DS_Get */
#define ACK_ADSL_BAT_DS_GET 0x070E

/**
   Returns information about the downstream bit-allocation per tone for the chosen
   range of subcarriers.(Section 7.5.1.29.1 of G997.1)
*/
typedef struct ACK_ADSL_BAT_DS_Get ACK_ADSL_BAT_DS_Get_t;

/** Message ID for CMD_ADSL_BAT_US_Get */
#define CMD_ADSL_BAT_US_GET 0x060E

/**
   Requests information about the upstream bit-allocation per subcarrier in ADSL mode.
*/
typedef struct CMD_ADSL_BAT_US_Get CMD_ADSL_BAT_US_Get_t;

/** Message ID for ACK_ADSL_BAT_US_Get */
#define ACK_ADSL_BAT_US_GET 0x060E

/**
   Returns information about the upstream bit-allocation per tone for the chosen range
   of subcarriers.(Section 7.5.1.29.2 of G997.1)
*/
typedef struct ACK_ADSL_BAT_US_Get ACK_ADSL_BAT_US_Get_t;

/** Message ID for CMD_ADSL_GainTableDS_Get */
#define CMD_ADSL_GAINTABLEDS_GET 0x090E

/**
   Requests information about the Gains per subcarrier for the downstream direction.
*/
typedef struct CMD_ADSL_GainTableDS_Get CMD_ADSL_GainTableDS_Get_t;

/** Message ID for ACK_ADSL_GainTableDS_Get */
#define ACK_ADSL_GAINTABLEDS_GET 0x090E

/**
   Returns information about the Gain-per-tone for the chosen range of subcarriers for
   the downstream direction.(Section 7.5.1.29.3 of G997.1) as requested by
   CMD_ADSL_GainTableDS_Get.
*/
typedef struct ACK_ADSL_GainTableDS_Get ACK_ADSL_GainTableDS_Get_t;

/** Message ID for CMD_ADSL_GainTableUS_Get */
#define CMD_ADSL_GAINTABLEUS_GET 0x080E

/**
   Requests information about the Gains per subcarrier for the upstream direction.
*/
typedef struct CMD_ADSL_GainTableUS_Get CMD_ADSL_GainTableUS_Get_t;

/** Message ID for ACK_ADSL_GainTableUS_Get */
#define ACK_ADSL_GAINTABLEUS_GET 0x080E

/**
   Returns information about the Gain-per-tone for the chosen range of subcarriers for
   the upstream direction.(Section 7.5.1.29.4 of G997.1)
*/
typedef struct ACK_ADSL_GainTableUS_Get ACK_ADSL_GainTableUS_Get_t;

/** Message ID for CMD_ADSL_ExMarginReductionGet */
#define CMD_ADSL_EXMARGINREDUCTIONGET 0x2F03

/**
   Requests information about the Excess Margin Reduction needed for the fine gain
   calculation at the ATU_R.(See also ACK_ADSL_GainTableDS_Get).
*/
typedef struct CMD_ADSL_ExMarginReductionGet CMD_ADSL_ExMarginReductionGet_t;

/** Message ID for ACK_ADSL_ExMarginReductionGet */
#define ACK_ADSL_EXMARGINREDUCTIONGET 0x2F03

/**
   Returns information about the Excess Margin Reduction for the downstream direction.
*/
typedef struct ACK_ADSL_ExMarginReductionGet ACK_ADSL_ExMarginReductionGet_t;

/** Message ID for CMD_HlogDS_Get */
#define CMD_HLOGDS_GET 0x4A03

/**
   Requests information about the downstream HLOG information per subcarrier group
   (Section 7.5.1.26.6 of G997.1).
   During STEADY_STATE, the command can be used in VDSL to request near-end data only
   (CPE). For the far-end HLOG to be provided via the EOC channel
   CMD_TestParamsFE_Request must be used. In ADSL, the command can be applied for
   near-end as well as far-end parameters.
   During loop diagnostic mode, the command shall be used to request both near-end and
   far-end data.
*/
typedef struct CMD_HlogDS_Get CMD_HlogDS_Get_t;

/** Message ID for ACK_HlogDS_Get */
#define ACK_HLOGDS_GET 0x4A03

/**
   Returns information about the downstream HLOG per subcarrier group for the chosen
   range. (Section 7.5.1.26.6 of G997.1)
*/
typedef struct ACK_HlogDS_Get ACK_HlogDS_Get_t;

/** Message ID for CMD_HlogUS_Get */
#define CMD_HLOGUS_GET 0x4B03

/**
   Requests information about the upstream HLOG information per subcarrier group
   (Section 7.5.1.26.11 of G997.1).
   During STEADY_STATE, the command can be used in VDSL to request near-end data only
   (CO). For the far-end HLOG to be provided via the EOC channel
   CMD_TestParamsFE_Request must be used. In ADSL, the command can be applied for
   near-end as well as far-end parameters.
   During loop diagnostic mode, the command is used to request both near-end and
   far-end data.
*/
typedef struct CMD_HlogUS_Get CMD_HlogUS_Get_t;

/** Message ID for ACK_HlogUS_Get */
#define ACK_HLOGUS_GET 0x4B03

/**
   Returns information about the upstream HLOG per subcarrier group for the chosen
   range. (Section 7.5.1.26.11 of G997.1)
*/
typedef struct ACK_HlogUS_Get ACK_HlogUS_Get_t;

/** Message ID for CMD_HlinDS_Get */
#define CMD_HLINDS_GET 0x4803

/**
   Requests information about the downstream HLIN information per subcarrier group.
   (Section 7.5.1.26.3 of G997.1).
   The HLIN data are available during loop diagnostic mode only.
*/
typedef struct CMD_HlinDS_Get CMD_HlinDS_Get_t;

/** Message ID for ACK_HlinDS_Get */
#define ACK_HLINDS_GET 0x4803

/**
   Returns information about the downstream HLIN per subcarrier group for the chosen
   range. (Section 7.5.1.26.3 of G997.1)
*/
typedef struct ACK_HlinDS_Get ACK_HlinDS_Get_t;

/** Message ID for CMD_HlinUS_Get */
#define CMD_HLINUS_GET 0x4903

/**
   Requests information about the upstream HLIN information per subcarrier group.
   (Section 7.5.1.26.9 of G997.1).
   The HLIN data are available in loop diagnostic mode only.
*/
typedef struct CMD_HlinUS_Get CMD_HlinUS_Get_t;

/** Message ID for ACK_HlinUS_Get */
#define ACK_HLINUS_GET 0x4903

/**
   Returns information about the upstream HLIN per subcarrier group for the chosen
   range. (Section 7.5.1.26.9 of G997.1)
*/
typedef struct ACK_HlinUS_Get ACK_HlinUS_Get_t;

/** Message ID for CMD_QLN_DS_Get */
#define CMD_QLN_DS_GET 0x4C03

/**
   Requests information about the downstream QLN information (QLNpsds) per subcarrier
   group (Section 7.5.1.27.3 of G997.1).
   During STEADY_STATE, the command can be used in VDSL to request near-end data only
   (CPE). For the far-end QLN to be provided via the EOC channel
   CMD_TestParamsFE_Request must be used. In ADSL, the command can be applied for
   near-end as well as far-end parameters.
   During loop diagnostic mode, the command is used to request both near-end and
   far-end data.
*/
typedef struct CMD_QLN_DS_Get CMD_QLN_DS_Get_t;

/** Message ID for ACK_QLN_DS_Get */
#define ACK_QLN_DS_GET 0x4C03

/**
   Returns information about the QLN per subcarrier group for the chosen range.
   (Section 7.5.1.27.3 of G997.1)
*/
typedef struct ACK_QLN_DS_Get ACK_QLN_DS_Get_t;

/** Message ID for CMD_QLN_US_Get */
#define CMD_QLN_US_GET 0x4D03

/**
   Requests information about the upstream QLN information upstream (QLNpsus) per
   subcarrier group. (Section 7.5.1.27.6 of G997.1).
   During STEADY_STATE, the command can be used in VDSL to request near-end data only
   (CO). For the far-end QLN to be provided via the EOC channel
   CMD_TestParamsFE_Request must be used. In ADSL, the command can be applied for
   near-end as well as far-end parameters.
   During loop diagnostic mode, the command can be used to request both near-end and
   far-end data.
*/
typedef struct CMD_QLN_US_Get CMD_QLN_US_Get_t;

/** Message ID for ACK_QLN_US_Get */
#define ACK_QLN_US_GET 0x4D03

/**
   Returns information about the QLN per subcarrier group for the chosen range.
   (Section 7.5.1.27.6 of G997.1)
*/
typedef struct ACK_QLN_US_Get ACK_QLN_US_Get_t;

/** Message ID for CMD_SNR_DS_Get */
#define CMD_SNR_DS_GET 0x5503

/**
   Requests information about the downstream SNR per subcarrier group (Section
   7.5.1.28.3 of G997.1).
*/
typedef struct CMD_SNR_DS_Get CMD_SNR_DS_Get_t;

/** Message ID for ACK_SNR_DS_Get */
#define ACK_SNR_DS_GET 0x5503

/**
   Returns information about the SNR per subcarrier group for the chosen range.
   (Section 7.5.1.28.3 of G997.1)
*/
typedef struct ACK_SNR_DS_Get ACK_SNR_DS_Get_t;

/** Message ID for CMD_SNR_US_Get */
#define CMD_SNR_US_GET 0x4E03

/**
   Requests information about the upstream SNR per subcarrier group (Section 7.5.1.28.6
   of G997.1).
   During Showtime the message is used to retrieve the SNRpsus at the ADSL-CPE. During
   loop diagnostic mode it is applied at the VDSL-CO & CPE and the ADSL-CPE.
*/
typedef struct CMD_SNR_US_Get CMD_SNR_US_Get_t;

/** Message ID for ACK_SNR_US_Get */
#define ACK_SNR_US_GET 0x4E03

/**
   Returns information about the upstream SNR per subcarrier group for the chosen
   range. (Section 7.5.1.28.6 of G997.1)
*/
typedef struct ACK_SNR_US_Get ACK_SNR_US_Get_t;

/** Message ID for CMD_TestParamsAuxDS_Get */
#define CMD_TESTPARAMSAUXDS_GET 0x4F03

/**
   Requests test parameter related information for the downstream direction: The HLIN
   scaling factor (HLINSCds), the subcarrier group size "G" and the measurement times
   for HLOGpsds, QLNpsds, SNRpsds.
   (Sections 7.5.1.26.1/2/4/5, 7.5.1.27.1/2 and 7.5.1.28.1/2 of G997.1)
   During loop diagnostic mode (VDSL, ADSL) and in ADSL also during STEADY_STATE, the
   command is used to request both near-end and far-end data.
   In VDSL during STEADY_STATE, the command can be used to retrieve all near-end data
   (VTU-R) but far-end (applied at VTU-O) only to retrieve the "group size" parameters.
   To get the measurement time parameters (via the EOC channel) the message
   CMD_TestParamsFE_Request must be applied instead.
*/
typedef struct CMD_TestParamsAuxDS_Get CMD_TestParamsAuxDS_Get_t;

/** Message ID for ACK_TestParamsAuxDS_Get */
#define ACK_TESTPARAMSAUXDS_GET 0x4F03

/**
   Provides the test-parameter related information as requested by
   CMD_TestParamsAuxDS_Get: The HLIN scaling factor (HLINSCds), the subcarrier group
   size "G" and the measurement times for HLOGpsds, QLNpsds, SNRpsds.
   (Sections 7.5.1.26.1/2/4/5, 7.5.1.27.1/2 and 7.5.1.28.1/2 of G997.1)
*/
typedef struct ACK_TestParamsAuxDS_Get ACK_TestParamsAuxDS_Get_t;

/** Message ID for CMD_TestParamsAuxUS_Get */
#define CMD_TESTPARAMSAUXUS_GET 0x5003

/**
   Requests test parameter related information for the upstream direction: The HLIN
   scaling factor (HLINSCus), the subcarrier group size "G" and the measurement times
   for HLOGpsus, QLNpsus, SNRpsus.
   (Sections 7.5.1.26.7/8/10/11, 7.5.1.27.4/5 and 7.5.1.28.4/5 of G997.1)
   During loop diagnostic mode (VDSL, ADSL) and in ADSL also during STEADY_STATE, the
   command is used to request both near-end and far-end data.
   In VDSL during STEADY_STATE, the command can be used to retrieve all near-end data
   (VTU-O) but far-end (applied at VTU-R) only to retrieve the "group size" parameters.
   To get the measurement time parameters (via the EOC channel) the message
   CMD_TestParamsFE_Request must be applied instead.
*/
typedef struct CMD_TestParamsAuxUS_Get CMD_TestParamsAuxUS_Get_t;

/** Message ID for ACK_TestParamsAuxUS_Get */
#define ACK_TESTPARAMSAUXUS_GET 0x5003

/**
   Provides the test-parameter related information as requested by
   CMD_TestParamsAuxUS_Get: The HLIN scaling factor (HLINSCus), the subcarrier group
   size "G" and the measurement times for HLOGpsus, QLNpsus, SNRpsus.
*/
typedef struct ACK_TestParamsAuxUS_Get ACK_TestParamsAuxUS_Get_t;

/** Message ID for CMD_TestParamsFE_Request */
#define CMD_TESTPARAMSFE_REQUEST 0x0849

/**
   This message is used to trigger retrieval of the far-end PMD Test Parameters Hlog,
   SNR and QLN via the EOC channel during Showtime. If StartIndex or EndIndex do not
   contain values in a valid range then no autonomous message will be sent by the
   firmware. Once the retrieval process is started, it can also be aborted with this
   message via the control parameter. The status of the parameter retrieval process can
   be polled via the CMD_TestParamsFE_Poll message. Once the parameters are retrieved,
   they are provided with the EVT_PMD_TestParamsGet message.
*/
typedef struct CMD_TestParamsFE_Request CMD_TestParamsFE_Request_t;

/** Message ID for ACK_TestParamsFE_Request */
#define ACK_TESTPARAMSFE_REQUEST 0x0849

/**
   This is the acknowledgement for CMD_TestParamsFE_Request.
*/
typedef struct ACK_TestParamsFE_Request ACK_TestParamsFE_Request_t;

/** Message ID for CMD_TestParamsFE_Poll */
#define CMD_TESTPARAMSFE_POLL 0x0809

/**
   This message polls the status of the far end parameter retrieval process.
*/
typedef struct CMD_TestParamsFE_Poll CMD_TestParamsFE_Poll_t;

/** Message ID for ACK_TestParamsFE_Poll */
#define ACK_TESTPARAMSFE_POLL 0x0809

/**
   This is the acknowledgement for CMD_TestParamsFE_Poll.
*/
typedef struct ACK_TestParamsFE_Poll ACK_TestParamsFE_Poll_t;

/** Message ID for EVT_PMD_TestParamsGet */
#define EVT_PMD_TESTPARAMSGET 0x5803

/**
   This event message provides the far-end data after the far end data retrieval
   process. This message is a result of the CMD_TestParamsFE_Request message.
*/
typedef struct EVT_PMD_TestParamsGet EVT_PMD_TestParamsGet_t;

/** Message ID for CMD_ClearEOC_Configure */
#define CMD_CLEAREOC_CONFIGURE 0x0A49

/**
   The message is used to configure the autonomous messaging related to Clear EOC
   transmission.
*/
typedef struct CMD_ClearEOC_Configure CMD_ClearEOC_Configure_t;

/** Message ID for ACK_ClearEOC_Configure */
#define ACK_CLEAREOC_CONFIGURE 0x0A49

/**
   This is the acknowledgement for CMD_ClearEOC_Configure.
*/
typedef struct ACK_ClearEOC_Configure ACK_ClearEOC_Configure_t;

/** Message ID for CMD_ClearEOC_TxTrigger */
#define CMD_CLEAREOC_TXTRIGGER 0x0949

/**
   The message is used to trigger the transmission of  Clear EOC messages that were
   placed into the Clear EOC transmit buffer before with CMD_ClearEOC_Write.
*/
typedef struct CMD_ClearEOC_TxTrigger CMD_ClearEOC_TxTrigger_t;

/** Message ID for ACK_ClearEOC_TxTrigger */
#define ACK_CLEAREOC_TXTRIGGER 0x0949

/**
   This is the acknowledgement for CMD_ClearEOC_TxTrigger.
*/
typedef struct ACK_ClearEOC_TxTrigger ACK_ClearEOC_TxTrigger_t;

/** Message ID for CMD_ClearEOC_Write */
#define CMD_CLEAREOC_WRITE 0x5143

/**
   This message is used to write data to the ClearEOC write buffer of type
   VNX_ClearEOC_t. When the buffer is filled, the transmission is started applying
   CMD_ClearEOC_TxTrigger. If the message to transmit is longer than the mailbox size,
   a sequence of writes to the ClearEOC buffer has to be done before the transmission
   is started with CMD_ClearEOC_TxTrigger. When autonomous Tx status messaging is
   activated via CMD_ClearEOC_Configure, then the finished transmission is indicated by
   EVT_ClearEOCStatusGet.
*/
typedef struct CMD_ClearEOC_Write CMD_ClearEOC_Write_t;

/** Message ID for ACK_ClearEOC_Write */
#define ACK_CLEAREOC_WRITE 0x5143

/**
   This message is the acknowledgement for CMD_ClearEOC_Write.
*/
typedef struct ACK_ClearEOC_Write ACK_ClearEOC_Write_t;

/** Message ID for CMD_ClearEOC_Read */
#define CMD_CLEAREOC_READ 0x5203

/**
   This message is used to read data from the ClearEOC buffer of type VNX_ClearEOC_t.
   The length of the actual Clear EOC message can be found in the buffer. Please refer
   to VNX_ClearEOC_t. The availability of data can either be checked via
   CMD_ClearEOCStatusGet in polling mode or it can be reported by an autonomous
   EVT_ClearEOCStatusGet message when data is received (to be enabled using
   CMD_ClearEOC_Configure).
*/
typedef struct CMD_ClearEOC_Read CMD_ClearEOC_Read_t;

/** Message ID for ACK_ClearEOC_Read */
#define ACK_CLEAREOC_READ 0x5203

/**
   This message is the acknowledgement to CMD_ClearEOC_Read.
*/
typedef struct ACK_ClearEOC_Read ACK_ClearEOC_Read_t;

/** Message ID for EVT_ClearEOC_Read */
#define EVT_CLEAREOC_READ 0x5203

/**
   This message is an autonomous message that is generated when ClearEOC data was
   received and autonomous Clear EOC data messaging has been activated via
   CMD_ClearEOC_Configure. If the ClearEOC data does not fit in one message, then a
   sequence of messages is generated. The ClearEOC buffer is of type VNX_ClearEOC_t.
*/
typedef struct EVT_ClearEOC_Read EVT_ClearEOC_Read_t;

/** Message ID for CMD_ClearEOCStatusGet */
#define CMD_CLEAREOCSTATUSGET 0x0B09

/**
   This message is used to retrieve the status of the clear eoc data transmission.
*/
typedef struct CMD_ClearEOCStatusGet CMD_ClearEOCStatusGet_t;

/** Message ID for ACK_ClearEOCStatusGet */
#define ACK_CLEAREOCSTATUSGET 0x0B09

/**
   This is the acknowledgement for CMD_ClearEOCStatusGet.
*/
typedef struct ACK_ClearEOCStatusGet ACK_ClearEOCStatusGet_t;

/** Message ID for EVT_ClearEOCStatusGet */
#define EVT_CLEAREOCSTATUSGET 0x0B09

/**
   This autonomous message reports the Clear EOC status. It is sent only if the
   "Autonomous Status Message Control" was enabled for Tx and/or Rx direction with
   CMD_ClearEOC_Configure. If Tx direction is enabled, the message is generated when a
   Tx transmission is finished or failed. If Rx direction is enabled, the message is
   generated when the Rx status transitions from "Idle" to "Data Available" for
   retrieval by the host.
*/
typedef struct EVT_ClearEOCStatusGet EVT_ClearEOCStatusGet_t;

/** Message ID for CMD_ClearEOCStatusSet */
#define CMD_CLEAREOCSTATUSSET 0x0B49

/**
   The message is used to reset the transmit or receive status of the clear eoc data
   transmission to IDLE (for defined states see also CMD_ClearEOCStatusGet). See the
   description on the Clear EOC handling on Page746 for when it has to be applied.
   Transmit and receive status are distinguished by the Index parameter.
*/
typedef struct CMD_ClearEOCStatusSet CMD_ClearEOCStatusSet_t;

/** Message ID for ACK_ClearEOCStatusSet */
#define ACK_CLEAREOCSTATUSSET 0x0B49

/**
   This is the acknowledgement for CMD_ClearEOCStatusSet.
*/
typedef struct ACK_ClearEOCStatusSet ACK_ClearEOCStatusSet_t;

/** Message ID for CMD_OH_OptionsSet */
#define CMD_OH_OPTIONSSET 0x1945

/**
   Configuration of options for the overhead handling.
*/
typedef struct CMD_OH_OptionsSet CMD_OH_OptionsSet_t;

/** Message ID for ACK_OH_OptionsSet */
#define ACK_OH_OPTIONSSET 0x1945

/**
   Acknowledgement for CMD_OH_OptionsSet.
*/
typedef struct ACK_OH_OptionsSet ACK_OH_OptionsSet_t;

/** Message ID for CMD_OH_StatsGet */
#define CMD_OH_STATSGET 0x0F03

/**
   Requests OH polling statistic information.
*/
typedef struct CMD_OH_StatsGet CMD_OH_StatsGet_t;

/** Message ID for ACK_OH_StatsGet */
#define ACK_OH_STATSGET 0x0F03

/**
   Reports the OH polling statistics as requested by CMD_OH_StatsGet.
*/
typedef struct ACK_OH_StatsGet ACK_OH_StatsGet_t;

/** Message ID for CMD_OLR_Control */
#define CMD_OLR_CONTROL 0x0F45

/**
   Enables/Disables support for certain OLR events (SRA, SOS).
   An OLR transition is always initiated by the receiving PMD, so the CPE requests the
   OLR event for downstream and the CO for upstream direction.
   ATU_R: A control bit exists for downstream only, for upstream the CPE services all
   US SRA requests from the CO if possible (no framing constraints).
*/
typedef struct CMD_OLR_Control CMD_OLR_Control_t;

/** Message ID for ACK_OLR_Control */
#define ACK_OLR_CONTROL 0x0F45

/**
   Acknowledgement for CMD_OLR_Control.
*/
typedef struct ACK_OLR_Control ACK_OLR_Control_t;

/** Message ID for CMD_SRA_DS_Configure */
#define CMD_SRA_DS_CONFIGURE 0x4548

/**
   Configures the downstream SRA behaviour.
*/
typedef struct CMD_SRA_DS_Configure CMD_SRA_DS_Configure_t;

/** Message ID for ACK_SRA_DS_Configure */
#define ACK_SRA_DS_CONFIGURE 0x4548

/**
   Acknowledgement for CMD_SRA_DS_Configure.
*/
typedef struct ACK_SRA_DS_Configure ACK_SRA_DS_Configure_t;

/** Message ID for CMD_SRA_US_Configure */
#define CMD_SRA_US_CONFIGURE 0x4648

/**
   Configures the upstream SRA behaviour.
*/
typedef struct CMD_SRA_US_Configure CMD_SRA_US_Configure_t;

/** Message ID for ACK_SRA_US_Configure */
#define ACK_SRA_US_CONFIGURE 0x4648

/**
   Acknowledgement for CMD_SRA_US_Configure.
*/
typedef struct ACK_SRA_US_Configure ACK_SRA_US_Configure_t;

/** Message ID for CMD_SOS_DS_Configure */
#define CMD_SOS_DS_CONFIGURE 0x4748

/**
   The messages configures the downstream SOS triggering parameters. They are
   configured at the VTU-O and transferred to the VTU-R during initialization with
   O-MSG1.
*/
typedef struct CMD_SOS_DS_Configure CMD_SOS_DS_Configure_t;

/** Message ID for ACK_SOS_DS_Configure */
#define ACK_SOS_DS_CONFIGURE 0x4748

/**
   Acknowledgement for CMD_SOS_DS_Configure.
*/
typedef struct ACK_SOS_DS_Configure ACK_SOS_DS_Configure_t;

/** Message ID for CMD_SOS_US_Configure */
#define CMD_SOS_US_CONFIGURE 0x4848

/**
   The messages configures the upstream SOS triggering parameters.
*/
typedef struct CMD_SOS_US_Configure CMD_SOS_US_Configure_t;

/** Message ID for ACK_SOS_US_Configure */
#define ACK_SOS_US_CONFIGURE 0x4848

/**
   Acknowledgement for CMD_SOS_US_Configure.
*/
typedef struct ACK_SOS_US_Configure ACK_SOS_US_Configure_t;

/** Message ID for CMD_SOS_RateBC0_DS_Set */
#define CMD_SOS_RATEBC0_DS_SET 0x4948

/**
   The messages configures the downstream SOS data rate for bearer channel 0. (Section
   7.3.2.1.6 of G.997.1)
*/
typedef struct CMD_SOS_RateBC0_DS_Set CMD_SOS_RateBC0_DS_Set_t;

/** Message ID for ACK_SOS_RateBC0_DS_Set */
#define ACK_SOS_RATEBC0_DS_SET 0x4948

/**
   Acknowledgement for CMD_SOS_RateBC0_DS_Set.
*/
typedef struct ACK_SOS_RateBC0_DS_Set ACK_SOS_RateBC0_DS_Set_t;

/** Message ID for CMD_SOS_RateBC0_US_Set */
#define CMD_SOS_RATEBC0_US_SET 0x4B48

/**
   The messages configures the upstream SOS data rate for bearer channel 0. (Section
   7.3.2.1.7 of G.997.1)
*/
typedef struct CMD_SOS_RateBC0_US_Set CMD_SOS_RateBC0_US_Set_t;

/** Message ID for ACK_SOS_RateBC0_US_Set */
#define ACK_SOS_RATEBC0_US_SET 0x4B48

/**
   Acknowledgement for CMD_SOS_RateBC0_US_Set.
*/
typedef struct ACK_SOS_RateBC0_US_Set ACK_SOS_RateBC0_US_Set_t;

/** Message ID for CMD_OLR_US_StatsGet */
#define CMD_OLR_US_STATSGET 0x5F03

/**
   Requests the OLR status information on bit swaps, DRR, SRA and SOS events for the
   upstream direction.
*/
typedef struct CMD_OLR_US_StatsGet CMD_OLR_US_StatsGet_t;

/** Message ID for ACK_OLR_US_StatsGet */
#define ACK_OLR_US_STATSGET 0x5F03

/**
   Reports the OLR status information for the upstream direction as requested by
   CMD_OLR_US_StatsGet.
*/
typedef struct ACK_OLR_US_StatsGet ACK_OLR_US_StatsGet_t;

/** Message ID for CMD_OLR_DS_StatsGet */
#define CMD_OLR_DS_STATSGET 0x6003

/**
   Requests the OLR status information on bit swaps, DRR, SRA and SOS events for the
   downstream direction.
*/
typedef struct CMD_OLR_DS_StatsGet CMD_OLR_DS_StatsGet_t;

/** Message ID for ACK_OLR_DS_StatsGet */
#define ACK_OLR_DS_STATSGET 0x6003

/**
   Reports the OLR status information for the downstream direction as requested by
   CMD_OLR_DS_StatsGet.
*/
typedef struct ACK_OLR_DS_StatsGet ACK_OLR_DS_StatsGet_t;

/** Message ID for CMD_RA_ModeDS_Get */
#define CMD_RA_MODEDS_GET 0xD903

/**
   Requests the actual active downstream RA mode (ACT-RA-MODEds, Section 7.5.1.33.1 of
   G.997.1).
*/
typedef struct CMD_RA_ModeDS_Get CMD_RA_ModeDS_Get_t;

/** Message ID for ACK_RA_ModeDS_Get */
#define ACK_RA_MODEDS_GET 0xD903

/**
   Reports the actual active downstream RA mode (ACT-RA-MODEds) as requested by
   CMD_RA_ModeDS_Get.
*/
typedef struct ACK_RA_ModeDS_Get ACK_RA_ModeDS_Get_t;

/** Message ID for CMD_RA_ModeUS_Get */
#define CMD_RA_MODEUS_GET 0xDB03

/**
   Requests the actual active upstream RA mode (ACT-RA-MODEus, Section 7.5.1.33.2 of
   G.997.1).

*/
typedef struct CMD_RA_ModeUS_Get CMD_RA_ModeUS_Get_t;

/** Message ID for ACK_RA_ModeUS_Get */
#define ACK_RA_MODEUS_GET 0xDB03

/**
   Reports the actual active upstream RA mode (ACT-RA-MODEus) as requested by
   CMD_RA_ModeUS_Get.
*/
typedef struct ACK_RA_ModeUS_Get ACK_RA_ModeUS_Get_t;

/** Message ID for EVT_OLR_US_EventGet */
#define EVT_OLR_US_EVENTGET 0x0307

/**
   Autonomous message indicating a successful upstream OLR event (SRA or SOS).

*/
typedef struct EVT_OLR_US_EventGet EVT_OLR_US_EventGet_t;

/** Message ID for EVT_OLR_DS_EventGet */
#define EVT_OLR_DS_EVENTGET 0x0407

/**
   Autonomous message indicating a successful downstream OLR event (SRA or SOS).
*/
typedef struct EVT_OLR_DS_EventGet EVT_OLR_DS_EventGet_t;

/** Message ID for CMD_OLR_US_EventConfigure */
#define CMD_OLR_US_EVENTCONFIGURE 0x0F49

/**
   Enables/Disables the generation of EVENT messages (EVT) for specific upstream OLR
   events. If the corresponding Enable bit for an OLR event is set, then the modem
   firmware will send an autonomous message EVT_OLR_US_EventGet if the OLR event
   happened in the last 1-second interval.
*/
typedef struct CMD_OLR_US_EventConfigure CMD_OLR_US_EventConfigure_t;

/** Message ID for ACK_OLR_US_EventConfigure */
#define ACK_OLR_US_EVENTCONFIGURE 0x0F49

/**
   Acknoledgement for CMD_OLR_US_EventConfigure.
*/
typedef struct ACK_OLR_US_EventConfigure ACK_OLR_US_EventConfigure_t;

/** Message ID for CMD_OLR_DS_EventConfigure */
#define CMD_OLR_DS_EVENTCONFIGURE 0x1049

/**
   Enables/Disables the generation of EVENT messages (EVT) for specific downstream OLR
   events. If the corresponding Enable bit for an OLR event is set, then the modem
   firmware will send an autonomous message EVT_OLR_DS_EventGet if the OLR event
   happened in the last 1-second interval.
*/
typedef struct CMD_OLR_DS_EventConfigure CMD_OLR_DS_EventConfigure_t;

/** Message ID for ACK_OLR_DS_EventConfigure */
#define ACK_OLR_DS_EVENTCONFIGURE 0x1049

/**
   Acknoledgement for CMD_OLR_DS_EventConfigure.
*/
typedef struct ACK_OLR_DS_EventConfigure ACK_OLR_DS_EventConfigure_t;

/** Message ID for CMD_CRC_ErrorRequest */
#define CMD_CRC_ERRORREQUEST 0x0C49

/**
   Triggers the insertion of corrupt CRCÕs into the transmit path at the VTU-R or
   VTU-C. The message controls the EOC "Diagnostic" command to start and stop the
   corrupt CRC transmission. (Section 11.2.3.2 of G993.2 [5]). The EOC "Diagnostic"
   command is sent by the CO only for triggering corrupt CRCÕs.
*/
typedef struct CMD_CRC_ErrorRequest CMD_CRC_ErrorRequest_t;

/** Message ID for ACK_CRC_ErrorRequest */
#define ACK_CRC_ERRORREQUEST 0x0C49

/**
   This is the acknowledgement for CMD_CRC_ErrorRequest.
*/
typedef struct ACK_CRC_ErrorRequest ACK_CRC_ErrorRequest_t;

/** Message ID for CMD_CRC_ErrorStatusGet */
#define CMD_CRC_ERRORSTATUSGET 0x0D09

/**
   Requests the status of corrupt CRC insertion, initiated by CMD_CRC_ErrorRequest.
*/
typedef struct CMD_CRC_ErrorStatusGet CMD_CRC_ErrorStatusGet_t;

/** Message ID for ACK_CRC_ErrorStatusGet */
#define ACK_CRC_ERRORSTATUSGET 0x0D09

/**
   Provides the status of corrupt CRC insertion. Acknowledgement for
   CMD_CRC_ErrorStatusGet.
*/
typedef struct ACK_CRC_ErrorStatusGet ACK_CRC_ErrorStatusGet_t;

/** Message ID for CMD_FwTimeStampGet */
#define CMD_FWTIMESTAMPGET 0x3703

/**
   The message request the compile time of the loaded FW binary.
*/
typedef struct CMD_FwTimeStampGet CMD_FwTimeStampGet_t;

/** Message ID for ACK_FwTimeStampGet */
#define ACK_FWTIMESTAMPGET 0x3703

/**
   Provides the compile time stamp as requested with CMD_FwTimeStampGet.
*/
typedef struct ACK_FwTimeStampGet ACK_FwTimeStampGet_t;

/** Message ID for CMD_DebugTrailControl */
#define CMD_DEBUGTRAILCONTROL 0x5643

/**
   Without affecting normal operation, certain types of data may be logged to a
   dedicated data buffer to be read out by the management system. This message is used
   to specify the type of data to be logged and the point in time at which to stop
   logging.
*/
typedef struct CMD_DebugTrailControl CMD_DebugTrailControl_t;

/** Message ID for ACK_DebugTrailControl */
#define ACK_DEBUGTRAILCONTROL 0x5643

/**
   This is the acknowledgement for CMD_DebugTrailControl.
*/
typedef struct ACK_DebugTrailControl ACK_DebugTrailControl_t;

/** Message ID for CMD_RingbufferDataGet */
#define CMD_RINGBUFFERDATAGET 0x0703

/**
   This message is used to retrieve debug trace data with the debug trace system. The
   debug trace system needs to be actived with CMD_DebugTrailControl, before this
   message can be used.
*/
typedef struct CMD_RingbufferDataGet CMD_RingbufferDataGet_t;

/** Message ID for ACK_RingbufferDataGet */
#define ACK_RINGBUFFERDATAGET 0x0703

/**
   This is the acknowledgement for CMD_RingbufferDataGet.
*/
typedef struct ACK_RingbufferDataGet ACK_RingbufferDataGet_t;

/** Message ID for CMD_RingbufferStatusGet */
#define CMD_RINGBUFFERSTATUSGET 0x5703

/**
   This message is used to retrieve the status of the debug trace system. The debug
   trace system needs to be actived with CMD_DebugTrailControl, before this message can
   be used.
*/
typedef struct CMD_RingbufferStatusGet CMD_RingbufferStatusGet_t;

/** Message ID for ACK_RingbufferStatusGet */
#define ACK_RINGBUFFERSTATUSGET 0x5703

/**
   Provides the Debug Trail Status requested by CMD_RingbufferStatusGet.
   The Debug Trail Index, Buffer Size, and Wrap Count are used to determine the
   location of valid data within the Debug Buffer to retrieve them with
   CMD_RingbufferDataGet.
   Note: See example below.
*/
typedef struct ACK_RingbufferStatusGet ACK_RingbufferStatusGet_t;

/** Message ID for CMD_SELT_Configure */
#define CMD_SELT_CONFIGURE 0x1048

/**
   Configures the parameters for single-ended line testing (SELT).
*/
typedef struct CMD_SELT_Configure CMD_SELT_Configure_t;

/** Message ID for ACK_SELT_Configure */
#define ACK_SELT_CONFIGURE 0x1048

/**
   Acknowledgement for CMD_SELT_Configure.
*/
typedef struct ACK_SELT_Configure ACK_SELT_Configure_t;

/** Message ID for CMD_SELT_QLN_Get */
#define CMD_SELT_QLN_GET 0x0020

/**
   The message requests the results of the quiet-line noise (QLN) measurement which is
   part of the SELT test, if enabled with CMD_SELT_Configure.
*/
typedef struct CMD_SELT_QLN_Get CMD_SELT_QLN_Get_t;

/** Message ID for ACK_SELT_QLN_Get */
#define ACK_SELT_QLN_GET 0x0020

/**
   Returns information about the QLN per subcarrier resulting from the SELT test.
*/
typedef struct ACK_SELT_QLN_Get ACK_SELT_QLN_Get_t;

/** Message ID for CMD_SELT_UER_Get */
#define CMD_SELT_UER_GET 0x0120

/**
   The message requests the results of the Uncalibrated Echo Response (UER) measurement
   which is part of the SELT test, if enabled with CMD_SELT_Configure.
*/
typedef struct CMD_SELT_UER_Get CMD_SELT_UER_Get_t;

/** Message ID for ACK_SELT_UER_Get */
#define ACK_SELT_UER_GET 0x0120

/**
   Returns information about the UER per subcarrier resulting from the SELT test.
*/
typedef struct ACK_SELT_UER_Get ACK_SELT_UER_Get_t;

/**
   Requests information about the bit-allocation per subcarrier in VDSL mode. The
   values for all subcarriers of both directions can be retrieved.
   (For ADSL use CMD_ADSL_BAT_DS_Get and CMD_ADSL_BAT_US_Get).
*/
struct CMD_BAT_TableEntriesGet
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
   Returns information about the bit-allocation per tone for the chosen range of
   subcarriers.(Section 7.5.1.29.1-2 of G997.1)
*/
struct ACK_BAT_TableEntriesGet
{
#if MEI_DRV_OS_BYTE_ORDER == MEI_DRV_OS_BIG_ENDIAN
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Bit Allocation */
   VNX_BAT_TableEntry_t BAT[128];
#else
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Bit Allocation */
   VNX_BAT_TableEntry_t BAT[128];
#endif
} __PACKED__ ;


/**
   Requests information about the Gains per subcarrier. The values for all subcarriers
   of both directions can be retrieved.
   (For ADSL use CMD_ADSL_GainTableDS_Get and CMD_ADSL_GainTableUS_Get).
*/
struct CMD_GainTableEntriesGet
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
   Returns information about the Gain-per-tone for the chosen range of
   subcarriers.(Section 7.5.1.29.3-4 of G997.1)
*/
struct ACK_GainTableEntriesGet
{
#if MEI_DRV_OS_BYTE_ORDER == MEI_DRV_OS_BIG_ENDIAN
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Gains */
   IFX_uint16_t Gains[128];
#else
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Gains */
   IFX_uint16_t Gains[128];
#endif
} __PACKED__ ;


/**
   The message requests information about the SNR per subcarrier available at the
   near-end side , which means for upstream direction at the CO side and for downstream
   direction at the CPE. It is the hosts responsibility to select the tone indices
   accordingly.
*/
struct CMD_SNR_NE_TableEntriesGet
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
   Returns information about the SNR per subcarrier available at the near-end side,
   which means for upstream direction at the CO side and for downstream direction at
   the CPE.
*/
struct ACK_SNR_NE_TableEntriesGet
{
#if MEI_DRV_OS_BYTE_ORDER == MEI_DRV_OS_BIG_ENDIAN
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** SNR */
   IFX_uint16_t SNRps[128];
#else
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** SNR */
   IFX_uint16_t SNRps[128];
#endif
} __PACKED__ ;


/**
   Requests information about the downstream bit-allocation per subcarrier in ADSL
   mode.
*/
struct CMD_ADSL_BAT_DS_Get
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
   Returns information about the downstream bit-allocation per tone for the chosen
   range of subcarriers.(Section 7.5.1.29.1 of G997.1)
*/
struct ACK_ADSL_BAT_DS_Get
{
#if MEI_DRV_OS_BYTE_ORDER == MEI_DRV_OS_BIG_ENDIAN
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Bit Allocation */
   VNX_BAT_TableEntry_t BAT[128];
#else
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Bit Allocation */
   VNX_BAT_TableEntry_t BAT[128];
#endif
} __PACKED__ ;


/**
   Requests information about the upstream bit-allocation per subcarrier in ADSL mode.
*/
struct CMD_ADSL_BAT_US_Get
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
   Returns information about the upstream bit-allocation per tone for the chosen range
   of subcarriers.(Section 7.5.1.29.2 of G997.1)
*/
struct ACK_ADSL_BAT_US_Get
{
#if MEI_DRV_OS_BYTE_ORDER == MEI_DRV_OS_BIG_ENDIAN
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Bit Allocation */
   VNX_BAT_TableEntry_t BAT[32];
#else
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Bit Allocation */
   VNX_BAT_TableEntry_t BAT[32];
#endif
} __PACKED__ ;


/**
   Requests information about the Gains per subcarrier for the downstream direction.
*/
struct CMD_ADSL_GainTableDS_Get
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
   Returns information about the Gain-per-tone for the chosen range of subcarriers for
   the downstream direction.(Section 7.5.1.29.3 of G997.1) as requested by
   CMD_ADSL_GainTableDS_Get.
*/
struct ACK_ADSL_GainTableDS_Get
{
#if MEI_DRV_OS_BYTE_ORDER == MEI_DRV_OS_BIG_ENDIAN
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Gains */
   IFX_uint16_t Gains[128];
#else
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Gains */
   IFX_uint16_t Gains[128];
#endif
} __PACKED__ ;


/**
   Requests information about the Gains per subcarrier for the upstream direction.
*/
struct CMD_ADSL_GainTableUS_Get
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
   Returns information about the Gain-per-tone for the chosen range of subcarriers for
   the upstream direction.(Section 7.5.1.29.4 of G997.1)
*/
struct ACK_ADSL_GainTableUS_Get
{
#if MEI_DRV_OS_BYTE_ORDER == MEI_DRV_OS_BIG_ENDIAN
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Gains */
   IFX_uint16_t Gains[64];
#else
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Gains */
   IFX_uint16_t Gains[64];
#endif
} __PACKED__ ;


/**
   Requests information about the Excess Margin Reduction needed for the fine gain
   calculation at the ATU_R.(See also ACK_ADSL_GainTableDS_Get).
*/
struct CMD_ADSL_ExMarginReductionGet
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
   Returns information about the Excess Margin Reduction for the downstream direction.
*/
struct ACK_ADSL_ExMarginReductionGet
{
#if MEI_DRV_OS_BYTE_ORDER == MEI_DRV_OS_BIG_ENDIAN
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Excess Margin Reduction */
   IFX_uint16_t eSnrmReduction;
#else
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Excess Margin Reduction */
   IFX_uint16_t eSnrmReduction;
#endif
} __PACKED__ ;


/**
   Requests information about the downstream HLOG information per subcarrier group
   (Section 7.5.1.26.6 of G997.1).
   During STEADY_STATE, the command can be used in VDSL to request near-end data only
   (CPE). For the far-end HLOG to be provided via the EOC channel
   CMD_TestParamsFE_Request must be used. In ADSL, the command can be applied for
   near-end as well as far-end parameters.
   During loop diagnostic mode, the command shall be used to request both near-end and
   far-end data.
*/
struct CMD_HlogDS_Get
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
   Returns information about the downstream HLOG per subcarrier group for the chosen
   range. (Section 7.5.1.26.6 of G997.1)
*/
struct ACK_HlogDS_Get
{
#if MEI_DRV_OS_BYTE_ORDER == MEI_DRV_OS_BIG_ENDIAN
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** HLOG per SG: HLOGpsds */
   IFX_uint16_t HLOGpsds[128];
#else
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** HLOG per SG: HLOGpsds */
   IFX_uint16_t HLOGpsds[128];
#endif
} __PACKED__ ;


/**
   Requests information about the upstream HLOG information per subcarrier group
   (Section 7.5.1.26.11 of G997.1).
   During STEADY_STATE, the command can be used in VDSL to request near-end data only
   (CO). For the far-end HLOG to be provided via the EOC channel
   CMD_TestParamsFE_Request must be used. In ADSL, the command can be applied for
   near-end as well as far-end parameters.
   During loop diagnostic mode, the command is used to request both near-end and
   far-end data.
*/
struct CMD_HlogUS_Get
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
   Returns information about the upstream HLOG per subcarrier group for the chosen
   range. (Section 7.5.1.26.11 of G997.1)
*/
struct ACK_HlogUS_Get
{
#if MEI_DRV_OS_BYTE_ORDER == MEI_DRV_OS_BIG_ENDIAN
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** HLOG per SG: HLOGpsds */
   IFX_uint16_t HLOGpsds[128];
#else
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** HLOG per SG: HLOGpsds */
   IFX_uint16_t HLOGpsds[128];
#endif
} __PACKED__ ;


/**
   Requests information about the downstream HLIN information per subcarrier group.
   (Section 7.5.1.26.3 of G997.1).
   The HLIN data are available during loop diagnostic mode only.
*/
struct CMD_HlinDS_Get
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
   Returns information about the downstream HLIN per subcarrier group for the chosen
   range. (Section 7.5.1.26.3 of G997.1)
*/
struct ACK_HlinDS_Get
{
#if MEI_DRV_OS_BYTE_ORDER == MEI_DRV_OS_BIG_ENDIAN
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** HLIN per SG: HLINpsds */
   VNX_HLIN_t HLINpsds[64];
#else
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** HLIN per SG: HLINpsds */
   VNX_HLIN_t HLINpsds[64];
#endif
} __PACKED__ ;


/**
   Requests information about the upstream HLIN information per subcarrier group.
   (Section 7.5.1.26.9 of G997.1).
   The HLIN data are available in loop diagnostic mode only.
*/
struct CMD_HlinUS_Get
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
   Returns information about the upstream HLIN per subcarrier group for the chosen
   range. (Section 7.5.1.26.9 of G997.1)
*/
struct ACK_HlinUS_Get
{
#if MEI_DRV_OS_BYTE_ORDER == MEI_DRV_OS_BIG_ENDIAN
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** HLIN per SG: HLINpsus */
   VNX_HLIN_t HLINpsus[64];
#else
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** HLIN per SG: HLINpsus */
   VNX_HLIN_t HLINpsus[64];
#endif
} __PACKED__ ;


/**
   Requests information about the downstream QLN information (QLNpsds) per subcarrier
   group (Section 7.5.1.27.3 of G997.1).
   During STEADY_STATE, the command can be used in VDSL to request near-end data only
   (CPE). For the far-end QLN to be provided via the EOC channel
   CMD_TestParamsFE_Request must be used. In ADSL, the command can be applied for
   near-end as well as far-end parameters.
   During loop diagnostic mode, the command is used to request both near-end and
   far-end data.
*/
struct CMD_QLN_DS_Get
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
   Returns information about the QLN per subcarrier group for the chosen range.
   (Section 7.5.1.27.3 of G997.1)
*/
struct ACK_QLN_DS_Get
{
#if MEI_DRV_OS_BYTE_ORDER == MEI_DRV_OS_BIG_ENDIAN
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** QLN per SG: QLNpsds */
   VNX_QLN_NE_t QLNds[128];
#else
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** QLN per SG: QLNpsds */
   VNX_QLN_NE_t QLNds[128];
#endif
} __PACKED__ ;


/**
   Requests information about the upstream QLN information upstream (QLNpsus) per
   subcarrier group. (Section 7.5.1.27.6 of G997.1).
   During STEADY_STATE, the command can be used in VDSL to request near-end data only
   (CO). For the far-end QLN to be provided via the EOC channel
   CMD_TestParamsFE_Request must be used. In ADSL, the command can be applied for
   near-end as well as far-end parameters.
   During loop diagnostic mode, the command can be used to request both near-end and
   far-end data.
*/
struct CMD_QLN_US_Get
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
   Returns information about the QLN per subcarrier group for the chosen range.
   (Section 7.5.1.27.6 of G997.1)
*/
struct ACK_QLN_US_Get
{
#if MEI_DRV_OS_BYTE_ORDER == MEI_DRV_OS_BIG_ENDIAN
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** QLN per SG: QLNpsus */
   VNX_QLN_NE_t QLNus[128];
#else
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** QLN per SG: QLNpsus */
   VNX_QLN_NE_t QLNus[128];
#endif
} __PACKED__ ;


/**
   Requests information about the downstream SNR per subcarrier group (Section
   7.5.1.28.3 of G997.1).
*/
struct CMD_SNR_DS_Get
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
   Returns information about the SNR per subcarrier group for the chosen range.
   (Section 7.5.1.28.3 of G997.1)
*/
struct ACK_SNR_DS_Get
{
#if MEI_DRV_OS_BYTE_ORDER == MEI_DRV_OS_BIG_ENDIAN
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** SNR per SG: SNRpsds */
   VNX_SNR_t SNRpsds[128];
#else
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** SNR per SG: SNRpsds */
   VNX_SNR_t SNRpsds[128];
#endif
} __PACKED__ ;


/**
   Requests information about the upstream SNR per subcarrier group (Section 7.5.1.28.6
   of G997.1).
   During Showtime the message is used to retrieve the SNRpsus at the ADSL-CPE. During
   loop diagnostic mode it is applied at the VDSL-CO & CPE and the ADSL-CPE.
*/
struct CMD_SNR_US_Get
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
   Returns information about the upstream SNR per subcarrier group for the chosen
   range. (Section 7.5.1.28.6 of G997.1)
*/
struct ACK_SNR_US_Get
{
#if MEI_DRV_OS_BYTE_ORDER == MEI_DRV_OS_BIG_ENDIAN
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** SNR per SG: SNRpsus */
   VNX_SNR_t SNRpsus[128];
#else
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** SNR per SG: SNRpsus */
   VNX_SNR_t SNRpsus[128];
#endif
} __PACKED__ ;


/**
   Requests test parameter related information for the downstream direction: The HLIN
   scaling factor (HLINSCds), the subcarrier group size "G" and the measurement times
   for HLOGpsds, QLNpsds, SNRpsds.
   (Sections 7.5.1.26.1/2/4/5, 7.5.1.27.1/2 and 7.5.1.28.1/2 of G997.1)
   During loop diagnostic mode (VDSL, ADSL) and in ADSL also during STEADY_STATE, the
   command is used to request both near-end and far-end data.
   In VDSL during STEADY_STATE, the command can be used to retrieve all near-end data
   (VTU-R) but far-end (applied at VTU-O) only to retrieve the "group size" parameters.
   To get the measurement time parameters (via the EOC channel) the message
   CMD_TestParamsFE_Request must be applied instead.
*/
struct CMD_TestParamsAuxDS_Get
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
   Provides the test-parameter related information as requested by
   CMD_TestParamsAuxDS_Get: The HLIN scaling factor (HLINSCds), the subcarrier group
   size "G" and the measurement times for HLOGpsds, QLNpsds, SNRpsds.
   (Sections 7.5.1.26.1/2/4/5, 7.5.1.27.1/2 and 7.5.1.28.1/2 of G997.1)
*/
struct ACK_TestParamsAuxDS_Get
{
#if MEI_DRV_OS_BYTE_ORDER == MEI_DRV_OS_BIG_ENDIAN
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** HLIN Scaling Factor "HLINSCds" */
   IFX_uint16_t HLINSC;
   /** HLIN Subcarrier Group Size DS "HLINGds" */
   IFX_uint16_t HLING;
   /** HLOG Measurement Time "HLOGMTds" */
   IFX_uint16_t HLOGMT;
   /** HLOG Subcarrier Group Size DS "HLOGGds" */
   IFX_uint16_t HLOGG;
   /** QLN Measurment Time "QLNMTds" */
   IFX_uint16_t QLNMT;
   /** QLN Subcarrier Group Size DS "QLNGds" */
   IFX_uint16_t QLNG;
   /** SNR Measurement Time "SNRMTds" */
   IFX_uint16_t SNRMT;
   /** SNR Subcarrier Group Size DS "SNRGds" */
   IFX_uint16_t SNRG;
#else
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** HLIN Scaling Factor "HLINSCds" */
   IFX_uint16_t HLINSC;
   /** HLIN Subcarrier Group Size DS "HLINGds" */
   IFX_uint16_t HLING;
   /** HLOG Measurement Time "HLOGMTds" */
   IFX_uint16_t HLOGMT;
   /** HLOG Subcarrier Group Size DS "HLOGGds" */
   IFX_uint16_t HLOGG;
   /** QLN Measurment Time "QLNMTds" */
   IFX_uint16_t QLNMT;
   /** QLN Subcarrier Group Size DS "QLNGds" */
   IFX_uint16_t QLNG;
   /** SNR Measurement Time "SNRMTds" */
   IFX_uint16_t SNRMT;
   /** SNR Subcarrier Group Size DS "SNRGds" */
   IFX_uint16_t SNRG;
#endif
} __PACKED__ ;


/**
   Requests test parameter related information for the upstream direction: The HLIN
   scaling factor (HLINSCus), the subcarrier group size "G" and the measurement times
   for HLOGpsus, QLNpsus, SNRpsus.
   (Sections 7.5.1.26.7/8/10/11, 7.5.1.27.4/5 and 7.5.1.28.4/5 of G997.1)
   During loop diagnostic mode (VDSL, ADSL) and in ADSL also during STEADY_STATE, the
   command is used to request both near-end and far-end data.
   In VDSL during STEADY_STATE, the command can be used to retrieve all near-end data
   (VTU-O) but far-end (applied at VTU-R) only to retrieve the "group size" parameters.
   To get the measurement time parameters (via the EOC channel) the message
   CMD_TestParamsFE_Request must be applied instead.
*/
struct CMD_TestParamsAuxUS_Get
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
   Provides the test-parameter related information as requested by
   CMD_TestParamsAuxUS_Get: The HLIN scaling factor (HLINSCus), the subcarrier group
   size "G" and the measurement times for HLOGpsus, QLNpsus, SNRpsus.
*/
struct ACK_TestParamsAuxUS_Get
{
#if MEI_DRV_OS_BYTE_ORDER == MEI_DRV_OS_BIG_ENDIAN
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** HLIN Scaling Factor "HLINSCus" */
   IFX_uint16_t HLINSC;
   /** HLIN Subcarrier Group Size DS "HLINGus" */
   IFX_uint16_t HLING;
   /** HLOG Measurement Time "HLOGMTus" */
   IFX_uint16_t HLOGMT;
   /** HLOG Subcarrier Group Size DS "HLOGGus" */
   IFX_uint16_t HLOGG;
   /** QLN Measurment Time "QLNMTus" */
   IFX_uint16_t QLNMT;
   /** QLN Subcarrier Group Size DS "QLNGus" */
   IFX_uint16_t QLNG;
   /** SNR Measurement Time "SNRMTus" */
   IFX_uint16_t SNRMT;
   /** SNR Subcarrier Group Size DS "SNRGus" */
   IFX_uint16_t SNRG;
#else
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** HLIN Scaling Factor "HLINSCus" */
   IFX_uint16_t HLINSC;
   /** HLIN Subcarrier Group Size DS "HLINGus" */
   IFX_uint16_t HLING;
   /** HLOG Measurement Time "HLOGMTus" */
   IFX_uint16_t HLOGMT;
   /** HLOG Subcarrier Group Size DS "HLOGGus" */
   IFX_uint16_t HLOGG;
   /** QLN Measurment Time "QLNMTus" */
   IFX_uint16_t QLNMT;
   /** QLN Subcarrier Group Size DS "QLNGus" */
   IFX_uint16_t QLNG;
   /** SNR Measurement Time "SNRMTus" */
   IFX_uint16_t SNRMT;
   /** SNR Subcarrier Group Size DS "SNRGus" */
   IFX_uint16_t SNRG;
#endif
} __PACKED__ ;


/**
   This message is used to trigger retrieval of the far-end PMD Test Parameters Hlog,
   SNR and QLN via the EOC channel during Showtime. If StartIndex or EndIndex do not
   contain values in a valid range then no autonomous message will be sent by the
   firmware. Once the retrieval process is started, it can also be aborted with this
   message via the control parameter. The status of the parameter retrieval process can
   be polled via the CMD_TestParamsFE_Poll message. Once the parameters are retrieved,
   they are provided with the EVT_PMD_TestParamsGet message.
*/
struct CMD_TestParamsFE_Request
{
#if MEI_DRV_OS_BYTE_ORDER == MEI_DRV_OS_BIG_ENDIAN
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Far-end Retrieval Control */
   IFX_uint16_t Control;
   /** Subcarrier Group Start Index */
   IFX_uint16_t StartIndex;
   /** Subcarrier Group End Index */
   IFX_uint16_t EndIndex;
#else
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Far-end Retrieval Control */
   IFX_uint16_t Control;
   /** Subcarrier Group Start Index */
   IFX_uint16_t StartIndex;
   /** Subcarrier Group End Index */
   IFX_uint16_t EndIndex;
#endif
} __PACKED__ ;


/**
   This is the acknowledgement for CMD_TestParamsFE_Request.
*/
struct ACK_TestParamsFE_Request
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
   This message polls the status of the far end parameter retrieval process.
*/
struct CMD_TestParamsFE_Poll
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
   This is the acknowledgement for CMD_TestParamsFE_Poll.
*/
struct ACK_TestParamsFE_Poll
{
#if MEI_DRV_OS_BYTE_ORDER == MEI_DRV_OS_BIG_ENDIAN
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Far-end retrieval status */
   IFX_uint16_t Status;
   /** Reserved1 */
   IFX_uint16_t Res1;
   /** Reserved2 */
   IFX_uint16_t Res2;
#else
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Far-end retrieval status */
   IFX_uint16_t Status;
   /** Reserved1 */
   IFX_uint16_t Res1;
   /** Reserved2 */
   IFX_uint16_t Res2;
#endif
} __PACKED__ ;


/**
   This event message provides the far-end data after the far end data retrieval
   process. This message is a result of the CMD_TestParamsFE_Request message.
*/
struct EVT_PMD_TestParamsGet
{
#if MEI_DRV_OS_BYTE_ORDER == MEI_DRV_OS_BIG_ENDIAN
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Reserved1 */
   IFX_uint16_t Res1;
   /** Subcarrier Group Start Index */
   IFX_uint16_t StartIndex;
   /** Subcarrier Group End Index */
   IFX_uint16_t EndIndex;
   /** HLOG Measurement Time HLOGMT */
   IFX_uint16_t hlogTime;
   /** SNR Measurement Time SNRMT */
   IFX_uint16_t snrTime;
   /** QLN Measurment Time QLNMT */
   IFX_uint16_t qlnTime;
   /** Testparameter Result */
   VNX_TestParam_t TestPar[60];
#else
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Reserved1 */
   IFX_uint16_t Res1;
   /** Subcarrier Group Start Index */
   IFX_uint16_t StartIndex;
   /** Subcarrier Group End Index */
   IFX_uint16_t EndIndex;
   /** HLOG Measurement Time HLOGMT */
   IFX_uint16_t hlogTime;
   /** SNR Measurement Time SNRMT */
   IFX_uint16_t snrTime;
   /** QLN Measurment Time QLNMT */
   IFX_uint16_t qlnTime;
   /** Testparameter Result */
   VNX_TestParam_t TestPar[60];
#endif
} __PACKED__ ;


/**
   The message is used to configure the autonomous messaging related to Clear EOC
   transmission.
*/
struct CMD_ClearEOC_Configure
{
#if MEI_DRV_OS_BYTE_ORDER == MEI_DRV_OS_BIG_ENDIAN
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Reserved */
   IFX_uint16_t Res02 : 13;
   /** Rx Autonomous Clear EOC Data Message Control */
   IFX_uint16_t RxEVTdata : 1;
   /** Rx Autonomous Status Message Control */
   IFX_uint16_t RxEVTstatus : 1;
   /** Tx Autonomous Status Message Control */
   IFX_uint16_t TxEVTstatus : 1;
#else
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Tx Autonomous Status Message Control */
   IFX_uint16_t TxEVTstatus : 1;
   /** Rx Autonomous Status Message Control */
   IFX_uint16_t RxEVTstatus : 1;
   /** Rx Autonomous Clear EOC Data Message Control */
   IFX_uint16_t RxEVTdata : 1;
   /** Reserved */
   IFX_uint16_t Res02 : 13;
#endif
} __PACKED__ ;


/**
   This is the acknowledgement for CMD_ClearEOC_Configure.
*/
struct ACK_ClearEOC_Configure
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
   The message is used to trigger the transmission of  Clear EOC messages that were
   placed into the Clear EOC transmit buffer before with CMD_ClearEOC_Write.
*/
struct CMD_ClearEOC_TxTrigger
{
#if MEI_DRV_OS_BYTE_ORDER == MEI_DRV_OS_BIG_ENDIAN
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Reserved */
   IFX_uint16_t Res02 : 15;
   /** Transmit Control Trigger */
   IFX_uint16_t txTrigger : 1;
#else
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Transmit Control Trigger */
   IFX_uint16_t txTrigger : 1;
   /** Reserved */
   IFX_uint16_t Res02 : 15;
#endif
} __PACKED__ ;


/**
   This is the acknowledgement for CMD_ClearEOC_TxTrigger.
*/
struct ACK_ClearEOC_TxTrigger
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
   This message is used to write data to the ClearEOC write buffer of type
   VNX_ClearEOC_t. When the buffer is filled, the transmission is started applying
   CMD_ClearEOC_TxTrigger. If the message to transmit is longer than the mailbox size,
   a sequence of writes to the ClearEOC buffer has to be done before the transmission
   is started with CMD_ClearEOC_TxTrigger. When autonomous Tx status messaging is
   activated via CMD_ClearEOC_Configure, then the finished transmission is indicated by
   EVT_ClearEOCStatusGet.
*/
struct CMD_ClearEOC_Write
{
#if MEI_DRV_OS_BYTE_ORDER == MEI_DRV_OS_BIG_ENDIAN
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Data */
   IFX_uint16_t Data[128];
#else
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Data */
   IFX_uint16_t Data[128];
#endif
} __PACKED__ ;


/**
   This message is the acknowledgement for CMD_ClearEOC_Write.
*/
struct ACK_ClearEOC_Write
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
   This message is used to read data from the ClearEOC buffer of type VNX_ClearEOC_t.
   The length of the actual Clear EOC message can be found in the buffer. Please refer
   to VNX_ClearEOC_t. The availability of data can either be checked via
   CMD_ClearEOCStatusGet in polling mode or it can be reported by an autonomous
   EVT_ClearEOCStatusGet message when data is received (to be enabled using
   CMD_ClearEOC_Configure).
*/
struct CMD_ClearEOC_Read
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
   This message is the acknowledgement to CMD_ClearEOC_Read.
*/
struct ACK_ClearEOC_Read
{
#if MEI_DRV_OS_BYTE_ORDER == MEI_DRV_OS_BIG_ENDIAN
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Data */
   IFX_uint16_t Data[128];
#else
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Data */
   IFX_uint16_t Data[128];
#endif
} __PACKED__ ;


/**
   This message is an autonomous message that is generated when ClearEOC data was
   received and autonomous Clear EOC data messaging has been activated via
   CMD_ClearEOC_Configure. If the ClearEOC data does not fit in one message, then a
   sequence of messages is generated. The ClearEOC buffer is of type VNX_ClearEOC_t.
*/
struct EVT_ClearEOC_Read
{
#if MEI_DRV_OS_BYTE_ORDER == MEI_DRV_OS_BIG_ENDIAN
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Data */
   IFX_uint16_t Data[128];
#else
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Data */
   IFX_uint16_t Data[128];
#endif
} __PACKED__ ;


/**
   This message is used to retrieve the status of the clear eoc data transmission.
*/
struct CMD_ClearEOCStatusGet
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
   This is the acknowledgement for CMD_ClearEOCStatusGet.
*/
struct ACK_ClearEOCStatusGet
{
#if MEI_DRV_OS_BYTE_ORDER == MEI_DRV_OS_BIG_ENDIAN
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Reserved */
   IFX_uint16_t Res02 : 14;
   /** Transmit Status */
   IFX_uint16_t txstat : 2;
   /** Reserved */
   IFX_uint16_t Res04 : 14;
   /** Receive Status */
   IFX_uint16_t rxstat : 2;
#else
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Transmit Status */
   IFX_uint16_t txstat : 2;
   /** Reserved */
   IFX_uint16_t Res02 : 14;
   /** Receive Status */
   IFX_uint16_t rxstat : 2;
   /** Reserved */
   IFX_uint16_t Res04 : 14;
#endif
} __PACKED__ ;


/**
   This autonomous message reports the Clear EOC status. It is sent only if the
   "Autonomous Status Message Control" was enabled for Tx and/or Rx direction with
   CMD_ClearEOC_Configure. If Tx direction is enabled, the message is generated when a
   Tx transmission is finished or failed. If Rx direction is enabled, the message is
   generated when the Rx status transitions from "Idle" to "Data Available" for
   retrieval by the host.
*/
struct EVT_ClearEOCStatusGet
{
#if MEI_DRV_OS_BYTE_ORDER == MEI_DRV_OS_BIG_ENDIAN
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Reserved */
   IFX_uint16_t Res02 : 14;
   /** Transmit Status */
   IFX_uint16_t txstat : 2;
   /** Reserved */
   IFX_uint16_t Res04 : 14;
   /** Receive Status */
   IFX_uint16_t rxstat : 2;
#else
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Transmit Status */
   IFX_uint16_t txstat : 2;
   /** Reserved */
   IFX_uint16_t Res02 : 14;
   /** Receive Status */
   IFX_uint16_t rxstat : 2;
   /** Reserved */
   IFX_uint16_t Res04 : 14;
#endif
} __PACKED__ ;


/**
   The message is used to reset the transmit or receive status of the clear eoc data
   transmission to IDLE (for defined states see also CMD_ClearEOCStatusGet). See the
   description on the Clear EOC handling on Page746 for when it has to be applied.
   Transmit and receive status are distinguished by the Index parameter.
*/
struct CMD_ClearEOCStatusSet
{
#if MEI_DRV_OS_BYTE_ORDER == MEI_DRV_OS_BIG_ENDIAN
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Reserved */
   IFX_uint16_t Res02 : 14;
   /** Status */
   IFX_uint16_t stat : 2;
#else
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Status */
   IFX_uint16_t stat : 2;
   /** Reserved */
   IFX_uint16_t Res02 : 14;
#endif
} __PACKED__ ;


/**
   This is the acknowledgement for CMD_ClearEOCStatusSet.
*/
struct ACK_ClearEOCStatusSet
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
   Configuration of options for the overhead handling.
*/
struct CMD_OH_OptionsSet
{
#if MEI_DRV_OS_BYTE_ORDER == MEI_DRV_OS_BIG_ENDIAN
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** EOC Polling Period Scaling Factor, Bits 15 to 8 */
   IFX_uint8_t eocPollFactor;
   /** Reserved */
   IFX_uint16_t Res03 : 3;
   /** EOC Polling Control Prio 2: PMD Test Parameters, Bit 4 */
   IFX_uint16_t eocPoll2 : 1;
   /** EOC Polling Control Prio 1: Inventory, Counters, Bit 3 */
   IFX_uint16_t eocPoll1 : 1;
   /** Reserved */
   IFX_uint16_t Res06 : 3;
#else
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Reserved */
   IFX_uint16_t Res06 : 3;
   /** EOC Polling Control Prio 1: Inventory, Counters, Bit 3 */
   IFX_uint16_t eocPoll1 : 1;
   /** EOC Polling Control Prio 2: PMD Test Parameters, Bit 4 */
   IFX_uint16_t eocPoll2 : 1;
   /** Reserved */
   IFX_uint16_t Res03 : 3;
   /** EOC Polling Period Scaling Factor, Bits 15 to 8 */
   IFX_uint8_t eocPollFactor;
#endif
} __PACKED__ ;


/**
   Acknowledgement for CMD_OH_OptionsSet.
*/
struct ACK_OH_OptionsSet
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
   Requests OH polling statistic information.
*/
struct CMD_OH_StatsGet
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
   Reports the OH polling statistics as requested by CMD_OH_StatsGet.
*/
struct ACK_OH_StatsGet
{
#if MEI_DRV_OS_BYTE_ORDER == MEI_DRV_OS_BIG_ENDIAN
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** EOC CMD Tx PRIO1 Sent */
   IFX_uint16_t eocCMD1;
   /** EOC ACK Rx PRIO1 Count */
   IFX_uint16_t eocRSP1;
   /** EOC CMD Tx PRIO2 Sent */
   IFX_uint16_t eocCMD2;
   /** EOC ACK Rx PRIO2 Count */
   IFX_uint16_t eocRSP2;
   /** EOC NACK Rx PRIO1 Count */
   IFX_uint16_t eocNACK1;
#else
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** EOC CMD Tx PRIO1 Sent */
   IFX_uint16_t eocCMD1;
   /** EOC ACK Rx PRIO1 Count */
   IFX_uint16_t eocRSP1;
   /** EOC CMD Tx PRIO2 Sent */
   IFX_uint16_t eocCMD2;
   /** EOC ACK Rx PRIO2 Count */
   IFX_uint16_t eocRSP2;
   /** EOC NACK Rx PRIO1 Count */
   IFX_uint16_t eocNACK1;
#endif
} __PACKED__ ;


/**
   Enables/Disables support for certain OLR events (SRA, SOS).
   An OLR transition is always initiated by the receiving PMD, so the CPE requests the
   OLR event for downstream and the CO for upstream direction.
   ATU_R: A control bit exists for downstream only, for upstream the CPE services all
   US SRA requests from the CO if possible (no framing constraints).
*/
struct CMD_OLR_Control
{
#if MEI_DRV_OS_BYTE_ORDER == MEI_DRV_OS_BIG_ENDIAN
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Reserved */
   IFX_uint16_t Res02 : 4;
   /** ROC DS */
   IFX_uint16_t ROC_DS : 1;
   /** ROC US */
   IFX_uint16_t ROC_US : 1;
   /** SOS DS */
   IFX_uint16_t SOS_DS : 1;
   /** SOS US */
   IFX_uint16_t SOS_US : 1;
   /** Reserved */
   IFX_uint16_t Res07 : 5;
   /** Auto-SRA DS */
   IFX_uint16_t autoSRA_DS : 1;
   /** Auto-SRA US */
   IFX_uint16_t autoSRA_US : 1;
   /** Reserved */
   IFX_uint16_t Res10 : 1;
#else
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Reserved */
   IFX_uint16_t Res10 : 1;
   /** Auto-SRA US */
   IFX_uint16_t autoSRA_US : 1;
   /** Auto-SRA DS */
   IFX_uint16_t autoSRA_DS : 1;
   /** Reserved */
   IFX_uint16_t Res07 : 5;
   /** SOS US */
   IFX_uint16_t SOS_US : 1;
   /** SOS DS */
   IFX_uint16_t SOS_DS : 1;
   /** ROC US */
   IFX_uint16_t ROC_US : 1;
   /** ROC DS */
   IFX_uint16_t ROC_DS : 1;
   /** Reserved */
   IFX_uint16_t Res02 : 4;
#endif
} __PACKED__ ;


/**
   Acknowledgement for CMD_OLR_Control.
*/
struct ACK_OLR_Control
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
   Configures the downstream SRA behaviour.
*/
struct CMD_SRA_DS_Configure
{
#if MEI_DRV_OS_BYTE_ORDER == MEI_DRV_OS_BIG_ENDIAN
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Downshift Noise Margin Downstream */
   IFX_uint16_t RA_DSNRMds;
   /** Downshift Time Interval Downstream */
   IFX_uint16_t RA_DTIMEds;
   /** Upshift Noise Margin Downstream */
   IFX_uint16_t RA_USNRMds;
   /** Upshift Time Interval Downstream */
   IFX_uint16_t RA_UTIMEds;
#else
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Downshift Noise Margin Downstream */
   IFX_uint16_t RA_DSNRMds;
   /** Downshift Time Interval Downstream */
   IFX_uint16_t RA_DTIMEds;
   /** Upshift Noise Margin Downstream */
   IFX_uint16_t RA_USNRMds;
   /** Upshift Time Interval Downstream */
   IFX_uint16_t RA_UTIMEds;
#endif
} __PACKED__ ;


/**
   Acknowledgement for CMD_SRA_DS_Configure.
*/
struct ACK_SRA_DS_Configure
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
   Configures the upstream SRA behaviour.
*/
struct CMD_SRA_US_Configure
{
#if MEI_DRV_OS_BYTE_ORDER == MEI_DRV_OS_BIG_ENDIAN
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Downshift Noise Margin Upstream */
   IFX_uint16_t RA_DSNRMus;
   /** Downshift Time Interval Upstream */
   IFX_uint16_t RA_DTIMEus;
   /** Upshift Noise Margin Upstream */
   IFX_uint16_t RA_USNRMus;
   /** Upshift Time Interval Upstream */
   IFX_uint16_t RA_UTIMEus;
#else
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Downshift Noise Margin Upstream */
   IFX_uint16_t RA_DSNRMus;
   /** Downshift Time Interval Upstream */
   IFX_uint16_t RA_DTIMEus;
   /** Upshift Noise Margin Upstream */
   IFX_uint16_t RA_USNRMus;
   /** Upshift Time Interval Upstream */
   IFX_uint16_t RA_UTIMEus;
#endif
} __PACKED__ ;


/**
   Acknowledgement for CMD_SRA_US_Configure.
*/
struct ACK_SRA_US_Configure
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
   The messages configures the downstream SOS triggering parameters. They are
   configured at the VTU-O and transferred to the VTU-R during initialization with
   O-MSG1.
*/
struct CMD_SOS_DS_Configure
{
#if MEI_DRV_OS_BYTE_ORDER == MEI_DRV_OS_BIG_ENDIAN
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Downstream SOS-TIME Window */
   IFX_uint16_t SOS_TIME;
   /** Downstream SOS-NTONES */
   IFX_uint16_t SOS_NTONES;
   /** Downstream SOS-CRC */
   IFX_uint16_t SOS_CRC;
   /** Downstream MAX-SOS */
   IFX_uint16_t MAX_SOS;
   /** Downstream SNRMOFFSET-ROC */
   IFX_uint16_t SNRMOFFSET_ROC;
   /** Downstream INPMIN-ROC */
   IFX_uint16_t INPMIN_ROC;
   /** Downstream Single-Step Size (G_SOS) */
   IFX_uint16_t G_SOS;
#else
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Downstream SOS-TIME Window */
   IFX_uint16_t SOS_TIME;
   /** Downstream SOS-NTONES */
   IFX_uint16_t SOS_NTONES;
   /** Downstream SOS-CRC */
   IFX_uint16_t SOS_CRC;
   /** Downstream MAX-SOS */
   IFX_uint16_t MAX_SOS;
   /** Downstream SNRMOFFSET-ROC */
   IFX_uint16_t SNRMOFFSET_ROC;
   /** Downstream INPMIN-ROC */
   IFX_uint16_t INPMIN_ROC;
   /** Downstream Single-Step Size (G_SOS) */
   IFX_uint16_t G_SOS;
#endif
} __PACKED__ ;


/**
   Acknowledgement for CMD_SOS_DS_Configure.
*/
struct ACK_SOS_DS_Configure
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
   The messages configures the upstream SOS triggering parameters.
*/
struct CMD_SOS_US_Configure
{
#if MEI_DRV_OS_BYTE_ORDER == MEI_DRV_OS_BIG_ENDIAN
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Upstream SOS-TIME Window */
   IFX_uint16_t SOS_TIME;
   /** Upstream SOS-NTONES */
   IFX_uint16_t SOS_NTONES;
   /** Upstream SOS-CRC */
   IFX_uint16_t SOS_CRC;
   /** Upstream MAX-SOS */
   IFX_uint16_t MAX_SOS;
   /** Upstream SNRMOFFSET-ROC */
   IFX_uint16_t SNRMOFFSET_ROC;
   /** Upstream INPMIN-ROC */
   IFX_uint16_t INPMIN_ROC;
   /** Upstream Single-Step Size (G_SOS) */
   IFX_uint16_t G_SOS;
#else
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Upstream SOS-TIME Window */
   IFX_uint16_t SOS_TIME;
   /** Upstream SOS-NTONES */
   IFX_uint16_t SOS_NTONES;
   /** Upstream SOS-CRC */
   IFX_uint16_t SOS_CRC;
   /** Upstream MAX-SOS */
   IFX_uint16_t MAX_SOS;
   /** Upstream SNRMOFFSET-ROC */
   IFX_uint16_t SNRMOFFSET_ROC;
   /** Upstream INPMIN-ROC */
   IFX_uint16_t INPMIN_ROC;
   /** Upstream Single-Step Size (G_SOS) */
   IFX_uint16_t G_SOS;
#endif
} __PACKED__ ;


/**
   Acknowledgement for CMD_SOS_US_Configure.
*/
struct ACK_SOS_US_Configure
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
   The messages configures the downstream SOS data rate for bearer channel 0. (Section
   7.3.2.1.6 of G.997.1)
*/
struct CMD_SOS_RateBC0_DS_Set
{
#if MEI_DRV_OS_BYTE_ORDER == MEI_DRV_OS_BIG_ENDIAN
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** PTM Minimum SOS Data Rate BC0 DS */
   IFX_uint16_t minSosBR0_PTM;
   /** ATM Minimum SOS Data Rate BC0 DS */
   IFX_uint16_t minSosBR0_ATM;
#else
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** PTM Minimum SOS Data Rate BC0 DS */
   IFX_uint16_t minSosBR0_PTM;
   /** ATM Minimum SOS Data Rate BC0 DS */
   IFX_uint16_t minSosBR0_ATM;
#endif
} __PACKED__ ;


/**
   Acknowledgement for CMD_SOS_RateBC0_DS_Set.
*/
struct ACK_SOS_RateBC0_DS_Set
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
   The messages configures the upstream SOS data rate for bearer channel 0. (Section
   7.3.2.1.7 of G.997.1)
*/
struct CMD_SOS_RateBC0_US_Set
{
#if MEI_DRV_OS_BYTE_ORDER == MEI_DRV_OS_BIG_ENDIAN
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** PTM Minimum SOS Data Rate BC0 US */
   IFX_uint16_t minSosBR0_PTM;
   /** ATM Minimum SOS Data Rate BC0 US */
   IFX_uint16_t minSosBR0_ATM;
#else
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** PTM Minimum SOS Data Rate BC0 US */
   IFX_uint16_t minSosBR0_PTM;
   /** ATM Minimum SOS Data Rate BC0 US */
   IFX_uint16_t minSosBR0_ATM;
#endif
} __PACKED__ ;


/**
   Acknowledgement for CMD_SOS_RateBC0_US_Set.
*/
struct ACK_SOS_RateBC0_US_Set
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
   Requests the OLR status information on bit swaps, DRR, SRA and SOS events for the
   upstream direction.
*/
struct CMD_OLR_US_StatsGet
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
   Reports the OLR status information for the upstream direction as requested by
   CMD_OLR_US_StatsGet.
*/
struct ACK_OLR_US_StatsGet
{
#if MEI_DRV_OS_BYTE_ORDER == MEI_DRV_OS_BIG_ENDIAN
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** US Bit Swap Requests */
   IFX_uint16_t BitswapReqs;
   /** US Extended Bit Swap Requests */
   IFX_uint16_t ExtBitswapReqs;
   /** US Bit Swap UTC Responses */
   IFX_uint16_t BitswapUTCs;
   /** US "Bit Swaps Performed" Count */
   IFX_uint16_t BitswapsDone;
   /** US Bitswap Timeouts */
   IFX_uint16_t BitswapTimeOuts;
   /** Reserved for DRR */
   IFX_uint16_t Res07[5];
   /** US SRA Requests */
   IFX_uint16_t SRA_Reqs;
   /** Reserved */
   IFX_uint16_t Res09;
   /** US SRA UTC Responses */
   IFX_uint16_t SRA_UTCs;
   /** US "SRA Performed" Count */
   IFX_uint16_t SRAsDone;
   /** US SRA Timeouts */
   IFX_uint16_t SRA_TimeOuts;
   /** US SOS Requests */
   IFX_uint16_t SOS_Reqs;
   /** Reserved */
   IFX_uint16_t Res14;
   /** US SOS UTC Responses */
   IFX_uint16_t SOS_UTCs;
   /** US "SOS Performed" Count */
   IFX_uint16_t SOS_Done;
   /** US SOS Timeouts */
   IFX_uint16_t SOS_TimeOuts;
#else
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** US Bit Swap Requests */
   IFX_uint16_t BitswapReqs;
   /** US Extended Bit Swap Requests */
   IFX_uint16_t ExtBitswapReqs;
   /** US Bit Swap UTC Responses */
   IFX_uint16_t BitswapUTCs;
   /** US "Bit Swaps Performed" Count */
   IFX_uint16_t BitswapsDone;
   /** US Bitswap Timeouts */
   IFX_uint16_t BitswapTimeOuts;
   /** Reserved for DRR */
   IFX_uint16_t Res07[5];
   /** US SRA Requests */
   IFX_uint16_t SRA_Reqs;
   /** Reserved */
   IFX_uint16_t Res09;
   /** US SRA UTC Responses */
   IFX_uint16_t SRA_UTCs;
   /** US "SRA Performed" Count */
   IFX_uint16_t SRAsDone;
   /** US SRA Timeouts */
   IFX_uint16_t SRA_TimeOuts;
   /** US SOS Requests */
   IFX_uint16_t SOS_Reqs;
   /** Reserved */
   IFX_uint16_t Res14;
   /** US SOS UTC Responses */
   IFX_uint16_t SOS_UTCs;
   /** US "SOS Performed" Count */
   IFX_uint16_t SOS_Done;
   /** US SOS Timeouts */
   IFX_uint16_t SOS_TimeOuts;
#endif
} __PACKED__ ;


/**
   Requests the OLR status information on bit swaps, DRR, SRA and SOS events for the
   downstream direction.
*/
struct CMD_OLR_DS_StatsGet
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
   Reports the OLR status information for the downstream direction as requested by
   CMD_OLR_DS_StatsGet.
*/
struct ACK_OLR_DS_StatsGet
{
#if MEI_DRV_OS_BYTE_ORDER == MEI_DRV_OS_BIG_ENDIAN
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** DS Bit Swap Requests */
   IFX_uint16_t BitswapReqs;
   /** DS Extended Bit Swap Requests */
   IFX_uint16_t ExtBitswapReqs;
   /** DS Bit Swap UTC Responses */
   IFX_uint16_t BitswapUTCs;
   /** DS "Bit Swaps Performed" Count */
   IFX_uint16_t BitswapsDone;
   /** DS Bitswap Timeouts */
   IFX_uint16_t BitswapTimeOuts;
   /** Reserved for DRR */
   IFX_uint16_t Res07[5];
   /** DS SRA Requests */
   IFX_uint16_t SRA_Reqs;
   /** Reserved */
   IFX_uint16_t Res09;
   /** DS SRA UTC Responses */
   IFX_uint16_t SRA_UTCs;
   /** DS "SRA Performed" Count */
   IFX_uint16_t SRAsDone;
   /** DS SRA Timeouts */
   IFX_uint16_t SRA_TimeOuts;
   /** DS SOS Requests */
   IFX_uint16_t SOS_Reqs;
   /** Reserved */
   IFX_uint16_t Res14;
   /** DS SOS UTC Responses */
   IFX_uint16_t SOS_UTCs;
   /** DS "SOS Performed" Count */
   IFX_uint16_t SOS_Done;
   /** DS SOS Timeouts */
   IFX_uint16_t SOS_TimeOuts;
#else
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** DS Bit Swap Requests */
   IFX_uint16_t BitswapReqs;
   /** DS Extended Bit Swap Requests */
   IFX_uint16_t ExtBitswapReqs;
   /** DS Bit Swap UTC Responses */
   IFX_uint16_t BitswapUTCs;
   /** DS "Bit Swaps Performed" Count */
   IFX_uint16_t BitswapsDone;
   /** DS Bitswap Timeouts */
   IFX_uint16_t BitswapTimeOuts;
   /** Reserved for DRR */
   IFX_uint16_t Res07[5];
   /** DS SRA Requests */
   IFX_uint16_t SRA_Reqs;
   /** Reserved */
   IFX_uint16_t Res09;
   /** DS SRA UTC Responses */
   IFX_uint16_t SRA_UTCs;
   /** DS "SRA Performed" Count */
   IFX_uint16_t SRAsDone;
   /** DS SRA Timeouts */
   IFX_uint16_t SRA_TimeOuts;
   /** DS SOS Requests */
   IFX_uint16_t SOS_Reqs;
   /** Reserved */
   IFX_uint16_t Res14;
   /** DS SOS UTC Responses */
   IFX_uint16_t SOS_UTCs;
   /** DS "SOS Performed" Count */
   IFX_uint16_t SOS_Done;
   /** DS SOS Timeouts */
   IFX_uint16_t SOS_TimeOuts;
#endif
} __PACKED__ ;


/**
   Requests the actual active downstream RA mode (ACT-RA-MODEds, Section 7.5.1.33.1 of
   G.997.1).
*/
struct CMD_RA_ModeDS_Get
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
   Reports the actual active downstream RA mode (ACT-RA-MODEds) as requested by
   CMD_RA_ModeDS_Get.
*/
struct ACK_RA_ModeDS_Get
{
#if MEI_DRV_OS_BYTE_ORDER == MEI_DRV_OS_BIG_ENDIAN
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** RA Mode DS */
   IFX_uint16_t actRA_mode;
#else
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** RA Mode DS */
   IFX_uint16_t actRA_mode;
#endif
} __PACKED__ ;


/**
   Requests the actual active upstream RA mode (ACT-RA-MODEus, Section 7.5.1.33.2 of
   G.997.1).

*/
struct CMD_RA_ModeUS_Get
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
   Reports the actual active upstream RA mode (ACT-RA-MODEus) as requested by
   CMD_RA_ModeUS_Get.
*/
struct ACK_RA_ModeUS_Get
{
#if MEI_DRV_OS_BYTE_ORDER == MEI_DRV_OS_BIG_ENDIAN
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** RA Mode US */
   IFX_uint16_t actRA_mode;
#else
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** RA Mode US */
   IFX_uint16_t actRA_mode;
#endif
} __PACKED__ ;


/**
   Autonomous message indicating a successful upstream OLR event (SRA or SOS).

*/
struct EVT_OLR_US_EventGet
{
#if MEI_DRV_OS_BYTE_ORDER == MEI_DRV_OS_BIG_ENDIAN
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Reserved */
   IFX_uint16_t Res02 : 14;
   /** SRA Event */
   IFX_uint16_t SRA_OK : 1;
   /** SOS Event (VDSL only) */
   IFX_uint16_t SOS_OK : 1;
#else
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** SOS Event (VDSL only) */
   IFX_uint16_t SOS_OK : 1;
   /** SRA Event */
   IFX_uint16_t SRA_OK : 1;
   /** Reserved */
   IFX_uint16_t Res02 : 14;
#endif
} __PACKED__ ;


/**
   Autonomous message indicating a successful downstream OLR event (SRA or SOS).
*/
struct EVT_OLR_DS_EventGet
{
#if MEI_DRV_OS_BYTE_ORDER == MEI_DRV_OS_BIG_ENDIAN
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Reserved */
   IFX_uint16_t Res02 : 14;
   /** SRA Event */
   IFX_uint16_t SRA_OK : 1;
   /** SOS Event (VDSL only) */
   IFX_uint16_t SOS_OK : 1;
#else
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** SOS Event (VDSL only) */
   IFX_uint16_t SOS_OK : 1;
   /** SRA Event */
   IFX_uint16_t SRA_OK : 1;
   /** Reserved */
   IFX_uint16_t Res02 : 14;
#endif
} __PACKED__ ;


/**
   Enables/Disables the generation of EVENT messages (EVT) for specific upstream OLR
   events. If the corresponding Enable bit for an OLR event is set, then the modem
   firmware will send an autonomous message EVT_OLR_US_EventGet if the OLR event
   happened in the last 1-second interval.
*/
struct CMD_OLR_US_EventConfigure
{
#if MEI_DRV_OS_BYTE_ORDER == MEI_DRV_OS_BIG_ENDIAN
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Reserved */
   IFX_uint16_t Res02 : 14;
   /** SRA Event US, Bit 1 */
   IFX_uint16_t SRA_OK : 1;
   /** SOS Event US , Bit 0 (VDSL only) */
   IFX_uint16_t SOS_OK : 1;
#else
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** SOS Event US , Bit 0 (VDSL only) */
   IFX_uint16_t SOS_OK : 1;
   /** SRA Event US, Bit 1 */
   IFX_uint16_t SRA_OK : 1;
   /** Reserved */
   IFX_uint16_t Res02 : 14;
#endif
} __PACKED__ ;


/**
   Acknoledgement for CMD_OLR_US_EventConfigure.
*/
struct ACK_OLR_US_EventConfigure
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
   Enables/Disables the generation of EVENT messages (EVT) for specific downstream OLR
   events. If the corresponding Enable bit for an OLR event is set, then the modem
   firmware will send an autonomous message EVT_OLR_DS_EventGet if the OLR event
   happened in the last 1-second interval.
*/
struct CMD_OLR_DS_EventConfigure
{
#if MEI_DRV_OS_BYTE_ORDER == MEI_DRV_OS_BIG_ENDIAN
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Reserved */
   IFX_uint16_t Res02 : 14;
   /** SRA Event DS, Bit 1 */
   IFX_uint16_t SRA_OK : 1;
   /** SOS Event DS , Bit 0 (VDSL only) */
   IFX_uint16_t SOS_OK : 1;
#else
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** SOS Event DS , Bit 0 (VDSL only) */
   IFX_uint16_t SOS_OK : 1;
   /** SRA Event DS, Bit 1 */
   IFX_uint16_t SRA_OK : 1;
   /** Reserved */
   IFX_uint16_t Res02 : 14;
#endif
} __PACKED__ ;


/**
   Acknoledgement for CMD_OLR_DS_EventConfigure.
*/
struct ACK_OLR_DS_EventConfigure
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
   Triggers the insertion of corrupt CRCÕs into the transmit path at the VTU-R or
   VTU-C. The message controls the EOC "Diagnostic" command to start and stop the
   corrupt CRC transmission. (Section 11.2.3.2 of G993.2 [5]). The EOC "Diagnostic"
   command is sent by the CO only for triggering corrupt CRCÕs.
*/
struct CMD_CRC_ErrorRequest
{
#if MEI_DRV_OS_BYTE_ORDER == MEI_DRV_OS_BIG_ENDIAN
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Reserved */
   IFX_uint16_t Res02 : 14;
   /** Control for Corrupt RxCRCs (at the CPE) */
   IFX_uint16_t crcRx : 1;
   /** Control for Corrupt TxCRCs (at the CPE) */
   IFX_uint16_t crcTx : 1;
#else
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Control for Corrupt TxCRCs (at the CPE) */
   IFX_uint16_t crcTx : 1;
   /** Control for Corrupt RxCRCs (at the CPE) */
   IFX_uint16_t crcRx : 1;
   /** Reserved */
   IFX_uint16_t Res02 : 14;
#endif
} __PACKED__ ;


/**
   This is the acknowledgement for CMD_CRC_ErrorRequest.
*/
struct ACK_CRC_ErrorRequest
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
   Requests the status of corrupt CRC insertion, initiated by CMD_CRC_ErrorRequest.
*/
struct CMD_CRC_ErrorStatusGet
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
   Provides the status of corrupt CRC insertion. Acknowledgement for
   CMD_CRC_ErrorStatusGet.
*/
struct ACK_CRC_ErrorStatusGet
{
#if MEI_DRV_OS_BYTE_ORDER == MEI_DRV_OS_BIG_ENDIAN
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Reserved */
   IFX_uint16_t Res02 : 14;
   /** Status of Corrupt RxCRCs (at the CPE) */
   IFX_uint16_t crcErrorsRx : 1;
   /** Status of Corrupt TxCRCs */
   IFX_uint16_t crcErrorsTx : 1;
#else
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Status of Corrupt TxCRCs */
   IFX_uint16_t crcErrorsTx : 1;
   /** Status of Corrupt RxCRCs (at the CPE) */
   IFX_uint16_t crcErrorsRx : 1;
   /** Reserved */
   IFX_uint16_t Res02 : 14;
#endif
} __PACKED__ ;


/**
   The message request the compile time of the loaded FW binary.
*/
struct CMD_FwTimeStampGet
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
   Provides the compile time stamp as requested with CMD_FwTimeStampGet.
*/
struct ACK_FwTimeStampGet
{
#if MEI_DRV_OS_BYTE_ORDER == MEI_DRV_OS_BIG_ENDIAN
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Month */
   IFX_uint16_t month : 8;
   /** Day */
   IFX_uint16_t day : 8;
   /** Minute */
   IFX_uint16_t minute : 8;
   /** Hour */
   IFX_uint16_t hour : 8;
#else
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Day */
   IFX_uint16_t day : 8;
   /** Month */
   IFX_uint16_t month : 8;
   /** Hour */
   IFX_uint16_t hour : 8;
   /** Minute */
   IFX_uint16_t minute : 8;
#endif
} __PACKED__ ;


/**
   Without affecting normal operation, certain types of data may be logged to a
   dedicated data buffer to be read out by the management system. This message is used
   to specify the type of data to be logged and the point in time at which to stop
   logging.
*/
struct CMD_DebugTrailControl
{
#if MEI_DRV_OS_BYTE_ORDER == MEI_DRV_OS_BIG_ENDIAN
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** FV0, Fixed Value */
   IFX_uint16_t AutoMsgTrail : 1;
   /** Reserved */
   IFX_uint16_t Res03 : 3;
   /** Showtime Event Logging Control */
   IFX_uint16_t EventsTrail : 1;
   /** Reserved */
   IFX_uint16_t Res05 : 10;
   /** FV0, Fixed Value */
   IFX_uint16_t StatesTrail : 1;
   /** Reserved */
   IFX_uint16_t Res07 : 15;
   /** Showtime Counter Logging Control */
   IFX_uint16_t CounterTrail : 1;
   /** Reserved */
   IFX_uint16_t Res09[5];
   /** Reserved */
   IFX_uint16_t Res10 : 15;
   /** Cyclic Update Control */
   IFX_uint16_t CyclicUpdate : 1;
   /** Reserved */
   IFX_uint16_t Res12 : 8;
   /** Showtime Event Logging: EOC */
   IFX_uint16_t EOC : 1;
   /** Showtime Event Logging: Rx IB Change */
   IFX_uint16_t FE_IB_DELTA : 1;
   /** Showtime Event Logging: FE LOS */
   IFX_uint16_t FE_LOS : 1;
   /** Showtime Event Logging: NE LOS */
   IFX_uint16_t NE_LOS : 1;
   /** Showtime Event Logging: FE FEC */
   IFX_uint16_t FE_FEC : 1;
   /** Showtime Event Logging: NE FEC */
   IFX_uint16_t NE_FEC : 1;
   /** Showtime Event Logging: FE CRC */
   IFX_uint16_t FE_CRC : 1;
   /** Showtime Event Logging: NE CRC */
   IFX_uint16_t NE_CRC : 1;
   /** Reserved */
   IFX_uint16_t Res21 : 8;
   /** Showtime Logging: FE SNRM */
   IFX_uint16_t FE_SNRM : 1;
   /** Showtime Logging: NE SNRM */
   IFX_uint16_t NE_SNRM : 1;
   /** Reserved */
   IFX_uint16_t Res24 : 1;
   /** Reserved */
   IFX_uint16_t Res25 : 1;
   /** Showtime Counter Logging: FE FEC */
   IFX_uint16_t FE_FECcount : 1;
   /** Showtime Counter Logging: NE FEC */
   IFX_uint16_t NE_FECcount : 1;
   /** Showtime Counter Logging: FE CRC */
   IFX_uint16_t FE_CRCcount : 1;
   /** Showtime Counter Logging: NE CRC */
   IFX_uint16_t NE_CRCcount : 1;
#else
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** FV0, Fixed Value */
   IFX_uint16_t StatesTrail : 1;
   /** Reserved */
   IFX_uint16_t Res05 : 10;
   /** Showtime Event Logging Control */
   IFX_uint16_t EventsTrail : 1;
   /** Reserved */
   IFX_uint16_t Res03 : 3;
   /** FV0, Fixed Value */
   IFX_uint16_t AutoMsgTrail : 1;
   /** Showtime Counter Logging Control */
   IFX_uint16_t CounterTrail : 1;
   /** Reserved */
   IFX_uint16_t Res07 : 15;
   /** Reserved */
   IFX_uint16_t Res09[5];
   /** Cyclic Update Control */
   IFX_uint16_t CyclicUpdate : 1;
   /** Reserved */
   IFX_uint16_t Res10 : 15;
   /** Showtime Event Logging: NE CRC */
   IFX_uint16_t NE_CRC : 1;
   /** Showtime Event Logging: FE CRC */
   IFX_uint16_t FE_CRC : 1;
   /** Showtime Event Logging: NE FEC */
   IFX_uint16_t NE_FEC : 1;
   /** Showtime Event Logging: FE FEC */
   IFX_uint16_t FE_FEC : 1;
   /** Showtime Event Logging: NE LOS */
   IFX_uint16_t NE_LOS : 1;
   /** Showtime Event Logging: FE LOS */
   IFX_uint16_t FE_LOS : 1;
   /** Showtime Event Logging: Rx IB Change */
   IFX_uint16_t FE_IB_DELTA : 1;
   /** Showtime Event Logging: EOC */
   IFX_uint16_t EOC : 1;
   /** Reserved */
   IFX_uint16_t Res12 : 8;
   /** Showtime Counter Logging: NE CRC */
   IFX_uint16_t NE_CRCcount : 1;
   /** Showtime Counter Logging: FE CRC */
   IFX_uint16_t FE_CRCcount : 1;
   /** Showtime Counter Logging: NE FEC */
   IFX_uint16_t NE_FECcount : 1;
   /** Showtime Counter Logging: FE FEC */
   IFX_uint16_t FE_FECcount : 1;
   /** Reserved */
   IFX_uint16_t Res25 : 1;
   /** Reserved */
   IFX_uint16_t Res24 : 1;
   /** Showtime Logging: NE SNRM */
   IFX_uint16_t NE_SNRM : 1;
   /** Showtime Logging: FE SNRM */
   IFX_uint16_t FE_SNRM : 1;
   /** Reserved */
   IFX_uint16_t Res21 : 8;
#endif
} __PACKED__ ;


/**
   This is the acknowledgement for CMD_DebugTrailControl.
*/
struct ACK_DebugTrailControl
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
   This message is used to retrieve debug trace data with the debug trace system. The
   debug trace system needs to be actived with CMD_DebugTrailControl, before this
   message can be used.
*/
struct CMD_RingbufferDataGet
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
   This is the acknowledgement for CMD_RingbufferDataGet.
*/
struct ACK_RingbufferDataGet
{
#if MEI_DRV_OS_BYTE_ORDER == MEI_DRV_OS_BIG_ENDIAN
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Trace Data from the Ringbuffer */
   IFX_uint16_t Data[128];
#else
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Trace Data from the Ringbuffer */
   IFX_uint16_t Data[128];
#endif
} __PACKED__ ;


/**
   This message is used to retrieve the status of the debug trace system. The debug
   trace system needs to be actived with CMD_DebugTrailControl, before this message can
   be used.
*/
struct CMD_RingbufferStatusGet
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
   Provides the Debug Trail Status requested by CMD_RingbufferStatusGet.
   The Debug Trail Index, Buffer Size, and Wrap Count are used to determine the
   location of valid data within the Debug Buffer to retrieve them with
   CMD_RingbufferDataGet.
   Note: See example below.
*/
struct ACK_RingbufferStatusGet
{
#if MEI_DRV_OS_BYTE_ORDER == MEI_DRV_OS_BIG_ENDIAN
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Index */
   IFX_uint16_t rbIndex;
   /** Buffer Size */
   IFX_uint16_t bufSize;
   /** Wrap Count */
   IFX_uint16_t wrapCnt;
#else
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Index */
   IFX_uint16_t rbIndex;
   /** Buffer Size */
   IFX_uint16_t bufSize;
   /** Wrap Count */
   IFX_uint16_t wrapCnt;
#endif
} __PACKED__ ;


/**
   Configures the parameters for single-ended line testing (SELT).
*/
struct CMD_SELT_Configure
{
#if MEI_DRV_OS_BYTE_ORDER == MEI_DRV_OS_BIG_ENDIAN
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Reserved */
   IFX_uint16_t Res02 : 13;
   /** UER Format Control */
   IFX_uint16_t SELT2 : 1;
   /** UER Control */
   IFX_uint16_t SELT1 : 1;
   /** QLN Control */
   IFX_uint16_t SELT0 : 1;
   /** Initial magnitude */
   IFX_uint16_t toneLevel;
   /** Number of Frames for QLN */
   IFX_uint16_t avgNum_QLN;
   /** Number of Frames for UER */
   IFX_uint16_t avgNum_UER;
   /** First UER Tone */
   IFX_uint16_t tone1st_UER;
   /** Last UER Tone */
   IFX_uint16_t toneLast_UER;
   /** FV1, Fixed Value, corresponding to 4 kHz. */
   IFX_uint16_t UER_FreqSpacing;
   /** SELT Version Tag */
   IFX_uint16_t versionTag;
   /** First QLNTone */
   IFX_uint16_t tone1st_QLN;
   /** Last QLN Tone */
   IFX_uint16_t toneLast_QLN;
   /** FV1, Fixed Value, corresponding to 4 kHz. */
   IFX_uint16_t QLN_FreqSpacing;
#else
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** QLN Control */
   IFX_uint16_t SELT0 : 1;
   /** UER Control */
   IFX_uint16_t SELT1 : 1;
   /** UER Format Control */
   IFX_uint16_t SELT2 : 1;
   /** Reserved */
   IFX_uint16_t Res02 : 13;
   /** Initial magnitude */
   IFX_uint16_t toneLevel;
   /** Number of Frames for QLN */
   IFX_uint16_t avgNum_QLN;
   /** Number of Frames for UER */
   IFX_uint16_t avgNum_UER;
   /** First UER Tone */
   IFX_uint16_t tone1st_UER;
   /** Last UER Tone */
   IFX_uint16_t toneLast_UER;
   /** FV1, Fixed Value, corresponding to 4 kHz. */
   IFX_uint16_t UER_FreqSpacing;
   /** SELT Version Tag */
   IFX_uint16_t versionTag;
   /** First QLNTone */
   IFX_uint16_t tone1st_QLN;
   /** Last QLN Tone */
   IFX_uint16_t toneLast_QLN;
   /** FV1, Fixed Value, corresponding to 4 kHz. */
   IFX_uint16_t QLN_FreqSpacing;
#endif
} __PACKED__ ;


/**
   Acknowledgement for CMD_SELT_Configure.
*/
struct ACK_SELT_Configure
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
   The message requests the results of the quiet-line noise (QLN) measurement which is
   part of the SELT test, if enabled with CMD_SELT_Configure.
*/
struct CMD_SELT_QLN_Get
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
   Returns information about the QLN per subcarrier resulting from the SELT test.
*/
struct ACK_SELT_QLN_Get
{
#if MEI_DRV_OS_BYTE_ORDER == MEI_DRV_OS_BIG_ENDIAN
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** QLNps */
   IFX_uint16_t QLNps[128];
#else
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** QLNps */
   IFX_uint16_t QLNps[128];
#endif
} __PACKED__ ;


/**
   The message requests the results of the Uncalibrated Echo Response (UER) measurement
   which is part of the SELT test, if enabled with CMD_SELT_Configure.
*/
struct CMD_SELT_UER_Get
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
   Returns information about the UER per subcarrier resulting from the SELT test.
*/
struct ACK_SELT_UER_Get
{
#if MEI_DRV_OS_BYTE_ORDER == MEI_DRV_OS_BIG_ENDIAN
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** UERps */
   VNX_UER_t UERps[32];
#else
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** UERps */
   VNX_UER_t UERps[32];
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

