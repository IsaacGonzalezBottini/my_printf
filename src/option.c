/*
** EPITECH PROJECT, 2022
** option
** File description:
** opt
*/

#include<stdarg.h>
#include<stdio.h>
#include<unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include"../include/option.h"
#include"../include/my_printf.h"
#include "../include/struct.h"

int is_flag(char c)
{
    for (int i = 0; tab_pt_fct[i].pt; i++) {
        if (c == tab_pt_fct[i].flag)
            return 1;
    }
    return 0;
}

int pass_fmt(char const *str)
{
    int i = 0;

    for (; is_flag(str[i]) == 0; i++);
    return i;
}

char *tab_format(char const *str)
{
    char *tab = NULL;
    int j = 0;

    tab = malloc(sizeof(char) * pass_fmt(str) + 1);
    if (tab == NULL)
        return NULL;
    for (int i = 0; is_flag(str[i]) == 0; i++) {
        tab[j] = str[i];
        j++;
    }
    tab[j] = '\0';
    return tab;
}

option *check_width(char const *str, option *op)
{
    op->width = my_getnbr(str);
    return check_preci(&str[nb_len(op->width)], op);
}

option *check_flag(char const *str)
{
    option *op = malloc(sizeof(option));
    int count = 0;
    char list[] = "-+# 0'";
    int *list_p[] = {&op->less, &op->plus,
        &op->diez, &op->space,
        &op->zero, &op->strof};
    op->fill = ' ';
    for (int i = 0; str[i] != '\0'; i++)  {
        if (is_a_flag(str[i], list, list_p) == 0)
            break;
        else
            count++;
    }
    if (op->zero)
        op->fill = '0';
    return check_width(&str[count], op);
}
