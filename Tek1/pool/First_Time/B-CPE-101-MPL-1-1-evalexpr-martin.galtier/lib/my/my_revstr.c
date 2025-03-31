/*
** EPITECH PROJECT, 2020
** my_revstr.c
** File description:
** test
*/

int my_strlen(char *str);

char *my_revstr(char *str)
{
    int i = 0;
    int r = my_strlen(str);
    unsigned char tab;
    while (i < r / 2) {
        tab = str[i];
        str[i] = str[r - 1 - i];
        str[r - 1 - i] = tab;
        i++;
    }
    return (str);
}
