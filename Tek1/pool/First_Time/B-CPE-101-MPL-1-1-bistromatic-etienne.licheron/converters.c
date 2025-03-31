/*
** EPITECH PROJECT, 2020
** BistroMatic
** File description:
** convert base to another base
*/

#include <stdio.h>
#include <stdlib.h>

int getnbr(const char *num, const char *base);

int nbr_rec(const char *num, const char *base, int res);

void revstr(char *str, int length);

int my_strlen(char const *str);

char *my_strdup(char *str);

int my_putstr(char const *str);

int digit(char c, const char *base)
{
    if (*base == c)
        return 0;
    return 1 + digit(c, base + 1);
}

void putnbr_rec(int num, const char *base, char *res)
{
    int base_len = my_strlen(base);
    int nbr_rec(const char *num, const char *base, int res);

    if (num < base_len) {
        res[0] = base[num];
        res[1] = 0;
        return;
    }
    else {
        int digit = num % base_len;
        *res = base[digit];
        num = num / base_len;
        putnbr_rec(num, base, res + 1);
    }
}

char *putnbr(unsigned int num, const char *base)
{
    char buffer[256];
    putnbr_rec(num, base, buffer);
    revstr(buffer, my_strlen(buffer));
    return my_strdup(buffer);
}

char *convert(const char *num, char const *from, const char *to)
{
    return putnbr(getnbr(num, from), to);
}