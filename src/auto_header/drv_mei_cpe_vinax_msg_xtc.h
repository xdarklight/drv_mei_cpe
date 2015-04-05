/******************************************************************************

                               Copyright (c) 2011
                            Lantiq Deutschland GmbH
                     Am Campeon 3; 85579 Neubiberg, Germany

  For licensing information, see the file 'LICENSE' in the root folder of
  this software module.

******************************************************************************/


#ifndef _VDSL2_FWDES_MSGXTC_V2_H_
#define _VDSL2_FWDES_MSGXTC_V2_H_

/** \file
   This chapter describes the messages used for the TC layer.
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


/** @defgroup _VDSL2_FWDES_MSGXTC_V2_ Messages for the TC Layer
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
#define  MdioFrame45_MDIO_WR  0x1
#define  MdioFrame45_MDIO_POSTREADINCADDR  0x2
#define  MdioFrame45_MDIO_RD  0x3
#define  MdioFrame45_MDIO_TA  0x2
#define  MdioFrame22_MDIO_RD  0x2
#define  MdioFrame22_MDIO_TA  0x2
#define  CMD_FlowModify_HDLC_TC  0x00000000
#define  CMD_FlowModify_EFM_TC  0x00000001
#define  CMD_FlowModify_ATM_TC  0x00000003
#define  CMD_LED_Control_LED1  0x00000000
#define  CMD_LED_Control_LED2  0x00000001
#define  CMD_LED_Control_OFF  0x00000000
#define  CMD_LED_Control_ON  0x00000001
#define  CMD_LED_Control_BLINK_SLOW  0x00000002
#define  CMD_LED_Control_BLINK_FAST  0x00000004
#define  CMD_LED_Control_TRAFFIC  0x00000003
#define  CMD_MAC_ConfigModify_10MBIT  0x00
#define  CMD_MAC_ConfigModify_100MBIT  0x01
#define  CMD_MAC_ConfigModify_HALF  0x0
#define  CMD_MAC_ConfigModify_FULL  0x1
#define  ACK_MAC_ConfigGet_10MBIT  0x00
#define  ACK_MAC_ConfigGet_100MBIT  0x01
#define  ACK_MAC_ConfigGet_HALF  0x0
#define  ACK_MAC_ConfigGet_FULL  0x1
/* ----- Constants Definition section (End) ----- */

/**
   This data structure defines a MDIO frame as used in the host messages
   CMD_MDIO_EFM_PHY_Access and ACK_MDIO_EFM_PHY_Access.
*/
typedef struct MdioFrame45 MdioFrame45_t;

/**
   This data structure defines a MDIO frame as used in the host messages
   CMD_MDIO_External_PHY_Access and ACK_MDIO_External_PHY_Access.
*/
typedef struct MdioFrame22 MdioFrame22_t;

/** Message ID for CMD_FlowModify */
#define CMD_FLOWMODIFY 0x0651

/**
   This host message is used to select the used TC.
   Note: To be applied before CMD_LinkControl in case of POSPHY/UTOPIA-interface.
*/
typedef struct CMD_FlowModify CMD_FlowModify_t;

/** Message ID for ACK_FlowModify */
#define ACK_FLOWMODIFY 0x0651

/**
   Acknowledgement to a CMD_FlowModify message.
*/
typedef struct ACK_FlowModify ACK_FlowModify_t;

/** Message ID for CMD_HW_ConfigSet */
#define CMD_HW_CONFIGSET 0x1051

/**
   The message allows to configure several VINAX specific hardware settings, which are
   related to the hardware configuration at board level (like e.g. enabling/disabling
   of certain clock outputs on general purpose I/O pins).
   The command is for use in modem state RESET.
*/
typedef struct CMD_HW_ConfigSet CMD_HW_ConfigSet_t;

/** Message ID for ACK_HW_ConfigSet */
#define ACK_HW_CONFIGSET 0x1051

/**
   Acknowledgement for the message CMD_HW_ConfigSet.
*/
typedef struct ACK_HW_ConfigSet ACK_HW_ConfigSet_t;

/** Message ID for CMD_LED_Control */
#define CMD_LED_CONTROL 0x1251

/**
   This message controls the behaviour of the LED�s which are attached to the Vinax
   device. These LED�s are used for status indication. The behaviour of the LEDs is
   individually configurable for the various modem states. The following LEDs can be
   controlled:
   VINAX V1.x: 2 LEDs per line
   LED1: connected to pin GPIO2_D.
   LED2: connected to pin SE_N.
   VINAX V2.x: 1 LED per line/port
   LED1: connected to pin GPIO0-3 (for ports 1-4)
*/
typedef struct CMD_LED_Control CMD_LED_Control_t;

