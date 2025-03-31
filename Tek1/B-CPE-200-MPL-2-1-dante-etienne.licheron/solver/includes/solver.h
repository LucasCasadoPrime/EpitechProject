/*
** EPITECH PROJECT, 2021
** B-CPE-200-MPL-2-1-dante-etienne.licheron
** File description:
** solver
*/

#ifndef SOLVER_H_
#define SOLVER_H_

#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>

typedef struct env_s {
    char **maze;
    int hauteur;
    int largeur;
}env;

void map_open(char *file, env *env);
void obtain_size(env *env);
int validchar(char *str);
void printmap(env *env);
char **my_str_to_word_array(char *str, const char *separator);
void goodfile(char *av);
char *map_read(char *av);
int pathfinder(int x, int y,env *env, int i);
void interpretor(env *env);
void free_map(env *env);

#endif /* !SOLVER_H_ */
