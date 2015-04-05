/******************************************************************************

                               Copyright (c) 2011
                            Lantiq Deutschland GmbH
                     Am Campeon 3; 85579 Neubiberg, Germany

  For licensing information, see the file 'LICENSE' in the root folder of
  this software module.

******************************************************************************/


#ifndef _VDSL2_FWDES_CONFIGPMD_H_
#define _VDSL2_FWDES_CONFIGPMD_H_

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

/** @defgroup _VDSL2_FWDES_CONFIGPMD_ Messages Overview
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
#define  ACK_ModemFSM_StateGet_RESET_STATE  0
#define  ACK_ModemFSM_StateGet_READY_STATE  1
#define  ACK_ModemFSM_StateGet_FAIL_STATE  2
#define  ACK_ModemFSM_StateGet_DIAG_COMPLETE_STATE  3
#define  ACK_ModemFSM_StateGet_GHS_STATE  5
#define  ACK_ModemFSM_StateGet_FULLINIT_STATE  6
#define  ACK_ModemFSM_StateGet_STEADY_STATE_TC_NOSYNC  7
#define  ACK_ModemFSM_StateGet_STEADY_STATE_TC_SYNC  8
#define  ACK_ModemFSM_StateGet_DIAGMODE_STATE  9
#define  ACK_ModemFSM_StateGet_SELT_STATE  12
#define  ACK_ModemFSM_StateGet_SELT_COMPLETE_STATE  13
#define  ACK_ModemFSM_StateGet_TEST_STATE  240
#define  ACK_ModemFSM_StateGet_L0  0
#define  ACK_ModemFSM_StateGet_L2  2
#define  ACK_ModemFSM_StateGet_L3  3
#define  EVT_ModemFSM_StateGet_RESET_STATE  0
#define  EVT_ModemFSM_StateGet_READY_STATE  1
#define  EVT_ModemFSM_StateGet_FAIL_STATE  2
#define  EVT_ModemFSM_StateGet_DIAG_COMPLETE_STATE  3
#define  EVT_ModemFSM_StateGet_GHS_STATE  5
#define  EVT_ModemFSM_StateGet_FULLINIT_STATE  6
#define  EVT_ModemFSM_StateGet_STEADY_STATE_TC_NOSYNC  7
#define  EVT_ModemFSM_StateGet_STEADY_STATE_TC_SYNC  8
#define  EVT_ModemFSM_StateGet_DIAGMODE_STATE  9
#define  EVT_ModemFSM_StateGet_SELT_STATE  12
#define  EVT_ModemFSM_StateGet_SELT_COMPLETE_STATE  13
#define  EVT_ModemFSM_StateGet_L0  0
#define  EVT_ModemFSM_StateGet_L2  2
#define  EVT_ModemFSM_StateGet_L3  3
#define  EVT_ModemReady_MRERR_OK  0x00
#define  EVT_ModemReady_MRERR_LVDS_SYNC  0x01
#define  EVT_ModemReady_MRWARN_OK  0x00
#define  EVT_ModemReady_MRWARN_LVDS_CRC  0x01
#define  CMD_ModemFSM_StateSet_LINKRES  0
#define  CMD_ModemFSM_StateSet_LINKINI  2
#define  CMD_ModemFSM_StateSet_TESTSTA  8
#define  CMD_ModemFSM_StateSet_SELTINI  9
#define  CMD_DSL_ModeModify_VDSL  0x0
#define  CMD_DSL_ModeModify_ADSL  0x1
#define  ALM_ModemFSM_FailReasonGet_S_OK  0x00
#define  ALM_ModemFSM_FailReasonGet_S_CODESWAP  0x01
#define  ALM_ModemFSM_FailReasonGet_S_PSDCONFIG  0x02
#define  ALM_ModemFSM_FailReasonGet_S_MINRATE_US  0x03
#define  ALM_ModemFSM_FailReasonGet_S_MINRATE_DS  0x04
#define  ALM_ModemFSM_FailReasonGet_S_INIT  0x05
#define  ALM_ModemFSM_FailReasonGet_S_MODE  0x06
#define  ALM_ModemFSM_FailReasonGet_S_HW_MODE  0x07
#define  ALM_ModemFSM_FailReasonGet_S_UPBO  0x08
#define  ALM_ModemFSM_FailReasonGet_S_TIMEOUT  0x09
#define  ALM_ModemFSM_FailReasonGet_S_XDSL_MODE  0x0A
#define  ALM_ModemFSM_FailReasonGet_S_LOS  0x10
#define  ALM_ModemFSM_FailReasonGet_S_LOF  0x11
#define  ALM_ModemFSM_FailReasonGet_S_LPR  0x12
#define  ALM_ModemFSM_FailReasonGet_S_LOM  0x13
#define  ALM_ModemFSM_FailReasonGet_S_LOL  0x14
#define  ALM_ModemFSM_FailReasonGet_S_ESE  0x15
#define  ALM_ModemFSM_FailReasonGet_S_32CRC  0x17
#define  ALM_ModemFSM_FailReasonGet_S_OOS0  0x18
#define  ALM_ModemFSM_FailReasonGet_S_LCD0  0x20
#define  ALM_ModemFSM_FailReasonGet_S_NCD0  0x22
#define  ALM_ModemFSM_FailReasonGet_E_OK  0x00
#define  ALM_ModemFSM_FailReasonGet_E_CONFIG  0x01
#define  ALM_ModemFSM_FailReasonGet_E_NOTFEASIBLE  0x02
#define  ALM_ModemFSM_FailReasonGet_E_COMM  0x03
#define  ALM_ModemFSM_FailReasonGet_E_COMMCRC  0x04
#define  ALM_ModemFSM_FailReasonGet_E_NOPEER  0x05
#define  ALM_ModemFSM_FailReasonGet_E_CHIPSET  0x06
#define  ALM_ModemFSM_FailReasonGet_E_UNKNOWN  0x07
#define  ALM_ModemFSM_FailReasonGet_E_RESERVED  0x08
#define  ALM_ModemFSM_FailReasonGet_E_SHOWTIME_NE  0x10
#define  ALM_ModemFSM_FailReasonGet_E_SHOWTIME_FE  0x11
#define  ACK_ModemFSM_FailReasonGet_S_OK  0x00
#define  ACK_ModemFSM_FailReasonGet_S_CODESWAP  0x01
#define  ACK_ModemFSM_FailReasonGet_S_PSDCONFIG  0x02
#define  ACK_ModemFSM_FailReasonGet_S_MINRATE_US  0x03
#define  ACK_ModemFSM_FailReasonGet_S_MINRATE_DS  0x04
#define  ACK_ModemFSM_FailReasonGet_S_INIT  0x05
#define  ACK_ModemFSM_FailReasonGet_S_MODE  0x06
#define  ACK_ModemFSM_FailReasonGet_S_HW_MODE  0x07
#define  ACK_ModemFSM_FailReasonGet_S_UPBO  0x08
#define  ACK_ModemFSM_FailReasonGet_S_TIMEOUT  0x09
#define  ACK_ModemFSM_FailReasonGet_S_XDSL_MODE  0x0A
#define  ACK_ModemFSM_FailReasonGet_S_LOS  0x10
#define  ACK_ModemFSM_FailReasonGet_S_LOF  0x11
#define  ACK_ModemFSM_FailReasonGet_S_LPR  0x12
#define  ACK_ModemFSM_FailReasonGet_S_LOM  0x13
#define  ACK_ModemFSM_FailReasonGet_S_LOL  0x14
#define  ACK_ModemFSM_FailReasonGet_S_ESE  0x15
#define  ACK_ModemFSM_FailReasonGet_S_32CRC  0x17
#define  ACK_ModemFSM_FailReasonGet_S_OOS0  0x18
#define  ACK_ModemFSM_FailReasonGet_S_LCD0  0x20
#define  ACK_ModemFSM_FailReasonGet_S_NCD0  0x22
#define  ACK_ModemFSM_FailReasonGet_E_OK  0x00
#define  ACK_ModemFSM_FailReasonGet_E_CONFIG  0x01
#define  ACK_ModemFSM_FailReasonGet_E_NOTFEASIBLE  0x02
#define  ACK_ModemFSM_FailReasonGet_E_COMM  0x03
#define  ACK_ModemFSM_FailReasonGet_E_COMMCRC  0x04
#define  ACK_ModemFSM_FailReasonGet_E_NOPEER  0x05
#define  ACK_ModemFSM_FailReasonGet_E_CHIPSET  0x06
#define  ACK_ModemFSM_FailReasonGet_E_UNKNOWN  0x07
#define  ACK_ModemFSM_FailReasonGet_E_RESERVED  0x08
#define  ACK_ModemFSM_FailReasonGet_E_SHOWTIME_NE  0x10
#define  ACK_ModemFSM_FailReasonGet_E_SHOWTIME_FE  0x11
#define  ACK_TxL3RequestStatusGet_L3PENDING  0
#define  ACK_TxL3RequestStatusGet_L3REJECTED  1
#define  ACK_TxL3RequestStatusGet_L3ACCEPTED  2
#define  ACK_TxL3RequestStatusGet_L3FAIL  3
#define  ACK_TxL3ReqFailReasonGet_TIMEOUT  9
#define  ACK_FW_ImageInfoGet_STANDALONE  0x0
#define  ACK_FW_ImageInfoGet_COMBINED  0x1
#define  ACK_FW_ImageInfoGet_VDSL_FW  0x0
#define  ACK_FW_ImageInfoGet_ADSL_FW  0x1
#define  ACK_FW_ImageInfoGet_CO_FW  0x0
#define  ACK_FW_ImageInfoGet_CPE_FW  0x1
#define  CMD_BearerCh0_DS_Set_MAX_BER3  0
#define  CMD_BearerCh0_DS_Set_MAX_BER5  1
#define  CMD_BearerCh0_DS_Set_MAX_BER7  2
#define  CMD_BearerCh0_US_Set_MAX_BER3  0
#define  CMD_BearerCh0_US_Set_MAX_BER5  1
#define  CMD_BearerCh0_US_Set_MAX_BER7  2
#define  CMD_AlgorithmControlSet_MAXPSD  0x0
#define  CMD_AlgorithmControlSet_PSDREF  0x1
#define  CMD_AlgorithmControlSet_IFFT_VDSL  0x0
#define  CMD_AlgorithmControlSet_IFFT_ADSL_PP  0x1
#define  CMD_AlgorithmControlSet_IFFT_ADSL_P  0x2
#define  CMD_AlgorithmControlSet_RETRAIN_IFFT_ADSL_PP  0xE
#define  CMD_AlgorithmControlSet_AUTOSELECT  0xF
#define  CMD_DigitalFilterSet_POTS  0
#define  CMD_DigitalFilterSet_ISDN  1
#define  CMD_DigitalFilterSet_POTS_2  2
#define  CMD_DigitalFilterSet_POTS_3  3
#define  CMD_HybridSelect_CO_AD_138_17_20V_ITU  0x0001
#define  CMD_HybridSelect_CO_AD_25_17_20V_ITU   0x0002
#define  CMD_HybridSelect_CO_AD_138_17_24V_ITU  0x0004
#define  CMD_HybridSelect_CO_AD_25_17_24V_ITU   0x0005
#define  CMD_HybridSelect_CO_AD_JAP_138_30_20V_ITU  0x0003
#define  CMD_HybridSelect_CO_AD_25_30_20V_ITU   0x0006
#define  CMD_HybridSelect_CO_AD_25_30_24V_ITU   0x0007
#define  CMD_HybridSelect_CO_AD_138_30_20V_ITU  0x0008
#define  CMD_HybridSelect_CO_AD_138_30_24V_ITU  0x0009
#define  CMD_HybridSelect_CO_AD_138_17_20V_ITU_R1  0x000A
#define  CMD_HybridSelect_HYB_AD1_138_17_CPE_R2  0x0010
#define  CMD_HybridSelect_HYB_AD1_138_17_CPE_R1  0x0011
#define  CMD_HybridSelect_HYB_AD1_25_17_CPE   0x0012
#define  CMD_HybridSelect_HYB_AD1_138_30_CPE   0x0013
#define  CMD_HybridSelect_HYB_F1_JAP_30  0x0014
#define  CMD_ACE_FilterSet_EQ  1
#define  CMD_ACE_FilterSet_OFF  2
#define  CMD_ACE_FilterSet_TEST  3
#define  CMD_ACE_FilterSet_ADAPTIVE   4
#define  CMD_Misc_ConfigSet_AVGPOWER  1
/* ----- Constants Definition section (End) ----- */

/** Message ID for CMD_ModemFSM_StateGet */
#define CMD_MODEMFSM_STATEGET 0x0002

/**
   Requests information about the current state of the modem state-machine.
   The command can be sent in all states of the modem state machine (see Figure2).
*/
typedef struct CMD_ModemFSM_StateGet CMD_ModemFSM_StateGet_t;

/** Message ID for ACK_ModemFSM_StateGet */
#define ACK_MODEMFSM_STATEGET 0x0002

/**
   Returns information about the current state of the modem state-machine.
*/
typedef struct ACK_ModemFSM_StateGet ACK_ModemFSM_StateGet_t;

/** Message ID for EVT_ModemFSM_StateGet */
#define EVT_MODEMFSM_STATEGET 0x0002

/**
   Returns information about the current state of the modem state-machine. This message
   is sent autonomously, if the modem enters a new state and reporting is enabled for
   that state (see CMD_ModemFSM_EventConfigure).
*/
typedef struct EVT_ModemFSM_StateGet EVT_ModemFSM_StateGet_t;

/** Message ID for EVT_ModemReady */
#define EVT_MODEMREADY 0xFF02

/**
   Autonomous message indicating that the modem online code was reached and that
   initialization was completed. The management entity may not perform any
   query-response messaging until the EVT_ModemReady message is received. Its
   generation cannot be disabled. If it is not received this indicates a problem,
   possibly with the boot sequence. If the message is received, it contains a result
   code that may also indicate that an error was detected by the firmware during
   initialization.
*/
typedef struct EVT_ModemReady EVT_ModemReady_t;

/** Message ID for CMD_ModemFSM_StateSet */
#define CMD_MODEMFSM_STATESET 0x0041

/**
   Controls state transitions of the modem state-machine.
*/
typedef struct CMD_ModemFSM_StateSet CMD_ModemFSM_StateSet_t;

/** Message ID for ACK_ModemFSM_StateSet */
#define ACK_MODEMFSM_STATESET 0x0041

/**
   Acknowledgement for message CMD_ModemFSM_StateSet
*/
typedef struct ACK_ModemFSM_StateSet ACK_ModemFSM_StateSet_t;

/** Message ID for CMD_DSL_ModeModify */
#define CMD_DSL_MODEMODIFY 0x0141

/**
   Changes the DSL mode of a line between VDSL and ADSL. After applying this message, a
   reboot with the selected FW takes place. In VINAX V1.X, the command is valid in boot
   modes 0x8 and 0x9 only and ignored otherwise.
   Note: This message needs to be applied for changing the DSL mode only, not for
   every line initialization.
   Note: VINAX V1.X only: Before applying this message in VINAX V1.X, the device
   driver writes the wanted DSL mode to a DFE HW register which is evaluated
   during the boot process. (PDSCR register, Bit PYPRG1, ’’0’’=VDSL)
   Note: The parameter "DLS Mode Boot Selection" is needed for a common ADSL/VDSL
   FW. Otherwise, this parameter is not evaluated.
*/
typedef struct CMD_DSL_ModeModify CMD_DSL_ModeModify_t;

/** Message ID for ACK_DSL_ModeModify */
#define ACK_DSL_MODEMODIFY 0x0141

/**
   Acknowledgement for message CMD_DSL_ModeModify
*/
typedef struct ACK_DSL_ModeModify ACK_DSL_ModeModify_t;

/** Message ID for ALM_ModemFSM_FailReasonGet */
#define ALM_MODEMFSM_FAILREASONGET 0x0502

/**
   Reports failure information after entering FAIL state. This message is sent
   autonomously without host request after entrance into FAIL was indicated by
   EVT_ModemFSM_StateGet. Both messages are generated only if enabled with
   CMD_ModemFSM_EventConfigure (common Bit E8 "FAIL").
*/
typedef struct ALM_ModemFSM_FailReasonGet ALM_ModemFSM_FailReasonGet_t;

/** Message ID for CMD_ModemFSM_FailReasonGet */
#define CMD_MODEMFSM_FAILREASONGET 0x0502

/**
   Requests failure information after entering FAIL state.
*/
typedef struct CMD_ModemFSM_FailReasonGet CMD_ModemFSM_FailReasonGet_t;

/** Message ID for ACK_ModemFSM_FailReasonGet */
#define ACK_MODEMFSM_FAILREASONGET 0x0502

/**
   Returns failure information after entering FAIL state.
*/
typedef struct ACK_ModemFSM_FailReasonGet ACK_ModemFSM_FailReasonGet_t;

/** Message ID for CMD_ModemFSM_OptionsSet */
#define CMD_MODEMFSM_OPTIONSSET 0x0449

/**
   Configuration of options for the modem state machine.
*/
typedef struct CMD_ModemFSM_OptionsSet CMD_ModemFSM_OptionsSet_t;

/** Message ID for ACK_ModemFSM_OptionsSet */
#define ACK_MODEMFSM_OPTIONSSET 0x0449

/**
   Acknowledgement to CMD_ModemFSM_OptionsSet (configuration of automatic re-start).
*/
typedef struct ACK_ModemFSM_OptionsSet ACK_ModemFSM_OptionsSet_t;

/** Message ID for CMD_ModemFSM_EventConfigure */
#define CMD_MODEMFSM_EVENTCONFIGURE 0x0049

/**
   Sets options for the modem state-machine. Enables/Disables autonomous messages for
   specific state transitions (EVT_ModemFSM_StateGet). The EVT message is generated
   after entering the particular state listed in the parameter description of the
   enable bits.
*/
typedef struct CMD_ModemFSM_EventConfigure CMD_ModemFSM_EventConfigure_t;

/** Message ID for ACK_ModemFSM_EventConfigure */
#define ACK_MODEMFSM_EVENTCONFIGURE 0x0049

/**
   Acknowledgement for CMD_ModemFSM_EventConfigure. (Enabling/Disabling EVENT messages
   (EVTs) for specific state transitions.)
*/
typedef struct ACK_ModemFSM_EventConfigure ACK_ModemFSM_EventConfigure_t;

/** Message ID for CMD_FailuresNE_AlarmConfigure */
#define CMD_FAILURESNE_ALARMCONFIGURE 0x0149

/**
   Enables/Disables the generation of ALARM messages (ALM) for specific near-end line
   failures. If the corresponding Enable bit for a line failure is set, then the modem
   firmware will send an autonomous message ALM_LineFailureNE_Get if this failure
   occurs.
*/
typedef struct CMD_FailuresNE_AlarmConfigure CMD_FailuresNE_AlarmConfigure_t;

/** Message ID for ACK_FailuresNE_AlarmConfigure */
#define ACK_FAILURESNE_ALARMCONFIGURE 0x0149

/**
   Acknowledgement to CMD_FailuresNE_AlarmConfigure.
*/
typedef struct ACK_FailuresNE_AlarmConfigure ACK_FailuresNE_AlarmConfigure_t;

/** Message ID for CMD_FailuresFE_AlarmConfigure */
#define CMD_FAILURESFE_ALARMCONFIGURE 0x0249

/**
   Enables/Disables the generation of ALARM messages (ALM) for specific far-end line
   failures. If the corresponding Enable bit for a line failure is set, then the modem
   firmware will send an autonomous message ALM_LineFailureFE_Get if this failure
   occurs.
*/
typedef struct CMD_FailuresFE_AlarmConfigure CMD_FailuresFE_AlarmConfigure_t;

/** Message ID for ACK_FailuresFE_AlarmConfigure */
#define ACK_FAILURESFE_ALARMCONFIGURE 0x0249

/**
   Acknowledgement to CMD_FailuresFE_AlarmConfigure.
*/
typedef struct ACK_FailuresFE_AlarmConfigure ACK_FailuresFE_AlarmConfigure_t;

/** Message ID for CMD_ReInitNE_Configure */
#define CMD_REINITNE_CONFIGURE 0x0549

/**
   Configures re-initialization triggers for near-end failure conditions in modem state
   STEADY STATE transmission (see Figure1). This command is accepted in RESET state
   only.
*/
typedef struct CMD_ReInitNE_Configure CMD_ReInitNE_Configure_t;

/** Message ID for ACK_ReInitNE_Configure */
#define ACK_REINITNE_CONFIGURE 0x0549

/**
   Acknowledgment to CMD_ReInitNE_Configure (Configuration of re-initialization
   triggers for near-end failures).
*/
typedef struct ACK_ReInitNE_Configure ACK_ReInitNE_Configure_t;

/** Message ID for CMD_ReInitFE_Configure */
#define CMD_REINITFE_CONFIGURE 0x0649

/**
   Configures Re-initialization triggers for Far-End failure conditions in modem state
   STEADY STATE.
*/
typedef struct CMD_ReInitFE_Configure CMD_ReInitFE_Configure_t;

/** Message ID for ACK_ReInitFE_Configure */
#define ACK_REINITFE_CONFIGURE 0x0649

/**
   Acknowledgment to CMD_ReInitFE_Configure (Configuration of Re-initialization
   triggers for far-end failures).
*/
typedef struct ACK_ReInitFE_Configure ACK_ReInitFE_Configure_t;

/** Message ID for CMD_L3ShutdownRequest */
#define CMD_L3SHUTDOWNREQUEST 0x0341

/**
   Triggers the sending of an L3 orderly shutdown request to the remote side.
   If applied at the CO and accepted by the CPE, the following happens: CO-FW itself
   forces L3 entry transitioning to RESET state. The initiator of the L3 entry (here
   CO) shall decide when to go out there as well.
   If applied at the CPE and accepted by the CO, the following shall happen: Not the FW
   but the CPE-Host forces L3 entry with transition to RESET state by applying
   CMD_ModemFSM_StateGet.
   Note: Different behaviour for the CPE is required because first the ADSL-CPE host
   is not informed autonomously and second some important FSM transitions like
   autorestart happen under explicite host control.
*/
typedef struct CMD_L3ShutdownRequest CMD_L3ShutdownRequest_t;

/** Message ID for ACK_L3ShutdownRequest */
#define ACK_L3SHUTDOWNREQUEST 0x0341

/**
   Acknowledgement for CMD_L3ShutdownRequest.
*/
typedef struct ACK_L3ShutdownRequest ACK_L3ShutdownRequest_t;

/** Message ID for CMD_RxL3RequestStatusGet */
#define CMD_RXL3REQUESTSTATUSGET 0x0402

/**
   Requests information about L3 orderly shutdown requests initiated from the remote
   side.
   Applying CMD_RxL3RequestStatusGet allows the host to determine whether a near-end
   LOS or LOM failure is due to an L3 shutdown or an unexpected line failure.
*/
typedef struct CMD_RxL3RequestStatusGet CMD_RxL3RequestStatusGet_t;

/** Message ID for ACK_RxL3RequestStatusGet */
#define ACK_RXL3REQUESTSTATUSGET 0x0402

/**
   Acknowledgement for CMD_RxL3RequestStatusGet.
   As long as the modem is in L0 (Showtime), an ATU-R will automatically respond to any
   L3 request from the ATU-C by sending an accept message.  If the ATU-R is in L2 mode
   when it receives the request, it will send a reject message. Upon receiving an
   acceptance, the remote side should enter L3 state and shut off its transmitter.
*/
typedef struct ACK_RxL3RequestStatusGet ACK_RxL3RequestStatusGet_t;

/** Message ID for CMD_TxL3RequestStatusGet */
#define CMD_TXL3REQUESTSTATUSGET 0x1402

/**
   Requests the status of a near-end initiated L3 shutdown request. If the remote side
   accepted the request, in case of an ADSL-CPE the host will force L3 entry using
   CMD_ModemFSM_StateSet. (In case of an ADSL-CO the FW itself will force L3 entry
   after getting the acceptance and transition to RESET state informing the host with
   the autonomous EVT_ModemFSM_StateGet.)
*/
typedef struct CMD_TxL3RequestStatusGet CMD_TxL3RequestStatusGet_t;

/** Message ID for ACK_TxL3RequestStatusGet */
#define ACK_TXL3REQUESTSTATUSGET 0x1402

/**
   Acknowledgement for CMD_TxL3RequestStatusGet.
*/
typedef struct ACK_TxL3RequestStatusGet ACK_TxL3RequestStatusGet_t;

/** Message ID for CMD_TxL3ReqFailReasonGet */
#define CMD_TXL3REQFAILREASONGET 0x1502

/**
   Requests the fail reason of a failed near-end initiated L3 request. (see also
   ACK_TxL3RequestStatusGet)
*/
typedef struct CMD_TxL3ReqFailReasonGet CMD_TxL3ReqFailReasonGet_t;

/** Message ID for ACK_TxL3ReqFailReasonGet */
#define ACK_TXL3REQFAILREASONGET 0x1502

/**
   Reports the fail reason of a near-end initiated L3 request, as response to
   CMD_TxL3ReqFailReasonGet.
*/
typedef struct ACK_TxL3ReqFailReasonGet ACK_TxL3ReqFailReasonGet_t;

/** Message ID for CMD_FW_ImageInfoGet */
#define CMD_FW_IMAGEINFOGET 0xD103

/**
   Requests information about the loaded FW image. This info is used e.g. for swapping
   between ADSL and VDSL.
*/
typedef struct CMD_FW_ImageInfoGet CMD_FW_ImageInfoGet_t;

/** Message ID for ACK_FW_ImageInfoGet */
#define ACK_FW_IMAGEINFOGET 0xD103

/**
   Provides the information about the FW image requested by ACK_FW_ImageInfoGet
*/
typedef struct ACK_FW_ImageInfoGet ACK_FW_ImageInfoGet_t;

/** Message ID for CMD_XTSE_Configure */
#define CMD_XTSE_CONFIGURE 0x0045

/**
   Configuration of the VTU Transmission System Enabling (XTSE).Configures the
   transmission system coding types to be supported on the line (VDSL flavour and annex
   support).
   (References: Section 7.3.1.1.1 of G.997.1 and G.994.1 Amd4 [10] Tables "Standard
   information field – SPar(1) coding")
*/
typedef struct CMD_XTSE_Configure CMD_XTSE_Configure_t;

/** Message ID for ACK_XTSE_Configure */
#define ACK_XTSE_CONFIGURE 0x0045

/**
   Acknowledgement for message CMD_XTSE_Configure.
*/
typedef struct ACK_XTSE_Configure ACK_XTSE_Configure_t;

/** Message ID for CMD_MultimodePrioSet */
#define CMD_MULTIMODEPRIOSET 0x0145

/**
   The message defines priorities for the various flavours/annexes. Now it is for ADSL
   mode only and covers the ADSL1/2/2+ annexes contained as XTSE bits in
   CMD_XTSE_Configure, except T1.413 (see Note 2). Currently as a first step with the
   additional limitation that only one Annex can be enabled for each flavour ADSL1,
   ADSL2, ADSL2+ in CMD_XTSE_Configure and only these get assigned priorities in
   CMD_MultimodePrioSet. The priority numbering starts from 1 (=highest priority).
   Default value for all is the special value FFFFH meaning "no priority assigned".
   Note: Prioritization between VDSL and ADSL is done at the level of the DSL-API.
   Note: T1.413 usage is only controlled by CMD_XTSE_Configure. The logic is to
   always favour GHS over T1.413 if both CO and CPE sides support it.
   Otherwise T1.413 is selected.
*/
typedef struct CMD_MultimodePrioSet CMD_MultimodePrioSet_t;

