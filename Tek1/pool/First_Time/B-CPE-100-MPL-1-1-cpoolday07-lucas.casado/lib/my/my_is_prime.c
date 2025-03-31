/*
** EPITECH PROJECT, 2020
** lib
** File description:
** my_is_prime
*/
#include <unistd.h>

void my_putchar(char c)
{
    write(1, &c, 1);
}
int my_put_nbr(int nb)
{
    if(nb == -2147483648) {
        my_putchar('-');
        my_putchar('2');
        nb = nb + 2000000000;
        nb = -1 * nb;
    }
    if (nb < 0) {
        nb = -nb;
        my_putchar('-');
    }
    if (nb > 9) {
        my_put_nbr(nb / 10);
        my_put_nbr(nb % 10);

    } else
        my_putchar(nb + 48);
    return (0);
}

int my_is_prime(int nb)
{
    int nb2 = 0;
    int div = 0;
    
    while (nb2 < nb) {
        nb2++; 
        if (nb %nb2 == 0) {
            div++;
        }
    }
    if (div == 2) {
        return (1);
    } else {
        return (0);
    }
}