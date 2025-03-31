/*
** EPITECH PROJECT, 2021
** LibMy
** File description:
** node_size
*/

#include <unistd.h>
#include "my.h"

int node_size(node **head)
{
    int i = 0;

    for (node *tmp = (*head); tmp != NULL; tmp = tmp->next)
        i++;
    return (i);
}