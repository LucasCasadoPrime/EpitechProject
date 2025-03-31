/*
** EPITECH PROJECT, 2021
** B-CPE-200-MPL-2-1-dante-etienne.licheron
** File description:
** open
*/

#include "solver.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}

int my_putstr(char *str)
{
    int i = 0;

    for (; str[i] != '\0'; i++)
        my_putchar(str[i]);
    return (1);
}

void map_open(char *filename, env *env)
{
    int fd = open(filename, O_RDONLY);
    char *content = NULL;
    struct stat s;

    stat(filename, &s);
    content = malloc(s.st_size + 1);
    read(fd, content, s.st_size);
    content[s.st_size] = 0;
    close(fd);
    env->maze = my_str_to_word_array(content, "\n");
    return;
}

char *map_read(char *av)
{
    int fd = open(av, O_RDONLY);
    char *content = NULL;
    struct stat s;

    stat(av, &s);
    content = malloc(s.st_size + 1);
    content[s.st_size] = 0;
    read(fd, content, s.st_size);
    close(fd);
    return (content);
}

void printmap(env *env)
{
    int i;

    for (i = 0; i < env->hauteur; i++) {
        write(1, env->maze[i], env->largeur);
        if (i < env->hauteur - 1)
            my_putchar('\n');
    }
}