/*
** EPITECH PROJECT, 2021
** LibMy
** File description:
** node_free_all
*/

#include <stdlib.h>
#include "my.h"

void node_free_one(node **head, node *to_del)
{
    node *tmp;
    node *change;

    if ((*head) == NULL || to_del == NULL || node_exists(head, to_del) != 1)
        return;
    if ((*head) == to_del) {
        (*head) = to_del->next;
        free(to_del->value);
        free(to_del);
        return;
    }
    for (tmp = (*head); tmp->next != to_del; tmp = tmp->next);
    change = tmp->next->next;
    free(tmp->next->value);
    free(tmp->next);
    tmp->next = change;
}