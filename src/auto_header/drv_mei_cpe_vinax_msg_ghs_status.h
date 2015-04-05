/******************************************************************************

                               Copyright (c) 2011
                            Lantiq Deutschland GmbH
                     Am Campeon 3; 85579 Neubiberg, Germany

  For licensing information, see the file 'LICENSE' in the root folder of
  this software module.

******************************************************************************/


#ifndef _VDSL2_FWDES_GHSINVSTATUS_H_
#define _VDSL2_FWDES_GHSINVSTATUS_H_

/** \file
   This chapter contains messages that are specific for the handshake phase.
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


/** @defgroup _VDSL2_FWDES_GHSINVSTATUS_ Handshake-specific Messages
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
#define  ACK_XTSE_StatusGet_L0  0
#define  ACK_XTSE_StatusGet_L3  3
#define  ACK_ACE_FilterGet_EQ  1
#define  ACK_ACE_FilterGet_OFF  2
#define  ACK_ACE_FilterGet_TEST  3
#define  ACK_ACE_FilterGet_ADAPTIVE   4
/* ----- Constants Definition section (End) ----- */

/** Message ID for CMD_HS_ToneGroupSet */
#define CMD_HS_TONEGROUPSET 0x2D48

/**
   Selects one or more groups of tones to be used during the handshake phase. (See
   G.994.1 Amendment 2 [8], Table 1/G.994.1)
*/
typedef struct CMD_HS_ToneGroupSet CMD_HS_ToneGroupSet_t;

/** Message ID for ACK_HS_ToneGroupSet */
#define ACK_HS_TONEGROUPSET 0x2D48

/**
   Acknowledgement to CMD_HS_ToneGroupSet.
*/
typedef struct ACK_HS_ToneGroupSet ACK_HS_ToneGroupSet_t;

/** Message ID for CMD_HS_VDSL2ProfileControl */
#define CMD_HS_VDSL2PROFILECONTROL 0x2C48

/**
   Configures the profile settings to be used for the handshake phase. (See G.994.1
   Amendment 4 [10], NPAR(3) coding).
   Note: All "support" bits should be set to "Enable".

*/
typedef struct CMD_HS_VDSL2ProfileControl CMD_HS_VDSL2ProfileControl_t;

/** Message ID for ACK_HS_VDSL2ProfileControl */
#define ACK_HS_VDSL2PROFILECONTROL 0x2C48

/**
   Acknowledgement to CMD_HS_VDSL2ProfileControl.
*/
typedef struct ACK_HS_VDSL2ProfileControl ACK_HS_VDSL2ProfileControl_t;

/** Message ID for CMD_HS_StandardInfoFE_VDSL2Get */
#define CMD_HS_STANDARDINFOFE_VDSL2GET 0xCC03

/**
   Requests the VDSL2 far-end Standard Info (See G.994.1 Amendment 4 [10], NPAR(3)
   coding).
*/
typedef struct CMD_HS_StandardInfoFE_VDSL2Get CMD_HS_StandardInfoFE_VDSL2Get_t;

/** Message ID for ACK_HS_StandardInfoFE_VDSL2Get */
#define ACK_HS_STANDARDINFOFE_VDSL2GET 0xCC03

/**
   Delivers the VDSL2 far-end info as requested by CMD_HS_StandardInfoFE_VDSL2Get (see
   G.994.1 Amendment 4 [10], NPAR(3) coding).
*/
typedef struct ACK_HS_StandardInfoFE_VDSL2Get ACK_HS_StandardInfoFE_VDSL2Get_t;

/** Message ID for CMD_HS_SelectedProfileVDSL2Get */
#define CMD_HS_SELECTEDPROFILEVDSL2GET 0xCD03

/**
   Requests the actual selected VDSL2 Profile (See G.994.1 Amendment 4 [10], NPAR(3)
   coding).
*/
typedef struct CMD_HS_SelectedProfileVDSL2Get CMD_HS_SelectedProfileVDSL2Get_t;

/** Message ID for ACK_HS_SelectedProfileVDSL2Get */
#define ACK_HS_SELECTEDPROFILEVDSL2GET 0xCD03

/**
   Provides the actual selected VDSL2 Profile as requested by
   CMD_HS_SelectedProfileVDSL2Get (see G.994.1 Amendment 4 [10], NPAR(3) coding).
*/
typedef struct ACK_HS_SelectedProfileVDSL2Get ACK_HS_SelectedProfileVDSL2Get_t;

/** Message ID for CMD_HS_StandardInfoFE_SPAR1Get */
#define CMD_HS_STANDARDINFOFE_SPAR1GET 0xCB03

/**
   Requests the handshake information about the far-end operating mode (See G.994.1 [6]
   and Amendments 1-4 [7]-[10], standard information fields- SPAR(1) coding).
*/
typedef struct CMD_HS_StandardInfoFE_SPAR1Get CMD_HS_StandardInfoFE_SPAR1Get_t;

/** Message ID for ACK_HS_StandardInfoFE_SPAR1Get */
#define ACK_HS_STANDARDINFOFE_SPAR1GET 0xCB03

/**
   Provides the handshake information about the far-end operating mode (See G.994.1 [6]
   and Amendments 1-4 [7]-[10], Standard information field - SPAR(1) coding). The bit
   numbering per octet below follows the standard (starting with "1").
*/
typedef struct ACK_HS_StandardInfoFE_SPAR1Get ACK_HS_StandardInfoFE_SPAR1Get_t;

/** Message ID for CMD_SysVendorID_O_Set */
#define CMD_SYSVENDORID_O_SET 0x3843

/**
   Sets the in System Vendor ID at the xTU-C. (Section 7.4.3 of G997.1 [11])
*/
typedef struct CMD_SysVendorID_O_Set CMD_SysVendorID_O_Set_t;

/** Message ID for ACK_SysVendorID_O_Set */
#define ACK_SYSVENDORID_O_SET 0x3843

/**
   Acknowledgement to CMD_SysVendorID_O_Set.
*/
typedef struct ACK_SysVendorID_O_Set ACK_SysVendorID_O_Set_t;

/** Message ID for CMD_SysVendorID_R_Set */
#define CMD_SYSVENDORID_R_SET 0x3C43

/**
   Sets the in System Vendor ID at the xTU-R. (Section 7.4.4 of G997.1 [11])
*/
typedef struct CMD_SysVendorID_R_Set CMD_SysVendorID_R_Set_t;

/** Message ID for ACK_SysVendorID_R_Set */
#define ACK_SYSVENDORID_R_SET 0x3C43

/**
   Acknowledgement to CMD_SysVendorID_R_Set.
*/
typedef struct ACK_SysVendorID_R_Set ACK_SysVendorID_R_Set_t;

/** Message ID for CMD_SysVendorVersionNum_O_Set */
#define CMD_SYSVENDORVERSIONNUM_O_SET 0x3A43

/**
   Sets the in system vendor version number at the xTU-C. (Section 7.4.5 of G997.1
   [11])
*/
typedef struct CMD_SysVendorVersionNum_O_Set CMD_SysVendorVersionNum_O_Set_t;

/** Message ID for ACK_SysVendorVersionNum_O_Set */
#define ACK_SYSVENDORVERSIONNUM_O_SET 0x3A43

/**
   Acknowledgement to CMD_SysVendorVersionNum_O_Set.
*/
typedef struct ACK_SysVendorVersionNum_O_Set ACK_SysVendorVersionNum_O_Set_t;

/** Message ID for CMD_SysVendorVersionNum_R_Set */
#define CMD_SYSVENDORVERSIONNUM_R_SET 0x3D43

/**
   Sets the in system vendor version number at the xTU-R. (Section 7.4.6 of G997.1
   [11])
*/
typedef struct CMD_SysVendorVersionNum_R_Set CMD_SysVendorVersionNum_R_Set_t;

/** Message ID for ACK_SysVendorVersionNum_R_Set */
#define ACK_SYSVENDORVERSIONNUM_R_SET 0x3D43

/**
   Acknowledgement to CMD_SysVendorVersionNum_R_Set.
*/
typedef struct ACK_SysVendorVersionNum_R_Set ACK_SysVendorVersionNum_R_Set_t;

/** Message ID for CMD_SysVendorSerialNum_O_Set */
#define CMD_SYSVENDORSERIALNUM_O_SET 0x3943

/**
   For CO side only!
   Sets the in system vendor version number at the xTU-C. (Section 7.4.7 of G997.1
   [11])
*/
typedef struct CMD_SysVendorSerialNum_O_Set CMD_SysVendorSerialNum_O_Set_t;

/** Message ID for ACK_SysVendorSerialNum_O_Set */
#define ACK_SYSVENDORSERIALNUM_O_SET 0x3943

/**
   Acknowledgement to CMD_SysVendorSerialNum_O_Set.
*/
typedef struct ACK_SysVendorSerialNum_O_Set ACK_SysVendorSerialNum_O_Set_t;

/** Message ID for CMD_SysVendorSerialNum_R_Set */
#define CMD_SYSVENDORSERIALNUM_R_SET 0x3E43

/**
   Sets the system vendor serial number at the xTU-R. (Section 7.4.8 of G997.1 [11])
*/
typedef struct CMD_SysVendorSerialNum_R_Set CMD_SysVendorSerialNum_R_Set_t;

/** Message ID for ACK_SysVendorSerialNum_R_Set */
#define ACK_SYSVENDORSERIALNUM_R_SET 0x3E43

/**
   Acknowledgement to CMD_SysVendorSerialNum_R_Set.
*/
typedef struct ACK_SysVendorSerialNum_R_Set ACK_SysVendorSerialNum_R_Set_t;

/** Message ID for CMD_AuxInventoryInfo_O_Set */
#define CMD_AUXINVENTORYINFO_O_SET 0x4243

/**
   Sets auxiliary inventory information at the VTU-O (¤11.2.3.2.4 of G993.2 [5]).
*/
typedef struct CMD_AuxInventoryInfo_O_Set CMD_AuxInventoryInfo_O_Set_t;

/** Message ID for ACK_AuxInventoryInfo_O_Set */
#define ACK_AUXINVENTORYINFO_O_SET 0x4243

/**
   Acknowledgement to CMD_AuxInventoryInfo_O_Set.
*/
typedef struct ACK_AuxInventoryInfo_O_Set ACK_AuxInventoryInfo_O_Set_t;

/** Message ID for CMD_AuxInventoryInfo_R_Set */
#define CMD_AUXINVENTORYINFO_R_SET 0x4343

/**
   Sets auxiliary inventory information at the VTU-R (¤11.2.3.2.4 of G993.2 [5]).
*/
typedef struct CMD_AuxInventoryInfo_R_Set CMD_AuxInventoryInfo_R_Set_t;

/** Message ID for ACK_AuxInventoryInfo_R_Set */
#define ACK_AUXINVENTORYINFO_R_SET 0x4343

/**
   Acknowledgement to CMD_AuxInventoryInfo_R_Set.
*/
typedef struct ACK_AuxInventoryInfo_R_Set ACK_AuxInventoryInfo_R_Set_t;

/** Message ID for CMD_VendorID_O_Get */
#define CMD_VENDORID_O_GET 0x4003

/**
   Requests the xTU-C Vendor ID. (Section 7.4.1 of G997.1 [11])
*/
typedef struct CMD_VendorID_O_Get CMD_VendorID_O_Get_t;

/** Message ID for ACK_VendorID_O_Get */
#define ACK_VENDORID_O_GET 0x4003

/**
   Provides the xTU-C Vendor ID as requested by CMD_VendorID_O_Get.
*/
typedef struct ACK_VendorID_O_Get ACK_VendorID_O_Get_t;

/** Message ID for CMD_VendorID_R_Get */
#define CMD_VENDORID_R_GET 0x4103

/**
   Requests the xTU-R Vendor ID. (Section 7.4.2 of G997.1 [11])
*/
typedef struct CMD_VendorID_R_Get CMD_VendorID_R_Get_t;

/** Message ID for ACK_VendorID_R_Get */
#define ACK_VENDORID_R_GET 0x4103

/**
   Provides the xTU-R Vendor ID as requested by CMD_VendorID_R_Get.
*/
typedef struct ACK_VendorID_R_Get ACK_VendorID_R_Get_t;

/** Message ID for CMD_SysVendorID_O_Get */
#define CMD_SYSVENDORID_O_GET 0x3803

/**
   Requests the xTU-C System Vendor ID. (Section 7.4.3 of G997.1 [11])
*/
typedef struct CMD_SysVendorID_O_Get CMD_SysVendorID_O_Get_t;

/** Message ID for ACK_SysVendorID_O_Get */
#define ACK_SYSVENDORID_O_GET 0x3803

/**
   Delivers the xTU-C System Vendor ID as requested by CMD_SysVendorID_O_Get.
*/
typedef struct ACK_SysVendorID_O_Get ACK_SysVendorID_O_Get_t;

/** Message ID for CMD_SysVendorID_R_Get */
#define CMD_SYSVENDORID_R_GET 0x3C03

/**
   Requests the xTU-R System Vendor ID. (Section 7.4.4 of G997.1 [11])
*/
typedef struct CMD_SysVendorID_R_Get CMD_SysVendorID_R_Get_t;

/** Message ID for ACK_SysVendorID_R_Get */
#define ACK_SYSVENDORID_R_GET 0x3C03

/**
   Delivers the xTU-R System Vendor ID as requested by CMD_SysVendorID_R_Get.
*/
typedef struct ACK_SysVendorID_R_Get ACK_SysVendorID_R_Get_t;

/** Message ID for CMD_SysVendorVersionNumO_Get */
#define CMD_SYSVENDORVERSIONNUMO_GET 0x3A03

/**
   Requests the xTU-C system vendor version number. (Section 7.4.5 of G997.1 [11])
*/
typedef struct CMD_SysVendorVersionNumO_Get CMD_SysVendorVersionNumO_Get_t;

/** Message ID for ACK_SysVendorVersionNum_O_Get */
#define ACK_SYSVENDORVERSIONNUM_O_GET 0x3A03

/**
   Delivers the xTU-C system vendor version number as requested by
   CMD_SysVendorVersionNumO_Get.
*/
typedef struct ACK_SysVendorVersionNum_O_Get ACK_SysVendorVersionNum_O_Get_t;

/** Message ID for CMD_SysVendorVersionNum_R_Get */
#define CMD_SYSVENDORVERSIONNUM_R_GET 0x3D03

/**
   Requests the xTU-R system vendor version number. (Section 7.4.6 of G997.1 [11])
*/
typedef struct CMD_SysVendorVersionNum_R_Get CMD_SysVendorVersionNum_R_Get_t;

/** Message ID for ACK_SysVendorVersionNum_R_Get */
#define ACK_SYSVENDORVERSIONNUM_R_GET 0x3D03

/**
   Delivers the xTU-R system vendor version number as requested by
   CMD_SysVendorVersionNum_R_Get.
*/
typedef struct ACK_SysVendorVersionNum_R_Get ACK_SysVendorVersionNum_R_Get_t;

/** Message ID for CMD_SysVendorSerialNum_O_Get */
#define CMD_SYSVENDORSERIALNUM_O_GET 0x3903

/**
   Requests the xTU-C system vendor serial number. (Section 7.4.7 of G997.1 [11])
*/
typedef struct CMD_SysVendorSerialNum_O_Get CMD_SysVendorSerialNum_O_Get_t;

/** Message ID for ACK_SysVendorSerialNum_O_Get */
#define ACK_SYSVENDORSERIALNUM_O_GET 0x3903

/**
   Delivers the xTU-C system vendor serial number as requested by
   CMD_SysVendorSerialNum_O_Get.
*/
typedef struct ACK_SysVendorSerialNum_O_Get ACK_SysVendorSerialNum_O_Get_t;

/** Message ID for CMD_SysVendorSerialNum_R_Get */
#define CMD_SYSVENDORSERIALNUM_R_GET 0x3E03

/**
   Requests the xTU-R system vendor serial number. (Section 7.4.8 of G997.1 [11])
*/
typedef struct CMD_SysVendorSerialNum_R_Get CMD_SysVendorSerialNum_R_Get_t;

/** Message ID for ACK_SysVendorSerialNum_R_Get */
#define ACK_SYSVENDORSERIALNUM_R_GET 0x3E03

/**
   Delivers the xTU-R system vendor version number as requested by
   CMD_SysVendorSerialNum_R_Get.
*/
typedef struct ACK_SysVendorSerialNum_R_Get ACK_SysVendorSerialNum_R_Get_t;

/** Message ID for CMD_AuxInventoryInfo_O_Get */
#define CMD_AUXINVENTORYINFO_O_GET 0x4203

/**
   Requests VTU-O auxiliary inventory information (¤11.2.3.2.4 of G993.2 [5]).
*/
typedef struct CMD_AuxInventoryInfo_O_Get CMD_AuxInventoryInfo_O_Get_t;

/** Message ID for ACK_AuxInventoryInfo_O_Get */
#define ACK_AUXINVENTORYINFO_O_GET 0x4203

/**
   Delivers the VTU-O auxiliary inventory information as requested by
   CMD_AuxInventoryInfo_O_Get.
*/
typedef struct ACK_AuxInventoryInfo_O_Get ACK_AuxInventoryInfo_O_Get_t;

/** Message ID for CMD_AuxInventoryInfo_R_Get */
#define CMD_AUXINVENTORYINFO_R_GET 0x4303

/**
   Requests VTU-R auxiliary inventory information (¤11.2.3.2.4 of G993.2 [5]).
*/
typedef struct CMD_AuxInventoryInfo_R_Get CMD_AuxInventoryInfo_R_Get_t;

/** Message ID for ACK_AuxInventoryInfo_R_Get */
#define ACK_AUXINVENTORYINFO_R_GET 0x4303

/**
   Delivers the VTU-R auxiliary inventory information as requested by
   CMD_AuxInventoryInfo_R_Get.
*/
typedef struct ACK_AuxInventoryInfo_R_Get ACK_AuxInventoryInfo_R_Get_t;

/** Message ID for CMD_XTSE_StatusGet */
#define CMD_XTSE_STATUSGET 0x0102

/**
   Requests the transmission system in use on the line (DSL flavour).
   (Section 7.5.1.1. of G.997.1 [11])
*/
typedef struct CMD_XTSE_StatusGet CMD_XTSE_StatusGet_t;

/** Message ID for ACK_XTSE_StatusGet */
#define ACK_XTSE_STATUSGET 0x0102

/**
   Reports the transmission system mode in use as requested by CMD_XTSE_StatusGet.
*/
typedef struct ACK_XTSE_StatusGet ACK_XTSE_StatusGet_t;

/** Message ID for CMD_BandControl_DS_Get */
#define CMD_BANDCONTROL_DS_GET 0xC803

/**
   Reads the used downstream band configuration.
   Note: The reported used DS band configuration reflects the MEDLEYds set as
   defined in the O-PRM message of the channel discovery phase according to
   G.993.2.
*/
typedef struct CMD_BandControl_DS_Get CMD_BandControl_DS_Get_t;

/** Message ID for ACK_BandControl_DS_Get */
#define ACK_BANDCONTROL_DS_GET 0xC803

/**
   Acknowledgement for message CMD_BandControl_DS_Get.
*/
typedef struct ACK_BandControl_DS_Get ACK_BandControl_DS_Get_t;

/** Message ID for CMD_BandControl_US_Get */
#define CMD_BANDCONTROL_US_GET 0xC903

/**
   Reads the used upstream band configuration.
   Note: The reported used US band configuration reflects the MEDLEYus set as
   defined in the R-PRM message of the channel discovery phase in G.993.2.
*/
typedef struct CMD_BandControl_US_Get CMD_BandControl_US_Get_t;

/** Message ID for ACK_BandControl_US_Get */
#define ACK_BANDCONTROL_US_GET 0xC903

/**
   Acknowledgement for message CMD_BandControl_US_Get.
*/
typedef struct ACK_BandControl_US_Get ACK_BandControl_US_Get_t;

/** Message ID for CMD_RFI_BandControlGet */
#define CMD_RFI_BANDCONTROLGET 0xCA03

/**
   Reads the RFI band configuration.
*/
typedef struct CMD_RFI_BandControlGet CMD_RFI_BandControlGet_t;

/** Message ID for ACK_RFI_BandControlGet */
#define ACK_RFI_BANDCONTROLGET 0xCA03

/**
   Acknowledgement for message CMD_RFI_BandControlGet.
*/
typedef struct ACK_RFI_BandControlGet ACK_RFI_BandControlGet_t;

/** Message ID for CMD_LineStatusDS_Get */
#define CMD_LINESTATUSDS_GET 0x4403

/**
   This message requests data about the line status (like noise margin) for downstream
   direction.
*/
typedef struct CMD_LineStatusDS_Get CMD_LineStatusDS_Get_t;

/** Message ID for ACK_LineStatusDS_Get */
#define ACK_LINESTATUSDS_GET 0x4403

/**
   The message delivers the line status data for downstream direction requested by
   CMD_LineStatusDS_Get.
*/
typedef struct ACK_LineStatusDS_Get ACK_LineStatusDS_Get_t;

/** Message ID for CMD_LineStatusUS_Get */
#define CMD_LINESTATUSUS_GET 0x4503

/**
   This message requests data about the upstream line status (like noise margin).
*/
typedef struct CMD_LineStatusUS_Get CMD_LineStatusUS_Get_t;

/** Message ID for ACK_LineStatusUS_Get */
#define ACK_LINESTATUSUS_GET 0x4503

/**
   The message delivers the line status data for upstream direction requested by
   CMD_LineStatusUS_Get.
*/
typedef struct ACK_LineStatusUS_Get ACK_LineStatusUS_Get_t;

/** Message ID for CMD_LineStatusPerBandDS_Get */
#define CMD_LINESTATUSPERBANDDS_GET 0xD203

/**
   This message requests data about the line status (noise margin, line attenuation and
   signal attenuation) for downstream direction in a "per band" granularity.
*/
typedef struct CMD_LineStatusPerBandDS_Get CMD_LineStatusPerBandDS_Get_t;

/** Message ID for ACK_LineStatusPerBandDS_Get */
#define ACK_LINESTATUSPERBANDDS_GET 0xD203

/**
   The message delivers the line status data (line attenuation, signal attenuation and
   noise margin) for downstream direction in a "per band" granularity as requested by
   CMD_LineStatusPerBandDS_Get.
*/
typedef struct ACK_LineStatusPerBandDS_Get ACK_LineStatusPerBandDS_Get_t;

