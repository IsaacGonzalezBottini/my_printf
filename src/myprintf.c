/*
** EPITECH PROJECT, 2022
** myprintf
** File description:
** printf
*/

#include<stdarg.h>
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include"../include/option.h"
#include"../include/struct.h"
#include"../include/my_printf.h"

int float_len(double f, int decimal);

int test(char const *str, va_list ap, int *icr)
{
    int retval = 0;
    char *fmt = NULL;

    for (int i = 0; str[i] != '\0'; i++) {
        fmt = tab_format(&str[i]);
        option *op = check_flag(fmt);

        i += pass_fmt(&str[i]);
        *icr = i + 1;
        for (int j = 0;tab_pt_fct[j].pt != NULL;j++) {
            if (str[i] == tab_pt_fct[j].flag) {
                retval = tab_pt_fct[j].pt(ap, op);
                return retval;
            }
        }
        free(fmt);
    }
    *icr = 0;
    return 0;
}

int my_printf(char const *format,...)
{
    int retval = 0;
    va_list ap;
    int icr;

    va_start(ap, format);
    for (int i = 0; format[i] != '\0';i++) {
        if (format[i] == '%') {
            retval += test(&format[i + 1], ap, &icr);
            i += icr;
        } else {
            my_putchar(format[i]);
        }
    }
    va_end(ap);
    return retval;
}
