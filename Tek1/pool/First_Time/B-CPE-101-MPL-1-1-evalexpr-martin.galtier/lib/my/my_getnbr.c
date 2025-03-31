/*
** EPITECH PROJECT, 2020
** my_strstr
** File description:
** print str
*/
#include <stdio.h>

int my_getnbr(char const *str)
{
    int neg = 1;
    int i = 0;
    int nbr = 0;

    while (str[i] == '+' || str[i] == '-') {
        if (str[i] == '-') {
            neg = neg * -1;
        }
        i = i + 1;
    }
    while (str[i] >= '0' && str[i] <= '9') {
        nbr *= 10;
        nbr += str[i] - '0';
        i = i + 1;
    }
    return (nbr * neg);
}
