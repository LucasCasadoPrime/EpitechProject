/*
** EPITECH PROJECT, 2020
** B-CPE-110-MPL-1-1-pushswap-lucas.casado
** File description:
** print_list
*/

#include "push_swap.h"

void print_list(head *chain)
{
    node *tmp = chain->first;
    
    for (; tmp != NULL; tmp = tmp->next)
        printf("%d\n", tmp->value);
}