/** Message ID for CMD_LineStatusPerBandUS_Get */
#define CMD_LINESTATUSPERBANDUS_GET 0xD303

/**
   This message requests data about the line status (noise margin, line - and signal
   attenuation) for upstream direction in a "per band" granularity.
*/
typedef struct CMD_LineStatusPerBandUS_Get CMD_LineStatusPerBandUS_Get_t;

/** Message ID for ACK_LineStatusPerBandUS_Get */
#define ACK_LINESTATUSPERBANDUS_GET 0xD303

/**
   The message delivers the line status data (line attenuation, signal attenuation and
   noise margin) for upstream direction in a "per band" granularity as requested by
   CMD_LineStatusPerBandUS_Get.
*/
typedef struct ACK_LineStatusPerBandUS_Get ACK_LineStatusPerBandUS_Get_t;

/** Message ID for CMD_PSD_BreakpointsDS_Get */
#define CMD_PSD_BREAKPOINTSDS_GET 0xD403

/**
   Requests the breakpoints of the actual PSD for the downstream direction. PSDs
   consisting of more than 42 PSD breakpoints must be read with 2 messages due to the
   the mailbox size. (The first parameter in the retrieved data structure contains the
   "Number of Breakpoints" parameter.)
*/
typedef struct CMD_PSD_BreakpointsDS_Get CMD_PSD_BreakpointsDS_Get_t;

/** Message ID for ACK_PSD_BreakpointsDS_Get */
#define ACK_PSD_BREAKPOINTSDS_GET 0xD403

/**
   Delivers the breakpoints of the actual PSD for the downstream direction as requested
   by CMD_PSD_BreakpointsDS_Get.
*/
typedef struct ACK_PSD_BreakpointsDS_Get ACK_PSD_BreakpointsDS_Get_t;

/** Message ID for CMD_PSD_BreakpointsUS_Get */
#define CMD_PSD_BREAKPOINTSUS_GET 0xD503

/**
   Requests the breakpoints of the actual PSD for the upstream direction.
*/
typedef struct CMD_PSD_BreakpointsUS_Get CMD_PSD_BreakpointsUS_Get_t;

/** Message ID for ACK_PSD_BreakpointsUS_Get */
#define ACK_PSD_BREAKPOINTSUS_GET 0xD503

/**
   Delivers the breakpoints of the actual PSD for the upstream direction as requested
   by CMD_PSD_BreakpointsUS_Get.
*/
typedef struct ACK_PSD_BreakpointsUS_Get ACK_PSD_BreakpointsUS_Get_t;

/** Message ID for CMD_VN_BreakpointsDS_Set */
#define CMD_VN_BREAKPOINTSDS_SET 0x2F48

/**
   Configures the virtual noise PSD for downstream direction via breakpoints obtained
   from G.997.1. The CPE receiver uses this to adjust the SNR computation for the
   expected noise levels.
*/
typedef struct CMD_VN_BreakpointsDS_Set CMD_VN_BreakpointsDS_Set_t;

/** Message ID for ACK_VN_BreakpointsDS_Set */
#define ACK_VN_BREAKPOINTSDS_SET 0x2F48

/**
   Acknowledgment for the DS configuration message of the virutal noise PSD
   CMD_VN_BreakpointsDS_Set.
*/
typedef struct ACK_VN_BreakpointsDS_Set ACK_VN_BreakpointsDS_Set_t;

/** Message ID for CMD_VN_BreakpointsUS_Set */
#define CMD_VN_BREAKPOINTSUS_SET 0x3048

/**
   Configures the virtual noise PSD in upstream direction via breakpoints. This
   information is used by the CO receiver for adjusting the SNR computation during
   training.
*/
typedef struct CMD_VN_BreakpointsUS_Set CMD_VN_BreakpointsUS_Set_t;

/** Message ID for ACK_VN_BreakpointsUS_Set */
#define ACK_VN_BREAKPOINTSUS_SET 0x3048

/**
   Acknowledgment for the configuration message of the virtual noise PSD set in US
   CMD_VN_BreakpointsUS_Set.
*/
typedef struct ACK_VN_BreakpointsUS_Set ACK_VN_BreakpointsUS_Set_t;

/** Message ID for CMD_TssiDS_VDSL2_Get */
#define CMD_TSSIDS_VDSL2_GET 0x2803

/**
   The Downstream TSSI Breakpoints are specified by the transmitter (VTU-O) and
   communicated to the receiver (VTU-R) via the O-PRM message.   The TSSI Breakpoints
   are used to shape the O-P-TEQ signal. This message provides read only access to the
   DS TSSI Breakpoints. The DS TSSI Breakpoints are not configurable via messages.
*/
typedef struct CMD_TssiDS_VDSL2_Get CMD_TssiDS_VDSL2_Get_t;

/** Message ID for ACK_TssiDS_VDSL2_Get */
#define ACK_TSSIDS_VDSL2_GET 0x2803

/**
   This is the acknowledgement of CMD_TssiDS_VDSL2_Get.
*/
typedef struct ACK_TssiDS_VDSL2_Get ACK_TssiDS_VDSL2_Get_t;

/** Message ID for CMD_TssiUS_VDSL2_Get */
#define CMD_TSSIUS_VDSL2_GET 0x2903

/**
   The Upstream TSSI Breakpoints are specified by the transmitter (VTU-R) and
   communicated to the receiver (VTU-O) via the R-PRM message.   The TSSI Breakpoints
   are used to shape the R-P-TEQ signal.
   Note: The TSSI Breakpoints can be read only but are not configurable via
   messages.
*/
typedef struct CMD_TssiUS_VDSL2_Get CMD_TssiUS_VDSL2_Get_t;

/** Message ID for ACK_TssiUS_VDSL2_Get */
#define ACK_TSSIUS_VDSL2_GET 0x2903

/**
   This is the acknowledgement of CMD_TssiUS_VDSL2_Get.
*/
typedef struct ACK_TssiUS_VDSL2_Get ACK_TssiUS_VDSL2_Get_t;

/** Message ID for CMD_ADSL_PCB_Get */
#define CMD_ADSL_PCB_GET 0x000E

/**
   Reads the actual power cutback value.
*/
typedef struct CMD_ADSL_PCB_Get CMD_ADSL_PCB_Get_t;

/** Message ID for ACK_ADSL_PCB_Get */
#define ACK_ADSL_PCB_GET 0x000E

/**
   Provides the actual power cutback values requested with CMD_ADSL_PCB_Get.
*/
typedef struct ACK_ADSL_PCB_Get ACK_ADSL_PCB_Get_t;

/** Message ID for CMD_ActualPSD_Get */
#define CMD_ACTUALPSD_GET 0xD803

/**
   Requests the PSD and power parameter values actually used by the firmware. The
   values can be different from what was configured with CMD_PSD_Set, e.g. if
   out-of-range values were written the FW limits them to the valid range.
*/
typedef struct CMD_ActualPSD_Get CMD_ActualPSD_Get_t;

/** Message ID for ACK_ActualPSD_Get */
#define ACK_ACTUALPSD_GET 0xD803

/**
   Provieds actually used PSD and power parameters as requested by CMD_ActualPSD_Get.
*/
typedef struct ACK_ActualPSD_Get ACK_ActualPSD_Get_t;

/** Message ID for CMD_BearerChsDS_Get */
#define CMD_BEARERCHSDS_GET 0x0106

/**
   Requests status information for the downstream bearer channels.
*/
typedef struct CMD_BearerChsDS_Get CMD_BearerChsDS_Get_t;

/** Message ID for ACK_BearerChsDS_Get */
#define ACK_BEARERCHSDS_GET 0x0106

/**
   Delivers status information for the downstream bearer channels.
   Attention: In VINAX V1.x the "LP1/Fast Path" parameters are populated only in
   ADSL1 mode with selected fast path.
*/
typedef struct ACK_BearerChsDS_Get ACK_BearerChsDS_Get_t;

/** Message ID for CMD_BearerChsUS_Get */
#define CMD_BEARERCHSUS_GET 0x0006

/**
   Requests status information for the upstream bearer channels.
*/
typedef struct CMD_BearerChsUS_Get CMD_BearerChsUS_Get_t;

/** Message ID for ACK_BearerChsUS_Get */
#define ACK_BEARERCHSUS_GET 0x0006

/**
   Delivers status information for the upstream bearer channels.
   Attention: In VINAX V1.x the "LP1/Fast Path" parameters are populated only in
   ADSL1 mode with selected fast path.
*/
typedef struct ACK_BearerChsUS_Get ACK_BearerChsUS_Get_t;

/** Message ID for CMD_FrameData1DS_Get */
#define CMD_FRAMEDATA1DS_GET 0x1E03

/**
   Requests basic VDSL1 frame setting data for the downstream direction.
*/
typedef struct CMD_FrameData1DS_Get CMD_FrameData1DS_Get_t;

/** Message ID for ACK_FrameData1DS_Get */
#define ACK_FRAMEDATA1DS_GET 0x1E03

/**
   Delivers basic VDSL1 framing parameters for the downstream direction requested by
   CMD_FrameData1DS_Get.These parameters are covered in sections 8.5 & 8.4 of G.993.1
   [4].
*/
typedef struct ACK_FrameData1DS_Get ACK_FrameData1DS_Get_t;

/** Message ID for CMD_FrameData1US_Get */
#define CMD_FRAMEDATA1US_GET 0x1F03

/**
   Requests basic VDSL1 frame setting data for the upstream direction.
*/
typedef struct CMD_FrameData1US_Get CMD_FrameData1US_Get_t;

/** Message ID for ACK_FrameData1US_Get */
#define ACK_FRAMEDATA1US_GET 0x1F03

/**
   Delivers basic VDSL1 frame setting data for the upstream direction requested by
   CMD_FrameData1US_Get. These parameters are covered in sections 8.5 & 8.4 of G.993.1
   [4].
*/
typedef struct ACK_FrameData1US_Get ACK_FrameData1US_Get_t;

/** Message ID for CMD_FrameDataExt1DS_Get */
#define CMD_FRAMEDATAEXT1DS_GET 0x2003

/**
   Requests an extended set of VDSL1 framing parameters for the downstream direction.
*/
typedef struct CMD_FrameDataExt1DS_Get CMD_FrameDataExt1DS_Get_t;

/** Message ID for ACK_FrameDataExt1DS_Get */
#define ACK_FRAMEDATAEXT1DS_GET 0x2003

/**
   Delivers an extended set of VDSL1 framing parameters for the downstream direction
   requested by CMD_FrameDataExt1DS_Get. (Sections 8.5 & 8.4 of G.993.1 [4])
*/
typedef struct ACK_FrameDataExt1DS_Get ACK_FrameDataExt1DS_Get_t;

/** Message ID for CMD_FrameDataExt1US_Get */
#define CMD_FRAMEDATAEXT1US_GET 0x2103

/**
   Requests an extended set of VDSL1 framing parameters for the upstream direction.
*/
typedef struct CMD_FrameDataExt1US_Get CMD_FrameDataExt1US_Get_t;

/** Message ID for ACK_FrameDataExt1US_Get */
#define ACK_FRAMEDATAEXT1US_GET 0x2103

/**
   Delivers an extended set of VDSL1 framing parameters for the upstream direction
   requested by CMD_FrameDataExt1US_Get. (Sections 8.5 & 8.4 of G.993.1 [4])
*/
typedef struct ACK_FrameDataExt1US_Get ACK_FrameDataExt1US_Get_t;

/** Message ID for CMD_FrameDataExt2DS_Get */
#define CMD_FRAMEDATAEXT2DS_GET 0x2203

/**
   Requests an extended set of VDSL2 framing parameters for the downstream direction.
*/
typedef struct CMD_FrameDataExt2DS_Get CMD_FrameDataExt2DS_Get_t;

/** Message ID for ACK_FrameDataExt2DS_Get */
#define ACK_FRAMEDATAEXT2DS_GET 0x2203

/**
   Delivers an extended set of VDSL2 framing parameters for the downstream direction
   requested by CMD_FrameDataExt2DS_Get. (Sections 7.5.2.6 of G.997.1 and 9.5 & 9.6 of
   G.993.2 [5])
*/
typedef struct ACK_FrameDataExt2DS_Get ACK_FrameDataExt2DS_Get_t;

/** Message ID for CMD_FrameDataExt2US_Get */
#define CMD_FRAMEDATAEXT2US_GET 0x2303

/**
   Requests an extended set of VDSL2 framing parameters for the upstream direction.
*/
typedef struct CMD_FrameDataExt2US_Get CMD_FrameDataExt2US_Get_t;

/** Message ID for ACK_FrameDataExt2US_Get */
#define ACK_FRAMEDATAEXT2US_GET 0x2303

/**
   Delivers an extended set of VDSL2 framing parameters for the upstream direction
   requested by CMD_FrameDataExt2US_Get. (Sections 7.5.2.6 of G.997.1 and 9.5 & 9.6 of
   G.993.2 [5])
*/
typedef struct ACK_FrameDataExt2US_Get ACK_FrameDataExt2US_Get_t;

/** Message ID for CMD_ADSL_FrameDataDS_LP0Get */
#define CMD_ADSL_FRAMEDATADS_LP0GET 0x010E

/**
   Requests ADSL framing parameters for the downstream direction, latency path
   0/Interleaved Path.
*/
typedef struct CMD_ADSL_FrameDataDS_LP0Get CMD_ADSL_FrameDataDS_LP0Get_t;

/** Message ID for ACK_ADSL_FrameDataDS_LP0Get */
#define ACK_ADSL_FRAMEDATADS_LP0GET 0x010E

/**
   Delivers the ADSL framing parameters for the downstream direction, LP0/Interleaved
   path, as requested by CMD_ADSL_FrameDataDS_LP0Get. (Sections 7.5 & 7.6 of G.992.3
   [2] and 7.4 of G.992.1 [1])
*/
typedef struct ACK_ADSL_FrameDataDS_LP0Get ACK_ADSL_FrameDataDS_LP0Get_t;

/** Message ID for CMD_ADSL_FrameDataUS_LP0Get */
#define CMD_ADSL_FRAMEDATAUS_LP0GET 0x020E

/**
   Requests ADSL framing parameters for the upstream direction, latency path
   0/Interleaved path.
*/
typedef struct CMD_ADSL_FrameDataUS_LP0Get CMD_ADSL_FrameDataUS_LP0Get_t;

/** Message ID for ACK_ADSL_FrameDataUS_LP0Get */
#define ACK_ADSL_FRAMEDATAUS_LP0GET 0x020E

/**
   Delivers the ADSL framing parameters for the upstream direction, latency path
   0/Interleaved path, as requested by CMD_ADSL_FrameDataUS_LP0Get. (Sections 7.5 & 7.6
   of G.992.3 [2] and 7.4 of G.992.1 [1])
*/
typedef struct ACK_ADSL_FrameDataUS_LP0Get ACK_ADSL_FrameDataUS_LP0Get_t;

/** Message ID for CMD_ADSL_FrameDataDS_LP1Get */
#define CMD_ADSL_FRAMEDATADS_LP1GET 0x030E

/**
   Requests ADSL framing parameters for the downstream direction, latency path 1 (LP1)/
   Fast path.
   Note: In VINAX Rev. 1.x to be used for ADSL1, "fast path" only.
*/
typedef struct CMD_ADSL_FrameDataDS_LP1Get CMD_ADSL_FrameDataDS_LP1Get_t;

/** Message ID for ACK_ADSL_FrameDataDS_LP1Get */
#define ACK_ADSL_FRAMEDATADS_LP1GET 0x030E

/**
   Delivers the ADSL framing parameters for the downstream direction, LP1/Fast path, as
   requested by CMD_ADSL_FrameDataDS_LP1Get. (Sections 7.5 & 7.6 of G.992.3 [2] and 7.4
   of G.992.1 [1])
*/
typedef struct ACK_ADSL_FrameDataDS_LP1Get ACK_ADSL_FrameDataDS_LP1Get_t;

/** Message ID for CMD_ADSL_FrameDataUS_LP1Get */
#define CMD_ADSL_FRAMEDATAUS_LP1GET 0x040E

/**
   Requests ADSL framing parameters for the upstream direction, latency path 1
   (LP1)/Fast path.
   Note: In VINAX Rev. 1.x to be used for ADSL1, "fast path" only.
*/
typedef struct CMD_ADSL_FrameDataUS_LP1Get CMD_ADSL_FrameDataUS_LP1Get_t;

/** Message ID for ACK_ADSL_FrameDataUS_LP1Get */
#define ACK_ADSL_FRAMEDATAUS_LP1GET 0x040E

/**
   Delivers the ADSL framing parameters for the upstream direction, LP1/Fast path, as
   requested by CMD_ADSL_FrameDataUS_LP1Get. (Sections 7.5 & 7.6 of G.992.3 [2] and 7.4
   of G.992.1 [1])
*/
typedef struct ACK_ADSL_FrameDataUS_LP1Get ACK_ADSL_FrameDataUS_LP1Get_t;

/** Message ID for CMD_AlgorithmControlGet */
#define CMD_ALGORITHMCONTROLGET 0x0205

/**
   Reads back the parameter values configured with CMD_AlgorithmControlSet.
*/
typedef struct CMD_AlgorithmControlGet CMD_AlgorithmControlGet_t;

/** Message ID for ACK_AlgorithmControlGet */
#define ACK_ALGORITHMCONTROLGET 0x0205

/**
   Provides the information requested by CMD_AlgorithmControlGet.
*/
typedef struct ACK_AlgorithmControlGet ACK_AlgorithmControlGet_t;

/** Message ID for CMD_DigitalFilterGet */
#define CMD_DIGITALFILTERGET 0x0405

/**
   Reads back the settings for the digital high-pass filters as configured with
   CMD_DigitalFilterSet.
*/
typedef struct CMD_DigitalFilterGet CMD_DigitalFilterGet_t;

/** Message ID for ACK_DigitalFilterGet */
#define ACK_DIGITALFILTERGET 0x0405

/**
   Provides the configured settings of the digital high-pass filters as requested by
   CMD_DigitalFilterGet.
*/
typedef struct ACK_DigitalFilterGet ACK_DigitalFilterGet_t;

/** Message ID for CMD_HybridSelectionGet */
#define CMD_HYBRIDSELECTIONGET 0x0505

/**
   Reads back the selected hybrid as configured with CMD_HybridSelect.
*/
typedef struct CMD_HybridSelectionGet CMD_HybridSelectionGet_t;

/** Message ID for ACK_HybridSelectionGet */
#define ACK_HYBRIDSELECTIONGET 0x0505

/**
   Provides the used hybrid as requested by CMD_HybridSelectionGet.
*/
typedef struct ACK_HybridSelectionGet ACK_HybridSelectionGet_t;

/** Message ID for CMD_ACE_FilterGet */
#define CMD_ACE_FILTERGET 0xD703

/**
   Reads the configured ACE filter mode.
*/
typedef struct CMD_ACE_FilterGet CMD_ACE_FilterGet_t;

/** Message ID for ACK_ACE_FilterGet */
#define ACK_ACE_FILTERGET 0xD703

/**
   Provides the configured ACE filter mode as requested by CMD_ACE_FilterGet.
*/
typedef struct ACK_ACE_FilterGet ACK_ACE_FilterGet_t;

/**
   Selects one or more groups of tones to be used during the handshake phase. (See
   G.994.1 Amendment 2 [8], Table 1/G.994.1)
*/
struct CMD_HS_ToneGroupSet
{
#if MEI_DRV_OS_BYTE_ORDER == MEI_DRV_OS_BIG_ENDIAN
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Reserved */
   IFX_uint16_t Res02 : 7;
   /** Tone Group 8: CAR_SET_V43I */
   IFX_uint16_t Group8 : 1;
   /** Tone Group 7: CAR_SET_V43P */
   IFX_uint16_t Group7 : 1;
   /** Tone Group 6: CAR_SET_V43 */
   IFX_uint16_t Group6 : 1;
   /** Tone Group 5: CAR_SET_J43 */
   IFX_uint16_t Group5 : 1;
   /** Tone Group 4: CAR_SET_C43 */
   IFX_uint16_t Group4 : 1;
   /** Tone Group 3: CAR_SET_B43C */
   IFX_uint16_t Group3 : 1;
   /** Tone Group 2: CAR_SET_B43 */
   IFX_uint16_t Group2 : 1;
   /** Tone Group 1: CAR_SET_A43C */
   IFX_uint16_t Group1 : 1;
   /** Tone Group 0: CAR_SET_A43 */
   IFX_uint16_t Group0 : 1;
#else
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Tone Group 0: CAR_SET_A43 */
   IFX_uint16_t Group0 : 1;
   /** Tone Group 1: CAR_SET_A43C */
   IFX_uint16_t Group1 : 1;
   /** Tone Group 2: CAR_SET_B43 */
   IFX_uint16_t Group2 : 1;
   /** Tone Group 3: CAR_SET_B43C */
   IFX_uint16_t Group3 : 1;
   /** Tone Group 4: CAR_SET_C43 */
   IFX_uint16_t Group4 : 1;
   /** Tone Group 5: CAR_SET_J43 */
   IFX_uint16_t Group5 : 1;
   /** Tone Group 6: CAR_SET_V43 */
   IFX_uint16_t Group6 : 1;
   /** Tone Group 7: CAR_SET_V43P */
   IFX_uint16_t Group7 : 1;
   /** Tone Group 8: CAR_SET_V43I */
   IFX_uint16_t Group8 : 1;
   /** Reserved */
   IFX_uint16_t Res02 : 7;
#endif
} __PACKED__ ;


/**
   Acknowledgement to CMD_HS_ToneGroupSet.
*/
struct ACK_HS_ToneGroupSet
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
   Configures the profile settings to be used for the handshake phase. (See G.994.1
   Amendment 4 [10], NPAR(3) coding).
   Note: All "support" bits should be set to "Enable".

