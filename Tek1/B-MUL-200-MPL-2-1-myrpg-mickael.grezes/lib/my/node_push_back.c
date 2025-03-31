/*
** EPITECH PROJECT, 2021
** LibMy
** File description:
** node_push_back
*/

#include <stdlib.h>
#include "my.h"

void node_push_back(node **head, void *value)
{
    node *elem = malloc(sizeof(*elem));
    node *tmp;

    elem->value = value;
    elem->next = NULL;
    if ((*head) == NULL)
        (*head) = elem;
    else {
        for (tmp = (*head); tmp->next != NULL; tmp = tmp->next);
        tmp->next = elem;
    }
}