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
#include"../include/my_printf.h"
#include "../include/option.h"

int err_float(double f, int maj)
{
    int inf = 0x7F800000;
    if (f == *(float *)&inf) {
        my_putchar('i' - (32 * maj));
        my_putchar('n' - (32 * maj));
        my_putchar('f' - (32 * maj));
        return 1;
    }
    if (f != f) {
        my_putchar('-');
        my_putchar('n' - (32 * maj));
        my_putchar('a');
        my_putchar('n' - (32 * maj));
        return 2;
    }

    return 0;
}

int disp_float(double f, int nb_disp, int dec, int len_int)
{
    int retval = 0;
    for (int i = 1, j = 0;i < nb_disp + 1;i++) {
        f -= j;
        f *= 10;
        my_put_nbr((int)f);
        retval++;
        if (i == len_int && dec != 0) {
            my_putchar('.');
            retval++;
        }
        j = f;
    }
    return retval;
}

int my_put_float(double f, int dec, int maj)
{
    if (err_float(f, maj))
        return -1;
    int sign = f < 0 ? -1 : 1;
    f = f < 0 ? -f : f;
    int len_int = nb_len((int)f);
    int nb_disp = dec + len_int;
    f = my_round(f, dec);
    for (;f > 10;f /= 10);
    f /= 10;
    if (sign == -1)
        my_putchar('-');
    return disp_float(f, nb_disp, dec, len_int);
}

int my_put_nbr_flagf(va_list ap, option *op)
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
