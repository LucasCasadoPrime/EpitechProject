/*
** EPITECH PROJECT, 2021
** B-CPE-200-MPL-2-1-dante-etienne.licheron
** File description:
** generator
*/

#include "generator.h"

void optimize_maze(all *all)
{
    int x = 0;

    for (int i = 2; i < all->y + 1; i += 2) {
        for (x = 0; x < all->x; x += 2) {
            if (all->map[i - 1][x] == 'X' && all->map[i][x - 1] != 'X')
                all->map[i - 1][x] = '*';
            if (all->map[i][x - 1] == 'X' && all->map[i - 1][x] != 'X')
                all->map[i][x - 1] = '*';
            if (x > 0 && all->map[i][x - 1] == 'X' && all->map[i - 1][x] == 'X')
                random_place(all, i, x);
        }
    }
}

void create_maze(all *all)
{
    int x = 0;
    all->map[all->y][all->x - 2] = '*';
    for (int i = 0; i < all->y; i += 2) {
        for (x = 0; x < all->x; x += 2) {
            all->map[i][x] = '*';
        }
    }
    for (int i = 0; i < all->x; i += 1)
        all->map[0][i] = '*';
    optimize_maze(all);
}

void malloc_maze(all *all)
{
    int x = 0;

    all->map = malloc(sizeof(char *) * (all->y + 1));
    for (int i = 0; i < all->y + 1; i += 1) {
        all->map[i] = malloc(sizeof(char) * (all->x + 1));
        all->map[i][all->x] = '\0';
    }
    for (int y = 0; y < all->y + 1; y += 1) {
        for (x = 0; x < all->x; x += 1) {
            all->map[y][x] = 'X';
            if (y == 0 && x == 0)
                all->map[y][x] = '*';
            if (y == all->y - 1 && x == all->x - 1)
                all->map[y][x] = '*';
        }
    }
    return;
}

void free_maze(all *all)
{
    for (int y = 0; y < all->y; y += 1) {
            free(all->map[y]);
    }
    free(all->map);
}

void maze_generator(all *all, int status)
{
    srand(time(NULL) * getpid());
    malloc_maze(all);
    create_maze(all);
    if (all->y > 1 && all->x > 2)
        all->map[all->y - 1][all->x - 2] = '*';
    if (status == 2)
        imperfector(all);
    for (int i = 0; i < all->y; i += 1) {
        write(1, all->map[i], all->x);
        if (i != all->y - 1)
            write(1, "\n", 1);
    }
    free_maze(all);
    return;
}