/** Message ID for ACK_MultimodePrioSet */
#define ACK_MULTIMODEPRIOSET 0x0145

/**
   Acknowledgement for message CMD_MultimodePrioSet.
*/
typedef struct ACK_MultimodePrioSet ACK_MultimodePrioSet_t;

/** Message ID for CMD_BandControl_DS_Set */
#define CMD_BANDCONTROL_DS_SET 0x2448

/**
   Controls the downstream band usage.
*/
typedef struct CMD_BandControl_DS_Set CMD_BandControl_DS_Set_t;

/** Message ID for ACK_BandControl_DS_Set */
#define ACK_BANDCONTROL_DS_SET 0x2448

/**
   Acknowledgement for message CMD_BandControl_DS_Set.
*/
typedef struct ACK_BandControl_DS_Set ACK_BandControl_DS_Set_t;

/** Message ID for CMD_BandControl_US_Set */
#define CMD_BANDCONTROL_US_SET 0x2548

/**
   Controls the upstream band usage.
   For CO side only, if used to configure normal modem operation in state RESET (and
   not for DMTscope tests). Then the data is transmitted from CO to the CPE during
   initialization (in GHS and FULL_INITIALIZATION state).
   If used for DMTscope tests without handshake and training phases it must be applied
   at the CPE directly.
*/
typedef struct CMD_BandControl_US_Set CMD_BandControl_US_Set_t;

/** Message ID for ACK_BandControl_US_Set */
#define ACK_BANDCONTROL_US_SET 0x2548

/**
   Acknowledgement for message CMD_BandControl_US_Set.
*/
typedef struct ACK_BandControl_US_Set ACK_BandControl_US_Set_t;

/** Message ID for CMD_RFI_BandControlSet */
#define CMD_RFI_BANDCONTROLSET 0x2B48

/**
   Sets the RFI bands to be notched out in the PSD.
   To delete all already configured RFI bands, apply the message with NumRfiBands=1 and
   RfiBand=(0,0).
   (Chapter 7.3.1.2.10 of G.997.1 [11])
*/
typedef struct CMD_RFI_BandControlSet CMD_RFI_BandControlSet_t;

/** Message ID for ACK_RFI_BandControlSet */
#define ACK_RFI_BANDCONTROLSET 0x2B48

/**
   Acknowledgement for message CMD_RFI_BandControlSet.
*/
typedef struct ACK_RFI_BandControlSet ACK_RFI_BandControlSet_t;

/** Message ID for CMD_OH_RateSet */
#define CMD_OH_RATESET 0x0448

/**
   Configures the minimum rate of the message based overhead. (Section 7.3.1.5 of
   G.997.1)
   For VDSL1, the minimum overhead rate refers to the EOC overhead rate. In ADSL mode,
   the message is applicable only for ADSL2/2+.
*/
typedef struct CMD_OH_RateSet CMD_OH_RateSet_t;

/** Message ID for ACK_OH_RateSet */
#define ACK_OH_RATESET 0x0448

/**
   Acknowledgement for message CMD_OH_RateSet.
*/
typedef struct ACK_OH_RateSet ACK_OH_RateSet_t;

/** Message ID for CMD_ADSL_WindowingCoeffSet */
#define CMD_ADSL_WINDOWINGCOEFFSET 0x0E4D

/**
   The command configures the windowing for ADSL2+ by setting IFFT windowing
   coefficients in the format of the C-MSG1 message of G.992.5. Only effective if
   "windowing" was enabled with CMD_AlgorithmControlSet.
*/
typedef struct CMD_ADSL_WindowingCoeffSet CMD_ADSL_WindowingCoeffSet_t;

/** Message ID for ACK_ADSL_WindowingCoeffSet */
#define ACK_ADSL_WINDOWINGCOEFFSET 0x0E4D

/**
   Acknowledgement for CMD_ADSL_WindowingCoeffSet.
*/
typedef struct ACK_ADSL_WindowingCoeffSet ACK_ADSL_WindowingCoeffSet_t;

/** Message ID for CMD_PSD_Set */
#define CMD_PSD_SET 0x2348

/**
   Configuration of PSD and Power parameters in VDSL and ADSL.
   Attention: Values starting with Parameter 12 are for ADSL multiple Annex
   support. They are valid only if enabled by the special value FFFFH in
   Parameter 2.
   For CO side only unless used for DMTscope tests! If used to configure normal modem
   operation in state RESET (and not for DMTscope tests), the data is transmitted from
   CO to the CPE during initialization. If used for DMTscope tests without handshake
   and training phases it is applicable for both sides.
*/
typedef struct CMD_PSD_Set CMD_PSD_Set_t;

/** Message ID for ACK_PSD_Set */
#define ACK_PSD_SET 0x2348

/**
   For CO side only unless used for DMTscope tests!
   Acknowledgement for the message CMD_PSD_Set.
*/
typedef struct ACK_PSD_Set ACK_PSD_Set_t;

/** Message ID for CMD_ADSL_AuxPSD_Set */
#define CMD_ADSL_AUXPSD_SET 0x0F4D

/**
   Temporary ADSL message!
   This message can be used to adjust the downstream Tx power level precisely with a
   fine granularity within a range of -1 dB to +1 dB. It is to be applied in addition
   (afterwards) to CMD_PSD_Set as long as the MAXNOMPSDds does not reach the required
   precision in the ADSL CO FW.
   To adjust the downstream power level, all six values need to be changed
   simultaneously with the same factor as described below, otherwise the TX power level
   will not be changed consistently.The adjustment by a delta of "X" dB with 0 < |X| £
   1 is done as follows:factor= 10exp(X/20)Updated values of TxAdjust =
   round(orginal_value * factor)
   The current TxAdjust values (=orginal_value) can be read using CMD_ADSL_AuxPSD_Get.
*/
typedef struct CMD_ADSL_AuxPSD_Set CMD_ADSL_AuxPSD_Set_t;

/** Message ID for ACK_ADSL_AuxPSD_Set */
#define ACK_ADSL_AUXPSD_SET 0x0F4D

/**
   Acknowledgement for the message CMD_ADSL_AuxPSD_Set.
*/
typedef struct ACK_ADSL_AuxPSD_Set ACK_ADSL_AuxPSD_Set_t;

/** Message ID for CMD_ADSL_AuxPSD_Get */
#define CMD_ADSL_AUXPSD_GET 0x0F0D

/**
   Temporary ADSL message!
   Requests the current downstream Tx power level scaling factors. These values are
   only necessary to calculate the parameters to be written with CMD_ADSL_AuxPSD_Set
   for DS power trimming.
*/
typedef struct CMD_ADSL_AuxPSD_Get CMD_ADSL_AuxPSD_Get_t;

/** Message ID for ACK_ADSL_AuxPSD_Get */
#define ACK_ADSL_AUXPSD_GET 0x0F0D

/**
   Temporary ADSL message!
   Provides the values of the downstream Tx power level scaling factors as requested by
   CMD_ADSL_AuxPSD_Get. Based on these values a power trimming can be done using
   CMD_ADSL_AuxPSD_Set.
*/
typedef struct ACK_ADSL_AuxPSD_Get ACK_ADSL_AuxPSD_Get_t;

/** Message ID for CMD_PSD_BreakpointsTxDS_Set */
#define CMD_PSD_BREAKPOINTSTXDS_SET 0x2648

/**
   Controls the transmit signal at the VTU-O via transmit PSD breakpoints (along with
   the MAXNOMPSD).These PSD breakpoints shape the PSD level relative to the MAXNOMPSD.
   (Chapter 7.3.1.2.9 of G.997.1)
   Note: TxPSDs consisting of more than 42 PSD breakpoints must be written with 2
   messages!
*/
typedef struct CMD_PSD_BreakpointsTxDS_Set CMD_PSD_BreakpointsTxDS_Set_t;

/** Message ID for ACK_PSD_BreakpointsTxDS_Set */
#define ACK_PSD_BREAKPOINTSTXDS_SET 0x2648

/**
   Acknowledgement for the message CMD_PSD_BreakpointsTxDS_Set.
*/
typedef struct ACK_PSD_BreakpointsTxDS_Set ACK_PSD_BreakpointsTxDS_Set_t;

/** Message ID for CMD_PSD_BreakpointsTxUS_Set */
#define CMD_PSD_BREAKPOINTSTXUS_SET 0x2848

/**
   Specifies the maximum upstream transmit PSD by means of breakpoints. Values are set
   at the VTU-O and transferred to the VTU-R in the O-SIGNATURE message (except if used
   for DMTscope). See chapter 12.4.4 in G.993.1 [4] and chapter 12.2.4.2.1 in G.993.2
   [5].
   If used for DMTscope tests without handshake and training phases it must be applied
   at the VTU-R directly.
*/
typedef struct CMD_PSD_BreakpointsTxUS_Set CMD_PSD_BreakpointsTxUS_Set_t;

/** Message ID for ACK_PSD_BreakpointsTxUS_Set */
#define ACK_PSD_BREAKPOINTSTXUS_SET 0x2848

/**
   Acknowledgement for the message CMD_PSD_BreakpointsTxUS_Set.
*/
typedef struct ACK_PSD_BreakpointsTxUS_Set ACK_PSD_BreakpointsTxUS_Set_t;

/** Message ID for CMD_PSD_BreakpointsRxRefUS_Set */
#define CMD_PSD_BREAKPOINTSRXREFUS_SET 0x2748

/**
   For VDSL1 only. In VDSL2 use CMD_PSD_BreakpointsRxRef2US_Set.
   Specifies the Upstream Receive Reference PSD by means of breakpoints. It is used for
   upstream power back-off (UPBO). Values are set at the VTU-O and transferred to the
   VTU-R in the O-SIGNATURE message (See chapter 12.4.4 in G.993.1 [4]).
*/
typedef struct CMD_PSD_BreakpointsRxRefUS_Set CMD_PSD_BreakpointsRxRefUS_Set_t;

/** Message ID for ACK_PSD_BreakpointsRxRefUS_Set */
#define ACK_PSD_BREAKPOINTSRXREFUS_SET 0x2748

/**
   Acknowledgement for the message CMD_PSD_BreakpointsRxRefUS_Set.
*/
typedef struct ACK_PSD_BreakpointsRxRefUS_Set ACK_PSD_BreakpointsRxRefUS_Set_t;

/** Message ID for CMD_PSD_BreakpointsRxRef2US_Set */
#define CMD_PSD_BREAKPOINTSRXREF2US_SET 0x2E48

/**
   Specifies the VDSL2 Upstream Receive Reference PSD (=UPBOPSD) in the (a, b) format
   (Section 7.3.1.2.14 of G997.1). Contains the parameters to compute the reference PSD
   that shall be used for the calculation of upstream power back-off (UPBO). One couple
   of parameters (a, b) is defined per upstream band (except US0). Values are set at
   the VTU-O and transferred to the VTU-R in the O-SIGNATURE message (See chapter
   12.2.4 in G.993.2 [5]).
*/
typedef struct CMD_PSD_BreakpointsRxRef2US_Set CMD_PSD_BreakpointsRxRef2US_Set_t;

/** Message ID for ACK_PSD_BreakpointsRxRef2US_Set */
#define ACK_PSD_BREAKPOINTSRXREF2US_SET 0x2E48

/**
   Acknowledgement for the message CMD_PSD_BreakpointsRxRef2US_Set.
*/
typedef struct ACK_PSD_BreakpointsRxRef2US_Set ACK_PSD_BreakpointsRxRef2US_Set_t;

/** Message ID for CMD_PBO_Control */
#define CMD_PBO_CONTROL 0x3448

/**
   Controls the Upstream Power Back-Off (UPBO) mode of operation. There are 2 modes: an
   "UPBO standard mode" (§ 7.3.1.2.14 of G997.1) and an "UPBO boost mode".
*/
typedef struct CMD_PBO_Control CMD_PBO_Control_t;

/** Message ID for ACK_PBO_Control */
#define ACK_PBO_CONTROL 0x3448

/**
   Acknowledgement for the message CMD_PBO_Control.
*/
typedef struct ACK_PBO_Control ACK_PBO_Control_t;

/** Message ID for CMD_UPBO_KL0Get */
#define CMD_UPBO_KL0GET 0xD603

/**
   Requests the electrical loop length estimate kl0.
*/
typedef struct CMD_UPBO_KL0Get CMD_UPBO_KL0Get_t;

/** Message ID for ACK_UPBO_KL0Get */
#define ACK_UPBO_KL0GET 0xD603

/**
   Delivers the data requested by CMD_UPBO_KL0Get.
   (Section 7.5.1.23 of G.997.1 [11])
*/
typedef struct ACK_UPBO_KL0Get ACK_UPBO_KL0Get_t;

/** Message ID for CMD_PSD_CeilingDS_Set */
#define CMD_PSD_CEILINGDS_SET 0x3848

/**
   Enables for each VDSL2 Profile an adaptive PSD optimization (ceiling) algorithm.
   Currently only required for Profile 8b due to the high transmit power.
*/
typedef struct CMD_PSD_CeilingDS_Set CMD_PSD_CeilingDS_Set_t;

/** Message ID for ACK_PSD_CeilingDS_Set */
#define ACK_PSD_CEILINGDS_SET 0x3848

/**
   Acknowledgement for message CMD_PSD_CeilingDS_Set.
*/
typedef struct ACK_PSD_CeilingDS_Set ACK_PSD_CeilingDS_Set_t;

/** Message ID for CMD_NoiseMarginSet */
#define CMD_NOISEMARGINSET 0x2248

/**
   Configuration of noise margin parameters.
*/
typedef struct CMD_NoiseMarginSet CMD_NoiseMarginSet_t;

/** Message ID for ACK_NoiseMarginSet */
#define ACK_NOISEMARGINSET 0x2248

/**
   Acknowledgement for the message CMD_NoiseMarginSet.
*/
typedef struct ACK_NoiseMarginSet ACK_NoiseMarginSet_t;

/** Message ID for CMD_NoiseMarginDeltaSet */
#define CMD_NOISEMARGINDELTASET 0x1C45

/**
   Configuration of a target noise margin delta, which is added to the target noise
   margin value configured at the CO (and in case of the CPE received from there). The
   resulting value is then taken as target noise margin, e.g. for bit loading.
*/
typedef struct CMD_NoiseMarginDeltaSet CMD_NoiseMarginDeltaSet_t;

/** Message ID for ACK_NoiseMarginDeltaSet */
#define ACK_NOISEMARGINDELTASET 0x1C45

/**
   Acknowledgement for the message CMD_NoiseMarginDeltaSet.
*/
typedef struct ACK_NoiseMarginDeltaSet ACK_NoiseMarginDeltaSet_t;

/** Message ID for CMD_TssiDS_ADSL_Set */
#define CMD_TSSIDS_ADSL_SET 0x044D

/**
   Sets the TSSI breakpoints for PSD shaping in ADSL2+ Annex A/B/I/J in downstream
   direction.
   Note: Not applicable in ADSL1.
   Note: ADSL2 Annex A/B/I/J is configured with CMD_TssiDS_ADSL2ABIJ_Set since FW
   w.3.x.y.z.a.
*/
typedef struct CMD_TssiDS_ADSL_Set CMD_TssiDS_ADSL_Set_t;

/** Message ID for ACK_TssiDS_ADSL_Set */
#define ACK_TSSIDS_ADSL_SET 0x044D

/**
   This is the acknowledgement for CMD_TssiDS_ADSL_Set.
*/
typedef struct ACK_TssiDS_ADSL_Set ACK_TssiDS_ADSL_Set_t;

/** Message ID for CMD_TssiDS_ADSL2ABIJ_Set */
#define CMD_TSSIDS_ADSL2ABIJ_SET 0x144D

/**
   Sets the TSSI breakpoints for PSD shaping for ADSL2 Annex A,B,I,J in downstream
   direction.
   Note: Not applicable in ADSL1.
*/
typedef struct CMD_TssiDS_ADSL2ABIJ_Set CMD_TssiDS_ADSL2ABIJ_Set_t;

/** Message ID for ACK_TssiDS_ADSL2ABIJ_Set */
#define ACK_TSSIDS_ADSL2ABIJ_SET 0x144D

/**
   This is the acknowledgement for CMD_TssiDS_ADSL2ABIJ_Set.
*/
typedef struct ACK_TssiDS_ADSL2ABIJ_Set ACK_TssiDS_ADSL2ABIJ_Set_t;

/** Message ID for CMD_TssiDS_ADSL2M_Set */
#define CMD_TSSIDS_ADSL2M_SET 0x164D

/**
   Sets the TSSI breakpoints for PSD shaping for ADSL in downstream direction. For
   ADSL2 Annex M.
   Note: Not applicable in ADSL1.
*/
typedef struct CMD_TssiDS_ADSL2M_Set CMD_TssiDS_ADSL2M_Set_t;

/** Message ID for ACK_TssiDS_ADSL2M_Set */
#define ACK_TSSIDS_ADSL2M_SET 0x164D

/**
   This is the acknowledgement for CMD_TssiDS_ADSL2M_Set.
*/
typedef struct ACK_TssiDS_ADSL2M_Set ACK_TssiDS_ADSL2M_Set_t;

/** Message ID for CMD_TssiDS_ADSL2pM_Set */
#define CMD_TSSIDS_ADSL2PM_SET 0x184D

/**
   Sets the TSSI breakpoints for PSD shaping in downstream direction for ADSL2+ Annex
   M.
   Note: Not applicable in ADSL1.
*/
typedef struct CMD_TssiDS_ADSL2pM_Set CMD_TssiDS_ADSL2pM_Set_t;

/** Message ID for ACK_TssiDS_ADSL2pM_Set */
#define ACK_TSSIDS_ADSL2PM_SET 0x184D

/**
   This is the acknowledgement for CMD_TssiDS_ADSL2pM_Set.
*/
typedef struct ACK_TssiDS_ADSL2pM_Set ACK_TssiDS_ADSL2pM_Set_t;

/** Message ID for CMD_TssiDS_ADSL2L_Set */
#define CMD_TSSIDS_ADSL2L_SET 0x1A4D

/**
   Sets the TSSI breakpoints for PSD shaping in downstream direction for ADSL2 Annex
   L.
   Note: Not applicable in ADSL1.
*/
typedef struct CMD_TssiDS_ADSL2L_Set CMD_TssiDS_ADSL2L_Set_t;

/** Message ID for ACK_TssiDS_ADSL2L_Set */
#define ACK_TSSIDS_ADSL2L_SET 0x1A4D

/**
   This is the acknowledgement for CMD_TssiDS_ADSL2L_Set.
*/
typedef struct ACK_TssiDS_ADSL2L_Set ACK_TssiDS_ADSL2L_Set_t;

/** Message ID for CMD_TssiUS_ADSL_Set */
#define CMD_TSSIUS_ADSL_SET 0x054D

/**
   Sets the TSSI breakpoints for ADSL2+ Annexes A, B in upstream direction. The US
   TSSI’s are used for RFI notching/carrier masking only.
   Note: Not applicable in ADSL1.
   Note: ADSL2 Annex A/B/L is configured with CMD_TssiUS_ADSL2ABL_Set since FW
   w.3.x.y.z.a.
*/
typedef struct CMD_TssiUS_ADSL_Set CMD_TssiUS_ADSL_Set_t;

/** Message ID for ACK_TssiUS_ADSL_Set */
#define ACK_TSSIUS_ADSL_SET 0x054D

/**
   This is the acknowledgement for CMD_TssiUS_ADSL_Set.
*/
typedef struct ACK_TssiUS_ADSL_Set ACK_TssiUS_ADSL_Set_t;

/** Message ID for CMD_TssiUS_ADSL2ABL_Set */
#define CMD_TSSIUS_ADSL2ABL_SET 0x154D

/**
   Sets the TSSI breakpoints for ADSL2 Annex A/B/L upstream direction. The US TSSI’s
   are used for RFI notching/carrier masking only.
   Note: Not applicable in ADSL1.
*/
typedef struct CMD_TssiUS_ADSL2ABL_Set CMD_TssiUS_ADSL2ABL_Set_t;

/** Message ID for ACK_TssiUS_ADSL2ABL_Set */
#define ACK_TSSIUS_ADSL2ABL_SET 0x154D

/**
   This is the acknowledgement for CMD_TssiUS_ADSL2ABL_Set.
*/
typedef struct ACK_TssiUS_ADSL2ABL_Set ACK_TssiUS_ADSL2ABL_Set_t;

/** Message ID for CMD_TssiUS_ADSL2M_Set */
#define CMD_TSSIUS_ADSL2M_SET 0x174D

/**
   Sets the TSSI breakpoints for ADSL2 Annex M in upstream direction. The US TSSI’s are
   used for RFI notching/carrier masking only.
   Note: Not applicable in ADSL1.
*/
typedef struct CMD_TssiUS_ADSL2M_Set CMD_TssiUS_ADSL2M_Set_t;

/** Message ID for ACK_TssiUS_ADSL2M_Set */
#define ACK_TSSIUS_ADSL2M_SET 0x174D

/**
   This is the acknowledgement for CMD_TssiUS_ADSL2M_Set.
*/
typedef struct ACK_TssiUS_ADSL2M_Set ACK_TssiUS_ADSL2M_Set_t;

/** Message ID for CMD_TssiUS_ADSL2pM_Set */
#define CMD_TSSIUS_ADSL2PM_SET 0x194D

/**
   Sets the TSSI breakpoints for ADSL2+ Annex M in upstream direction. This US TSSI
   message is used for RFI notching/carrier masking only.
   Note: Not applicable in ADSL1.
*/
typedef struct CMD_TssiUS_ADSL2pM_Set CMD_TssiUS_ADSL2pM_Set_t;

/** Message ID for ACK_TssiUS_ADSL2pM_Set */
#define ACK_TSSIUS_ADSL2PM_SET 0x194D

/**
   This is the acknowledgement for CMD_TssiUS_ADSL2pM_Set.
*/
typedef struct ACK_TssiUS_ADSL2pM_Set ACK_TssiUS_ADSL2pM_Set_t;

/** Message ID for CMD_TssiUS_ADSL2IJ_Set */
#define CMD_TSSIUS_ADSL2IJ_SET 0x1B4D

/**
   Sets the TSSI breakpoints for ADSL2 Annexes I, J in upstream direction. This US TSSI
   message is used for RFI notching/carrier masking only.
   Note: Not applicable in ADSL1.
*/
typedef struct CMD_TssiUS_ADSL2IJ_Set CMD_TssiUS_ADSL2IJ_Set_t;

/** Message ID for ACK_TssiUS_ADSL2IJ_Set */
#define ACK_TSSIUS_ADSL2IJ_SET 0x1B4D

/**
   This is the acknowledgement for CMD_TssiUS_ADSL2IJ_Set.
*/
typedef struct ACK_TssiUS_ADSL2IJ_Set ACK_TssiUS_ADSL2IJ_Set_t;

/** Message ID for CMD_TssiUS_ADSL2pIJ_Set */
#define CMD_TSSIUS_ADSL2PIJ_SET 0x1C4D

/**
   Sets the TSSI breakpoints for ADSL2+ Annexes I, J in upstream direction. This US
   TSSI message is used for RFI notching/carrier masking only.
   Note: Not applicable in ADSL1.
*/
typedef struct CMD_TssiUS_ADSL2pIJ_Set CMD_TssiUS_ADSL2pIJ_Set_t;

/** Message ID for ACK_TssiUS_ADSL2pIJ_Set */
#define ACK_TSSIUS_ADSL2PIJ_SET 0x1C4D

/**
   This is the acknowledgement for CMD_TssiUS_ADSL2IJ_Set.
*/
typedef struct ACK_TssiUS_ADSL2pIJ_Set ACK_TssiUS_ADSL2pIJ_Set_t;

/** Message ID for CMD_ADSL_M_MaskUS_Select */
#define CMD_ADSL_M_MASKUS_SELECT 0x124D

/**
   Selects the ADSL Annex M upstream mask. To be applied only in combination with
   G.992.3/5 Annex M support in CMD_XTSE_Configure. A selected US PSD mask cannot be
   additionally shaped with CMD_ADSL_PSD_ShapeUS_Set (the latter would be ignored). RFI
   notching and carrier masking can be done.
*/
typedef struct CMD_ADSL_M_MaskUS_Select CMD_ADSL_M_MaskUS_Select_t;

/** Message ID for ACK_ADSL_M_MaskUS_Select */
#define ACK_ADSL_M_MASKUS_SELECT 0x124D

/**
   This is the acknowledgement for CMD_ADSL_M_MaskUS_Select.
*/
typedef struct ACK_ADSL_M_MaskUS_Select ACK_ADSL_M_MaskUS_Select_t;

/** Message ID for CMD_ADSL_J_MaskUS_Select */
#define CMD_ADSL_J_MASKUS_SELECT 0x114D

/**
   Selects the ADSL Annex J upstream mask. To be applied only in combination with
   G.992.3/5 Annex J in CMD_XTSE_Configure. A selected US PSD mask cannot be
   additionally shaped with CMD_ADSL_PSD_ShapeUS_Set (the latter would be ignored). RFI
   notching and carrier masking can be done.
*/
typedef struct CMD_ADSL_J_MaskUS_Select CMD_ADSL_J_MaskUS_Select_t;

/** Message ID for ACK_ADSL_J_MaskUS_Select */
#define ACK_ADSL_J_MASKUS_SELECT 0x114D

/**
   This is the acknowledgement for CMD_ADSL_J_MaskUS_Select.
*/
typedef struct ACK_ADSL_J_MaskUS_Select ACK_ADSL_J_MaskUS_Select_t;

/** Message ID for CMD_ADSL_PSD_ShapeUS_Set */
#define CMD_ADSL_PSD_SHAPEUS_SET 0x134D

/**
   Specifies the upstream transmit PSD mask for ADSL2/2+ Annexes M and J by means of
   breakpoints. Values are set at the CO and transferred to the CPE during the G.994.1
   handshake phase (CL message with Submode_PSD_Shape parameter block), the CPE then
   derives its tssi’s accordingly.
   (Section 7.3.1.2.12 of G.997.1 [11] and J.3.4.3 of G.992.3 [2].)
   Attention: US PSD shaping (with this message) and US PSD mask selection
   (CMD_ADSL_J_MaskUS_Select or CMD_ADSL_M_MaskUS_Select) cannot be used
   simultaneously. If done, only the US PSD mask selection becomes
   effecive.
*/
typedef struct CMD_ADSL_PSD_ShapeUS_Set CMD_ADSL_PSD_ShapeUS_Set_t;

/** Message ID for ACK_ADSL_PSD_ShapeUS_Set */
#define ACK_ADSL_PSD_SHAPEUS_SET 0x134D

/**
   Acknowledgement for the message CMD_ADSL_PSD_ShapeUS_Set.
*/
typedef struct ACK_ADSL_PSD_ShapeUS_Set ACK_ADSL_PSD_ShapeUS_Set_t;

/** Message ID for CMD_ADSL_CarMaskDS_Set */
#define CMD_ADSL_CARMASKDS_SET 0x024D

