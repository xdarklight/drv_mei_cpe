/******************************************************************************

                               Copyright (c) 2011
                            Lantiq Deutschland GmbH
                     Am Campeon 3; 85579 Neubiberg, Germany

  For licensing information, see the file 'LICENSE' in the root folder of
  this software module.

******************************************************************************/


#ifndef _VDSL2_FWDES_UTOPIAPOSPHYMSG_H_
#define _VDSL2_FWDES_UTOPIAPOSPHYMSG_H_

/** \file
   This chapter contains the configuration messages for the UTOPIA and POS-PHY
   interface.
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

/** @defgroup _VDSL2_FWDES_UTOPIAPOSPHYMSG_ Messages for UTOPIA and POS-PHY
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
   Defines for the SAR configuration
*/
/** LLC Encapsultion Bridged Protocol */
#define SAR_LLC_ENCAP_BP 3
/** VC Multiplexing Bridged Protocol */
#define SAR_VC_MUX_BP 1
/** Filter on Destination MAC address */
#define SAR_FILTER_MAC_DESTADDR 0
/** Filter on Source MAC address */
#define SAR_FILTER_MAC_SRCADDR 3
/** Filter on VLAN ID */
#define SAR_FILTER_VLAN_ID 1
/** Filter on VLAN Priority */
#define SAR_FILTER_VLAN_PRIO 2
/** Discard the packet on mismatch classification */
#define SAR_DISCARD_PACKET 0
/** Filter on Default VPI/VCI */
#define SAR_DEF_VPI_VCI 1


/* ----- Constants Definition section ----- */
#define  CMD_UTOPIA_L2_Init_BITS_8  0x00000000
#define  CMD_UTOPIA_L2_Init_BITS_16  0x00000001
#define  CMD_UTOPIA_L2_Modify_ODD_PARITY  0x00000000
#define  CMD_UTOPIA_L2_Modify_EVEN_PARITY  0x00000001
#define  CMD_POSPHY_L2_Modify_ODD_PARITY  0x00000000
#define  CMD_POSPHY_L2_Modify_EVEN_PARITY  0x00000001
#define  CMD_POSPHY_L2_Modify_IFX_DISABLE  0x00000000
#define  CMD_POSPHY_L2_Modify_IFX_ENABLE  0x00000001
#define  CMD_EthernetOAM_Configure_PASSIVE  0x00000000
#define  CMD_EthernetOAM_Configure_ACTIVE  0x00000001
#define  CMD_EthernetInsertExtractControl_SYSTEM_SIDE  0x00000000
#define  CMD_EthernetInsertExtractControl_LINE_SIDE  0x00000001
#define  CMD_EthernetInsertExtractControl_SYSTEM_LINE_SIDE  0x00000002
#define  CMD_EthernetExtractConfigure_FV25  25
#define  CMD_EthernetExtractConfigure_FV26  26
#define  CMD_EthernetExtractConfigure_SYSTEM_SIDE  0x00000000
#define  CMD_EthernetExtractConfigure_LINE_SIDE  0x00000001
#define  CMD_EthernetExtractConfigure_SYSTEM_LINE_SIDE  0x00000002
#define  CMD_EthernetExtractConfigure_NO_FILTER  0x00000000
#define  CMD_EthernetExtractConfigure_DISCARD  0x00000001
#define  CMD_EthernetExtractConfigure_RESERVED_M  0x00000002
#define  CMD_EthernetExtractConfigure_EXTRACT  0x00000003
#define  CMD_EthernetExtractConfigure_MONITOR  0x00000002
#define  CMD_EthernetExtractConfigure_FILTER_MAC_DST_ADDR  0x00000001
#define  CMD_EthernetExtractConfigure_FILTER_MAC_SRC_ADDR  0x00000002
#define  CMD_EthernetExtractConfigure_FILTER_VLAN_ID  0x00000003
#define  CMD_EthernetExtractConfigure_FILTER_VLAN_PRIO  0x00000004
#define  ACK_EthernetExtractConfigure_FV25  25
#define  ACK_EthernetExtractConfigure_FV26  26
#define  CMD_EthernetExtractConfigGet_FV24  24
#define  CMD_EthernetExtractConfigGet_SYSTEM_SIDE  0x00000000
#define  CMD_EthernetExtractConfigGet_LINE_SIDE  0x00000001
#define  ACK_EthernetExtractConfigGet_FV24  24
#define  ACK_EthernetExtractConfigGet_SYSTEM_SIDE  0x00000000
#define  ACK_EthernetExtractConfigGet_LINE_SIDE  0x00000001
#define  ACK_EthernetExtractConfigGet_NO_FILTER  0x00000000
#define  ACK_EthernetExtractConfigGet_DISCARD  0x00000001
#define  ACK_EthernetExtractConfigGet_RESERVED_M  0x00000002
#define  ACK_EthernetExtractConfigGet_EXTRACT  0x00000003
#define  ACK_EthernetExtractConfigGet_FILTER_MAC_DST_ADDR  0x00000001
#define  ACK_EthernetExtractConfigGet_FILTER_MAC_SRC_ADDR  0x00000002
#define  ACK_EthernetExtractConfigGet_FILTER_VLAN_ID  0x00000003
#define  ACK_EthernetExtractConfigGet_FILTER_VLAN_PRIO  0x00000004
#define  EVT_EthernetFrameLineExtract_NEXT_FRAGMENT  0
#define  EVT_EthernetFrameLineExtract_START_OF_FRAME  1
#define  EVT_EthernetFrameLineExtract_END_OF_FRAME  2
#define  EVT_EthernetFrameLineExtract_FULL_FRAME  3
#define  EVT_EthernetFrameLineExtract_FILTER1  0
#define  EVT_EthernetFrameLineExtract_FILTER2  1
#define  EVT_EthernetFrameLineExtract_OAM_FILTER  2
#define  EVT_EthernetFrameSysExtract_NEXT_FRAGMENT  0
#define  EVT_EthernetFrameSysExtract_START_OF_FRAME  1
#define  EVT_EthernetFrameSysExtract_END_OF_FRAME  2
#define  EVT_EthernetFrameSysExtract_FULL_FRAME  3
#define  EVT_EthernetFrameSysExtract_FILTER1  0
#define  EVT_EthernetFrameSysExtract_FILTER2  1
#define  EVT_EthernetFrameSysExtract_OAM_FILTER  2
#define  CMD_AtmInsertExtractControl_LINE_SIDE  0x00000001
#define  EVT_AtmCellLineInsertStatusGet_INSERT_DONE  2
#define  EVT_AtmCellLineInsertStatusGet_INSERT_ERR  3
#define  ACK_AtmCellLineInsertStatusGet_INSERT_PROG  1
#define  ACK_AtmCellLineInsertStatusGet_INSERT_DONE  2
#define  ACK_AtmCellLineInsertStatusGet_INSERT_ERR  3
#define  ALM_AtmCellExtractFailed_LINE_SIDE  0x00000001
#define  CMD_AtmInsertExtractStatsGet_LINE_SIDE  0x00000001
#define  ACK_AtmInsertExtractStatsGet_LINE_SIDE  0x00000001
/* ----- Constants Definition section (End) ----- */

/** Message ID for CMD_LinkControl */
#define CMD_LINKCONTROL 0x0151

/**
   This command is used to enable/disable the transmit and receive flow at the
   UTOPIA/POS-PHY interface.
   Note: Before using this command the TC layer must be setup with CMD_FlowModify.
*/
typedef struct CMD_LinkControl CMD_LinkControl_t;

/** Message ID for ACK_LinkControl */
#define ACK_LINKCONTROL 0x0151

/**

*/
typedef struct ACK_LinkControl ACK_LinkControl_t;

/** Message ID for CMD_UTOPIA_L2_Init */
#define CMD_UTOPIA_L2_INIT 0x0251

/**
   This command is used to configure the UTOPIA interface.
*/
typedef struct CMD_UTOPIA_L2_Init CMD_UTOPIA_L2_Init_t;

/** Message ID for ACK_UTOPIA_L2_Init */
#define ACK_UTOPIA_L2_INIT 0x0251

/**

*/
typedef struct ACK_UTOPIA_L2_Init ACK_UTOPIA_L2_Init_t;

/** Message ID for CMD_UTOPIA_L2_Modify */
#define CMD_UTOPIA_L2_MODIFY 0x0351

/**
   This command is used to modify the default settings of the UTOPIA interface.
*/
typedef struct CMD_UTOPIA_L2_Modify CMD_UTOPIA_L2_Modify_t;

/** Message ID for ACK_UTOPIA_L2_Modify */
#define ACK_UTOPIA_L2_MODIFY 0x0351

/**

*/
typedef struct ACK_UTOPIA_L2_Modify ACK_UTOPIA_L2_Modify_t;

/** Message ID for CMD_POSPHY_L2_Init */
#define CMD_POSPHY_L2_INIT 0x0451

/**
   This command is used to initialize the POS-PHY interface.
*/
typedef struct CMD_POSPHY_L2_Init CMD_POSPHY_L2_Init_t;

/** Message ID for ACK_POSPHY_L2_Init */
#define ACK_POSPHY_L2_INIT 0x0451

/**

*/
typedef struct ACK_POSPHY_L2_Init ACK_POSPHY_L2_Init_t;