/** Message ID for ACK_LED_Control */
#define ACK_LED_CONTROL 0x1251

/**
   This message acknowledges the CMD_LED_Control message.
*/
typedef struct ACK_LED_Control ACK_LED_Control_t;

/** Message ID for CMD_MDIO_EFM_PHY_Access */
#define CMD_MDIO_EFM_PHY_ACCESS 0x0051

/**
   This host message can contain up to 31 MDIO commands for the internal EFM PHY.
   Supported types of MDIO commands: clause 45 formatted commands. If the host message
   contains one or more READ or POST-READ-INCREMENT-ADDRESS commands, the acknowledge
   ACK_MDIO_EFM_PHY_Access returns the content of the selected register(s) in its
   payload.
*/
typedef struct CMD_MDIO_EFM_PHY_Access CMD_MDIO_EFM_PHY_Access_t;

/** Message ID for ACK_MDIO_EFM_PHY_Access */
#define ACK_MDIO_EFM_PHY_ACCESS 0x0051

/**
   Acknowledge to a CMD_MDIO_EFM_PHY_Access command. If the latter contained one or
   more READ or POST-READ-INCREMENT-ADDRESS commands in its payload, the acknowledge
   will contain the content of the selected register(s) in its payload in the DATA
   field. The other fields of each MDIO command are copied from the
   CMD_MDIO_EFM_PHY_Access message payload. WRITE and ADDRESS commands in the payload
   are not modified by ACK_MDIO_EFM_PHY_Access.
*/
typedef struct ACK_MDIO_EFM_PHY_Access ACK_MDIO_EFM_PHY_Access_t;

/** Message ID for CMD_MDIO_External_PHY_Access */
#define CMD_MDIO_EXTERNAL_PHY_ACCESS 0x0851

/**
   This host message can contain up to 31 MDIO clause 22 formatted commands for the
   external PHY. If the host message contains one or more READ or
   POST-READ-INCREMENT-ADDRESS commands, the acknowledge ACK_MDIO_External_PHY_Access
   returns the content of the selected register(s) in its payload.
*/
typedef struct CMD_MDIO_External_PHY_Access CMD_MDIO_External_PHY_Access_t;

/** Message ID for ACK_MDIO_External_PHY_Access */
#define ACK_MDIO_EXTERNAL_PHY_ACCESS 0x0851

/**
   Acknowledge to a CMD_MDIO_External_PHY_Access command. If the latter contained one
   or more READ or POST-READ-INCREMENT-ADDRESS commands in its payload, the acknowledge
   will contain the content of the selected register(s) in its payload in the DATA
   field. The other fields of each MDIO command are copied from the
   CMD_MDIO_External_PHY_Access message payload. WRITE and ADDRESS commands in the
   payload are not modified by ACK_MDIO_External_PHY_Access.
*/
typedef struct ACK_MDIO_External_PHY_Access ACK_MDIO_External_PHY_Access_t;

/** Message ID for CMD_MAC_ConfigModify */
#define CMD_MAC_CONFIGMODIFY 0x1351

/**
   This message is used to modify the MAC related TC configuration settings in
   STEADY_STATE. For writing them in RESET state, use the command
   CMD_MDIO_EFM_PHY_Access.
*/
typedef struct CMD_MAC_ConfigModify CMD_MAC_ConfigModify_t;

/** Message ID for ACK_MAC_ConfigModify */
#define ACK_MAC_CONFIGMODIFY 0x1351

/**
   This message acknowledges the message CMD_MAC_ConfigModify.
*/
typedef struct ACK_MAC_ConfigModify ACK_MAC_ConfigModify_t;

/** Message ID for CMD_MAC_ConfigGet */
#define CMD_MAC_CONFIGGET 0x1411

/**
   Reads the MAC related TC configuration settings in STEADY_STATE. For reading them in
   RESET state, use the command CMD_MDIO_EFM_PHY_Access.
*/
typedef struct CMD_MAC_ConfigGet CMD_MAC_ConfigGet_t;

/** Message ID for ACK_MAC_ConfigGet */
#define ACK_MAC_CONFIGGET 0x1411

/**
   The message delivers the data requested by ACK_MAC_ConfigGet.
   For STEADY_STATE only!
*/
typedef struct ACK_MAC_ConfigGet ACK_MAC_ConfigGet_t;

/** Message ID for CMD_PHY_AddressSet */
#define CMD_PHY_ADDRESSSET 0x1551

