/*
** EPITECH PROJECT, 2022
** my_getnbr
** File description:
** find a number in string and return as a int
*/

int check_carac(char const *str)
{
    int i = 0;

    for (; (str[i] < '0' || str[i] > '9'); i++) {
        if (str[i] != '-' && str[i] != '+') {
            return 0;
        }
    }
    return 1;
}

int get_sign(char const *str)
{
    int less = 0;

    for (int i = 0; (str[i] < '0' || str[i] > '9'); i++) {
        if (str[i] == '-')
            less++;
    }
    if (less % 2 == 0)
        return 1;
    else
        return 0;
}

int get_index(char const *str)
{
    int i = 0;

    for (; (str[i] < '0' || str[i] > '9'); i++);
    return i;
}

char *find_int_in_str(char const *str, char *tmp)
{
    int j = 0;

    if (get_sign(str) == 0) {
            tmp[j] = '-';
            j++;
    }
    for (int i = get_index(str); (str[i] >= '0' && str[i] <= '9'); i++) {
        tmp[j] = str[i];
        j++;
    }
    tmp[j] = '\0';
    return tmp;
}

int my_getnbr(char const *str)
{
    int i = 0;
    long nb = 0;
    int bool = 0;
    char tmp[256];
    if (check_carac(str) == 0)
        return 0;
    find_int_in_str(str, tmp);
    if (tmp[i] == '-') {
        bool = 1;
        i++;
    }
    for (; tmp[i] != '\0'; i++) {
        if (nb > 214748364 || (nb == 214748364 && tmp[i] > '7' && bool != 1)
            || (nb == 214748364 && tmp[i] > '8' && bool == 1)) {
            return 0;
        }
        nb = nb * 10 + tmp[i] - 48;
    }
    nb = bool ? -(nb) : nb;
    return nb;
}
