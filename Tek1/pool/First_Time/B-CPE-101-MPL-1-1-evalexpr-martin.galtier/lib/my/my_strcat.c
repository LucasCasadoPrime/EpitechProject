/*
** EPITECH PROJECT, 2020
** strcat
** File description:
** concat
*/
#include <stdlib.h>
#include "my.h"

char *my_strcat(char *s1, char *s2)
{
    int i = 0;
    int j = 0;
    char *result = NULL;
    int s1_size = my_strlen(s1);
    int s2_size = my_strlen(s2);

    result = malloc(sizeof(char) * (s1_size + s2_size + 1));

    while (s1 != NULL && s1[i] != '\0') {
        result[i] = s1[i];
        i++;
    }
    while (s2 != NULL && s2[i] != '\0') {
        result[i] = s2[j];
        j++;
        i++;
    }
    result[i] = '\0';
    return (result);
}
