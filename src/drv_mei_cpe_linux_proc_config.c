/******************************************************************************

                               Copyright (c) 2011
                            Lantiq Deutschland GmbH
                     Am Campeon 3; 85579 Neubiberg, Germany

  For licensing information, see the file 'LICENSE' in the root folder of
  this software module.

******************************************************************************/

/* ==========================================================================
   !!! Attention Attention Attention Attention Attention !!!

   gcc version 3.3.6 and 3.4.6
   ===========================
   For the following source code the compiler generate floating point obj-code:

   >> unsigned int meiDmyCnt[2] = {0xFFFFFFFF, 0xFFFFFFFF};
   >> MEI_GetDigitArray((char *)pArg, meiDmyCnt, 2);

   !!! this will lead to a KERNEL crash because floating point is not allowed
       within kernel space.

   ==> DO NOT REDUCE THE ARRAY TO "unsigned int meiDmyCnt[2]"
   ========================================================================== */


/* ==========================================================================
   Description : Linux proc fs config read write part
   ========================================================================== */

#ifdef LINUX

/* ==========================================================================
   Includes
   ========================================================================== */

/* get at first the driver configuration */
#include "drv_mei_cpe_config.h"

#include "ifx_types.h"
#include "drv_mei_cpe_os.h"

#ifdef __KERNEL__
   #include <linux/kernel.h>
#endif

#include <linux/module.h>
#include <linux/version.h>
#include <linux/init.h>
#include <linux/ctype.h>
#include <linux/ioport.h>
#include <linux/irq.h>
#include <asm/io.h>

#ifdef CONFIG_DEVFS_FS
#include <linux/devfs_fs_kernel.h>
#endif /* CONFIG_DEVFS_FS */

#if CONFIG_PROC_FS
#include <linux/proc_fs.h>
#endif


#if (LINUX_VERSION_CODE >= KERNEL_VERSION(2,6,0))
   #undef CONFIG_DEVFS_FS
#endif


/* add VINAX debug/printout part */
#include "drv_mei_cpe_dbg.h"
#include "drv_mei_cpe_dbg_driver.h"

#include "drv_mei_cpe_api.h"
#include "drv_mei_cpe_mei_interface.h"

#if (MEI_SUPPORT_ROM_CODE == 1)
#include "drv_mei_cpe_rom_handler_if.h"
#endif

#if (MEI_SUPPORT_DRV_MODEM_TESTS == 1)
#include "drv_mei_cpe_modem_test.h"
#endif


#if CONFIG_PROC_FS

/* ==========================================================================
   Configuration via proc file system is supported
*/
#if (MEI_SUPPORT_PROCFS_CONFIG == 1)

#include "drv_mei_cpe_linux_proc_config.h"

/* ==========================================================================
   procfs config Function Declaration
   ========================================================================== */

static unsigned long MEI_GetDigitValue(char *pArg, int base);
static int MEI_GetDigitArray( char *pArgList,
                                unsigned int *pArray,
                                unsigned int maxCount,
                                int          base);

#if (MEI_DEBUG_PRINT == 1)
static int MEI_ProcWriteConfigGlobalDbgConfig(char *pArg);
static int MEI_ProcReadConfigGlobalDbgConfig(char *pPage);
#endif      /* #if (MEI_DEBUG_PRINT == 1) */

static int MEI_ProcReadConfig( char *page, char **start,
                                 off_t off, int count,
                                 int *eof, void *data);

static int MEI_ProcWriteConfig( struct file *file,
                                  const char *buffer,
                                  unsigned long count,
                                  void *data);

static int MEI_ProcWriteConfigLog(char *pArg);
static int MEI_ProcReadConfigLog(char *pPage);

static int MEI_ProcWriteConfigTrace(char *pArg);
static int MEI_ProcReadConfigTrace(char *pPage);

static int MEI_ProcWriteConfigLogMei(char *pArg);
static int MEI_ProcReadConfigLogMei(char *pPage);

static int MEI_ProcWriteConfigTraceMei(char *pArg);
static int MEI_ProcReadConfigTraceMei(char *pPage);

static int MEI_ProcWriteConfigMailboxME2ARC(char *pArg);
static int MEI_ProcReadConfigMailboxME2ARC(char *pPage);

static int MEI_ProcWriteConfigMailboxARC2ME(char *pArg);
static int MEI_ProcReadConfigMailboxARC2ME(char *pPage);

#if (MEI_SUPPORT_ROM_CODE == 1)

static int MEI_ProcWriteConfigTraceRom(char *pArg);
static int MEI_ProcReadConfigTraceRom(char *pPage);

#endif

static int MEI_ProcReadConfigBlockTimeout(char *pPage);
static int MEI_ProcWriteConfigBlockTimeout(char *pArg);

static int MEI_ProcReadConfigMaxWaitModemOnline(char *pPage);
static int MEI_ProcWriteConfigMaxWaitModemOnline(char *pArg);

