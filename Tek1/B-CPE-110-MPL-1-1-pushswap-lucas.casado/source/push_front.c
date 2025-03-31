/*
** EPITECH PROJECT, 2020
** B-CPE-110-MPL-1-1-pushswap-lucas.casado
** File description:
** push_front
*/

#include "push_swap.h"

void push_front(head *chain, int value)
{
    node *train = malloc(sizeof(*train));
    
    if (chain == NULL || train == NULL)
        exit(84);
    train->value = value;
    train->next = chain->first;
    chain->first = train;
}