/**
   Attention: To be applied after TSSI configuration!
   This configures the ADSL downstream carrier mask per tone.
   The carrier masking must be applied after TSSI configuration with
   CMD_TssiDS_ADSL_Set, because it is meant for masking, i.e. switching off carriers
   but not for switching on carriers with are suppressed via the TSSI breakpoints.
   The message has a fix length to support all ADSL modes, in ADSL and ADSL2 the values
   for the subcarrier indices >255 are unused ("Don’t care").
*/
typedef struct CMD_ADSL_CarMaskDS_Set CMD_ADSL_CarMaskDS_Set_t;

/** Message ID for ACK_ADSL_CarMaskDS_Set */
#define ACK_ADSL_CARMASKDS_SET 0x024D

/**
   This is the acknowledgement for CMD_ADSL_CarMaskDS_Set.
*/
typedef struct ACK_ADSL_CarMaskDS_Set ACK_ADSL_CarMaskDS_Set_t;

/** Message ID for CMD_ADSL_CarMaskUS_Set */
#define CMD_ADSL_CARMASKUS_SET 0x034D

/**
   Attention: To be applied after TSSI configuration!
   This configures the ADSL upstream carrier mask per tone.
   The carrier masking must be applied after TSSI configuration with
   CMD_TssiUS_ADSL_Set, because it is meant for masking, i.e. switching off carriers
   but not for switching them on if suppressed via the TSSI breakpoints.
*/
typedef struct CMD_ADSL_CarMaskUS_Set CMD_ADSL_CarMaskUS_Set_t;

/** Message ID for ACK_ADSL_CarMaskUS_Set */
#define ACK_ADSL_CARMASKUS_SET 0x034D

/**
   This is the acknowledgement for CMD_ADSL_CarMaskUS_Set.
*/
typedef struct ACK_ADSL_CarMaskUS_Set ACK_ADSL_CarMaskUS_Set_t;

/** Message ID for CMD_ADSL_PCB_DS_Set */
#define CMD_ADSL_PCB_DS_SET 0x004D

/**
   This configures the ADSL downstream power cutback for the different ADSL flavours.
*/
typedef struct CMD_ADSL_PCB_DS_Set CMD_ADSL_PCB_DS_Set_t;

/** Message ID for ACK_ADSL_PCB_DS_Set */
#define ACK_ADSL_PCB_DS_SET 0x004D

/**
   This is the acknowledgement for CMD_ADSL_PCB_DS_Set.
*/
typedef struct ACK_ADSL_PCB_DS_Set ACK_ADSL_PCB_DS_Set_t;

/** Message ID for CMD_ADSL_PCB_US_Set */
#define CMD_ADSL_PCB_US_SET 0x014D

/**
   This configures the ADSL upstream power cutback for the different ADSL flavours (not
   applicable for ADSL1)
*/
typedef struct CMD_ADSL_PCB_US_Set CMD_ADSL_PCB_US_Set_t;

/** Message ID for ACK_ADSL_PCB_US_Set */
#define ACK_ADSL_PCB_US_SET 0x014D

/**
   This is the acknowledgement for CMD_ADSL_PCB_US_Set.
*/
typedef struct ACK_ADSL_PCB_US_Set ACK_ADSL_PCB_US_Set_t;

/** Message ID for CMD_BearerCh0_DS_Set */
#define CMD_BEARERCH0_DS_SET 0x0048

/**
   Sets parameters for downstream bearer channel 0 (Chapters 7.3.2.1-5 of G.997.1
   [11]).
   The mode, ATM or PTM, is selected with the configuration controls "ATMControl" and
   "PTMControl" in Parameter 2. Exactly one of them must be enabled, not both!
   Note: On ADSL: PTM configuration does not use CMD_ADSL_TransportModeSet. Since
   ATM is the FW default in ADSL anyway, CMD_ADSL_TransportModeSet does not
   need to be applied explicitely either.
*/
typedef struct CMD_BearerCh0_DS_Set CMD_BearerCh0_DS_Set_t;

/** Message ID for ACK_BearerCh0_DS_Set */
#define ACK_BEARERCH0_DS_SET 0x0048

/**
   Acknowledgement for CMD_BearerCh0_DS_Set. (Configuration of bearer channel 0).
*/
typedef struct ACK_BearerCh0_DS_Set ACK_BearerCh0_DS_Set_t;

/** Message ID for CMD_BearerCh0_US_Set */
#define CMD_BEARERCH0_US_SET 0x0248

/**
   Sets parameters for upstream bearer channel 0 (Chapters 7.3.2.1-5 of G.997.1 [11]).
   The mode, ATM or PTM, is selected with the configuration controls "ATMControl" and
   "PTMControl" in Parameter 2. Exactly one of them must be enabled, not both!
   Note: PTM configuration does not use CMD_ADSL_TransportModeSet. Since ATM is the
   FW default there anyway, the message does not need to be applied
   explicitely.
*/
typedef struct CMD_BearerCh0_US_Set CMD_BearerCh0_US_Set_t;

/** Message ID for ACK_BearerCh0_US_Set */
#define ACK_BEARERCH0_US_SET 0x0248

/**
   Acknowledgement for CMD_BearerCh0_US_Set. (Configuration of bearer channel 0).
*/
typedef struct ACK_BearerCh0_US_Set ACK_BearerCh0_US_Set_t;

/** Message ID for CMD_ADSL_TransportModeSet */
#define CMD_ADSL_TRANSPORTMODESET 0x004F

/**
   Configures the bearer channel to TPS-TC mapping for both directions as ATM.
   Note: The value written with this message will be made the default value starting
   with the end-of-July 06 release so that it is not necessary to apply it
   explicitely then.
*/
typedef struct CMD_ADSL_TransportModeSet CMD_ADSL_TransportModeSet_t;

/** Message ID for ACK_ADSL_TransportModeSet */
#define ACK_ADSL_TRANSPORTMODESET 0x004F

/**
   Acknowledgment for message CMD_ADSL_TransportModeSet.
*/
typedef struct ACK_ADSL_TransportModeSet ACK_ADSL_TransportModeSet_t;

/** Message ID for CMD_AlgorithmControlSet */
#define CMD_ALGORITHMCONTROLSET 0x0245

/**
   Controls certain funtions of the chip set.
   Attention: 1. The default values may be different for VDSL and ADSL, CO and
   CPE.2. This message uses a negative logic! Thus all "Reserved" bit
   parameters of this message shall be set to "1" unless explicitely
   otherwise noted.
*/
typedef struct CMD_AlgorithmControlSet CMD_AlgorithmControlSet_t;

/** Message ID for ACK_AlgorithmControlSet */
#define ACK_ALGORITHMCONTROLSET 0x0245

/**
   Acknowledgement for message CMD_AlgorithmControlSet.
*/
typedef struct ACK_AlgorithmControlSet ACK_AlgorithmControlSet_t;

/** Message ID for CMD_DigitalFilterSet */
#define CMD_DIGITALFILTERSET 0x0445

/**
   The message controls the digital filters in the VINAX.
*/
typedef struct CMD_DigitalFilterSet CMD_DigitalFilterSet_t;

/** Message ID for ACK_DigitalFilterSet */
#define ACK_DIGITALFILTERSET 0x0445

/**
   Acknowledgement for message CMD_DigitalFilterSet.
*/
typedef struct ACK_DigitalFilterSet ACK_DigitalFilterSet_t;

/** Message ID for CMD_HybridSelect */
#define CMD_HYBRIDSELECT 0x0545

/**
   Selection of the used hybrid.
*/
typedef struct CMD_HybridSelect CMD_HybridSelect_t;

/** Message ID for ACK_HybridSelect */
#define ACK_HYBRIDSELECT 0x0545

/**
   Acknowledgement for message CMD_HybridSelect.
*/
typedef struct ACK_HybridSelect ACK_HybridSelect_t;

/** Message ID for CMD_GainCalibrationSet */
#define CMD_GAINCALIBRATIONSET 0x3348

/**
   Sets transmit and receive gain value for the gain calibration.
*/
typedef struct CMD_GainCalibrationSet CMD_GainCalibrationSet_t;

/** Message ID for ACK_GainCalibrationSet */
#define ACK_GAINCALIBRATIONSET 0x3348

/**
   Acknowledgement to CMD_GainCalibrationSet.
*/
typedef struct ACK_GainCalibrationSet ACK_GainCalibrationSet_t;

/** Message ID for CMD_ADSL_GainCalibrationSet */
#define CMD_ADSL_GAINCALIBRATIONSET 0x104D

/**
   Sets transmit and receive gain value for the gain calibration.
*/
typedef struct CMD_ADSL_GainCalibrationSet CMD_ADSL_GainCalibrationSet_t;

/** Message ID for ACK_ADSL_GainCalibrationSet */
#define ACK_ADSL_GAINCALIBRATIONSET 0x104D

/**
   Acknowledgement to CMD_ADSL_GainCalibrationSet.
*/
typedef struct ACK_ADSL_GainCalibrationSet ACK_ADSL_GainCalibrationSet_t;

/** Message ID for CMD_PARR_ThreshSet */
#define CMD_PARR_THRESHSET 0x3648

/**
   This command is used to configure the power level threshold at which the Peak to
   Average Ratio Reduction (PARR) algorithm is enabled. The PARR is operating when the
   transmit power level is above the threshold.
   Only valid if PARR was switched on with CMD_AlgorithmControlSet.
*/
typedef struct CMD_PARR_ThreshSet CMD_PARR_ThreshSet_t;

/** Message ID for ACK_PARR_ThreshSet */
#define ACK_PARR_THRESHSET 0x3648

/**
   This is the acknowledgement for CMD_PARR_ThreshSet.
*/
typedef struct ACK_PARR_ThreshSet ACK_PARR_ThreshSet_t;

/** Message ID for CMD_VDSL_PARR_ToneSelect */
#define CMD_VDSL_PARR_TONESELECT 0x3548

/**
   The command selects PARR tones to be used by the Peak to Average Ratio Reduction
   (PARR) algorithm. Only valid if PARR was enabled with CMD_AlgorithmControlSet.
   Note: Care must be taken in selecting the parameters. See Chapter5.5.11.3. A poor
   selection will result in decreased performance!
*/
typedef struct CMD_VDSL_PARR_ToneSelect CMD_VDSL_PARR_ToneSelect_t;

/** Message ID for ACK_VDSL_PARR_ToneSelect */
#define ACK_VDSL_PARR_TONESELECT 0x3548

/**
   Acknowledgement for CMD_VDSL_PARR_ToneSelect.
*/
typedef struct ACK_VDSL_PARR_ToneSelect ACK_VDSL_PARR_ToneSelect_t;

/** Message ID for CMD_ADSL12A_PARR_ToneSelect */
#define CMD_ADSL12A_PARR_TONESELECT 0x084D

/**
   The command selects PARR tones to be used by the Peak to Average Ratio Reduction
   (PARR) algorithm in ADSL1 (G.992.1) and ADSL2 (G.992.3), both Annex A. Only valid if
   PARR was enabled with CMD_AlgorithmControlSet. The message has a fixed length to
   select up to 9 PARR tones. Unused PARR tones are set to "0".
   Note: Care must be taken in selecting the parameters. See Chapter5.5.11.3. A poor
   selection will result in decreased performance!
*/
typedef struct CMD_ADSL12A_PARR_ToneSelect CMD_ADSL12A_PARR_ToneSelect_t;

/** Message ID for ACK_ADSL12A_PARR_ToneSelect */
#define ACK_ADSL12A_PARR_TONESELECT 0x084D

/**
   Acknowledgement for CMD_ADSL12A_PARR_ToneSelect.
*/
typedef struct ACK_ADSL12A_PARR_ToneSelect ACK_ADSL12A_PARR_ToneSelect_t;

/** Message ID for CMD_ADSL2pA_PARR_ToneSelect */
#define CMD_ADSL2PA_PARR_TONESELECT 0x094D

/**
   The command selects PARR tones to be used by the Peak to Average Ratio Reduction
   (PARR) algorithm in ADSL2+ (G.992.5) mode, Annex A. Only valid if PARR was enabled
   with CMD_AlgorithmControlSet. The message has a fixed length to select up to 9 PARR
   tones. Unused PARR tones are set to "0".
   Note: Care must be taken in selecting the parameters. See Chapter5.5.11.3. A poor
   selection will result in decreased performance!
*/
typedef struct CMD_ADSL2pA_PARR_ToneSelect CMD_ADSL2pA_PARR_ToneSelect_t;

/** Message ID for ACK_ADSL2pA_PARR_ToneSelect */
#define ACK_ADSL2PA_PARR_TONESELECT 0x094D

/**
   Acknowledgement for CMD_ADSL2pA_PARR_ToneSelect.
*/
typedef struct ACK_ADSL2pA_PARR_ToneSelect ACK_ADSL2pA_PARR_ToneSelect_t;

/** Message ID for CMD_ADSL12B_PARR_ToneSelect */
#define CMD_ADSL12B_PARR_TONESELECT 0x0A4D

/**
   The command selects PARR tones to be used by the Peak to Average Ratio Reduction
   (PARR) algorithm in ADSL1 (G.992.1) and ADSL2 (G.992.3), both Annex B. Only valid if
   PARR was enabled with CMD_AlgorithmControlSet. The message has a fixed length to
   select up to 9 PARR tones. Unused PARR tones are set to "0".
   Note: Care must be taken in selecting the parameters. See Chapter5.5.11.3. A poor
   selection will result in decreased performance!
*/
typedef struct CMD_ADSL12B_PARR_ToneSelect CMD_ADSL12B_PARR_ToneSelect_t;

/** Message ID for ACK_ADSL12B_PARR_ToneSelect */
#define ACK_ADSL12B_PARR_TONESELECT 0x0A4D

/**
   Acknowledgement for CMD_ADSL12B_PARR_ToneSelect.
*/
typedef struct ACK_ADSL12B_PARR_ToneSelect ACK_ADSL12B_PARR_ToneSelect_t;

/** Message ID for CMD_ADSL2pB_PARR_ToneSelect */
#define CMD_ADSL2PB_PARR_TONESELECT 0x0B4D

/**
   The command selects PARR tones to be used by the Peak to Average Ratio Reduction
   (PARR) algorithm in ADSL2+ (G.992.5) mode, Annex B. Only valid if PARR was enabled
   with CMD_AlgorithmControlSet. The message has a fixed length to select up to 9 PARR
   tones. Unused PARR tones are set to "0".
   Note: Care must be taken in selecting the parameters. See Chapter5.5.11.3. A poor
   selection will result in decreased performance!
*/
typedef struct CMD_ADSL2pB_PARR_ToneSelect CMD_ADSL2pB_PARR_ToneSelect_t;

/** Message ID for ACK_ADSL2pB_PARR_ToneSelect */
#define ACK_ADSL2PB_PARR_TONESELECT 0x0B4D

/**
   Acknowledgement for CMD_ADSL2pB_PARR_ToneSelect.
*/
typedef struct ACK_ADSL2pB_PARR_ToneSelect ACK_ADSL2pB_PARR_ToneSelect_t;

/** Message ID for CMD_ADSL12M_PARR_ToneSelect */
#define CMD_ADSL12M_PARR_TONESELECT 0x0C4D

/**
   The command selects PARR tones to be used by the Peak to Average Ratio Reduction
   (PARR) algorithm in ADSL1 (G.992.1) and ADSL2 (G.992.3), both Annex M. Only valid if
   PARR was enabled with CMD_AlgorithmControlSet. The message has a fixed length to
   select up to 9 PARR tones. Unused PARR tones are set to "0".
   Note: Care must be taken in selecting the parameters. See Chapter5.5.11.3. A poor
   selection will result in decreased performance!
*/
typedef struct CMD_ADSL12M_PARR_ToneSelect CMD_ADSL12M_PARR_ToneSelect_t;

/** Message ID for ACK_ADSL12M_PARR_ToneSelect */
#define ACK_ADSL12M_PARR_TONESELECT 0x0C4D

/**
   Acknowledgement for CMD_ADSL12M_PARR_ToneSelect.
*/
typedef struct ACK_ADSL12M_PARR_ToneSelect ACK_ADSL12M_PARR_ToneSelect_t;

/** Message ID for CMD_ADSL2pM_PARR_ToneSelect */
#define CMD_ADSL2PM_PARR_TONESELECT 0x0D4D

/**
   The command selects PARR tones to be used by the Peak to Average Ratio Reduction
   (PARR) algorithm in ADSL2+ (G.992.5) mode, Annex M. Only valid if PARR was enabled
   with CMD_AlgorithmControlSet. The message has a fixed length to select up to 9 PARR
   tones. Unused PARR tones are set to "0".
   Note: Care must be taken in selecting the parameters. See Chapter5.5.11.3. A poor
   selection will result in decreased performance!
*/
typedef struct CMD_ADSL2pM_PARR_ToneSelect CMD_ADSL2pM_PARR_ToneSelect_t;

/** Message ID for ACK_ADSL2pM_PARR_ToneSelect */
#define ACK_ADSL2PM_PARR_TONESELECT 0x0D4D

/**
   Acknowledgement for CMD_ADSL2pM_PARR_ToneSelect.
*/
typedef struct ACK_ADSL2pM_PARR_ToneSelect ACK_ADSL2pM_PARR_ToneSelect_t;

/** Message ID for CMD_US_DeinterleaverMemPartition */
#define CMD_US_DEINTERLEAVERMEMPARTITION 0x3748

/**
   The message controls the amount of de-interleaver memory claimed by the CO US
   receiver. This is necessary for interoperability reasons.
   Note: The VDSL2 standard defines the interleaver/de-interleaver memory as a
   single sized block, i.e. its definition assumes this memory block can be
   shared by the VTU's interleaver and de-interleaver at any ratio as long as
   the total memory (interleaver + de-interleaver) does not exceed the memory
   requirements from the standard. The interleaver setting is controlled by
   the CO. The CO estimates how much memory is needed for the US
   de-interleaving, based on it specifies to the CPE how much de-interleaving
   memory it can use for the DS. The CPE then chooses the interleaver depth
   and other framing parameters based on the memory restrictions provided by
   the CO.
   FW versions up to w.9.x.y.z.a distinguish between "known" and "unknown" CPE modems
   and use 2 different parameters for them, whereas FW versions starting from
   w.10.x.y.z.a do not make this distinction any more and use only one. This only
   parameter has a slightly different meaning for shared (Rev. 2.x) or non-shared (Rev.
   1.x) interleaver memory. If US and DS share a common memory, the configured number
   relates to that common memory. In case of separate memories ("non-shared"), the
   configured number relates to the US memory only.
   FW versions up to w.9.x.y.z.a (with 2 parameters): For known far-end modems, it is
   advantageous to use as much as possible of the de-interleaving memory available in
   the HW.  For interoperability purposes with unknown CPEs, the US memory usage is
   limited to a configurable part, which is dependant on profile and data rate.
   Note: Example for the "old" scheme: G.993.2 requires 64 kB of total interleaving
   and de-interleaving memory (altogether for CO+CPE) for band plans 8 a-d.
   The Vinax supports 128 kB in total, corresponding to 64 kB for each
   direction (CO+CPE), thus at the CO there are 32 kB available for
   de-interleaving.Known CPE: CO uses all 32 kB of the available HW memory for
   de-interleaving.Unknown CPE: The memory required at the CO for
   de-interleaving is profile and data rate dependant.
*/
typedef struct CMD_US_DeinterleaverMemPartition CMD_US_DeinterleaverMemPartition_t;

/** Message ID for ACK_US_DeinterleaverMemPartition */
#define ACK_US_DEINTERLEAVERMEMPARTITION 0x3748

/**
   This is the acknowledgement for CMD_US_DeinterleaverMemPartition.
*/
typedef struct ACK_US_DeinterleaverMemPartition ACK_US_DeinterleaverMemPartition_t;

/** Message ID for CMD_ACE_FilterSet */
#define CMD_ACE_FILTERSET 0x3B48

/**
   The message controls the ACE filter in the AFE’s receive part.
*/
typedef struct CMD_ACE_FilterSet CMD_ACE_FilterSet_t;

/** Message ID for ACK_ACE_FilterSet */
#define ACK_ACE_FILTERSET 0x3B48

/**
   Acknowledgement for message CMD_ACE_FilterSet.
*/
typedef struct ACK_ACE_FilterSet ACK_ACE_FilterSet_t;

/** Message ID for CMD_Misc_ConfigSet */
#define CMD_MISC_CONFIGSET 0x3A48

/**
   Performs some miscellaneous chip set configurations.
*/
typedef struct CMD_Misc_ConfigSet CMD_Misc_ConfigSet_t;

/** Message ID for ACK_Misc_ConfigSet */
#define ACK_MISC_CONFIGSET 0x3A48

/**
   This is the acknowledgement for ACK_Misc_ConfigSet.
*/
typedef struct ACK_Misc_ConfigSet ACK_Misc_ConfigSet_t;

/** Message ID for CMD_InteropConfigSet */
#define CMD_INTEROPCONFIGSET 0x6743

/**
   The message configures interoperability settings at the ADSL-CPE.
*/
typedef struct CMD_InteropConfigSet CMD_InteropConfigSet_t;

/** Message ID for ACK_InteropConfigSet */
#define ACK_INTEROPCONFIGSET 0x6743

/**
   This is the acknowledgement for CMD_InteropConfigSet.
*/
typedef struct ACK_InteropConfigSet ACK_InteropConfigSet_t;

/** Message ID for CMD_InteropConfigGet */
#define CMD_INTEROPCONFIGGET 0x6703

/**
   The message requests the interoperability settings used at the ADSL-CPE.
*/
typedef struct CMD_InteropConfigGet CMD_InteropConfigGet_t;

/** Message ID for ACK_InteropConfigGet */
#define ACK_INTEROPCONFIGGET 0x6703

/**
   This is the acknowledgement for CMD_InteropConfigGet.
*/
typedef struct ACK_InteropConfigGet ACK_InteropConfigGet_t;

/**
   Requests information about the current state of the modem state-machine.
   The command can be sent in all states of the modem state machine (see Figure2).
*/
struct CMD_ModemFSM_StateGet
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
   Returns information about the current state of the modem state-machine.
*/
struct ACK_ModemFSM_StateGet
{
#if MEI_DRV_OS_BYTE_ORDER == MEI_DRV_OS_BIG_ENDIAN
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Modem Status */
   IFX_uint16_t ModemState;
   /** Reserved */
   IFX_uint16_t Res03 : 14;
   /** Line Power Management State */
   IFX_uint16_t LxState : 2;
#else
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Modem Status */
   IFX_uint16_t ModemState;
   /** Line Power Management State */
   IFX_uint16_t LxState : 2;
   /** Reserved */
   IFX_uint16_t Res03 : 14;
#endif
} __PACKED__ ;


/**
   Returns information about the current state of the modem state-machine. This message
   is sent autonomously, if the modem enters a new state and reporting is enabled for
   that state (see CMD_ModemFSM_EventConfigure).
*/
struct EVT_ModemFSM_StateGet
{
#if MEI_DRV_OS_BYTE_ORDER == MEI_DRV_OS_BIG_ENDIAN
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Modem Status */
   IFX_uint16_t ModemState;
   /** Reserved */
   IFX_uint16_t Res03 : 14;
   /** Line Power Management State */
   IFX_uint16_t LxState : 2;
#else
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Modem Status */
   IFX_uint16_t ModemState;
   /** Line Power Management State */
   IFX_uint16_t LxState : 2;
   /** Reserved */
   IFX_uint16_t Res03 : 14;
#endif
} __PACKED__ ;


/**
   Autonomous message indicating that the modem online code was reached and that
   initialization was completed. The management entity may not perform any
   query-response messaging until the EVT_ModemReady message is received. Its
   generation cannot be disabled. If it is not received this indicates a problem,
   possibly with the boot sequence. If the message is received, it contains a result
   code that may also indicate that an error was detected by the firmware during
   initialization.
*/
struct EVT_ModemReady
{
#if MEI_DRV_OS_BYTE_ORDER == MEI_DRV_OS_BIG_ENDIAN
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Error Code */
   IFX_uint8_t ErrorCode;
   /** Warning Code */
   IFX_uint8_t WarningCode;
#else
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Warning Code */
   IFX_uint8_t WarningCode;
   /** Error Code */
   IFX_uint8_t ErrorCode;
#endif
} __PACKED__ ;


/**
   Controls state transitions of the modem state-machine.
*/
struct CMD_ModemFSM_StateSet
{
#if MEI_DRV_OS_BYTE_ORDER == MEI_DRV_OS_BIG_ENDIAN
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Reserved */
   IFX_uint16_t Res02 : 12;
   /** Link Control */
   IFX_uint16_t LinkControl : 4;
#else
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Link Control */
   IFX_uint16_t LinkControl : 4;
   /** Reserved */
   IFX_uint16_t Res02 : 12;
#endif
} __PACKED__ ;


/**
   Acknowledgement for message CMD_ModemFSM_StateSet
*/
struct ACK_ModemFSM_StateSet
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
   Changes the DSL mode of a line between VDSL and ADSL. After applying this message, a
   reboot with the selected FW takes place. In VINAX V1.X, the command is valid in boot
   modes 0x8 and 0x9 only and ignored otherwise.
   Note: This message needs to be applied for changing the DSL mode only, not for
   every line initialization.
   Note: VINAX V1.X only: Before applying this message in VINAX V1.X, the device
   driver writes the wanted DSL mode to a DFE HW register which is evaluated
   during the boot process. (PDSCR register, Bit PYPRG1, ’’0’’=VDSL)
   Note: The parameter "DLS Mode Boot Selection" is needed for a common ADSL/VDSL
   FW. Otherwise, this parameter is not evaluated.
*/
struct CMD_DSL_ModeModify
{
#if MEI_DRV_OS_BYTE_ORDER == MEI_DRV_OS_BIG_ENDIAN
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Reserved */
   IFX_uint16_t Res02 : 15;
   /** DSL Mode Boot Selection */
   IFX_uint16_t DSL_Mode : 1;
#else
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** DSL Mode Boot Selection */
   IFX_uint16_t DSL_Mode : 1;
   /** Reserved */
   IFX_uint16_t Res02 : 15;
#endif
} __PACKED__ ;


/**
   Acknowledgement for message CMD_DSL_ModeModify
*/
struct ACK_DSL_ModeModify
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
   Reports failure information after entering FAIL state. This message is sent
   autonomously without host request after entrance into FAIL was indicated by
   EVT_ModemFSM_StateGet. Both messages are generated only if enabled with
   CMD_ModemFSM_EventConfigure (common Bit E8 "FAIL").
*/
struct ALM_ModemFSM_FailReasonGet
{
#if MEI_DRV_OS_BYTE_ORDER == MEI_DRV_OS_BIG_ENDIAN
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** System Sub Error Code */
   IFX_uint8_t SubErrorCode;
   /** System Error Code */
   IFX_uint8_t ErrorCode;
   /** Failure State Information */
   IFX_uint16_t FW_FailCode;
   /** Tx Symbol Count, LSW */
   IFX_uint16_t TxSymCountLSW;
   /** Tx Symbol Count, MSW */
   IFX_uint16_t TxSymCountMSW;
   /** Tx State at Failure */
   IFX_uint16_t TxStateOnFail;
   /** Tx Sub State at Failure */
   IFX_uint16_t TxSubStateOnFail;
   /** Rx Symbol Count, LSW */
   IFX_uint16_t RxSymCountLSW;
   /** Rx Symbol Count, MSW */
   IFX_uint16_t RxSymCountMSW;
   /** Rx State at Failure */
   IFX_uint16_t RxStateOnFail;
   /** Rx Sub State at Failure */
   IFX_uint16_t RxSubStateOnFail;
#else
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** System Error Code */
   IFX_uint8_t ErrorCode;
   /** System Sub Error Code */
   IFX_uint8_t SubErrorCode;
   /** Failure State Information */
   IFX_uint16_t FW_FailCode;
   /** Tx Symbol Count, LSW */
   IFX_uint16_t TxSymCountLSW;
   /** Tx Symbol Count, MSW */
   IFX_uint16_t TxSymCountMSW;
   /** Tx State at Failure */
   IFX_uint16_t TxStateOnFail;
   /** Tx Sub State at Failure */
   IFX_uint16_t TxSubStateOnFail;
   /** Rx Symbol Count, LSW */
   IFX_uint16_t RxSymCountLSW;
   /** Rx Symbol Count, MSW */
   IFX_uint16_t RxSymCountMSW;
   /** Rx State at Failure */
   IFX_uint16_t RxStateOnFail;
   /** Rx Sub State at Failure */
   IFX_uint16_t RxSubStateOnFail;
#endif
} __PACKED__ ;


