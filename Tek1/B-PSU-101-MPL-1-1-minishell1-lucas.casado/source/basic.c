/*
** EPITECH PROJECT, 2021
** B-PSU-101-MPL-1-1-minishell1-lucas.casado
** File description:
** basic
*/

#include "sh.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}

int my_putstr (char const *str)
{
    for (int i = 0; str[i]; i++) {
        my_putchar(str[i]);
    }
    return (0);
}

char *my_strncpy(char *dest, char *src, int n)
{
    char carac;

    carac = 0;
    while (carac < n && src[carac] != '\0') {
        dest[carac] = src[carac];
        carac = carac + 1;
    }
    if (n <= carac) {
        dest[carac] = '\0';
    }
    return (dest);
}