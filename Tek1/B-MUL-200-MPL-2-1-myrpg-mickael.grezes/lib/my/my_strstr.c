/*
** EPITECH PROJECT, 2020
** LibMy
** File description:
** my_strstr
*/

#include <unistd.h>

char *my_strstr(char *str, char const *to_find)
{
    if (str == NULL || to_find == NULL)
        return (NULL);
    for (int i = 0; str[i] != 0; i += 1)
        for (int x = 0; str[i + x] == to_find[x]; x++)
            if (to_find[x + 1] == 0)
                return (&str[i]);
    if (to_find[0] == 0)
        return (str);
    return (NULL);
}