*/
struct CMD_HS_VDSL2ProfileControl
{
#if MEI_DRV_OS_BYTE_ORDER == MEI_DRV_OS_BIG_ENDIAN
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Reserved */
   IFX_uint8_t Res02;
   /** 30a, Profile Support Bit 7 */
   IFX_uint16_t profileSup7 : 1;
   /** 17a, Profile Support Bit 6 */
   IFX_uint16_t profileSup6 : 1;
   /** 12b, Profile Support Bit 5 */
   IFX_uint16_t profileSup5 : 1;
   /** 12a, Profile Support Bit 4 */
   IFX_uint16_t profileSup4 : 1;
   /** 8d, Profile Support Bit 3 */
   IFX_uint16_t profileSup3 : 1;
   /** 8c, Profile Support Bit 2 */
   IFX_uint16_t profileSup2 : 1;
   /** 8b, Profile Support Bit 1 */
   IFX_uint16_t profileSup1 : 1;
   /** 8a, Profile Support Bit 0 */
   IFX_uint16_t profileSup0 : 1;
   /** Reserved */
   IFX_uint8_t Res11;
   /** 30a, Profile Preferred Bit 7 */
   IFX_uint16_t profilePref7 : 1;
   /** 17a, Profile Preferred Bit 6 */
   IFX_uint16_t profilePref6 : 1;
   /** 12b, Profile Preferred Bit 5 */
   IFX_uint16_t profilePref5 : 1;
   /** 12a, Profile Preferred Bit 4 */
   IFX_uint16_t profilePref4 : 1;
   /** 8d, Profile Preferred Bit 3 */
   IFX_uint16_t profilePref3 : 1;
   /** 8c, Profile Preferred Bit 2 */
   IFX_uint16_t profilePref2 : 1;
   /** 8b, Profile Preferred Bit 1 */
   IFX_uint16_t profilePref1 : 1;
   /** 8a, Profile Preferred Bit 0 */
   IFX_uint16_t profilePref0 : 1;
   /** ADLU-56, Annex A US0 PSDs Supported Bit 15 */
   IFX_uint16_t A_US0PsdSup15 : 1;
   /** ADLU-52, Annex A US0 PSDs Supported Bit 14 */
   IFX_uint16_t A_US0PsdSup14 : 1;
   /** ADLU-48, Annex A US0 PSDs Supported Bit 13 */
   IFX_uint16_t A_US0PsdSup13 : 1;
   /** ADLU-44, Annex A US0 PSDs Supported Bit 12 */
   IFX_uint16_t A_US0PsdSup12 : 1;
   /** ADLU-40, Annex A US0 PSDs Supported Bit 11 */
   IFX_uint16_t A_US0PsdSup11 : 1;
   /** ADLU-36, Annex A US0 PSDs Supported Bit 10 */
   IFX_uint16_t A_US0PsdSup10 : 1;
   /** ADLU-32, Annex A US0 PSDs Supported Bit 9 */
   IFX_uint16_t A_US0PsdSup9 : 1;
   /** EU-64, Annex A US0 PSDs Supported Bit 8 */
   IFX_uint16_t A_US0PsdSup8 : 1;
   /** EU-60, Annex A US0 PSDs Supported Bit 7 */
   IFX_uint16_t A_US0PsdSup7 : 1;
   /** EU-56, Annex A US0 PSDs Supported Bit 6 */
   IFX_uint16_t A_US0PsdSup6 : 1;
   /** EU-52, Annex A US0 PSDs Supported Bit 5 */
   IFX_uint16_t A_US0PsdSup5 : 1;
   /** EU-48, Annex A US0 PSDs Supported Bit 4 */
   IFX_uint16_t A_US0PsdSup4 : 1;
   /** EU-44, Annex A US0 PSDs Supported Bit 3 */
   IFX_uint16_t A_US0PsdSup3 : 1;
   /** EU-40, Annex A US0 PSDs Supported Bit 2 */
   IFX_uint16_t A_US0PsdSup2 : 1;
   /** EU-36, Annex A US0 PSDs Supported Bit 1 */
   IFX_uint16_t A_US0PsdSup1 : 1;
   /** EU-32, Annex A US0 PSDs Supported Bit 0 */
   IFX_uint16_t A_US0PsdSup0 : 1;
   /** Reserved */
   IFX_uint16_t Res36 : 10;
   /** ADLU-128, Annex A US0 PSDs Supported Bit 21 */
   IFX_uint16_t A_US0PsdSup21 : 1;
   /** EU-128, Annex A US0 PSDs Supported Bit 20 */
   IFX_uint16_t A_US0PsdSup20 : 1;
   /** 17a Profile, Annex A US0 PSDs Supported Bit 19 */
   IFX_uint16_t A_US0PsdSup19 : 1;
   /** 12b Profile, Annex A US0 PSDs Supported Bit 18 */
   IFX_uint16_t A_US0PsdSup18 : 1;
   /** ADLU-64, Annex A US0 PSDs Supported Bit 17 */
   IFX_uint16_t A_US0PsdSup17 : 1;
   /** ADLU-60, Annex A US0 PSDs Supported Bit 16 */
   IFX_uint16_t A_US0PsdSup16 : 1;
   /** ADLU-56, Annex A US0 PSDs Preferred Bit 15 */
   IFX_uint16_t A_US0PsdPref15 : 1;
   /** ADLU-52, Annex A US0 PSDs Preferred Bit 14 */
   IFX_uint16_t A_US0PsdPref14 : 1;
   /** ADLU-48, Annex A US0 PSDs Preferred Bit 13 */
   IFX_uint16_t A_US0PsdPref13 : 1;
   /** ADLU-44, Annex A US0 PSDs Preferred Bit 12 */
   IFX_uint16_t A_US0PsdPref12 : 1;
   /** ADLU-40, Annex A US0 PSDs Preferred Bit 11 */
   IFX_uint16_t A_US0PsdPref11 : 1;
   /** ADLU-36, Annex A US0 PSDs Preferred Bit 10 */
   IFX_uint16_t A_US0PsdPref10 : 1;
   /** ADLU-32, Annex A US0 PSDs Preferred Bit 9 */
   IFX_uint16_t A_US0PsdPref9 : 1;
   /** EU-64, Annex A US0 PSDs Preferred Bit 8 */
   IFX_uint16_t A_US0PsdPref8 : 1;
   /** EU-60, Annex A US0 PSDs Preferred Bit 7 */
   IFX_uint16_t A_US0PsdPref7 : 1;
   /** EU-56, Annex A US0 PSDs Preferred Bit 6 */
   IFX_uint16_t A_US0PsdPref6 : 1;
   /** EU-52, Annex A US0 PSDs Preferred Bit 5 */
   IFX_uint16_t A_US0PsdPref5 : 1;
   /** EU-48, Annex A US0 PSDs Preferred Bit 4 */
   IFX_uint16_t A_US0PsdPref4 : 1;
   /** EU-44, Annex A US0 PSDs Preferred Bit 3 */
   IFX_uint16_t A_US0PsdPref3 : 1;
   /** EU-40, Annex A US0 PSDs Preferred Bit 2 */
   IFX_uint16_t A_US0PsdPref2 : 1;
   /** EU-36, Annex A US0 PSDs Preferred Bit 1 */
   IFX_uint16_t A_US0PsdPref1 : 1;
   /** EU-32, Annex A US0 PSDs Preferred Bit 0 */
   IFX_uint16_t A_US0PsdPref0 : 1;
   /** Reserved */
   IFX_uint16_t Res59 : 10;
   /** ADLU-128, Annex A US0 PSDs Preferred Bit 21 */
   IFX_uint16_t A_US0PsdPref21 : 1;
   /** EU-128, Annex A US0 PSDs Preferred Bit 20 */
   IFX_uint16_t A_US0PsdPref20 : 1;
   /** 17a Profile, Annex A US0 PSDs Preferred Bit 19 */
   IFX_uint16_t A_US0PsdPref19 : 1;
   /** 12b Profile, Annex A US0 PSDs Preferred Bit 18 */
   IFX_uint16_t A_US0PsdPref18 : 1;
   /** ADLU-64, Annex A US0 PSDs Preferred Bit 17 */
   IFX_uint16_t A_US0PsdPref17 : 1;
   /** ADLU-60, Annex A US0 PSDs Preferred Bit 16 */
   IFX_uint16_t A_US0PsdPref16 : 1;
   /** Reserved */
   IFX_uint16_t Res66 : 11;
   /** 17a Profile, Annex B US0 PSDs Supported Bit 4 */
   IFX_uint16_t B_US0PsdSup4 : 1;
   /** 12b Profile, Annex B US0 PSDs Supported Bit 3 */
   IFX_uint16_t B_US0PsdSup3 : 1;
   /** US0 In 120 to 276 kHz, Annex B US0 PSDs Supported Bit 2 */
   IFX_uint16_t B_US0PsdSup2 : 1;
   /** US0 In 25 to 276 kHz, Annex B US0 PSDs Supported Bit 1 */
   IFX_uint16_t B_US0PsdSup1 : 1;
   /** US0 In 25 to 138 kHz, Annex B US0 PSDs Supported Bit 0 */
   IFX_uint16_t B_US0PsdSup0 : 1;
   /** Reserved */
   IFX_uint16_t Res72 : 13;
   /** US0 In 120 to 276 kHz, Annex B US0 PSDs Preferred Bit 2 */
   IFX_uint16_t B_US0PsdPref2 : 1;
   /** US0 In 25 to 276 kHz, Annex B US0 PSDs Preferred Bit 1 */
   IFX_uint16_t B_US0PsdPref1 : 1;
   /** US0 In 25 to 138 kHz, Annex B US0 PSDs Preferred Bit 0 */
   IFX_uint16_t B_US0PsdPref0 : 1;
   /** Reserved */
   IFX_uint16_t Res76 : 2;
   /** 17a Profile, Annex C US0 PSDs Supported Bit 13 */
   IFX_uint16_t C_US0PsdSup13 : 1;
   /** 12b Profile, Annex C US0 PSDs Supported Bit 12 */
   IFX_uint16_t C_US0PsdSup12 : 1;
   /** Reserved */
   IFX_uint16_t Res79 : 6;
   /** US0 In 25 to 276 kHz, Annex C US0 PSDs Supported Bit 5 */
   IFX_uint16_t C_US0PsdSup5 : 1;
   /** US0 In 25 to 138 kHz, Annex C US0 PSDs Supported Bit 4 */
   IFX_uint16_t C_US0PsdSup4 : 1;
   /** Reserved */
   IFX_uint16_t Res82 : 2;
   /** US0 In 25 to 276kHz, Annex C US0 PSDs Supported Bit 1 */
   IFX_uint16_t C_US0PsdSup1 : 1;
   /** US0 In 25 to 138 kHz, Annex C US0 PSDs Supported Bit 0 */
   IFX_uint16_t C_US0PsdSup0 : 1;
   /** Reserved */
   IFX_uint16_t Res85 : 10;
   /** US0 In 25 to 276 kHz, Annex C US0 PSDs Preferred Bit 5 */
   IFX_uint16_t C_US0PsdPref5 : 1;
   /** US0 In 25 to 138 kHz, Annex C US0 PSDs Preferred Bit 4 */
   IFX_uint16_t C_US0PsdPref4 : 1;
   /** Reserved */
   IFX_uint16_t Res88 : 2;
   /** US0 In 25 to 276kHz, Annex C US0 PSDs Preferred Bit 1 */
   IFX_uint16_t C_US0PsdPref1 : 1;
   /** US0 In 25 to 138 kHz, Annex C US0 PSDs Preferred Bit 0 */
   IFX_uint16_t C_US0PsdPref0 : 1;
#else
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** 8a, Profile Support Bit 0 */
   IFX_uint16_t profileSup0 : 1;
   /** 8b, Profile Support Bit 1 */
   IFX_uint16_t profileSup1 : 1;
   /** 8c, Profile Support Bit 2 */
   IFX_uint16_t profileSup2 : 1;
   /** 8d, Profile Support Bit 3 */
   IFX_uint16_t profileSup3 : 1;
   /** 12a, Profile Support Bit 4 */
   IFX_uint16_t profileSup4 : 1;
   /** 12b, Profile Support Bit 5 */
   IFX_uint16_t profileSup5 : 1;
   /** 17a, Profile Support Bit 6 */
   IFX_uint16_t profileSup6 : 1;
   /** 30a, Profile Support Bit 7 */
   IFX_uint16_t profileSup7 : 1;
   /** Reserved */
   IFX_uint8_t Res02;
   /** 8a, Profile Preferred Bit 0 */
   IFX_uint16_t profilePref0 : 1;
   /** 8b, Profile Preferred Bit 1 */
   IFX_uint16_t profilePref1 : 1;
   /** 8c, Profile Preferred Bit 2 */
   IFX_uint16_t profilePref2 : 1;
   /** 8d, Profile Preferred Bit 3 */
   IFX_uint16_t profilePref3 : 1;
   /** 12a, Profile Preferred Bit 4 */
   IFX_uint16_t profilePref4 : 1;
   /** 12b, Profile Preferred Bit 5 */
   IFX_uint16_t profilePref5 : 1;
   /** 17a, Profile Preferred Bit 6 */
   IFX_uint16_t profilePref6 : 1;
   /** 30a, Profile Preferred Bit 7 */
   IFX_uint16_t profilePref7 : 1;
   /** Reserved */
   IFX_uint8_t Res11;
   /** EU-32, Annex A US0 PSDs Supported Bit 0 */
   IFX_uint16_t A_US0PsdSup0 : 1;
   /** EU-36, Annex A US0 PSDs Supported Bit 1 */
   IFX_uint16_t A_US0PsdSup1 : 1;
   /** EU-40, Annex A US0 PSDs Supported Bit 2 */
   IFX_uint16_t A_US0PsdSup2 : 1;
   /** EU-44, Annex A US0 PSDs Supported Bit 3 */
   IFX_uint16_t A_US0PsdSup3 : 1;
   /** EU-48, Annex A US0 PSDs Supported Bit 4 */
   IFX_uint16_t A_US0PsdSup4 : 1;
   /** EU-52, Annex A US0 PSDs Supported Bit 5 */
   IFX_uint16_t A_US0PsdSup5 : 1;
   /** EU-56, Annex A US0 PSDs Supported Bit 6 */
   IFX_uint16_t A_US0PsdSup6 : 1;
   /** EU-60, Annex A US0 PSDs Supported Bit 7 */
   IFX_uint16_t A_US0PsdSup7 : 1;
   /** EU-64, Annex A US0 PSDs Supported Bit 8 */
   IFX_uint16_t A_US0PsdSup8 : 1;
   /** ADLU-32, Annex A US0 PSDs Supported Bit 9 */
   IFX_uint16_t A_US0PsdSup9 : 1;
   /** ADLU-36, Annex A US0 PSDs Supported Bit 10 */
   IFX_uint16_t A_US0PsdSup10 : 1;
   /** ADLU-40, Annex A US0 PSDs Supported Bit 11 */
   IFX_uint16_t A_US0PsdSup11 : 1;
   /** ADLU-44, Annex A US0 PSDs Supported Bit 12 */
   IFX_uint16_t A_US0PsdSup12 : 1;
   /** ADLU-48, Annex A US0 PSDs Supported Bit 13 */
   IFX_uint16_t A_US0PsdSup13 : 1;
   /** ADLU-52, Annex A US0 PSDs Supported Bit 14 */
   IFX_uint16_t A_US0PsdSup14 : 1;
   /** ADLU-56, Annex A US0 PSDs Supported Bit 15 */
   IFX_uint16_t A_US0PsdSup15 : 1;
   /** ADLU-60, Annex A US0 PSDs Supported Bit 16 */
   IFX_uint16_t A_US0PsdSup16 : 1;
   /** ADLU-64, Annex A US0 PSDs Supported Bit 17 */
   IFX_uint16_t A_US0PsdSup17 : 1;
   /** 12b Profile, Annex A US0 PSDs Supported Bit 18 */
   IFX_uint16_t A_US0PsdSup18 : 1;
   /** 17a Profile, Annex A US0 PSDs Supported Bit 19 */
   IFX_uint16_t A_US0PsdSup19 : 1;
   /** EU-128, Annex A US0 PSDs Supported Bit 20 */
   IFX_uint16_t A_US0PsdSup20 : 1;
   /** ADLU-128, Annex A US0 PSDs Supported Bit 21 */
   IFX_uint16_t A_US0PsdSup21 : 1;
   /** Reserved */
   IFX_uint16_t Res36 : 10;
   /** EU-32, Annex A US0 PSDs Preferred Bit 0 */
   IFX_uint16_t A_US0PsdPref0 : 1;
   /** EU-36, Annex A US0 PSDs Preferred Bit 1 */
   IFX_uint16_t A_US0PsdPref1 : 1;
   /** EU-40, Annex A US0 PSDs Preferred Bit 2 */
   IFX_uint16_t A_US0PsdPref2 : 1;
   /** EU-44, Annex A US0 PSDs Preferred Bit 3 */
   IFX_uint16_t A_US0PsdPref3 : 1;
   /** EU-48, Annex A US0 PSDs Preferred Bit 4 */
   IFX_uint16_t A_US0PsdPref4 : 1;
   /** EU-52, Annex A US0 PSDs Preferred Bit 5 */
   IFX_uint16_t A_US0PsdPref5 : 1;
   /** EU-56, Annex A US0 PSDs Preferred Bit 6 */
   IFX_uint16_t A_US0PsdPref6 : 1;
   /** EU-60, Annex A US0 PSDs Preferred Bit 7 */
   IFX_uint16_t A_US0PsdPref7 : 1;
   /** EU-64, Annex A US0 PSDs Preferred Bit 8 */
   IFX_uint16_t A_US0PsdPref8 : 1;
   /** ADLU-32, Annex A US0 PSDs Preferred Bit 9 */
   IFX_uint16_t A_US0PsdPref9 : 1;
   /** ADLU-36, Annex A US0 PSDs Preferred Bit 10 */
   IFX_uint16_t A_US0PsdPref10 : 1;
   /** ADLU-40, Annex A US0 PSDs Preferred Bit 11 */
   IFX_uint16_t A_US0PsdPref11 : 1;
   /** ADLU-44, Annex A US0 PSDs Preferred Bit 12 */
   IFX_uint16_t A_US0PsdPref12 : 1;
   /** ADLU-48, Annex A US0 PSDs Preferred Bit 13 */
   IFX_uint16_t A_US0PsdPref13 : 1;
   /** ADLU-52, Annex A US0 PSDs Preferred Bit 14 */
   IFX_uint16_t A_US0PsdPref14 : 1;
   /** ADLU-56, Annex A US0 PSDs Preferred Bit 15 */
   IFX_uint16_t A_US0PsdPref15 : 1;
   /** ADLU-60, Annex A US0 PSDs Preferred Bit 16 */
   IFX_uint16_t A_US0PsdPref16 : 1;
   /** ADLU-64, Annex A US0 PSDs Preferred Bit 17 */
   IFX_uint16_t A_US0PsdPref17 : 1;
   /** 12b Profile, Annex A US0 PSDs Preferred Bit 18 */
   IFX_uint16_t A_US0PsdPref18 : 1;
   /** 17a Profile, Annex A US0 PSDs Preferred Bit 19 */
   IFX_uint16_t A_US0PsdPref19 : 1;
   /** EU-128, Annex A US0 PSDs Preferred Bit 20 */
   IFX_uint16_t A_US0PsdPref20 : 1;
   /** ADLU-128, Annex A US0 PSDs Preferred Bit 21 */
   IFX_uint16_t A_US0PsdPref21 : 1;
   /** Reserved */
   IFX_uint16_t Res59 : 10;
   /** US0 In 25 to 138 kHz, Annex B US0 PSDs Supported Bit 0 */
   IFX_uint16_t B_US0PsdSup0 : 1;
   /** US0 In 25 to 276 kHz, Annex B US0 PSDs Supported Bit 1 */
   IFX_uint16_t B_US0PsdSup1 : 1;
   /** US0 In 120 to 276 kHz, Annex B US0 PSDs Supported Bit 2 */
   IFX_uint16_t B_US0PsdSup2 : 1;
   /** 12b Profile, Annex B US0 PSDs Supported Bit 3 */
   IFX_uint16_t B_US0PsdSup3 : 1;
   /** 17a Profile, Annex B US0 PSDs Supported Bit 4 */
   IFX_uint16_t B_US0PsdSup4 : 1;
   /** Reserved */
   IFX_uint16_t Res66 : 11;
   /** US0 In 25 to 138 kHz, Annex B US0 PSDs Preferred Bit 0 */
   IFX_uint16_t B_US0PsdPref0 : 1;
   /** US0 In 25 to 276 kHz, Annex B US0 PSDs Preferred Bit 1 */
   IFX_uint16_t B_US0PsdPref1 : 1;
   /** US0 In 120 to 276 kHz, Annex B US0 PSDs Preferred Bit 2 */
   IFX_uint16_t B_US0PsdPref2 : 1;
   /** Reserved */
   IFX_uint16_t Res72 : 13;
   /** US0 In 25 to 138 kHz, Annex C US0 PSDs Supported Bit 0 */
   IFX_uint16_t C_US0PsdSup0 : 1;
   /** US0 In 25 to 276kHz, Annex C US0 PSDs Supported Bit 1 */
   IFX_uint16_t C_US0PsdSup1 : 1;
   /** Reserved */
   IFX_uint16_t Res82 : 2;
   /** US0 In 25 to 138 kHz, Annex C US0 PSDs Supported Bit 4 */
   IFX_uint16_t C_US0PsdSup4 : 1;
   /** US0 In 25 to 276 kHz, Annex C US0 PSDs Supported Bit 5 */
   IFX_uint16_t C_US0PsdSup5 : 1;
   /** Reserved */
   IFX_uint16_t Res79 : 6;
   /** 12b Profile, Annex C US0 PSDs Supported Bit 12 */
   IFX_uint16_t C_US0PsdSup12 : 1;
   /** 17a Profile, Annex C US0 PSDs Supported Bit 13 */
   IFX_uint16_t C_US0PsdSup13 : 1;
   /** Reserved */
   IFX_uint16_t Res76 : 2;
   /** US0 In 25 to 138 kHz, Annex C US0 PSDs Preferred Bit 0 */
   IFX_uint16_t C_US0PsdPref0 : 1;
   /** US0 In 25 to 276kHz, Annex C US0 PSDs Preferred Bit 1 */
   IFX_uint16_t C_US0PsdPref1 : 1;
   /** Reserved */
   IFX_uint16_t Res88 : 2;
   /** US0 In 25 to 138 kHz, Annex C US0 PSDs Preferred Bit 4 */
   IFX_uint16_t C_US0PsdPref4 : 1;
   /** US0 In 25 to 276 kHz, Annex C US0 PSDs Preferred Bit 5 */
   IFX_uint16_t C_US0PsdPref5 : 1;
   /** Reserved */
   IFX_uint16_t Res85 : 10;
#endif
} __PACKED__ ;


