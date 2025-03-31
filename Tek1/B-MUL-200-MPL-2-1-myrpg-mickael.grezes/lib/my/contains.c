/*
** EPITECH PROJECT, 2021
** LibMy
** File description:
** contains
*/

int check_contains(char c, char *to_verify)
{
    for (int i = 0; to_verify[i]; i++)
        if (to_verify[i] == c)
            return (1);
    return (0);
}

int contains(char *str, char *to_verify)
{
    for (int i = 0; str[i]; i++)
        if (check_contains(str[i], to_verify) == 1)
            return (1);
    return (0);
}