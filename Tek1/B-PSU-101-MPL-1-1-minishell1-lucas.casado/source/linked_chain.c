/*
** EPITECH PROJECT, 2021
** B-PSU-101-MPL-1-1-minishell1-lucas.casado
** File description:
** linked_chain
*/

#include "sh.h"

void *my_memset(void *s, int c, int n)
{
    char *tmp;
    int	i;

    tmp = s;
    i = 0;
    while (i < n)
        tmp[i++] = c;
    return (tmp);
}

void *my_calloc(int nmemb, int size)
{
    void *ptr;

    if (!(ptr = malloc(nmemb * size)))
        return (NULL);
    ptr = my_memset(ptr, 0, nmemb * size);
    return (ptr);
}

void push_back(node **first, void *value)
{
    node *elem = my_calloc(1, sizeof(*elem));
    node *tmp;

    elem->value = value;
    elem->next = NULL;
    if ((*first) == NULL)
        (*first) = elem;
    else {
        for (tmp = (*first); tmp->next != NULL; tmp = tmp->next);
        tmp->next = elem;
    }
}