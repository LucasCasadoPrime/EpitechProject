/*
** EPITECH PROJECT, 2021
** LibMy
** File description:
** node_push_front
*/

#include <stdlib.h>
#include "my.h"

void node_push_front(node **head, void *value)
{
    node *elem = malloc(sizeof(*elem));

    elem->value = value;
    elem->next = (*head);
    (*head) = elem;
}