/**
   Acknowledgement to CMD_HS_VDSL2ProfileControl.
*/
struct ACK_HS_VDSL2ProfileControl
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
   Requests the VDSL2 far-end Standard Info (See G.994.1 Amendment 4 [10], NPAR(3)
   coding).
*/
struct CMD_HS_StandardInfoFE_VDSL2Get
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
   Delivers the VDSL2 far-end info as requested by CMD_HS_StandardInfoFE_VDSL2Get (see
   G.994.1 Amendment 4 [10], NPAR(3) coding).
*/
struct ACK_HS_StandardInfoFE_VDSL2Get
{
#if MEI_DRV_OS_BYTE_ORDER == MEI_DRV_OS_BIG_ENDIAN
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Reserved */
   IFX_uint16_t Res02;
   /** Reserved */
   IFX_uint8_t Res03;
   /** 30a, Profile Support Bit 7 */
   IFX_uint16_t profileSup7 : 1;
   /** 17a, Profile Support Bit 6 */
   IFX_uint16_t profileSup6 : 1;
   /** 12b, Profile Support Bit 5 */
   IFX_uint16_t profileSup5 : 1;
   /** 12a, Profile Support Bit 4 */
   IFX_uint16_t profileSup4 : 1;
   /** 8d, Profile Support Bit 3 */
   IFX_uint16_t profileSup3 : 1;
   /** 8c, Profile Support Bit 2 */
   IFX_uint16_t profileSup2 : 1;
   /** 8b, Profile Support Bit 1 */
   IFX_uint16_t profileSup1 : 1;
   /** 8a, Profile Support Bit 0 */
   IFX_uint16_t profileSup0 : 1;
   /** ADLU-56, Annex A US0 PSDs Supported Bit 15 */
   IFX_uint16_t A_US0PsdSup15 : 1;
   /** ADLU-52, Annex A US0 PSDs Supported Bit 14 */
   IFX_uint16_t A_US0PsdSup14 : 1;
   /** ADLU-48, Annex A US0 PSDs Supported Bit 13 */
   IFX_uint16_t A_US0PsdSup13 : 1;
   /** ADLU-44, Annex A US0 PSDs Supported Bit 12 */
   IFX_uint16_t A_US0PsdSup12 : 1;
   /** ADLU-40, Annex A US0 PSDs Supported Bit 11 */
   IFX_uint16_t A_US0PsdSup11 : 1;
   /** ADLU-36, Annex A US0 PSDs Supported Bit 10 */
   IFX_uint16_t A_US0PsdSup10 : 1;
   /** ADLU-32, Annex A US0 PSDs Supported Bit 9 */
   IFX_uint16_t A_US0PsdSup9 : 1;
   /** EU-64, Annex A US0 PSDs Supported Bit 8 */
   IFX_uint16_t A_US0PsdSup8 : 1;
   /** EU-60, Annex A US0 PSDs Supported Bit 7 */
   IFX_uint16_t A_US0PsdSup7 : 1;
   /** EU-56, Annex A US0 PSDs Supported Bit 6 */
   IFX_uint16_t A_US0PsdSup6 : 1;
   /** EU-52, Annex A US0 PSDs Supported Bit 5 */
   IFX_uint16_t A_US0PsdSup5 : 1;
   /** EU-48, Annex A US0 PSDs Supported Bit 4 */
   IFX_uint16_t A_US0PsdSup4 : 1;
   /** EU-44, Annex A US0 PSDs Supported Bit 3 */
   IFX_uint16_t A_US0PsdSup3 : 1;
   /** EU-40, Annex A US0 PSDs Supported Bit 2 */
   IFX_uint16_t A_US0PsdSup2 : 1;
   /** EU-36, Annex A US0 PSDs Supported Bit 1 */
   IFX_uint16_t A_US0PsdSup1 : 1;
   /** EU-32, Annex A US0 PSDs Supported Bit 0 */
   IFX_uint16_t A_US0PsdSup0 : 1;
   /** Reserved */
   IFX_uint16_t Res28 : 10;
   /** ADLU-128 Annex A US0 PSDs Supported Bit 21 */
   IFX_uint16_t A_US0PsdSup21 : 1;
   /** EU-128, Annex A US0 PSDs Supported Bit 20 */
   IFX_uint16_t A_US0PsdSup20 : 1;
   /** 17a Profile, Annex A US0 PSDs Supported Bit 19 */
   IFX_uint16_t A_US0PsdSup19 : 1;
   /** 12b Profile, Annex A US0 PSDs Supported Bit 18 */
   IFX_uint16_t A_US0PsdSup18 : 1;
   /** ADLU-64, Annex A US0 PSDs Supported Bit 17 */
   IFX_uint16_t A_US0PsdSup17 : 1;
   /** ADLU-60, Annex A US0 PSDs Supported Bit 16 */
   IFX_uint16_t A_US0PsdSup16 : 1;
   /** Reserved */
   IFX_uint16_t Res35 : 11;
   /** 17a Profile, Annex B US0 PSDs Supported Bit 4 */
   IFX_uint16_t B_US0PsdSup4 : 1;
   /** 12b Profile, Annex B US0 PSDs Supported Bit 3 */
   IFX_uint16_t B_US0PsdSup3 : 1;
   /** US0 In 25 to 138 kHz, Annex B US0 PSDs Supported Bit 2 */
   IFX_uint16_t B_US0PsdSup2 : 1;
   /** US0 In 138 to 276 kHz, Annex B US0 PSDs Supported Bit 1 */
   IFX_uint16_t B_US0PsdSup1 : 1;
   /** US0 In 25 to 276 kHz, Annex B US0 PSDs Supported Bit 0 */
   IFX_uint16_t B_US0PsdSup0 : 1;
   /** Reserved */
   IFX_uint16_t Res41 : 2;
   /** 17a Profile, Annex C US0 PSDs Supported Bit 13 */
   IFX_uint16_t C_US0PsdSup13 : 1;
   /** 12b Profile, Annex C US0 PSDs Supported Bit 12 */
   IFX_uint16_t C_US0PsdSup12 : 1;
   /** Reserved */
   IFX_uint16_t Res44 : 6;
   /** US0 In 25 to 276 kHz, Annex C US0 PSDs Supported Bit 5 */
   IFX_uint16_t C_US0PsdSup5 : 1;
   /** US0 In 25 to 138 kHz, Annex C US0 PSDs Supported Bit 4 */
   IFX_uint16_t C_US0PsdSup4 : 1;
   /** Reserved */
   IFX_uint16_t Res47 : 2;
   /** US0 In 25 to 276kHz, Annex C US0 PSDs Supported Bit 1 */
   IFX_uint16_t C_US0PsdSup1 : 1;
   /** US0 In 25 to 138 kHz, Annex C US0 PSDs Supported Bit 0 */
   IFX_uint16_t C_US0PsdSup0 : 1;
#else
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Reserved */
   IFX_uint16_t Res02;
   /** 8a, Profile Support Bit 0 */
   IFX_uint16_t profileSup0 : 1;
   /** 8b, Profile Support Bit 1 */
   IFX_uint16_t profileSup1 : 1;
   /** 8c, Profile Support Bit 2 */
   IFX_uint16_t profileSup2 : 1;
   /** 8d, Profile Support Bit 3 */
   IFX_uint16_t profileSup3 : 1;
   /** 12a, Profile Support Bit 4 */
   IFX_uint16_t profileSup4 : 1;
   /** 12b, Profile Support Bit 5 */
   IFX_uint16_t profileSup5 : 1;
   /** 17a, Profile Support Bit 6 */
   IFX_uint16_t profileSup6 : 1;
   /** 30a, Profile Support Bit 7 */
   IFX_uint16_t profileSup7 : 1;
   /** Reserved */
   IFX_uint8_t Res03;
   /** EU-32, Annex A US0 PSDs Supported Bit 0 */
   IFX_uint16_t A_US0PsdSup0 : 1;
   /** EU-36, Annex A US0 PSDs Supported Bit 1 */
   IFX_uint16_t A_US0PsdSup1 : 1;
   /** EU-40, Annex A US0 PSDs Supported Bit 2 */
   IFX_uint16_t A_US0PsdSup2 : 1;
   /** EU-44, Annex A US0 PSDs Supported Bit 3 */
   IFX_uint16_t A_US0PsdSup3 : 1;
   /** EU-48, Annex A US0 PSDs Supported Bit 4 */
   IFX_uint16_t A_US0PsdSup4 : 1;
   /** EU-52, Annex A US0 PSDs Supported Bit 5 */
   IFX_uint16_t A_US0PsdSup5 : 1;
   /** EU-56, Annex A US0 PSDs Supported Bit 6 */
   IFX_uint16_t A_US0PsdSup6 : 1;
   /** EU-60, Annex A US0 PSDs Supported Bit 7 */
   IFX_uint16_t A_US0PsdSup7 : 1;
   /** EU-64, Annex A US0 PSDs Supported Bit 8 */
   IFX_uint16_t A_US0PsdSup8 : 1;
   /** ADLU-32, Annex A US0 PSDs Supported Bit 9 */
   IFX_uint16_t A_US0PsdSup9 : 1;
   /** ADLU-36, Annex A US0 PSDs Supported Bit 10 */
   IFX_uint16_t A_US0PsdSup10 : 1;
   /** ADLU-40, Annex A US0 PSDs Supported Bit 11 */
   IFX_uint16_t A_US0PsdSup11 : 1;
   /** ADLU-44, Annex A US0 PSDs Supported Bit 12 */
   IFX_uint16_t A_US0PsdSup12 : 1;
   /** ADLU-48, Annex A US0 PSDs Supported Bit 13 */
   IFX_uint16_t A_US0PsdSup13 : 1;
   /** ADLU-52, Annex A US0 PSDs Supported Bit 14 */
   IFX_uint16_t A_US0PsdSup14 : 1;
   /** ADLU-56, Annex A US0 PSDs Supported Bit 15 */
   IFX_uint16_t A_US0PsdSup15 : 1;
   /** ADLU-60, Annex A US0 PSDs Supported Bit 16 */
   IFX_uint16_t A_US0PsdSup16 : 1;
   /** ADLU-64, Annex A US0 PSDs Supported Bit 17 */
   IFX_uint16_t A_US0PsdSup17 : 1;
   /** 12b Profile, Annex A US0 PSDs Supported Bit 18 */
   IFX_uint16_t A_US0PsdSup18 : 1;
   /** 17a Profile, Annex A US0 PSDs Supported Bit 19 */
   IFX_uint16_t A_US0PsdSup19 : 1;
   /** EU-128, Annex A US0 PSDs Supported Bit 20 */
   IFX_uint16_t A_US0PsdSup20 : 1;
   /** ADLU-128 Annex A US0 PSDs Supported Bit 21 */
   IFX_uint16_t A_US0PsdSup21 : 1;
   /** Reserved */
   IFX_uint16_t Res28 : 10;
   /** US0 In 25 to 276 kHz, Annex B US0 PSDs Supported Bit 0 */
   IFX_uint16_t B_US0PsdSup0 : 1;
   /** US0 In 138 to 276 kHz, Annex B US0 PSDs Supported Bit 1 */
   IFX_uint16_t B_US0PsdSup1 : 1;
   /** US0 In 25 to 138 kHz, Annex B US0 PSDs Supported Bit 2 */
   IFX_uint16_t B_US0PsdSup2 : 1;
   /** 12b Profile, Annex B US0 PSDs Supported Bit 3 */
   IFX_uint16_t B_US0PsdSup3 : 1;
   /** 17a Profile, Annex B US0 PSDs Supported Bit 4 */
   IFX_uint16_t B_US0PsdSup4 : 1;
   /** Reserved */
   IFX_uint16_t Res35 : 11;
   /** US0 In 25 to 138 kHz, Annex C US0 PSDs Supported Bit 0 */
   IFX_uint16_t C_US0PsdSup0 : 1;
   /** US0 In 25 to 276kHz, Annex C US0 PSDs Supported Bit 1 */
   IFX_uint16_t C_US0PsdSup1 : 1;
   /** Reserved */
   IFX_uint16_t Res47 : 2;
   /** US0 In 25 to 138 kHz, Annex C US0 PSDs Supported Bit 4 */
   IFX_uint16_t C_US0PsdSup4 : 1;
   /** US0 In 25 to 276 kHz, Annex C US0 PSDs Supported Bit 5 */
   IFX_uint16_t C_US0PsdSup5 : 1;
   /** Reserved */
   IFX_uint16_t Res44 : 6;
   /** 12b Profile, Annex C US0 PSDs Supported Bit 12 */
   IFX_uint16_t C_US0PsdSup12 : 1;
   /** 17a Profile, Annex C US0 PSDs Supported Bit 13 */
   IFX_uint16_t C_US0PsdSup13 : 1;
   /** Reserved */
   IFX_uint16_t Res41 : 2;
#endif
} __PACKED__ ;


/**
   Requests the actual selected VDSL2 Profile (See G.994.1 Amendment 4 [10], NPAR(3)
   coding).
*/
struct CMD_HS_SelectedProfileVDSL2Get
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
   Provides the actual selected VDSL2 Profile as requested by
   CMD_HS_SelectedProfileVDSL2Get (see G.994.1 Amendment 4 [10], NPAR(3) coding).
*/
struct ACK_HS_SelectedProfileVDSL2Get
{
#if MEI_DRV_OS_BYTE_ORDER == MEI_DRV_OS_BIG_ENDIAN
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Reserved */
   IFX_uint16_t Res02;
   /** Reserved */
   IFX_uint8_t Res03;
   /** 30a, Profile Selected Bit 7 */
   IFX_uint16_t profileSel7 : 1;
   /** 17a, Profile Selected Bit 6 */
   IFX_uint16_t profileSel6 : 1;
   /** 12b, Profile Selected Bit 5 */
   IFX_uint16_t profileSel5 : 1;
   /** 12a, Profile Selected Bit 4 */
   IFX_uint16_t profileSel4 : 1;
   /** 8d, Profile Selected Bit 3 */
   IFX_uint16_t profileSel3 : 1;
   /** 8c, Profile Selected Bit 2 */
   IFX_uint16_t profileSel2 : 1;
   /** 8b, Profile Selected Bit 1 */
   IFX_uint16_t profileSel1 : 1;
   /** 8a, Profile Selected Bit 0 */
   IFX_uint16_t profileSel0 : 1;
   /** ADLU-56, Annex A US0 PSDs Selected Bit  15 */
   IFX_uint16_t A_US0PsdSel15 : 1;
   /** ADLU-52, Annex A US0 PSDs Selected Bit  14 */
   IFX_uint16_t A_US0PsdSel14 : 1;
   /** ADLU-48, Annex A US0 PSDs Selected Bit  13 */
   IFX_uint16_t A_US0PsdSel13 : 1;
   /** ADLU-44, Annex A US0 PSDs Selected Bit  12 */
   IFX_uint16_t A_US0PsdSel12 : 1;
   /** ADLU-40, Annex A US0 PSDs Selected Bit  11 */
   IFX_uint16_t A_US0PsdSel11 : 1;
   /** ADLU-36, Annex A US0 PSDs Selected Bit  10 */
   IFX_uint16_t A_US0PsdSel10 : 1;
   /** ADLU-32, Annex A US0 PSDs Selected Bit  9 */
   IFX_uint16_t A_US0PsdSel9 : 1;
   /** EU-64, Annex A US0 PSDs Selected Bit  8 */
   IFX_uint16_t A_US0PsdSel8 : 1;
   /** EU-60, Annex A US0 PSDs Selected Bit  7 */
   IFX_uint16_t A_US0PsdSel7 : 1;
   /** EU-56, Annex A US0 PSDs Selected Bit  6 */
   IFX_uint16_t A_US0PsdSel6 : 1;
   /** EU-52, Annex A US0 PSDs Selected Bit  5 */
   IFX_uint16_t A_US0PsdSel5 : 1;
   /** EU-48, Annex A US0 PSDs Selected Bit  4 */
   IFX_uint16_t A_US0PsdSel4 : 1;
   /** EU-44, Annex A US0 PSDs Selected Bit  3 */
   IFX_uint16_t A_US0PsdSel3 : 1;
   /** EU-40, Annex A US0 PSDs Selected Bit  2 */
   IFX_uint16_t A_US0PsdSel2 : 1;
   /** EU-36, Annex A US0 PSDs Selected Bit  1 */
   IFX_uint16_t A_US0PsdSel1 : 1;
   /** EU-32, Annex A US0 PSDs Selected Bit  0 */
   IFX_uint16_t A_US0PsdSel0 : 1;
   /** Reserved */
   IFX_uint16_t Res28 : 10;
   /** ADLU-128 Annex A US0 PSDs Selected Bit 21 */
   IFX_uint16_t A_US0PsdSel21 : 1;
   /** EU-128, Annex A US0 PSDs Selected Bit 20 */
   IFX_uint16_t A_US0PsdSel20 : 1;
   /** Reserved */
   IFX_uint16_t Res31 : 2;
   /** ADLU-64, Annex A US0 PSDs Selected Bit 17 */
   IFX_uint16_t A_US0PsdSel17 : 1;
   /** ADLU-60, Annex A US0 PSDs Selected Bit 16 */
   IFX_uint16_t A_US0PsdSel16 : 1;
   /** Reserved */
   IFX_uint16_t Res34 : 13;
   /** US0 In 120 to 276 kHz, Annex B US0 PSDs Selected Bit 2 */
   IFX_uint16_t B_US0PsdSel2 : 1;
   /** US0 In 25 to 276 kHz, Annex B US0 PSDs Selected Bit 1 */
   IFX_uint16_t B_US0PsdSel1 : 1;
   /** US0 In 25 to 138 kHz, Annex B US0 PSDs Selected Bit 0 */
   IFX_uint16_t B_US0PsdSel0 : 1;
   /** Reserved */
   IFX_uint16_t Res38 : 10;
   /** US0 In 25 to 276 kHz, Annex C US0 PSDs Selected Bit 5 */
   IFX_uint16_t C_US0PsdSel5 : 1;
   /** US0 In 25 to 138 kHz, Annex C US0 PSDs Selected Bit 4 */
   IFX_uint16_t C_US0PsdSel4 : 1;
   /** Reserved */
   IFX_uint16_t Res41 : 2;
   /** US0 In 25 to 276kHz, Annex C US0 PSDs Selected Bit 1 */
   IFX_uint16_t C_US0PsdSel1 : 1;
   /** US0 In 25 to 138 kHz, Annex C US0 PSDs Selected Bit 0 */
   IFX_uint16_t C_US0PsdSel0 : 1;
#else
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Reserved */
   IFX_uint16_t Res02;
   /** 8a, Profile Selected Bit 0 */
   IFX_uint16_t profileSel0 : 1;
   /** 8b, Profile Selected Bit 1 */
   IFX_uint16_t profileSel1 : 1;
   /** 8c, Profile Selected Bit 2 */
   IFX_uint16_t profileSel2 : 1;
   /** 8d, Profile Selected Bit 3 */
   IFX_uint16_t profileSel3 : 1;
   /** 12a, Profile Selected Bit 4 */
   IFX_uint16_t profileSel4 : 1;
   /** 12b, Profile Selected Bit 5 */
   IFX_uint16_t profileSel5 : 1;
   /** 17a, Profile Selected Bit 6 */
   IFX_uint16_t profileSel6 : 1;
   /** 30a, Profile Selected Bit 7 */
   IFX_uint16_t profileSel7 : 1;
   /** Reserved */
   IFX_uint8_t Res03;
   /** EU-32, Annex A US0 PSDs Selected Bit  0 */
   IFX_uint16_t A_US0PsdSel0 : 1;
   /** EU-36, Annex A US0 PSDs Selected Bit  1 */
   IFX_uint16_t A_US0PsdSel1 : 1;
   /** EU-40, Annex A US0 PSDs Selected Bit  2 */
   IFX_uint16_t A_US0PsdSel2 : 1;
   /** EU-44, Annex A US0 PSDs Selected Bit  3 */
   IFX_uint16_t A_US0PsdSel3 : 1;
   /** EU-48, Annex A US0 PSDs Selected Bit  4 */
   IFX_uint16_t A_US0PsdSel4 : 1;
   /** EU-52, Annex A US0 PSDs Selected Bit  5 */
   IFX_uint16_t A_US0PsdSel5 : 1;
   /** EU-56, Annex A US0 PSDs Selected Bit  6 */
   IFX_uint16_t A_US0PsdSel6 : 1;
   /** EU-60, Annex A US0 PSDs Selected Bit  7 */
   IFX_uint16_t A_US0PsdSel7 : 1;
   /** EU-64, Annex A US0 PSDs Selected Bit  8 */
   IFX_uint16_t A_US0PsdSel8 : 1;
   /** ADLU-32, Annex A US0 PSDs Selected Bit  9 */
   IFX_uint16_t A_US0PsdSel9 : 1;
   /** ADLU-36, Annex A US0 PSDs Selected Bit  10 */
   IFX_uint16_t A_US0PsdSel10 : 1;
   /** ADLU-40, Annex A US0 PSDs Selected Bit  11 */
   IFX_uint16_t A_US0PsdSel11 : 1;
   /** ADLU-44, Annex A US0 PSDs Selected Bit  12 */
   IFX_uint16_t A_US0PsdSel12 : 1;
   /** ADLU-48, Annex A US0 PSDs Selected Bit  13 */
   IFX_uint16_t A_US0PsdSel13 : 1;
   /** ADLU-52, Annex A US0 PSDs Selected Bit  14 */
   IFX_uint16_t A_US0PsdSel14 : 1;
   /** ADLU-56, Annex A US0 PSDs Selected Bit  15 */
   IFX_uint16_t A_US0PsdSel15 : 1;
   /** ADLU-60, Annex A US0 PSDs Selected Bit 16 */
   IFX_uint16_t A_US0PsdSel16 : 1;
   /** ADLU-64, Annex A US0 PSDs Selected Bit 17 */
   IFX_uint16_t A_US0PsdSel17 : 1;
   /** Reserved */
   IFX_uint16_t Res31 : 2;
   /** EU-128, Annex A US0 PSDs Selected Bit 20 */
   IFX_uint16_t A_US0PsdSel20 : 1;
   /** ADLU-128 Annex A US0 PSDs Selected Bit 21 */
   IFX_uint16_t A_US0PsdSel21 : 1;
   /** Reserved */
   IFX_uint16_t Res28 : 10;
   /** US0 In 25 to 138 kHz, Annex B US0 PSDs Selected Bit 0 */
   IFX_uint16_t B_US0PsdSel0 : 1;
   /** US0 In 25 to 276 kHz, Annex B US0 PSDs Selected Bit 1 */
   IFX_uint16_t B_US0PsdSel1 : 1;
   /** US0 In 120 to 276 kHz, Annex B US0 PSDs Selected Bit 2 */
   IFX_uint16_t B_US0PsdSel2 : 1;
   /** Reserved */
   IFX_uint16_t Res34 : 13;
   /** US0 In 25 to 138 kHz, Annex C US0 PSDs Selected Bit 0 */
   IFX_uint16_t C_US0PsdSel0 : 1;
   /** US0 In 25 to 276kHz, Annex C US0 PSDs Selected Bit 1 */
   IFX_uint16_t C_US0PsdSel1 : 1;
   /** Reserved */
   IFX_uint16_t Res41 : 2;
   /** US0 In 25 to 138 kHz, Annex C US0 PSDs Selected Bit 4 */
   IFX_uint16_t C_US0PsdSel4 : 1;
   /** US0 In 25 to 276 kHz, Annex C US0 PSDs Selected Bit 5 */
   IFX_uint16_t C_US0PsdSel5 : 1;
   /** Reserved */
   IFX_uint16_t Res38 : 10;
#endif
} __PACKED__ ;


