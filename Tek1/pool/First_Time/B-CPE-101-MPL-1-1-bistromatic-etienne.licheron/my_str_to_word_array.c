/*
** EPITECH PROJECT, 2020
** str_to_word_array
** File description:
** Put multiples word in a **
*/

#include <stdio.h>
#include <stdlib.h>

void apply(char **result, char const *str)
{
    int row = 0;
    int current = 0;

    result[0][0] = '0';
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == 32) {
            row++;
            current = 0;
        }
        else {
            result[row][current] = str[i];
            current++;
        }
    }
    result[row] = NULL;
}

char **my_str_to_word_array(char const *str)
{
    char **result;
    int row = 0;
    int current = 0;

    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] == 32)
            row++;
    result = malloc(sizeof(char *) * row);
    row = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == 32) {
            result[row] = malloc(sizeof(char) * current);
            current = 0;
            row++;
        }
        else
            current++;
    }
    apply(result, str);
    return (result);
}