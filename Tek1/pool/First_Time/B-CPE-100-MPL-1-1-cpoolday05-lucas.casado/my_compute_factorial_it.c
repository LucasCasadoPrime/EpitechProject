/*
** EPITECH PROJECT, 2020
** my_compute_factorial_it
** File description:
** print factorial
*/

int my_compute_factorial_it(int nb)
{
    int i = 1;
    int nb2 = nb;

    if (nb < 0 || nb >= 13) {
        return (0);
    }

    if (nb == 0) {
        return (1);
    }
      
    while (i < nb2) {
        nb = nb * (nb2 - i);
        i = i + 1;
    }
    return (nb);
}
   
