/*
** EPITECH PROJECT, 2021
** LibMy
** File description:
** node_exists
*/

#include <unistd.h>
#include "my.h"

int node_exists(node **head, node *to_detect)
{
    if ((*head) == NULL)
        return (-1);
    for (node *tmp = (*head); tmp; tmp = tmp->next)
        if (tmp == to_detect)
            return (1);
    return (0);
}