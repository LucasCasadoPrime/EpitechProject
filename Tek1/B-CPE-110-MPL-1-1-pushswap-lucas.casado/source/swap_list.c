/*
** EPITECH PROJECT, 2020
** B-CPE-110-MPL-1-1-pushswap-lucas.casado
** File description:
** swap_list
*/

#include "push_swap.h"

void swap_list(head *chain, movement nb)
{
    node *tmp = chain->first;
    int value;
    bool t = true;
    
    if (tmp != NULL && tmp->next != NULL && t == false) {
        value = tmp->value;
        tmp->value = tmp->next->value;
        tmp->next->value = value;
        if (nb.step == 0)
            write(1, "sa", 2);
        else
            write(1, " sa", 3);
    }
}