static int MEI_ProcReadConfigMaxWaitDfeResp(char *pPage);
static int MEI_ProcWriteConfigMaxWaitDfeResp(char *pArg);

#if (MEI_SUPPORT_DEVICE_VINAX == 1)
static int MEI_ProcWriteConfigBootMode(char *pArg);
static int MEI_ProcReadConfigBootMode(char *pPage);
#endif /* #if (MEI_SUPPORT_DEVICE_VINAX == 1)*/

#if (MEI_SUPPORT_VDSL2_ADSL_SWAP == 1)
static int MEI_ProcWriteConfigFwSelect(char *pArg);
static int MEI_ProcReadConfigFwSelect(char *pPage);
#endif

#if ( (MEI_MSG_DUMP_ENABLE == 1) && (MEI_DEBUG_PRINT == 1) )
static int MEI_ProcWriteConfigMsgDumpEnable(char *pArg);
static int MEI_ProcReadConfigMsgDumpEnable(char *pPage);

static int MEI_ProcWriteConfigMsgDumpId(char *pArg);
static int MEI_ProcReadConfigMsgDumpId(char *pPage);
#endif

#if (MEI_EXT_MEI_ACCESS_ADD_CSE_MIPS == 1) || (MEI_EXT_MEI_ACCESS_ADD_CSE == 1)
static int MEI_ProcWriteConfigMeiAccCse(char *pArg);
static int MEI_ProcReadConfigMeiAccCse(char *pPage);
#endif

#if (MEI_SUPPORT_DRV_MODEM_TESTS == 1)
static int MEI_ProcWriteConfigDTestCntrl(char *pArg);
static int MEI_ProcReadConfigDTestCntrl(char *pPage);
#endif

static int MEI_ProcWriteConfigFsmSetPreAct(char *pArg);
static int MEI_ProcReadConfigFsmSetPreAct(char *pPage);



/* ==========================================================================
   Local variables
   ========================================================================== */

/* config proc dir entry */
static struct proc_dir_entry *MEI_ProcConfigFile;

#undef NO_SEPARATOR
#define NO_SEPARATOR

#undef SEPARATOR
#define SEPARATOR ,

#undef GET_FIELD_2
#define GET_FIELD_2(y,z,sep) z sep

/**
   Contains the procfs configuration.
*/
static MEI_CONFIG_PROC_ENTRY_T arrVinaxDfeProcFsConfigTable[e_PROCFS_CONFIG_LAST + 1] =
{
   MEI_PROCFS_CONFIG_TABLE
};


/* ==========================================================================
   procfs config Function Definitions
   ========================================================================== */
/**
   get the digit value from the argument.
*/
static unsigned long MEI_GetDigitValue(char *pArg, int base)
{
   unsigned long ulVal = 0;
   char *end, *pStart = pArg;

   /* skip space */
   while(*pStart != '\0')
   {
      if (isdigit(*pStart))
      {
         break;
      }
      pStart++;
   }

   ulVal = simple_strtoul(pStart, &end, base);

   return ulVal;
}

/**
   get the digit values from the argument list.
*/
static int MEI_GetDigitArray( char *pArgList,
                                unsigned int *pArray,
                                unsigned int maxCount,
                                int          base)
{
   char           *pCurrArg, *pNextArg;
   unsigned int   count = 0;

   pCurrArg = (char *)pArgList;

   if (pCurrArg == NULL)
   {
      PRN_DBG_USR_NL( MEI_DRV, MEI_DRV_PRN_LEVEL_HIGH,
            ("MEI_DRV: ERROR - scan array, missing arg" MEI_DRV_CRLF));
      return 0;
   }

   if (pArray == NULL)
   {
      PRN_DBG_USR_NL( MEI_DRV, MEI_DRV_PRN_LEVEL_HIGH,
            ("MEI_DRV: ERROR - scan array, missing return param" MEI_DRV_CRLF));
      return 0;
   }

   /* remove leading spaces */
   while ( (strlen(pCurrArg)) && (isspace(*pCurrArg)) )
   {
      pCurrArg++;
   }

   pNextArg = pCurrArg;

   while (count < maxCount)
   {
      /* search end of first arg */
      while (strlen(pNextArg) && !(isspace(*pNextArg)) )
      {
         pNextArg++;
      }

      if (strlen(pNextArg) > 0)
      {
         /* terminate first arg if not last one */
         *pNextArg = '\0';
         pNextArg++;
      }

      if (strlen(pCurrArg))
      {
         pArray[count] = MEI_GetDigitValue(pCurrArg, base);
         count++;
      }
      else
      {
         break;
      }

      /* search begin of next arg */
      while (strlen(pNextArg) && isspace(*pNextArg) )
      {
         pNextArg++;
      }

      pCurrArg = pNextArg;
   }

   return count;
}

