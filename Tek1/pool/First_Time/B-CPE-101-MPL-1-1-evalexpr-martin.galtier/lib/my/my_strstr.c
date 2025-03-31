/*
** EPITECH PROJECT, 2020
** my_strstr
** File description:
** print str
*/
#include <stdio.h>

int my_strlen(char const *str);

int my_strncmp(char const *s1, char const *s2, int n);

char *my_strstr(char *str, char const *to_find)
{
    int size = my_strlen(to_find);

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == to_find[0] && my_strncmp(&str[i], to_find, size) == 0)
            return (&str[i]);
    }
    return (NULL);
}
