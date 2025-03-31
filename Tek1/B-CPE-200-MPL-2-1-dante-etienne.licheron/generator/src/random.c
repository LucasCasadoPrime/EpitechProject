/*
** EPITECH PROJECT, 2021
** B-CPE-200-MPL-2-1-dante-etienne.licheron
** File description:
** random
*/

#include "generator.h"

void random_place(all *all, int i, int x)
{
    int pos = rand() % 2;

    if (pos == 1)
        all->map[i][x - 1] = '*';
    else
        all->map[i - 1][x] = '*';
}