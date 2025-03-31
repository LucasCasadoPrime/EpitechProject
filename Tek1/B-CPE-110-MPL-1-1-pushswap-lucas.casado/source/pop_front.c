/*
** EPITECH PROJECT, 2020
** B-CPE-110-MPL-1-1-pushswap-lucas.casado
** File description:
** pop_front
*/

#include "push_swap.h"

void pop_front(head *chain)
{
    node *tmp;

    if (chain->first != NULL) {
        tmp = chain->first->next;
        free(chain->first);
        chain->first = tmp;
    }
}