/** Message ID for CMD_POSPHY_L2_Modify */
#define CMD_POSPHY_L2_MODIFY 0x0551

/**
   This command is used to modify the default settings of the POS-PHY interface.
   In VINAX V2.x the settings for Parameter 2 (Parity), 3 (Chunksize) und 5 (PMPE) are
   valid for all ports per die (4 in VINAX-M/S, 2 in VINAX-L), therefore the firmware
   executes the change only if all ports of the die (see Table22) are disabled. (True
   directly after FW download, otherwise apply CMD_LinkControl.)
*/
typedef struct CMD_POSPHY_L2_Modify CMD_POSPHY_L2_Modify_t;

/** Message ID for ACK_POSPHY_L2_Modify */
#define ACK_POSPHY_L2_MODIFY 0x0551

/**

*/
typedef struct ACK_POSPHY_L2_Modify ACK_POSPHY_L2_Modify_t;

/** Message ID for CMD_SegmentationReassemblyConfig */
#define CMD_SEGMENTATIONREASSEMBLYCONFIG 0x0A51

/**
   This command is used to configure the general settings for the SAR process.
   Note: The link must be disabled before this command can be sent. The command is
   accepted in modem state RESET only.
*/
typedef struct CMD_SegmentationReassemblyConfig CMD_SegmentationReassemblyConfig_t;

/** Message ID for ACK_SegmentationReassemblyConfig */
#define ACK_SEGMENTATIONREASSEMBLYCONFIG 0x0A51

/**
   Acknowledgement for the message CMD_SegmentationReassemblyConfig.
*/
typedef struct ACK_SegmentationReassemblyConfig ACK_SegmentationReassemblyConfig_t;

/** Message ID for CMD_Segmentation_VCC_Config */
#define CMD_SEGMENTATION_VCC_CONFIG 0x0B51

/**
   This command configures the ethernet forwarding table, up to 8 entries can be
   defined.
   Note: The command is accepted in modem state RESET only.
   Note: The link must be disabled before this command can be sent.
   Note: The general settings for the SAR process must be configured before with
   CMD_SegmentationReassemblyConfig.
*/
typedef struct CMD_Segmentation_VCC_Config CMD_Segmentation_VCC_Config_t;

/** Message ID for ACK_Segmentation_VCC_Config */
#define ACK_SEGMENTATION_VCC_CONFIG 0x0B51

/**
   Acknowledgement for the message CMD_Segmentation_VCC_Config.
*/
typedef struct ACK_Segmentation_VCC_Config ACK_Segmentation_VCC_Config_t;

/** Message ID for CMD_SegmentationClassFilter_Add */
#define CMD_SEGMENTATIONCLASSFILTER_ADD 0x0C51

/**
   This command adds a classification filter to the segmentation classification table,
   up to 16 entries can be defined.
   Note: The link must be disabled before this command can be sent.
   Note: The Ethernet Forwarding Table must not be empty (see
   CMD_Segmentation_VCC_Config).
*/
typedef struct CMD_SegmentationClassFilter_Add CMD_SegmentationClassFilter_Add_t;

/** Message ID for ACK_SegmentationClassFilter_Add */
#define ACK_SEGMENTATIONCLASSFILTER_ADD 0x0C51

/**
   Acknowledgement to the message CMD_SegmentationClassFilter_Add.
*/
typedef struct ACK_SegmentationClassFilter_Add ACK_SegmentationClassFilter_Add_t;

/** Message ID for CMD_ReassemblyClassFilter_Add */
#define CMD_REASSEMBLYCLASSFILTER_ADD 0x0D51

/**
   This command adds a classification filter to the reassembly classification table,
   upto 8 entries can be defined.
   Note: The link must be disabled before this command can be sent.
*/
typedef struct CMD_ReassemblyClassFilter_Add CMD_ReassemblyClassFilter_Add_t;

/** Message ID for ACK_ReassemblyClassFilter_Add */
#define ACK_REASSEMBLYCLASSFILTER_ADD 0x0D51

/**
   Acknowledgement for the message CMD_ReassemblyClassFilter_Add.
*/
typedef struct ACK_ReassemblyClassFilter_Add ACK_ReassemblyClassFilter_Add_t;

/** Message ID for CMD_VCC_MappingGet */
#define CMD_VCC_MAPPINGGET 0x0E11

/**
   Requests the mapping between the ATM-entry number (0...7) in the MAC-VPI/VCI map
   table and the VCC value.
*/
typedef struct CMD_VCC_MappingGet CMD_VCC_MappingGet_t;

/** Message ID for ACK_VCC_MappingGet */
#define ACK_VCC_MAPPINGGET 0x0E11

/**
   Acknowledgement to a CMD_VCC_MappingGet command. Provides the mapping between the
   ATM-entry number (0...7) in the MAC-VPI/VCI map table and the VCC value.
*/
typedef struct ACK_VCC_MappingGet ACK_VCC_MappingGet_t;

/** Message ID for CMD_EthernetOAM_Control */
#define CMD_ETHERNETOAM_CONTROL 0x4051

/**
   This message enables/disables the Ethernet OAM layer. Enabling is required before
   doing any OAM configuration settings likee.g. for Insert/Extract or OAM filtering.
*/
typedef struct CMD_EthernetOAM_Control CMD_EthernetOAM_Control_t;

/** Message ID for ACK_EthernetOAM_Control */
#define ACK_ETHERNETOAM_CONTROL 0x4051

/**
   Acknowledgment for message CMD_EthernetOAM_Control.
*/
typedef struct ACK_EthernetOAM_Control ACK_EthernetOAM_Control_t;

/** Message ID for CMD_EthernetOAM_Configure */
#define CMD_ETHERNETOAM_CONFIGURE 0x4151

/**
   This message configures the OAM operation.
   The command is to be applied locally at both xTU-C and xTU-R only after TC
   configuration. (See also Attention note at Page912).
*/
typedef struct CMD_EthernetOAM_Configure CMD_EthernetOAM_Configure_t;

/** Message ID for ACK_EthernetOAM_Configure */
#define ACK_ETHERNETOAM_CONFIGURE 0x4151

/**
   This message acknowledges the CMD_EthernetOAM_Configure message.
*/
typedef struct ACK_EthernetOAM_Configure ACK_EthernetOAM_Configure_t;

/** Message ID for CMD_MAC_FrameConfigure */
#define CMD_MAC_FRAMECONFIGURE 0x1651

/**
   The message configures Ethernet properties like MAC address of the device, the
   allowed ethernet frame sizes for each bearer and the handling of slow protocol
   frames.
   The MAC address is needed in the FW as "MAC source address" for OAM PDUs not built
   by the host like PAUSE frames (in contrary to the OAM PDUs inserted by the host IF
   which get this address from the host before insertion).
   The configurable maximum frame length defines the limit , starting at which frames
   are treated as "too long" and are counted accordingly or art discarded.)
   Background: : VLAN tags. Without :1518, tagged (simle):1522, tagged (stacked):>1522
*/
typedef struct CMD_MAC_FrameConfigure CMD_MAC_FrameConfigure_t;

/** Message ID for ACK_MAC_FrameConfigure */
#define ACK_MAC_FRAMECONFIGURE 0x1651

/**
   Acknowledgment for message CMD_MAC_FrameConfigure.
*/
typedef struct ACK_MAC_FrameConfigure ACK_MAC_FrameConfigure_t;

/** Message ID for CMD_EthernetInsertExtractControl */
#define CMD_ETHERNETINSERTEXTRACTCONTROL 0x4451

/**
   This command enables/disables the ethernet insert/extract to the system/line side.
   The command is to be applied locally. For a hostless CPE the Insert/Extract
   operation is enabled by default.
*/
typedef struct CMD_EthernetInsertExtractControl CMD_EthernetInsertExtractControl_t;

/** Message ID for ACK_EthernetInsertExtractControl */
#define ACK_ETHERNETINSERTEXTRACTCONTROL 0x4451

/**
   Acknowledgment for message CMD_EthernetInsertExtractControl.
*/
typedef struct ACK_EthernetInsertExtractControl ACK_EthernetInsertExtractControl_t;

/** Message ID for CMD_EthernetFrameLineInsert */
#define CMD_ETHERNETFRAMELINEINSERT 0x4551

/**
   This command writes an ethernet frame or fragments of it to be inserted to the Line
   side in transmit direction.
   The length of an ethernet frame migth be longer than the mailbox size, then it is
   send via a sequence of messages.
   The frame is transmitted when the message is received with a positive fragment
   length. A frame length of 0 indicates that the data from the message is copied to
   the frame transmit buffer but the frame is not transmitted yet.
   Applicable at xTU-C and xTU-R.
   Example:
   For inserting an OAM PDU, the firmware assumes that the data fragments contain the
   following structure:
   6 Bytes: Ethernet Destination Address: 01-80-c2-00-00-02
   6 Bytes: Ethernet Source Address.
   2 Bytes: Length/Type field: 88-09 [Slow Protocols]
   1 Byte: Subtype = 0x03 [OAM]
   2 Bytes: Flags
   1 Byte: Code
   42-1496 Bytes: Data/Padding
   4 Bytes: FCS (automatically appended by Vinax)
   The FCS must not be in the data structure but is instead automatically appended. The
   first 4 bytes of the data structure which contain the length of the ethernet frame
   are not transmitted.
*/
typedef struct CMD_EthernetFrameLineInsert CMD_EthernetFrameLineInsert_t;

