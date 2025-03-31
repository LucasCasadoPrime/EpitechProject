/*
** EPITECH PROJECT, 2020
** my_factorial_rec
** File description:
** recursive
*/

int my_compute_factorial_rec(int nb)
{
    int i = 1;
    int nb2 = nb;

    if (nb == 0) {
        return (1);
    }
    if (nb < 0 || nb >= 13) {
        return (0);
    }
    return (nb * my_compute_factorial_rec(nb - 1));

}
           
       
