/*
** EPITECH PROJECT, 2021
** B-CPE-200-MPL-2-1-matchstick-lucas.casado
** File description:
** my_atoi
*/

#include "../include/include.h"

int my_atoi_isnum(char c)
{
    if (c >= 48 && c <= 57)
        return (1);
    return (0);
}

int my_atoi(char *str)
{
    long result = 0;
    int final_result = 0;
    int i = 0;

    for (int x = 0; str[x]; x += 1) {
        if ((str[x] < '0' || str[x] > '9') && str[x] != '\n')
            return (-1);
    }
    for (; my_atoi_isnum(str[i]) == 0; i++);
    for (; my_atoi_isnum(str[i]) == 1; i++) {
        result *= 10;
        result += str[i] - 48;
        if (result > 2147483647)
            return (8080);
    }
    final_result = result;
    return (final_result);
}