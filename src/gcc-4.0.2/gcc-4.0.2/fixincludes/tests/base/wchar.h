/*  DO NOT EDIT THIS FILE.

    It has been auto-edited by fixincludes from:

	"fixinc/tests/inc/wchar.h"

    This had to be done to correct non-standard usages in the
    original, manufacturer supplied header file.  */



#if defined( ALPHA_WCHAR_CHECK )
extern wchar_t *wcstok __((wchar_t *, const wchar_t *, wchar_t **)) __asm__("wcstok_r");
extern size_t   wcsftime __((wchar_t *, size_t, const wchar_t *, const struct tm *)) __asm__("__wcsftime_isoc");
#endif  /* ALPHA_WCHAR_CHECK */
