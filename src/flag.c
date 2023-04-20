/*
** EPITECH PROJECT, 2022
** flag
** File description:
** 5 basics flag
*/

#include <stdio.h>
#include<stdlib.h>
#include <stdarg.h>
#include "../include/my_printf.h"
#include "../include/option.h"

int  my_putchar_p(va_list ap, option *op)
{
    my_putchar('%');
    return 1;
}

int my_putchar_c(va_list ap, option *op)
{
    my_putchar(va_arg(ap, int));
    return 1;
}

int my_putstr_s(va_list ap, option *op)
{
    char *str = va_arg(ap, char *);
    int preci = op->preci >= 0 ? op->preci : my_strlen(str);
    char *new = malloc(sizeof(char) * my_strlen(str));
    for (int i = 0;str[i] != '\0' && i < preci; i++)
        new[i] = str[i];
    for (int i = my_strlen(new); i < op->width && !op->less; i++)
            my_putchar(' ');
    my_putstr(new);
    if (op->less) {
        for (int i = my_strlen(new); i < op->width; i++)
            my_putchar(' ');
    }
    return my_strlen(new);
}

int my_put_nbr_i(va_list ap, option *op)
{
    int nb = va_arg(ap, int);
    int count = 0;
    int i = 0;
    f_width(op, nb);
    if (op->space == 1 && nb >= 0)
        my_putchar(' ');
    my_put_nbr(nb);
    f_less(op, nb);
    while (nb > 0) {
        nb /= 10;
        count++;
    }
    return count;
}

int my_put_nbr_d(va_list ap, option *op)
{
    int nb = va_arg(ap, int);
    int count = 0;
    int i = 0;
    f_width(op, nb);
    if (op->space == 1 && nb >= 0)
        my_putchar(' ');
    my_put_nbr(nb);
    f_less(op, nb);
    while (nb > 0) {
        nb /= 10;
        count++;
    }
    return count;
}
