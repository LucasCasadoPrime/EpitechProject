/*
** EPITECH PROJECT, 2020
** B-PSU-100-MPL-1-1-myprintf-lucas.casado
** File description:
** my_put_bin
*/

int my_put_bin(int nbr)
{
    int bin = 0;

    for (int i = 1; nbr != 0; i = i * 10) {
        bin = bin + (nbr % 2) * i;
        nbr = nbr / 2;
    }
    return (bin);
}