#if (MEI_DEBUG_PRINT == 1)
/**
   Handle procfs config - write global debug level for int and usr direction.

   1. arg: debug level for user direction
   2. arg: debug level for interrupt direction
*/
static int MEI_ProcWriteConfigGlobalDbgConfig(char *pArg)
{
   int i;
   unsigned int glDbgLevelCntrl[7] = {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF,
                                      0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF};

   if (pArg == NULL)
   {
      PRN_ERR_USR_NL( MEI_DRV, MEI_DRV_PRN_LEVEL_ERR,
            ("MEI_DRV: Global Debug Level - missing args" MEI_DRV_CRLF));
      return 0;
   }

   MEI_GetDigitArray(pArg, glDbgLevelCntrl, 7, 16);

   if ( (glDbgLevelCntrl[0]>=MEI_DRV_PRN_LEVEL_LOW) &&
        (glDbgLevelCntrl[0]<=MEI_DRV_PRN_LEVEL_OFF) )
   {
      MEI_DRVOS_GDBG_USR_LEVEL_SET(glDbgLevelCntrl[0]);
   }

   if ( (glDbgLevelCntrl[1]>=MEI_DRV_PRN_LEVEL_LOW) &&
        (glDbgLevelCntrl[1]<=MEI_DRV_PRN_LEVEL_OFF) )
   {
      MEI_DRVOS_GDBG_INT_LEVEL_SET(glDbgLevelCntrl[1]);
   }

   if (glDbgLevelCntrl[2] != 0xFFFFFFFF)
   {
      MEI_DRV_PRN_DEBUG_CONTROL_SET((IFX_uint32_t)glDbgLevelCntrl[2]);
   }

   for (i=0; i<4; i++)
   {
      if (glDbgLevelCntrl[3+i] != 0xFFFFFFFF)
      {
         MEI_DRV_PRN_DEBUG_CONTROL_MASK_SET(i, (IFX_uint32_t)glDbgLevelCntrl[3+i])
      }
   }

   return 0;
}


/**
   Handle procfs config - read global debug level for int and usr direction.
*/
static int MEI_ProcReadConfigGlobalDbgConfig(char *pPage)
{
   return (sprintf( pPage, "%2d: %s \tT = %d L = %d \tCnt = 0x%X, Mask[0..3] = 0x%X 0x%X 0x%X 0x%X" MEI_DRV_CRLF,
                    e_PROCFS_CONFIG_G_DBG_CONFIG,
                    arrVinaxDfeProcFsConfigTable[e_PROCFS_CONFIG_G_DBG_CONFIG].pName,
                    MEI_DRVOS_GDBG_USR_LEVEL_GET(),
                    MEI_DRVOS_GDBG_INT_LEVEL_GET(),
                    MEI_DRV_PRN_DEBUG_CONTROL_GET(),
                    MEI_DRV_PRN_DEBUG_CONTROL_MASK_GET(0),
                    MEI_DRV_PRN_DEBUG_CONTROL_MASK_GET(1),
                    MEI_DRV_PRN_DEBUG_CONTROL_MASK_GET(2),
                    MEI_DRV_PRN_DEBUG_CONTROL_MASK_GET(3) ));
}
#endif      /* #if (MEI_DEBUG_PRINT == 1) */

/**
   Handle procfs config - set LOG configuration.
*/
static int MEI_ProcWriteConfigLog(char *pArg)
{
   unsigned long level;

   level = (IFX_int32_t)MEI_GetDigitValue(pArg, 0);

   if ( (level>=MEI_DRV_PRN_LEVEL_LOW) &&  (level<=MEI_DRV_PRN_LEVEL_OFF) )
   {
      MEI_DRV_PRN_INT_LEVEL_SET(MEI_DRV, level);
   }
   else
   {
      PRN_DBG_USR_NL( MEI_DRV, MEI_DRV_PRN_LEVEL_HIGH,
            ("MEI_DRV: config entry TRACE: arg %s --> level (%d) invalid" MEI_DRV_CRLF,
             (char *)pArg, (int)level));
   }

   return 0;
}

/**
   Handle procfs config - set LOG configuration.
*/
static int MEI_ProcReadConfigLog(char *pPage)
{
   return (sprintf( pPage, "%2d: %s \t= %2d" MEI_DRV_CRLF,
                    e_PROCFS_CONFIG_LOG,
                    arrVinaxDfeProcFsConfigTable[e_PROCFS_CONFIG_LOG].pName,
                    MEI_DRV_PRN_INT_LEVEL_GET(MEI_DRV)) );
}


/**
   Handle procfs config - set TRACE configuration.
*/
static int MEI_ProcWriteConfigTrace(char *pArg)
{
   unsigned long level;

   level = (IFX_int32_t)MEI_GetDigitValue(pArg, 0);

   if ( (level>=MEI_DRV_PRN_LEVEL_LOW) &&  (level<=MEI_DRV_PRN_LEVEL_OFF) )
   {
      MEI_DRV_PRN_USR_LEVEL_SET(MEI_DRV, level);
   }
   else
   {
      PRN_DBG_USR_NL( MEI_DRV, MEI_DRV_PRN_LEVEL_HIGH,
            ("MEI_DRV: config entry TRACE: arg %s --> level (%d) invalid" MEI_DRV_CRLF,
             (char *)pArg, (int)level));
   }

   return 0;
}


