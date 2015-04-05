#ifndef _MEI_CPE_DRV_EXAMP_INT_WRAP_VXW_H
#define _MEI_CPE_DRV_EXAMP_INT_WRAP_VXW_H

/* ! ! ! ! ! ! ! ! ! ! ! ! ! ! ! ! ! ! ! ! ! ! ! ! ! ! ! ! ! ! ! ! ! ! ! ! !

                This is only an

               E X A M P L E  (vxWorks)

            how to setup and use the wrap of
         the VINAX driver interrupt functions.

   ! ! ! ! ! ! ! ! ! ! ! ! ! ! ! ! ! ! ! ! ! ! ! ! ! ! ! ! ! ! ! ! ! ! ! ! !  */


/******************************************************************************

                               Copyright (c) 2011
                            Lantiq Deutschland GmbH
                     Am Campeon 3; 85579 Neubiberg, Germany

  For licensing information, see the file 'LICENSE' in the root folder of
  this software module.

******************************************************************************/

/* ============================================================================
   Description : This file contains the defines specific to the vxWorks
                 interrupt wrapper functions.
   Remarks     : !!!! this is only a example code how to setup and use the
                      interrupt wrap.
   ========================================================================= */

#warning THIS_IS_ONLY_AN_EXAMPLE_HOW_TO_WRAP_THE_INTERRUPT_FUNCTIONS

/* ============================================================================
   Inlcudes
   ========================================================================= */

/* get the VINAX driver interrupt wrapper functions */
#include "drv_mei_cpe_vxworks.h"


/* ============================================================================
   typedefs interrupt wrapping (vxWorks)
   ========================================================================= */

/*
   For save the original ISR routine and parameters
   (you get it from the VINAX driver "intConnect" call)
*/
typedef struct MEI_MyIsrParams_s
{
   MEI_IntServRoutine_WrapVxW_t MEI_OrgDrvIsr;
   int                            MEI_OrgIsrParams;

   /* here you can add your own stuff */

} MEI_MyIsrParams_t;



/* ============================================================================
   global function (vxWorks) - declarations
   ========================================================================= */
extern int MEI_MyIntWrapSetup();



#endif      /* _MEI_CPE_DRV_EXAMP_INT_WRAP_VXW_H */

