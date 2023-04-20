/*
** EPITECH PROJECT, 2022
** oui
** File description:
** oui
*/

#include <stdio.h>
#include "../include/option.h"
#include "../include/my_printf.h"

option *check_preci(char const *str, option *op)
{
    op->preci = -1;
    if (!(str[0] == '.'))
        return op;
    op->preci = my_getnbr(&str[1]);
    return op;
}
