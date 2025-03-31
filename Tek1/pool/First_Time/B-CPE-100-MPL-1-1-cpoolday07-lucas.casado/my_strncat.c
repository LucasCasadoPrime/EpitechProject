/*
** EPITECH PROJECT, 2020
** lib
** File description:
** my_strncat
*/

void my_putchar(char);

char my_putstr(char);

char *my_strncat(char *dest, char const *src, int n)
{
    int i = 0;
    int str1 = 0;
    int str2 = 0;

    while (src[str1] != '\0') {
        str1 = str1 + 1;
    }
    while (dest[str2] != '\0') {
        str2 = str2 +1;
    }
   
    while (i < (str1 + str2)) {
        dest[str1 + i] = src[i];
        i = i + 1;
    }
    dest[str1 + str2] = '\0';
    while (dest[i] <= n) {
        n = n + 1;
    }
    return (n);
}
