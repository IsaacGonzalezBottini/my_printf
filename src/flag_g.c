/*
** EPITECH PROJECT, 2022
** flag
** File description:
** flag
*/
#include<stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include "../include/my_printf.h"
#include "../include/option.h"

int my_put_float(double f, int dec, int maj);
double my_round(double f, int decimal);
int my_put_e(double f, int dec, int maj);
int nb_len(int n);
double power_ten(int nb);

int my_put_g_rounder(int dec, int rounder, int *len)
{
    for (int i = 1; i < dec + 1; i++) {
        if ((rounder % (int)power_ten(i)) / (int)power_ten(i - 1) == 0) {
            (*len)++;
        } else {
            break;
        }
    }
}

int my_put_g(double f, int dec, int maj)
{
    int rounder = 0;
    int len = nb_len((int)f);
    rounder = (int)(f * power_ten(dec - len));
    if (len <= dec) {
        my_put_g_rounder(dec, rounder, &len );
        my_put_float(f, dec - len, maj);

    } else {
        my_put_e(f,dec - 1,0);
    }
    my_putchar('\n');
}

int my_put_flagg(va_list ap, option *op)
{
    double f = va_arg(ap, double);
    if (op->plus && f > 0)
        my_putchar('+');
    if (op->space && f > 0)
        my_putchar(' ');
    return my_put_g(f, 6, 0);
}

int my_put_flagbigg(va_list ap, option *op)
{
    double f = va_arg(ap, double);
    if (op->plus && f > 0)
        my_putchar('+');
    if (op->space && f > 0)
        my_putchar(' ');
    return my_put_g(f, 6, 1);
}
