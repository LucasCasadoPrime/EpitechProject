/*
** EPITECH PROJECT, 2021
** LibMy
** File description:
** my_itoa
*/

#include <stdlib.h>

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

int number_length(int nb)
{
    int length = 0;

    if (nb == 0)
        return (1);
    if (nb < 0)
        nb = -nb;
    for (int i = nb; i != 0; i /= 10)
        length++;
    return (length);
}

char *my_itoa(int nb)
{
    char *dest;
    int plus = 0;

    if (nb == 0) {
        dest = my_calloc(2, sizeof(char));
        dest[0] = '0';
        return (dest);
    }
    dest = my_calloc(number_length(nb) + 2, sizeof(char));
    if (nb < 0) {
        plus = 1;
        dest[0] = '-';
        nb = -nb;
    }
    for (int i = number_length(nb) + plus; i != 0 + plus; i--) {
        dest[i - 1] = (nb % 10) + '0';
        nb /= 10;
    }
    return (dest);
}