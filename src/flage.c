/*
** EPITECH PROJECT, 2022
** flage
** File description:
** all functions for %e
*/

#include<stdarg.h>
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include"../include/my_printf.h"
#include "../include/option.h"

int my_put_float(double f,int dec, int maj);

int my_put_e(double f, int dec, int maj)
{
    int retval;
    int e = 0;
    for (; f > 10; e++)
        f /= 10;
    for (; f < 1; e--)
        f *= 10;
    int err = my_put_float(f, dec, maj);
    if (err == -1)
        return 3;
    retval = err;
    my_putchar('e' - (maj * 32) );
    my_putchar(e > 0 ? 43 : 45);
    if (e < 10)
        my_putchar('0');
    my_put_nbr(e < 0 ? -e : e);
    return retval;
}

int my_put_flage(va_list ap, option *op)
{
    double f = va_arg(ap, double);
    int preci = op->preci >= 0 ? op->preci : 6;
    if (!op->less)
        float_width(f, preci + 3, op);
    if (op->less && op->plus)
        my_putchar('+');
    if (op->space && f > 0 && op->width == 0)
        my_putchar(' ');
    int retval = my_put_e(f, preci, 0);
    if (op->diez && op->preci == 0)
        my_putchar('.');
    if (op->less)
        float_width(f, preci + 3, op);
    return retval;

}

int my_put_flagbige(va_list ap, option *op)
{
    double f = va_arg(ap, double);
    int preci = op->preci >= 0 ? op->preci : 6;
    if (!op->less)
        float_width(f, preci + 3, op);
    if (op->less && op->plus)
        my_putchar('+');
    if (op->space && f > 0 && op->width == 0)
        my_putchar(' ');
    int retval = my_put_e(f, preci, 0);
    if (op->diez && op->preci == 0)
        my_putchar('.');
    if (op->less)
        float_width(f, preci + 3, op);
    return retval;
}
