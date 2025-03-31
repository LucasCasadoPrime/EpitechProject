/*
** EPITECH PROJECT, 2021
** LibMy
** File description:
** my_calloc
*/

#include "generator.h"

void *my_memset(void *ptr, int c, int n)
{
    char *tmp = ptr;

    for (int i = 0; i < n; i++)
        tmp[i] = c;
    return (tmp);
}

void *my_calloc(int nb, int size)
{
    void *ptr = malloc(nb * size);

    if (ptr == NULL)
        return (NULL);
    ptr = my_memset(ptr, 0, nb);
    return (ptr);
}