/*
** EPITECH PROJECT, 2021
** LibMy
** File description:
** number_length
*/

int number_length(int nb)
{
    int length = 0;

    if (nb == 0)
        return (1);
    if (nb < 0)
        nb = -nb;
    for (int i = nb; i != 0; i /= 10)
        length++;
    return (length);
}