/*
** EPITECH PROJECT, 2021
** LibMy
** File description:
** my_strndup
*/

void *my_calloc(int nb, int size);

int string_length(char const *str);

char *my_strncpy(char *dest, char const *src, int n);

char *my_strndup(const char *s, int n)
{
    char *dest = my_calloc(n + 1, sizeof(char));

    dest = my_strncpy(dest, s, n);
    return (dest);
}