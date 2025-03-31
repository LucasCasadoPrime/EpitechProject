/*
** EPITECH PROJECT, 2020
** my_atoi
** File description:
** my_itoa
*/

#include <stdlib.h>
#include <stdio.h>

char *my_itoa(long long nb)
{
    char *str;
    long long tmp = nb;
    long long tmp_two;
    long long current = 0;

    if (nb == 0)
        return ("0");
    if (tmp < 0) {
        tmp = -tmp;
        current = 1;
    }
    tmp_two = tmp;
    for (; tmp > 0; current++)
        tmp = tmp / 10;
    str = malloc(sizeof(char) * current + 1);
    if (nb < 0) {
        str[0] = '-';
        nb = -nb;
    }
    str[current] = '\0';
    current--;
    for (; tmp_two > 0; current--) {
        tmp_two = tmp_two / 10;
        str[current] = nb % 10  + '0';
        nb = nb / 10;
    }
    return (str);
}