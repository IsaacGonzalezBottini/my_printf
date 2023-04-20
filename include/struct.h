/*
** EPITECH PROJECT, 2022
** my_printf
** File description:
** struc and tab dor my_printf
*/

#include "my_printf.h"
#include "option.h"
#ifndef STRUCT_H_
    #define STRUCT_H_

struct base {
    int (*pt)(va_list ap, option *op);
    char flag;
};

static const struct base tab_pt_fct[] = {
    {my_putchar_p, '%'},
    {my_putchar_c, 'c'},
    {my_putstr_s, 's'},
    {my_put_nbr_i, 'i'},
    {my_put_nbr_d, 'd'},
    {my_put_nbr_b, 'b'},
    {my_put_nbr_o, 'o'},
    {my_put_nbr_x, 'x'},
    {my_put_nbr_bigx, 'X'},
    {my_put_str_bigs, 'S'},
    {my_put_nbr_u, 'u'},
    {my_put_nbr_flagf, 'f'},
    {my_put_address, 'p'},
    {my_put_flage,'e'},
    {my_put_flagbige,'E'},
    {my_put_nbr_flagbigf,'F'},
    {my_put_flagg,'g'},
    {my_put_flagbigg,'G'},
    {NULL, 0}
};

#endif /* !STRUCT_H_! */
