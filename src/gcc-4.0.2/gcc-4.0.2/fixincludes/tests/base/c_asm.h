/*  DO NOT EDIT THIS FILE.

    It has been auto-edited by fixincludes from:

	"fixinc/tests/inc/c_asm.h"

    This had to be done to correct non-standard usages in the
    original, manufacturer supplied header file.  */



#if defined( DEC_INTERN_ASM_CHECK )
#ifdef __DECC
float fasm {
    ... asm stuff ...
};
#pragma intrinsic( dasm )
#endif
/* END ASM TEST*/
#endif  /* DEC_INTERN_ASM_CHECK */