/**
   This message configures the PHY address of the external Ethernet PHY. (For MAC-Mode
   only).
*/
typedef struct CMD_PHY_AddressSet CMD_PHY_AddressSet_t;

/** Message ID for ACK_PHY_AddressSet */
#define ACK_PHY_ADDRESSSET 0x1551

/**
   This message acknowledges the message CMD_PHY_AddressSet.
*/
typedef struct ACK_PHY_AddressSet ACK_PHY_AddressSet_t;

/**
   This data structure defines a MDIO frame as used in the host messages
   CMD_MDIO_EFM_PHY_Access and ACK_MDIO_EFM_PHY_Access.
*/
struct MdioFrame45
{
#if MEI_DRV_OS_BYTE_ORDER == MEI_DRV_OS_BIG_ENDIAN
   /** Start of Frame */
   IFX_uint32_t ST : 2;
   /** Operation code */
   IFX_uint32_t OP : 2;
   /** Port Address */
   IFX_uint32_t PRTAD : 5;
   /** Device Address */
   IFX_uint32_t DEVAD : 5;
   /** Turn-around bits */
   IFX_uint32_t TA : 2;
   /** Data Field */
   IFX_uint32_t DATA : 16;
#else
   /** Data Field */
   IFX_uint32_t DATA : 16;
   /** Turn-around bits */
   IFX_uint32_t TA : 2;
   /** Device Address */
   IFX_uint32_t DEVAD : 5;
   /** Port Address */
   IFX_uint32_t PRTAD : 5;
   /** Operation code */
   IFX_uint32_t OP : 2;
   /** Start of Frame */
   IFX_uint32_t ST : 2;
#endif
} __PACKED__ ;


/**
   This data structure defines a MDIO frame as used in the host messages
   CMD_MDIO_External_PHY_Access and ACK_MDIO_External_PHY_Access.
*/
struct MdioFrame22
{
#if MEI_DRV_OS_BYTE_ORDER == MEI_DRV_OS_BIG_ENDIAN
   /** Start of Frame */
   IFX_uint32_t ST : 2;
   /** Operation code */
   IFX_uint32_t OP : 2;
   /** PHY Address */
   IFX_uint32_t PHYAD : 5;
   /** Register Address */
   IFX_uint32_t REGAD : 5;
   /** Turn-around bits */
   IFX_uint32_t TA : 2;
   /** Data Field */
   IFX_uint32_t DATA : 16;
#else
   /** Data Field */
   IFX_uint32_t DATA : 16;
   /** Turn-around bits */
   IFX_uint32_t TA : 2;
   /** Register Address */
   IFX_uint32_t REGAD : 5;
   /** PHY Address */
   IFX_uint32_t PHYAD : 5;
   /** Operation code */
   IFX_uint32_t OP : 2;
   /** Start of Frame */
   IFX_uint32_t ST : 2;
#endif
} __PACKED__ ;


/**
   This host message is used to select the used TC.
   Note: To be applied before CMD_LinkControl in case of POSPHY/UTOPIA-interface.
*/
struct CMD_FlowModify
{
#if MEI_DRV_OS_BYTE_ORDER == MEI_DRV_OS_BIG_ENDIAN
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** TC Selection */
   IFX_uint32_t TC;
#else
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** TC Selection */
   IFX_uint32_t TC;
#endif
} __PACKED__ ;


/**
   Acknowledgement to a CMD_FlowModify message.
*/
struct ACK_FlowModify
{
#if MEI_DRV_OS_BYTE_ORDER == MEI_DRV_OS_BIG_ENDIAN
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
#else
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
#endif
} __PACKED__ ;


/**
   The message allows to configure several VINAX specific hardware settings, which are
   related to the hardware configuration at board level (like e.g. enabling/disabling
   of certain clock outputs on general purpose I/O pins).
   The command is for use in modem state RESET.
*/
struct CMD_HW_ConfigSet
{
#if MEI_DRV_OS_BYTE_ORDER == MEI_DRV_OS_BIG_ENDIAN
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** DFE clock out CLKO2 */
   IFX_uint32_t CLKO2;
   /** DFE clock out CLKO1 */
   IFX_uint32_t CLKO1;
   /** Status LEDs */
   IFX_uint32_t LED_Status;
#else
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** DFE clock out CLKO2 */
   IFX_uint32_t CLKO2;
   /** DFE clock out CLKO1 */
   IFX_uint32_t CLKO1;
   /** Status LEDs */
   IFX_uint32_t LED_Status;
#endif
} __PACKED__ ;