/**
   Handle procfs config - set TRACE configuration.
*/
static int MEI_ProcReadConfigTrace(char *pPage)
{
   return (sprintf( pPage, "%2d: %s \t= %2d" MEI_DRV_CRLF,
                    e_PROCFS_CONFIG_TRACE,
                    arrVinaxDfeProcFsConfigTable[e_PROCFS_CONFIG_TRACE].pName,
                    MEI_DRV_PRN_USR_LEVEL_GET(MEI_DRV)));
}


/**
   Handle procfs config - set TRACE configuration.
*/
static int MEI_ProcWriteConfigLogMei(char *pArg)
{
   unsigned long level;

   level = (IFX_int32_t)MEI_GetDigitValue(pArg, 0);

   if ( (level>=MEI_DRV_PRN_LEVEL_LOW) &&  (level<=MEI_DRV_PRN_LEVEL_OFF) )
   {
      MEI_DRV_PRN_INT_LEVEL_SET(MEI_MEI_ACCESS, level);
   }
   else
   {
      PRN_DBG_USR_NL( MEI_DRV, MEI_DRV_PRN_LEVEL_HIGH,
            ("MEI_DRV: config entry Log MEI: arg %s --> level (%d) invalid" MEI_DRV_CRLF,
             (char *)pArg, (int)level));
   }

   return 0;
}


/**
   Handle procfs config - set TRACE configuration.
*/
static int MEI_ProcReadConfigLogMei(char *pPage)
{
   return (sprintf( pPage, "%2d: %s \t= %2d" MEI_DRV_CRLF,
                    e_PROCFS_CONFIG_LOG_MEI,
                    arrVinaxDfeProcFsConfigTable[e_PROCFS_CONFIG_LOG_MEI].pName,
                    MEI_DRV_PRN_INT_LEVEL_GET(MEI_MEI_ACCESS)));
}


/**
   Handle procfs config - set TRACE configuration.
*/
static int MEI_ProcWriteConfigTraceMei(char *pArg)
{
   unsigned long level;

   level = (IFX_int32_t)MEI_GetDigitValue(pArg, 0);

   if ( (level>=MEI_DRV_PRN_LEVEL_LOW) &&  (level<=MEI_DRV_PRN_LEVEL_OFF) )
   {
      MEI_DRV_PRN_USR_LEVEL_SET(MEI_MEI_ACCESS, level);
   }
   else
   {
      PRN_DBG_USR_NL( MEI_DRV, MEI_DRV_PRN_LEVEL_HIGH,
            ("MEI_DRV: config entry TRACE MEI: arg %s --> level (%d) invalid" MEI_DRV_CRLF,
             (char *)pArg, (int)level));
   }

   return 0;
}


/**
   Handle procfs config - set TRACE configuration.
*/
static int MEI_ProcReadConfigTraceMei(char *pPage)
{
   return (sprintf( pPage, "%2d: %s \t= %2d" MEI_DRV_CRLF,
                    e_PROCFS_CONFIG_TRACE_MEI,
                    arrVinaxDfeProcFsConfigTable[e_PROCFS_CONFIG_TRACE_MEI].pName,
                    MEI_DRV_PRN_USR_LEVEL_GET(MEI_MEI_ACCESS)));
}


/**
   Handle procfs config - set mailbox addr ME2ARC.
*/
static int MEI_ProcWriteConfigMailboxME2ARC(char *pArg)
{
   unsigned long addr = 0;

   addr = (IFX_int32_t)MEI_GetDigitValue(pArg, 16);

   MEI_MailboxBase_ME2ARC = addr;

   return 0;
}


/**
   Handle procfs config - read  mailbox addr ME2ARC.
*/
static int MEI_ProcReadConfigMailboxME2ARC(char *pPage)
{
   return (sprintf( pPage, "%2d: %s \t= 0x%08X" MEI_DRV_CRLF,
                    e_PROCFS_CONFIG_MB_ME2ARC,
                    arrVinaxDfeProcFsConfigTable[e_PROCFS_CONFIG_MB_ME2ARC].pName,
                    MEI_MailboxBase_ME2ARC));
}


/**
   Handle procfs config - set mailbox addr ARC2ME.
*/
static int MEI_ProcWriteConfigMailboxARC2ME(char *pArg)
{
   unsigned long addr = 0;

   addr = (IFX_int32_t)MEI_GetDigitValue(pArg, 16);

   MEI_MailboxBase_ARC2ME = addr;

   return 0;
}