/**
   Requests the handshake information about the far-end operating mode (See G.994.1 [6]
   and Amendments 1-4 [7]-[10], standard information fields- SPAR(1) coding).
*/
struct CMD_HS_StandardInfoFE_SPAR1Get
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
   Provides the handshake information about the far-end operating mode (See G.994.1 [6]
   and Amendments 1-4 [7]-[10], Standard information field - SPAR(1) coding). The bit
   numbering per octet below follows the standard (starting with "1").
*/
struct ACK_HS_StandardInfoFE_SPAR1Get
{
#if MEI_DRV_OS_BYTE_ORDER == MEI_DRV_OS_BIG_ENDIAN
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Reserved */
   IFX_uint16_t Res02 : 1;
   /** Octet 2, Bit 7: Committee T1 enhanced SHDSL */
   IFX_uint16_t Oct2B7 : 1;
   /** Octet 2, Bit 6: ETSI SCM VDSL */
   IFX_uint16_t Oct2B6 : 1;
   /** Octet 2, Bit 5: ETSI MCM VDSL */
   IFX_uint16_t Oct2B5 : 1;
   /** Octet 2, Bit 4: T1E1 Trial-use SCM VDSL */
   IFX_uint16_t Oct2B4 : 1;
   /** Octet 2, Bit 3: T1E1 Trial-use MCM VDSL */
   IFX_uint16_t Oct2B3 : 1;
   /** Octet 2, Bit 2: G991.2 Annex B/G */
   IFX_uint16_t Oct2B2 : 1;
   /** Octet 2, Bit 1: G991.2 Annex A/F */
   IFX_uint16_t Oct2B1 : 1;
   /** Reserved */
   IFX_uint16_t Res10 : 1;
   /** Octet 1, Bit 7: G992.1 Annex I */
   IFX_uint16_t Oct1B7 : 1;
   /** Octet 1, Bit 6: G992.1 Annex H */
   IFX_uint16_t Oct1B6 : 1;
   /** Octet 1, Bit 5: G992.2 Annex C */
   IFX_uint16_t Oct1B5 : 1;
   /** Octet 1, Bit 4: G992.2 Annex A/B */
   IFX_uint16_t Oct1B4 : 1;
   /** Octet 1, Bit 3: G992.1 Annex C */
   IFX_uint16_t Oct1B3 : 1;
   /** Octet 1, Bit 2: G992.1 Annex B */
   IFX_uint16_t Oct1B2 : 1;
   /** Octet 1, Bit 1: G992.1 Annex A */
   IFX_uint16_t Oct1B1 : 1;
   /** Reserved */
   IFX_uint16_t Res18 : 1;
   /** Octet 4, Bit 7: IEEE 802.3ah 2BASE-TS */
   IFX_uint16_t Oct4B7 : 1;
   /** Octet 4, Bit 6: IEEE 802.3ah 2BASE-TL */
   IFX_uint16_t Oct4B6 : 1;
   /** Octet 4, Bit 5: G992.5 Annex J */
   IFX_uint16_t Oct4B5 : 1;
   /** Octet 4, Bit 4: G992.3 Annex M */
   IFX_uint16_t Oct4B4 : 1;
   /** Octet 4, Bit 3: G992.5 Annex I */
   IFX_uint16_t Oct4B3 : 1;
   /** Octet 4, Bit 2: G992.5 Annex B */
   IFX_uint16_t Oct4B2 : 1;
   /** Octet 4, Bit 1: G992.5 Annex A */
   IFX_uint16_t Oct4B1 : 1;
   /** Reserved */
   IFX_uint16_t Res26 : 1;
   /** Octet 3, Bit 7: G992.3 Annex C */
   IFX_uint16_t Oct3B7 : 1;
   /** Octet 3, Bit 6: G992.4 Annex I */
   IFX_uint16_t Oct3B6 : 1;
   /** Octet 3, Bit 5: G992.4 Annex A */
   IFX_uint16_t Oct3B5 : 1;
   /** Octet 3, Bit 4: G992.3 Annex J */
   IFX_uint16_t Oct3B4 : 1;
   /** Octet 3, Bit 3: G992.3 Annex I */
   IFX_uint16_t Oct3B3 : 1;
   /** Octet 3, Bit 2: G992.3 Annex B */
   IFX_uint16_t Oct3B2 : 1;
   /** Octet 3, Bit 1: G992.3 Annex A/L */
   IFX_uint16_t Oct3B1 : 1;
   /** Reserved */
   IFX_uint8_t Res34;
   /** Reserved */
   IFX_uint16_t Res35 : 2;
   /** Octet 5, Bit 5: G993.2 */
   IFX_uint16_t Oct5B6 : 1;
   /** Octet 5, Bit 4: G992.5 Annex C */
   IFX_uint16_t Oct5B5 : 1;
   /** Octet 5, Bit 3: Variable Silence Period */
   IFX_uint16_t Oct5B4 : 1;
   /** Octet 5, Bit 2: G992.1 Annex I / T1E1 TRQ 12 */
   IFX_uint16_t Oct5B3 : 1;
   /** Octet 5, Bit 1: G993.1 / ANSI T1.424 */
   IFX_uint16_t Oct5B2 : 1;
   /** Octet 5, Bit 0: G992.5 Annex M */
   IFX_uint16_t Oct5B1 : 1;
#else
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Octet 1, Bit 1: G992.1 Annex A */
   IFX_uint16_t Oct1B1 : 1;
   /** Octet 1, Bit 2: G992.1 Annex B */
   IFX_uint16_t Oct1B2 : 1;
   /** Octet 1, Bit 3: G992.1 Annex C */
   IFX_uint16_t Oct1B3 : 1;
   /** Octet 1, Bit 4: G992.2 Annex A/B */
   IFX_uint16_t Oct1B4 : 1;
   /** Octet 1, Bit 5: G992.2 Annex C */
   IFX_uint16_t Oct1B5 : 1;
   /** Octet 1, Bit 6: G992.1 Annex H */
   IFX_uint16_t Oct1B6 : 1;
   /** Octet 1, Bit 7: G992.1 Annex I */
   IFX_uint16_t Oct1B7 : 1;
   /** Reserved */
   IFX_uint16_t Res10 : 1;
   /** Octet 2, Bit 1: G991.2 Annex A/F */
   IFX_uint16_t Oct2B1 : 1;
   /** Octet 2, Bit 2: G991.2 Annex B/G */
   IFX_uint16_t Oct2B2 : 1;
   /** Octet 2, Bit 3: T1E1 Trial-use MCM VDSL */
   IFX_uint16_t Oct2B3 : 1;
   /** Octet 2, Bit 4: T1E1 Trial-use SCM VDSL */
   IFX_uint16_t Oct2B4 : 1;
   /** Octet 2, Bit 5: ETSI MCM VDSL */
   IFX_uint16_t Oct2B5 : 1;
   /** Octet 2, Bit 6: ETSI SCM VDSL */
   IFX_uint16_t Oct2B6 : 1;
   /** Octet 2, Bit 7: Committee T1 enhanced SHDSL */
   IFX_uint16_t Oct2B7 : 1;
   /** Reserved */
   IFX_uint16_t Res02 : 1;
   /** Octet 3, Bit 1: G992.3 Annex A/L */
   IFX_uint16_t Oct3B1 : 1;
   /** Octet 3, Bit 2: G992.3 Annex B */
   IFX_uint16_t Oct3B2 : 1;
   /** Octet 3, Bit 3: G992.3 Annex I */
   IFX_uint16_t Oct3B3 : 1;
   /** Octet 3, Bit 4: G992.3 Annex J */
   IFX_uint16_t Oct3B4 : 1;
   /** Octet 3, Bit 5: G992.4 Annex A */
   IFX_uint16_t Oct3B5 : 1;
   /** Octet 3, Bit 6: G992.4 Annex I */
   IFX_uint16_t Oct3B6 : 1;
   /** Octet 3, Bit 7: G992.3 Annex C */
   IFX_uint16_t Oct3B7 : 1;
   /** Reserved */
   IFX_uint16_t Res26 : 1;
   /** Octet 4, Bit 1: G992.5 Annex A */
   IFX_uint16_t Oct4B1 : 1;
   /** Octet 4, Bit 2: G992.5 Annex B */
   IFX_uint16_t Oct4B2 : 1;
   /** Octet 4, Bit 3: G992.5 Annex I */
   IFX_uint16_t Oct4B3 : 1;
   /** Octet 4, Bit 4: G992.3 Annex M */
   IFX_uint16_t Oct4B4 : 1;
   /** Octet 4, Bit 5: G992.5 Annex J */
   IFX_uint16_t Oct4B5 : 1;
   /** Octet 4, Bit 6: IEEE 802.3ah 2BASE-TL */
   IFX_uint16_t Oct4B6 : 1;
   /** Octet 4, Bit 7: IEEE 802.3ah 2BASE-TS */
   IFX_uint16_t Oct4B7 : 1;
   /** Reserved */
   IFX_uint16_t Res18 : 1;
   /** Octet 5, Bit 0: G992.5 Annex M */
   IFX_uint16_t Oct5B1 : 1;
   /** Octet 5, Bit 1: G993.1 / ANSI T1.424 */
   IFX_uint16_t Oct5B2 : 1;
   /** Octet 5, Bit 2: G992.1 Annex I / T1E1 TRQ 12 */
   IFX_uint16_t Oct5B3 : 1;
   /** Octet 5, Bit 3: Variable Silence Period */
   IFX_uint16_t Oct5B4 : 1;
   /** Octet 5, Bit 4: G992.5 Annex C */
   IFX_uint16_t Oct5B5 : 1;
   /** Octet 5, Bit 5: G993.2 */
   IFX_uint16_t Oct5B6 : 1;
   /** Reserved */
   IFX_uint16_t Res35 : 2;
   /** Reserved */
   IFX_uint8_t Res34;
#endif
} __PACKED__ ;


/**
   Sets the in System Vendor ID at the xTU-C. (Section 7.4.3 of G997.1 [11])
*/
struct CMD_SysVendorID_O_Set
{
#if MEI_DRV_OS_BYTE_ORDER == MEI_DRV_OS_BIG_ENDIAN
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** xTU-C System Vendor ID */
   IFX_uint16_t sysVendorID[4];
#else
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** xTU-C System Vendor ID */
   IFX_uint16_t sysVendorID[4];
#endif
} __PACKED__ ;


/**
   Acknowledgement to CMD_SysVendorID_O_Set.
*/
struct ACK_SysVendorID_O_Set
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
   Sets the in System Vendor ID at the xTU-R. (Section 7.4.4 of G997.1 [11])
*/
struct CMD_SysVendorID_R_Set
{
#if MEI_DRV_OS_BYTE_ORDER == MEI_DRV_OS_BIG_ENDIAN
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** xTU-R System Vendor ID */
   IFX_uint16_t sysVendorID[4];
#else
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** xTU-R System Vendor ID */
   IFX_uint16_t sysVendorID[4];
#endif
} __PACKED__ ;


/**
   Acknowledgement to CMD_SysVendorID_R_Set.
*/
struct ACK_SysVendorID_R_Set
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
   Sets the in system vendor version number at the xTU-C. (Section 7.4.5 of G997.1
   [11])
*/
struct CMD_SysVendorVersionNum_O_Set
{
#if MEI_DRV_OS_BYTE_ORDER == MEI_DRV_OS_BIG_ENDIAN
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** xTU-C System Vendor Version Number */
   IFX_uint16_t versionNum[8];
#else
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** xTU-C System Vendor Version Number */
   IFX_uint16_t versionNum[8];
#endif
} __PACKED__ ;


/**
   Acknowledgement to CMD_SysVendorVersionNum_O_Set.
*/
struct ACK_SysVendorVersionNum_O_Set
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
   Sets the in system vendor version number at the xTU-R. (Section 7.4.6 of G997.1
   [11])
*/
struct CMD_SysVendorVersionNum_R_Set
{
#if MEI_DRV_OS_BYTE_ORDER == MEI_DRV_OS_BIG_ENDIAN
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** xTU-R System Vendor Version Number */
   IFX_uint16_t versionNum[8];
#else
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** xTU-R System Vendor Version Number */
   IFX_uint16_t versionNum[8];
#endif
} __PACKED__ ;


/**
   Acknowledgement to CMD_SysVendorVersionNum_R_Set.
*/
struct ACK_SysVendorVersionNum_R_Set
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
   For CO side only!
   Sets the in system vendor version number at the xTU-C. (Section 7.4.7 of G997.1
   [11])
*/
struct CMD_SysVendorSerialNum_O_Set
{
#if MEI_DRV_OS_BYTE_ORDER == MEI_DRV_OS_BIG_ENDIAN
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** xTU-C System Vendor Serial Number */
   IFX_uint16_t serialNum[16];
#else
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** xTU-C System Vendor Serial Number */
   IFX_uint16_t serialNum[16];
#endif
} __PACKED__ ;


/**
   Acknowledgement to CMD_SysVendorSerialNum_O_Set.
*/
struct ACK_SysVendorSerialNum_O_Set
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
   Sets the system vendor serial number at the xTU-R. (Section 7.4.8 of G997.1 [11])
*/
struct CMD_SysVendorSerialNum_R_Set
{
#if MEI_DRV_OS_BYTE_ORDER == MEI_DRV_OS_BIG_ENDIAN
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** xTU-R System Vendor Serial Number */
   IFX_uint16_t serialNum[16];
#else
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** xTU-R System Vendor Serial Number */
   IFX_uint16_t serialNum[16];
#endif
} __PACKED__ ;


/**
   Acknowledgement to CMD_SysVendorSerialNum_R_Set.
*/
struct ACK_SysVendorSerialNum_R_Set
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
   Sets auxiliary inventory information at the VTU-O (¤11.2.3.2.4 of G993.2 [5]).
*/
struct CMD_AuxInventoryInfo_O_Set
{
#if MEI_DRV_OS_BYTE_ORDER == MEI_DRV_OS_BIG_ENDIAN
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** VTU-O Auxiliary Inventory Information */
   IFX_uint16_t auxInfo[32];
#else
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** VTU-O Auxiliary Inventory Information */
   IFX_uint16_t auxInfo[32];
#endif
} __PACKED__ ;


/**
   Acknowledgement to CMD_AuxInventoryInfo_O_Set.
*/
struct ACK_AuxInventoryInfo_O_Set
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
   Sets auxiliary inventory information at the VTU-R (¤11.2.3.2.4 of G993.2 [5]).
*/
struct CMD_AuxInventoryInfo_R_Set
{
#if MEI_DRV_OS_BYTE_ORDER == MEI_DRV_OS_BIG_ENDIAN
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** VTU-R Auxiliary Inventory Information */
   IFX_uint16_t auxInfo[32];
#else
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** VTU-R Auxiliary Inventory Information */
   IFX_uint16_t auxInfo[32];
#endif
} __PACKED__ ;


/**
   Acknowledgement to CMD_AuxInventoryInfo_R_Set.
*/
struct ACK_AuxInventoryInfo_R_Set
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
   Requests the xTU-C Vendor ID. (Section 7.4.1 of G997.1 [11])
*/
struct CMD_VendorID_O_Get
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
   Provides the xTU-C Vendor ID as requested by CMD_VendorID_O_Get.
*/
struct ACK_VendorID_O_Get
{
#if MEI_DRV_OS_BYTE_ORDER == MEI_DRV_OS_BIG_ENDIAN
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** xTU-C G.994.1 Vendor ID */
   IFX_uint16_t vendorID[4];
#else
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** xTU-C G.994.1 Vendor ID */
   IFX_uint16_t vendorID[4];
#endif
} __PACKED__ ;


/**
   Requests the xTU-R Vendor ID. (Section 7.4.2 of G997.1 [11])
*/
struct CMD_VendorID_R_Get
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
   Provides the xTU-R Vendor ID as requested by CMD_VendorID_R_Get.
*/
struct ACK_VendorID_R_Get
{
#if MEI_DRV_OS_BYTE_ORDER == MEI_DRV_OS_BIG_ENDIAN
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** xTU-R G.994.1 Vendor ID */
   IFX_uint16_t vendorID[4];
#else
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** xTU-R G.994.1 Vendor ID */
   IFX_uint16_t vendorID[4];
#endif
} __PACKED__ ;


/**
   Requests the xTU-C System Vendor ID. (Section 7.4.3 of G997.1 [11])
*/
struct CMD_SysVendorID_O_Get
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
   Delivers the xTU-C System Vendor ID as requested by CMD_SysVendorID_O_Get.
*/
struct ACK_SysVendorID_O_Get
{
#if MEI_DRV_OS_BYTE_ORDER == MEI_DRV_OS_BIG_ENDIAN
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** xTU-C System Vendor ID */
   IFX_uint16_t sysVendorID[4];
#else
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** xTU-C System Vendor ID */
   IFX_uint16_t sysVendorID[4];
#endif
} __PACKED__ ;


/**
   Requests the xTU-R System Vendor ID. (Section 7.4.4 of G997.1 [11])
*/
struct CMD_SysVendorID_R_Get
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
   Delivers the xTU-R System Vendor ID as requested by CMD_SysVendorID_R_Get.
*/
struct ACK_SysVendorID_R_Get
{
#if MEI_DRV_OS_BYTE_ORDER == MEI_DRV_OS_BIG_ENDIAN
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** xTU-R System Vendor ID */
   IFX_uint16_t sysVendorID[4];
#else
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** xTU-R System Vendor ID */
   IFX_uint16_t sysVendorID[4];
#endif
} __PACKED__ ;


/**
   Requests the xTU-C system vendor version number. (Section 7.4.5 of G997.1 [11])
*/
struct CMD_SysVendorVersionNumO_Get
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
   Delivers the xTU-C system vendor version number as requested by
   CMD_SysVendorVersionNumO_Get.
*/
struct ACK_SysVendorVersionNum_O_Get
{
#if MEI_DRV_OS_BYTE_ORDER == MEI_DRV_OS_BIG_ENDIAN
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** xTU-C System Vendor Version Number */
   IFX_uint16_t versionNum[8];
#else
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** xTU-C System Vendor Version Number */
   IFX_uint16_t versionNum[8];
#endif
} __PACKED__ ;


/**
   Requests the xTU-R system vendor version number. (Section 7.4.6 of G997.1 [11])
*/
struct CMD_SysVendorVersionNum_R_Get
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
   Delivers the xTU-R system vendor version number as requested by
   CMD_SysVendorVersionNum_R_Get.
*/
struct ACK_SysVendorVersionNum_R_Get
{
#if MEI_DRV_OS_BYTE_ORDER == MEI_DRV_OS_BIG_ENDIAN
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** xTU-R System Vendor Version Number */
   IFX_uint16_t versionNum[8];
#else
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** xTU-R System Vendor Version Number */
   IFX_uint16_t versionNum[8];
#endif
} __PACKED__ ;


/**
   Requests the xTU-C system vendor serial number. (Section 7.4.7 of G997.1 [11])
*/
struct CMD_SysVendorSerialNum_O_Get
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
   Delivers the xTU-C system vendor serial number as requested by
   CMD_SysVendorSerialNum_O_Get.
*/
struct ACK_SysVendorSerialNum_O_Get
{
#if MEI_DRV_OS_BYTE_ORDER == MEI_DRV_OS_BIG_ENDIAN
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** xTU-C System Vendor Serial Number */
   IFX_uint16_t serialNum[16];
#else
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** xTU-C System Vendor Serial Number */
   IFX_uint16_t serialNum[16];
#endif
} __PACKED__ ;


/**
   Requests the xTU-R system vendor serial number. (Section 7.4.8 of G997.1 [11])
*/
struct CMD_SysVendorSerialNum_R_Get
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
   Delivers the xTU-R system vendor version number as requested by
   CMD_SysVendorSerialNum_R_Get.
*/
struct ACK_SysVendorSerialNum_R_Get
{
#if MEI_DRV_OS_BYTE_ORDER == MEI_DRV_OS_BIG_ENDIAN
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** xTU-R System Vendor Serial Number */
   IFX_uint16_t serialNum[16];
#else
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** xTU-R System Vendor Serial Number */
   IFX_uint16_t serialNum[16];
#endif
} __PACKED__ ;


/**
   Requests VTU-O auxiliary inventory information (¤11.2.3.2.4 of G993.2 [5]).
*/
struct CMD_AuxInventoryInfo_O_Get
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
   Delivers the VTU-O auxiliary inventory information as requested by
   CMD_AuxInventoryInfo_O_Get.
