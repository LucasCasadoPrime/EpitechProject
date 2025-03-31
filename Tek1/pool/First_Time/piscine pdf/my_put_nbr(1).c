/*
** EPITECH PROJECT, 2020
** Day03Task07
** File description:
** displays the number given as a parameter
*/

int put_number(int nb)
{
    if (nb < 2147483647 && nb > -2147483647) {
        if (nb == 0)
            my_putchar('0');
        if (nb < 0) {
            my_putchar('-');
            nb *= -1;
        }
        while (nb != 0) {
            my_putchar(nb %10);
            nb /= 10;
        }
        return (nb);
    }
}