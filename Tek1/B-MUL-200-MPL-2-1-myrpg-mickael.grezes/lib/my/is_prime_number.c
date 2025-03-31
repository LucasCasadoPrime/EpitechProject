/*
** EPITECH PROJECT, 2020
** LibMy
** File description:
** is_prime_number
*/

int is_prime_number(int nb)
{
    if (nb < 2)
        return (0);
    for (int i = 2; i < nb; i += 1)
        if (nb % i == 0)
            return (0);
    return (1);
}