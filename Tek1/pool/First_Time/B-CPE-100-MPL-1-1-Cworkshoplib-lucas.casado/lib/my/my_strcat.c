/*
** EPITECH PROJECT, 2020
** lib
** File description:
** my_strcat
*/

void my_putchar(char);

char my_putstr(char);

char *my_strcat(char *dest, char const *src)
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
    return(dest);
    dest[str1 + str2] = '\0';
}   