/**
   Handle procfs config - read  mailbox addr ARC2ME.
*/
static int MEI_ProcReadConfigMailboxARC2ME(char *pPage)
{
   return (sprintf( pPage, "%2d: %s \t= 0x%08X" MEI_DRV_CRLF,
                    e_PROCFS_CONFIG_MB_ARC2ME,
                    arrVinaxDfeProcFsConfigTable[e_PROCFS_CONFIG_MB_ARC2ME].pName,
                    MEI_MailboxBase_ARC2ME));
}


#if (MEI_SUPPORT_ROM_CODE == 1)

/**
   Handle procfs config - set TRACE configuration.
*/
static int MEI_ProcWriteConfigTraceRom(char *pArg)
{
   unsigned long level;

   level = (IFX_int32_t)MEI_GetDigitValue(pArg, 0);

   if ( (level>=MEI_DRV_PRN_LEVEL_LOW) &&  (level<=MEI_DRV_PRN_LEVEL_OFF) )
   {
      MEI_DRV_PRN_USR_LEVEL_SET(MEI_ROM, level);
      MEI_DRV_PRN_INT_LEVEL_SET(MEI_ROM, level);
   }
   else
   {
      PRN_DBG_USR_NL( MEI_DRV, MEI_DRV_PRN_LEVEL_HIGH,
            ("MEI_DRV: config entry TRACE DL ROM: arg %s --> level (%d) invalid" MEI_DRV_CRLF,
             (char *)pArg, (int)level));
   }

   return 0;
}

/**
   Handle procfs config - set TRACE configuration.
*/
static int MEI_ProcReadConfigTraceRom(char *pPage)
{
   return (sprintf( pPage, "%2d: %s \t= %2d" MEI_DRV_CRLF,
                    e_PROCFS_CONFIG_TRACE_DL_ROM,
                    arrVinaxDfeProcFsConfigTable[e_PROCFS_CONFIG_TRACE_DL_ROM].pName,
                    MEI_DRV_PRN_USR_LEVEL_GET(MEI_ROM)));
}

#endif   /* #if (MEI_SUPPORT_ROM_CODE == 1) */

/**
   Handle procfs config - block timeout for Download.
*/
static int MEI_ProcWriteConfigBlockTimeout(char *pArg)
{
   unsigned long block = 0;

   block = MEI_GetDigitValue(pArg, 10);

   MEI_BlockTimeout = (block==0)? 0 : 1;

   return 0;
}


/**
   Handle procfs config - read  block timeout for Download.
*/
static int MEI_ProcReadConfigBlockTimeout(char *pPage)
{
   return (sprintf( pPage, "%2d: %s \t= %d" MEI_DRV_CRLF,
                    e_PROCFS_CONFIG_BLOCK_TOUT,
                    arrVinaxDfeProcFsConfigTable[e_PROCFS_CONFIG_BLOCK_TOUT].pName,
                    MEI_BlockTimeout));
}


/**
   Handle procfs config - write max Wait for VINAX Response.
*/
static int MEI_ProcWriteConfigMaxWaitModemOnline(char *pArg)
{
   unsigned long max_wait_ms = 0;

   max_wait_ms = MEI_GetDigitValue(pArg, 10);
   MEI_MaxWaitForModemReady_ms = max_wait_ms | MEI_CFG_DEF_WAIT_PROTECTION_FLAG;

   return 0;
}

/**
   Handle procfs config - read  Max Wait for VINAX Response.
*/
static int MEI_ProcReadConfigMaxWaitModemOnline(char *pPage)
{
   return (sprintf( pPage, "%2d: %s \t= %s%d [ms]\n\r",
                    e_PROCFS_CONFIG_W_MODEM_ONLINE,
                    arrVinaxDfeProcFsConfigTable[e_PROCFS_CONFIG_W_MODEM_ONLINE].pName,
                    ((MEI_MaxWaitForModemReady_ms & MEI_CFG_DEF_WAIT_PROTECTION_FLAG) ? "*" : ""),
                    (MEI_MaxWaitForModemReady_ms & ~MEI_CFG_DEF_WAIT_PROTECTION_FLAG) ));
}


/**
   Handle procfs config - write max Wait for VINAX Response.
*/
static int MEI_ProcWriteConfigMaxWaitDfeResp(char *pArg)
{
   unsigned long max_wait_ms = 0;

   max_wait_ms = MEI_GetDigitValue(pArg, 10);

   MEI_MaxWaitDfeResponce_ms = max_wait_ms;

   return 0;
}


/**
   Handle procfs config - read  Max Wait for VINAX Response.
*/
static int MEI_ProcReadConfigMaxWaitDfeResp(char *pPage)
{
   return (sprintf( pPage, "%2d: %s \t= %d [ms]" MEI_DRV_CRLF,
                    e_PROCFS_CONFIG_W_DFE_RESP,
                    arrVinaxDfeProcFsConfigTable[e_PROCFS_CONFIG_W_DFE_RESP].pName,
                    MEI_MaxWaitDfeResponce_ms));
}

