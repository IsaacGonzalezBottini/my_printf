/*
** EPITECH PROJECT, 2022
** flag3
** File description:
** f3
*/

#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include "../include/my_printf.h"
#include "../include/option.h"

int my_put_nbr_b(va_list ap, option *op)
{
    int n = va_arg(ap, int);
    long p = 1;
    int count = 0;
    if (op->diez)
        op->width -= 2;
    if (op->fill == ' ')
        f_width_base(op, n, 2);
    if (op->diez)
        my_putstr("0b");
    if (op->fill == '0')
        f_width_base(op, n, 2);
    base_bin(&p, &n, &count, op);
    return count;
}

int my_put_nbr_o(va_list ap, option *op)
{
    int nb = va_arg(ap, int);
    int count = 0;
    if (op->diez)
        op->width -= 1;
    if (op->fill == ' ')
        f_width_base(op, nb, 8);
    if (op->diez)
        my_putchar('0');
    if (op->fill == '0')
        f_width_base(op, nb, 8);
    count = my_putbase(nb, 8, 0);
    f_less_base(op, nb, 8);
    return count;
}

int my_put_nbr_x(va_list ap, option *op)
{
    int nb = va_arg(ap, int);
    int count = 0;
    if (op->diez)
        op->width -= 1 + (op->fill == ' ' ? 1 : 0);
    if (op->fill == ' ')
        f_width_base(op, nb, 16);
    if (op->diez)
        my_putstr("0x");
    if (op->fill == '0')
        f_width_base(op, nb, 8);
    count = my_putbase(nb, 16, 0);
    f_less_base(op, nb, 16);
    return count;
}

int my_put_nbr_bigx(va_list ap, option *op)
{
    int nb = va_arg(ap, int);
    int count = 0;
    if (op->diez)
        op->width -= 1 + (op->fill == ' ' ? 1 : 0);
    if (op->fill == ' ')
        f_width_base(op, nb, 16);
    if (op->diez)
        my_putstr("0X");
    if (op->fill == '0')
        f_width_base(op, nb, 8);
    count = my_putbase(nb, 16, 1);
    f_less_base(op, nb, 16);
    return count;
}