/**
   Requests failure information after entering FAIL state.
*/
struct CMD_ModemFSM_FailReasonGet
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
   Returns failure information after entering FAIL state.
*/
struct ACK_ModemFSM_FailReasonGet
{
#if MEI_DRV_OS_BYTE_ORDER == MEI_DRV_OS_BIG_ENDIAN
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** System Sub Error Code */
   IFX_uint8_t SubErrorCode;
   /** System Error Code */
   IFX_uint8_t ErrorCode;
   /** Failure State Information */
   IFX_uint16_t FW_FailCode;
   /** Tx Symbol Count, LSW */
   IFX_uint16_t TxSymCountLSW;
   /** Tx Symbol Count, MSW */
   IFX_uint16_t TxSymCountMSW;
   /** Tx State at Failure */
   IFX_uint16_t TxStateOnFail;
   /** Tx Sub State at Failure */
   IFX_uint16_t TxSubStateOnFail;
   /** Rx Symbol Count, LSW */
   IFX_uint16_t RxSymCountLSW;
   /** Rx Symbol Count, MSW */
   IFX_uint16_t RxSymCountMSW;
   /** Rx State at Failure */
   IFX_uint16_t RxStateOnFail;
   /** Rx Sub State at Failure */
   IFX_uint16_t RxSubStateOnFail;
#else
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** System Error Code */
   IFX_uint8_t ErrorCode;
   /** System Sub Error Code */
   IFX_uint8_t SubErrorCode;
   /** Failure State Information */
   IFX_uint16_t FW_FailCode;
   /** Tx Symbol Count, LSW */
   IFX_uint16_t TxSymCountLSW;
   /** Tx Symbol Count, MSW */
   IFX_uint16_t TxSymCountMSW;
   /** Tx State at Failure */
   IFX_uint16_t TxStateOnFail;
   /** Tx Sub State at Failure */
   IFX_uint16_t TxSubStateOnFail;
   /** Rx Symbol Count, LSW */
   IFX_uint16_t RxSymCountLSW;
   /** Rx Symbol Count, MSW */
   IFX_uint16_t RxSymCountMSW;
   /** Rx State at Failure */
   IFX_uint16_t RxStateOnFail;
   /** Rx Sub State at Failure */
   IFX_uint16_t RxSubStateOnFail;
#endif
} __PACKED__ ;


/**
   Configuration of options for the modem state machine.
*/
struct CMD_ModemFSM_OptionsSet
{
#if MEI_DRV_OS_BYTE_ORDER == MEI_DRV_OS_BIG_ENDIAN
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Reserved */
   IFX_uint16_t Res02 : 10;
   /** Granting of an L3 Request from ATU-R */
   IFX_uint16_t E5 : 1;
   /** US Virtual Noise Support */
   IFX_uint16_t E4 : 1;
   /** DS Virtual Noise Support */
   IFX_uint16_t E3 : 1;
   /** Loop Diagnostic Mode Control */
   IFX_uint16_t E2 : 1;
   /** Reserved 0 */
   IFX_uint16_t E1 : 1;
   /** Automatic Re-Start Control */
   IFX_uint16_t E0 : 1;
#else
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Automatic Re-Start Control */
   IFX_uint16_t E0 : 1;
   /** Reserved 0 */
   IFX_uint16_t E1 : 1;
   /** Loop Diagnostic Mode Control */
   IFX_uint16_t E2 : 1;
   /** DS Virtual Noise Support */
   IFX_uint16_t E3 : 1;
   /** US Virtual Noise Support */
   IFX_uint16_t E4 : 1;
   /** Granting of an L3 Request from ATU-R */
   IFX_uint16_t E5 : 1;
   /** Reserved */
   IFX_uint16_t Res02 : 10;
#endif
} __PACKED__ ;


/**
   Acknowledgement to CMD_ModemFSM_OptionsSet (configuration of automatic re-start).
*/
struct ACK_ModemFSM_OptionsSet
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
   Sets options for the modem state-machine. Enables/Disables autonomous messages for
   specific state transitions (EVT_ModemFSM_StateGet). The EVT message is generated
   after entering the particular state listed in the parameter description of the
   enable bits.
*/
struct CMD_ModemFSM_EventConfigure
{
#if MEI_DRV_OS_BYTE_ORDER == MEI_DRV_OS_BIG_ENDIAN
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Reserved */
   IFX_uint16_t Res02 : 1;
   /** Enable Bit 14 */
   IFX_uint16_t E14 : 1;
   /** Enable Bit 13 */
   IFX_uint16_t E13 : 1;
   /** Reserved */
   IFX_uint16_t Res05 : 1;
   /** Enable Bit 11 */
   IFX_uint16_t E11 : 1;
   /** Enable Bit 10 */
   IFX_uint16_t E10 : 1;
   /** Enable Bit 9 */
   IFX_uint16_t E9 : 1;
   /** Enable Bit 8 */
   IFX_uint16_t E8 : 1;
   /** Reserved */
   IFX_uint16_t Res10 : 1;
   /** Enable Bit 6 */
   IFX_uint16_t E6 : 1;
   /** Enable Bit 5 */
   IFX_uint16_t E5 : 1;
   /** Enable Bit 4 */
   IFX_uint16_t E4 : 1;
   /** Enable Bit 3 */
   IFX_uint16_t E3 : 1;
   /** Enable Bit 2 */
   IFX_uint16_t E2 : 1;
   /** Reserved */
   IFX_uint16_t Res16 : 1;
   /** Enable Bit 0 */
   IFX_uint16_t E0 : 1;
#else
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Enable Bit 0 */
   IFX_uint16_t E0 : 1;
   /** Reserved */
   IFX_uint16_t Res16 : 1;
   /** Enable Bit 2 */
   IFX_uint16_t E2 : 1;
   /** Enable Bit 3 */
   IFX_uint16_t E3 : 1;
   /** Enable Bit 4 */
   IFX_uint16_t E4 : 1;
   /** Enable Bit 5 */
   IFX_uint16_t E5 : 1;
   /** Enable Bit 6 */
   IFX_uint16_t E6 : 1;
   /** Reserved */
   IFX_uint16_t Res10 : 1;
   /** Enable Bit 8 */
   IFX_uint16_t E8 : 1;
   /** Enable Bit 9 */
   IFX_uint16_t E9 : 1;
   /** Enable Bit 10 */
   IFX_uint16_t E10 : 1;
   /** Enable Bit 11 */
   IFX_uint16_t E11 : 1;
   /** Reserved */
   IFX_uint16_t Res05 : 1;
   /** Enable Bit 13 */
   IFX_uint16_t E13 : 1;
   /** Enable Bit 14 */
   IFX_uint16_t E14 : 1;
   /** Reserved */
   IFX_uint16_t Res02 : 1;
#endif
} __PACKED__ ;


/**
   Acknowledgement for CMD_ModemFSM_EventConfigure. (Enabling/Disabling EVENT messages
   (EVTs) for specific state transitions.)
*/
struct ACK_ModemFSM_EventConfigure
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
   Enables/Disables the generation of ALARM messages (ALM) for specific near-end line
   failures. If the corresponding Enable bit for a line failure is set, then the modem
   firmware will send an autonomous message ALM_LineFailureNE_Get if this failure
   occurs.
*/
struct CMD_FailuresNE_AlarmConfigure
{
#if MEI_DRV_OS_BYTE_ORDER == MEI_DRV_OS_BIG_ENDIAN
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Reserved */
   IFX_uint16_t Res02 : 2;
   /** Enable Bit 13 */
   IFX_uint16_t E13 : 1;
   /** Enable Bit12 */
   IFX_uint16_t E12 : 1;
   /** Reserved */
   IFX_uint16_t Res05 : 8;
   /** Enable Bit3 */
   IFX_uint16_t E3 : 1;
   /** Reserved */
   IFX_uint16_t Res07 : 1;
   /** Enable Bit1 */
   IFX_uint16_t E1 : 1;
   /** Enable Bit0 */
   IFX_uint16_t E0 : 1;
#else
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Enable Bit0 */
   IFX_uint16_t E0 : 1;
   /** Enable Bit1 */
   IFX_uint16_t E1 : 1;
   /** Reserved */
   IFX_uint16_t Res07 : 1;
   /** Enable Bit3 */
   IFX_uint16_t E3 : 1;
   /** Reserved */
   IFX_uint16_t Res05 : 8;
   /** Enable Bit12 */
   IFX_uint16_t E12 : 1;
   /** Enable Bit 13 */
   IFX_uint16_t E13 : 1;
   /** Reserved */
   IFX_uint16_t Res02 : 2;
#endif
} __PACKED__ ;


/**
   Acknowledgement to CMD_FailuresNE_AlarmConfigure.
*/
struct ACK_FailuresNE_AlarmConfigure
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
   Enables/Disables the generation of ALARM messages (ALM) for specific far-end line
   failures. If the corresponding Enable bit for a line failure is set, then the modem
   firmware will send an autonomous message ALM_LineFailureFE_Get if this failure
   occurs.
*/
struct CMD_FailuresFE_AlarmConfigure
{
#if MEI_DRV_OS_BYTE_ORDER == MEI_DRV_OS_BIG_ENDIAN
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Reserved */
   IFX_uint16_t Res02 : 12;
   /** Enable Bit3 */
   IFX_uint16_t E3 : 1;
   /** Enable Bit2 */
   IFX_uint16_t E2 : 1;
   /** Enable Bit1 */
   IFX_uint16_t E1 : 1;
   /** Enable Bit0 */
   IFX_uint16_t E0 : 1;
#else
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Enable Bit0 */
   IFX_uint16_t E0 : 1;
   /** Enable Bit1 */
   IFX_uint16_t E1 : 1;
   /** Enable Bit2 */
   IFX_uint16_t E2 : 1;
   /** Enable Bit3 */
   IFX_uint16_t E3 : 1;
   /** Reserved */
   IFX_uint16_t Res02 : 12;
#endif
} __PACKED__ ;


/**
   Acknowledgement to CMD_FailuresFE_AlarmConfigure.
*/
struct ACK_FailuresFE_AlarmConfigure
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
   Configures re-initialization triggers for near-end failure conditions in modem state
   STEADY STATE transmission (see Figure1). This command is accepted in RESET state
   only.
*/
struct CMD_ReInitNE_Configure
{
#if MEI_DRV_OS_BYTE_ORDER == MEI_DRV_OS_BIG_ENDIAN
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** 32 CRCs */
   IFX_uint16_t E15 : 1;
   /** Reserved */
   IFX_uint16_t Res03 : 1;
   /** ESE */
   IFX_uint16_t E13 : 1;
   /** Reserved */
   IFX_uint16_t Res05 : 2;
   /** OOS BC0 */
   IFX_uint16_t E10 : 1;
   /** Reserved */
   IFX_uint16_t Res07 : 6;
   /** LOM */
   IFX_uint16_t E3 : 1;
   /** Reserved */
   IFX_uint16_t Res09 : 1;
   /** LOF */
   IFX_uint16_t E1 : 1;
   /** LOS */
   IFX_uint16_t E0 : 1;
#else
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** LOS */
   IFX_uint16_t E0 : 1;
   /** LOF */
   IFX_uint16_t E1 : 1;
   /** Reserved */
   IFX_uint16_t Res09 : 1;
   /** LOM */
   IFX_uint16_t E3 : 1;
   /** Reserved */
   IFX_uint16_t Res07 : 6;
   /** OOS BC0 */
   IFX_uint16_t E10 : 1;
   /** Reserved */
   IFX_uint16_t Res05 : 2;
   /** ESE */
   IFX_uint16_t E13 : 1;
   /** Reserved */
   IFX_uint16_t Res03 : 1;
   /** 32 CRCs */
   IFX_uint16_t E15 : 1;
#endif
} __PACKED__ ;


/**
   Acknowledgment to CMD_ReInitNE_Configure (Configuration of re-initialization
   triggers for near-end failures).
*/
struct ACK_ReInitNE_Configure
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
   Configures Re-initialization triggers for Far-End failure conditions in modem state
   STEADY STATE.
*/
struct CMD_ReInitFE_Configure
{
#if MEI_DRV_OS_BYTE_ORDER == MEI_DRV_OS_BIG_ENDIAN
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Reserved */
   IFX_uint16_t Res02 : 12;
   /** LOM */
   IFX_uint16_t E3 : 1;
   /** Enable Bit 2 for Re-init Trigger */
   IFX_uint16_t E2 : 1;
   /** Reserved */
   IFX_uint16_t Res05 : 1;
   /** LOS */
   IFX_uint16_t E0 : 1;
#else
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** LOS */
   IFX_uint16_t E0 : 1;
   /** Reserved */
   IFX_uint16_t Res05 : 1;
   /** Enable Bit 2 for Re-init Trigger */
   IFX_uint16_t E2 : 1;
   /** LOM */
   IFX_uint16_t E3 : 1;
   /** Reserved */
   IFX_uint16_t Res02 : 12;
#endif
} __PACKED__ ;


/**
   Acknowledgment to CMD_ReInitFE_Configure (Configuration of Re-initialization
   triggers for far-end failures).
*/
struct ACK_ReInitFE_Configure
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
   Triggers the sending of an L3 orderly shutdown request to the remote side.
   If applied at the CO and accepted by the CPE, the following happens: CO-FW itself
   forces L3 entry transitioning to RESET state. The initiator of the L3 entry (here
   CO) shall decide when to go out there as well.
   If applied at the CPE and accepted by the CO, the following shall happen: Not the FW
   but the CPE-Host forces L3 entry with transition to RESET state by applying
   CMD_ModemFSM_StateGet.
   Note: Different behaviour for the CPE is required because first the ADSL-CPE host
   is not informed autonomously and second some important FSM transitions like
   autorestart happen under explicite host control.
*/
struct CMD_L3ShutdownRequest
{
#if MEI_DRV_OS_BYTE_ORDER == MEI_DRV_OS_BIG_ENDIAN
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Reserved */
   IFX_uint16_t Res02 : 15;
   /** L3 Orderly Shutdown Request */
   IFX_uint16_t L3shutdown : 1;
#else
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** L3 Orderly Shutdown Request */
   IFX_uint16_t L3shutdown : 1;
   /** Reserved */
   IFX_uint16_t Res02 : 15;
#endif
} __PACKED__ ;


/**
   Acknowledgement for CMD_L3ShutdownRequest.
*/
struct ACK_L3ShutdownRequest
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
   Requests information about L3 orderly shutdown requests initiated from the remote
   side.
   Applying CMD_RxL3RequestStatusGet allows the host to determine whether a near-end
   LOS or LOM failure is due to an L3 shutdown or an unexpected line failure.
*/
struct CMD_RxL3RequestStatusGet
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
   Acknowledgement for CMD_RxL3RequestStatusGet.
   As long as the modem is in L0 (Showtime), an ATU-R will automatically respond to any
   L3 request from the ATU-C by sending an accept message.  If the ATU-R is in L2 mode
   when it receives the request, it will send a reject message. Upon receiving an
   acceptance, the remote side should enter L3 state and shut off its transmitter.
*/
struct ACK_RxL3RequestStatusGet
{
#if MEI_DRV_OS_BYTE_ORDER == MEI_DRV_OS_BIG_ENDIAN
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** L3 Request Response */
   IFX_uint16_t L3ReqResponse : 1;
   /** L3 Request Received */
   IFX_uint16_t L3ReqReceived : 1;
   /** Reserved */
   IFX_uint16_t Res04 : 14;
#else
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Reserved */
   IFX_uint16_t Res04 : 14;
   /** L3 Request Received */
   IFX_uint16_t L3ReqReceived : 1;
   /** L3 Request Response */
   IFX_uint16_t L3ReqResponse : 1;
#endif
} __PACKED__ ;


/**
   Requests the status of a near-end initiated L3 shutdown request. If the remote side
   accepted the request, in case of an ADSL-CPE the host will force L3 entry using
   CMD_ModemFSM_StateSet. (In case of an ADSL-CO the FW itself will force L3 entry
   after getting the acceptance and transition to RESET state informing the host with
   the autonomous EVT_ModemFSM_StateGet.)
*/
struct CMD_TxL3RequestStatusGet
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
   Acknowledgement for CMD_TxL3RequestStatusGet.
*/
struct ACK_TxL3RequestStatusGet
{
#if MEI_DRV_OS_BYTE_ORDER == MEI_DRV_OS_BIG_ENDIAN
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Reserved */
   IFX_uint16_t Res02 : 14;
   /** Status L3 Request */
   IFX_uint16_t L3ReqStatus : 2;
#else
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Status L3 Request */
   IFX_uint16_t L3ReqStatus : 2;
   /** Reserved */
   IFX_uint16_t Res02 : 14;
#endif
} __PACKED__ ;


/**
   Requests the fail reason of a failed near-end initiated L3 request. (see also
   ACK_TxL3RequestStatusGet)
*/
struct CMD_TxL3ReqFailReasonGet
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
   Reports the fail reason of a near-end initiated L3 request, as response to
   CMD_TxL3ReqFailReasonGet.
*/
struct ACK_TxL3ReqFailReasonGet
{
#if MEI_DRV_OS_BYTE_ORDER == MEI_DRV_OS_BIG_ENDIAN
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Reserved */
   IFX_uint16_t Res02 : 8;
   /** L3 Fail Reason */
   IFX_uint16_t L3FailReason : 4;
   /** Reserved */
   IFX_uint16_t Res04 : 4;
#else
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Reserved */
   IFX_uint16_t Res04 : 4;
   /** L3 Fail Reason */
   IFX_uint16_t L3FailReason : 4;
   /** Reserved */
   IFX_uint16_t Res02 : 8;
#endif
} __PACKED__ ;


/**
   Requests information about the loaded FW image. This info is used e.g. for swapping
   between ADSL and VDSL.
*/
struct CMD_FW_ImageInfoGet
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
   Provides the information about the FW image requested by ACK_FW_ImageInfoGet
*/
struct ACK_FW_ImageInfoGet
{
#if MEI_DRV_OS_BYTE_ORDER == MEI_DRV_OS_BIG_ENDIAN
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Reserved */
   IFX_uint16_t Res02 : 13;
   /** Site */
   IFX_uint16_t imageType : 1;
   /** DSL mode */
   IFX_uint16_t dslMode : 1;
   /** Site */
   IFX_uint16_t location : 1;
#else
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Site */
   IFX_uint16_t location : 1;
   /** DSL mode */
   IFX_uint16_t dslMode : 1;
   /** Site */
   IFX_uint16_t imageType : 1;
   /** Reserved */
   IFX_uint16_t Res02 : 13;
#endif
} __PACKED__ ;


/**
   Configuration of the VTU Transmission System Enabling (XTSE).Configures the
   transmission system coding types to be supported on the line (VDSL flavour and annex
   support).
   (References: Section 7.3.1.1.1 of G.997.1 and G.994.1 Amd4 [10] Tables "Standard
   information field – SPar(1) coding")
*/
struct CMD_XTSE_Configure
{
#if MEI_DRV_OS_BYTE_ORDER == MEI_DRV_OS_BIG_ENDIAN
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** ADSL Mode-Bit15: G.992.5, Annex A */
   IFX_uint16_t A15 : 1;
   /** ADSL Mode-Bit14: G.992.5, Annex B */
   IFX_uint16_t A14 : 1;
   /** ADSL Mode-Bit13: G.992.3, Annex M */
   IFX_uint16_t A13 : 1;
   /** ADSL Mode-Bit12: G.992.3, Annex L, US Mask2 */
   IFX_uint16_t A12 : 1;
   /** ADSL Mode-Bit11: G.992.3, Annex L, US Mask1 */
   IFX_uint16_t A11 : 1;
   /** Reserved */
   IFX_uint16_t Res07 : 1;
   /** ADSL Mode-Bit9: G.992.3, Annex B */
   IFX_uint16_t A9 : 1;
   /** ADSL Mode-Bit8: G.992.3, Annex A */
   IFX_uint16_t A8 : 1;
   /** ADSL Mode-Bit7: G.992.5, Annex J */
   IFX_uint16_t A7 : 1;
   /** ADSL Mode-Bit6: G.992.5, Annex I */
   IFX_uint16_t A6 : 1;
   /** ADSL Mode-Bit5: G.992.3, Annex J */
   IFX_uint16_t A5 : 1;
   /** ADSL Mode-Bit4: G.992.3, Annex I */
   IFX_uint16_t A4 : 1;
   /** ADSL Mode-Bit3: G.992.1, Annex B */
   IFX_uint16_t A3 : 1;
   /** ADSL Mode-Bit2: G.992.1, Annex A */
   IFX_uint16_t A2 : 1;
   /** ADSL Mode-Bit1: G.992.5, Annex M */
   IFX_uint16_t A1 : 1;
   /** ADSL Mode-Bit0: T1.413 */
   IFX_uint16_t A0 : 1;
   /** Reserved */
   IFX_uint16_t Res18 : 10;
   /** VDSL Mode-Bit5: VDSL1 Interop, Ikanos FE */
   IFX_uint16_t interopIkanos : 1;
   /** VDSL Mode-Bit4: VDSL1 Interop, Conexant FE */
   IFX_uint16_t interopConexant : 1;
   /** Reserved */
   IFX_uint16_t Res21 : 1;
   /** VDSL Mode-Bit2: VDSL2 */
   IFX_uint16_t V2 : 1;
   /** Reserved */
   IFX_uint16_t Res23 : 1;
   /** VDSL Mode-Bit0: VDSL1 */
   IFX_uint16_t V0 : 1;
#else
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** ADSL Mode-Bit0: T1.413 */
   IFX_uint16_t A0 : 1;
   /** ADSL Mode-Bit1: G.992.5, Annex M */
   IFX_uint16_t A1 : 1;
   /** ADSL Mode-Bit2: G.992.1, Annex A */
   IFX_uint16_t A2 : 1;
   /** ADSL Mode-Bit3: G.992.1, Annex B */
   IFX_uint16_t A3 : 1;
   /** ADSL Mode-Bit4: G.992.3, Annex I */
   IFX_uint16_t A4 : 1;
   /** ADSL Mode-Bit5: G.992.3, Annex J */
   IFX_uint16_t A5 : 1;
   /** ADSL Mode-Bit6: G.992.5, Annex I */
   IFX_uint16_t A6 : 1;
   /** ADSL Mode-Bit7: G.992.5, Annex J */
   IFX_uint16_t A7 : 1;
   /** ADSL Mode-Bit8: G.992.3, Annex A */
   IFX_uint16_t A8 : 1;
   /** ADSL Mode-Bit9: G.992.3, Annex B */
   IFX_uint16_t A9 : 1;
   /** Reserved */
   IFX_uint16_t Res07 : 1;
   /** ADSL Mode-Bit11: G.992.3, Annex L, US Mask1 */
   IFX_uint16_t A11 : 1;
   /** ADSL Mode-Bit12: G.992.3, Annex L, US Mask2 */
   IFX_uint16_t A12 : 1;
   /** ADSL Mode-Bit13: G.992.3, Annex M */
   IFX_uint16_t A13 : 1;
   /** ADSL Mode-Bit14: G.992.5, Annex B */
   IFX_uint16_t A14 : 1;
   /** ADSL Mode-Bit15: G.992.5, Annex A */
   IFX_uint16_t A15 : 1;
   /** VDSL Mode-Bit0: VDSL1 */
   IFX_uint16_t V0 : 1;
   /** Reserved */
   IFX_uint16_t Res23 : 1;
   /** VDSL Mode-Bit2: VDSL2 */
   IFX_uint16_t V2 : 1;
   /** Reserved */
   IFX_uint16_t Res21 : 1;
   /** VDSL Mode-Bit4: VDSL1 Interop, Conexant FE */
   IFX_uint16_t interopConexant : 1;
   /** VDSL Mode-Bit5: VDSL1 Interop, Ikanos FE */
   IFX_uint16_t interopIkanos : 1;
   /** Reserved */
   IFX_uint16_t Res18 : 10;
#endif
} __PACKED__ ;


/**
   Acknowledgement for message CMD_XTSE_Configure.
*/
struct ACK_XTSE_Configure
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
   The message defines priorities for the various flavours/annexes. Now it is for ADSL
   mode only and covers the ADSL1/2/2+ annexes contained as XTSE bits in
   CMD_XTSE_Configure, except T1.413 (see Note 2). Currently as a first step with the
   additional limitation that only one Annex can be enabled for each flavour ADSL1,
   ADSL2, ADSL2+ in CMD_XTSE_Configure and only these get assigned priorities in
   CMD_MultimodePrioSet. The priority numbering starts from 1 (=highest priority).
   Default value for all is the special value FFFFH meaning "no priority assigned".
   Note: Prioritization between VDSL and ADSL is done at the level of the DSL-API.
   Note: T1.413 usage is only controlled by CMD_XTSE_Configure. The logic is to
   always favour GHS over T1.413 if both CO and CPE sides support it.
   Otherwise T1.413 is selected.
