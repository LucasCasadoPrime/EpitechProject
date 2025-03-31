/*
** EPITECH PROJECT, 2020
** my_str
** File description:
** print string
*/

#include "my.h"

int my_putstr (char const *str)
{
    for (int i = 0; str[i]; i++) {
        my_putchar(str[i]);
    }
    return (0);
}