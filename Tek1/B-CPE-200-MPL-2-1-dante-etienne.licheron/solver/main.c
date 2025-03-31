/*
** EPITECH PROJECT, 2021
** Dante
** File description:
** main
*/

#include "solver.h"

int pathfinder(int x, int y, env *env, int i)
{
    env->maze[y][x] = 'o';
    if (i == 174467)
        return (-1);
    if (x == env->largeur - 1 && y == env->hauteur - 1)
        return (0);
    if (x + 1 < env->largeur && env->maze[y][x + 1] == '*')
        if (pathfinder(x + 1, y, env, i + 1) == 0)
            return (0);
    if (y + 1 < env->hauteur && env->maze[y + 1][x] == '*')
        if (pathfinder(x, y + 1, env, i + 1) == 0)
            return (0);
    if (x - 1 >= 0 && env->maze[y][x - 1] == '*')
        if (pathfinder(x - 1, y, env, i + 1) == 0)
            return (0);
    if (y - 1 >= 0 && env->maze[y - 1][x] == '*')
        if (pathfinder(x, y - 1, env, i + 1) == 0)
            return (0);
    env->maze[y][x] = 'a';
    return (-1);
}

void interpretor(env *env)
{
    int x = 0;
    int y = 0;

    for (; env->maze[y]; y++) {
        for (x = 0; env->maze[y][x]; x++){
            if (env->maze[y][x] == 'a')
                env->maze[y][x] = '*';
        }
    }
}

int main(int ac, char **av)
{
    env env;
    if (ac != 2)
        return (84);
    goodfile(av[1]);
    if (validchar(map_read(av[1])) == 84)
        return (84);
    map_open(av[1], &env);
    obtain_size(&env);
    if (env.hauteur == 0)
        return (84);
    if (pathfinder(0, 0, &env, 0) == -1) {
        fprintf(stderr, "no solution found\n");
        return (84);
    }
    interpretor(&env);
    printmap(&env);
    free_map(&env);
    return (0);
}