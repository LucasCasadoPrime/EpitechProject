/*
** EPITECH PROJECT, 2020
** conv_base
** File description:
** convert an int in another base
*/

#include <stdlib.h>

char *my_strcpy( char *dest, char const *src);

int my_strlen(const char *str);

char *my_strdup(char *str)
{
    int len;
    char *dup;
    len = my_strlen(str) + 1;
    dup = malloc(len);
    if (dup == NULL)
        return (NULL);
    dup = my_strcpy(dup, str);
    dup[len - 1] = '\0';
    return (dup);
}