/*
** EPITECH PROJECT, 2021
** Dante
** File description:
** main
*/

#include "generator.h"

int main(int ac, char **av)
{
    all all;
    if (ac == 4) {
        if (atoi(av[1]) == 0 || atoi(av[2]) == 0)
            return (84);
        all.x = atoi(av[1]);
        all.y = atoi(av[2]);
        if (strcmp(av[3], "perfect") == 0) {
            maze_generator(&all, 1);
            return (0);
        }
        return (84);
    }
    else if (ac == 3) {
        if (atoi(av[1]) == 0 || atoi(av[2]) == 0)
            return (84);
        all.x = atoi(av[1]);
        all.y = atoi(av[2]);
        maze_generator(&all, 2);
    }
    return (0);
}