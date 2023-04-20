/*
** EPITECH PROJECT, 2022
** flag bigf
** File description:
** f
*/

#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include "../include/my_printf.h"
#include "../include/option.h"

int my_put_float(double f, int dec, int maj);

int my_put_nbr_flagbigf(va_list ap, option *op)
{
    double f = va_arg(ap,double);
    int preci = op->preci >= 0 ? op->preci : 6;
    if (!op->less)
        float_width(f, preci, op);
    if (op->less && op->plus)
        my_putchar('+');
    if (op->space && f > 0 && op->width == 0)
        my_putchar(' ');
    int retval = my_put_float(f, preci, 0);
    if (op->diez && op->preci == 0)
        my_putchar('.');
    if (op->less)
        float_width(f, preci, op);
    return retval;
}
