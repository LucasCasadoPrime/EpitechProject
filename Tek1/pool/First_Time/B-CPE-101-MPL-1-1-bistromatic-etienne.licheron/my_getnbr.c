/*
** EPITECH PROJECT, 2020
** my_getnbr
** File description:
** Write a number sent to the function as a string
*/

int my_getnbr_isnum(char const *str)
{
    if (str[0] >= 48 && str[0] <= 57)
        return (1);
    return (0);
}

long long my_getnbr(char const *str)
{
    long long result = 0;
    int nb_dash = 0;

    for (int i = 0; str[i] != 0; i++) {
        if (my_getnbr_isnum(&str[i]) == 0 && str[i] != '-' && str[i] != '+')
            break;
        if (str[i] == '-' && result == 0)
            nb_dash++;
        else if (my_getnbr_isnum(&str[i]) == 1)
            result = (result * 10) + (str[i] - 48);
    }
    if (nb_dash % 2 == 1)
        result = -result;
    return (result);
}