/*
** EPITECH PROJECT, 2020
** Day06
** File description:
** reverse string
*/

char *my_revstr(char *str)
{
    int i;
    char revstr[50];
    for (i = 0; str[i]; i = i + 1)
        revstr[i] = str[i];
    i = i - 1;
    for (int n = 0; i >= 0; n = n + 1, i = i - 1) {
        str[n] = revstr[i];
    }
    return (str);
}
