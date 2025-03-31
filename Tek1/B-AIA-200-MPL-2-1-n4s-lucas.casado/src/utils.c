/*
** EPITECH PROJECT, 2021
** B-AIA-200-MPL-2-1-n4s-lucas.casado
** File description:
** utils
*/

#include "include.h"

int my_putnbr_base_long(long nbr, char *base)
{
    int i = 0;
    int size;
    long nb;

    if (nbr < 0) {
        nbr = - nbr;
        i += 1;
        my_put_char('-');
    }
    size = my_strlen(base);
    if (nbr > 0) {
        nb = nbr;
        nbr /= size;
        i += my_putnbr_base_long(nbr, base);
        i += 1;
        my_put_char(base[nb % size]);
    }
    return (i);
}

int my_put_float(double nbr)
{
    char *base = "0123456789";
    long dec;
    long ent;
    double dec2;
    int i = 0;

    ent = nbr;
    dec = nbr * (float)1000000;
    dec -= ent * 1000000;
    dec2 = (double)dec;
    i += my_putnbr_base_long(ent, base);
    i++;
    my_put_char('.');
    i += my_putnbr_base_long((long)dec2, base);
    return (i);
}

int is_number(char c)
{
    if (!(c >= '0' && c <= '9'))
        return (false);
    return (true);
}

double my_atof(char *str)
{
    double val = 0;
    int e = 0;
    int i = 0;

    while (*str != '\0' && is_number(*str) == true)
        val = val * 10 + (*str++ - '0');
    if (str[i] == '.')
        while (*str != '\0' && is_number(*str) == true)
            val = val * 10 + (*str++ - '0');
    while (e++ < 0)
        val *= 0.1;
    return (val);
}