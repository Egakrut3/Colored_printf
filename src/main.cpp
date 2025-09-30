/*! \file */

#include "Colored_printf.h"
#include <stdio.h>

/*!
 *An entry point for the program

 *\return Returns error code of running this program
 */
int main() {
    colored_error_printf(RED, BLACK, "Something wrong");

    colored_printf(GREEN, BLACK, "\n\n\nCommit GitHub\n\n");
    return 0;
}
