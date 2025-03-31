/*
** EPITECH PROJECT, 2020
** my_compute_power_it
** File description:
** print power of a
*/

int my_compute_power_it(int nb, int p)
{ 
    int nb2 = nb;
    int i = 1;

    if (p == 0) {
        return(1);
    }

    if (p < 0) {
        return(0);
    } else {
        while (i < p) {
            nb = nb * nb2;
            i = i + 1;
        }
    }
    return (nb);
}         
