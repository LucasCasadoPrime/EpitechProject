/*
** EPITECH PROJECT, 2020
** B-PSU-100-MPL-1-1-myprintf-lucas.casado
** File description:
** my_put_octadecimal
*/

int my_put_octadecimal(int nbr)
{
    int octanb = 0;

    for (int i = 1; nbr != 0; i = i * 10) {
        octanb = octanb + (nbr % 8) * i;
        nbr = nbr / 8;
    }
    return (octanb);
}