/** Message ID for ACK_EthernetFrameLineInsert */
#define ACK_ETHERNETFRAMELINEINSERT 0x4551

/**
   This message acknowledges the CMD_EthernetFrameLineInsert message.
*/
typedef struct ACK_EthernetFrameLineInsert ACK_EthernetFrameLineInsert_t;

/** Message ID for CMD_EthernetFrameSysInsert */
#define CMD_ETHERNETFRAMESYSINSERT 0x4651

/**
   This command writes an ethernet frame or fragments of it to be inserted to the
   system side in transmit direction.
   The length of an ethernet frame migth be longer than the mailbox size, then it is
   send via a sequence of messages.
   The frame is transmitted when the message is received with a positive fragment
   length. A frame length of 0 indicates that the all data from the message is copied
   to the frame transmit buffer but the frame is not transmitted yet.
   Applicable at xTU-C and xTU-R (with host).
   Example:
   For inserting an OAM PDU, the firmware assumes that the data fragments contain the
   following structure:
   6 Bytes: Ethernet Destination Address: 01-80-c2-00-00-02
   6 Bytes: Ethernet Source Address.
   2 Bytes: Length/Type field: 88-09 [Slow Protocols]
   1 Byte: Subtype = 0x03 [OAM]
   2 Bytes: Flags
   1 Byte: Code
   42-1496 Bytes: Data/Padding
   4 Bytes: FCS (automatically appended by Vinax)
   The FCS must not be in the data structure but is instead automatically appended. The
   first 4 bytes of the data structure which contain the length of the ethernet frame
   are not transmitted.
*/
typedef struct CMD_EthernetFrameSysInsert CMD_EthernetFrameSysInsert_t;

/** Message ID for ACK_EthernetFrameSysInsert */
#define ACK_ETHERNETFRAMESYSINSERT 0x4651

/**
   This message acknowledges the CMD_EthernetFrameSysInsert message.
*/
typedef struct ACK_EthernetFrameSysInsert ACK_EthernetFrameSysInsert_t;

/** Message ID for CMD_EthernetExtractConfigure */
#define CMD_ETHERNETEXTRACTCONFIGURE 0x4351

/**
   This message configures the ethernet packet extraction filters. There are extraction
   units at system and at line side. For each side there are two programmable filters
   and 3 fixed filters for PAUSE, MAC Control and Slow Protocol frames. The fixed
   filters can only be used to discard frames. The filter units can be configured such
   that the filtered frames are extracted and copied to the mailbox or the extracted
   frames can also be discarded.
   The message is to be applied locally before CMD_EthernetInsertExtractControl! (but
   after TC configuration, see Attention note at Page922).
   At the hostless CPE the message becomes effective only if the "LAN Update Enable"
   parameter in CMD_FW_UpdateLAN_Configure was DISABLED. Otherwise
   CMD_EthernetInsertExtractControl has no effect here!
   Application example:
   Spanning Tree Protocol BPDUÕs shall not be transported from LAN to WAN. BPDUÕs can
   be identified by the ethernet multicast destination address 01-80-C2-00-00-00. In
   order to block all ethernet frames with this destination address with filter unit 1,
   the following settings have to be programmed:
   Side: System Side
   Filter1Operation: Discard
   Filter1Config: FILTER_MAC_DST_ADDRESS
   MacAddr1_0_3: 0x0180C200
   MacAddr1_4_5: 0x00000000
   AddrMask1_0_3: 0x00000000
   AddrMask1_4_5: 0x00000000
   This will extract all BPDU frames identified via the ethernet multicast address.
*/
typedef struct CMD_EthernetExtractConfigure CMD_EthernetExtractConfigure_t;

/** Message ID for ACK_EthernetExtractConfigure */
#define ACK_ETHERNETEXTRACTCONFIGURE 0x4351

/**
   This message acknowledges the CMD_EthernetExtractConfigure message.
*/
typedef struct ACK_EthernetExtractConfigure ACK_EthernetExtractConfigure_t;

/** Message ID for CMD_EthernetExtractConfigGet */
#define CMD_ETHERNETEXTRACTCONFIGGET 0x4911

/**
   The message reads back the ethernet extraction settings in use, as configured with
   CMD_EthernetExtractConfigure.
*/
typedef struct CMD_EthernetExtractConfigGet CMD_EthernetExtractConfigGet_t;

/** Message ID for ACK_EthernetExtractConfigGet */
#define ACK_ETHERNETEXTRACTCONFIGGET 0x4911

/**
   The message contains the ethernet extraction settings in use, as requested by
   CMD_EthernetExtractConfigGet.
*/
typedef struct ACK_EthernetExtractConfigGet ACK_EthernetExtractConfigGet_t;

/** Message ID for EVT_EthernetFrameLineExtract */
#define EVT_ETHERNETFRAMELINEEXTRACT 0x4711

/**
   This event indicates the extraction of an ethernet frame from the line side in
   receive direction.
   Frames which are longer than the mailbox are transported in fragments.
   This EVT is generated at xTU-C and xTU-R with host.
*/
typedef struct EVT_EthernetFrameLineExtract EVT_EthernetFrameLineExtract_t;

/** Message ID for EVT_EthernetFrameSysExtract */
#define EVT_ETHERNETFRAMESYSEXTRACT 0x4811

/**
   This event indicates the extraction of an ethernet frame from the system side in
   transmit direction.
   Frames which are longer than the mailbox are transported in fragments.
   This EVT is generated at xTU-C and xTU-R with host.
*/
typedef struct EVT_EthernetFrameSysExtract EVT_EthernetFrameSysExtract_t;

/** Message ID for CMD_AtmInsertExtractControl */
#define CMD_ATMINSERTEXTRACTCONTROL 0x5051

/**
   The command enables/disables the ATM insert/extract processing. It is to be applied
   locally.
*/
typedef struct CMD_AtmInsertExtractControl CMD_AtmInsertExtractControl_t;

/** Message ID for ACK_AtmInsertExtractControl */
#define ACK_ATMINSERTEXTRACTCONTROL 0x5051

/**
   Acknowledgment for message CMD_AtmInsertExtractControl.
*/
typedef struct ACK_AtmInsertExtractControl ACK_AtmInsertExtractControl_t;

/** Message ID for CMD_AtmCellLineInsert */
#define CMD_ATMCELLLINEINSERT 0x5151

/**
   This command writes ATM cells to be inserted to the line side in transmit direction.
   Up to 4 ATM cells can be put into the mailbox. A "good" acknowledge
   (ACK_AtmCellLineInsert) does not indicate that the cells have been succesfully
   inserted but only that the message has been accepted by the FW. The FW accepts a
   message only if the previous insertion was completed, otherwise the
   ACK_AtmCellLineInsert indicates an error "E1H" in the functional opcode. Successful
   insertion is indicated with EVT_AtmCellLineInsertStatusGet. On receipt of it the
   next cells to be inserted can be immediately written down to the VINAX.
*/
typedef struct CMD_AtmCellLineInsert CMD_AtmCellLineInsert_t;

/** Message ID for ACK_AtmCellLineInsert */
#define ACK_ATMCELLLINEINSERT 0x5151

/**
   This message acknowledges CMD_AtmCellLineInsert.
   Note: Note on the functional opcode, part of the message header and not described
   in this document (see [16] ):A "good" acknowledge (functional opcode
   5H=D2H_CMV_WRITE_REPLY) does not indicate that the cells have been
   successfully inserted but only that the message has been accepted by the
   FW. The FW accepts a message only if the previous insertion was completed,
   otherwise the ACK_AtmCellLineInsert indicates an error "E1H" in the
   functional opcode.
*/
typedef struct ACK_AtmCellLineInsert ACK_AtmCellLineInsert_t;

/** Message ID for EVT_AtmCellLineInsertStatusGet */
#define EVT_ATMCELLLINEINSERTSTATUSGET 0x5511

/**
   This autonomous message reports the final status of the ATM cell insertion as
   completed or failed. It is sent only if the "Insert Status EVT Control" was enabled
   in CMD_AtmInsertExtractControl and if the ACK_AtmCellLineInsert did not indicate an
   error before. If both conditions are met, the message is generated when the ATM cell
   insertion requested with the last CMD_AtmCellLineInsert is finished (for all cells)
   or failed.
*/
typedef struct EVT_AtmCellLineInsertStatusGet EVT_AtmCellLineInsertStatusGet_t;

/** Message ID for CMD_AtmCellLineInsertStatusGet */
#define CMD_ATMCELLLINEINSERTSTATUSGET 0x5511

/**
   Requests the status of the ATM cell insertion for the last CMD_AtmCellLineInsert
   sent.
*/
typedef struct CMD_AtmCellLineInsertStatusGet CMD_AtmCellLineInsertStatusGet_t;

/** Message ID for ACK_AtmCellLineInsertStatusGet */
#define ACK_ATMCELLLINEINSERTSTATUSGET 0x5511

