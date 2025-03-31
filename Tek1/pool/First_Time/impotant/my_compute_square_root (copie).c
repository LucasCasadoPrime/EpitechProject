/*
** EPITECH PROJECT, 2020
** my_compute_square_root
** File description:
** print square root 
*/

int my_compute_square_root(int nb)
{
    int nb2 = 0;
        
    if ( nb <= 0) {
        return 0;
    }
    while (nb != nb2 * nb2) {
        nb2 = nb2 + 1;
        if (nb2 >= nb)
            return 0;
    }
    return (nb2);
}
    
