/*
** EPITECH PROJECT, 2020
** B-PSU-100-MPL-1-1-myprintf-lucas.casado
** File description:
** my_put_a_short
*/

#include <unistd.h>
#include "my.h"

short my_put_a_short(short nb)
{
    if (nb == -32768) {
        my_putchar('-');
        my_putchar('9');
        nb = nb + 30000;
        nb = -1 * nb;
    }
    if (nb < 0) {
        nb = -nb;
        my_putchar('-');
    }
    if (nb > 9) {
        my_put_a_short(nb / 10);
        my_put_a_short(nb % 10);

    } else
        my_putchar(nb + 48);
    return (0);
}
