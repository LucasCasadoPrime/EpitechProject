/*
** EPITECH PROJECT, 2020
** Get nbr
** File description:
** Get number
*/

int digit(char c, const char *base);

int my_strlen(const char *str);

int nbr_rec(const char *num, const char *base, int res)
{
    if (*num == 0)
        return res;
    return (nbr_rec(num +1, base, res * my_strlen(base) + digit(num[0], base)));
}

int getnbr(const char *num, const char *base)
{
    return nbr_rec(num, base, 0);
}