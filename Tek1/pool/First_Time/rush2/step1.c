/*
** EPITECH PROJECT, 2020
** rush2
** File description:
** step1
*/
#include <unistd.h>

void my_putchar(char c)
{
    write (1, &c, 1);
}

int my_put_nbr(int nb)
{
    if (nb == -2147483648) {
        write(1, "-2147483648", 11);
        return(0);
    }
    if (nb < 0) {
        nb = -nb;
        write (1, "-", 1);
    }
    if (nb > 9) {
        my_put_nbr(nb/10);
        my_put_nbr(nb%10);

    } else
        my_putchar(nb+'0');
    return (0);
}

int main(int argc, char **argv)
{
    char str = argv[2][0];
    int count = 0;

    for (int j = 2 ; j < argc ; j++) {
    for (int t = 0 ; argv[1][t] ; t++) {
        if (argv[1][t] == str)
            count++;
    }
    str = str + 32;
    for (int i = 0 ;  argv[1][i] ; i++) {
        if (argv[1][i] == str)
            count++;
    }
    str = str - 64;
    for (int k = 0 ; argv[1][k] ; k++) {
        if (argv[1][k] == str)
            count++;
    }
    my_putchar(argv[j][0]);
    my_putchar(':');
    my_put_nbr(count);
    my_putchar(10);
    str = argv[j][0];
    count = 0;
    }
    return (0);
}
