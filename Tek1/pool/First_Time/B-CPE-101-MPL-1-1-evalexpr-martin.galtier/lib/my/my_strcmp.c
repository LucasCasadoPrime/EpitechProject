/*
** EPITECH PROJECT, 2020
** my_strcmp
** File description:
** calc the dif
*/

int my_strcmp(char const *s1, char const *s2)
{
    int res = 0;
    int i = 0;

    while (s1[i] != '\0' && s2[i] != '\0') {
        if (s1[i] != s2[i]) {
            res = s1[i] - s2[i];
            return (res);
        } else {
            i++;
        }
    }
    return (0);
}
