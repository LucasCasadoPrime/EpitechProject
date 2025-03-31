/*
** EPITECH PROJECT, 2020
** LibMy
** File description:
** reverse_string
*/

char *reverse_string(char *str)
{
    int len = 0;
    char tmp;

    for (; str[len] != 0; len += 1);
    len -= 1;
    for (int i = 0; i < len; len -= 1) {
        tmp = str[i];
        str[i] = str[len];
        str[len] = tmp;
        i += 1;
    }
    return (str);
}