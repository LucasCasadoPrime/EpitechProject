/*
** EPITECH PROJECT, 2020
** B-CPE-110-MPL-1-1-pushswap-lucas.casado
** File description:
** push_swap
*/

#ifndef PUSH_SWAP_H_
#define PUSH_SWAP_H_

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>

typedef struct head_s {
    struct node_s *first;  
}head;

typedef struct node_s {
    int value;
   struct node_s *next;
}node;

typedef struct movement_s
{
    int step;
}movement;

head *init_head(void);
void push_front(head *chain, int value);
void print_list(head *chain);
void push_back(head *chain, int value);
void pop_front(head *chain);
void pop_back(head *chain);
void free_list(head *chain);
void swap_list(head *chain, movement nb);
void a_to_b(head *chain_a, head *chain_b, movement nb);
void b_to_a(head *chain_b, head *chain_a);
int my_strlen(char const *str);
void convert_to_number(char c, int *number);
int is_number(char c);
void neg_task(char c, int *isneg);
int my_getnbr(char const *str);
int my_putstr (char const *str);
void my_putchar(char c);
void sort(head *chain_a, head *chain_b);

#endif /* !PUSH_SWAP_H_ */
