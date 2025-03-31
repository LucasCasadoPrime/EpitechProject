/*
** EPITECH PROJECT, 2021
** LibMy
** File description:
** node_free_all
*/

#include <stdlib.h>
#include "my.h"

void node_free_all(node **head)
{
    node *tmp;

    for (; (*head) != NULL; free(tmp)) {
        tmp = (*head);
        (*head) = tmp->next;
        free(tmp->value);
    }
}