/**
   The message reports the status of the ATM cell insertion as requested by
   CMD_AtmCellLineInsertStatusGet.
*/
typedef struct ACK_AtmCellLineInsertStatusGet ACK_AtmCellLineInsertStatusGet_t;

/** Message ID for EVT_AtmCellLineExtract */
#define EVT_ATMCELLLINEEXTRACT 0x5211

/**
   This event indicates the extraction of ATM cells from the line side in receive
   direction and provides the data.
   ATM cells are extracted and provided to the host only if the ATM insert/extract was
   enabled with CMD_AtmInsertExtractControl. Once an extract filter matches, the cell
   will be extracted. In VINAX V1.x only OAM cells (F4 or F5) are filtered out (any of
   them) and there is no programmable filter condition at the FW-API. Up to 4 cells can
   be contained in the message, the exact number can be easily calculated from in the
   Length parameter (see below). Consecutive ATM cells start 32 bit aligned in the "ATM
   data" field.
   A loss of ATM cells to be extracted due to an extract buffer overflow is indicated
   by ALM_AtmCellExtractFailed.
   Note: For OAM cell extraction the message will usually contain 1 ATM cell only.
*/
typedef struct EVT_AtmCellLineExtract EVT_AtmCellLineExtract_t;

/** Message ID for ALM_AtmCellExtractFailed */
#define ALM_ATMCELLEXTRACTFAILED 0x5311

/**
   This autonomous alarm message indicates a congestion problem in the ATM cell
   extraction and delivery process and reports the number of ATM cells that got lost
   due to a buffer overflow. It is generated only if the corresponding control in
   CMD_AtmInsertExtractControl was enabled. The message is sent only once per second
   (provided any failure ocurred).
*/
typedef struct ALM_AtmCellExtractFailed ALM_AtmCellExtractFailed_t;

/** Message ID for CMD_AtmInsertExtractStatsGet */
#define CMD_ATMINSERTEXTRACTSTATSGET 0x5411

/**
   The message requests the values of ATM insert/extract statistics counters.
*/
typedef struct CMD_AtmInsertExtractStatsGet CMD_AtmInsertExtractStatsGet_t;

/** Message ID for ACK_AtmInsertExtractStatsGet */
#define ACK_ATMINSERTEXTRACTSTATSGET 0x5411

/**
   The message delivers the values of ATM insert/extract statistics counters as
   requested by CMD_AtmInsertExtractStatsGet.
*/
typedef struct ACK_AtmInsertExtractStatsGet ACK_AtmInsertExtractStatsGet_t;

/**
   This command is used to enable/disable the transmit and receive flow at the
   UTOPIA/POS-PHY interface.
   Note: Before using this command the TC layer must be setup with CMD_FlowModify.
*/
struct CMD_LinkControl
{
#if MEI_DRV_OS_BYTE_ORDER == MEI_DRV_OS_BIG_ENDIAN
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Link Number */
   IFX_uint32_t LinkNo;
   /** Transmit Control Mode */
   IFX_uint32_t TX_Mode;
   /** Receive Control Mode */
   IFX_uint32_t RX_Mode;
#else
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Link Number */
   IFX_uint32_t LinkNo;
   /** Transmit Control Mode */
   IFX_uint32_t TX_Mode;
   /** Receive Control Mode */
   IFX_uint32_t RX_Mode;
#endif
} __PACKED__ ;


/**

*/
struct ACK_LinkControl
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
   This command is used to configure the UTOPIA interface.
*/
struct CMD_UTOPIA_L2_Init
{
#if MEI_DRV_OS_BYTE_ORDER == MEI_DRV_OS_BIG_ENDIAN
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Data Width */
   IFX_uint32_t Width;
#else
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Data Width */
   IFX_uint32_t Width;
#endif
} __PACKED__ ;


/**

*/
struct ACK_UTOPIA_L2_Init
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
   This command is used to modify the default settings of the UTOPIA interface.
*/
struct CMD_UTOPIA_L2_Modify
{
#if MEI_DRV_OS_BYTE_ORDER == MEI_DRV_OS_BIG_ENDIAN
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** UDF2 Byte */
   IFX_uint32_t UDF2_bytes;
   /** Parity Mode */
   IFX_uint32_t ParityMode;
   /** Cell Discard if Parity Error */
   IFX_uint32_t CDPE;
   /** UTOPIA Port Numbers */
   IFX_uint32_t PortNum;
#else
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** UDF2 Byte */
   IFX_uint32_t UDF2_bytes;
   /** Parity Mode */
   IFX_uint32_t ParityMode;
   /** Cell Discard if Parity Error */
   IFX_uint32_t CDPE;
   /** UTOPIA Port Numbers */
   IFX_uint32_t PortNum;
#endif
} __PACKED__ ;


/**

*/
struct ACK_UTOPIA_L2_Modify
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
   This command is used to initialize the POS-PHY interface.
*/
struct CMD_POSPHY_L2_Init
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

*/
struct ACK_POSPHY_L2_Init
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
   This command is used to modify the default settings of the POS-PHY interface.
   In VINAX V2.x the settings for Parameter 2 (Parity), 3 (Chunksize) und 5 (PMPE) are
   valid for all ports per die (4 in VINAX-M/S, 2 in VINAX-L), therefore the firmware
   executes the change only if all ports of the die (see Table22) are disabled. (True
   directly after FW download, otherwise apply CMD_LinkControl.)
*/
struct CMD_POSPHY_L2_Modify
{
#if MEI_DRV_OS_BYTE_ORDER == MEI_DRV_OS_BIG_ENDIAN
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Parity Mode */
   IFX_uint32_t ParityMode;
   /** Burst Transfer Size */
   IFX_uint32_t ChunkSize;
   /** POS-PHY Bus Frequency */
   IFX_uint32_t Frequency;
   /** Packet Error Marking if Parity Error */
   IFX_uint32_t PMPE;
   /** POS-PHY Port Numbers */
   IFX_uint32_t PortNum;
   /** ATM Cell Mode Enable for POSPHY (VINAX V2.X only) */
   IFX_uint32_t atmCellMode;
#else
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Parity Mode */
   IFX_uint32_t ParityMode;
   /** Burst Transfer Size */
   IFX_uint32_t ChunkSize;
   /** POS-PHY Bus Frequency */
   IFX_uint32_t Frequency;
   /** Packet Error Marking if Parity Error */
   IFX_uint32_t PMPE;
   /** POS-PHY Port Numbers */
   IFX_uint32_t PortNum;
   /** ATM Cell Mode Enable for POSPHY (VINAX V2.X only) */
   IFX_uint32_t atmCellMode;
#endif
} __PACKED__ ;


/**

*/
struct ACK_POSPHY_L2_Modify
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
   This command is used to configure the general settings for the SAR process.
   Note: The link must be disabled before this command can be sent. The command is
   accepted in modem state RESET only.
*/
struct CMD_SegmentationReassemblyConfig
{
#if MEI_DRV_OS_BYTE_ORDER == MEI_DRV_OS_BIG_ENDIAN
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Link Number */
   IFX_uint32_t LinkNo;
   /** CPCS Protocol */
   IFX_uint32_t CPCS_Protocol;
   /** FCS Preserved within the PDU */
   IFX_uint32_t FCS_Present;
   /** Segmentation Classification Filter */
   IFX_uint32_t SegClassFilter;
   /** Segmentation Default Action */
   IFX_uint32_t SegDefAction;
   /** Segmentation Default Virtual Path Identifier */
   IFX_uint32_t SegDef_VPI;
   /** Segmentation Default Virtual Channel Identifier */
   IFX_uint32_t SegDef_VCI;
#else
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Link Number */
   IFX_uint32_t LinkNo;
   /** CPCS Protocol */
   IFX_uint32_t CPCS_Protocol;
   /** FCS Preserved within the PDU */
   IFX_uint32_t FCS_Present;
   /** Segmentation Classification Filter */
   IFX_uint32_t SegClassFilter;
   /** Segmentation Default Action */
   IFX_uint32_t SegDefAction;
   /** Segmentation Default Virtual Path Identifier */
   IFX_uint32_t SegDef_VPI;
   /** Segmentation Default Virtual Channel Identifier */
   IFX_uint32_t SegDef_VCI;
#endif
} __PACKED__ ;


/**
   Acknowledgement for the message CMD_SegmentationReassemblyConfig.
*/
struct ACK_SegmentationReassemblyConfig
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
   This command configures the ethernet forwarding table, up to 8 entries can be
   defined.
   Note: The command is accepted in modem state RESET only.
   Note: The link must be disabled before this command can be sent.
   Note: The general settings for the SAR process must be configured before with
   CMD_SegmentationReassemblyConfig.
*/
struct CMD_Segmentation_VCC_Config
{
#if MEI_DRV_OS_BYTE_ORDER == MEI_DRV_OS_BIG_ENDIAN
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Link Number */
   IFX_uint32_t LinkNo;
   /** VCC Identifier */
   IFX_uint32_t VCC_id;
   /** Virtual Path Identifier */
   IFX_uint32_t VPI;
   /** Virtual Channel Identifier */
   IFX_uint32_t VCI;
#else
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Link Number */
   IFX_uint32_t LinkNo;
   /** VCC Identifier */
   IFX_uint32_t VCC_id;
   /** Virtual Path Identifier */
   IFX_uint32_t VPI;
   /** Virtual Channel Identifier */
   IFX_uint32_t VCI;
#endif
} __PACKED__ ;


