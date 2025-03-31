/*
** EPITECH PROJECT, 2020
** B-CPE-110-MPL-1-1-pushswap-lucas.casado
** File description:
** pop_back
*/

#include "push_swap.h"

void pop_back(head *chain)
{
    node *tmp;

    if (chain == NULL)
        exit(84);
    if (chain->first != NULL) {
        for (tmp = chain->first; tmp->next != NULL; tmp = tmp->next);
        free(tmp->next);
        tmp->next = NULL;
    }
}