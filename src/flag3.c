/*
** EPITECH PROJECT, 2022
** flag3
** File description:
** flag %S %f %p
*/

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "../include/my_printf.h"
#include "../include/option.h"

int my_put_str_bigs(va_list ap, option *op)
{
    char *str = va_arg(ap, char *);
    int count = 0;
    int c_base = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 0 && str[i] <= 32) {
            count++;
            my_putchar('\\');
            c_base = my_putbase(str[i], 8, 0);
        } else {
            my_putchar(str[i]);
            count++;
        }
    }
    return count + c_base;
}

int my_put_nbr_u(va_list ap, option *op)
{
    int nb = va_arg(ap, int);
    char tmp[20];
    int i = 0;
    int v_return = 0;
    f_width_u(op, nb);
    if (op->space == 1 && nb >= 0)
        my_putchar(' ');
    for (; nb > 0; i++) {
        tmp[i] = nb % 10 + '0';
        nb /= 10;
    }
    v_return = i;
    i--;
    for (; i >= 0; i--)
        my_putchar(tmp[i]);
    f_less(op, nb);
    return v_return;
}

void display_hexa(long nb, long base)
{
    if (nb % base <= 9)
        my_putchar(nb % base + '0');
    else {
        if (nb % base == 10)
            my_putchar('a');
        if (nb % base == 11)
            my_putchar('b');
        if (nb % base == 12)
            my_putchar('c');
        if (nb % base == 13)
            my_putchar('d');
        if (nb % base == 14)
            my_putchar('e');
        if (nb % base == 15)
            my_putchar('f');
    }
}

int test_base(long nb, long base, int *count)
{
    (*count)++;
    if (nb < 0) {
        my_putchar('-');
        nb *= -1;
    }
    if (nb >= base)
        test_base(nb / base, base, count);
    display_hexa(nb, base);
    return 0;
}

int my_put_address(va_list ap, option *op)
{
    int *ct = malloc(sizeof(int));
    void *pt = va_arg(ap, void *);

    *ct = 2;
    my_putstr("0x");
    test_base((long int)pt, 16, ct);
    return *ct;
}
