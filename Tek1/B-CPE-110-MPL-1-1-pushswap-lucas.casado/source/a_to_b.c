/*
** EPITECH PROJECT, 2020
** B-CPE-110-MPL-1-1-pushswap-lucas.casado
** File description:
** a_to_b
*/

#include "push_swap.h"

void a_to_b(head *chain_a, head *chain_b, movement nb)
{
    if (chain_a != NULL && chain_a->first != NULL) {
        push_front(chain_b, chain_a->first->value);
        pop_front(chain_a);
        if (nb.step == 0)
            write(1, "pb", 2);
        else
            write(1, " pb", 3);
    }
}