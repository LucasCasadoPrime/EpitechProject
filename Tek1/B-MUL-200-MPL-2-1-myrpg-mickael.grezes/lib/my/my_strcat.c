/*
** EPITECH PROJECT, 2020
** STRCAT
** File description:
** my_strcat
*/

int my_strlen(char const *str);

char *my_strcat(char *dest, char *src)
{
    int len = my_strlen(dest);
    int i = 0;

    for (; i != my_strlen(src); i++)
        dest[len + i] = src[i];
    dest[len + i] = '\0';
    return (dest);
}