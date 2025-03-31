/*
** EPITECH PROJECT, 2020
** revstr
** File description:
** reverse a string
*/

int my_strlen(const char *str);

void revstr_rec(char *str, int length)
{
    if (length < 2)
        return;

    char tmp;

    tmp = str[0];
    str[0] = str[length - 1];
    str[length - 1] = tmp;

    revstr_rec(str + 1, length - 2);
}

void revstr(char *str)
{
    revstr_rec(str, my_strlen(str));
}