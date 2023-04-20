/*
** EPITECH PROJECT, 2022
** opt
** File description:
** opt
*/

#ifndef OPTION_H_
    #define OPTION_H_

typedef struct option {
    int diez;
    int less;
    int plus;
    int zero;
    int space;
    int strof;
    char fill;
    int preci;

    int width;
    int size;
}option;



option *cr_option(void);
int test_op(option *op, char const *c);

#endif