#if (MEI_SUPPORT_DEVICE_VINAX == 1)
/**
   Handle procfs config - write boot mode used for Download.
*/
static int MEI_ProcWriteConfigBootMode(char *pArg)
{
   unsigned long bootmode = 0;

   bootmode = MEI_GetDigitValue(pArg, 10);

   MEI_BootMode = (unsigned char)(bootmode);

   return 0;
}


/**
   Handle procfs config - read boot mode used for Download.
*/
static int MEI_ProcReadConfigBootMode(char *pPage)
{
   return (sprintf( pPage, "%2d: %s \t= 0x%02X " MEI_DRV_CRLF,
                    e_PROCFS_CONFIG_BOOTMODE,
                    arrVinaxDfeProcFsConfigTable[e_PROCFS_CONFIG_BOOTMODE].pName,
                    MEI_BootMode));
}
#endif /* (MEI_SUPPORT_DEVICE_VINAX == 1)*/

#if (MEI_SUPPORT_VDSL2_ADSL_SWAP == 1)

/**
   Handle procfs config - write fw mode select (VDSL2 / ADSL).
*/
static int MEI_ProcWriteConfigFwSelect(char *pArg)
{
   unsigned long fwmode = 0;

   fwmode = MEI_GetDigitValue(pArg, 0x10);

   MEI_fwModeSelect = (IFX_int32_t)(fwmode);

   return 0;
}


/**
   Handle procfs config - read fw mode select (VDSL2 / ADSL).
*/
static int MEI_ProcReadConfigFwSelect(char *pPage)
{
   return (sprintf( pPage, "%2d: %s \t= 0x%02X " MEI_DRV_CRLF,
                    e_PROCFS_CONFIG_FW_SELECT,
                    arrVinaxDfeProcFsConfigTable[e_PROCFS_CONFIG_FW_SELECT].pName,
                    MEI_fwModeSelect));
}

#endif      /* #if (MEI_SUPPORT_VDSL2_ADSL_SWAP == 1) */


/**
   Handle procfs config - write FSM State Set Pre-Action.
*/
static int MEI_ProcWriteConfigFsmSetPreAct(char *pArg)
{
   unsigned long actionFlags = 0;

   actionFlags = MEI_GetDigitValue(pArg, 0x10);

   MEI_FsmStateSetMsgPreAction = (IFX_int32_t)(actionFlags);

   return 0;
}

/**
   Handle procfs config - read FSM State Set Pre-Action.
*/
static int MEI_ProcReadConfigFsmSetPreAct(char *pPage)
{
   return (sprintf( pPage, "%2d: %s \t= 0x%02X " MEI_DRV_CRLF,
                    e_PROCFS_CONFIG_FSM_SET_PRE_ACT,
                    arrVinaxDfeProcFsConfigTable[e_PROCFS_CONFIG_FSM_SET_PRE_ACT].pName,
                    MEI_FsmStateSetMsgPreAction));
}




#if ( (MEI_MSG_DUMP_ENABLE == 1) && (MEI_DEBUG_PRINT == 1) )
static int MEI_ProcWriteConfigMsgDumpEnable(char *pArg)
{
   unsigned long tmpVal;
   tmpVal = (IFX_int32_t)MEI_GetDigitValue(pArg, 16);

   /*
      0x0000007F  enable: 0 off, 1 driver, 2 WE, 3 WH
      0x00000080  set label on/off
      0x0000FF00  out control - 0x01  H2D_CMV_READ
                                0x02  D2H_CMV_READ_REPLY
                                0x02  H2D_CMV_WRITE
                                0x08  D2H_CMV_WRITE_REPLY
                                0x10  D2H_CMV_INDICATE
                                0x20
      0xFFFF0000  Line filter - 0x8000 filter on
   */
   MEI_msgDumpEnable   =  tmpVal & 0x0000007F;
   MEI_msgDumpSetLabel = (tmpVal & 0x00000080) ? IFX_TRUE : IFX_FALSE;
   MEI_msgDumpOutCntrl = (tmpVal & 0x0000FF00) >> 8;
   MEI_msgDumpLine     = (IFX_uint16_t)((tmpVal & 0xFFFF0000) >> 16);

   return 0;
}


static int MEI_ProcReadConfigMsgDumpEnable(char *pPage)
{
   unsigned long tmpVal;

   tmpVal = ( MEI_msgDumpEnable | (MEI_msgDumpSetLabel ? 0x00000080 : 0x0) |
              (MEI_msgDumpOutCntrl << 8) |
              ( ((IFX_uint32_t)MEI_msgDumpLine) << 16) );

   return (sprintf( pPage, "%2d: %s \t= 0x%02X " MEI_DRV_CRLF,
                    e_PROCFS_CONFIG_MDMP_ENABLE,
                    arrVinaxDfeProcFsConfigTable[e_PROCFS_CONFIG_MDMP_ENABLE].pName,
                    (unsigned int)tmpVal));
}