/**
   Acknowledgement for the message CMD_HW_ConfigSet.
*/
struct ACK_HW_ConfigSet
{
#if MEI_DRV_OS_BYTE_ORDER == MEI_DRV_OS_BIG_ENDIAN
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
#else
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
#endif
} __PACKED__ ;


/**
   This message controls the behaviour of the LED�s which are attached to the Vinax
   device. These LED�s are used for status indication. The behaviour of the LEDs is
   individually configurable for the various modem states. The following LEDs can be
   controlled:
   VINAX V1.x: 2 LEDs per line
   LED1: connected to pin GPIO2_D.
   LED2: connected to pin SE_N.
   VINAX V2.x: 1 LED per line/port
   LED1: connected to pin GPIO0-3 (for ports 1-4)
*/
struct CMD_LED_Control
{
#if MEI_DRV_OS_BYTE_ORDER == MEI_DRV_OS_BIG_ENDIAN
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** LED number */
   IFX_uint32_t led;
   /** RESET State LED Control */
   IFX_uint32_t LED_RESET;
   /** Handshake/Full Init State LED Control */
   IFX_uint32_t LED_GHS_INIT;
   /** Showtime LED Control */
   IFX_uint32_t LED_Showtime;
   /** FAIL State LED Control */
   IFX_uint32_t LED_FAIL;
   /** Reserved */
   IFX_uint32_t Res07;
   /** LED Firmware Update Control */
   IFX_uint32_t LED_Firmware;
   /** READY State LED Control */
   IFX_uint32_t LED_READY;
#else
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** LED number */
   IFX_uint32_t led;
   /** RESET State LED Control */
   IFX_uint32_t LED_RESET;
   /** Handshake/Full Init State LED Control */
   IFX_uint32_t LED_GHS_INIT;
   /** Showtime LED Control */
   IFX_uint32_t LED_Showtime;
   /** FAIL State LED Control */
   IFX_uint32_t LED_FAIL;
   /** Reserved */
   IFX_uint32_t Res07;
   /** LED Firmware Update Control */
   IFX_uint32_t LED_Firmware;
   /** READY State LED Control */
   IFX_uint32_t LED_READY;
#endif
} __PACKED__ ;


/**
   This message acknowledges the CMD_LED_Control message.
*/
struct ACK_LED_Control
{
#if MEI_DRV_OS_BYTE_ORDER == MEI_DRV_OS_BIG_ENDIAN
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
#else
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
#endif
} __PACKED__ ;


/**
   This host message can contain up to 31 MDIO commands for the internal EFM PHY.
   Supported types of MDIO commands: clause 45 formatted commands. If the host message
   contains one or more READ or POST-READ-INCREMENT-ADDRESS commands, the acknowledge
   ACK_MDIO_EFM_PHY_Access returns the content of the selected register(s) in its
   payload.
*/
struct CMD_MDIO_EFM_PHY_Access
{
#if MEI_DRV_OS_BYTE_ORDER == MEI_DRV_OS_BIG_ENDIAN
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** MDIO Command */
   IFX_uint32_t MDIO_Cmd[31];
#else
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** MDIO Command */
   IFX_uint32_t MDIO_Cmd[31];
#endif
} __PACKED__ ;


/**
   Acknowledge to a CMD_MDIO_EFM_PHY_Access command. If the latter contained one or
   more READ or POST-READ-INCREMENT-ADDRESS commands in its payload, the acknowledge
   will contain the content of the selected register(s) in its payload in the DATA
   field. The other fields of each MDIO command are copied from the
   CMD_MDIO_EFM_PHY_Access message payload. WRITE and ADDRESS commands in the payload
   are not modified by ACK_MDIO_EFM_PHY_Access.
*/
struct ACK_MDIO_EFM_PHY_Access
{
#if MEI_DRV_OS_BYTE_ORDER == MEI_DRV_OS_BIG_ENDIAN
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** MDIO Command */
   IFX_uint32_t MDIO_Cmd[31];
#else
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** MDIO Command */
   IFX_uint32_t MDIO_Cmd[31];
#endif
} __PACKED__ ;


/**
   This host message can contain up to 31 MDIO clause 22 formatted commands for the
   external PHY. If the host message contains one or more READ or
   POST-READ-INCREMENT-ADDRESS commands, the acknowledge ACK_MDIO_External_PHY_Access
   returns the content of the selected register(s) in its payload.
*/
struct CMD_MDIO_External_PHY_Access
{
#if MEI_DRV_OS_BYTE_ORDER == MEI_DRV_OS_BIG_ENDIAN
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** MDIO Command */
   IFX_uint32_t MDIO_Cmd[31];
#else
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** MDIO Command */
   IFX_uint32_t MDIO_Cmd[31];
#endif
} __PACKED__ ;


