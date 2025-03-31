/*
** EPITECH PROJECT, 2021
** LibMy
** File description:
** my_strdup
*/

#include <unistd.h>

void *my_calloc(int nb, int size);

int string_length(char const *str);

char *my_strcpy(char *dest, char const *src);

char *my_strdup(const char *s)
{
    char *dest = my_calloc(string_length(s) + 1, sizeof(char));

    if (dest == NULL)
        return (NULL);
    dest = my_strcpy(dest, s);
    return (dest);
}