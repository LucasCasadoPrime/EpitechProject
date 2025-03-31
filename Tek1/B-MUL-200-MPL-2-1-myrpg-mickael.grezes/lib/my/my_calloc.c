/*
** EPITECH PROJECT, 2021
** LibMy
** File description:
** my_calloc
*/

#include <stdlib.h>

void *my_memset(void *ptr, int c, int n);

void *my_calloc(int nb, int size)
{
    void *ptr = malloc(nb * size);

    if (ptr == NULL)
        return (NULL);
    ptr = my_memset(ptr, 0, nb);
    return (ptr);
}