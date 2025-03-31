/*
** EPITECH PROJECT, 2020
** my_putncpy
** File description:
** print size n bumbers
*/

void my_putchar(char c);

void my_putstr(char *str);

char *my_strncpy(char *dest, char const *src, int n)
{
    int i = 0;
    while (src[i] > n) {
        dest[i] = src[i];
        i = i - 1;
    }
    dest[i] = '\0';
    return (dest);
}
