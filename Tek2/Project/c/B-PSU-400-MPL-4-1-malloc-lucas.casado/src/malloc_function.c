/*
** EPITECH PROJECT, 2022
** B-PSU-400-MPL-4-1-malloc-lucas.casado
** File description:
** malloc_function
*/

#include "my_malloc.h"

void *reallocarray(void *ptr, size_t nmemb, size_t size)
{
    if (nmemb > 0 && SIZE_MAX / nmemb < size)
        return (NULL);
    else
        return (realloc(ptr, nmemb * size));
}

void *calloc(size_t nmemb, size_t size)
{
    unsigned char *pointer;
    size_t idx;

    if ((pointer = malloc(size * nmemb)) == NULL)
        return (NULL);
    for (idx = 0; idx < size; idx ++)
        pointer[idx] = 0;
    return (pointer);
}

void *realloc(void *pointer, size_t size)
{
    void *new_pointer;
    block_t *old;
    block_t *new;
    block_t *heap_start = NULL;

    new_pointer = malloc(size);
    if (new_pointer == NULL) {
        free(pointer);
        return (NULL);
    }
    old = find_block(heap_start, pointer);
    new = find_block(heap_start, new_pointer);
    if (old == NULL || new == NULL)
        return (new_pointer);
    memcpy(new, old, size);
    free(pointer);
    return (new_pointer);
}

void free(void *pointer)
{
    block_t *tempory;
    block_t *heap_start = NULL;

    if (pointer == NULL)
        return;
    tempory = heap_start;
    while (tempory != NULL) {
        if (tempory->address == pointer) {
            if (free_the_block(tempory) == NULL)
                heap_start = NULL;
            return;
        }
        tempory = tempory->next;
    }
}

void *malloc(size_t size)
{
    block_t *heap_start = NULL;
    block_t *block;

    if (size == 0)
        return (NULL);
    if (heap_start == NULL) {
        heap_start = create_page(size);
        if (heap_start == NULL)
            return (NULL);
        return (heap_start->address);
    }
    block = find_free_block(size, heap_start);
    if (block != NULL) {
        block->is_free = false;
        return (block->address);
    } else {
        block = create_block(size, heap_start);
        if (block == NULL)
            return (NULL);
        return (block->address);
    }
    return (NULL);
}