#ifndef _DRV_MEI_CPE_OS_H
#define _DRV_MEI_CPE_OS_H
/******************************************************************************

                              Copyright (c) 2014
                            Lantiq Deutschland GmbH

  For licensing information, see the file 'LICENSE' in the root folder of
  this software module.

******************************************************************************/

/* ==========================================================================
   Description : This file contains OS specific defines for the VRX driver.

   Remarks     : Please use the compiler switches here if you have
                 more than one OS.
   ========================================================================== */

/** \file
   This is the OS interface header file and contains the required OS interface
   functions, settings and defines. */

#if (MEI_DRV_IFXOS_ENABLE == 1)

#include "ifxos_common.h"
#include "ifxos_copy_user_space.h"
#include "ifxos_debug.h"
#include "ifxos_event.h"
#include "ifxos_linux_drv.h"
#include "ifxos_thread.h"
#include "ifxos_memory_alloc.h"
#include "ifxos_memory_map.h"
#include "ifxos_lock.h"
#include "ifxos_time.h"
#include "ifxos_select.h"

#endif /* #if (MEI_DRV_IFXOS_ENABLE == 1)*/

#if defined(LINUX)
#  include "drv_mei_cpe_linux.h"
#elif defined(VXWORKS)
#  include "drv_mei_cpe_vxworks.h"
#  if (MEI_DRV_IFXOS_ENABLE != 1)
#    error "Please include IFXOS support"
#  endif
#elif defined(NUCLEUS_PLUS)
#  include "drv_mei_cpe_nucleus.h"
#  if (MEI_DRV_IFXOS_ENABLE != 1)
#    error "Please include IFXOS support"
#  endif
#elif defined(ECOS)
#  include "drv_mei_cpe_ecos.h"
#  if (MEI_DRV_IFXOS_ENABLE != 1)
#    error "Please include IFXOS support"
#  endif
#elif defined(WIN32)
#  if (MEI_DRV_IFXOS_ENABLE != 1)
#    error "Please include IFXOS support"
#  endif
#else
#  error "OS type not defined!!!"
#endif

#if defined(LINUX)
#define MEI_DRVOS_NON_CACHED_MEM_ADDR(x)   KSEG1ADDR(x)
#else
#define MEI_DRVOS_NON_CACHED_MEM_ADDR(x)   (x)
#endif /* #if defined(LINUX)*/

#if (MEI_DRV_IFXOS_ENABLE == 1)

#if defined(IFXOS_HAVE_VERSION_CHECK)
#  if (!IFXOS_VERSION_CHECK_EG_THAN(1,0,0))
#     error "IFXOS_VERSION_CHECK: requiere at least IFX OS version 1.0.0"
#  endif
#else
#  ifdef WIN32
#     pragma message( "requiere at least IFX OS version 1.0.0")
#  else
#     warning "requiere at least IFX OS version 1.0.0"
#  endif
#endif

#ifdef IFXOS_HAVE_DRV_SELECT
#  if (IFXOS_HAVE_DRV_SELECT == 1)
   #define MEI_DRVOS_HAVE_DRV_SELECT   1
#  endif
#endif

#define MEI_DRVOS_sema_t                  IFXOS_lock_t
#define MEI_DRVOS_SemaphoreInit           IFXOS_LockInit
#define MEI_DRVOS_SemaphoreDelete         IFXOS_LockDelete
#define MEI_DRVOS_SemaphoreLock           IFXOS_LockGet
#define MEI_DRVOS_SemaphoreUnlock         IFXOS_LockRelease

#define MEI_DRVOS_selectQueue_t           IFXOS_drvSelectQueue_t
#define MEI_DRVOS_select_OSArg_t          IFXOS_drvSelectOSArg_t
#define MEI_DRVOS_selectTable_t           IFXOS_drvSelectTable_t
#define MEI_DRVOS_SelectQueueInit         IFXOS_DrvSelectQueueInit
#define MEI_DRVOS_SelectQueueWakeUp       IFXOS_DrvSelectQueueWakeUp
#define MEI_DRVOS_SelectQueueAddTask      IFXOS_DrvSelectQueueAddTask
#define MEI_DRVOS_SEL_WAKEUP_TYPE_RD      IFXOS_DRV_SEL_WAKEUP_TYPE_RD

#define MEI_DRVOS_event_t                 IFXOS_event_t
#define MEI_DRVOS_EventInit               IFXOS_EventInit
#define MEI_DRVOS_EventDelete             IFXOS_EventDelete
#define MEI_DRVOS_EventWakeUp             IFXOS_EventWakeUp
#define MEI_DRVOS_EventWait_timeout(_event_, _time_to_wait_) IFXOS_EventWait(_event_, _time_to_wait_, IFX_NULL)

#define MEI_PRINT_USR                     IFXOS_DBG_PRINT_USR
#define MEI_PRINT_INT                     IFXOS_ERR_PRINT_INT
#define MEI_PRINT_INT_RAW                 IFXOS_PRINT_INT_RAW

#define MEI_DRVOS_GetElapsedTime_ms       IFXOS_ElapsedTimeMSecGet
#define MEI_DRVOS_Wait_ms                 IFXOS_MSecSleep

#define MEI_DRVOS_ThreadCtrl_t            IFXOS_ThreadCtrl_t
#define MEI_DRVOS_ThreadParams_t          IFXOS_ThreadParams_t
#define MEI_DRVOS_ThreadInit(p,a,b,c,d)   IFXOS_ThreadInit(p,a,b,MEI_DRVOS_DEFAULT_STACK_SIZE,0,c,d)
#define MEI_DRVOS_ThreadDelete(_thread_)  IFXOS_ThreadDelete(_thread_, 0)
#define MEI_DRVOS_ThreadPriorityModify    IFXOS_ThreadPriorityModify

#define MEI_DRVOS_Malloc                  IFXOS_BlockAlloc
#define MEI_DRVOS_Free                    IFXOS_BlockFree

#define MEI_DRVOS_VirtMalloc              IFXOS_MemAlloc
#define MEI_DRVOS_VirtFree                IFXOS_MemFree

#define MEI_DRVOS_Phy2VirtMap             IFXOS_Phy2VirtMap
#define MEI_DRVOS_Phy2VirtUnmap           IFXOS_Phy2VirtUnmap

#define MEI_DRVOS_CpyToUser               IFXOS_CpyToUser
#define MEI_DRVOS_CpyFromUser             IFXOS_CpyFromUser


#define MEI_DRV_OS_LITTLE_ENDIAN          IFXOS_LITTLE_ENDIAN
#define MEI_DRV_OS_BIG_ENDIAN             IFXOS_BIG_ENDIAN
#define MEI_DRV_OS_BYTE_ORDER             IFXOS_BYTE_ORDER

/** default task stack size */
#ifndef MEI_DRVOS_DEFAULT_STACK_SIZE
#define MEI_DRVOS_DEFAULT_STACK_SIZE      IFXOS_DEFAULT_STACK_SIZE
#endif

#endif /* #if (MEI_DRV_IFXOS_ENABLE == 1)*/

#endif      /* #ifndef _DRV_MEI_CPE_OS_H */

