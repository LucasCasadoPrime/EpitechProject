/*
** EPITECH PROJECT, 2021
** B-MUL-200-MPL-2-1-myrpg-mickael.grezes
** File description:
** my_strncmp
*/

int my_strncmp(char const *s1, char const *s2, int n)
{
    int i = 0;
    int diff = 0;
    for (; i != n; i += 1)
        diff += s1[i] - s2[i];
    if (diff == 0)
        return (0);
    if (diff > 0)
        return (1);
    return (-1);
}