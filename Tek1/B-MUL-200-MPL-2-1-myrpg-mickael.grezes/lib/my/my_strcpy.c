/*
** EPITECH PROJECT, 2021
** B-MUL-200-MPL-2-1-myrpg-mickael.grezes
** File description:
** my_strcpy
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