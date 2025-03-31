/*
** EPITECH PROJECT, 2020
** B-PSU-100-MPL-1-1-myprintf-lucas.casado
** File description:
** my_put_unnbr
*/

#include <unistd.h>
#include <stdlib.h>
#include "my.h"

unsigned int my_put_unnbr(int nb)
{
    if(nb == -2147483648) {
        my_putchar('-');
        my_putchar('2');
        nb = nb + 2000000000;
        nb = -1 * nb;
    }
    if (nb < 0) {
        exit(84);
    }
    if (nb > 9) {
        my_put_unnbr(nb / 10);
        my_put_unnbr(nb % 10);

    } else
        my_putchar(nb + 48);
    return (0);
}