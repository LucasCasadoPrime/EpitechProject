/*
** EPITECH PROJECT, 2022
** B-PSU-400-MPL-4-1-malloc-lucas.casado
** File description:
** my_malloc
*/

#ifndef MY_MALLOC_H_
#define MY_MALLOC_H_

#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>

typedef struct	block_s block_t;

struct block_s {
    block_t *prec;
    block_t *next;
    bool is_free;
    size_t size;
    void *address;
};

//tools functions
block_t	*find_block(block_t *tempory, void *pointer);
block_t	*free_the_block(block_t *tempory);
block_t *find_free_block(size_t const size, block_t *tempory);
void *create_page(size_t const size);
void *create_block(size_t const size, block_t *tempory);

//malloc functions
extern void *malloc(size_t size);
extern void free(void *pointer);
extern void *calloc(size_t nb, size_t size);
extern void *realloc(void *pointer, size_t size);

#endif /* !MY_MALLOC_H_ */
