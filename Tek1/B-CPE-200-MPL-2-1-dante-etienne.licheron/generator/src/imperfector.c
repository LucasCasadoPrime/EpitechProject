/*
** EPITECH PROJECT, 2021
** B-CPE-200-MPL-2-1-dante-etienne.licheron
** File description:
** imperfector
*/

#include "generator.h"

void imperfector(all *all)
{
    int x = 0;
    int pos = rand() % 2;

    for (int i = 0; i < all->y; i += 1) {
        for (x = 0; x < all->x; x += 1) {
            pos = rand() % 2;
            if (pos == 1)
                all->map[i][x] = '*';
        }
    }
}