/**
   Acknowledgement for the message CMD_Segmentation_VCC_Config.
*/
struct ACK_Segmentation_VCC_Config
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
   This command adds a classification filter to the segmentation classification table,
   up to 16 entries can be defined.
   Note: The link must be disabled before this command can be sent.
   Note: The Ethernet Forwarding Table must not be empty (see
   CMD_Segmentation_VCC_Config).
*/
struct CMD_SegmentationClassFilter_Add
{
#if MEI_DRV_OS_BYTE_ORDER == MEI_DRV_OS_BIG_ENDIAN
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Link Number */
   IFX_uint32_t LinkNo;
   /** MAC Address part 1 */
   IFX_uint32_t MAC_Address_1;
   /** MAC Address part 2 */
   IFX_uint32_t MAC_Address_2;
   /** VLAN Identifier */
   IFX_uint32_t VLAN_id;
   /** VLAN priority */
   IFX_uint32_t VLAN_prio;
   /** VCC Forwarding Identifier */
   IFX_uint32_t VCC_id;
#else
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Link Number */
   IFX_uint32_t LinkNo;
   /** MAC Address part 1 */
   IFX_uint32_t MAC_Address_1;
   /** MAC Address part 2 */
   IFX_uint32_t MAC_Address_2;
   /** VLAN Identifier */
   IFX_uint32_t VLAN_id;
   /** VLAN priority */
   IFX_uint32_t VLAN_prio;
   /** VCC Forwarding Identifier */
   IFX_uint32_t VCC_id;
#endif
} __PACKED__ ;


/**
   Acknowledgement to the message CMD_SegmentationClassFilter_Add.
*/
struct ACK_SegmentationClassFilter_Add
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
   This command adds a classification filter to the reassembly classification table,
   upto 8 entries can be defined.
   Note: The link must be disabled before this command can be sent.
*/
struct CMD_ReassemblyClassFilter_Add
{
#if MEI_DRV_OS_BYTE_ORDER == MEI_DRV_OS_BIG_ENDIAN
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Link Number */
   IFX_uint32_t LinkNo;
   /** Virtual Path Identifier */
   IFX_uint32_t VPI;
   /** Virtual Channel Identifier */
   IFX_uint32_t VCI;
#else
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Link Number */
   IFX_uint32_t LinkNo;
   /** Virtual Path Identifier */
   IFX_uint32_t VPI;
   /** Virtual Channel Identifier */
   IFX_uint32_t VCI;
#endif
} __PACKED__ ;


/**
   Acknowledgement for the message CMD_ReassemblyClassFilter_Add.
*/
struct ACK_ReassemblyClassFilter_Add
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
   Requests the mapping between the ATM-entry number (0...7) in the MAC-VPI/VCI map
   table and the VCC value.
*/
struct CMD_VCC_MappingGet
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
   Acknowledgement to a CMD_VCC_MappingGet command. Provides the mapping between the
   ATM-entry number (0...7) in the MAC-VPI/VCI map table and the VCC value.
*/
struct ACK_VCC_MappingGet
{
#if MEI_DRV_OS_BYTE_ORDER == MEI_DRV_OS_BIG_ENDIAN
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Link Number (=Bearer Channel Number) */
   IFX_uint32_t LinkNo;
   /** VCC Value for Channel 0 */
   IFX_uint32_t VCC0;
   /** VCC Value for Channel 1 */
   IFX_uint32_t VCC1;
   /** VCC Value for Channel 2 */
   IFX_uint32_t VCC2;
   /** VCC Value for Channel 3 */
   IFX_uint32_t VCC3;
   /** VCC Value for Channel 4 */
   IFX_uint32_t VCC4;
   /** VCC Value for Channel 5 */
   IFX_uint32_t VCC5;
   /** VCC Value for Channel 6 */
   IFX_uint32_t VCC6;
   /** VCC Value for Channel 7 */
   IFX_uint32_t VCC7;
#else
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Link Number (=Bearer Channel Number) */
   IFX_uint32_t LinkNo;
   /** VCC Value for Channel 0 */
   IFX_uint32_t VCC0;
   /** VCC Value for Channel 1 */
   IFX_uint32_t VCC1;
   /** VCC Value for Channel 2 */
   IFX_uint32_t VCC2;
   /** VCC Value for Channel 3 */
   IFX_uint32_t VCC3;
   /** VCC Value for Channel 4 */
   IFX_uint32_t VCC4;
   /** VCC Value for Channel 5 */
   IFX_uint32_t VCC5;
   /** VCC Value for Channel 6 */
   IFX_uint32_t VCC6;
   /** VCC Value for Channel 7 */
   IFX_uint32_t VCC7;
#endif
} __PACKED__ ;


/**
   This message enables/disables the Ethernet OAM layer. Enabling is required before
   doing any OAM configuration settings likee.g. for Insert/Extract or OAM filtering.
*/
struct CMD_EthernetOAM_Control
{
#if MEI_DRV_OS_BYTE_ORDER == MEI_DRV_OS_BIG_ENDIAN
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Link Number */
   IFX_uint32_t LinkNo;
   /** Ethernet OAM enable */
   IFX_uint32_t OAM;
#else
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Link Number */
   IFX_uint32_t LinkNo;
   /** Ethernet OAM enable */
   IFX_uint32_t OAM;
#endif
} __PACKED__ ;


/**
   Acknowledgment for message CMD_EthernetOAM_Control.
*/
struct ACK_EthernetOAM_Control
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
   This message configures the OAM operation.
   The command is to be applied locally at both xTU-C and xTU-R only after TC
   configuration. (See also Attention note at Page912).
*/
struct CMD_EthernetOAM_Configure
{
#if MEI_DRV_OS_BYTE_ORDER == MEI_DRV_OS_BIG_ENDIAN
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Link Number */
   IFX_uint32_t LinkNo;
   /** OAM PDU Size */
   IFX_uint32_t OAMPDU_Size;
   /** OAM Mode */
   IFX_uint32_t OAM_Mode;
   /** Variable Retrieval */
   IFX_uint32_t VarRetrieval;
   /** Link Events */
   IFX_uint32_t LinkEvents;
   /** OAM Loopback */
   IFX_uint32_t Loopback;
   /** Unidirectional operation */
   IFX_uint32_t UnidirOAMsend;
#else
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Link Number */
   IFX_uint32_t LinkNo;
   /** OAM PDU Size */
   IFX_uint32_t OAMPDU_Size;
   /** OAM Mode */
   IFX_uint32_t OAM_Mode;
   /** Variable Retrieval */
   IFX_uint32_t VarRetrieval;
   /** Link Events */
   IFX_uint32_t LinkEvents;
   /** OAM Loopback */
   IFX_uint32_t Loopback;
   /** Unidirectional operation */
   IFX_uint32_t UnidirOAMsend;
#endif
} __PACKED__ ;


/**
   This message acknowledges the CMD_EthernetOAM_Configure message.
*/
struct ACK_EthernetOAM_Configure
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
   The message configures Ethernet properties like MAC address of the device, the
   allowed ethernet frame sizes for each bearer and the handling of slow protocol
   frames.
   The MAC address is needed in the FW as "MAC source address" for OAM PDUs not built
   by the host like PAUSE frames (in contrary to the OAM PDUs inserted by the host IF
   which get this address from the host before insertion).
   The configurable maximum frame length defines the limit , starting at which frames
   are treated as "too long" and are counted accordingly or art discarded.)
   Background: : VLAN tags. Without :1518, tagged (simle):1522, tagged (stacked):>1522
*/
struct CMD_MAC_FrameConfigure
{
#if MEI_DRV_OS_BYTE_ORDER == MEI_DRV_OS_BIG_ENDIAN
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** MAC Address Octets 0 - 3 */
   IFX_uint32_t MacAddr_0_3;
   /** MAC Address Octets 4 - 5 */
   IFX_uint32_t MacAddr_4_5;
   /** Max Frame Size Link 0 */
   IFX_uint32_t MaxFrameSize_0;
   /** Max Frame Size Link 1 */
   IFX_uint32_t MaxFrameSize_1;
   /** Max Frame Size Link 2 */
   IFX_uint32_t MaxFrameSize_2;
   /** Enable Support of external Slow Protocol Handling */
   IFX_uint32_t ExtEthernetOAM;
#else
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** MAC Address Octets 0 - 3 */
   IFX_uint32_t MacAddr_0_3;
   /** MAC Address Octets 4 - 5 */
   IFX_uint32_t MacAddr_4_5;
   /** Max Frame Size Link 0 */
   IFX_uint32_t MaxFrameSize_0;
   /** Max Frame Size Link 1 */
   IFX_uint32_t MaxFrameSize_1;
   /** Max Frame Size Link 2 */
   IFX_uint32_t MaxFrameSize_2;
   /** Enable Support of external Slow Protocol Handling */
   IFX_uint32_t ExtEthernetOAM;
#endif
} __PACKED__ ;


/**
   Acknowledgment for message CMD_MAC_FrameConfigure.
*/
struct ACK_MAC_FrameConfigure
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
   This command enables/disables the ethernet insert/extract to the system/line side.
   The command is to be applied locally. For a hostless CPE the Insert/Extract
   operation is enabled by default.
