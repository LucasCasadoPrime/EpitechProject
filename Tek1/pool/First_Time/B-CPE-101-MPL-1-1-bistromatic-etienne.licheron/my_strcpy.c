/*
** EPITECH PROJECT, 2020
** mt_strcpy
** File description:
** function copy string into string
*/

char *my_strcpy( char *dest, char const *src)
{
    int i = 0;
    while (src[i] != 0) {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return (dest);
}
