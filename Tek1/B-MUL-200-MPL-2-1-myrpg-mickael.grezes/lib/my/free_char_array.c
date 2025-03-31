/*
** EPITECH PROJECT, 2021
** LibMy
** File description:
** free_char_array
*/

#include <stdlib.h>

void free_char_array(char **array)
{
    if (array == NULL)
        return;
    for (int i = 0; array[i] != 0; i++)
        free(array[i]);
    free(array);
}