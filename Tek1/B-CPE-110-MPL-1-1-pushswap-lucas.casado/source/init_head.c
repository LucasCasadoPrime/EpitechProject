/*
** EPITECH PROJECT, 2020
** B-CPE-110-MPL-1-1-pushswap-lucas.casado
** File description:
** init_head
*/

#include "push_swap.h"

head *init_head(void)
{
    head *chain = malloc(sizeof(*chain));
    chain->first = NULL;
    return (chain);
}