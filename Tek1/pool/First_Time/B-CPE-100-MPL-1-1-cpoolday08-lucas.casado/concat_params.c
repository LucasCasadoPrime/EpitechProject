/*
** EPITECH PROJECT, 2020
** day08
** File description:
** concat_params
*/
#include <my.h>
#include <stdlib.h>

char *my_concat_params(int argc, char **argv)
{
    char *maxrange;
    int dist;
    int count = 0;

    for (int i = 0; argc > i; i++) {
        dist = my_strlen(argv[i]);
    }
    maxrange = malloc(sizeof(char) * (dist + argc));
    for (int k = 0; k < argc; k++) {
        for (int j = 0; argv[k][j] != '\0'; j++) {
            maxrange[count] = argv[k][j];
            count++;
        }
        maxrange[count] = '\n';
        count++;
    }
    maxrange[count] = '\0';
    return (maxrange);
}