static int MEI_ProcWriteConfigMsgDumpId(char *pArg)
{
   MEI_msgDumpId = (IFX_int16_t)MEI_GetDigitValue(pArg, 10);
   return 0;
}

static int MEI_ProcReadConfigMsgDumpId(char *pPage)
{
   return (sprintf( pPage, "%2d: %s \t= 0x%02X " MEI_DRV_CRLF,
                    e_PROCFS_CONFIG_MDMP_ID,
                    arrVinaxDfeProcFsConfigTable[e_PROCFS_CONFIG_MDMP_ID].pName,
                    MEI_msgDumpId));
}

#endif /* ( (MEI_MSG_DUMP_ENABLE == 1) && (MEI_DEBUG_PRINT == 1) ) */

#if (MEI_EXT_MEI_ACCESS_ADD_CSE_MIPS == 1) || (MEI_EXT_MEI_ACCESS_ADD_CSE == 1)
/**
   Handle procfs config - write MEI Access Dummy Loop Count.
*/
static int MEI_ProcWriteConfigMeiAccCse(char *pArg)
{
   /* !!! do not reduce the array size before you have read the comment at
          the top of this file !!! */
   unsigned int meiDmyCnt[3] = {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF};

   MEI_GetDigitArray(pArg, meiDmyCnt, 2, 16);

   if ( (meiDmyCnt[0] != 0xFFFFFFFF) &&
        (meiDmyCnt[1] != 0xFFFFFFFF) )
   {
      MEI_DummyAccessLoopsRd = meiDmyCnt[1];
      MEI_DummyAccessLoopsWr = meiDmyCnt[2];
   }

   return 0;
}

/**
   Handle procfs config - read MEI Access Dummy Loop Count.
*/
static int MEI_ProcReadConfigMeiAccCse(char *pPage)
{
   return (sprintf( pPage, "%2d: %s \tRd=%d \tWr=%d\n\r",
                    e_PROCFS_CONFIG_MEI_ACCESS_ADD_CSE,
                    arrVinaxDfeProcFsConfigTable[e_PROCFS_CONFIG_MEI_ACCESS_ADD_CSE].pName,
                    MEI_DummyAccessLoopsRd, MEI_DummyAccessLoopsWr));
}

#endif      /* #if (MEI_EXT_MEI_ACCESS_ADD_CSE_MIPS == 1) || (MEI_EXT_MEI_ACCESS_ADD_CSE == 1) */


#if (MEI_SUPPORT_DRV_MODEM_TESTS == 1)
/**
   Handle procfs config - write Modem Test control.
*/
static int MEI_ProcWriteConfigDTestCntrl(char *pArg)
{
   unsigned int testCntrl[3] = {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF};

   MEI_GetDigitArray(pArg, testCntrl, 3, 16);

   if (testCntrl[0] != 0xFFFFFFFF)
      MEI_DTEST_Setup(testCntrl[0]);

   if ( (testCntrl[1] != 0xFFFFFFFF) &&
        (testCntrl[2] != 0xFFFFFFFF) )
   {
      MEI_procDebugTestBufDmaRangeMin = testCntrl[1];
      MEI_procDebugTestBufDmaRangeMax = testCntrl[2];
   }

   return 0;
}

/**
   Handle procfs config - read Modem Test control.
*/
static int MEI_ProcReadConfigDTestCntrl(char *pPage)
{
   return (sprintf( pPage, "%2d: %s \t= 0x%08X min = 0x%08X max = 0x%08X" MEI_DRV_CRLF,
                    e_PROCFS_CONFIG_DTEST_CNTRL,
                    arrVinaxDfeProcFsConfigTable[e_PROCFS_CONFIG_DTEST_CNTRL].pName,
                    MEI_procDebugTestCntrl,
                    MEI_procDebugTestBufDmaRangeMin,
                    MEI_procDebugTestBufDmaRangeMax));
}
#endif


/**
*/
static int MEI_ProcReadConfig( char *page, char **start,
                                     off_t off, int count,
                                     int *eof, void *data)
{
   int len = 0, i;
   MEI_CONFIG_PROC_ENTRY_T *pConfigPage = (MEI_CONFIG_PROC_ENTRY_T *)data;

   #if (LINUX_VERSION_CODE < KERNEL_VERSION(2,6,0))
   MOD_INC_USE_COUNT;
   #endif

   for (i = 0; i < e_PROCFS_CONFIG_LAST; i++)
   {

/*
      PRN_DBG_USR_NL( MEI_DRV, MEI_DRV_PRN_LEVEL_HIGH,
            ("MEI_DRV: read config entry[%d]: %s" MEI_DRV_CRLF,
              i,
              pConfigPage[i].pName ));
*/

      len += pConfigPage[i].pRdFct(page + len);

/*
      len += sprintf( page+len, "%2d: %s \t= %2d" MEI_DRV_CRLF,
                      i,
                      pConfigPage[i].pName,
                      99);
*/
   }

   #if (LINUX_VERSION_CODE < KERNEL_VERSION(2,6,0))
   MOD_DEC_USE_COUNT;
   #endif
   return len;
}

