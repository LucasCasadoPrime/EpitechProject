/*
** EPITECH PROJECT, 2020
** LibMy
** File description:
** to_number
*/

int is_digit(char c)
{
    if (c >= '0' && c <= '9')
        return (1);
    return (0);
}

int to_number(char const *str)
{
    long result = 0;
    int nb_dash = 0;

    for (int i = 0; str[i] != 0; i++) {
        if (is_digit(str[i]) == 0 && str[i] != '-' && str[i] != '+')
            break;
        if (str[i] == '-' && result == 0)
            nb_dash++;
        else if (is_digit(str[i]) == 1)
            result = (result * 10) + (str[i] - 48);
        if (result > 2147483648)
            return (0);
    }
    if (nb_dash % 2 == 1)
        result = -result;
    if (result > 2147483647)
        return (0);
    return (result);
}