/*
** EPITECH PROJECT, 2021
** LibMy
** File description:
** node_node_to_array
*/

#include <unistd.h>
#include "my.h"

char **node_to_array(node **head)
{
    char **array = my_calloc(node_size(head) + 1, sizeof(char *));
    int i = 0;

    for (node *tmp = (*head); tmp != NULL; tmp = tmp->next) {
        array[i] = my_strdup(tmp->value);
        i++;
    }
    array[i] = 0;
    return (array);
}