/*
** EPITECH PROJECT, 2022
** my_putbase
** File description:
** put base
*/

#include <stddef.h>
#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>
#include "../include/my_printf.h"

int my_putbase(int n, int b, int maj)
{
    int count = 0;
    int letter[6] = {'a', 'b', 'c', 'd', 'e', 'f'};
    int *t = malloc(sizeof(int) * n);
    int i = 0;

    while (n > 0) {
        t[i] = n % b;
        n = n / b;
        i++;
    }
    for (i -= 1; i > -1; i--) {
        char c = t[i] + 48 > 57 ? letter[t[i] - 10] - (32 * maj) : t[i] + 48;
        write(1, &c, 1);
        count++;
    }
    return count;
}
