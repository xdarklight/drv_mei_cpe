/******************************************************************************

                               Copyright (c) 2011
                            Lantiq Deutschland GmbH
                     Am Campeon 3; 85579 Neubiberg, Germany

  For licensing information, see the file 'LICENSE' in the root folder of
  this software module.

******************************************************************************/

/* ============================================================================
   Description : VINAX Driver, VxWorks BSP part
   ========================================================================= */

/* ============================= */
/* Group=Main                    */
/* ============================= */


#if defined(VXWORKS) && defined(INCLUDE_VINAX)
/*
  sorry for this style, but this is a easy way to include the driver code
  into the board support package of VxWorks
*/

/* get at first the driver configuration */
#include "drv_mei_cpe_config.h"

#include "ifx_types.h"
/* add VINAX OS Layer */
#include "drv_mei_cpe_os.h"
/* add VINAX debug/printout part */
#include "drv_mei_cpe_dbg.h"

#include "drv_mei_cpe_api.h"
#include "drv_mei_cpe_vxworks.c"
#include "drv_mei_cpe_common.c"

#endif

