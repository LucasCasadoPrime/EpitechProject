/*
** EPITECH PROJECT, 2021
** LibMy
** File description:
** node_search
*/

#include <unistd.h>
#include "my.h"

node *node_nsearch(node **head, void *value, int nb)
{
    for (node *tmp = (*head); tmp != NULL; tmp = tmp->next)
        if (my_strncmp(tmp->value, value, nb) == 0)
            return (tmp);
    return (NULL);
}