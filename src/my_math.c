/*
** EPITECH PROJECT, 2022
** math
** File description:
** formule de math
*/


#include<stdarg.h>
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include"../include/my_printf.h"

int nb_len(int n)
{
    int i = 0;
    n = n < 0 ? -n : n;
    for (i;n > 0;i++)
        n /= 10;
    return i;
}

int nb_len_base(int nb, int base, int *count)
{
    int h = 1;
    int i = 0;

    (*count)++;
    if (nb < 0)
        nb *= -1;
    if (base == 2) {
        for (; nb >= h; h *= 2)
            i++;
        return i;
    }
    if (nb >= base)
        nb_len_base(nb / base, base, count);
    return *count;
}

double power_ten(int nb)
{
    double v = 1;
    for (int i = nb; i > 0; i--)
        v *= 10;
    for (int i = nb; i < 0; i++)
        v /= 10;
    return v;

}

double my_round(double f, int decimal)
{
    f += power_ten(-(decimal + 1)) * 5;
    return f;

}

int float_len(double f, int decimal)
{
    int v = nb_len((int)f);
    v += decimal;
    v += decimal > 0 ? 1 : 0;
    return v;
}
