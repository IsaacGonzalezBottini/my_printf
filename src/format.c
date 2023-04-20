/*
** EPITECH PROJECT, 2022
** format c
** File description:
** c
*/

#include <stdarg.h>
#include "../include/option.h"
#include "../include/my_printf.h"

int is_a_flag(char const str_i, char *list, int **list_p)
{
    for (int i = 0;list[i] != '\0';i++) {
        if (list[i] == str_i) {
            *list_p[i] = 1;
            return 1;
        }
    }
    return 0;
}

void f_width(option *op, int nb)
{
    int i = 0;
    if (op->fill == '0' && op->plus && nb > 0)
        my_putchar('+');
    if (op->width > 0 && op->less != 1) {
        if (nb < 0)
            i++;
        if (op->plus)
            i++;
        for (; i < op->width - nb_len(nb); i++)
            my_putchar(op->fill);
    }
    if (op->fill == ' ' && op->plus && nb > 0)
        my_putchar('+');
}

void f_width_u(option *op, int nb)
{
    int i = 0;

    if (op->width > 0 && op->less != 1) {
        if (nb < 0)
            i++;
        for (; i < op->width - nb_len(nb); i++)
            my_putchar(op->fill);
    }
}

void f_less(option *op, int nb)
{
    if (op->less) {
        for (int i = nb_len(nb) + 1; i < op->width; i++)
            my_putchar(' ');
    }
}

void float_width(double f, int decimal, option *op)
{
    if (op->fill == '0' && op->plus && f > 0 && !op->less)
        my_putchar('+');
    if (op->width > 0) {
        op->width -= float_len(f, decimal);
        op->width -= (f < 0 ? 1 : 0) + (op->plus ? 1 : 0);
        for (int i = 0;i < op->width;i++)
            my_putchar(op->fill);
    }
    if (op->fill == ' ' && op->plus && f > 0 && !op->less)
        my_putchar('+');
}
