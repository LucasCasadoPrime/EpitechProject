/*
** EPITECH PROJECT, 2020
** my_isneg
** File description:
** print N if parameter is negative or P is positive 
*/

#include <unistd.h>

void my_putchar(char c)
{
    write(1, &c, 1);
}
int my_isneg(int n)
{
    if (n >= 0) {
        my_putchar('P');
    } else {
        my_putchar('N');
    }
    return (0);
}