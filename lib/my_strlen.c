/*
** EPITECH PROJECT, 2022
** my_strlen
** File description:
** return the len of a string
*/

int my_strlen(char const *str)
{
    int i = 0;

    for (; str[i] != '\0'; i++);
    return i;
}