*/
struct CMD_MultimodePrioSet
{
#if MEI_DRV_OS_BYTE_ORDER == MEI_DRV_OS_BIG_ENDIAN
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Enable/Disable for the Configurable Priorities */
   IFX_uint16_t prioEnable : 1;
   /** Reserved */
   IFX_uint16_t Res03 : 15;
   /** Reserved */
   IFX_uint16_t Res04;
   /** Priority for G.992.5, Annex M */
   IFX_uint16_t prioXTSE_A1;
   /** Priority for G.992.1, Annex A */
   IFX_uint16_t prioXTSE_A2;
   /** Priority for G.992.1, Annex B */
   IFX_uint16_t prioXTSE_A3;
   /** Priority for G.992.3, Annex I */
   IFX_uint16_t prioXTSE_A4;
   /** Priority for G.992.3, Annex J */
   IFX_uint16_t prioXTSE_A5;
   /** Priority for G.992.5, Annex I */
   IFX_uint16_t prioXTSE_A6;
   /** Priority for G.992.5, Annex J */
   IFX_uint16_t prioXTSE_A7;
   /** Priority for G.992.3, Annex A */
   IFX_uint16_t prioXTSE_A8;
   /** Priority for G.992.3, Annex B */
   IFX_uint16_t prioXTSE_A9;
   /** Reserved */
   IFX_uint16_t Unused;
   /** Priority for G.992.3, Annex L, US Mask1 */
   IFX_uint16_t prioXTSE_A11;
   /** Priority for G.992.3, Annex L, US Mask2 */
   IFX_uint16_t prioXTSE_A12;
   /** Priority for G.992.3, Annex M */
   IFX_uint16_t prioXTSE_A13;
   /** Priority for G.992.5, Annex B */
   IFX_uint16_t prioXTSE_A14;
   /** Priority for G.992.5, Annex A */
   IFX_uint16_t prioXTSE_A15;
#else
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Reserved */
   IFX_uint16_t Res03 : 15;
   /** Enable/Disable for the Configurable Priorities */
   IFX_uint16_t prioEnable : 1;
   /** Reserved */
   IFX_uint16_t Res04;
   /** Priority for G.992.5, Annex M */
   IFX_uint16_t prioXTSE_A1;
   /** Priority for G.992.1, Annex A */
   IFX_uint16_t prioXTSE_A2;
   /** Priority for G.992.1, Annex B */
   IFX_uint16_t prioXTSE_A3;
   /** Priority for G.992.3, Annex I */
   IFX_uint16_t prioXTSE_A4;
   /** Priority for G.992.3, Annex J */
   IFX_uint16_t prioXTSE_A5;
   /** Priority for G.992.5, Annex I */
   IFX_uint16_t prioXTSE_A6;
   /** Priority for G.992.5, Annex J */
   IFX_uint16_t prioXTSE_A7;
   /** Priority for G.992.3, Annex A */
   IFX_uint16_t prioXTSE_A8;
   /** Priority for G.992.3, Annex B */
   IFX_uint16_t prioXTSE_A9;
   /** Reserved */
   IFX_uint16_t Unused;
   /** Priority for G.992.3, Annex L, US Mask1 */
   IFX_uint16_t prioXTSE_A11;
   /** Priority for G.992.3, Annex L, US Mask2 */
   IFX_uint16_t prioXTSE_A12;
   /** Priority for G.992.3, Annex M */
   IFX_uint16_t prioXTSE_A13;
   /** Priority for G.992.5, Annex B */
   IFX_uint16_t prioXTSE_A14;
   /** Priority for G.992.5, Annex A */
   IFX_uint16_t prioXTSE_A15;
#endif
} __PACKED__ ;


/**
   Acknowledgement for message CMD_MultimodePrioSet.
*/
struct ACK_MultimodePrioSet
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
   Controls the downstream band usage.
*/
struct CMD_BandControl_DS_Set
{
#if MEI_DRV_OS_BYTE_ORDER == MEI_DRV_OS_BIG_ENDIAN
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Reserved */
   IFX_uint8_t Res02;
   /** Number of Downstream Bands */
   IFX_uint8_t NumBandsDS;
   /** Band Descriptor DS */
   VNX_ToneIndex_t band[8];
#else
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Number of Downstream Bands */
   IFX_uint8_t NumBandsDS;
   /** Reserved */
   IFX_uint8_t Res02;
   /** Band Descriptor DS */
   VNX_ToneIndex_t band[8];
#endif
} __PACKED__ ;


/**
   Acknowledgement for message CMD_BandControl_DS_Set.
*/
struct ACK_BandControl_DS_Set
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
   Controls the upstream band usage.
   For CO side only, if used to configure normal modem operation in state RESET (and
   not for DMTscope tests). Then the data is transmitted from CO to the CPE during
   initialization (in GHS and FULL_INITIALIZATION state).
   If used for DMTscope tests without handshake and training phases it must be applied
   at the CPE directly.
*/
struct CMD_BandControl_US_Set
{
#if MEI_DRV_OS_BYTE_ORDER == MEI_DRV_OS_BIG_ENDIAN
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Reserved */
   IFX_uint8_t Res02;
   /** Number of Upstream Bands */
   IFX_uint8_t NumBandsUS;
   /** Band Descriptor US */
   VNX_ToneIndex_t band[8];
#else
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Number of Upstream Bands */
   IFX_uint8_t NumBandsUS;
   /** Reserved */
   IFX_uint8_t Res02;
   /** Band Descriptor US */
   VNX_ToneIndex_t band[8];
#endif
} __PACKED__ ;


/**
   Acknowledgement for message CMD_BandControl_US_Set.
*/
struct ACK_BandControl_US_Set
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
   Sets the RFI bands to be notched out in the PSD.
   To delete all already configured RFI bands, apply the message with NumRfiBands=1 and
   RfiBand=(0,0).
   (Chapter 7.3.1.2.10 of G.997.1 [11])
*/
struct CMD_RFI_BandControlSet
{
#if MEI_DRV_OS_BYTE_ORDER == MEI_DRV_OS_BIG_ENDIAN
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Reserved */
   IFX_uint8_t Res02;
   /** Number of RFI Bands */
   IFX_uint8_t NumRfiBands;
   /** RFI Band Descriptor */
   VNX_ToneIndex_t RfiBand[16];
#else
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Number of RFI Bands */
   IFX_uint8_t NumRfiBands;
   /** Reserved */
   IFX_uint8_t Res02;
   /** RFI Band Descriptor */
   VNX_ToneIndex_t RfiBand[16];
#endif
} __PACKED__ ;


/**
   Acknowledgement for message CMD_RFI_BandControlSet.
*/
struct ACK_RFI_BandControlSet
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
   Configures the minimum rate of the message based overhead. (Section 7.3.1.5 of
   G.997.1)
   For VDSL1, the minimum overhead rate refers to the EOC overhead rate. In ADSL mode,
   the message is applicable only for ADSL2/2+.
*/
struct CMD_OH_RateSet
{
#if MEI_DRV_OS_BYTE_ORDER == MEI_DRV_OS_BIG_ENDIAN
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** MSGMINds, Minimum OH Rate DS */
   IFX_uint16_t minOH_RateDS;
   /** MSGMINus, Minimum OH Rate US */
   IFX_uint16_t minOH_RateUS;
#else
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** MSGMINds, Minimum OH Rate DS */
   IFX_uint16_t minOH_RateDS;
   /** MSGMINus, Minimum OH Rate US */
   IFX_uint16_t minOH_RateUS;
#endif
} __PACKED__ ;


/**
   Acknowledgement for message CMD_OH_RateSet.
*/
struct ACK_OH_RateSet
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
   The command configures the windowing for ADSL2+ by setting IFFT windowing
   coefficients in the format of the C-MSG1 message of G.992.5. Only effective if
   "windowing" was enabled with CMD_AlgorithmControlSet.
*/
struct CMD_ADSL_WindowingCoeffSet
{
#if MEI_DRV_OS_BYTE_ORDER == MEI_DRV_OS_BIG_ENDIAN
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Windowing Coefficients */
   IFX_uint16_t winCoeff[8];
#else
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Windowing Coefficients */
   IFX_uint16_t winCoeff[8];
#endif
} __PACKED__ ;


/**
   Acknowledgement for CMD_ADSL_WindowingCoeffSet.
*/
struct ACK_ADSL_WindowingCoeffSet
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
   Configuration of PSD and Power parameters in VDSL and ADSL.
   Attention: Values starting with Parameter 12 are for ADSL multiple Annex
   support. They are valid only if enabled by the special value FFFFH in
   Parameter 2.
   For CO side only unless used for DMTscope tests! If used to configure normal modem
   operation in state RESET (and not for DMTscope tests), the data is transmitted from
   CO to the CPE during initialization. If used for DMTscope tests without handshake
   and training phases it is applicable for both sides.
*/
struct CMD_PSD_Set
{
#if MEI_DRV_OS_BYTE_ORDER == MEI_DRV_OS_BIG_ENDIAN
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** MAXNOMPSDds (VDSL2, ADSL2/2+) */
   IFX_uint16_t MAXNOMPSDds;
   /** MAXNOMPSDus (VDSL2, ADSL2/2+) */
   IFX_uint16_t MAXNOMPSDus;
   /** MAXNOMATPds (VDSL2, ADSL2/2+) */
   IFX_uint16_t MAXNOMATPds;
   /** MAXNOMATPus (VDSL2, ADSL2/2+) */
   IFX_uint16_t MAXNOMATPus;
   /** Reserved */
   IFX_uint16_t Res06;
   /** Reserved */
   IFX_uint16_t Res07[5];
   /** MAXNOMPSDds (ADSL2 Annexes A, B) */
   IFX_uint16_t MAXNOMPSDds_2AB;
   /** MAXNOMPSDus (ADSL2 Annexes A, B) */
   IFX_uint16_t MAXNOMPSDus_2AB;
   /** MAXNOMATPds (ADSL2 Annexes A, B) */
   IFX_uint16_t MAXNOMATPds_2AB;
   /** MAXNOMATPus (ADSL2 Annexes A, B) */
   IFX_uint16_t MAXNOMATPus_2AB;
   /** Reserved */
   IFX_uint16_t Res12;
   /** MAXNOMPSDds (ADSL2+ Annexes A, B) */
   IFX_uint16_t MAXNOMPSDds_2pAB;
   /** MAXNOMPSDus (ADSL2+ Annexes A, B) */
   IFX_uint16_t MAXNOMPSDus_2pAB;
   /** MAXNOMATPds (ADSL2+ Annexes A, B) */
   IFX_uint16_t MAXNOMATPds_2pAB;
   /** MAXNOMATPus (ADSL2+ Annexes A, B) */
   IFX_uint16_t MAXNOMATPus_2pAB;
   /** Reserved */
   IFX_uint16_t Res17;
   /** MAXNOMPSDds (ADSL2 Annex M) */
   IFX_uint16_t MAXNOMPSDds_2M;
   /** MAXNOMPSDus (ADSL2 Annex M) */
   IFX_uint16_t MAXNOMPSDus_2M;
   /** MAXNOMATPds (ADSL2 Annex M) */
   IFX_uint16_t MAXNOMATPds_2M;
   /** MAXNOMATPus (ADSL2 Annex M) */
   IFX_uint16_t MAXNOMATPus_2M;
   /** Reserved */
   IFX_uint16_t Res22;
   /** MAXNOMPSDds (ADSL2+ Annex M) */
   IFX_uint16_t MAXNOMPSDds_2pM;
   /** MAXNOMPSDus (ADSL2+ Annex M) */
   IFX_uint16_t MAXNOMPSDus_2pM;
   /** MAXNOMATPds (ADSL2+ Annex M) */
   IFX_uint16_t MAXNOMATPds_2pM;
   /** MAXNOMATPus (ADSL2+ Annex M) */
   IFX_uint16_t MAXNOMATPus_2pM;
   /** Reserved */
   IFX_uint16_t Res27;
   /** MAXNOMPSDds (ADSL2 Annex J) */
   IFX_uint16_t MAXNOMPSDds_2J;
   /** MAXNOMPSDus (ADSL2 Annex J) */
   IFX_uint16_t MAXNOMPSDus_2J;
   /** MAXNOMATPds (ADSL2 Annex J) */
   IFX_uint16_t MAXNOMATPds_2J;
   /** MAXNOMATPus (ADSL2 Annex J) */
   IFX_uint16_t MAXNOMATPus_2J;
   /** Reserved */
   IFX_uint16_t Res32;
   /** MAXNOMPSDds (ADSL2+ Annex J) */
   IFX_uint16_t MAXNOMPSDds_2pJ;
   /** MAXNOMPSDus (ADSL2+ Annex J) */
   IFX_uint16_t MAXNOMPSDus_2pJ;
   /** MAXNOMATPds (ADSL2+ Annex J) */
   IFX_uint16_t MAXNOMATPds_2pJ;
   /** MAXNOMATPus (ADSL2+ Annex J) */
   IFX_uint16_t MAXNOMATPus_2pJ;
   /** Reserved */
   IFX_uint16_t Res37;
   /** MAXNOMPSDds (ADSL2 Annex I) */
   IFX_uint16_t MAXNOMPSDds_2I;
   /** MAXNOMPSDus (ADSL2 Annex I) */
   IFX_uint16_t MAXNOMPSDus_2I;
   /** MAXNOMATPds (ADSL2 Annex I) */
   IFX_uint16_t MAXNOMATPds_2I;
   /** MAXNOMATPus (ADSL2 Annex I) */
   IFX_uint16_t MAXNOMATPus_2I;
   /** Reserved */
   IFX_uint16_t Res42;
   /** MAXNOMPSDds (ADSL2+ Annex I) */
   IFX_uint16_t MAXNOMPSDds_2pI;
   /** MAXNOMPSDus (ADSL2+ Annex I) */
   IFX_uint16_t MAXNOMPSDus_2pI;
   /** MAXNOMATPds (ADSL2+ Annex I) */
   IFX_uint16_t MAXNOMATPds_2pI;
   /** MAXNOMATPus (ADSL2+ Annex I) */
   IFX_uint16_t MAXNOMATPus_2pI;
   /** Reserved */
   IFX_uint16_t Res47;
   /** MAXNOMPSDds (ADSL2 Annex L Mask1) */
   IFX_uint16_t MAXNOMPSDds_2Lm1;
   /** MAXNOMPSDus (ADSL2 Annex L Mask1) */
   IFX_uint16_t MAXNOMPSDus_2Lm1;
   /** MAXNOMATPds (ADSL2 Annex L Mask1) */
   IFX_uint16_t MAXNOMATPds_2Lm1;
   /** MAXNOMATPus (ADSL2 Annex L Mask1) */
   IFX_uint16_t MAXNOMATPus_2Lm1;
   /** Reserved */
   IFX_uint16_t Res52;
   /** MAXNOMPSDds (ADSL2 Annex L Mask2) */
   IFX_uint16_t MAXNOMPSDds_2Lm2;
   /** MAXNOMPSDus (ADSL2 Annex L Mask2) */
   IFX_uint16_t MAXNOMPSDus_2Lm2;
   /** MAXNOMATPds (ADSL2 Annex L Mask2) */
   IFX_uint16_t MAXNOMATPds_2Lm2;
   /** MAXNOMATPus (ADSL2 Annex L Mask2) */
   IFX_uint16_t MAXNOMATPus_2Lm2;
   /** Reserved */
   IFX_uint16_t Res57;
#else
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** MAXNOMPSDds (VDSL2, ADSL2/2+) */
   IFX_uint16_t MAXNOMPSDds;
   /** MAXNOMPSDus (VDSL2, ADSL2/2+) */
   IFX_uint16_t MAXNOMPSDus;
   /** MAXNOMATPds (VDSL2, ADSL2/2+) */
   IFX_uint16_t MAXNOMATPds;
   /** MAXNOMATPus (VDSL2, ADSL2/2+) */
   IFX_uint16_t MAXNOMATPus;
   /** Reserved */
   IFX_uint16_t Res06;
   /** Reserved */
   IFX_uint16_t Res07[5];
   /** MAXNOMPSDds (ADSL2 Annexes A, B) */
   IFX_uint16_t MAXNOMPSDds_2AB;
   /** MAXNOMPSDus (ADSL2 Annexes A, B) */
   IFX_uint16_t MAXNOMPSDus_2AB;
   /** MAXNOMATPds (ADSL2 Annexes A, B) */
   IFX_uint16_t MAXNOMATPds_2AB;
   /** MAXNOMATPus (ADSL2 Annexes A, B) */
   IFX_uint16_t MAXNOMATPus_2AB;
   /** Reserved */
   IFX_uint16_t Res12;
   /** MAXNOMPSDds (ADSL2+ Annexes A, B) */
   IFX_uint16_t MAXNOMPSDds_2pAB;
   /** MAXNOMPSDus (ADSL2+ Annexes A, B) */
   IFX_uint16_t MAXNOMPSDus_2pAB;
   /** MAXNOMATPds (ADSL2+ Annexes A, B) */
   IFX_uint16_t MAXNOMATPds_2pAB;
   /** MAXNOMATPus (ADSL2+ Annexes A, B) */
   IFX_uint16_t MAXNOMATPus_2pAB;
   /** Reserved */
   IFX_uint16_t Res17;
   /** MAXNOMPSDds (ADSL2 Annex M) */
   IFX_uint16_t MAXNOMPSDds_2M;
   /** MAXNOMPSDus (ADSL2 Annex M) */
   IFX_uint16_t MAXNOMPSDus_2M;
   /** MAXNOMATPds (ADSL2 Annex M) */
   IFX_uint16_t MAXNOMATPds_2M;
   /** MAXNOMATPus (ADSL2 Annex M) */
   IFX_uint16_t MAXNOMATPus_2M;
   /** Reserved */
   IFX_uint16_t Res22;
   /** MAXNOMPSDds (ADSL2+ Annex M) */
   IFX_uint16_t MAXNOMPSDds_2pM;
   /** MAXNOMPSDus (ADSL2+ Annex M) */
   IFX_uint16_t MAXNOMPSDus_2pM;
   /** MAXNOMATPds (ADSL2+ Annex M) */
   IFX_uint16_t MAXNOMATPds_2pM;
   /** MAXNOMATPus (ADSL2+ Annex M) */
   IFX_uint16_t MAXNOMATPus_2pM;
   /** Reserved */
   IFX_uint16_t Res27;
   /** MAXNOMPSDds (ADSL2 Annex J) */
   IFX_uint16_t MAXNOMPSDds_2J;
   /** MAXNOMPSDus (ADSL2 Annex J) */
   IFX_uint16_t MAXNOMPSDus_2J;
   /** MAXNOMATPds (ADSL2 Annex J) */
   IFX_uint16_t MAXNOMATPds_2J;
   /** MAXNOMATPus (ADSL2 Annex J) */
   IFX_uint16_t MAXNOMATPus_2J;
   /** Reserved */
   IFX_uint16_t Res32;
   /** MAXNOMPSDds (ADSL2+ Annex J) */
   IFX_uint16_t MAXNOMPSDds_2pJ;
   /** MAXNOMPSDus (ADSL2+ Annex J) */
   IFX_uint16_t MAXNOMPSDus_2pJ;
   /** MAXNOMATPds (ADSL2+ Annex J) */
   IFX_uint16_t MAXNOMATPds_2pJ;
   /** MAXNOMATPus (ADSL2+ Annex J) */
   IFX_uint16_t MAXNOMATPus_2pJ;
   /** Reserved */
   IFX_uint16_t Res37;
   /** MAXNOMPSDds (ADSL2 Annex I) */
   IFX_uint16_t MAXNOMPSDds_2I;
   /** MAXNOMPSDus (ADSL2 Annex I) */
   IFX_uint16_t MAXNOMPSDus_2I;
   /** MAXNOMATPds (ADSL2 Annex I) */
   IFX_uint16_t MAXNOMATPds_2I;
   /** MAXNOMATPus (ADSL2 Annex I) */
   IFX_uint16_t MAXNOMATPus_2I;
   /** Reserved */
   IFX_uint16_t Res42;
   /** MAXNOMPSDds (ADSL2+ Annex I) */
   IFX_uint16_t MAXNOMPSDds_2pI;
   /** MAXNOMPSDus (ADSL2+ Annex I) */
   IFX_uint16_t MAXNOMPSDus_2pI;
   /** MAXNOMATPds (ADSL2+ Annex I) */
   IFX_uint16_t MAXNOMATPds_2pI;
   /** MAXNOMATPus (ADSL2+ Annex I) */
   IFX_uint16_t MAXNOMATPus_2pI;
   /** Reserved */
   IFX_uint16_t Res47;
   /** MAXNOMPSDds (ADSL2 Annex L Mask1) */
   IFX_uint16_t MAXNOMPSDds_2Lm1;
   /** MAXNOMPSDus (ADSL2 Annex L Mask1) */
   IFX_uint16_t MAXNOMPSDus_2Lm1;
   /** MAXNOMATPds (ADSL2 Annex L Mask1) */
   IFX_uint16_t MAXNOMATPds_2Lm1;
   /** MAXNOMATPus (ADSL2 Annex L Mask1) */
   IFX_uint16_t MAXNOMATPus_2Lm1;
   /** Reserved */
   IFX_uint16_t Res52;
   /** MAXNOMPSDds (ADSL2 Annex L Mask2) */
   IFX_uint16_t MAXNOMPSDds_2Lm2;
   /** MAXNOMPSDus (ADSL2 Annex L Mask2) */
   IFX_uint16_t MAXNOMPSDus_2Lm2;
   /** MAXNOMATPds (ADSL2 Annex L Mask2) */
   IFX_uint16_t MAXNOMATPds_2Lm2;
   /** MAXNOMATPus (ADSL2 Annex L Mask2) */
   IFX_uint16_t MAXNOMATPus_2Lm2;
   /** Reserved */
   IFX_uint16_t Res57;
#endif
} __PACKED__ ;


/**
   For CO side only unless used for DMTscope tests!
   Acknowledgement for the message CMD_PSD_Set.
*/
struct ACK_PSD_Set
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
   Temporary ADSL message!
   This message can be used to adjust the downstream Tx power level precisely with a
   fine granularity within a range of -1 dB to +1 dB. It is to be applied in addition
   (afterwards) to CMD_PSD_Set as long as the MAXNOMPSDds does not reach the required
   precision in the ADSL CO FW.
   To adjust the downstream power level, all six values need to be changed
   simultaneously with the same factor as described below, otherwise the TX power level
   will not be changed consistently.The adjustment by a delta of "X" dB with 0 < |X| £
   1 is done as follows:factor= 10exp(X/20)Updated values of TxAdjust =
   round(orginal_value * factor)
   The current TxAdjust values (=orginal_value) can be read using CMD_ADSL_AuxPSD_Get.
*/
struct CMD_ADSL_AuxPSD_Set
{
#if MEI_DRV_OS_BYTE_ORDER == MEI_DRV_OS_BIG_ENDIAN
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Adjustment Parameter 0 */
   IFX_uint16_t TxAdjust0;
   /** Adjustment Parameter 1 */
   IFX_uint16_t TxAdjust1;
   /** Adjustment Parameter 2 */
   IFX_uint16_t TxAdjust2;
   /** Adjustment Parameter 3 */
   IFX_uint16_t TxAdjust3;
   /** Adjustment Parameter 4 */
   IFX_uint16_t TxAdjust4;
   /** Adjustment Parameter 5 */
   IFX_uint16_t TxAdjust5;
#else
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Adjustment Parameter 0 */
   IFX_uint16_t TxAdjust0;
   /** Adjustment Parameter 1 */
   IFX_uint16_t TxAdjust1;
   /** Adjustment Parameter 2 */
   IFX_uint16_t TxAdjust2;
   /** Adjustment Parameter 3 */
   IFX_uint16_t TxAdjust3;
   /** Adjustment Parameter 4 */
   IFX_uint16_t TxAdjust4;
   /** Adjustment Parameter 5 */
   IFX_uint16_t TxAdjust5;
#endif
} __PACKED__ ;


/**
   Acknowledgement for the message CMD_ADSL_AuxPSD_Set.
*/
struct ACK_ADSL_AuxPSD_Set
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
   Temporary ADSL message!
   Requests the current downstream Tx power level scaling factors. These values are
   only necessary to calculate the parameters to be written with CMD_ADSL_AuxPSD_Set
   for DS power trimming.
*/
struct CMD_ADSL_AuxPSD_Get
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
   Temporary ADSL message!
   Provides the values of the downstream Tx power level scaling factors as requested by
   CMD_ADSL_AuxPSD_Get. Based on these values a power trimming can be done using
   CMD_ADSL_AuxPSD_Set.
*/
struct ACK_ADSL_AuxPSD_Get
{
#if MEI_DRV_OS_BYTE_ORDER == MEI_DRV_OS_BIG_ENDIAN
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Adjustment Parameter 0 */
   IFX_uint16_t TxAdjust0;
   /** Adjustment Parameter 1 */
   IFX_uint16_t TxAdjust1;
   /** Adjustment Parameter 2 */
   IFX_uint16_t TxAdjust2;
   /** Adjustment Parameter 3 */
   IFX_uint16_t TxAdjust3;
   /** Adjustment Parameter 4 */
   IFX_uint16_t TxAdjust4;
   /** Adjustment Parameter 5 */
   IFX_uint16_t TxAdjust5;
#else
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Adjustment Parameter 0 */
   IFX_uint16_t TxAdjust0;
   /** Adjustment Parameter 1 */
   IFX_uint16_t TxAdjust1;
   /** Adjustment Parameter 2 */
   IFX_uint16_t TxAdjust2;
   /** Adjustment Parameter 3 */
   IFX_uint16_t TxAdjust3;
   /** Adjustment Parameter 4 */
   IFX_uint16_t TxAdjust4;
   /** Adjustment Parameter 5 */
   IFX_uint16_t TxAdjust5;
#endif
} __PACKED__ ;


/**
   Controls the transmit signal at the VTU-O via transmit PSD breakpoints (along with
   the MAXNOMPSD).These PSD breakpoints shape the PSD level relative to the MAXNOMPSD.
   (Chapter 7.3.1.2.9 of G.997.1)
   Note: TxPSDs consisting of more than 42 PSD breakpoints must be written with 2
   messages!
*/
struct CMD_PSD_BreakpointsTxDS_Set
{
#if MEI_DRV_OS_BYTE_ORDER == MEI_DRV_OS_BIG_ENDIAN
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Data */
   VNX_PSD_TxDS_t Data;
#else
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Data */
   VNX_PSD_TxDS_t Data;

#endif
} __PACKED__ ;


/**
   Acknowledgement for the message CMD_PSD_BreakpointsTxDS_Set.
*/
struct ACK_PSD_BreakpointsTxDS_Set
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
   Specifies the maximum upstream transmit PSD by means of breakpoints. Values are set
   at the VTU-O and transferred to the VTU-R in the O-SIGNATURE message (except if used
   for DMTscope). See chapter 12.4.4 in G.993.1 [4] and chapter 12.2.4.2.1 in G.993.2
   [5].
   If used for DMTscope tests without handshake and training phases it must be applied
   at the VTU-R directly.
*/
struct CMD_PSD_BreakpointsTxUS_Set
{
#if MEI_DRV_OS_BYTE_ORDER == MEI_DRV_OS_BIG_ENDIAN
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Reserved */
   IFX_uint8_t Res02;
   /** Number of Breakpoints */
   IFX_uint8_t NumBreakPts;
   /** Breakpoint Descriptor TxPSDus */
   VNX_PSDbreak_t breakpoint[32];
#else
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Number of Breakpoints */
   IFX_uint8_t NumBreakPts;
   /** Reserved */
   IFX_uint8_t Res02;
   /** Breakpoint Descriptor TxPSDus */
   VNX_PSDbreak_t breakpoint[32];
#endif
} __PACKED__ ;


/**
   Acknowledgement for the message CMD_PSD_BreakpointsTxUS_Set.
*/
struct ACK_PSD_BreakpointsTxUS_Set
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
   For VDSL1 only. In VDSL2 use CMD_PSD_BreakpointsRxRef2US_Set.
   Specifies the Upstream Receive Reference PSD by means of breakpoints. It is used for
   upstream power back-off (UPBO). Values are set at the VTU-O and transferred to the
   VTU-R in the O-SIGNATURE message (See chapter 12.4.4 in G.993.1 [4]).
*/
struct CMD_PSD_BreakpointsRxRefUS_Set
{
#if MEI_DRV_OS_BYTE_ORDER == MEI_DRV_OS_BIG_ENDIAN
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Reserved */
   IFX_uint8_t Res02;
   /** Number of Breakpoints */
   IFX_uint8_t NumBreakPts;
   /** Breakpoint Descriptor RxRef PSD */
   VNX_PSDbreak_t breakpoint[32];
#else
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Number of Breakpoints */
   IFX_uint8_t NumBreakPts;
   /** Reserved */
   IFX_uint8_t Res02;
   /** Breakpoint Descriptor RxRef PSD */
   VNX_PSDbreak_t breakpoint[32];
#endif
} __PACKED__ ;


