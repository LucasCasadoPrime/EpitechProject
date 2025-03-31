/*
** EPITECH PROJECT, 2020
** lib
** File description:
** my_is_prime
*/

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
