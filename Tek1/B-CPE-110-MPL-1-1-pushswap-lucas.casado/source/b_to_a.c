/*
** EPITECH PROJECT, 2020
** B-CPE-110-MPL-1-1-pushswap-lucas.casado
** File description:
** b_to_a
*/

#include "push_swap.h"

void b_to_a(head *chain_b, head *chain_a)
{
    
    if (chain_b != NULL && chain_b->first != NULL) {
        push_front(chain_a, chain_b->first->value);
        pop_front(chain_b);
        write(1, " pa", 3);
    }
}