/*
** EPITECH PROJECT, 2020
** my_strncpy
** File description:
** my_strncpy
*/

#include <stdio.h>
#include <stdlib.h>

char *my_strncpy(char *dest, char const *src, int n)
{
    dest = malloc((sizeof(char) * n));
    for (int i = 0; i < n; i++)
        dest[i] = src[i];
    dest[n - 1] = '\0';
    return (dest);
}