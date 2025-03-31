/*
** EPITECH PROJECT, 2021
** B-PSU-200-MPL-2-1-mysokoban-lucas.casado
** File description:
** include
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>

typedef struct all_s
{
    char **map;
    int line;
    int max;
    int scene;
    int ai;
}all;

int good_match(char *match, all *all, int match_left);
int good_line(char *line, all *all);
void put_matches(all *all);
void create_map(all *all);
void print_map(all *all, int n);
int nb_matches(int line, all *all);
char **malloc_map(all *all);
int my_getnbr(char const *str);
char **my_str_to_word_array(char *str, const char *separator);
char *my_memset(char *str, char c, int size);
int my_putstr(char *str);
void my_putchar(char c);
int my_strlen(char const *str);
int my_atoi(char *str);
void remove_match(all *all, int line, int match, int n);
void removed(all *all, int match, int line, int n);
int my_putnbr(int nb);
void player(all *all);
int nb_matches2(all *all);
void ia_turn(all *all);