*/
struct ACK_AuxInventoryInfo_O_Get
{
#if MEI_DRV_OS_BYTE_ORDER == MEI_DRV_OS_BIG_ENDIAN
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** VTU-O Auxiliary Inventory Information */
   IFX_uint16_t auxInfo[32];
#else
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** VTU-O Auxiliary Inventory Information */
   IFX_uint16_t auxInfo[32];
#endif
} __PACKED__ ;


/**
   Requests VTU-R auxiliary inventory information (¤11.2.3.2.4 of G993.2 [5]).
*/
struct CMD_AuxInventoryInfo_R_Get
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
   Delivers the VTU-R auxiliary inventory information as requested by
   CMD_AuxInventoryInfo_R_Get.
*/
struct ACK_AuxInventoryInfo_R_Get
{
#if MEI_DRV_OS_BYTE_ORDER == MEI_DRV_OS_BIG_ENDIAN
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** VTU-O Auxiliary Inventory Information */
   IFX_uint16_t auxInfo[32];
#else
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** VTU-O Auxiliary Inventory Information */
   IFX_uint16_t auxInfo[32];
#endif
} __PACKED__ ;


/**
   Requests the transmission system in use on the line (DSL flavour).
   (Section 7.5.1.1. of G.997.1 [11])
*/
struct CMD_XTSE_StatusGet
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
   Reports the transmission system mode in use as requested by CMD_XTSE_StatusGet.
*/
struct ACK_XTSE_StatusGet
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
   IFX_uint16_t Res18 : 13;
   /** VDSL Mode-Bit2: VDSL2 */
   IFX_uint16_t V2 : 1;
   /** Reserved */
   IFX_uint16_t Res20 : 1;
   /** VDSL Mode-Bit0: VDSL1 */
   IFX_uint16_t V0 : 1;
   /** Reserved */
   IFX_uint16_t Res22 : 14;
   /** Line Power Management State */
   IFX_uint16_t LxState : 2;
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
   IFX_uint16_t Res20 : 1;
   /** VDSL Mode-Bit2: VDSL2 */
   IFX_uint16_t V2 : 1;
   /** Reserved */
   IFX_uint16_t Res18 : 13;
   /** Line Power Management State */
   IFX_uint16_t LxState : 2;
   /** Reserved */
   IFX_uint16_t Res22 : 14;
#endif
} __PACKED__ ;


/**
   Reads the used downstream band configuration.
   Note: The reported used DS band configuration reflects the MEDLEYds set as
   defined in the O-PRM message of the channel discovery phase according to
   G.993.2.
*/
struct CMD_BandControl_DS_Get
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
   Acknowledgement for message CMD_BandControl_DS_Get.
*/
struct ACK_BandControl_DS_Get
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
   Reads the used upstream band configuration.
   Note: The reported used US band configuration reflects the MEDLEYus set as
   defined in the R-PRM message of the channel discovery phase in G.993.2.
*/
struct CMD_BandControl_US_Get
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
   Acknowledgement for message CMD_BandControl_US_Get.
*/
struct ACK_BandControl_US_Get
{
#if MEI_DRV_OS_BYTE_ORDER == MEI_DRV_OS_BIG_ENDIAN
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Reserved */
   IFX_uint8_t Res02;
   /** Number of Upstream Bands */
   IFX_uint8_t NumBandsDS;
   /** Band Descriptor US */
   VNX_ToneIndex_t band[8];
#else
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Number of Upstream Bands */
   IFX_uint8_t NumBandsDS;
   /** Reserved */
   IFX_uint8_t Res02;
   /** Band Descriptor US */
   VNX_ToneIndex_t band[8];
#endif
} __PACKED__ ;


/**
   Reads the RFI band configuration.
*/
struct CMD_RFI_BandControlGet
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
   Acknowledgement for message CMD_RFI_BandControlGet.
*/
struct ACK_RFI_BandControlGet
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
   This message requests data about the line status (like noise margin) for downstream
   direction.
*/
struct CMD_LineStatusDS_Get
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
   The message delivers the line status data for downstream direction requested by
   CMD_LineStatusDS_Get.
*/
struct ACK_LineStatusDS_Get
{
#if MEI_DRV_OS_BYTE_ORDER == MEI_DRV_OS_BIG_ENDIAN
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Reserved */
   IFX_uint16_t Res02;
   /** Downstream LATN */
   IFX_uint16_t LATNds;
   /** Downstream SATN */
   IFX_uint16_t SATNds;
   /** Downstream SNRM */
   IFX_uint16_t SNRMds;
   /** Downstream ATTNDR, LSW */
   IFX_uint16_t ATTNDRds_LSW;
   /** Downstream ATTNDR, MSW */
   IFX_uint16_t ATTNDRds_MSW;
   /** Downstream ACTATP */
   IFX_int16_t ACTATPds;
   /** Downstream ACTPSD (ADSL only) */
   IFX_uint16_t ACTPSDds;
   /** Reserved */
   IFX_uint16_t Res10 : 7;
   /** Virtual Noise Status DS */
   IFX_uint16_t VNstatus_ds : 1;
   /** Reserved */
   IFX_uint16_t Res12 : 7;
   /** TCM Status DS */
   IFX_uint16_t TCMstatus_ds : 1;
   /** Reserved */
   IFX_uint16_t Res14;
   /** Line Rate DS, LSW */
   IFX_uint16_t lineRateDS_LSW;
   /** Line Rate DS, MSW */
   IFX_uint16_t lineRateDS_MSW;
#else
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Reserved */
   IFX_uint16_t Res02;
   /** Downstream LATN */
   IFX_uint16_t LATNds;
   /** Downstream SATN */
   IFX_uint16_t SATNds;
   /** Downstream SNRM */
   IFX_uint16_t SNRMds;
   /** Downstream ATTNDR, LSW */
   IFX_uint16_t ATTNDRds_LSW;
   /** Downstream ATTNDR, MSW */
   IFX_uint16_t ATTNDRds_MSW;
   /** Downstream ACTATP */
   IFX_int16_t ACTATPds;
   /** Downstream ACTPSD (ADSL only) */
   IFX_uint16_t ACTPSDds;
   /** TCM Status DS */
   IFX_uint16_t TCMstatus_ds : 1;
   /** Reserved */
   IFX_uint16_t Res12 : 7;
   /** Virtual Noise Status DS */
   IFX_uint16_t VNstatus_ds : 1;
   /** Reserved */
   IFX_uint16_t Res10 : 7;
   /** Reserved */
   IFX_uint16_t Res14;
   /** Line Rate DS, LSW */
   IFX_uint16_t lineRateDS_LSW;
   /** Line Rate DS, MSW */
   IFX_uint16_t lineRateDS_MSW;
#endif
} __PACKED__ ;


/**
   This message requests data about the upstream line status (like noise margin).
*/
struct CMD_LineStatusUS_Get
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
   The message delivers the line status data for upstream direction requested by
   CMD_LineStatusUS_Get.
*/
struct ACK_LineStatusUS_Get
{
#if MEI_DRV_OS_BYTE_ORDER == MEI_DRV_OS_BIG_ENDIAN
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Reserved */
   IFX_uint16_t Res02;
   /** Upstream LATN */
   IFX_uint16_t LATNus;
   /** Upstream SATN */
   IFX_uint16_t SATNus;
   /** Upstream SNRM */
   IFX_uint16_t SNRMus;
   /** Upstream ATTNDR, LSW */
   IFX_uint16_t ATTNDRus_LSW;
   /** Upstream ATTNDR, MSW */
   IFX_uint16_t ATTNDRus_MSW;
   /** Upstream ACTATP */
   IFX_int16_t ACTATPus;
   /** Upstream ACTPSD (ADSL only) */
   IFX_uint16_t ACTPSDus;
   /** Reserved */
   IFX_uint16_t Res10 : 7;
   /** Virtual Noise Status US */
   IFX_uint16_t VNstatus_us : 1;
   /** Reserved */
   IFX_uint16_t Res12 : 7;
   /** TCM Status US */
   IFX_uint16_t TCMstatus_us : 1;
   /** Reserved */
   IFX_uint16_t Res14;
   /** Line Rate US, LSW */
   IFX_uint16_t lineRateUS_LSW;
   /** Line Rate US, MSW */
   IFX_uint16_t lineRateUS_MSW;
#else
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Reserved */
   IFX_uint16_t Res02;
   /** Upstream LATN */
   IFX_uint16_t LATNus;
   /** Upstream SATN */
   IFX_uint16_t SATNus;
   /** Upstream SNRM */
   IFX_uint16_t SNRMus;
   /** Upstream ATTNDR, LSW */
   IFX_uint16_t ATTNDRus_LSW;
   /** Upstream ATTNDR, MSW */
   IFX_uint16_t ATTNDRus_MSW;
   /** Upstream ACTATP */
   IFX_int16_t ACTATPus;
   /** Upstream ACTPSD (ADSL only) */
   IFX_uint16_t ACTPSDus;
   /** TCM Status US */
   IFX_uint16_t TCMstatus_us : 1;
   /** Reserved */
   IFX_uint16_t Res12 : 7;
   /** Virtual Noise Status US */
   IFX_uint16_t VNstatus_us : 1;
   /** Reserved */
   IFX_uint16_t Res10 : 7;
   /** Reserved */
   IFX_uint16_t Res14;
   /** Line Rate US, LSW */
   IFX_uint16_t lineRateUS_LSW;
   /** Line Rate US, MSW */
   IFX_uint16_t lineRateUS_MSW;
#endif
} __PACKED__ ;


/**
   This message requests data about the line status (noise margin, line attenuation and
   signal attenuation) for downstream direction in a "per band" granularity.
*/
struct CMD_LineStatusPerBandDS_Get
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
   The message delivers the line status data (line attenuation, signal attenuation and
   noise margin) for downstream direction in a "per band" granularity as requested by
   CMD_LineStatusPerBandDS_Get.
*/
struct ACK_LineStatusPerBandDS_Get
{
#if MEI_DRV_OS_BYTE_ORDER == MEI_DRV_OS_BIG_ENDIAN
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Reserved */
   IFX_uint16_t Res02;
   /** Line Status Descriptor DS */
   VNX_LineStatus_pb_t LineStatus_pb_ds[8];
#else
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Reserved */
   IFX_uint16_t Res02;
   /** Line Status Descriptor DS */
   VNX_LineStatus_pb_t LineStatus_pb_ds[8];
#endif
} __PACKED__ ;


/**
   This message requests data about the line status (noise margin, line - and signal
   attenuation) for upstream direction in a "per band" granularity.
*/
struct CMD_LineStatusPerBandUS_Get
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
   The message delivers the line status data (line attenuation, signal attenuation and
   noise margin) for upstream direction in a "per band" granularity as requested by
   CMD_LineStatusPerBandUS_Get.
*/
struct ACK_LineStatusPerBandUS_Get
{
#if MEI_DRV_OS_BYTE_ORDER == MEI_DRV_OS_BIG_ENDIAN
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Reserved */
   IFX_uint16_t Res02;
   /** Line Status Descriptor US */
   VNX_LineStatus_pb_t LineStatus_pb_us[8];
#else
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Reserved */
   IFX_uint16_t Res02;
   /** Line Status Descriptor US */
   VNX_LineStatus_pb_t LineStatus_pb_us[8];
#endif
} __PACKED__ ;


/**
   Requests the breakpoints of the actual PSD for the downstream direction. PSDs
   consisting of more than 42 PSD breakpoints must be read with 2 messages due to the
   the mailbox size. (The first parameter in the retrieved data structure contains the
   "Number of Breakpoints" parameter.)
*/
struct CMD_PSD_BreakpointsDS_Get
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
   Delivers the breakpoints of the actual PSD for the downstream direction as requested
   by CMD_PSD_BreakpointsDS_Get.
*/
struct ACK_PSD_BreakpointsDS_Get
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
   /** Breakpoint Descriptor DS PSD */
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
   /** Breakpoint Descriptor DS PSD */
   VNX_PSDbreak_t breakpoint[32];
#endif
} __PACKED__ ;


/**
   Requests the breakpoints of the actual PSD for the upstream direction.
*/
struct CMD_PSD_BreakpointsUS_Get
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
   Delivers the breakpoints of the actual PSD for the upstream direction as requested
   by CMD_PSD_BreakpointsUS_Get.
*/
struct ACK_PSD_BreakpointsUS_Get
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
   /** Breakpoint Descriptor US PSD */
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
   /** Breakpoint Descriptor US PSD */
   VNX_PSDbreak_t breakpoint[32];
#endif
} __PACKED__ ;


/**
   Configures the virtual noise PSD for downstream direction via breakpoints obtained
   from G.997.1. The CPE receiver uses this to adjust the SNR computation for the
   expected noise levels.
*/
struct CMD_VN_BreakpointsDS_Set
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
   /** Breakpoint Descriptor TxREFVNds */
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
   /** Breakpoint Descriptor TxREFVNds */
   VNX_PSDbreak_t breakpoint[32];
#endif
} __PACKED__ ;


/**
   Acknowledgment for the DS configuration message of the virutal noise PSD
   CMD_VN_BreakpointsDS_Set.
*/
struct ACK_VN_BreakpointsDS_Set
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
   Configures the virtual noise PSD in upstream direction via breakpoints. This
   information is used by the CO receiver for adjusting the SNR computation during
   training.
*/
struct CMD_VN_BreakpointsUS_Set
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
   /** Breakpoint Descriptor TxREFVNus */
   VNX_PSDbreak_t breakpoint[16];
#else
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Number of Breakpoints */
   IFX_uint8_t NumBreakPts;
   /** Reserved */
   IFX_uint8_t Res02;
   /** Breakpoint Descriptor TxREFVNus */
   VNX_PSDbreak_t breakpoint[16];
#endif
} __PACKED__ ;


/**
   Acknowledgment for the configuration message of the virtual noise PSD set in US
   CMD_VN_BreakpointsUS_Set.
*/
struct ACK_VN_BreakpointsUS_Set
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
   The Downstream TSSI Breakpoints are specified by the transmitter (VTU-O) and
   communicated to the receiver (VTU-R) via the O-PRM message.   The TSSI Breakpoints
   are used to shape the O-P-TEQ signal. This message provides read only access to the
   DS TSSI Breakpoints. The DS TSSI Breakpoints are not configurable via messages.
*/
struct CMD_TssiDS_VDSL2_Get
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
   This is the acknowledgement of CMD_TssiDS_VDSL2_Get.
*/
struct ACK_TssiDS_VDSL2_Get
{
#if MEI_DRV_OS_BYTE_ORDER == MEI_DRV_OS_BIG_ENDIAN
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Data from the DS TSSI breakpoint buffer */
   IFX_uint16_t Data[128];
#else
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Data from the DS TSSI breakpoint buffer */
   IFX_uint16_t Data[128];
#endif
} __PACKED__ ;


/**
   The Upstream TSSI Breakpoints are specified by the transmitter (VTU-R) and
   communicated to the receiver (VTU-O) via the R-PRM message.   The TSSI Breakpoints
   are used to shape the R-P-TEQ signal.
   Note: The TSSI Breakpoints can be read only but are not configurable via
   messages.
*/
struct CMD_TssiUS_VDSL2_Get
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
   This is the acknowledgement of CMD_TssiUS_VDSL2_Get.
*/
struct ACK_TssiUS_VDSL2_Get
{
#if MEI_DRV_OS_BYTE_ORDER == MEI_DRV_OS_BIG_ENDIAN
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Data from the US TSSI breakpoint buffer */
   IFX_uint16_t Data[128];
#else
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Data from the US TSSI breakpoint buffer */
   IFX_uint16_t Data[128];
#endif
} __PACKED__ ;


/**
   Reads the actual power cutback value.
*/
struct CMD_ADSL_PCB_Get
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
   Provides the actual power cutback values requested with CMD_ADSL_PCB_Get.
*/
struct ACK_ADSL_PCB_Get
{
#if MEI_DRV_OS_BYTE_ORDER == MEI_DRV_OS_BIG_ENDIAN
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Downstream Power Cutback */
   IFX_uint16_t dspcb;
   /** Upstream Power Cutback */
   IFX_uint16_t uspcb;
#else
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Downstream Power Cutback */
   IFX_uint16_t dspcb;
   /** Upstream Power Cutback */
   IFX_uint16_t uspcb;
#endif
} __PACKED__ ;


/**
   Requests the PSD and power parameter values actually used by the firmware. The
   values can be different from what was configured with CMD_PSD_Set, e.g. if
   out-of-range values were written the FW limits them to the valid range.
*/
struct CMD_ActualPSD_Get
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
   Provieds actually used PSD and power parameters as requested by CMD_ActualPSD_Get.
*/
struct ACK_ActualPSD_Get
{
#if MEI_DRV_OS_BYTE_ORDER == MEI_DRV_OS_BIG_ENDIAN
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Power/PSD Configuration Parameter: MAXNOMPSDds */
   IFX_uint16_t MAXNOMPSDds;
   /** Power/PSD Configuration Parameter: MAXNOMPSDus */
   IFX_uint16_t MAXNOMPSDus;
   /** Power/PSD Configuration Parameter: MAXNOMATPds */
   IFX_uint16_t MAXNOMATPds;
   /** Power/PSD Configuration Parameters */
   IFX_uint16_t MAXNOMATPus;
   /** Reserved */
   IFX_uint16_t Res06;
#else
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Power/PSD Configuration Parameter: MAXNOMPSDds */
   IFX_uint16_t MAXNOMPSDds;
   /** Power/PSD Configuration Parameter: MAXNOMPSDus */
   IFX_uint16_t MAXNOMPSDus;
   /** Power/PSD Configuration Parameter: MAXNOMATPds */
   IFX_uint16_t MAXNOMATPds;
   /** Power/PSD Configuration Parameters */
   IFX_uint16_t MAXNOMATPus;
   /** Reserved */
   IFX_uint16_t Res06;
#endif
} __PACKED__ ;


/**
   Requests status information for the downstream bearer channels.
*/
struct CMD_BearerChsDS_Get
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
   Delivers status information for the downstream bearer channels.
   Attention: In VINAX V1.x the "LP1/Fast Path" parameters are populated only in
   ADSL1 mode with selected fast path.
*/
struct ACK_BearerChsDS_Get
{
#if MEI_DRV_OS_BYTE_ORDER == MEI_DRV_OS_BIG_ENDIAN
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Net Data Rate DS for LP0, LSW */
   IFX_uint16_t DRdsLP0_LSW;
   /** Net Data Rate DS for LP0, MSW */
   IFX_uint16_t DRdsLP0_MSW;
   /** Data Rate DS for LP1, LSW */
   IFX_uint16_t DRdsLP1_LSW;
   /** Data Rate DS for LP1, MSW */
   IFX_uint16_t DRdsLP1_MSW;
   /** Reserved */
   IFX_uint16_t Res06[4];
   /** Actual Interleaving Delay DS, LP0 */
   IFX_uint16_t delay_dsLP0;
   /** Actual Interleaving Delay DS, LP1 */
   IFX_uint16_t delay_dsLP1;
   /** Actual Interleaver Depth DS, LP0 */
   IFX_uint16_t intlDepth_dsLP0;
   /** Actual Interleaver Depth DS, LP1 */
   IFX_uint16_t intlDepth_dsLP1;
   /** Reserved */
   IFX_uint16_t Res11 : 7;
   /** TCM Status DS, LP0 */
   IFX_uint16_t TCMstatus_dsLP0 : 1;
   /** Parity Bytes DS, LP0 */
   IFX_uint16_t parity_dsLP0 : 8;
   /** Reserved */
   IFX_uint8_t Res14;
   /** Parity Bytes DS, LP1 */
   IFX_uint16_t parity_dsLP1 : 8;
   /** Actual INP NoErasure DS , LP0 */
   IFX_uint16_t actInpNoErasure_LP0;
   /** Actual INP NoErasure DS, LP1 */
   IFX_uint16_t actInpNoErasure_LP1;
   /** Rx Estimated Actual INP DS, LP0 */
   IFX_uint16_t actInpErasure_LP0;
   /** Rx Estimated Actual INP DS, LP1 */
   IFX_uint16_t actInpErasure_LP1;
#else
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Net Data Rate DS for LP0, LSW */
   IFX_uint16_t DRdsLP0_LSW;
   /** Net Data Rate DS for LP0, MSW */
   IFX_uint16_t DRdsLP0_MSW;
   /** Data Rate DS for LP1, LSW */
   IFX_uint16_t DRdsLP1_LSW;
   /** Data Rate DS for LP1, MSW */
   IFX_uint16_t DRdsLP1_MSW;
   /** Reserved */
   IFX_uint16_t Res06[4];
   /** Actual Interleaving Delay DS, LP0 */
   IFX_uint16_t delay_dsLP0;
   /** Actual Interleaving Delay DS, LP1 */
   IFX_uint16_t delay_dsLP1;
   /** Actual Interleaver Depth DS, LP0 */
   IFX_uint16_t intlDepth_dsLP0;
   /** Actual Interleaver Depth DS, LP1 */
   IFX_uint16_t intlDepth_dsLP1;
   /** Parity Bytes DS, LP0 */
   IFX_uint16_t parity_dsLP0 : 8;
   /** TCM Status DS, LP0 */
   IFX_uint16_t TCMstatus_dsLP0 : 1;
   /** Reserved */
   IFX_uint16_t Res11 : 7;
   /** Parity Bytes DS, LP1 */
   IFX_uint16_t parity_dsLP1 : 8;
   /** Reserved */
   IFX_uint8_t Res14;
   /** Actual INP NoErasure DS , LP0 */
   IFX_uint16_t actInpNoErasure_LP0;
   /** Actual INP NoErasure DS, LP1 */
   IFX_uint16_t actInpNoErasure_LP1;
   /** Rx Estimated Actual INP DS, LP0 */
   IFX_uint16_t actInpErasure_LP0;
   /** Rx Estimated Actual INP DS, LP1 */
   IFX_uint16_t actInpErasure_LP1;
#endif
} __PACKED__ ;


/**
   Requests status information for the upstream bearer channels.
*/
struct CMD_BearerChsUS_Get
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
   Delivers status information for the upstream bearer channels.
   Attention: In VINAX V1.x the "LP1/Fast Path" parameters are populated only in
   ADSL1 mode with selected fast path.
