/*
** EPITECH PROJECT, 2020
** LibMy
** File description:
** show_number
*/

#include <unistd.h>

void my_putchar(char c);

void show_number(int nb)
{
    if (nb == -2147483648) {
        write(1, "-2147483648", 11);
        return;
    }
    if (nb < 0) {
        nb = -nb;
        write (1, "-", 1);
    }
    if (nb > 9) {
        show_number(nb / 10);
        show_number(nb % 10);
    } else
        my_putchar(nb + '0');
}