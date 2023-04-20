/*
** EPITECH PROJECT, 2022
** my_printf
** File description:
** struc and tab dor my_printf
*/

#include "option.h"

#ifndef MY_PRINTF_H_
    #define MY_PRINTF_H_

void my_putchar(char c);
int my_putstr(char const *str);
int my_put_nbr(int nb);
int my_strlen(char const *str);
int my_putbase(int n, int b, int maj);
int my_getnbr(char const *str);

int nb_len(int n);
int nb_len_base(int nb, int base, int *count);
double power_ten(int nb);
double my_round(double f, int decimal);
int base_bin(long *p, int *n, int *count, option *op);
int my_put_float(double f, int dec, int maj);
int float_len(double f, int decimal);
void float_width(double f, int decimal, option *op);
option *check_preci(char const *str, option *op);

int pass_fmt(char const *str);
char *tab_format(char const *str);
option *check_flag(char const *str);
int is_a_flag(char const str_i, char *list, int **list_p);
void f_width(option *op, int nb);
void f_width_u(option *op, int nb);
void f_less(option *op, int nb);
void f_width_base(option *op, int nb, int base);
void f_less_base(option *op, int nb, int base);

int my_put_flagg(va_list ap, option *op);
int my_put_flagbigg(va_list ap, option *op);
int my_put_nbr_flagf(va_list ap, option *op);
int my_put_nbr_flagbigf(va_list ap, option *op);
int my_put_flage(va_list ap, option *op);
int my_put_flagbige(va_list ap, option *op);
int my_putchar_p(va_list ap, option *op);
int my_putchar_c(va_list ap, option *op);
int my_putstr_s(va_list ap, option *op);
int my_put_nbr_i(va_list ap, option *op);
int my_put_nbr_d(va_list ap, option *op);
int my_put_nbr_b(va_list ap, option *op);
int my_put_nbr_o(va_list ap, option *op);
int my_put_nbr_x(va_list ap, option *op);
int my_put_nbr_bigx(va_list ap, option *op);
int my_put_str_bigs(va_list ap, option *op);
int my_put_nbr_u(va_list ap, option *op);
int my_put_address(va_list ap, option *op);
int my_printf(char const *format,...);
#endif /* !MY_PRINTF_H_! */
