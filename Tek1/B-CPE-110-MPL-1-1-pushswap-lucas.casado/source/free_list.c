/*
** EPITECH PROJECT, 2020
** B-CPE-110-MPL-1-1-pushswap-lucas.casado
** File description:
** free_list
*/

#include "push_swap.h"

void free_list(head *chain)
{
    node *tmp;

    if (chain != NULL) {
        if (chain->first != NULL) {
            for (tmp = chain->first; tmp != NULL; tmp = chain->first) {
                tmp = tmp->next;
                free(chain->first);
                chain->first = tmp;
            }
        }
        free(chain);
    }
}