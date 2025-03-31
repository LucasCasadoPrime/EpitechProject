/*
** EPITECH PROJECT, 2021
** B-CPE-200-MPL-2-1-matchstick-lucas.casado
** File description:
** map
*/

#include "../include/include.h"

char **malloc_map(all *all)
{
    int i = 0;
    char **map;

    map = malloc(sizeof(char *) * (all->line + 3));
    for (i = 0; i < (all->line + 2); i++) {
        map[i] = malloc(sizeof(char) * (all->line * 2) + 3);
    }
    map[i] = NULL;
    return (map);
}

void create_map(all *all)
{
    int i = 1;

    all->map = malloc_map(all);
    all->map[0] = my_memset(all->map[0], '*', (all->line * 2) + 1);
    for (i = 1; i < all->line + 1; i++) {
        all->map[i] = my_memset(all->map[i], ' ', (all->line * 2) + 1);
        all->map[i][0] = '*';
        all->map[i][all->line * 2] = '*';
    }
    all->map[all->line + 1] = my_memset(all->map[all->line + 1], \
    '*', (all->line * 2) + 1);
}

void put_matches(all *all)
{
    int x = all->line;
    int y = 1;
    int i = 0;

    for (i = 0; y <= all->line; i++) {
        x = (all->line - i);
        while (x < (all->line + i + 1)) {
            all->map[y][x] = '|';
            x++;
        }
        y++;
    }
}

void print_map(all *all, int n)
{
    int i;

    for (i = 0; all->map[i] != NULL; i++) {
        my_putstr(all->map[i]);
        my_putchar('\n');
    }
    if (n == 1)
        my_putchar('\n');
}