*/
struct CMD_EthernetInsertExtractControl
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
   /** Direction */
   IFX_uint32_t direction;
#else
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Link Number */
   IFX_uint32_t LinkNo;
   /** Control */
   IFX_uint32_t Control;
   /** Direction */
   IFX_uint32_t direction;
#endif
} __PACKED__ ;


/**
   Acknowledgment for message CMD_EthernetInsertExtractControl.
*/
struct ACK_EthernetInsertExtractControl
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
   This command writes an ethernet frame or fragments of it to be inserted to the Line
   side in transmit direction.
   The length of an ethernet frame migth be longer than the mailbox size, then it is
   send via a sequence of messages.
   The frame is transmitted when the message is received with a positive fragment
   length. A frame length of 0 indicates that the data from the message is copied to
   the frame transmit buffer but the frame is not transmitted yet.
   Applicable at xTU-C and xTU-R.
   Example:
   For inserting an OAM PDU, the firmware assumes that the data fragments contain the
   following structure:
   6 Bytes: Ethernet Destination Address: 01-80-c2-00-00-02
   6 Bytes: Ethernet Source Address.
   2 Bytes: Length/Type field: 88-09 [Slow Protocols]
   1 Byte: Subtype = 0x03 [OAM]
   2 Bytes: Flags
   1 Byte: Code
   42-1496 Bytes: Data/Padding
   4 Bytes: FCS (automatically appended by Vinax)
   The FCS must not be in the data structure but is instead automatically appended. The
   first 4 bytes of the data structure which contain the length of the ethernet frame
   are not transmitted.
*/
struct CMD_EthernetFrameLineInsert
{
#if MEI_DRV_OS_BYTE_ORDER == MEI_DRV_OS_BIG_ENDIAN
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Link Number */
   IFX_uint32_t LinkNo;
   /** Fragment length */
   IFX_uint32_t FragLength;
   /** Fragment data */
   IFX_uint32_t Data[62];
#else
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Link Number */
   IFX_uint32_t LinkNo;
   /** Fragment length */
   IFX_uint32_t FragLength;
   /** Fragment data */
   IFX_uint32_t Data[62];
#endif
} __PACKED__ ;


/**
   This message acknowledges the CMD_EthernetFrameLineInsert message.
*/
struct ACK_EthernetFrameLineInsert
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
   This command writes an ethernet frame or fragments of it to be inserted to the
   system side in transmit direction.
   The length of an ethernet frame migth be longer than the mailbox size, then it is
   send via a sequence of messages.
   The frame is transmitted when the message is received with a positive fragment
   length. A frame length of 0 indicates that the all data from the message is copied
   to the frame transmit buffer but the frame is not transmitted yet.
   Applicable at xTU-C and xTU-R (with host).
   Example:
   For inserting an OAM PDU, the firmware assumes that the data fragments contain the
   following structure:
   6 Bytes: Ethernet Destination Address: 01-80-c2-00-00-02
   6 Bytes: Ethernet Source Address.
   2 Bytes: Length/Type field: 88-09 [Slow Protocols]
   1 Byte: Subtype = 0x03 [OAM]
   2 Bytes: Flags
   1 Byte: Code
   42-1496 Bytes: Data/Padding
   4 Bytes: FCS (automatically appended by Vinax)
   The FCS must not be in the data structure but is instead automatically appended. The
   first 4 bytes of the data structure which contain the length of the ethernet frame
   are not transmitted.
*/
struct CMD_EthernetFrameSysInsert
{
#if MEI_DRV_OS_BYTE_ORDER == MEI_DRV_OS_BIG_ENDIAN
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Link Number */
   IFX_uint32_t LinkNo;
   /** Fragment length */
   IFX_uint32_t FragLength;
   /** Fragment data */
   IFX_uint32_t Data[62];
#else
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Link Number */
   IFX_uint32_t LinkNo;
   /** Fragment length */
   IFX_uint32_t FragLength;
   /** Fragment data */
   IFX_uint32_t Data[62];
#endif
} __PACKED__ ;


/**
   This message acknowledges the CMD_EthernetFrameSysInsert message.
*/
struct ACK_EthernetFrameSysInsert
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
   This message configures the ethernet packet extraction filters. There are extraction
   units at system and at line side. For each side there are two programmable filters
   and 3 fixed filters for PAUSE, MAC Control and Slow Protocol frames. The fixed
   filters can only be used to discard frames. The filter units can be configured such
   that the filtered frames are extracted and copied to the mailbox or the extracted
   frames can also be discarded.
   The message is to be applied locally before CMD_EthernetInsertExtractControl! (but
   after TC configuration, see Attention note at Page922).
   At the hostless CPE the message becomes effective only if the "LAN Update Enable"
   parameter in CMD_FW_UpdateLAN_Configure was DISABLED. Otherwise
   CMD_EthernetInsertExtractControl has no effect here!
   Application example:
   Spanning Tree Protocol BPDUÕs shall not be transported from LAN to WAN. BPDUÕs can
   be identified by the ethernet multicast destination address 01-80-C2-00-00-00. In
   order to block all ethernet frames with this destination address with filter unit 1,
   the following settings have to be programmed:
   Side: System Side
   Filter1Operation: Discard
   Filter1Config: FILTER_MAC_DST_ADDRESS
   MacAddr1_0_3: 0x0180C200
   MacAddr1_4_5: 0x00000000
   AddrMask1_0_3: 0x00000000
   AddrMask1_4_5: 0x00000000
   This will extract all BPDU frames identified via the ethernet multicast address.
*/
struct CMD_EthernetExtractConfigure
{
#if MEI_DRV_OS_BYTE_ORDER == MEI_DRV_OS_BIG_ENDIAN
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Link Number */
   IFX_uint32_t LinkNo;
   /** System or Line side */
   IFX_uint32_t Side;
   /** Pause Frame Filter */
   IFX_uint32_t PauseFilter;
   /** MAC Control Frame Filter */
   IFX_uint32_t MacControlFilter;
   /** Slow Protocol Frame Filter */
   IFX_uint32_t SlowProFilter;
   /** Operation Mode Filter 1 */
   IFX_uint32_t OpModeFilter1;
   /** Operation Mode Filter 2 */
   IFX_uint32_t OpModeFilter2;
   /** Filter type selection for programmable filter 1 */
   IFX_uint32_t Filter1Config;
   /** Filter 1 MAC Address octets 0 to 3 */
   IFX_uint32_t MacAddr1_0_3;
   /** Filter 1 MAC Address octets 4 to 5 */
   IFX_uint32_t MacAddr1_4_5;
   /** Filter 1 MAC Address Mask octets 0 to 3 */
   IFX_uint32_t AddrMask1_0_3;
   /** Filter 1 MAC Address Mask octets 4 to 5 */
   IFX_uint32_t AddrMask1_4_5;
   /** Filter 1 VLAN ID */
   IFX_uint32_t VlanID_1;
   /** Filter 1 VLAN ID Mask */
   IFX_uint32_t VlanID_Mask_1;
   /** Filter 1 VLAN Priority */
   IFX_uint32_t VlanPrio_1;
   /** Filter 1 VLAN Priority Mask */
   IFX_uint32_t VlanPrioMask_1;
   /** Filter type selection for programmable filter 2 */
   IFX_uint32_t Filter2Config;
   /** Filter 2 MAC Address octets 0 to 3 */
   IFX_uint32_t MacAddr2_0_3;
   /** Filter 2 MAC Address octets 4 to 5 */
   IFX_uint32_t MacAddr2_4_5;
   /** Filter 2 MAC Address Mask octets 0 to 3 */
   IFX_uint32_t AddrMask2_0_3;
   /** Filter 2 MAC Address Mask octets 4 to 5 */
   IFX_uint32_t AddrMask2_4_5;
   /** Filter 2 VLAN ID */
   IFX_uint32_t VlanID_2;
   /** Filter 2 VLAN ID Mask */
   IFX_uint32_t VlanID_Mask_2;
   /** Filter 2 VLAN Priority */
   IFX_uint32_t VlanPrio_2;
   /** Filter 2 VLAN Priority Mask */
   IFX_uint32_t VlanPrioMask_2;
   /** OAM Filter (not for VINAX V1.X) */
   IFX_uint32_t OAMFilter;
#else
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Link Number */
   IFX_uint32_t LinkNo;
   /** System or Line side */
   IFX_uint32_t Side;
   /** Pause Frame Filter */
   IFX_uint32_t PauseFilter;
   /** MAC Control Frame Filter */
   IFX_uint32_t MacControlFilter;
   /** Slow Protocol Frame Filter */
   IFX_uint32_t SlowProFilter;
   /** Operation Mode Filter 1 */
   IFX_uint32_t OpModeFilter1;
   /** Operation Mode Filter 2 */
   IFX_uint32_t OpModeFilter2;
   /** Filter type selection for programmable filter 1 */
   IFX_uint32_t Filter1Config;
   /** Filter 1 MAC Address octets 0 to 3 */
   IFX_uint32_t MacAddr1_0_3;
   /** Filter 1 MAC Address octets 4 to 5 */
   IFX_uint32_t MacAddr1_4_5;
   /** Filter 1 MAC Address Mask octets 0 to 3 */
   IFX_uint32_t AddrMask1_0_3;
   /** Filter 1 MAC Address Mask octets 4 to 5 */
   IFX_uint32_t AddrMask1_4_5;
   /** Filter 1 VLAN ID */
   IFX_uint32_t VlanID_1;
   /** Filter 1 VLAN ID Mask */
   IFX_uint32_t VlanID_Mask_1;
   /** Filter 1 VLAN Priority */
   IFX_uint32_t VlanPrio_1;
   /** Filter 1 VLAN Priority Mask */
   IFX_uint32_t VlanPrioMask_1;
   /** Filter type selection for programmable filter 2 */
   IFX_uint32_t Filter2Config;
   /** Filter 2 MAC Address octets 0 to 3 */
   IFX_uint32_t MacAddr2_0_3;
   /** Filter 2 MAC Address octets 4 to 5 */
   IFX_uint32_t MacAddr2_4_5;
   /** Filter 2 MAC Address Mask octets 0 to 3 */
   IFX_uint32_t AddrMask2_0_3;
   /** Filter 2 MAC Address Mask octets 4 to 5 */
   IFX_uint32_t AddrMask2_4_5;
   /** Filter 2 VLAN ID */
   IFX_uint32_t VlanID_2;
   /** Filter 2 VLAN ID Mask */
   IFX_uint32_t VlanID_Mask_2;
   /** Filter 2 VLAN Priority */
   IFX_uint32_t VlanPrio_2;
   /** Filter 2 VLAN Priority Mask */
   IFX_uint32_t VlanPrioMask_2;
   /** OAM Filter (not for VINAX V1.X) */
   IFX_uint32_t OAMFilter;
#endif
} __PACKED__ ;


