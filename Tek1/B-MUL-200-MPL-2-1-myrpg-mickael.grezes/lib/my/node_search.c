/*
** EPITECH PROJECT, 2021
** LibMy
** File description:
** node_search
*/

#include <unistd.h>
#include "my.h"

node *node_search(node **head, void *value)
{
    for (node *tmp = (*head); tmp != NULL; tmp = tmp->next)
        if (tmp->value == value)
            return (tmp);
    return (NULL);
}