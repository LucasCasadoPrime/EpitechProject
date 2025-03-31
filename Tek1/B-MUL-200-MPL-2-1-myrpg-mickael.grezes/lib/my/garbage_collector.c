/*
** EPITECH PROJECT, 2021
** LibMy
** File description:
** garbage_collector
*/

#include <stdlib.h>
#include "my.h"

node **gc_get_list(void)
{
    static node *list = NULL;

    return (&list);
}

void *gc_add_ptr(void *ptr)
{
    node **list = gc_get_list();

    node_push_front(list, ptr);
    return (ptr);
}

__attribute__ ((alloc_size (1))) void *gc_malloc(size_t to_alloc)
{
    void *ptr = malloc(to_alloc);

    if (ptr == NULL)
        return (ptr);
    gc_add_ptr(ptr);
    return (ptr);
}

__attribute__ ((destructor)) void gc_destroy(void)
{
    node **list = gc_get_list();

    node_free_all(list);
}
