/*
** EPITECH PROJECT, 2022
** B-PSU-400-MPL-4-1-malloc-lucas.casado
** File description:
** malloc
*/

#include "my_malloc.h"

block_t *find_block(block_t *tempory, void *pointer)
{
    if (pointer == NULL)
        return (NULL);
    while (tempory != NULL) {
        if (tempory->address == pointer)
            return (tempory);
        tempory = tempory->next;
    }
    return (NULL);
}

static block_t *free_last_block(block_t *tempory, block_t *res)
{
    if (tempory->prec != NULL)
        tempory->prec->next = NULL;
    else
        res = NULL;
    sbrk((tempory->size + sizeof(block_t)) * -1);
    return (res);
}

block_t *free_the_block(block_t *tempory)
{
    block_t *dup;

    dup = tempory;
    tempory->is_free = true;

    while (tempory->prec != NULL && tempory->prec->is_free != false) {
        tempory->prec->size += tempory->size + sizeof(block_t);
        tempory->prec->next = tempory->next;
        if (tempory->next != NULL)
            tempory->next->prec = tempory->prec;
        tempory = tempory->prec;
    }
    while (tempory->next != NULL && tempory->next->is_free != false) {
        tempory->size += tempory->next->size + sizeof(block_t);
        tempory->next->next->prec = tempory;
        tempory->next = tempory->next->next;
    }
    if (tempory->next == NULL)
        dup = free_last_block(tempory, dup);
    return (dup);
}

block_t *find_free_block(size_t const size, block_t *tempory)
{
    if (tempory == NULL)
        return (NULL);
    while (tempory->next != NULL) {
        if (tempory->is_free == true && size <= tempory->size)
            return (tempory);
        tempory = tempory->next;
    }
    return (NULL);
}

void *create_block(size_t const size, block_t *tempory)
{
    void *address;
    address = sbrk(size + sizeof(block_t));

    while (tempory->next != NULL)
    tempory = tempory->next;
    if (address == (void *)-1)
        return (NULL);
    tempory->next = address;
    tempory->next->is_free = false;
    tempory->next->prec = tempory;
    tempory->next->next = NULL;
    tempory->next->size = size;
    tempory->next->address = address + sizeof(block_t);
    return (tempory->next);
}