/**
   This message acknowledges the CMD_EthernetExtractConfigure message.
*/
struct ACK_EthernetExtractConfigure
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
   The message reads back the ethernet extraction settings in use, as configured with
   CMD_EthernetExtractConfigure.
*/
struct CMD_EthernetExtractConfigGet
{
#if MEI_DRV_OS_BYTE_ORDER == MEI_DRV_OS_BIG_ENDIAN
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Link Number */
   IFX_uint32_t LinkNo;
   /** System or Line side */
   IFX_uint32_t Side;
#else
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Link Number */
   IFX_uint32_t LinkNo;
   /** System or Line side */
   IFX_uint32_t Side;
#endif
} __PACKED__ ;


/**
   The message contains the ethernet extraction settings in use, as requested by
   CMD_EthernetExtractConfigGet.
*/
struct ACK_EthernetExtractConfigGet
{
#if MEI_DRV_OS_BYTE_ORDER == MEI_DRV_OS_BIG_ENDIAN
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Link Number */
   IFX_uint32_t LinkNo;
   /** System or Line side */
   IFX_uint32_t Side;
   /** Pause Frame Filter */
   IFX_uint32_t PauseFilter;
   /** MAC Control Frame Filter */
   IFX_uint32_t MacControlFilter;
   /** Slow Protocol Frame Filter */
   IFX_uint32_t SlowProFilter;
   /** Operation Mode Filter 1 */
   IFX_uint32_t OpModeFilter1;
   /** Operation Mode Filter 2 */
   IFX_uint32_t OpModeFilter2;
   /** Filter type selection for programmable filter 1 */
   IFX_uint32_t Filter1Config;
   /** Filter 1 MAC Address octets 0 to 3 */
   IFX_uint32_t MacAddr1_0_3;
   /** Filter 1 MAC Address octets 4 to 5 */
   IFX_uint32_t MacAddr1_4_5;
   /** Filter 1 MAC Address Mask octets 0 to 3 */
   IFX_uint32_t AddrMask1_0_3;
   /** Filter 1 MAC Address Mask octets 4 to 5 */
   IFX_uint32_t AddrMask1_4_5;
   /** Filter 1 VLAN ID */
   IFX_uint32_t VlanID_1;
   /** Filter 1 VLAN ID Mask */
   IFX_uint32_t VlanID_Mask_1;
   /** Filter 1 VLAN Priority */
   IFX_uint32_t VlanPrio_1;
   /** Filter 1 VLAN Priority Mask */
   IFX_uint32_t VlanPrioMask_1;
   /** Filter type selection for programmable filter 2 */
   IFX_uint32_t Filter2Config;
   /** Filter 2 MAC Address octets 0 to 3 */
   IFX_uint32_t MacAddr2_0_3;
   /** Filter 2 MAC Address octets 4 to 5 */
   IFX_uint32_t MacAddr2_4_5;
   /** Filter 2 MAC Address Mask octets 0 to 3 */
   IFX_uint32_t AddrMask2_0_3;
   /** Filter 2 MAC Address Mask octets 4 to 5 */
   IFX_uint32_t AddrMask2_4_5;
   /** Filter 2 VLAN ID */
   IFX_uint32_t VlanID_2;
   /** Filter 2 VLAN ID Mask */
   IFX_uint32_t VlanID_Mask_2;
   /** Filter 2 VLAN Priority */
   IFX_uint32_t VlanPrio_2;
   /** Filter 2 VLAN Priority Mask */
   IFX_uint32_t VlanPrioMask_2;
   /** OAM Filter (not for VINAX V1.X) */
   IFX_uint32_t OAMFilter;
#else
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Link Number */
   IFX_uint32_t LinkNo;
   /** System or Line side */
   IFX_uint32_t Side;
   /** Pause Frame Filter */
   IFX_uint32_t PauseFilter;
   /** MAC Control Frame Filter */
   IFX_uint32_t MacControlFilter;
   /** Slow Protocol Frame Filter */
   IFX_uint32_t SlowProFilter;
   /** Operation Mode Filter 1 */
   IFX_uint32_t OpModeFilter1;
   /** Operation Mode Filter 2 */
   IFX_uint32_t OpModeFilter2;
   /** Filter type selection for programmable filter 1 */
   IFX_uint32_t Filter1Config;
   /** Filter 1 MAC Address octets 0 to 3 */
   IFX_uint32_t MacAddr1_0_3;
   /** Filter 1 MAC Address octets 4 to 5 */
   IFX_uint32_t MacAddr1_4_5;
   /** Filter 1 MAC Address Mask octets 0 to 3 */
   IFX_uint32_t AddrMask1_0_3;
   /** Filter 1 MAC Address Mask octets 4 to 5 */
   IFX_uint32_t AddrMask1_4_5;
   /** Filter 1 VLAN ID */
   IFX_uint32_t VlanID_1;
   /** Filter 1 VLAN ID Mask */
   IFX_uint32_t VlanID_Mask_1;
   /** Filter 1 VLAN Priority */
   IFX_uint32_t VlanPrio_1;
   /** Filter 1 VLAN Priority Mask */
   IFX_uint32_t VlanPrioMask_1;
   /** Filter type selection for programmable filter 2 */
   IFX_uint32_t Filter2Config;
   /** Filter 2 MAC Address octets 0 to 3 */
   IFX_uint32_t MacAddr2_0_3;
   /** Filter 2 MAC Address octets 4 to 5 */
   IFX_uint32_t MacAddr2_4_5;
   /** Filter 2 MAC Address Mask octets 0 to 3 */
   IFX_uint32_t AddrMask2_0_3;
   /** Filter 2 MAC Address Mask octets 4 to 5 */
   IFX_uint32_t AddrMask2_4_5;
   /** Filter 2 VLAN ID */
   IFX_uint32_t VlanID_2;
   /** Filter 2 VLAN ID Mask */
   IFX_uint32_t VlanID_Mask_2;
   /** Filter 2 VLAN Priority */
   IFX_uint32_t VlanPrio_2;
   /** Filter 2 VLAN Priority Mask */
   IFX_uint32_t VlanPrioMask_2;
   /** OAM Filter (not for VINAX V1.X) */
   IFX_uint32_t OAMFilter;
#endif
} __PACKED__ ;


/**
   This event indicates the extraction of an ethernet frame from the line side in
   receive direction.
   Frames which are longer than the mailbox are transported in fragments.
   This EVT is generated at xTU-C and xTU-R with host.
*/
struct EVT_EthernetFrameLineExtract
{
#if MEI_DRV_OS_BYTE_ORDER == MEI_DRV_OS_BIG_ENDIAN
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Link Number */
   IFX_uint32_t LinkNo;
   /** Start of Frame / End of Frame Indication */
   IFX_uint32_t SOF_EOF;
   /** Length of the fragment */
   IFX_uint32_t FragLength;
   /** Filter match */
   IFX_uint32_t Filtermatch;
   /** Fragment data */
   IFX_uint32_t Data[60];
#else
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Link Number */
   IFX_uint32_t LinkNo;
   /** Start of Frame / End of Frame Indication */
   IFX_uint32_t SOF_EOF;
   /** Length of the fragment */
   IFX_uint32_t FragLength;
   /** Filter match */
   IFX_uint32_t Filtermatch;
   /** Fragment data */
   IFX_uint32_t Data[60];
#endif
} __PACKED__ ;


