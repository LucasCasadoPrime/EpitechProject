/*
** EPITECH PROJECT, 2020
** my_strcmp
** File description:
** Reproduction of the LibC function
*/

int my_strcmp(char const *s1, char const *s2)
{
    int i = 0;

    while (s1[i] == s2[i]) {
        if (s1[i] == 0) {
            break;
        }
        i++;
    }
    return (s1[i] - s2[i]);
}