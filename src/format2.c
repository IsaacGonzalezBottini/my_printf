/*
** EPITECH PROJECT, 2022
** format2
** File description:
** all functions for format
*/

#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
#include "../include/option.h"
#include "../include/my_printf.h"

void f_width_base(option *op, int nb, int base)
{
    int i = 0;
    int *ct = malloc(sizeof(int));
    int lim = op->width - nb_len_base(nb, base, ct);
    if (op->width > 0 && op->less != 1) {
        for (; i < lim; i++)
            my_putchar(op->fill);
    }
}

void f_less_base(option *op, int nb, int base)
{
    int *ct = malloc(sizeof(int));
    if (op->less) {
        for (int i = nb_len_base(nb, base, ct); i < op->width; i++)
            my_putchar(' ');
    }
}

int base_bin(long *p, int *n, int *count, option *op)
{
    for (; *p < *n; *p *= 2);
    *p /= *p != *n ? 2 : 1;
    for (; *p > 0; *p /= 2)
        if (*n >= *p) {
            my_putchar('1');
            *n -= *p;
            *count++;
        } else {
            my_putchar('0');
            *count++;
        }
    f_less_base(op, *n, 2);
    return *count;
}
