/*
** EPITECH PROJECT, 2021
** B-AIA-200-MPL-2-1-n4s-lucas.casado
** File description:
** basic
*/

#include "include.h"

int my_strlen(const char *str)
{
    int len = 0;

    for (; str[len]; len++);
    return (len);
}

void my_put_char(char c)
{
    write(1, &c, 1);
}

void my_put_str(const char *str)
{
    for (int i = 0; str[i]; i++)
        my_put_char(str[i]);
}