/**
   Acknowledge to a CMD_MDIO_External_PHY_Access command. If the latter contained one
   or more READ or POST-READ-INCREMENT-ADDRESS commands in its payload, the acknowledge
   will contain the content of the selected register(s) in its payload in the DATA
   field. The other fields of each MDIO command are copied from the
   CMD_MDIO_External_PHY_Access message payload. WRITE and ADDRESS commands in the
   payload are not modified by ACK_MDIO_External_PHY_Access.
*/
struct ACK_MDIO_External_PHY_Access
{
#if MEI_DRV_OS_BYTE_ORDER == MEI_DRV_OS_BIG_ENDIAN
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** MDIO Command */
   IFX_uint32_t MDIO_Cmd[31];
#else
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** MDIO Command */
   IFX_uint32_t MDIO_Cmd[31];
#endif
} __PACKED__ ;


/**
   This message is used to modify the MAC related TC configuration settings in
   STEADY_STATE. For writing them in RESET state, use the command
   CMD_MDIO_EFM_PHY_Access.
*/
struct CMD_MAC_ConfigModify
{
#if MEI_DRV_OS_BYTE_ORDER == MEI_DRV_OS_BIG_ENDIAN
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Autonegotiation */
   IFX_uint32_t AutoNeg;
   /** Flow Control */
   IFX_uint32_t FlowControl;
   /** Speed */
   IFX_uint32_t Speed;
   /** Duplex Mode */
   IFX_uint32_t DuplexMode;
#else
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Autonegotiation */
   IFX_uint32_t AutoNeg;
   /** Flow Control */
   IFX_uint32_t FlowControl;
   /** Speed */
   IFX_uint32_t Speed;
   /** Duplex Mode */
   IFX_uint32_t DuplexMode;
#endif
} __PACKED__ ;


/**
   This message acknowledges the message CMD_MAC_ConfigModify.
*/
struct ACK_MAC_ConfigModify
{
#if MEI_DRV_OS_BYTE_ORDER == MEI_DRV_OS_BIG_ENDIAN
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
#else
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
#endif
} __PACKED__ ;


/**
   Reads the MAC related TC configuration settings in STEADY_STATE. For reading them in
   RESET state, use the command CMD_MDIO_EFM_PHY_Access.
*/
struct CMD_MAC_ConfigGet
{
#if MEI_DRV_OS_BYTE_ORDER == MEI_DRV_OS_BIG_ENDIAN
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
#else
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
#endif
} __PACKED__ ;


/**
   The message delivers the data requested by ACK_MAC_ConfigGet.
   For STEADY_STATE only!
*/
struct ACK_MAC_ConfigGet
{
#if MEI_DRV_OS_BYTE_ORDER == MEI_DRV_OS_BIG_ENDIAN
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Auto-Negotiation */
   IFX_uint32_t AutoNeg;
   /** Flow Control */
   IFX_uint32_t FlowControl;
   /** Speed */
   IFX_uint32_t speed;
   /** Duplex Mode */
   IFX_uint32_t DuplexMode;
#else
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Auto-Negotiation */
   IFX_uint32_t AutoNeg;
   /** Flow Control */
   IFX_uint32_t FlowControl;
   /** Speed */
   IFX_uint32_t speed;
   /** Duplex Mode */
   IFX_uint32_t DuplexMode;
#endif
} __PACKED__ ;


/**
   This message configures the PHY address of the external Ethernet PHY. (For MAC-Mode
   only).
*/
struct CMD_PHY_AddressSet
{
#if MEI_DRV_OS_BYTE_ORDER == MEI_DRV_OS_BIG_ENDIAN
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** Reserved */
   IFX_uint32_t Res02 : 27;
   /** PHY Address */
   IFX_uint32_t PhyAddr : 5;
#else
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
   /** PHY Address */
   IFX_uint32_t PhyAddr : 5;
   /** Reserved */
   IFX_uint32_t Res02 : 27;
#endif
} __PACKED__ ;


/**
   This message acknowledges the message CMD_PHY_AddressSet.
*/
struct ACK_PHY_AddressSet
{
#if MEI_DRV_OS_BYTE_ORDER == MEI_DRV_OS_BIG_ENDIAN
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
#else
   /** Index */
   IFX_uint16_t Index;
   /** Length */
   IFX_uint16_t Length;
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