/**
   Acknowledgement for the message CMD_PSD_BreakpointsRxRefUS_Set.
*/
struct ACK_PSD_BreakpointsRxRefUS_Set
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
   Specifies the VDSL2 Upstream Receive Reference PSD (=UPBOPSD) in the (a, b) format
   (Section 7.3.1.2.14 of G997.1). Contains the parameters to compute the reference PSD
   that shall be used for the calculation of upstream power back-off (UPBO). One couple
   of parameters (a, b) is defined per upstream band (except US0). Values are set at
   the VTU-O and transferred to the VTU-R in the O-SIGNATURE message (See chapter
   12.2.4 in G.993.2 [5]).
*/
struct CMD_PSD_BreakpointsRxRef2US_Set
{
#if MEI_DRV_OS_BYTE_ORDER == MEI_DRV_OS_BIG_ENDIAN
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Reserved */
   IFX_uint8_t Res02;
   /** Number of Bands */
   IFX_uint8_t numOfBands;
   /** (a, b) UPBO RxRef2 PSD Descriptor */
   VNX_RxRef2PSD_t a_b_set[7];
#else
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Number of Bands */
   IFX_uint8_t numOfBands;
   /** Reserved */
   IFX_uint8_t Res02;
   /** (a, b) UPBO RxRef2 PSD Descriptor */
   VNX_RxRef2PSD_t a_b_set[7];
#endif
} __PACKED__ ;


/**
   Acknowledgement for the message CMD_PSD_BreakpointsRxRef2US_Set.
*/
struct ACK_PSD_BreakpointsRxRef2US_Set
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
   Controls the Upstream Power Back-Off (UPBO) mode of operation. There are 2 modes: an
   "UPBO standard mode" (§ 7.3.1.2.14 of G997.1) and an "UPBO boost mode".
*/
struct CMD_PBO_Control
{
#if MEI_DRV_OS_BYTE_ORDER == MEI_DRV_OS_BIG_ENDIAN
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Reserved */
   IFX_uint16_t Res02 : 13;
   /** UPBO Verification Enable */
   IFX_uint16_t UPBOCheck : 1;
   /** UPBO Boost Mode Enable */
   IFX_uint16_t UPBOBoost : 1;
   /** Force CO-MIB Electrical Loop Length */
   IFX_uint16_t UPBOKO : 1;
   /** UPBOKL */
   IFX_uint16_t UPBOKL;
   /** kl0_start */
   IFX_uint16_t kl0_start;
   /** kl0_stop */
   IFX_uint16_t kl0_stop;
   /** FREFstart */
   IFX_uint16_t FREFstart;
   /** FREFstop */
   IFX_uint16_t FREFstop;
   /** KLREFstart */
   IFX_uint16_t KLREFstart;
   /** KLREFstop */
   IFX_uint16_t KLREFstop;
   /** UPBO Check Sensitivity */
   IFX_int16_t sensitivity;
#else
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Force CO-MIB Electrical Loop Length */
   IFX_uint16_t UPBOKO : 1;
   /** UPBO Boost Mode Enable */
   IFX_uint16_t UPBOBoost : 1;
   /** UPBO Verification Enable */
   IFX_uint16_t UPBOCheck : 1;
   /** Reserved */
   IFX_uint16_t Res02 : 13;
   /** UPBOKL */
   IFX_uint16_t UPBOKL;
   /** kl0_start */
   IFX_uint16_t kl0_start;
   /** kl0_stop */
   IFX_uint16_t kl0_stop;
   /** FREFstart */
   IFX_uint16_t FREFstart;
   /** FREFstop */
   IFX_uint16_t FREFstop;
   /** KLREFstart */
   IFX_uint16_t KLREFstart;
   /** KLREFstop */
   IFX_uint16_t KLREFstop;
   /** UPBO Check Sensitivity */
   IFX_int16_t sensitivity;
#endif
} __PACKED__ ;


/**
   Acknowledgement for the message CMD_PBO_Control.
*/
struct ACK_PBO_Control
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
   Requests the electrical loop length estimate kl0.
*/
struct CMD_UPBO_KL0Get
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
   Delivers the data requested by CMD_UPBO_KL0Get.
   (Section 7.5.1.23 of G.997.1 [11])
*/
struct ACK_UPBO_KL0Get
{
#if MEI_DRV_OS_BYTE_ORDER == MEI_DRV_OS_BIG_ENDIAN
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Kl0 Estimate VTU-O */
   IFX_uint16_t kl0_EstimO;
   /** Kl0 Estimate VTU-R */
   IFX_uint16_t kl0_EstimR;
#else
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Kl0 Estimate VTU-O */
   IFX_uint16_t kl0_EstimO;
   /** Kl0 Estimate VTU-R */
   IFX_uint16_t kl0_EstimR;
#endif
} __PACKED__ ;


/**
   Enables for each VDSL2 Profile an adaptive PSD optimization (ceiling) algorithm.
   Currently only required for Profile 8b due to the high transmit power.
*/
struct CMD_PSD_CeilingDS_Set
{
#if MEI_DRV_OS_BYTE_ORDER == MEI_DRV_OS_BIG_ENDIAN
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Reserved */
   IFX_uint8_t Res02;
   /** Enable PSD Ceiling Optimization for Profile 30a */
   IFX_uint16_t PSDCeil7 : 1;
   /** Enable PSD Ceiling Optimization for Profile 17a */
   IFX_uint16_t PSDCeil6 : 1;
   /** Enable PSD Ceiling Optimization for Profile 12b */
   IFX_uint16_t PSDCeil5 : 1;
   /** Enable PSD Ceiling Optimization for Profile 12a */
   IFX_uint16_t PSDCeil4 : 1;
   /** Enable PSD Ceiling Optimization for Profile 8d */
   IFX_uint16_t PSDCeil3 : 1;
   /** Enable PSD Ceiling Optimization for Profile 8c */
   IFX_uint16_t PSDCeil2 : 1;
   /** Enable PSD Ceiling Optimization for Profile 8b */
   IFX_uint16_t PSDCeil1 : 1;
   /** Enable PSD Ceiling Optimization for Profile 8a */
   IFX_uint16_t PSDCeil0 : 1;
#else
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Enable PSD Ceiling Optimization for Profile 8a */
   IFX_uint16_t PSDCeil0 : 1;
   /** Enable PSD Ceiling Optimization for Profile 8b */
   IFX_uint16_t PSDCeil1 : 1;
   /** Enable PSD Ceiling Optimization for Profile 8c */
   IFX_uint16_t PSDCeil2 : 1;
   /** Enable PSD Ceiling Optimization for Profile 8d */
   IFX_uint16_t PSDCeil3 : 1;
   /** Enable PSD Ceiling Optimization for Profile 12a */
   IFX_uint16_t PSDCeil4 : 1;
   /** Enable PSD Ceiling Optimization for Profile 12b */
   IFX_uint16_t PSDCeil5 : 1;
   /** Enable PSD Ceiling Optimization for Profile 17a */
   IFX_uint16_t PSDCeil6 : 1;
   /** Enable PSD Ceiling Optimization for Profile 30a */
   IFX_uint16_t PSDCeil7 : 1;
   /** Reserved */
   IFX_uint8_t Res02;
#endif
} __PACKED__ ;


/**
   Acknowledgement for message CMD_PSD_CeilingDS_Set.
*/
struct ACK_PSD_CeilingDS_Set
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
   Configuration of noise margin parameters.
*/
struct CMD_NoiseMarginSet
{
#if MEI_DRV_OS_BYTE_ORDER == MEI_DRV_OS_BIG_ENDIAN
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Noise Margin Configuration Parameter: TARSNRMds */
   IFX_uint16_t TARSNRMds;
   /** Noise Margin Configuration Parameter: TARSNRMus */
   IFX_uint16_t TARSNRMus;
   /** Noise Margin Configuration Parameter: MAXSNRMds */
   IFX_uint16_t MAXSNRMds;
   /** Noise Margin Configuration Parameter: MAXSNRMus */
   IFX_uint16_t MAXSNRMus;
   /** Noise Margin Configuration Parameter: MINSNRMds */
   IFX_uint16_t MINSNRMds;
   /** Noise Margin Configuration Parameter: MINSNRMus */
   IFX_uint16_t MINSNRMus;
#else
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Noise Margin Configuration Parameter: TARSNRMds */
   IFX_uint16_t TARSNRMds;
   /** Noise Margin Configuration Parameter: TARSNRMus */
   IFX_uint16_t TARSNRMus;
   /** Noise Margin Configuration Parameter: MAXSNRMds */
   IFX_uint16_t MAXSNRMds;
   /** Noise Margin Configuration Parameter: MAXSNRMus */
   IFX_uint16_t MAXSNRMus;
   /** Noise Margin Configuration Parameter: MINSNRMds */
   IFX_uint16_t MINSNRMds;
   /** Noise Margin Configuration Parameter: MINSNRMus */
   IFX_uint16_t MINSNRMus;
#endif
} __PACKED__ ;


/**
   Acknowledgement for the message CMD_NoiseMarginSet.
*/
struct ACK_NoiseMarginSet
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
   Configuration of a target noise margin delta, which is added to the target noise
   margin value configured at the CO (and in case of the CPE received from there). The
   resulting value is then taken as target noise margin, e.g. for bit loading.
*/
struct CMD_NoiseMarginDeltaSet
{
#if MEI_DRV_OS_BYTE_ORDER == MEI_DRV_OS_BIG_ENDIAN
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Target Noise Margin Delta DS (ADSL and VDSL) */
   IFX_int16_t deltaTARSNRMds;
   /** Target Noise Margin Delta US (VDSL only) */
   IFX_int16_t deltaTARSNRMus;
#else
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Target Noise Margin Delta DS (ADSL and VDSL) */
   IFX_int16_t deltaTARSNRMds;
   /** Target Noise Margin Delta US (VDSL only) */
   IFX_int16_t deltaTARSNRMus;
#endif
} __PACKED__ ;


/**
   Acknowledgement for the message CMD_NoiseMarginDeltaSet.
*/
struct ACK_NoiseMarginDeltaSet
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
   Sets the TSSI breakpoints for PSD shaping in ADSL2+ Annex A/B/I/J in downstream
   direction.
   Note: Not applicable in ADSL1.
   Note: ADSL2 Annex A/B/I/J is configured with CMD_TssiDS_ADSL2ABIJ_Set since FW
   w.3.x.y.z.a.
*/
struct CMD_TssiDS_ADSL_Set
{
#if MEI_DRV_OS_BYTE_ORDER == MEI_DRV_OS_BIG_ENDIAN
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Handshake Control */
   IFX_uint16_t HS_enable : 1;
   /** Reserved */
   IFX_uint16_t Res03 : 7;
   /** Number of Breakpoints */
   IFX_uint8_t NumBreakPt;
   /** TSSI Breakpoints */
   VNX_TSSIbreak_t tssiBreakpt[60];
#else
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Number of Breakpoints */
   IFX_uint8_t NumBreakPt;
   /** Reserved */
   IFX_uint16_t Res03 : 7;
   /** Handshake Control */
   IFX_uint16_t HS_enable : 1;
   /** TSSI Breakpoints */
   VNX_TSSIbreak_t tssiBreakpt[60];
#endif
} __PACKED__ ;


/**
   This is the acknowledgement for CMD_TssiDS_ADSL_Set.
*/
struct ACK_TssiDS_ADSL_Set
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
   Sets the TSSI breakpoints for PSD shaping for ADSL2 Annex A,B,I,J in downstream
   direction.
   Note: Not applicable in ADSL1.
*/
struct CMD_TssiDS_ADSL2ABIJ_Set
{
#if MEI_DRV_OS_BYTE_ORDER == MEI_DRV_OS_BIG_ENDIAN
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Handshake Control */
   IFX_uint16_t HS_enable : 1;
   /** Reserved */
   IFX_uint16_t Res03 : 7;
   /** Number of Breakpoints */
   IFX_uint8_t NumBreakPt;
   /** TSSI Breakpoints */
   VNX_TSSIbreak_t tssiBreakpt[60];
#else
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Number of Breakpoints */
   IFX_uint8_t NumBreakPt;
   /** Reserved */
   IFX_uint16_t Res03 : 7;
   /** Handshake Control */
   IFX_uint16_t HS_enable : 1;
   /** TSSI Breakpoints */
   VNX_TSSIbreak_t tssiBreakpt[60];
#endif
} __PACKED__ ;


/**
   This is the acknowledgement for CMD_TssiDS_ADSL2ABIJ_Set.
*/
struct ACK_TssiDS_ADSL2ABIJ_Set
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
   Sets the TSSI breakpoints for PSD shaping for ADSL in downstream direction. For
   ADSL2 Annex M.
   Note: Not applicable in ADSL1.
*/
struct CMD_TssiDS_ADSL2M_Set
{
#if MEI_DRV_OS_BYTE_ORDER == MEI_DRV_OS_BIG_ENDIAN
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Handshake Control */
   IFX_uint16_t HS_enable : 1;
   /** Reserved */
   IFX_uint16_t Res03 : 7;
   /** Number of Breakpoints */
   IFX_uint8_t NumBreakPt;
   /** TSSI Breakpoints */
   VNX_TSSIbreak_t tssiBreakpt[60];
#else
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Number of Breakpoints */
   IFX_uint8_t NumBreakPt;
   /** Reserved */
   IFX_uint16_t Res03 : 7;
   /** Handshake Control */
   IFX_uint16_t HS_enable : 1;
   /** TSSI Breakpoints */
   VNX_TSSIbreak_t tssiBreakpt[60];
#endif
} __PACKED__ ;


/**
   This is the acknowledgement for CMD_TssiDS_ADSL2M_Set.
*/
struct ACK_TssiDS_ADSL2M_Set
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
   Sets the TSSI breakpoints for PSD shaping in downstream direction for ADSL2+ Annex
   M.
   Note: Not applicable in ADSL1.
*/
struct CMD_TssiDS_ADSL2pM_Set
{
#if MEI_DRV_OS_BYTE_ORDER == MEI_DRV_OS_BIG_ENDIAN
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Handshake Control */
   IFX_uint16_t HS_enable : 1;
   /** Reserved */
   IFX_uint16_t Res03 : 7;
   /** Number of Breakpoints */
   IFX_uint8_t NumBreakPt;
   /** TSSI Breakpoints */
   VNX_TSSIbreak_t tssiBreakpt[60];
#else
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Number of Breakpoints */
   IFX_uint8_t NumBreakPt;
   /** Reserved */
   IFX_uint16_t Res03 : 7;
   /** Handshake Control */
   IFX_uint16_t HS_enable : 1;
   /** TSSI Breakpoints */
   VNX_TSSIbreak_t tssiBreakpt[60];
#endif
} __PACKED__ ;


/**
   This is the acknowledgement for CMD_TssiDS_ADSL2pM_Set.
*/
struct ACK_TssiDS_ADSL2pM_Set
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
   Sets the TSSI breakpoints for PSD shaping in downstream direction for ADSL2 Annex
   L.
   Note: Not applicable in ADSL1.
*/
struct CMD_TssiDS_ADSL2L_Set
{
#if MEI_DRV_OS_BYTE_ORDER == MEI_DRV_OS_BIG_ENDIAN
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Handshake Control */
   IFX_uint16_t HS_enable : 1;
   /** Reserved */
   IFX_uint16_t Res03 : 7;
   /** Number of Breakpoints */
   IFX_uint8_t NumBreakPt;
   /** TSSI Breakpoints */
   VNX_TSSIbreak_t tssiBreakpt[60];
#else
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Number of Breakpoints */
   IFX_uint8_t NumBreakPt;
   /** Reserved */
   IFX_uint16_t Res03 : 7;
   /** Handshake Control */
   IFX_uint16_t HS_enable : 1;
   /** TSSI Breakpoints */
   VNX_TSSIbreak_t tssiBreakpt[60];
#endif
} __PACKED__ ;


/**
   This is the acknowledgement for CMD_TssiDS_ADSL2L_Set.
*/
struct ACK_TssiDS_ADSL2L_Set
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
   Sets the TSSI breakpoints for ADSL2+ Annexes A, B in upstream direction. The US
   TSSI’s are used for RFI notching/carrier masking only.
   Note: Not applicable in ADSL1.
   Note: ADSL2 Annex A/B/L is configured with CMD_TssiUS_ADSL2ABL_Set since FW
   w.3.x.y.z.a.
*/
struct CMD_TssiUS_ADSL_Set
{
#if MEI_DRV_OS_BYTE_ORDER == MEI_DRV_OS_BIG_ENDIAN
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Handshake Control */
   IFX_uint16_t HS_enable : 1;
   /** Reserved */
   IFX_uint16_t Res03 : 7;
   /** Number of Breakpoints */
   IFX_uint8_t NumBreakPt;
   /** TSSI Breakpoints */
   VNX_TSSIbreak_t tssiBreakpt[4];
#else
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Number of Breakpoints */
   IFX_uint8_t NumBreakPt;
   /** Reserved */
   IFX_uint16_t Res03 : 7;
   /** Handshake Control */
   IFX_uint16_t HS_enable : 1;
   /** TSSI Breakpoints */
   VNX_TSSIbreak_t tssiBreakpt[4];
#endif
} __PACKED__ ;


/**
   This is the acknowledgement for CMD_TssiUS_ADSL_Set.
*/
struct ACK_TssiUS_ADSL_Set
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
   Sets the TSSI breakpoints for ADSL2 Annex A/B/L upstream direction. The US TSSI’s
   are used for RFI notching/carrier masking only.
   Note: Not applicable in ADSL1.
*/
struct CMD_TssiUS_ADSL2ABL_Set
{
#if MEI_DRV_OS_BYTE_ORDER == MEI_DRV_OS_BIG_ENDIAN
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Handshake Control */
   IFX_uint16_t HS_enable : 1;
   /** Reserved */
   IFX_uint16_t Res03 : 7;
   /** Number of Breakpoints */
   IFX_uint8_t NumBreakPt;
   /** TSSI Breakpoints */
   VNX_TSSIbreak_t tssiBreakpt[4];
#else
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Number of Breakpoints */
   IFX_uint8_t NumBreakPt;
   /** Reserved */
   IFX_uint16_t Res03 : 7;
   /** Handshake Control */
   IFX_uint16_t HS_enable : 1;
   /** TSSI Breakpoints */
   VNX_TSSIbreak_t tssiBreakpt[4];
#endif
} __PACKED__ ;


/**
   This is the acknowledgement for CMD_TssiUS_ADSL2ABL_Set.
*/
struct ACK_TssiUS_ADSL2ABL_Set
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
   Sets the TSSI breakpoints for ADSL2 Annex M in upstream direction. The US TSSI’s are
   used for RFI notching/carrier masking only.
   Note: Not applicable in ADSL1.
*/
struct CMD_TssiUS_ADSL2M_Set
{
#if MEI_DRV_OS_BYTE_ORDER == MEI_DRV_OS_BIG_ENDIAN
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Handshake Control */
   IFX_uint16_t HS_enable : 1;
   /** Reserved */
   IFX_uint16_t Res03 : 7;
   /** Number of Breakpoints */
   IFX_uint8_t NumBreakPt;
   /** TSSI Breakpoints */
   VNX_TSSIbreak_t tssiBreakpt[4];
#else
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Number of Breakpoints */
   IFX_uint8_t NumBreakPt;
   /** Reserved */
   IFX_uint16_t Res03 : 7;
   /** Handshake Control */
   IFX_uint16_t HS_enable : 1;
   /** TSSI Breakpoints */
   VNX_TSSIbreak_t tssiBreakpt[4];
#endif
} __PACKED__ ;


/**
   This is the acknowledgement for CMD_TssiUS_ADSL2M_Set.
*/
struct ACK_TssiUS_ADSL2M_Set
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
   Sets the TSSI breakpoints for ADSL2+ Annex M in upstream direction. This US TSSI
   message is used for RFI notching/carrier masking only.
   Note: Not applicable in ADSL1.
*/
struct CMD_TssiUS_ADSL2pM_Set
{
#if MEI_DRV_OS_BYTE_ORDER == MEI_DRV_OS_BIG_ENDIAN
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Handshake Control */
   IFX_uint16_t HS_enable : 1;
   /** Reserved */
   IFX_uint16_t Res03 : 7;
   /** Number of Breakpoints */
   IFX_uint8_t NumBreakPt;
   /** TSSI Breakpoints */
   VNX_TSSIbreak_t tssiBreakpt[4];
#else
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Number of Breakpoints */
   IFX_uint8_t NumBreakPt;
   /** Reserved */
   IFX_uint16_t Res03 : 7;
   /** Handshake Control */
   IFX_uint16_t HS_enable : 1;
   /** TSSI Breakpoints */
   VNX_TSSIbreak_t tssiBreakpt[4];
#endif
} __PACKED__ ;


/**
   This is the acknowledgement for CMD_TssiUS_ADSL2pM_Set.
*/
struct ACK_TssiUS_ADSL2pM_Set
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
   Sets the TSSI breakpoints for ADSL2 Annexes I, J in upstream direction. This US TSSI
   message is used for RFI notching/carrier masking only.
   Note: Not applicable in ADSL1.
*/
struct CMD_TssiUS_ADSL2IJ_Set
{
#if MEI_DRV_OS_BYTE_ORDER == MEI_DRV_OS_BIG_ENDIAN
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Handshake Control */
   IFX_uint16_t HS_enable : 1;
   /** Reserved */
   IFX_uint16_t Res03 : 7;
   /** Number of Breakpoints */
   IFX_uint8_t NumBreakPt;
   /** TSSI Breakpoints */
   VNX_TSSIbreak_t tssiBreakpt[4];
#else
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Number of Breakpoints */
   IFX_uint8_t NumBreakPt;
   /** Reserved */
   IFX_uint16_t Res03 : 7;
   /** Handshake Control */
   IFX_uint16_t HS_enable : 1;
   /** TSSI Breakpoints */
   VNX_TSSIbreak_t tssiBreakpt[4];
#endif
} __PACKED__ ;


/**
   This is the acknowledgement for CMD_TssiUS_ADSL2IJ_Set.
*/
struct ACK_TssiUS_ADSL2IJ_Set
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
   Sets the TSSI breakpoints for ADSL2+ Annexes I, J in upstream direction. This US
   TSSI message is used for RFI notching/carrier masking only.
   Note: Not applicable in ADSL1.
*/
struct CMD_TssiUS_ADSL2pIJ_Set
{
#if MEI_DRV_OS_BYTE_ORDER == MEI_DRV_OS_BIG_ENDIAN
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Handshake Control */
   IFX_uint16_t HS_enable : 1;
   /** Reserved */
   IFX_uint16_t Res03 : 7;
   /** Number of Breakpoints */
   IFX_uint8_t NumBreakPt;
   /** TSSI Breakpoints */
   VNX_TSSIbreak_t tssiBreakpt[4];
#else
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Number of Breakpoints */
   IFX_uint8_t NumBreakPt;
   /** Reserved */
   IFX_uint16_t Res03 : 7;
   /** Handshake Control */
   IFX_uint16_t HS_enable : 1;
   /** TSSI Breakpoints */
   VNX_TSSIbreak_t tssiBreakpt[4];
#endif
} __PACKED__ ;


/**
   This is the acknowledgement for CMD_TssiUS_ADSL2IJ_Set.
*/
struct ACK_TssiUS_ADSL2pIJ_Set
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
   Selects the ADSL Annex M upstream mask. To be applied only in combination with
   G.992.3/5 Annex M support in CMD_XTSE_Configure. A selected US PSD mask cannot be
   additionally shaped with CMD_ADSL_PSD_ShapeUS_Set (the latter would be ignored). RFI
   notching and carrier masking can be done.
*/
struct CMD_ADSL_M_MaskUS_Select
{
#if MEI_DRV_OS_BYTE_ORDER == MEI_DRV_OS_BIG_ENDIAN
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Reserved */
   IFX_uint16_t Res02 : 7;
   /** G.992.3/5 Annex M Upstream Mask 9 */
   IFX_uint16_t mask9 : 1;
   /** G.992.3/5 Annex M Upstream Mask 8 */
   IFX_uint16_t mask8 : 1;
   /** G.992.3/5 Annex M Upstream Mask 7 */
   IFX_uint16_t mask7 : 1;
   /** G.992.3/5 Annex M Upstream Mask 6 */
   IFX_uint16_t mask6 : 1;
   /** G.992.3/5 Annex M Upstream Mask 5 */
   IFX_uint16_t mask5 : 1;
   /** G.992.3/5 Annex M Upstream Mask 4 */
   IFX_uint16_t mask4 : 1;
   /** G.992.3/5 Annex M Upstream Mask 3 */
   IFX_uint16_t mask3 : 1;
   /** G.992.3/5 Annex M Upstream Mask 2 */
   IFX_uint16_t mask2 : 1;
   /** G.992.3/5 Annex M Upstream Mask 1 */
   IFX_uint16_t mask1 : 1;
#else
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** G.992.3/5 Annex M Upstream Mask 1 */
   IFX_uint16_t mask1 : 1;
   /** G.992.3/5 Annex M Upstream Mask 2 */
   IFX_uint16_t mask2 : 1;
   /** G.992.3/5 Annex M Upstream Mask 3 */
   IFX_uint16_t mask3 : 1;
   /** G.992.3/5 Annex M Upstream Mask 4 */
   IFX_uint16_t mask4 : 1;
   /** G.992.3/5 Annex M Upstream Mask 5 */
   IFX_uint16_t mask5 : 1;
   /** G.992.3/5 Annex M Upstream Mask 6 */
   IFX_uint16_t mask6 : 1;
   /** G.992.3/5 Annex M Upstream Mask 7 */
   IFX_uint16_t mask7 : 1;
   /** G.992.3/5 Annex M Upstream Mask 8 */
   IFX_uint16_t mask8 : 1;
   /** G.992.3/5 Annex M Upstream Mask 9 */
   IFX_uint16_t mask9 : 1;
   /** Reserved */
   IFX_uint16_t Res02 : 7;
#endif
} __PACKED__ ;


/**
   This is the acknowledgement for CMD_ADSL_M_MaskUS_Select.
*/
struct ACK_ADSL_M_MaskUS_Select
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
   Selects the ADSL Annex J upstream mask. To be applied only in combination with
   G.992.3/5 Annex J in CMD_XTSE_Configure. A selected US PSD mask cannot be
   additionally shaped with CMD_ADSL_PSD_ShapeUS_Set (the latter would be ignored). RFI
   notching and carrier masking can be done.
