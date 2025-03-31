/*
** EPITECH PROJECT, 2021
** antman
** File description:
** absolute_number
*/

int absolute_number(int nb)
{
    if (nb < 0)
        nb = -nb;
    return (nb);
}