*/
struct ACK_BearerChsUS_Get
{
#if MEI_DRV_OS_BYTE_ORDER == MEI_DRV_OS_BIG_ENDIAN
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Net Data Rate US for LP0, LSW */
   IFX_uint16_t DRusLP0_LSW;
   /** Net Data Rate US for LP0, MSW */
   IFX_uint16_t DRusLP0_MSW;
   /** Data Rate US for LP1, LSW */
   IFX_uint16_t DRusLP1_LSW;
   /** Data Rate US for LP1, MSW */
   IFX_uint16_t DRusLP1_MSW;
   /** Reserved */
   IFX_uint16_t Res06[4];
   /** Actual Interleaving Delay US, LP0 */
   IFX_uint16_t delay_usLP0;
   /** Actual Interleaving Delay US, LP1 */
   IFX_uint16_t delay_usLP1;
   /** Actual Interleaver Depth US, LP0 */
   IFX_uint16_t intlDepth_usLP0;
   /** Actual Interleaver Depth US, LP1 */
   IFX_uint16_t intlDepth_usLP1;
   /** Reserved */
   IFX_uint16_t Res11 : 7;
   /** TCM Status US, LP0 */
   IFX_uint16_t TCMstatus_usLP0 : 1;
   /** Parity Bytes US, LP0 */
   IFX_uint16_t parity_usLP0 : 8;
   /** Reserved */
   IFX_uint8_t Res14;
   /** Parity Bytes US, LP1 */
   IFX_uint16_t parity_usLP1 : 8;
   /** Actual INP NoErasure US , LP0 */
   IFX_uint16_t actInpNoErasure_LP0;
   /** Actual INP NoErasure US, LP1 */
   IFX_uint16_t actInpNoErasure_LP1;
   /** Rx Estimated Actual INP US , LP0 */
   IFX_uint16_t actInpErasure_LP0;
   /** Rx Estimated Actual INP US, LP1 */
   IFX_uint16_t actInpErasure_LP1;
#else
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Net Data Rate US for LP0, LSW */
   IFX_uint16_t DRusLP0_LSW;
   /** Net Data Rate US for LP0, MSW */
   IFX_uint16_t DRusLP0_MSW;
   /** Data Rate US for LP1, LSW */
   IFX_uint16_t DRusLP1_LSW;
   /** Data Rate US for LP1, MSW */
   IFX_uint16_t DRusLP1_MSW;
   /** Reserved */
   IFX_uint16_t Res06[4];
   /** Actual Interleaving Delay US, LP0 */
   IFX_uint16_t delay_usLP0;
   /** Actual Interleaving Delay US, LP1 */
   IFX_uint16_t delay_usLP1;
   /** Actual Interleaver Depth US, LP0 */
   IFX_uint16_t intlDepth_usLP0;
   /** Actual Interleaver Depth US, LP1 */
   IFX_uint16_t intlDepth_usLP1;
   /** Parity Bytes US, LP0 */
   IFX_uint16_t parity_usLP0 : 8;
   /** TCM Status US, LP0 */
   IFX_uint16_t TCMstatus_usLP0 : 1;
   /** Reserved */
   IFX_uint16_t Res11 : 7;
   /** Parity Bytes US, LP1 */
   IFX_uint16_t parity_usLP1 : 8;
   /** Reserved */
   IFX_uint8_t Res14;
   /** Actual INP NoErasure US , LP0 */
   IFX_uint16_t actInpNoErasure_LP0;
   /** Actual INP NoErasure US, LP1 */
   IFX_uint16_t actInpNoErasure_LP1;
   /** Rx Estimated Actual INP US , LP0 */
   IFX_uint16_t actInpErasure_LP0;
   /** Rx Estimated Actual INP US, LP1 */
   IFX_uint16_t actInpErasure_LP1;
#endif
} __PACKED__ ;


/**
   Requests basic VDSL1 frame setting data for the downstream direction.
*/
struct CMD_FrameData1DS_Get
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
   Delivers basic VDSL1 framing parameters for the downstream direction requested by
   CMD_FrameData1DS_Get.These parameters are covered in sections 8.5 & 8.4 of G.993.1
   [4].
*/
struct ACK_FrameData1DS_Get
{
#if MEI_DRV_OS_BYTE_ORDER == MEI_DRV_OS_BIG_ENDIAN
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Data Rate DS LP0 */
   IFX_uint16_t rateLP0ds;
   /** Reserved */
   IFX_uint16_t Res03;
   /** RS-Codeword Size "N" LP0 DS */
   IFX_uint16_t cwSizeLP0ds;
   /** Reserved */
   IFX_uint16_t Res05;
   /** RS Check Bytes "R" LP0 DS */
   IFX_uint16_t RS_ParBytesLP0ds;
   /** Reserved */
   IFX_uint16_t Res07;
   /** Interleaver Block Length "I", LP0 DS */
   IFX_uint16_t IntlBlockLenLP0ds;
   /** Reserved */
   IFX_uint16_t Res09;
   /** Interleaving Depth Parameter "M" LP0 DS */
   IFX_uint16_t IntlDepthLP0ds;
   /** Reserved */
   IFX_uint16_t Res11;
#else
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Data Rate DS LP0 */
   IFX_uint16_t rateLP0ds;
   /** Reserved */
   IFX_uint16_t Res03;
   /** RS-Codeword Size "N" LP0 DS */
   IFX_uint16_t cwSizeLP0ds;
   /** Reserved */
   IFX_uint16_t Res05;
   /** RS Check Bytes "R" LP0 DS */
   IFX_uint16_t RS_ParBytesLP0ds;
   /** Reserved */
   IFX_uint16_t Res07;
   /** Interleaver Block Length "I", LP0 DS */
   IFX_uint16_t IntlBlockLenLP0ds;
   /** Reserved */
   IFX_uint16_t Res09;
   /** Interleaving Depth Parameter "M" LP0 DS */
   IFX_uint16_t IntlDepthLP0ds;
   /** Reserved */
   IFX_uint16_t Res11;
#endif
} __PACKED__ ;


/**
   Requests basic VDSL1 frame setting data for the upstream direction.
*/
struct CMD_FrameData1US_Get
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
   Delivers basic VDSL1 frame setting data for the upstream direction requested by
   CMD_FrameData1US_Get. These parameters are covered in sections 8.5 & 8.4 of G.993.1
   [4].
*/
struct ACK_FrameData1US_Get
{
#if MEI_DRV_OS_BYTE_ORDER == MEI_DRV_OS_BIG_ENDIAN
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Data Rate LP0 US */
   IFX_uint16_t rateLP0us;
   /** Reserved */
   IFX_uint16_t Res03;
   /** RS-Codeword Size "N" LP0 US */
   IFX_uint16_t cwSizeLP0us;
   /** Reserved */
   IFX_uint16_t Res05;
   /** RS Check Bytes "R" LP0 US */
   IFX_uint16_t RS_ParBytesLP0us;
   /** Reserved */
   IFX_uint16_t Res07;
   /** Interleaver Block Length "I", LP0 US */
   IFX_uint16_t IntlBlockLenLP0us;
   /** Reserved */
   IFX_uint16_t Res09;
   /** Interleaving Depth Parameter "M" LP0 US */
   IFX_uint16_t IntlDepthLP0us;
   /** Reserved */
   IFX_uint16_t Res11;
#else
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Data Rate LP0 US */
   IFX_uint16_t rateLP0us;
   /** Reserved */
   IFX_uint16_t Res03;
   /** RS-Codeword Size "N" LP0 US */
   IFX_uint16_t cwSizeLP0us;
   /** Reserved */
   IFX_uint16_t Res05;
   /** RS Check Bytes "R" LP0 US */
   IFX_uint16_t RS_ParBytesLP0us;
   /** Reserved */
   IFX_uint16_t Res07;
   /** Interleaver Block Length "I", LP0 US */
   IFX_uint16_t IntlBlockLenLP0us;
   /** Reserved */
   IFX_uint16_t Res09;
   /** Interleaving Depth Parameter "M" LP0 US */
   IFX_uint16_t IntlDepthLP0us;
   /** Reserved */
   IFX_uint16_t Res11;
#endif
} __PACKED__ ;


/**
   Requests an extended set of VDSL1 framing parameters for the downstream direction.
*/
struct CMD_FrameDataExt1DS_Get
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
   Delivers an extended set of VDSL1 framing parameters for the downstream direction
   requested by CMD_FrameDataExt1DS_Get. (Sections 8.5 & 8.4 of G.993.1 [4])
*/
struct ACK_FrameDataExt1DS_Get
{
#if MEI_DRV_OS_BYTE_ORDER == MEI_DRV_OS_BIG_ENDIAN
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Reserved */
   IFX_uint16_t Res02[2];
   /** Data Bytes per Frame "U" LP0 DS */
   IFX_uint16_t U_LP0ds;
   /** Reserved */
   IFX_uint16_t Res04;
   /** Dummy Bytes "Dz" LP0 DS */
   IFX_uint16_t Dz_LP0ds;
   /** Reserved */
   IFX_uint16_t Res06;
   /** OH Bytes "E" LP0 DS */
   IFX_uint16_t E_LP0ds;
   /** Reserved */
   IFX_uint16_t Res08;
   /** RS Dummy Bytes LP0 DS */
   IFX_uint16_t Drs_LP0ds;
   /** Reserved */
   IFX_uint16_t Res10;
   /** RS Info Bytes "K" LP0 DS */
   IFX_uint16_t K_LP0ds;
   /** Reserved */
   IFX_uint16_t Res12;
   /** RS Check Bytes "R" LP0 DS */
   IFX_uint16_t R_LP0ds;
   /** Reserved */
   IFX_uint16_t Res14;
   /** RS Codeword Size "N" LP0 DS */
   IFX_uint16_t N_LP0ds;
   /** Reserved */
   IFX_uint16_t Res16;
   /** Bytes per Symbol "P" LP0 DS */
   IFX_uint16_t P_LP0ds;
   /** Reserved */
   IFX_uint16_t Res18;
   /** Interleaving Depth Parameter "M" LP0 DS */
   IFX_uint16_t M_LP0ds;
   /** Reserved */
   IFX_uint16_t Res20;
   /** Interleaver Block Length "I", LP0 DS */
   IFX_uint16_t I_LP0ds;
   /** Reserved */
   IFX_uint16_t Res22;
   /** Framing Parameter "q", LP0 DS */
   IFX_uint16_t q_LP0ds;
   /** Reserved */
   IFX_uint16_t Res24;
   /** Interleaving Depth "D" LP0 DS */
   IFX_uint16_t D_LP0ds;
   /** Reserved */
   IFX_uint16_t Res26;
#else
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Reserved */
   IFX_uint16_t Res02[2];
   /** Data Bytes per Frame "U" LP0 DS */
   IFX_uint16_t U_LP0ds;
   /** Reserved */
   IFX_uint16_t Res04;
   /** Dummy Bytes "Dz" LP0 DS */
   IFX_uint16_t Dz_LP0ds;
   /** Reserved */
   IFX_uint16_t Res06;
   /** OH Bytes "E" LP0 DS */
   IFX_uint16_t E_LP0ds;
   /** Reserved */
   IFX_uint16_t Res08;
   /** RS Dummy Bytes LP0 DS */
   IFX_uint16_t Drs_LP0ds;
   /** Reserved */
   IFX_uint16_t Res10;
   /** RS Info Bytes "K" LP0 DS */
   IFX_uint16_t K_LP0ds;
   /** Reserved */
   IFX_uint16_t Res12;
   /** RS Check Bytes "R" LP0 DS */
   IFX_uint16_t R_LP0ds;
   /** Reserved */
   IFX_uint16_t Res14;
   /** RS Codeword Size "N" LP0 DS */
   IFX_uint16_t N_LP0ds;
   /** Reserved */
   IFX_uint16_t Res16;
   /** Bytes per Symbol "P" LP0 DS */
   IFX_uint16_t P_LP0ds;
   /** Reserved */
   IFX_uint16_t Res18;
   /** Interleaving Depth Parameter "M" LP0 DS */
   IFX_uint16_t M_LP0ds;
   /** Reserved */
   IFX_uint16_t Res20;
   /** Interleaver Block Length "I", LP0 DS */
   IFX_uint16_t I_LP0ds;
   /** Reserved */
   IFX_uint16_t Res22;
   /** Framing Parameter "q", LP0 DS */
   IFX_uint16_t q_LP0ds;
   /** Reserved */
   IFX_uint16_t Res24;
   /** Interleaving Depth "D" LP0 DS */
   IFX_uint16_t D_LP0ds;
   /** Reserved */
   IFX_uint16_t Res26;
#endif
} __PACKED__ ;


/**
   Requests an extended set of VDSL1 framing parameters for the upstream direction.
*/
struct CMD_FrameDataExt1US_Get
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
   Delivers an extended set of VDSL1 framing parameters for the upstream direction
   requested by CMD_FrameDataExt1US_Get. (Sections 8.5 & 8.4 of G.993.1 [4])
*/
struct ACK_FrameDataExt1US_Get
{
#if MEI_DRV_OS_BYTE_ORDER == MEI_DRV_OS_BIG_ENDIAN
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Reserved */
   IFX_uint16_t Res02[2];
   /** Data Bytes per Frame "U" LP0 US */
   IFX_uint16_t U_LP0us;
   /** Reserved */
   IFX_uint16_t Res04;
   /** Dummy Bytes "Dz" LP0 US */
   IFX_uint16_t Dz_LP0us;
   /** Reserved */
   IFX_uint16_t Res06;
   /** OH Bytes LP0 "E" US */
   IFX_uint16_t E_LP0us;
   /** Reserved */
   IFX_uint16_t Res08;
   /** RS Dummy Bytes LP0 US */
   IFX_uint16_t Drs_LP0us;
   /** Reserved */
   IFX_uint16_t Res10;
   /** RS Info Bytes "K" LP0 US */
   IFX_uint16_t K_LP0us;
   /** Reserved */
   IFX_uint16_t Res12;
   /** RS Check Bytes "R" LP0 US */
   IFX_uint16_t R_LP0us;
   /** Reserved */
   IFX_uint16_t Res14;
   /** RS Codeword Size "N" LP0 US */
   IFX_uint16_t N_LP0us;
   /** Reserved */
   IFX_uint16_t Res16;
   /** Bytes per Symbol "P" LP0 US */
   IFX_uint16_t P_LP0us;
   /** Reserved */
   IFX_uint16_t Res18;
   /** Interleaving Depth Parameter "M" LP0 US */
   IFX_uint16_t M_LP0us;
   /** Reserved */
   IFX_uint16_t Res20;
   /** Interleaver Block Length "I", LP0 US */
   IFX_uint16_t I_LP0us;
   /** Reserved */
   IFX_uint16_t Res22;
   /** Framing Parameter "q", LP0 US */
   IFX_uint16_t q_LP0us;
   /** Reserved */
   IFX_uint16_t Res24;
   /** Interleaving Depth "D" LP0 US */
   IFX_uint16_t D_LP0us;
   /** Reserved */
   IFX_uint16_t Res26;
#else
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Reserved */
   IFX_uint16_t Res02[2];
   /** Data Bytes per Frame "U" LP0 US */
   IFX_uint16_t U_LP0us;
   /** Reserved */
   IFX_uint16_t Res04;
   /** Dummy Bytes "Dz" LP0 US */
   IFX_uint16_t Dz_LP0us;
   /** Reserved */
   IFX_uint16_t Res06;
   /** OH Bytes LP0 "E" US */
   IFX_uint16_t E_LP0us;
   /** Reserved */
   IFX_uint16_t Res08;
   /** RS Dummy Bytes LP0 US */
   IFX_uint16_t Drs_LP0us;
   /** Reserved */
   IFX_uint16_t Res10;
   /** RS Info Bytes "K" LP0 US */
   IFX_uint16_t K_LP0us;
   /** Reserved */
   IFX_uint16_t Res12;
   /** RS Check Bytes "R" LP0 US */
   IFX_uint16_t R_LP0us;
   /** Reserved */
   IFX_uint16_t Res14;
   /** RS Codeword Size "N" LP0 US */
   IFX_uint16_t N_LP0us;
   /** Reserved */
   IFX_uint16_t Res16;
   /** Bytes per Symbol "P" LP0 US */
   IFX_uint16_t P_LP0us;
   /** Reserved */
   IFX_uint16_t Res18;
   /** Interleaving Depth Parameter "M" LP0 US */
   IFX_uint16_t M_LP0us;
   /** Reserved */
   IFX_uint16_t Res20;
   /** Interleaver Block Length "I", LP0 US */
   IFX_uint16_t I_LP0us;
   /** Reserved */
   IFX_uint16_t Res22;
   /** Framing Parameter "q", LP0 US */
   IFX_uint16_t q_LP0us;
   /** Reserved */
   IFX_uint16_t Res24;
   /** Interleaving Depth "D" LP0 US */
   IFX_uint16_t D_LP0us;
   /** Reserved */
   IFX_uint16_t Res26;
#endif
} __PACKED__ ;


/**
   Requests an extended set of VDSL2 framing parameters for the downstream direction.
*/
struct CMD_FrameDataExt2DS_Get
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
   Delivers an extended set of VDSL2 framing parameters for the downstream direction
   requested by CMD_FrameDataExt2DS_Get. (Sections 7.5.2.6 of G.997.1 and 9.5 & 9.6 of
   G.993.2 [5])
*/
struct ACK_FrameDataExt2DS_Get
{
#if MEI_DRV_OS_BYTE_ORDER == MEI_DRV_OS_BIG_ENDIAN
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Bytes "Bp" from BC0 per MDF LP0 DS */
   IFX_uint16_t B0_LP0ds;
   /** Reserved */
   IFX_uint16_t Res03;
   /** Reserved */
   IFX_uint16_t Res04;
   /** Reserved */
   IFX_uint16_t Res05;
   /** MDFs per OH Sub-Frame "Tp" LP0 DS */
   IFX_uint16_t Tp_LP0ds;
   /** Reserved */
   IFX_uint16_t Res07;
   /** OH Bytes per OH sub-frame "Gp" LP0 DS */
   IFX_uint16_t Gp_LP0ds;
   /** Reserved */
   IFX_uint16_t Res09;
   /** OH Frames per OH Superframe "Fp" LP0 DS */
   IFX_uint16_t Fp_LP0ds;
   /** Reserved */
   IFX_uint16_t Res11;
   /** MDFs per RS-Codeword "Mp" LP0 DS */
   IFX_uint16_t Mp_LP0ds;
   /** Reserved */
   IFX_uint16_t Res13;
   /** Bits per Symbol "Lp" LP0 DS */
   IFX_uint16_t Lp_LP0ds;
   /** Reserved */
   IFX_uint16_t Res15;
   /** RS Check Bytes "Rp" LP0 DS */
   IFX_uint16_t Rp_LP0ds;
   /** Reserved */
   IFX_uint16_t Res17;
   /** Interleaver Block Length "Ip", LP0 DS */
   IFX_uint16_t Ip_LP0ds;
   /** Reserved */
   IFX_uint16_t Res19;
   /** Interleaving Depth "Dp" LP0 DS */
   IFX_uint16_t Dp_LP0ds;
   /** Reserved */
   IFX_uint16_t Res21;
   /** OH Frame Period "PERp", LP0 DS */
   IFX_uint16_t PERp_LP0ds;
   /** Reserved */
   IFX_uint16_t Res23;
   /** Line Data Rate DS for LP0, LSW */
   IFX_uint16_t DRp_LP0ds_LSW;
   /** Line Data Rate DS for LP0, MSW */
   IFX_uint16_t DRp_LP0ds_MSW;
   /** Reserved */
   IFX_uint16_t Res26;
   /** Reserved */
   IFX_uint16_t Res27;
   /** RS Codeword Size "N_fecp" LP0 DS */
   IFX_uint16_t N_fecp_LP0ds;
   /** Reserved */
   IFX_uint16_t Res29;
   /** Framing Parameter "q", LP0 DS */
   IFX_uint16_t q_LP0ds;
   /** Reserved */
   IFX_uint16_t Res31;
   /** OH Bytes per OH FrameLP0 "SEQp" DS */
   IFX_uint16_t SEQp_LP0ds;
   /** Reserved */
   IFX_uint16_t Res33;
   /** OH sub-frames "Up" per OH frame LP0 DS */
   IFX_uint16_t Up_LP0ds;
   /** Reserved */
   IFX_uint16_t Res35;
   /** Bytes per OH Frame LP0 DS, LSW */
   IFX_uint16_t PERBp_LP0ds_LSW;
   /** Bytes per OH Frame LP0 DS, MSW */
   IFX_uint16_t PERBp_LP0ds_MSW;
   /** Reserved */
   IFX_uint16_t Res38;
   /** Reserved */
   IFX_uint16_t Res39;
   /** Bytes in MSG OH "MSGc" LP0 DS */
   IFX_uint16_t MSGc_LP0ds;
   /** Reserved */
   IFX_uint16_t Res41;
#else
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Bytes "Bp" from BC0 per MDF LP0 DS */
   IFX_uint16_t B0_LP0ds;
   /** Reserved */
   IFX_uint16_t Res03;
   /** Reserved */
   IFX_uint16_t Res04;
   /** Reserved */
   IFX_uint16_t Res05;
   /** MDFs per OH Sub-Frame "Tp" LP0 DS */
   IFX_uint16_t Tp_LP0ds;
   /** Reserved */
   IFX_uint16_t Res07;
   /** OH Bytes per OH sub-frame "Gp" LP0 DS */
   IFX_uint16_t Gp_LP0ds;
   /** Reserved */
   IFX_uint16_t Res09;
   /** OH Frames per OH Superframe "Fp" LP0 DS */
   IFX_uint16_t Fp_LP0ds;
   /** Reserved */
   IFX_uint16_t Res11;
   /** MDFs per RS-Codeword "Mp" LP0 DS */
   IFX_uint16_t Mp_LP0ds;
   /** Reserved */
   IFX_uint16_t Res13;
   /** Bits per Symbol "Lp" LP0 DS */
   IFX_uint16_t Lp_LP0ds;
   /** Reserved */
   IFX_uint16_t Res15;
   /** RS Check Bytes "Rp" LP0 DS */
   IFX_uint16_t Rp_LP0ds;
   /** Reserved */
   IFX_uint16_t Res17;
   /** Interleaver Block Length "Ip", LP0 DS */
   IFX_uint16_t Ip_LP0ds;
   /** Reserved */
   IFX_uint16_t Res19;
   /** Interleaving Depth "Dp" LP0 DS */
   IFX_uint16_t Dp_LP0ds;
   /** Reserved */
   IFX_uint16_t Res21;
   /** OH Frame Period "PERp", LP0 DS */
   IFX_uint16_t PERp_LP0ds;
   /** Reserved */
   IFX_uint16_t Res23;
   /** Line Data Rate DS for LP0, LSW */
   IFX_uint16_t DRp_LP0ds_LSW;
   /** Line Data Rate DS for LP0, MSW */
   IFX_uint16_t DRp_LP0ds_MSW;
   /** Reserved */
   IFX_uint16_t Res26;
   /** Reserved */
   IFX_uint16_t Res27;
   /** RS Codeword Size "N_fecp" LP0 DS */
   IFX_uint16_t N_fecp_LP0ds;
   /** Reserved */
   IFX_uint16_t Res29;
   /** Framing Parameter "q", LP0 DS */
   IFX_uint16_t q_LP0ds;
   /** Reserved */
   IFX_uint16_t Res31;
   /** OH Bytes per OH FrameLP0 "SEQp" DS */
   IFX_uint16_t SEQp_LP0ds;
   /** Reserved */
   IFX_uint16_t Res33;
   /** OH sub-frames "Up" per OH frame LP0 DS */
   IFX_uint16_t Up_LP0ds;
   /** Reserved */
   IFX_uint16_t Res35;
   /** Bytes per OH Frame LP0 DS, LSW */
   IFX_uint16_t PERBp_LP0ds_LSW;
   /** Bytes per OH Frame LP0 DS, MSW */
   IFX_uint16_t PERBp_LP0ds_MSW;
   /** Reserved */
   IFX_uint16_t Res38;
   /** Reserved */
   IFX_uint16_t Res39;
   /** Bytes in MSG OH "MSGc" LP0 DS */
   IFX_uint16_t MSGc_LP0ds;
   /** Reserved */
   IFX_uint16_t Res41;
#endif
} __PACKED__ ;


