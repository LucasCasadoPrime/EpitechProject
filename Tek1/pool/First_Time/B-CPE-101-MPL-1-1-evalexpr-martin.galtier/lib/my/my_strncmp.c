/*
** EPITECH PROJECT, 2020
** my strncmp
** File description:
** strncmp
*/

int my_strncmp(char const *s1, char const *s2, int n)
{
    int res = 0;
    int i = 0;

    while (s1[i] != '\0' && s2[i] != '\0' && i < n) {
        if (s1[i] != s2[i]) {
            res = s1[i] - s2[i];
            return (res);
        } else {
            i++;
        }
    }
    return (0);
}
