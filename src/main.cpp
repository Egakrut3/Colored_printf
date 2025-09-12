/*! \file */

#include "Colored_printf.h"
#include <stdio.h>

/*!
 *An entry point for the program

 *\return Returns error code of running this program
 */
int main()
{
    colored_printf(GREEN, WHITE, "Hello world!");

    printf("\n\n\nCommit GitHub\n\n");
    return 0;
}
