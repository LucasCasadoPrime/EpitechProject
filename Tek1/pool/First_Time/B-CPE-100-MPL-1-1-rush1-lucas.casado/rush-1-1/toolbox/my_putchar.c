/*
** EPITECH PROJECT, 2020
** Rush1
** File description:
** Program my_putchar
*/

#include <unistd.h>

void my_putchar(char c)
{
    write(1, &c, 1);
}
