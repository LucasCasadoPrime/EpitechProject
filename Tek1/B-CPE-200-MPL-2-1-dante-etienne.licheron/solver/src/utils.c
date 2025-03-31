/*
** EPITECH PROJECT, 2021
** B-CPE-200-MPL-2-1-dante-etienne.licheron
** File description:
** utils
*/

#include "solver.h"

int validchar(char *str)
{
    int y = 0;

    for (; str[y]; y++) {
        if (str[y] != '*' && str[y] != '\n' && str[y] != 'X')
            return (84);
    }
    return (0);
}

void obtain_size(env *env)
{
    int y = 0;
    int x = 0;

    for (; env->maze[y]; y++) {
        for (x = 0; env->maze[y][x]; x++);
    }
    env->hauteur = y;
    env->largeur = x;
}

void goodfile(char *av)
{
    struct stat sb;
    int return_value;

    return_value = lstat(av, &sb);
    if (return_value == -1 || !S_ISREG(sb.st_mode))
        exit(84);
}

void free_map(env *env)
{
    int i;

    for (i = 0; i < env->hauteur; i++)
        free(env->maze[i]);
    free(env->maze);
}