/**
*/
static int MEI_ProcWriteConfig( struct file *file,
                                      const char *buffer,
                                      unsigned long count,
                                      void *data)
{
   int len, i;
   char MEI_procWriteBuf[64];
   char *pArgPointer = IFX_NULL;
   MEI_CONFIG_PROC_ENTRY_T *pConfigPage = (MEI_CONFIG_PROC_ENTRY_T *)data;

   #if (LINUX_VERSION_CODE < KERNEL_VERSION(2,6,0))
   MOD_INC_USE_COUNT;
   #endif

   /* check lenght of user data */
   len = (count > sizeof(MEI_procWriteBuf)) ? sizeof(MEI_procWriteBuf) : count;

   memset(MEI_procWriteBuf, 0x00, sizeof(MEI_procWriteBuf));

   if ( (MEI_DRVOS_CpyFromUser(MEI_procWriteBuf, buffer, len)) == IFX_NULL)
   {
      #if (LINUX_VERSION_CODE < KERNEL_VERSION(2,6,0))
      MOD_DEC_USE_COUNT;
      #endif
      return -e_MEI_ERR_GET_ARG;
   }

   /* terminate - last byte is 0x0A (CR) */
   MEI_procWriteBuf[len-1] = '\0';

   PRN_DBG_USR_NL( MEI_DRV, MEI_DRV_PRN_LEVEL_LOW,
         ("MEI_DRV: write config entry: %s (%d)" MEI_DRV_CRLF,
           MEI_procWriteBuf, len ));

   /* Interprete data */
   for (i = 0; i < e_PROCFS_CONFIG_LAST; i++)
   {
      if (strncmp(pConfigPage[i].pName, MEI_procWriteBuf, strlen(pConfigPage[i].pName)) == 0)
      {
         if ( (strlen(MEI_procWriteBuf) > strlen(pConfigPage[i].pName)) &&
              (isspace(MEI_procWriteBuf[strlen(pConfigPage[i].pName)])) )
            /* found --> break */
            break;
      }
   }

   if (i < e_PROCFS_CONFIG_LAST)
   {
      pArgPointer = &MEI_procWriteBuf[strlen(pConfigPage[i].pName)];
      PRN_DBG_USR_NL( MEI_DRV, MEI_DRV_PRN_LEVEL_LOW,
            ("MEI_DRV: found config entry[%d]: %s - Args <%s>" MEI_DRV_CRLF,
              i, pConfigPage[i].pName, pArgPointer ));

      if (pConfigPage[i].pWrFct != IFX_NULL)
      {
         pConfigPage[i].pWrFct(pArgPointer);
      }
   }
   else
   {
      PRN_DBG_USR_NL( MEI_DRV, MEI_DRV_PRN_LEVEL_LOW,
            ("MEI_DRV: config entry not found: %s (%d)" MEI_DRV_CRLF,
              MEI_procWriteBuf, len ));
   }

   #if (LINUX_VERSION_CODE < KERNEL_VERSION(2,6,0))
   MOD_DEC_USE_COUNT;
   #endif
   return len;
}



/**
   Create an read/write proc entry for configuration.
*/
int MEI_InstallProcEntryConfig(struct proc_dir_entry *driver_proc_node)
{
   if (driver_proc_node != NULL)
   {
      /* create new entry (read/write) */
      MEI_ProcConfigFile = create_proc_entry("config", 0644, driver_proc_node);

      if (MEI_ProcConfigFile == NULL)
      {
         /* error create proc entry "config" */
         PRN_ERR_USR_NL( MEI_DRV, MEI_DRV_PRN_LEVEL_ERR,
               ("MEI_DRV: cannot create proc config entry" MEI_DRV_CRLF));
         return -e_MEI_ERR_DEV_INIT;
      }

      /* Set the configuration data */
      MEI_ProcConfigFile->data       = &arrVinaxDfeProcFsConfigTable;
      MEI_ProcConfigFile->read_proc  = MEI_ProcReadConfig;
      MEI_ProcConfigFile->write_proc = MEI_ProcWriteConfig;

      #if (LINUX_VERSION_CODE < KERNEL_VERSION(2,6,30))
      MEI_ProcConfigFile->owner      = THIS_MODULE;
      #endif
   }

   PRN_DBG_USR_NL( MEI_DRV, MEI_DRV_PRN_LEVEL_HIGH,
         ("MEI_DRV: create proc config entry" MEI_DRV_CRLF));

   return 0;
}

#endif      /* #if (MEI_SUPPORT_PROCFS_CONFIG == 1) */

#endif      /* #if CONFIG_PROC_FS */

#endif      /* #ifdef LINUX */