*/
struct CMD_ADSL_J_MaskUS_Select
{
#if MEI_DRV_OS_BYTE_ORDER == MEI_DRV_OS_BIG_ENDIAN
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Reserved */
   IFX_uint16_t Res02 : 7;
   /** G.992.3/5 Annex J Upstream Mask 9 */
   IFX_uint16_t mask9 : 1;
   /** G.992.3/5 Annex J Upstream Mask 8 */
   IFX_uint16_t mask8 : 1;
   /** G.992.3/5 Annex J Upstream Mask 7 */
   IFX_uint16_t mask7 : 1;
   /** G.992.3/5 Annex J Upstream Mask 6 */
   IFX_uint16_t mask6 : 1;
   /** G.992.3/5 Annex J Upstream Mask 5 */
   IFX_uint16_t mask5 : 1;
   /** G.992.3/5 Annex J Upstream Mask 4 */
   IFX_uint16_t mask4 : 1;
   /** G.992.3/5 Annex J Upstream Mask 3 */
   IFX_uint16_t mask3 : 1;
   /** G.992.3/5 Annex J Upstream Mask 2 */
   IFX_uint16_t mask2 : 1;
   /** G.992.3/5 Annex J Upstream Mask 1 */
   IFX_uint16_t mask1 : 1;
#else
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** G.992.3/5 Annex J Upstream Mask 1 */
   IFX_uint16_t mask1 : 1;
   /** G.992.3/5 Annex J Upstream Mask 2 */
   IFX_uint16_t mask2 : 1;
   /** G.992.3/5 Annex J Upstream Mask 3 */
   IFX_uint16_t mask3 : 1;
   /** G.992.3/5 Annex J Upstream Mask 4 */
   IFX_uint16_t mask4 : 1;
   /** G.992.3/5 Annex J Upstream Mask 5 */
   IFX_uint16_t mask5 : 1;
   /** G.992.3/5 Annex J Upstream Mask 6 */
   IFX_uint16_t mask6 : 1;
   /** G.992.3/5 Annex J Upstream Mask 7 */
   IFX_uint16_t mask7 : 1;
   /** G.992.3/5 Annex J Upstream Mask 8 */
   IFX_uint16_t mask8 : 1;
   /** G.992.3/5 Annex J Upstream Mask 9 */
   IFX_uint16_t mask9 : 1;
   /** Reserved */
   IFX_uint16_t Res02 : 7;
#endif
} __PACKED__ ;


/**
   This is the acknowledgement for CMD_ADSL_J_MaskUS_Select.
*/
struct ACK_ADSL_J_MaskUS_Select
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
   Specifies the upstream transmit PSD mask for ADSL2/2+ Annexes M and J by means of
   breakpoints. Values are set at the CO and transferred to the CPE during the G.994.1
   handshake phase (CL message with Submode_PSD_Shape parameter block), the CPE then
   derives its tssi’s accordingly.
   (Section 7.3.1.2.12 of G.997.1 [11] and J.3.4.3 of G.992.3 [2].)
   Attention: US PSD shaping (with this message) and US PSD mask selection
   (CMD_ADSL_J_MaskUS_Select or CMD_ADSL_M_MaskUS_Select) cannot be used
   simultaneously. If done, only the US PSD mask selection becomes
   effecive.
*/
struct CMD_ADSL_PSD_ShapeUS_Set
{
#if MEI_DRV_OS_BYTE_ORDER == MEI_DRV_OS_BIG_ENDIAN
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Handshake Control */
   IFX_uint16_t HS_enable : 1;
   /** Reserved */
   IFX_uint16_t Res03 : 7;
   /** Number of Breakpoints */
   IFX_uint8_t NumBreakPts;
   /** Breakpoint Descriptor PSDMASKus */
   VNX_PSDbreak_t breakpoint[4];
#else
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Number of Breakpoints */
   IFX_uint8_t NumBreakPts;
   /** Reserved */
   IFX_uint16_t Res03 : 7;
   /** Handshake Control */
   IFX_uint16_t HS_enable : 1;
   /** Breakpoint Descriptor PSDMASKus */
   VNX_PSDbreak_t breakpoint[4];
#endif
} __PACKED__ ;


/**
   Acknowledgement for the message CMD_ADSL_PSD_ShapeUS_Set.
*/
struct ACK_ADSL_PSD_ShapeUS_Set
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
   Attention: To be applied after TSSI configuration!
   This configures the ADSL downstream carrier mask per tone.
   The carrier masking must be applied after TSSI configuration with
   CMD_TssiDS_ADSL_Set, because it is meant for masking, i.e. switching off carriers
   but not for switching on carriers with are suppressed via the TSSI breakpoints.
   The message has a fix length to support all ADSL modes, in ADSL and ADSL2 the values
   for the subcarrier indices >255 are unused ("Don’t care").
*/
struct CMD_ADSL_CarMaskDS_Set
{
#if MEI_DRV_OS_BYTE_ORDER == MEI_DRV_OS_BIG_ENDIAN
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Carrier Mask Bitfield */
   IFX_uint16_t mask[32];
#else
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Carrier Mask Bitfield */
   IFX_uint16_t mask[32];
#endif
} __PACKED__ ;


/**
   This is the acknowledgement for CMD_ADSL_CarMaskDS_Set.
*/
struct ACK_ADSL_CarMaskDS_Set
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
   Attention: To be applied after TSSI configuration!
   This configures the ADSL upstream carrier mask per tone.
   The carrier masking must be applied after TSSI configuration with
   CMD_TssiUS_ADSL_Set, because it is meant for masking, i.e. switching off carriers
   but not for switching them on if suppressed via the TSSI breakpoints.
*/
struct CMD_ADSL_CarMaskUS_Set
{
#if MEI_DRV_OS_BYTE_ORDER == MEI_DRV_OS_BIG_ENDIAN
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Carrier Mask Bitfield */
   IFX_uint16_t mask[4];
#else
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Carrier Mask Bitfield */
   IFX_uint16_t mask[4];
#endif
} __PACKED__ ;


/**
   This is the acknowledgement for CMD_ADSL_CarMaskUS_Set.
*/
struct ACK_ADSL_CarMaskUS_Set
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
   This configures the ADSL downstream power cutback for the different ADSL flavours.
*/
struct CMD_ADSL_PCB_DS_Set
{
#if MEI_DRV_OS_BYTE_ORDER == MEI_DRV_OS_BIG_ENDIAN
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Default Minimum Power Cutback */
   IFX_uint16_t pcbdef;
   /** ADSL1 Minimum Power Cutback */
   IFX_uint16_t pcbadsl1;
   /** ADSL2 Minimum Power Cutback for Annex A/B/I/J */
   IFX_uint16_t pcbadsl2;
   /** ADSL2 Minimum Power Cutback for Annex L Upstream Mask 1 */
   IFX_uint16_t pcbadsl2l1;
   /** ADSL2 Minimum Power Cutback for Annex L Upstream Mask 2 */
   IFX_uint16_t pcbadsl2l2;
   /** ADSL2 Minimum Power Cutback for Annex M */
   IFX_uint16_t pcbadsl2m;
   /** ADSL2+ Minimum Power Cutback for Annex A/B/I/J */
   IFX_uint16_t pcbadsl2p;
   /** ADSL2+ Minimum Power Cutback for Annex M */
   IFX_uint16_t pcbadsl2pm;
#else
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Default Minimum Power Cutback */
   IFX_uint16_t pcbdef;
   /** ADSL1 Minimum Power Cutback */
   IFX_uint16_t pcbadsl1;
   /** ADSL2 Minimum Power Cutback for Annex A/B/I/J */
   IFX_uint16_t pcbadsl2;
   /** ADSL2 Minimum Power Cutback for Annex L Upstream Mask 1 */
   IFX_uint16_t pcbadsl2l1;
   /** ADSL2 Minimum Power Cutback for Annex L Upstream Mask 2 */
   IFX_uint16_t pcbadsl2l2;
   /** ADSL2 Minimum Power Cutback for Annex M */
   IFX_uint16_t pcbadsl2m;
   /** ADSL2+ Minimum Power Cutback for Annex A/B/I/J */
   IFX_uint16_t pcbadsl2p;
   /** ADSL2+ Minimum Power Cutback for Annex M */
   IFX_uint16_t pcbadsl2pm;
#endif
} __PACKED__ ;


/**
   This is the acknowledgement for CMD_ADSL_PCB_DS_Set.
*/
struct ACK_ADSL_PCB_DS_Set
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
   This configures the ADSL upstream power cutback for the different ADSL flavours (not
   applicable for ADSL1)
*/
struct CMD_ADSL_PCB_US_Set
{
#if MEI_DRV_OS_BYTE_ORDER == MEI_DRV_OS_BIG_ENDIAN
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Default Minimum Power Cutback */
   IFX_uint16_t pcbdef;
   /** Reserved */
   IFX_uint16_t Res03;
   /** ADSL2 Minimum Power Cutback for Annex A/B/I/J */
   IFX_uint16_t pcbadsl2;
   /** ADSL2 Minimum Power Cutback for Annex L Upstream Mask 1 */
   IFX_uint16_t pcbadsl2l1;
   /** ADSL2 Minimum Power Cutback for Annex L Upstream Mask 2 */
   IFX_uint16_t pcbadsl2l2;
   /** ADSL2 Minimum Power Cutback for Annex M */
   IFX_uint16_t pcbadsl2m;
   /** ADSL2+ Minimum Power Cutback for Annex A/B/I/J */
   IFX_uint16_t pcbadsl2p;
   /** ADSL2+ Minimum Power Cutback for Annex M */
   IFX_uint16_t pcbadsl2pm;
#else
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Default Minimum Power Cutback */
   IFX_uint16_t pcbdef;
   /** Reserved */
   IFX_uint16_t Res03;
   /** ADSL2 Minimum Power Cutback for Annex A/B/I/J */
   IFX_uint16_t pcbadsl2;
   /** ADSL2 Minimum Power Cutback for Annex L Upstream Mask 1 */
   IFX_uint16_t pcbadsl2l1;
   /** ADSL2 Minimum Power Cutback for Annex L Upstream Mask 2 */
   IFX_uint16_t pcbadsl2l2;
   /** ADSL2 Minimum Power Cutback for Annex M */
   IFX_uint16_t pcbadsl2m;
   /** ADSL2+ Minimum Power Cutback for Annex A/B/I/J */
   IFX_uint16_t pcbadsl2p;
   /** ADSL2+ Minimum Power Cutback for Annex M */
   IFX_uint16_t pcbadsl2pm;
#endif
} __PACKED__ ;


/**
   This is the acknowledgement for CMD_ADSL_PCB_US_Set.
*/
struct ACK_ADSL_PCB_US_Set
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
   Sets parameters for downstream bearer channel 0 (Chapters 7.3.2.1-5 of G.997.1
   [11]).
   The mode, ATM or PTM, is selected with the configuration controls "ATMControl" and
   "PTMControl" in Parameter 2. Exactly one of them must be enabled, not both!
   Note: On ADSL: PTM configuration does not use CMD_ADSL_TransportModeSet. Since
   ATM is the FW default in ADSL anyway, CMD_ADSL_TransportModeSet does not
   need to be applied explicitely either.
*/
struct CMD_BearerCh0_DS_Set
{
#if MEI_DRV_OS_BYTE_ORDER == MEI_DRV_OS_BIG_ENDIAN
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Reserved */
   IFX_uint16_t Res02 : 13;
   /** Reserved (STM) */
   IFX_uint16_t Res03 : 1;
   /** ATM Configuration Control */
   IFX_uint16_t ATMControl : 1;
   /** PTM Configuration Control */
   IFX_uint16_t PTMControl : 1;
   /** Minimum Data Rate BC0 PTM DS */
   IFX_uint16_t minRate0_PTMds;
   /** Maximum Data Rate BC0 PTM DS */
   IFX_uint16_t maxRate0_PTMds;
   /** Minimum Reserved Data Rate BC0 PTM DS */
   IFX_uint16_t minResRate0_PTMds;
   /** Reserved */
   IFX_uint8_t Res09;
   /** Maximum Interleaving Delay BC0 PTM DS */
   IFX_uint8_t maxDelay0_PTMds;
   /** Reserved */
   IFX_uint16_t Res11 : 6;
   /** "SHORT PACKETS" OPTION BC0 PTM DS */
   IFX_uint16_t ShortPacket_PTMds : 1;
   /** "PRE-EMPTION" OPTION BC0 PTM DS */
   IFX_uint16_t Preempt_PTMds : 1;
   /** Reserved */
   IFX_uint16_t Res14 : 6;
   /** Maximum BER BC0 PTM DS */
   IFX_uint16_t BER_PTMds : 2;
   /** Reserved */
   IFX_uint16_t Res16 : 4;
   /** Minimum INP BC0 PTM DS */
   IFX_uint16_t minINP_PTMds : 12;
   /** Minimum Data Rate BC0 ATM DS */
   IFX_uint16_t minRate0_ATMds;
   /** Maximum Data Rate BC0 ATM DS */
   IFX_uint16_t maxRate0_ATMds;
   /** Minimum Reserved Data Rate BC0 ATM DS */
   IFX_uint16_t minResRate0_ATMds;
   /** Reserved */
   IFX_uint8_t Res21;
   /** Maximum Interleaving Delay BC0 ATM DS */
   IFX_uint8_t maxDelay0_ATMds;
   /** Reserved */
   IFX_uint16_t Res23 : 14;
   /** Maximum BER BC0 ATM DS */
   IFX_uint16_t BER_ATMds : 2;
   /** Reserved */
   IFX_uint16_t Res25 : 4;
   /** Minimum INP BC0 ATM DS */
   IFX_uint16_t minINP_ATMds : 12;
   /** Reserved */
   IFX_uint16_t Res27[6];
#else
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** PTM Configuration Control */
   IFX_uint16_t PTMControl : 1;
   /** ATM Configuration Control */
   IFX_uint16_t ATMControl : 1;
   /** Reserved (STM) */
   IFX_uint16_t Res03 : 1;
   /** Reserved */
   IFX_uint16_t Res02 : 13;
   /** Minimum Data Rate BC0 PTM DS */
   IFX_uint16_t minRate0_PTMds;
   /** Maximum Data Rate BC0 PTM DS */
   IFX_uint16_t maxRate0_PTMds;
   /** Minimum Reserved Data Rate BC0 PTM DS */
   IFX_uint16_t minResRate0_PTMds;
   /** Maximum Interleaving Delay BC0 PTM DS */
   IFX_uint8_t maxDelay0_PTMds;
   /** Reserved */
   IFX_uint8_t Res09;
   /** Maximum BER BC0 PTM DS */
   IFX_uint16_t BER_PTMds : 2;
   /** Reserved */
   IFX_uint16_t Res14 : 6;
   /** "PRE-EMPTION" OPTION BC0 PTM DS */
   IFX_uint16_t Preempt_PTMds : 1;
   /** "SHORT PACKETS" OPTION BC0 PTM DS */
   IFX_uint16_t ShortPacket_PTMds : 1;
   /** Reserved */
   IFX_uint16_t Res11 : 6;
   /** Minimum INP BC0 PTM DS */
   IFX_uint16_t minINP_PTMds : 12;
   /** Reserved */
   IFX_uint16_t Res16 : 4;
   /** Minimum Data Rate BC0 ATM DS */
   IFX_uint16_t minRate0_ATMds;
   /** Maximum Data Rate BC0 ATM DS */
   IFX_uint16_t maxRate0_ATMds;
   /** Minimum Reserved Data Rate BC0 ATM DS */
   IFX_uint16_t minResRate0_ATMds;
   /** Maximum Interleaving Delay BC0 ATM DS */
   IFX_uint8_t maxDelay0_ATMds;
   /** Reserved */
   IFX_uint8_t Res21;
   /** Maximum BER BC0 ATM DS */
   IFX_uint16_t BER_ATMds : 2;
   /** Reserved */
   IFX_uint16_t Res23 : 14;
   /** Minimum INP BC0 ATM DS */
   IFX_uint16_t minINP_ATMds : 12;
   /** Reserved */
   IFX_uint16_t Res25 : 4;
   /** Reserved */
   IFX_uint16_t Res27[6];
#endif
} __PACKED__ ;


/**
   Acknowledgement for CMD_BearerCh0_DS_Set. (Configuration of bearer channel 0).
*/
struct ACK_BearerCh0_DS_Set
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
   Sets parameters for upstream bearer channel 0 (Chapters 7.3.2.1-5 of G.997.1 [11]).
   The mode, ATM or PTM, is selected with the configuration controls "ATMControl" and
   "PTMControl" in Parameter 2. Exactly one of them must be enabled, not both!
   Note: PTM configuration does not use CMD_ADSL_TransportModeSet. Since ATM is the
   FW default there anyway, the message does not need to be applied
   explicitely.
*/
struct CMD_BearerCh0_US_Set
{
#if MEI_DRV_OS_BYTE_ORDER == MEI_DRV_OS_BIG_ENDIAN
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Reserved */
   IFX_uint16_t Res02 : 13;
   /** Reserved (STM) */
   IFX_uint16_t Res03 : 1;
   /** ATM Configuration Control */
   IFX_uint16_t ATMControl : 1;
   /** PTM Configuration Control */
   IFX_uint16_t PTMControl : 1;
   /** Minimum Data Rate BC0 PTM US */
   IFX_uint16_t minRate0_PTMus;
   /** Maximum Data Rate BC0 PTM US */
   IFX_uint16_t maxRate0_PTMus;
   /** Minimum Reserved Data Rate BC0 PTM US */
   IFX_uint16_t minResRate0_PTMus;
   /** Reserved */
   IFX_uint8_t Res09;
   /** Maximum Interleaving Delay BC0 PTM US */
   IFX_uint8_t maxDelay0_PTMus;
   /** Reserved */
   IFX_uint16_t Res11 : 6;
   /** "SHORT PACKETS" OPTION BC0 PTM US */
   IFX_uint16_t ShortPacket_PTMus : 1;
   /** "PRE-EMPTION" OPTION BC0 PTM US */
   IFX_uint16_t Preempt_PTMus : 1;
   /** Reserved */
   IFX_uint16_t Res14 : 6;
   /** Maximum BER BC0 PTM US */
   IFX_uint16_t BER_PTMus : 2;
   /** Reserved */
   IFX_uint16_t Res16 : 4;
   /** Minimum INP BC0 PTM US */
   IFX_uint16_t minINP_PTMus : 12;
   /** Minimum Data Rate BC0 ATM US */
   IFX_uint16_t minRate0_ATMus;
   /** Maximum Data Rate BC0 ATM US */
   IFX_uint16_t maxRate0_ATMus;
   /** Minimum Reserved Data Rate BC0 ATM US */
   IFX_uint16_t minResRate0_ATMus;
   /** Reserved */
   IFX_uint8_t Res21;
   /** Maximum Interleaving Delay BC0 ATM US */
   IFX_uint8_t maxDelay0_ATMus;
   /** Reserved */
   IFX_uint16_t Res23 : 14;
   /** Maximum BER BC0 ATM US */
   IFX_uint16_t BER_ATMus : 2;
   /** Reserved */
   IFX_uint16_t Res25 : 4;
   /** Minimum INP BC0 ATM US */
   IFX_uint16_t minINP_ATMus : 12;
   /** Reserved */
   IFX_uint16_t Res27[6];
#else
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** PTM Configuration Control */
   IFX_uint16_t PTMControl : 1;
   /** ATM Configuration Control */
   IFX_uint16_t ATMControl : 1;
   /** Reserved (STM) */
   IFX_uint16_t Res03 : 1;
   /** Reserved */
   IFX_uint16_t Res02 : 13;
   /** Minimum Data Rate BC0 PTM US */
   IFX_uint16_t minRate0_PTMus;
   /** Maximum Data Rate BC0 PTM US */
   IFX_uint16_t maxRate0_PTMus;
   /** Minimum Reserved Data Rate BC0 PTM US */
   IFX_uint16_t minResRate0_PTMus;
   /** Maximum Interleaving Delay BC0 PTM US */
   IFX_uint8_t maxDelay0_PTMus;
   /** Reserved */
   IFX_uint8_t Res09;
   /** Maximum BER BC0 PTM US */
   IFX_uint16_t BER_PTMus : 2;
   /** Reserved */
   IFX_uint16_t Res14 : 6;
   /** "PRE-EMPTION" OPTION BC0 PTM US */
   IFX_uint16_t Preempt_PTMus : 1;
   /** "SHORT PACKETS" OPTION BC0 PTM US */
   IFX_uint16_t ShortPacket_PTMus : 1;
   /** Reserved */
   IFX_uint16_t Res11 : 6;
   /** Minimum INP BC0 PTM US */
   IFX_uint16_t minINP_PTMus : 12;
   /** Reserved */
   IFX_uint16_t Res16 : 4;
   /** Minimum Data Rate BC0 ATM US */
   IFX_uint16_t minRate0_ATMus;
   /** Maximum Data Rate BC0 ATM US */
   IFX_uint16_t maxRate0_ATMus;
   /** Minimum Reserved Data Rate BC0 ATM US */
   IFX_uint16_t minResRate0_ATMus;
   /** Maximum Interleaving Delay BC0 ATM US */
   IFX_uint8_t maxDelay0_ATMus;
   /** Reserved */
   IFX_uint8_t Res21;
   /** Maximum BER BC0 ATM US */
   IFX_uint16_t BER_ATMus : 2;
   /** Reserved */
   IFX_uint16_t Res23 : 14;
   /** Minimum INP BC0 ATM US */
   IFX_uint16_t minINP_ATMus : 12;
   /** Reserved */
   IFX_uint16_t Res25 : 4;
   /** Reserved */
   IFX_uint16_t Res27[6];
#endif
} __PACKED__ ;


/**
   Acknowledgement for CMD_BearerCh0_US_Set. (Configuration of bearer channel 0).
*/
struct ACK_BearerCh0_US_Set
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
   Configures the bearer channel to TPS-TC mapping for both directions as ATM.
   Note: The value written with this message will be made the default value starting
   with the end-of-July 06 release so that it is not necessary to apply it
   explicitely then.
*/
struct CMD_ADSL_TransportModeSet
{
#if MEI_DRV_OS_BYTE_ORDER == MEI_DRV_OS_BIG_ENDIAN
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Physical Transport Mode */
   IFX_uint16_t mode;
#else
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Physical Transport Mode */
   IFX_uint16_t mode;
#endif
} __PACKED__ ;


/**
   Acknowledgment for message CMD_ADSL_TransportModeSet.
*/
struct ACK_ADSL_TransportModeSet
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
   Controls certain funtions of the chip set.
   Attention: 1. The default values may be different for VDSL and ADSL, CO and
   CPE.2. This message uses a negative logic! Thus all "Reserved" bit
   parameters of this message shall be set to "1" unless explicitely
   otherwise noted.
*/
struct CMD_AlgorithmControlSet
{
#if MEI_DRV_OS_BYTE_ORDER == MEI_DRV_OS_BIG_ENDIAN
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Reserved */
   IFX_uint16_t AAC15 : 1;
   /** Reserved */
   IFX_uint16_t AAC14 : 1;
   /** Reserved */
   IFX_uint16_t AAC13 : 1;
   /** Reserved */
   IFX_uint16_t AAC12 : 1;
   /** ADSL-Only Algorithm Control, Bit 11 Enhanced Downstream Interleaving */
   IFX_uint16_t AAC11 : 1;
   /** ADSL-Only Algorithm Control, Bit 10 Enhanced Upstream Interleaving */
   IFX_uint16_t AAC10 : 1;
   /** ADSL-Only Algorithm Control, Bit 9 */
   IFX_uint16_t AAC9 : 1;
   /** Reserved */
   IFX_uint16_t AAC8 : 1;
   /** Reserved */
   IFX_uint16_t AAC7 : 1;
   /** Reserved */
   IFX_uint16_t Res11 : 1;
   /** ADSL-Only Algorithm Control, Bit 5 */
   IFX_uint16_t AAC5 : 1;
   /** ADSL-Only Algorithm Control, Bit 4 */
   IFX_uint16_t AAC4 : 1;
   /** Reserved */
   IFX_uint16_t AAC3 : 1;
   /** ADSL&VDSL Algorithm Control, Bit 2 */
   IFX_uint16_t AAC2 : 1;
   /** Reserved */
   IFX_uint16_t AAC1 : 1;
   /** Reserved */
   IFX_uint16_t AAC0 : 1;
   /** Reserved */
   IFX_uint16_t IAC15 : 1;
   /** Initialization Algorithm Control, Bit14 */
   IFX_uint16_t IAC14 : 1;
   /** Initialization Algorithm Control, Bit13 */
   IFX_uint16_t IAC13 : 1;
   /** Reserved */
   IFX_uint16_t Res21 : 1;
   /** Initialization Algorithm Control, Bit11 */
   IFX_uint16_t IAC11 : 1;
   /** Initialization Algorithm Control, Bit10 */
   IFX_uint16_t IAC10 : 1;
   /** Initialization Algorithm Control, Bit9 */
   IFX_uint16_t IAC9 : 1;
   /** Pilot Tone Selection Control, Bit8 */
   IFX_uint16_t IAC8 : 1;
   /** Initialization Algorithm Control, Bit7 */
   IFX_uint16_t IAC7 : 1;
   /** Initialization Algorithm Control, Bit6 */
   IFX_uint16_t IAC6 : 1;
   /** Reserved */
   IFX_uint16_t Res28 : 1;
   /** Initialization Algorithm Control, Bit4 */
   IFX_uint16_t IAC4 : 1;
   /** Initialization Algorithm Control, Bit3 */
   IFX_uint16_t IAC3 : 1;
   /** Initialization Algorithm Control, Bit2 */
   IFX_uint16_t IAC2 : 1;
   /** Initialization Algorithm Control, Bit1 */
   IFX_uint16_t IAC1 : 1;
   /** Initialization Algorithm Control, Bit0 */
   IFX_uint16_t IAC0 : 1;
   /** Steady-State Algorithm Control, Bit15 */
   IFX_uint16_t SAC15 : 1;
   /** Steady-State Algorithm Control, Bit14 */
   IFX_uint16_t SAC14 : 1;
   /** Reserved */
   IFX_uint16_t Res36 : 3;
   /** Steady-State Algorithm Control, Bit10 */
   IFX_uint16_t SAC10 : 1;
   /** Steady-State Algorithm Control, Bit9 */
   IFX_uint16_t SAC9 : 1;
   /** Steady-State Algorithm Control, Bit8 */
   IFX_uint16_t SAC8 : 1;
   /** Steady-State Algorithm Control, Bit7 */
   IFX_uint16_t SAC7 : 1;
   /** Steady-State Algorithm Control, Bit6 */
   IFX_uint16_t SAC6 : 1;
   /** Reserved */
   IFX_uint16_t Res42 : 1;
   /** Steady-State Algorithm Control, Bit4 */
   IFX_uint16_t SAC4 : 1;
   /** Steady-State Algorithm Control, Bit3 */
   IFX_uint16_t SAC3 : 1;
   /** Steady-State Algorithm Control, Bit2 */
   IFX_uint16_t SAC2 : 1;
   /** Steady-State Algorithm Control, Bit1 */
   IFX_uint16_t SAC1 : 1;
   /** Steady-State Algorithm Control, Bit0 */
   IFX_uint16_t SAC0 : 1;
   /** Reserved */
   IFX_uint16_t Res48 : 12;
   /** VDSL-Only Algorithm Control, Bits 3:0 */
   IFX_uint16_t VAC : 4;
#else
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Reserved */
   IFX_uint16_t AAC0 : 1;
   /** Reserved */
   IFX_uint16_t AAC1 : 1;
   /** ADSL&VDSL Algorithm Control, Bit 2 */
   IFX_uint16_t AAC2 : 1;
   /** Reserved */
   IFX_uint16_t AAC3 : 1;
   /** ADSL-Only Algorithm Control, Bit 4 */
   IFX_uint16_t AAC4 : 1;
   /** ADSL-Only Algorithm Control, Bit 5 */
   IFX_uint16_t AAC5 : 1;
   /** Reserved */
   IFX_uint16_t Res11 : 1;
   /** Reserved */
   IFX_uint16_t AAC7 : 1;
   /** Reserved */
   IFX_uint16_t AAC8 : 1;
   /** ADSL-Only Algorithm Control, Bit 9 */
   IFX_uint16_t AAC9 : 1;
   /** ADSL-Only Algorithm Control, Bit 10 Enhanced Upstream Interleaving */
   IFX_uint16_t AAC10 : 1;
   /** ADSL-Only Algorithm Control, Bit 11 Enhanced Downstream Interleaving */
   IFX_uint16_t AAC11 : 1;
   /** Reserved */
   IFX_uint16_t AAC12 : 1;
   /** Reserved */
   IFX_uint16_t AAC13 : 1;
   /** Reserved */
   IFX_uint16_t AAC14 : 1;
   /** Reserved */
   IFX_uint16_t AAC15 : 1;
   /** Initialization Algorithm Control, Bit0 */
   IFX_uint16_t IAC0 : 1;
   /** Initialization Algorithm Control, Bit1 */
   IFX_uint16_t IAC1 : 1;
   /** Initialization Algorithm Control, Bit2 */
   IFX_uint16_t IAC2 : 1;
   /** Initialization Algorithm Control, Bit3 */
   IFX_uint16_t IAC3 : 1;
   /** Initialization Algorithm Control, Bit4 */
   IFX_uint16_t IAC4 : 1;
   /** Reserved */
   IFX_uint16_t Res28 : 1;
   /** Initialization Algorithm Control, Bit6 */
   IFX_uint16_t IAC6 : 1;
   /** Initialization Algorithm Control, Bit7 */
   IFX_uint16_t IAC7 : 1;
   /** Pilot Tone Selection Control, Bit8 */
   IFX_uint16_t IAC8 : 1;
   /** Initialization Algorithm Control, Bit9 */
   IFX_uint16_t IAC9 : 1;
   /** Initialization Algorithm Control, Bit10 */
   IFX_uint16_t IAC10 : 1;
   /** Initialization Algorithm Control, Bit11 */
   IFX_uint16_t IAC11 : 1;
   /** Reserved */
   IFX_uint16_t Res21 : 1;
   /** Initialization Algorithm Control, Bit13 */
   IFX_uint16_t IAC13 : 1;
   /** Initialization Algorithm Control, Bit14 */
   IFX_uint16_t IAC14 : 1;
   /** Reserved */
   IFX_uint16_t IAC15 : 1;
   /** Steady-State Algorithm Control, Bit0 */
   IFX_uint16_t SAC0 : 1;
   /** Steady-State Algorithm Control, Bit1 */
   IFX_uint16_t SAC1 : 1;
   /** Steady-State Algorithm Control, Bit2 */
   IFX_uint16_t SAC2 : 1;
   /** Steady-State Algorithm Control, Bit3 */
   IFX_uint16_t SAC3 : 1;
   /** Steady-State Algorithm Control, Bit4 */
   IFX_uint16_t SAC4 : 1;
   /** Reserved */
   IFX_uint16_t Res42 : 1;
   /** Steady-State Algorithm Control, Bit6 */
   IFX_uint16_t SAC6 : 1;
   /** Steady-State Algorithm Control, Bit7 */
   IFX_uint16_t SAC7 : 1;
   /** Steady-State Algorithm Control, Bit8 */
   IFX_uint16_t SAC8 : 1;
   /** Steady-State Algorithm Control, Bit9 */
   IFX_uint16_t SAC9 : 1;
   /** Steady-State Algorithm Control, Bit10 */
   IFX_uint16_t SAC10 : 1;
   /** Reserved */
   IFX_uint16_t Res36 : 3;
   /** Steady-State Algorithm Control, Bit14 */
   IFX_uint16_t SAC14 : 1;
   /** Steady-State Algorithm Control, Bit15 */
   IFX_uint16_t SAC15 : 1;
   /** VDSL-Only Algorithm Control, Bits 3:0 */
   IFX_uint16_t VAC : 4;
   /** Reserved */
   IFX_uint16_t Res48 : 12;
#endif
} __PACKED__ ;


