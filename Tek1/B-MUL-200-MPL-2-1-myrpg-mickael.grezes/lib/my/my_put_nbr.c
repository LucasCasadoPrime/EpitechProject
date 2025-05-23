/*
** EPITECH PROJECT, 2020
** my_put_nbr
** File description:
** display digits
*/

#include <unistd.h>

int my_putchar(char c);

int my_put_nbr(int nb)
{
    if (nb == -2147483648) {
        write(1, "-2147483648", 11);
        return (0);
    }
    if (nb < 0) {
        nb = -nb;
        write (1, "-", 1);
    }
    if (nb > 9) {
        my_put_nbr(nb / 10);
        my_put_nbr(nb % 10);
    } else
        my_putchar(nb + '0');
    return (0);
}

void my_put_bin(unsigned int nb)
{
    int nbr[32];
    int i = 0;

    while (nb >= 1) {
        nbr[i] = nb % 2;
        nb /= 2;
        i++;
    }
    for (int j = i - 1; j >= 0; j--)
        my_put_nbr(nbr[j]);
}