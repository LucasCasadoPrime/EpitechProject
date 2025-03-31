/*
** EPITECH PROJECT, 2021
** B-CPE-200-MPL-2-1-dante-etienne.licheron
** File description:
** generator
*/

#ifndef GENERATOR_H_
#define GENERATOR_H_

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

typedef struct all_s
{
    int x;
    int y;
    char **map;
}all;

void *my_calloc(int nb, int size);
void maze_generator(all *all, int status);
void random_place(all *all, int i, int x);
void imperfector(all *all);

#endif /* !GENERATOR_H_ */