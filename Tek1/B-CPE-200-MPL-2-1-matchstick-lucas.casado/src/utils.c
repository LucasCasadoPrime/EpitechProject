/*
** EPITECH PROJECT, 2021
** B-CPE-200-MPL-2-1-matchstick-lucas.casado
** File description:
** utils
*/

#include "../include/include.h"

char *my_memset(char *str, char c, int size)
{
	int count;

	for (count = 0; count < size; count++)
		str[count] = c;
	str[count] = '\0';
	return (str);
}

void my_putchar(char c)
{
    write(1, &c, 1);
}

int my_putstr(char *str)
{
    int i = 0;

    for(; str[i] != '\0'; i++)
        my_putchar(str[i]);
    return (1);
}

int nb_matches(int line,all *all)
{
	int count = 0;
	int i;

	for (i = 0; all->map[line][i] != '\0'; i++)
		if (all->map[line][i] == '|')
			count++;
	return (count);
}

int my_putnbr(int nb)
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
        my_putnbr(nb / 10);
        my_putnbr(nb % 10);

    } else
        my_putchar(nb + 48);
    return (0);
}