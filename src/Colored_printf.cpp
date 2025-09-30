/*! \file */

#include "Colored_printf.h"
#include <stdio.h>
#include <stdarg.h>

/*!
 *Is identical to printf, but uses color

 *\param[in] foreground_color The desired color for symbols
 *\param[in] background_color The desired color for background
 *\param[in] format The format to passed to printf
 *\param[in, out] others The arguments to passed to printf

 *\return Returns value equal to value returned by printf
 */
int colored_printf(enum Color const foreground_color, enum Color const background_color,
                   char const *const format, ...) {
    printf("\033[%d;%dm", 30 + foreground_color, 40 + background_color);

    va_list arg_list = nullptr;
    va_start(arg_list, format);
    int const ret_value = vprintf(format, arg_list);
    va_end(arg_list);

    printf("\033[0m");
    return ret_value;
}
