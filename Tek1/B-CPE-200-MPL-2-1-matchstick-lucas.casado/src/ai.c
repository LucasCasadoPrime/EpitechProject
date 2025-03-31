/*
** EPITECH PROJECT, 2021
** B-CPE-200-MPL-2-1-matchstick-lucas.casado
** File description:
** ai
*/

#include "../include/include.h"

void ia_turn(all *all)
{
    int i = 0;
    int x = 0;

    for (; all->map[i]; i += 1) {
        for (x = 0; all->map[i][x]; x += 1) {
            if (all->map[i][x] == '|' && all->map[i][x + 1] == '*') {
                all->ai = i;
                remove_match(all, i, 1, 2);
                return;
            }
            if (all->map[i][x] == '|' && all->map[i][x + 1] == ' ') {
                all->ai = i;
                remove_match(all, i, 1, 2);
                return;
            }
        }
    }
}