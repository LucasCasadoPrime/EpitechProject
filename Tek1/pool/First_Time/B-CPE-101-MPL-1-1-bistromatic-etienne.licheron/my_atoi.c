/*
** EPITECH PROJECT, 2020
** my_atoi
** File description:
** Convert an string into an integer
*/

int my_atoi_isnum(char c)
{
    if (c >= 48 && c <= 57)
        return (1);
    return (0);
}

int my_atoi(char *str)
{
    long result = 0;
    int final_result = 0;
    int i = 0;
    int dash = 0;

    for (; my_atoi_isnum(str[i]) == 0; i++);
    if (str[i - 1] == '-')
        dash = -1;
    for (; my_atoi_isnum(str[i]) == 1; i++) {
        result *= 10;
        result += str[i] - 48;
        if (result > 2147483647)
            return (0);
    }
    if (dash == -1)
        result = -result;
    final_result = result;
    return (final_result);
}