/**
   This event indicates the extraction of an ethernet frame from the system side in
   transmit direction.
   Frames which are longer than the mailbox are transported in fragments.
   This EVT is generated at xTU-C and xTU-R with host.
*/
struct EVT_EthernetFrameSysExtract
{
#if MEI_DRV_OS_BYTE_ORDER == MEI_DRV_OS_BIG_ENDIAN
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Link Number */
   IFX_uint32_t LinkNo;
   /** Start of Frame / End of Frame Indication */
   IFX_uint32_t SOF_EOF;
   /** Length of the fragment */
   IFX_uint32_t FragLength;
   /** Filter match */
   IFX_uint32_t Filtermatch;
   /** Fragment data */
   IFX_uint32_t Data[60];
#else
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Link Number */
   IFX_uint32_t LinkNo;
   /** Start of Frame / End of Frame Indication */
   IFX_uint32_t SOF_EOF;
   /** Length of the fragment */
   IFX_uint32_t FragLength;
   /** Filter match */
   IFX_uint32_t Filtermatch;
   /** Fragment data */
   IFX_uint32_t Data[60];
#endif
} __PACKED__ ;


/**
   The command enables/disables the ATM insert/extract processing. It is to be applied
   locally.
*/
struct CMD_AtmInsertExtractControl
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
   /** Direction */
   IFX_uint32_t direction;
   /** Extract Failure ALM Control */
   IFX_uint32_t extractFailMsg;
   /** Insert Status EVT Control */
   IFX_uint32_t insertEVT_Status;
   /** ATM QoS for VINAX-VE */
   IFX_uint32_t ATM_QoS;
#else
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Link Number */
   IFX_uint32_t LinkNo;
   /** Control */
   IFX_uint32_t Control;
   /** Direction */
   IFX_uint32_t direction;
   /** Extract Failure ALM Control */
   IFX_uint32_t extractFailMsg;
   /** Insert Status EVT Control */
   IFX_uint32_t insertEVT_Status;
   /** ATM QoS for VINAX-VE */
   IFX_uint32_t ATM_QoS;
#endif
} __PACKED__ ;


/**
   Acknowledgment for message CMD_AtmInsertExtractControl.
*/
struct ACK_AtmInsertExtractControl
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
   This command writes ATM cells to be inserted to the line side in transmit direction.
   Up to 4 ATM cells can be put into the mailbox. A "good" acknowledge
   (ACK_AtmCellLineInsert) does not indicate that the cells have been succesfully
   inserted but only that the message has been accepted by the FW. The FW accepts a
   message only if the previous insertion was completed, otherwise the
   ACK_AtmCellLineInsert indicates an error "E1H" in the functional opcode. Successful
   insertion is indicated with EVT_AtmCellLineInsertStatusGet. On receipt of it the
   next cells to be inserted can be immediately written down to the VINAX.
*/
struct CMD_AtmCellLineInsert
{
#if MEI_DRV_OS_BYTE_ORDER == MEI_DRV_OS_BIG_ENDIAN
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Link Number */
   IFX_uint32_t LinkNo;
   /** ATM Data */
   IFX_uint32_t VNX_ATMcell_t[4];
#else
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Link Number */
   IFX_uint32_t LinkNo;
   /** ATM Data */
   IFX_uint32_t VNX_ATMcell_t[4];
#endif
} __PACKED__ ;


/**
   This message acknowledges CMD_AtmCellLineInsert.
   Note: Note on the functional opcode, part of the message header and not described
   in this document (see [16] ):A "good" acknowledge (functional opcode
   5H=D2H_CMV_WRITE_REPLY) does not indicate that the cells have been
   successfully inserted but only that the message has been accepted by the
   FW. The FW accepts a message only if the previous insertion was completed,
   otherwise the ACK_AtmCellLineInsert indicates an error "E1H" in the
   functional opcode.
*/
struct ACK_AtmCellLineInsert
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
   This autonomous message reports the final status of the ATM cell insertion as
   completed or failed. It is sent only if the "Insert Status EVT Control" was enabled
   in CMD_AtmInsertExtractControl and if the ACK_AtmCellLineInsert did not indicate an
   error before. If both conditions are met, the message is generated when the ATM cell
   insertion requested with the last CMD_AtmCellLineInsert is finished (for all cells)
   or failed.
*/
struct EVT_AtmCellLineInsertStatusGet
{
#if MEI_DRV_OS_BYTE_ORDER == MEI_DRV_OS_BIG_ENDIAN
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Link Number */
   IFX_uint32_t LinkNo;
   /** Insert Status */
   IFX_uint32_t insertStatus;
#else
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Link Number */
   IFX_uint32_t LinkNo;
   /** Insert Status */
   IFX_uint32_t insertStatus;
#endif
} __PACKED__ ;


/**
   Requests the status of the ATM cell insertion for the last CMD_AtmCellLineInsert
   sent.
*/
struct CMD_AtmCellLineInsertStatusGet
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
   The message reports the status of the ATM cell insertion as requested by
   CMD_AtmCellLineInsertStatusGet.
*/
struct ACK_AtmCellLineInsertStatusGet
{
#if MEI_DRV_OS_BYTE_ORDER == MEI_DRV_OS_BIG_ENDIAN
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Link Number */
   IFX_uint32_t LinkNo;
   /** Insert Status */
   IFX_uint32_t insertStatus;
#else
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Link Number */
   IFX_uint32_t LinkNo;
   /** Insert Status */
   IFX_uint32_t insertStatus;
#endif
} __PACKED__ ;


/**
   This event indicates the extraction of ATM cells from the line side in receive
   direction and provides the data.
   ATM cells are extracted and provided to the host only if the ATM insert/extract was
   enabled with CMD_AtmInsertExtractControl. Once an extract filter matches, the cell
   will be extracted. In VINAX V1.x only OAM cells (F4 or F5) are filtered out (any of
   them) and there is no programmable filter condition at the FW-API. Up to 4 cells can
   be contained in the message, the exact number can be easily calculated from in the
   Length parameter (see below). Consecutive ATM cells start 32 bit aligned in the "ATM
   data" field.
   A loss of ATM cells to be extracted due to an extract buffer overflow is indicated
   by ALM_AtmCellExtractFailed.
   Note: For OAM cell extraction the message will usually contain 1 ATM cell only.
*/
struct EVT_AtmCellLineExtract
{
#if MEI_DRV_OS_BYTE_ORDER == MEI_DRV_OS_BIG_ENDIAN
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Link Number */
   IFX_uint32_t LinkNo;
   /** Reserved */
   IFX_uint32_t Reserved03;
   /** ATM Data */
   IFX_uint32_t VNX_ATMcell_t[4];
#else
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Link Number */
   IFX_uint32_t LinkNo;
   /** Reserved */
   IFX_uint32_t Reserved03;
   /** ATM Data */
   IFX_uint32_t VNX_ATMcell_t[4];
#endif
} __PACKED__ ;


/**
   This autonomous alarm message indicates a congestion problem in the ATM cell
   extraction and delivery process and reports the number of ATM cells that got lost
   due to a buffer overflow. It is generated only if the corresponding control in
   CMD_AtmInsertExtractControl was enabled. The message is sent only once per second
   (provided any failure ocurred).
*/
struct ALM_AtmCellExtractFailed
{
#if MEI_DRV_OS_BYTE_ORDER == MEI_DRV_OS_BIG_ENDIAN
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Link Number */
   IFX_uint32_t LinkNo;
   /** Direction */
   IFX_uint32_t direction;
   /** Cell Extract Fail Counter */
   IFX_uint32_t FailCount;
#else
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Link Number */
   IFX_uint32_t LinkNo;
   /** Direction */
   IFX_uint32_t direction;
   /** Cell Extract Fail Counter */
   IFX_uint32_t FailCount;
#endif
} __PACKED__ ;


/**
   The message requests the values of ATM insert/extract statistics counters.
*/
struct CMD_AtmInsertExtractStatsGet
{
#if MEI_DRV_OS_BYTE_ORDER == MEI_DRV_OS_BIG_ENDIAN
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Link Number */
   IFX_uint32_t LinkNo;
   /** Direction */
   IFX_uint32_t direction;
#else
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Link Number */
   IFX_uint32_t LinkNo;
   /** Direction */
   IFX_uint32_t direction;
#endif
} __PACKED__ ;


/**
   The message delivers the values of ATM insert/extract statistics counters as
   requested by CMD_AtmInsertExtractStatsGet.
*/
struct ACK_AtmInsertExtractStatsGet
{
#if MEI_DRV_OS_BYTE_ORDER == MEI_DRV_OS_BIG_ENDIAN
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Link Number */
   IFX_uint32_t LinkNo;
   /** Direction */
   IFX_uint32_t direction;
   /** Cell Extract Counter */
   IFX_uint32_t extractedCells;
   /** Cell Extract Fail Counter */
   IFX_uint32_t failExtractCells;
   /** Reserved */
   IFX_uint32_t Res06;
   /** Cell Insert Counter */
   IFX_uint32_t insertedCells;
#else
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Link Number */
   IFX_uint32_t LinkNo;
   /** Direction */
   IFX_uint32_t direction;
   /** Cell Extract Counter */
   IFX_uint32_t extractedCells;
   /** Cell Extract Fail Counter */
   IFX_uint32_t failExtractCells;
   /** Reserved */
   IFX_uint32_t Res06;
   /** Cell Insert Counter */
   IFX_uint32_t insertedCells;
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