/**
   Requests an extended set of VDSL2 framing parameters for the upstream direction.
*/
struct CMD_FrameDataExt2US_Get
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
   Delivers an extended set of VDSL2 framing parameters for the upstream direction
   requested by CMD_FrameDataExt2US_Get. (Sections 7.5.2.6 of G.997.1 and 9.5 & 9.6 of
   G.993.2 [5])
*/
struct ACK_FrameDataExt2US_Get
{
#if MEI_DRV_OS_BYTE_ORDER == MEI_DRV_OS_BIG_ENDIAN
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Bytes "Bp" from BC0 per MDF LP0 US */
   IFX_uint16_t B0_LP0us;
   /** Reserved */
   IFX_uint16_t Res03;
   /** Reserved */
   IFX_uint16_t Res04;
   /** Reserved */
   IFX_uint16_t Res05;
   /** MDFs per OH Sub-Frame "Tp" LP0 US */
   IFX_uint16_t Tp_LP0us;
   /** Reserved */
   IFX_uint16_t Res07;
   /** OH Bytes per OH sub-frame "Gp" LP0 US */
   IFX_uint16_t Gp_LP0us;
   /** Reserved */
   IFX_uint16_t Res09;
   /** OH Frames per OH Superframe "Fp" LP0 US */
   IFX_uint16_t Fp_LP0us;
   /** Reserved */
   IFX_uint16_t Res11;
   /** MDFs per RS-Codeword "Mp" LP0 US */
   IFX_uint16_t Mp_LP0us;
   /** Reserved */
   IFX_uint16_t Res13;
   /** Bits per Symbol "Lp" LP0 US */
   IFX_uint16_t Lp_LP0us;
   /** Reserved */
   IFX_uint16_t Res15;
   /** RS Check Bytes "Rp" LP0 US */
   IFX_uint16_t Rp_LP0us;
   /** Reserved */
   IFX_uint16_t Res17;
   /** Interleaver Block Length "Ip", LP0 US */
   IFX_uint16_t Ip_LP0us;
   /** Reserved */
   IFX_uint16_t Res19;
   /** Interleaving Depth "Dp" LP0 US */
   IFX_uint16_t Dp_LP0us;
   /** Reserved */
   IFX_uint16_t Res21;
   /** OH Frame Period "PERp", LP0 US */
   IFX_uint16_t PERp_LP0us;
   /** Reserved */
   IFX_uint16_t Res23;
   /** Line Data Rate US for LP0, LSW */
   IFX_uint16_t DRp_LP0us_LSW;
   /** Line Data Rate US for LP0, MSW */
   IFX_uint16_t DRp_LP0us_MSW;
   /** Reserved */
   IFX_uint16_t Res26;
   /** Reserved */
   IFX_uint16_t Res27;
   /** RS Codeword Size "N_fecp" LP0 US */
   IFX_uint16_t N_fecp_LP0us;
   /** Reserved */
   IFX_uint16_t Res29;
   /** Framing Parameter "q", LP0 US */
   IFX_uint16_t q_LP0us;
   /** Reserved */
   IFX_uint16_t Res31;
   /** OH Bytes per OH FrameLP0 "SEQp" US */
   IFX_uint16_t SEQp_LP0us;
   /** Reserved */
   IFX_uint16_t Res33;
   /** OH sub-frames "Up" per OH frame LP0 US */
   IFX_uint16_t Up_LP0us;
   /** Reserved */
   IFX_uint16_t Res35;
   /** Bytes per OH Frame LP0 US, LSW */
   IFX_uint16_t PERBp_LP0us_LSW;
   /** Bytes per OH Frame LP0 US, MSW */
   IFX_uint16_t PERBp_LP0us_MSW;
   /** Reserved */
   IFX_uint16_t Res38;
   /** Reserved */
   IFX_uint16_t Res39;
   /** Bytes in MSG OH "MSGc" LP0 US */
   IFX_uint16_t MSGc_LP0us;
   /** Reserved */
   IFX_uint16_t Res41;
#else
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Bytes "Bp" from BC0 per MDF LP0 US */
   IFX_uint16_t B0_LP0us;
   /** Reserved */
   IFX_uint16_t Res03;
   /** Reserved */
   IFX_uint16_t Res04;
   /** Reserved */
   IFX_uint16_t Res05;
   /** MDFs per OH Sub-Frame "Tp" LP0 US */
   IFX_uint16_t Tp_LP0us;
   /** Reserved */
   IFX_uint16_t Res07;
   /** OH Bytes per OH sub-frame "Gp" LP0 US */
   IFX_uint16_t Gp_LP0us;
   /** Reserved */
   IFX_uint16_t Res09;
   /** OH Frames per OH Superframe "Fp" LP0 US */
   IFX_uint16_t Fp_LP0us;
   /** Reserved */
   IFX_uint16_t Res11;
   /** MDFs per RS-Codeword "Mp" LP0 US */
   IFX_uint16_t Mp_LP0us;
   /** Reserved */
   IFX_uint16_t Res13;
   /** Bits per Symbol "Lp" LP0 US */
   IFX_uint16_t Lp_LP0us;
   /** Reserved */
   IFX_uint16_t Res15;
   /** RS Check Bytes "Rp" LP0 US */
   IFX_uint16_t Rp_LP0us;
   /** Reserved */
   IFX_uint16_t Res17;
   /** Interleaver Block Length "Ip", LP0 US */
   IFX_uint16_t Ip_LP0us;
   /** Reserved */
   IFX_uint16_t Res19;
   /** Interleaving Depth "Dp" LP0 US */
   IFX_uint16_t Dp_LP0us;
   /** Reserved */
   IFX_uint16_t Res21;
   /** OH Frame Period "PERp", LP0 US */
   IFX_uint16_t PERp_LP0us;
   /** Reserved */
   IFX_uint16_t Res23;
   /** Line Data Rate US for LP0, LSW */
   IFX_uint16_t DRp_LP0us_LSW;
   /** Line Data Rate US for LP0, MSW */
   IFX_uint16_t DRp_LP0us_MSW;
   /** Reserved */
   IFX_uint16_t Res26;
   /** Reserved */
   IFX_uint16_t Res27;
   /** RS Codeword Size "N_fecp" LP0 US */
   IFX_uint16_t N_fecp_LP0us;
   /** Reserved */
   IFX_uint16_t Res29;
   /** Framing Parameter "q", LP0 US */
   IFX_uint16_t q_LP0us;
   /** Reserved */
   IFX_uint16_t Res31;
   /** OH Bytes per OH FrameLP0 "SEQp" US */
   IFX_uint16_t SEQp_LP0us;
   /** Reserved */
   IFX_uint16_t Res33;
   /** OH sub-frames "Up" per OH frame LP0 US */
   IFX_uint16_t Up_LP0us;
   /** Reserved */
   IFX_uint16_t Res35;
   /** Bytes per OH Frame LP0 US, LSW */
   IFX_uint16_t PERBp_LP0us_LSW;
   /** Bytes per OH Frame LP0 US, MSW */
   IFX_uint16_t PERBp_LP0us_MSW;
   /** Reserved */
   IFX_uint16_t Res38;
   /** Reserved */
   IFX_uint16_t Res39;
   /** Bytes in MSG OH "MSGc" LP0 US */
   IFX_uint16_t MSGc_LP0us;
   /** Reserved */
   IFX_uint16_t Res41;
#endif
} __PACKED__ ;


/**
   Requests ADSL framing parameters for the downstream direction, latency path
   0/Interleaved Path.
*/
struct CMD_ADSL_FrameDataDS_LP0Get
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
   Delivers the ADSL framing parameters for the downstream direction, LP0/Interleaved
   path, as requested by CMD_ADSL_FrameDataDS_LP0Get. (Sections 7.5 & 7.6 of G.992.3
   [2] and 7.4 of G.992.1 [1])
*/
struct ACK_ADSL_FrameDataDS_LP0Get
{
#if MEI_DRV_OS_BYTE_ORDER == MEI_DRV_OS_BIG_ENDIAN
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** RS Check Bytes "Rp" DS LP0 */
   IFX_uint16_t Rp;
   /** Symbols per RS-Codeword "Sp" DS LP0 */
   IFX_uint16_t Sp;
   /** Interleaving Depth "Dp" DS LP0 */
   IFX_uint16_t Dp;
   /** Bytes per MDF "Kp" DS LP0 */
   IFX_uint16_t Kp;
   /** MDFs per RS-Codeword "Mp" DS LP0 */
   IFX_uint16_t Mp;
   /** Bits per Symbol "Lp" DS LP0 */
   IFX_uint16_t Lp;
   /** TCM Bits DS LP0 */
   IFX_uint16_t TCM;
   /** Framing Mode DS LP0 */
   IFX_uint16_t fraMode;
   /** "Tp" DS LP0 */
   IFX_uint16_t Tp;
   /** "SEQp" DS LP0 */
   IFX_uint16_t SEQp;
   /** Bytes in MSG-OH "MSGc" DS */
   IFX_uint16_t MSGc;
#else
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** RS Check Bytes "Rp" DS LP0 */
   IFX_uint16_t Rp;
   /** Symbols per RS-Codeword "Sp" DS LP0 */
   IFX_uint16_t Sp;
   /** Interleaving Depth "Dp" DS LP0 */
   IFX_uint16_t Dp;
   /** Bytes per MDF "Kp" DS LP0 */
   IFX_uint16_t Kp;
   /** MDFs per RS-Codeword "Mp" DS LP0 */
   IFX_uint16_t Mp;
   /** Bits per Symbol "Lp" DS LP0 */
   IFX_uint16_t Lp;
   /** TCM Bits DS LP0 */
   IFX_uint16_t TCM;
   /** Framing Mode DS LP0 */
   IFX_uint16_t fraMode;
   /** "Tp" DS LP0 */
   IFX_uint16_t Tp;
   /** "SEQp" DS LP0 */
   IFX_uint16_t SEQp;
   /** Bytes in MSG-OH "MSGc" DS */
   IFX_uint16_t MSGc;
#endif
} __PACKED__ ;


/**
   Requests ADSL framing parameters for the upstream direction, latency path
   0/Interleaved path.
*/
struct CMD_ADSL_FrameDataUS_LP0Get
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
   Delivers the ADSL framing parameters for the upstream direction, latency path
   0/Interleaved path, as requested by CMD_ADSL_FrameDataUS_LP0Get. (Sections 7.5 & 7.6
   of G.992.3 [2] and 7.4 of G.992.1 [1])
*/
struct ACK_ADSL_FrameDataUS_LP0Get
{
#if MEI_DRV_OS_BYTE_ORDER == MEI_DRV_OS_BIG_ENDIAN
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** RS Check Bytes "Rp" US LP0 */
   IFX_uint16_t Rp_LP0us;
   /** Symbols per RS-Codeword "Sp" US LP0 */
   IFX_uint16_t Sp;
   /** Interleaving Depth "Dp" US LP0 */
   IFX_uint16_t Dp;
   /** Bytes per MDF "Kp" US LP0 */
   IFX_uint16_t Kp;
   /** MDFs per RS-Codeword "Mp" US LP0 */
   IFX_uint16_t Mp;
   /** Bits per Symbol "Lp" US LP0 */
   IFX_uint16_t Lp;
   /** TCM Bits US LP0 */
   IFX_uint16_t TCM;
   /** Framing Mode US LP0 */
   IFX_uint16_t fraMode;
   /** "Tp" US LP0 */
   IFX_uint16_t Tp;
   /** "SEQp" US LP0 */
   IFX_uint16_t SEQp;
   /** Bytes in MSG-OH "MSGc" US */
   IFX_uint16_t MSGc;
#else
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** RS Check Bytes "Rp" US LP0 */
   IFX_uint16_t Rp_LP0us;
   /** Symbols per RS-Codeword "Sp" US LP0 */
   IFX_uint16_t Sp;
   /** Interleaving Depth "Dp" US LP0 */
   IFX_uint16_t Dp;
   /** Bytes per MDF "Kp" US LP0 */
   IFX_uint16_t Kp;
   /** MDFs per RS-Codeword "Mp" US LP0 */
   IFX_uint16_t Mp;
   /** Bits per Symbol "Lp" US LP0 */
   IFX_uint16_t Lp;
   /** TCM Bits US LP0 */
   IFX_uint16_t TCM;
   /** Framing Mode US LP0 */
   IFX_uint16_t fraMode;
   /** "Tp" US LP0 */
   IFX_uint16_t Tp;
   /** "SEQp" US LP0 */
   IFX_uint16_t SEQp;
   /** Bytes in MSG-OH "MSGc" US */
   IFX_uint16_t MSGc;
#endif
} __PACKED__ ;


/**
   Requests ADSL framing parameters for the downstream direction, latency path 1 (LP1)/
   Fast path.
   Note: In VINAX Rev. 1.x to be used for ADSL1, "fast path" only.
*/
struct CMD_ADSL_FrameDataDS_LP1Get
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
   Delivers the ADSL framing parameters for the downstream direction, LP1/Fast path, as
   requested by CMD_ADSL_FrameDataDS_LP1Get. (Sections 7.5 & 7.6 of G.992.3 [2] and 7.4
   of G.992.1 [1])
*/
struct ACK_ADSL_FrameDataDS_LP1Get
{
#if MEI_DRV_OS_BYTE_ORDER == MEI_DRV_OS_BIG_ENDIAN
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** RS Check Bytes "Rp" DS LP1 */
   IFX_uint16_t Rp;
   /** Symbols per RS-Codeword "Sp" DS LP1 */
   IFX_uint16_t Sp;
   /** Interleaving Depth "Dp" DS LP1 */
   IFX_uint16_t Dp;
   /** Bytes per MDF "Kp" DS LP1 */
   IFX_uint16_t Kp;
   /** MDFs per RS-Codeword "Mp" DS LP1 */
   IFX_uint16_t Mp;
   /** Bits per Symbol "Lp" DS LP1 */
   IFX_uint16_t Lp;
   /** TCM Bits DS LP1 */
   IFX_uint16_t TCM;
   /** Framing Mode DS LP1 */
   IFX_uint16_t fraMode;
   /** "Tp" DS LP1 */
   IFX_uint16_t Tp;
   /** "SEQp" DS LP1 */
   IFX_uint16_t SEQp;
   /** Bytes in MSG-OH "MSGc" DS */
   IFX_uint16_t MSGc;
#else
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** RS Check Bytes "Rp" DS LP1 */
   IFX_uint16_t Rp;
   /** Symbols per RS-Codeword "Sp" DS LP1 */
   IFX_uint16_t Sp;
   /** Interleaving Depth "Dp" DS LP1 */
   IFX_uint16_t Dp;
   /** Bytes per MDF "Kp" DS LP1 */
   IFX_uint16_t Kp;
   /** MDFs per RS-Codeword "Mp" DS LP1 */
   IFX_uint16_t Mp;
   /** Bits per Symbol "Lp" DS LP1 */
   IFX_uint16_t Lp;
   /** TCM Bits DS LP1 */
   IFX_uint16_t TCM;
   /** Framing Mode DS LP1 */
   IFX_uint16_t fraMode;
   /** "Tp" DS LP1 */
   IFX_uint16_t Tp;
   /** "SEQp" DS LP1 */
   IFX_uint16_t SEQp;
   /** Bytes in MSG-OH "MSGc" DS */
   IFX_uint16_t MSGc;
#endif
} __PACKED__ ;


/**
   Requests ADSL framing parameters for the upstream direction, latency path 1
   (LP1)/Fast path.
   Note: In VINAX Rev. 1.x to be used for ADSL1, "fast path" only.
*/
struct CMD_ADSL_FrameDataUS_LP1Get
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
   Delivers the ADSL framing parameters for the upstream direction, LP1/Fast path, as
   requested by CMD_ADSL_FrameDataUS_LP1Get. (Sections 7.5 & 7.6 of G.992.3 [2] and 7.4
   of G.992.1 [1])
*/
struct ACK_ADSL_FrameDataUS_LP1Get
{
#if MEI_DRV_OS_BYTE_ORDER == MEI_DRV_OS_BIG_ENDIAN
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** RS Check Bytes "Rp" US LP1 */
   IFX_uint16_t Rp_LP0us;
   /** Symbols per RS-Codeword "Sp" US LP1 */
   IFX_uint16_t Sp;
   /** Interleaving Depth "Dp" US LP1 */
   IFX_uint16_t Dp;
   /** Bytes per MDF "Kp" US LP1 */
   IFX_uint16_t Kp;
   /** MDFs per RS-Codeword "Mp" US LP1 */
   IFX_uint16_t Mp;
   /** Bits per Symbol "Lp" US LP1 */
   IFX_uint16_t Lp;
   /** TCM Bits US LP1 */
   IFX_uint16_t TCM;
   /** Framing Mode US LP1 */
   IFX_uint16_t fraMode;
   /** "Tp" US LP1 */
   IFX_uint16_t Tp;
   /** "SEQp" US LP1 */
   IFX_uint16_t SEQp;
   /** Bytes in MSG-OH "MSGc" US */
   IFX_uint16_t MSGc;
#else
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** RS Check Bytes "Rp" US LP1 */
   IFX_uint16_t Rp_LP0us;
   /** Symbols per RS-Codeword "Sp" US LP1 */
   IFX_uint16_t Sp;
   /** Interleaving Depth "Dp" US LP1 */
   IFX_uint16_t Dp;
   /** Bytes per MDF "Kp" US LP1 */
   IFX_uint16_t Kp;
   /** MDFs per RS-Codeword "Mp" US LP1 */
   IFX_uint16_t Mp;
   /** Bits per Symbol "Lp" US LP1 */
   IFX_uint16_t Lp;
   /** TCM Bits US LP1 */
   IFX_uint16_t TCM;
   /** Framing Mode US LP1 */
   IFX_uint16_t fraMode;
   /** "Tp" US LP1 */
   IFX_uint16_t Tp;
   /** "SEQp" US LP1 */
   IFX_uint16_t SEQp;
   /** Bytes in MSG-OH "MSGc" US */
   IFX_uint16_t MSGc;
#endif
} __PACKED__ ;


/**
   Reads back the parameter values configured with CMD_AlgorithmControlSet.
*/
struct CMD_AlgorithmControlGet
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
   Provides the information requested by CMD_AlgorithmControlGet.
*/
struct ACK_AlgorithmControlGet
{
#if MEI_DRV_OS_BYTE_ORDER == MEI_DRV_OS_BIG_ENDIAN
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Algorithm Control Parameter Status */
   IFX_uint16_t Readback[4];
#else
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Algorithm Control Parameter Status */
   IFX_uint16_t Readback[4];
#endif
} __PACKED__ ;


/**
   Reads back the settings for the digital high-pass filters as configured with
   CMD_DigitalFilterSet.
*/
struct CMD_DigitalFilterGet
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
   Provides the configured settings of the digital high-pass filters as requested by
   CMD_DigitalFilterGet.
*/
struct ACK_DigitalFilterGet
{
#if MEI_DRV_OS_BYTE_ORDER == MEI_DRV_OS_BIG_ENDIAN
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Digital Filter Parameter Status */
   IFX_uint16_t Readback[2];
#else
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Digital Filter Parameter Status */
   IFX_uint16_t Readback[2];
#endif
} __PACKED__ ;


/**
   Reads back the selected hybrid as configured with CMD_HybridSelect.
*/
struct CMD_HybridSelectionGet
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
   Provides the used hybrid as requested by CMD_HybridSelectionGet.
*/
struct ACK_HybridSelectionGet
{
#if MEI_DRV_OS_BYTE_ORDER == MEI_DRV_OS_BIG_ENDIAN
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Hybrid Status */
   IFX_uint16_t Readback;
#else
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Hybrid Status */
   IFX_uint16_t Readback;
#endif
} __PACKED__ ;


/**
   Reads the configured ACE filter mode.
*/
struct CMD_ACE_FilterGet
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
   Provides the configured ACE filter mode as requested by CMD_ACE_FilterGet.
*/
struct ACK_ACE_FilterGet
{
#if MEI_DRV_OS_BYTE_ORDER == MEI_DRV_OS_BIG_ENDIAN
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Reserved */
   IFX_uint8_t Res02;
   /** ACE Filter Mode */
   IFX_uint8_t filterMode;
#else
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** ACE Filter Mode */
   IFX_uint8_t filterMode;
   /** Reserved */
   IFX_uint8_t Res02;
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