/**
   Acknowledgement for message CMD_AlgorithmControlSet.
*/
struct ACK_AlgorithmControlSet
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
   The message controls the digital filters in the VINAX.
*/
struct CMD_DigitalFilterSet
{
#if MEI_DRV_OS_BYTE_ORDER == MEI_DRV_OS_BIG_ENDIAN
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Filter Operation Mode */
   IFX_uint16_t OpMode;
   /** Automatic Filter Control */
   IFX_uint16_t autoControl : 1;
   /** Reserved */
   IFX_uint16_t Res04 : 13;
   /** Rx Filter Control */
   IFX_uint16_t RxControl : 1;
   /** Tx Filter Control */
   IFX_uint16_t TxControl : 1;
#else
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Filter Operation Mode */
   IFX_uint16_t OpMode;
   /** Tx Filter Control */
   IFX_uint16_t TxControl : 1;
   /** Rx Filter Control */
   IFX_uint16_t RxControl : 1;
   /** Reserved */
   IFX_uint16_t Res04 : 13;
   /** Automatic Filter Control */
   IFX_uint16_t autoControl : 1;
#endif
} __PACKED__ ;


/**
   Acknowledgement for message CMD_DigitalFilterSet.
*/
struct ACK_DigitalFilterSet
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
   Selection of the used hybrid.
*/
struct CMD_HybridSelect
{
#if MEI_DRV_OS_BYTE_ORDER == MEI_DRV_OS_BIG_ENDIAN
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Hybrid Type Selection */
   IFX_uint16_t HybridType;
#else
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Hybrid Type Selection */
   IFX_uint16_t HybridType;
#endif
} __PACKED__ ;


/**
   Acknowledgement for message CMD_HybridSelect.
*/
struct ACK_HybridSelect
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
   Sets transmit and receive gain value for the gain calibration.
*/
struct CMD_GainCalibrationSet
{
#if MEI_DRV_OS_BYTE_ORDER == MEI_DRV_OS_BIG_ENDIAN
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Transmit Path Gain Calibration */
   IFX_uint16_t gainTx;
   /** Receive Path Gain Calibration */
   IFX_uint16_t gainRx;
#else
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Transmit Path Gain Calibration */
   IFX_uint16_t gainTx;
   /** Receive Path Gain Calibration */
   IFX_uint16_t gainRx;
#endif
} __PACKED__ ;


/**
   Acknowledgement to CMD_GainCalibrationSet.
*/
struct ACK_GainCalibrationSet
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
   Sets transmit and receive gain value for the gain calibration.
*/
struct CMD_ADSL_GainCalibrationSet
{
#if MEI_DRV_OS_BYTE_ORDER == MEI_DRV_OS_BIG_ENDIAN
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Transmit Path Gain Calibration */
   IFX_uint16_t gainTx;
   /** Receive Path Gain Calibration */
   IFX_uint16_t gainRx;
#else
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Transmit Path Gain Calibration */
   IFX_uint16_t gainTx;
   /** Receive Path Gain Calibration */
   IFX_uint16_t gainRx;
#endif
} __PACKED__ ;


/**
   Acknowledgement to CMD_ADSL_GainCalibrationSet.
*/
struct ACK_ADSL_GainCalibrationSet
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
   This command is used to configure the power level threshold at which the Peak to
   Average Ratio Reduction (PARR) algorithm is enabled. The PARR is operating when the
   transmit power level is above the threshold.
   Only valid if PARR was switched on with CMD_AlgorithmControlSet.
*/
struct CMD_PARR_ThreshSet
{
#if MEI_DRV_OS_BYTE_ORDER == MEI_DRV_OS_BIG_ENDIAN
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Transmit Power Threshold */
   IFX_uint16_t powerThresh;
#else
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Transmit Power Threshold */
   IFX_uint16_t powerThresh;
#endif
} __PACKED__ ;


/**
   This is the acknowledgement for CMD_PARR_ThreshSet.
*/
struct ACK_PARR_ThreshSet
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
   The command selects PARR tones to be used by the Peak to Average Ratio Reduction
   (PARR) algorithm. Only valid if PARR was enabled with CMD_AlgorithmControlSet.
   Note: Care must be taken in selecting the parameters. See Chapter5.5.11.3. A poor
   selection will result in decreased performance!
*/
struct CMD_VDSL_PARR_ToneSelect
{
#if MEI_DRV_OS_BYTE_ORDER == MEI_DRV_OS_BIG_ENDIAN
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** PARR Scaling Exponent ("VDSL") */
   IFX_int16_t scaleExp_V;
   /** PARR Ceiling (dB above RMS) ("VDSL") */
   IFX_uint16_t ceil_V;
   /** PARR Scaling ("VDSL") */
   IFX_int16_t scale_V;
   /** PARR Scaling Exponent ("ADSL+/ADSL++") */
   IFX_int16_t scaleExp_A;
   /** PARR Ceiling (dB above RMS) ("ADSL+/ADSL++") */
   IFX_uint16_t ceil_A;
   /** PARR Scaling ("ADSL+/ADSL++") */
   IFX_int16_t scale_A;
   /** Number of PARR Tones */
   IFX_uint16_t numOfTones;
   /** PARR Tone */
   IFX_uint16_t parrTone[20];
#else
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** PARR Scaling Exponent ("VDSL") */
   IFX_int16_t scaleExp_V;
   /** PARR Ceiling (dB above RMS) ("VDSL") */
   IFX_uint16_t ceil_V;
   /** PARR Scaling ("VDSL") */
   IFX_int16_t scale_V;
   /** PARR Scaling Exponent ("ADSL+/ADSL++") */
   IFX_int16_t scaleExp_A;
   /** PARR Ceiling (dB above RMS) ("ADSL+/ADSL++") */
   IFX_uint16_t ceil_A;
   /** PARR Scaling ("ADSL+/ADSL++") */
   IFX_int16_t scale_A;
   /** Number of PARR Tones */
   IFX_uint16_t numOfTones;
   /** PARR Tone */
   IFX_uint16_t parrTone[20];
#endif
} __PACKED__ ;


/**
   Acknowledgement for CMD_VDSL_PARR_ToneSelect.
*/
struct ACK_VDSL_PARR_ToneSelect
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
   The command selects PARR tones to be used by the Peak to Average Ratio Reduction
   (PARR) algorithm in ADSL1 (G.992.1) and ADSL2 (G.992.3), both Annex A. Only valid if
   PARR was enabled with CMD_AlgorithmControlSet. The message has a fixed length to
   select up to 9 PARR tones. Unused PARR tones are set to "0".
   Note: Care must be taken in selecting the parameters. See Chapter5.5.11.3. A poor
   selection will result in decreased performance!
*/
struct CMD_ADSL12A_PARR_ToneSelect
{
#if MEI_DRV_OS_BYTE_ORDER == MEI_DRV_OS_BIG_ENDIAN
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Reserved */
   IFX_uint16_t Res02 : 13;
   /** PARR Scaling Exponent */
   IFX_uint16_t scaleExp : 3;
   /** PARR Ceiling (dB above RMS) */
   IFX_uint16_t ceil;
   /** PARR Scaling */
   IFX_int16_t scale;
   /** Number of used PARR Tones */
   IFX_uint16_t numOfTones;
   /** PARR Tones */
   IFX_uint16_t parrTone[9];
#else
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** PARR Scaling Exponent */
   IFX_uint16_t scaleExp : 3;
   /** Reserved */
   IFX_uint16_t Res02 : 13;
   /** PARR Ceiling (dB above RMS) */
   IFX_uint16_t ceil;
   /** PARR Scaling */
   IFX_int16_t scale;
   /** Number of used PARR Tones */
   IFX_uint16_t numOfTones;
   /** PARR Tones */
   IFX_uint16_t parrTone[9];
#endif
} __PACKED__ ;


/**
   Acknowledgement for CMD_ADSL12A_PARR_ToneSelect.
*/
struct ACK_ADSL12A_PARR_ToneSelect
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
   The command selects PARR tones to be used by the Peak to Average Ratio Reduction
   (PARR) algorithm in ADSL2+ (G.992.5) mode, Annex A. Only valid if PARR was enabled
   with CMD_AlgorithmControlSet. The message has a fixed length to select up to 9 PARR
   tones. Unused PARR tones are set to "0".
   Note: Care must be taken in selecting the parameters. See Chapter5.5.11.3. A poor
   selection will result in decreased performance!
*/
struct CMD_ADSL2pA_PARR_ToneSelect
{
#if MEI_DRV_OS_BYTE_ORDER == MEI_DRV_OS_BIG_ENDIAN
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Reserved */
   IFX_uint16_t Res02 : 13;
   /** PARR Scaling Exponent */
   IFX_uint16_t scaleExp : 3;
   /** PARR Ceiling (dB above RMS) */
   IFX_uint16_t ceil;
   /** PARR Scaling */
   IFX_int16_t scale;
   /** Number of used PARR Tones */
   IFX_uint16_t numOfTones;
   /** PARR Tones */
   IFX_uint16_t parrTone[9];
#else
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** PARR Scaling Exponent */
   IFX_uint16_t scaleExp : 3;
   /** Reserved */
   IFX_uint16_t Res02 : 13;
   /** PARR Ceiling (dB above RMS) */
   IFX_uint16_t ceil;
   /** PARR Scaling */
   IFX_int16_t scale;
   /** Number of used PARR Tones */
   IFX_uint16_t numOfTones;
   /** PARR Tones */
   IFX_uint16_t parrTone[9];
#endif
} __PACKED__ ;


/**
   Acknowledgement for CMD_ADSL2pA_PARR_ToneSelect.
*/
struct ACK_ADSL2pA_PARR_ToneSelect
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
   The command selects PARR tones to be used by the Peak to Average Ratio Reduction
   (PARR) algorithm in ADSL1 (G.992.1) and ADSL2 (G.992.3), both Annex B. Only valid if
   PARR was enabled with CMD_AlgorithmControlSet. The message has a fixed length to
   select up to 9 PARR tones. Unused PARR tones are set to "0".
   Note: Care must be taken in selecting the parameters. See Chapter5.5.11.3. A poor
   selection will result in decreased performance!
*/
struct CMD_ADSL12B_PARR_ToneSelect
{
#if MEI_DRV_OS_BYTE_ORDER == MEI_DRV_OS_BIG_ENDIAN
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Reserved */
   IFX_uint16_t Res02 : 13;
   /** PARR Scaling Exponent */
   IFX_uint16_t scaleExp : 3;
   /** PARR Ceiling (dB above RMS) */
   IFX_uint16_t ceil;
   /** PARR Scaling */
   IFX_int16_t scale;
   /** Number of used PARR Tones */
   IFX_uint16_t numOfTones;
   /** PARR Tones */
   IFX_uint16_t parrTone[9];
#else
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** PARR Scaling Exponent */
   IFX_uint16_t scaleExp : 3;
   /** Reserved */
   IFX_uint16_t Res02 : 13;
   /** PARR Ceiling (dB above RMS) */
   IFX_uint16_t ceil;
   /** PARR Scaling */
   IFX_int16_t scale;
   /** Number of used PARR Tones */
   IFX_uint16_t numOfTones;
   /** PARR Tones */
   IFX_uint16_t parrTone[9];
#endif
} __PACKED__ ;


/**
   Acknowledgement for CMD_ADSL12B_PARR_ToneSelect.
*/
struct ACK_ADSL12B_PARR_ToneSelect
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
   The command selects PARR tones to be used by the Peak to Average Ratio Reduction
   (PARR) algorithm in ADSL2+ (G.992.5) mode, Annex B. Only valid if PARR was enabled
   with CMD_AlgorithmControlSet. The message has a fixed length to select up to 9 PARR
   tones. Unused PARR tones are set to "0".
   Note: Care must be taken in selecting the parameters. See Chapter5.5.11.3. A poor
   selection will result in decreased performance!
*/
struct CMD_ADSL2pB_PARR_ToneSelect
{
#if MEI_DRV_OS_BYTE_ORDER == MEI_DRV_OS_BIG_ENDIAN
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Reserved */
   IFX_uint16_t Res02 : 13;
   /** PARR Scaling Exponent */
   IFX_uint16_t scaleExp : 3;
   /** PARR Ceiling (dB above RMS) */
   IFX_uint16_t ceil;
   /** PARR Scaling */
   IFX_int16_t scale;
   /** Number of used PARR Tones */
   IFX_uint16_t numOfTones;
   /** PARR Tones */
   IFX_uint16_t parrTone[9];
#else
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** PARR Scaling Exponent */
   IFX_uint16_t scaleExp : 3;
   /** Reserved */
   IFX_uint16_t Res02 : 13;
   /** PARR Ceiling (dB above RMS) */
   IFX_uint16_t ceil;
   /** PARR Scaling */
   IFX_int16_t scale;
   /** Number of used PARR Tones */
   IFX_uint16_t numOfTones;
   /** PARR Tones */
   IFX_uint16_t parrTone[9];
#endif
} __PACKED__ ;


/**
   Acknowledgement for CMD_ADSL2pB_PARR_ToneSelect.
*/
struct ACK_ADSL2pB_PARR_ToneSelect
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
   The command selects PARR tones to be used by the Peak to Average Ratio Reduction
   (PARR) algorithm in ADSL1 (G.992.1) and ADSL2 (G.992.3), both Annex M. Only valid if
   PARR was enabled with CMD_AlgorithmControlSet. The message has a fixed length to
   select up to 9 PARR tones. Unused PARR tones are set to "0".
   Note: Care must be taken in selecting the parameters. See Chapter5.5.11.3. A poor
   selection will result in decreased performance!
*/
struct CMD_ADSL12M_PARR_ToneSelect
{
#if MEI_DRV_OS_BYTE_ORDER == MEI_DRV_OS_BIG_ENDIAN
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Reserved */
   IFX_uint16_t Res02 : 13;
   /** PARR Scaling Exponent */
   IFX_uint16_t scaleExp : 3;
   /** PARR Ceiling (dB above RMS) */
   IFX_uint16_t ceil;
   /** PARR Scaling */
   IFX_int16_t scale;
   /** Number of used PARR Tones */
   IFX_uint16_t numOfTones;
   /** PARR Tones */
   IFX_uint16_t parrTone[9];
#else
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** PARR Scaling Exponent */
   IFX_uint16_t scaleExp : 3;
   /** Reserved */
   IFX_uint16_t Res02 : 13;
   /** PARR Ceiling (dB above RMS) */
   IFX_uint16_t ceil;
   /** PARR Scaling */
   IFX_int16_t scale;
   /** Number of used PARR Tones */
   IFX_uint16_t numOfTones;
   /** PARR Tones */
   IFX_uint16_t parrTone[9];
#endif
} __PACKED__ ;


/**
   Acknowledgement for CMD_ADSL12M_PARR_ToneSelect.
*/
struct ACK_ADSL12M_PARR_ToneSelect
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
   The command selects PARR tones to be used by the Peak to Average Ratio Reduction
   (PARR) algorithm in ADSL2+ (G.992.5) mode, Annex M. Only valid if PARR was enabled
   with CMD_AlgorithmControlSet. The message has a fixed length to select up to 9 PARR
   tones. Unused PARR tones are set to "0".
   Note: Care must be taken in selecting the parameters. See Chapter5.5.11.3. A poor
   selection will result in decreased performance!
*/
struct CMD_ADSL2pM_PARR_ToneSelect
{
#if MEI_DRV_OS_BYTE_ORDER == MEI_DRV_OS_BIG_ENDIAN
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Reserved */
   IFX_uint16_t Res02 : 13;
   /** PARR Scaling Exponent */
   IFX_uint16_t scaleExp : 3;
   /** PARR Ceiling (dB above RMS) */
   IFX_uint16_t ceil;
   /** PARR Scaling */
   IFX_int16_t scale;
   /** Number of used PARR Tones */
   IFX_uint16_t numOfTones;
   /** PARR Tones */
   IFX_uint16_t parrTone[9];
#else
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** PARR Scaling Exponent */
   IFX_uint16_t scaleExp : 3;
   /** Reserved */
   IFX_uint16_t Res02 : 13;
   /** PARR Ceiling (dB above RMS) */
   IFX_uint16_t ceil;
   /** PARR Scaling */
   IFX_int16_t scale;
   /** Number of used PARR Tones */
   IFX_uint16_t numOfTones;
   /** PARR Tones */
   IFX_uint16_t parrTone[9];
#endif
} __PACKED__ ;


/**
   Acknowledgement for CMD_ADSL2pM_PARR_ToneSelect.
*/
struct ACK_ADSL2pM_PARR_ToneSelect
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
   The message controls the amount of de-interleaver memory claimed by the CO US
   receiver. This is necessary for interoperability reasons.
   Note: The VDSL2 standard defines the interleaver/de-interleaver memory as a
   single sized block, i.e. its definition assumes this memory block can be
   shared by the VTU's interleaver and de-interleaver at any ratio as long as
   the total memory (interleaver + de-interleaver) does not exceed the memory
   requirements from the standard. The interleaver setting is controlled by
   the CO. The CO estimates how much memory is needed for the US
   de-interleaving, based on it specifies to the CPE how much de-interleaving
   memory it can use for the DS. The CPE then chooses the interleaver depth
   and other framing parameters based on the memory restrictions provided by
   the CO.
   FW versions up to w.9.x.y.z.a distinguish between "known" and "unknown" CPE modems
   and use 2 different parameters for them, whereas FW versions starting from
   w.10.x.y.z.a do not make this distinction any more and use only one. This only
   parameter has a slightly different meaning for shared (Rev. 2.x) or non-shared (Rev.
   1.x) interleaver memory. If US and DS share a common memory, the configured number
   relates to that common memory. In case of separate memories ("non-shared"), the
   configured number relates to the US memory only.
   FW versions up to w.9.x.y.z.a (with 2 parameters): For known far-end modems, it is
   advantageous to use as much as possible of the de-interleaving memory available in
   the HW.  For interoperability purposes with unknown CPEs, the US memory usage is
   limited to a configurable part, which is dependant on profile and data rate.
   Note: Example for the "old" scheme: G.993.2 requires 64 kB of total interleaving
   and de-interleaving memory (altogether for CO+CPE) for band plans 8 a-d.
   The Vinax supports 128 kB in total, corresponding to 64 kB for each
   direction (CO+CPE), thus at the CO there are 32 kB available for
   de-interleaving.Known CPE: CO uses all 32 kB of the available HW memory for
   de-interleaving.Unknown CPE: The memory required at the CO for
   de-interleaving is profile and data rate dependant.
*/
struct CMD_US_DeinterleaverMemPartition
{
#if MEI_DRV_OS_BYTE_ORDER == MEI_DRV_OS_BIG_ENDIAN
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** De-Interleaver Memory */
   IFX_uint16_t memknownCPE;
   /** De-Interleaver Memory for unknown CPE */
   IFX_uint16_t memUnknownCPE;
#else
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** De-Interleaver Memory */
   IFX_uint16_t memknownCPE;
   /** De-Interleaver Memory for unknown CPE */
   IFX_uint16_t memUnknownCPE;
#endif
} __PACKED__ ;


/**
   This is the acknowledgement for CMD_US_DeinterleaverMemPartition.
*/
struct ACK_US_DeinterleaverMemPartition
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
   The message controls the ACE filter in the AFE’s receive part.
*/
struct CMD_ACE_FilterSet
{
#if MEI_DRV_OS_BYTE_ORDER == MEI_DRV_OS_BIG_ENDIAN
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** ACE Filter Control */
   IFX_uint16_t filterControl;
#else
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** ACE Filter Control */
   IFX_uint16_t filterControl;
#endif
} __PACKED__ ;


/**
   Acknowledgement for message CMD_ACE_FilterSet.
*/
struct ACK_ACE_FilterSet
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
   Performs some miscellaneous chip set configurations.
*/
struct CMD_Misc_ConfigSet
{
#if MEI_DRV_OS_BYTE_ORDER == MEI_DRV_OS_BIG_ENDIAN
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Reserved */
   IFX_uint16_t Res02 : 10;
   /** 24-V Linedriver Optimization (ADSL only) */
   IFX_uint16_t LD24V_Opt : 1;
   /** US SNR limitation (VDSL only) */
   IFX_uint16_t snrUsCap : 1;
   /** INP Protection Improvement (VDSL only) */
   IFX_uint16_t FrameParams : 1;
   /** LOS Criteria Control (VDSL only) */
   IFX_uint16_t losCondition : 1;
   /** Dynamic Trellis Control (VDSL only) - Outdated! */
   IFX_uint16_t DynTrellis : 1;
   /** Clock Gating Control (CO only) */
   IFX_uint16_t clockGating : 1;
#else
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Clock Gating Control (CO only) */
   IFX_uint16_t clockGating : 1;
   /** Dynamic Trellis Control (VDSL only) - Outdated! */
   IFX_uint16_t DynTrellis : 1;
   /** LOS Criteria Control (VDSL only) */
   IFX_uint16_t losCondition : 1;
   /** INP Protection Improvement (VDSL only) */
   IFX_uint16_t FrameParams : 1;
   /** US SNR limitation (VDSL only) */
   IFX_uint16_t snrUsCap : 1;
   /** 24-V Linedriver Optimization (ADSL only) */
   IFX_uint16_t LD24V_Opt : 1;
   /** Reserved */
   IFX_uint16_t Res02 : 10;
#endif
} __PACKED__ ;


/**
   This is the acknowledgement for ACK_Misc_ConfigSet.
*/
struct ACK_Misc_ConfigSet
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
   The message configures interoperability settings at the ADSL-CPE.
*/
struct CMD_InteropConfigSet
{
#if MEI_DRV_OS_BYTE_ORDER == MEI_DRV_OS_BIG_ENDIAN
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Reserved */
   IFX_uint16_t Res02 : 10;
   /** CRC/FEC Counter Restore On Showtime Entry, Bit 5 */
   IFX_uint16_t cntRestore : 1;
   /** Reserved */
   IFX_uint16_t Res04 : 5;
   /** Reserved */
   IFX_uint16_t Res05 : 15;
   /** PCB Level Adjustment, Bit 0 */
   IFX_uint16_t pcbAdjust : 1;
#else
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Reserved */
   IFX_uint16_t Res04 : 5;
   /** CRC/FEC Counter Restore On Showtime Entry, Bit 5 */
   IFX_uint16_t cntRestore : 1;
   /** Reserved */
   IFX_uint16_t Res02 : 10;
   /** PCB Level Adjustment, Bit 0 */
   IFX_uint16_t pcbAdjust : 1;
   /** Reserved */
   IFX_uint16_t Res05 : 15;
#endif
} __PACKED__ ;


/**
   This is the acknowledgement for CMD_InteropConfigSet.
*/
struct ACK_InteropConfigSet
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
   The message requests the interoperability settings used at the ADSL-CPE.
*/
struct CMD_InteropConfigGet
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
   This is the acknowledgement for CMD_InteropConfigGet.
*/
struct ACK_InteropConfigGet
{
#if MEI_DRV_OS_BYTE_ORDER == MEI_DRV_OS_BIG_ENDIAN
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Reserved */
   IFX_uint16_t Res02 : 10;
   /** CRC/FEC Counter Restore On Showtime Entry, Bit 5 */
   IFX_uint16_t cntRestore : 1;
   /** Reserved */
   IFX_uint16_t Res04 : 5;
   /** Reserved */
   IFX_uint16_t Res05 : 15;
   /** PCB Level Adjustment, Bit 0 */
   IFX_uint16_t pcbAdjust : 1;
#else
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Reserved */
   IFX_uint16_t Res04 : 5;
   /** CRC/FEC Counter Restore On Showtime Entry, Bit 5 */
   IFX_uint16_t cntRestore : 1;
   /** Reserved */
   IFX_uint16_t Res02 : 10;
   /** PCB Level Adjustment, Bit 0 */
   IFX_uint16_t pcbAdjust : 1;
   /** Reserved */
   IFX_uint16_t Res05 : 15;
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

