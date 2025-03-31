/*
** EPITECH PROJECT, 2020
** B-CPE-110-MPL-1-1-pushswap-lucas.casado
** File description:
** push_back
*/

#include "push_swap.h"

void push_back(head *chain, int value)
{
    node *train = malloc(sizeof(*train));
    node *tmp;

    if (chain == NULL || train == NULL)
        exit(84);
    train->value = value;
    train->next = NULL;
    if (chain->first = NULL)
        chain->first = train;
    else {
        for (tmp = chain->first; tmp->next != NULL; tmp = tmp->next);
        tmp->next = train;
    }   
}