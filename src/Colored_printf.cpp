/*! \file */

#include "Colored_printf.h"
#define __STDC_WANT_LIB_EXT1__ 1
#include <stdio.h>
#include <stdarg.h>
#include <assert.h>

/*!
 *Is identical to printf_s, but uses color

 *\param[in] foreground_color The desired color for symbols
 *\param[in] background_color The desired color for background
 *\param[in] format The format to passed to printf
 *\param[in, out] others The arguments to passed to printf

 *\return Returns value equal to value returned by printf
 */
int colored_printf(enum Color const foreground_color, enum Color const background_color,
                   char const *const format, ...) {
    assert(format);

    printf_s("\033[%d;%dm", 30 + foreground_color, 40 + background_color);

    va_list arg_list = nullptr;
    va_start(arg_list, format);
    int const ret_value = vprintf_s(format, arg_list);
    va_end(arg_list);

    printf_s("\033[0m");
    return ret_value;
}

/*!
 *Is identical to fprintf_s(stderr, ...), but uses color

 *\param[in] foreground_color The desired color for symbols
 *\param[in] background_color The desired color for background
 *\param[in] format The format to passed to printf
 *\param[in, out] others The arguments to passed to printf

 *\return Returns value equal to value returned by printf
 */
int colored_error_printf(enum Color foreground_color, enum Color background_color,
                         char const *format, ...) {
    assert(format);

    fprintf_s(stderr, "\033[%d;%dm", 30 + foreground_color, 40 + background_color);

    va_list arg_list = nullptr;
    va_start(arg_list, format);
    int const ret_value = vfprintf_s(stderr, format, arg_list);
    va_end(arg_list);

    fprintf_s(stderr, "\033[0m");
    return ret_value;
}
