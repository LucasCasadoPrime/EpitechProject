/*
** EPITECH PROJECT, 2020
** day08
** File description:
** my_strdup
*/
#include <stdlib.h>
#include <my.h>

char *my_strdup(char const *src)
{

    char *message;
    int i = 0;
    message = malloc(sizeof(char) * (my_strlen(src) + 1));
    while (src[i] != 0) {
        message[i] = src[i];
        i = i + 1;
    }
    message = 0;
    return (message);
}
