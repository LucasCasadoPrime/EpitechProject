/*
** EPITECH PROJECT, 2022
** B-PSU-400-MPL-4-1-malloc-lucas.casado
** File description:
** create_page
*/

#include "my_malloc.h"

void *create_page(size_t const size)
{
    block_t *nmap;
    void *address;
    address = sbrk(size + sizeof(block_t));

    if (address == (void *)-1)
        return (NULL);
    nmap = address;
    nmap->is_free = false;
    nmap->prec = NULL;
    nmap->next = NULL;
    nmap->size = size;
    nmap->address = address + sizeof(block_t);
    return (nmap);
}
