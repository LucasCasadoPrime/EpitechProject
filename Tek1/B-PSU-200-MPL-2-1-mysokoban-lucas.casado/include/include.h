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
#include <ncurses.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>

typedef struct pos {
    int x;
    int y;
} pos_s;

typedef struct perso {
    pos_s player;
    char **map;
    char **save;
}perso_s;

int my_putstr(char const *str);
int start(char *av);
int validmap(char *strmap, perso_s *play);
char **my_str_to_word_array(char *str, const char *separator);
char *map_read(char *av);
int findp(char **map);
void event(perso_s *play, int key);
bool blocker(perso_s *play, int x, int y);
void objectset(perso_s *play, int x, int y, char c);
bool iscrate(perso_s *play, int x, int y);
int goodfile(char *av);
void move_up_crate(perso_s *play);
void move_down_crate(perso_s *play);
void move_left_crate(perso_s *play);
void move_rigth_crate(perso_s *play);
bool wallcrate(perso_s *play, int x, int y);
void extrakeys(int key, perso_s *play);
void win(perso_s *play);
int printresize(perso_s *play, int row, int col);
void printmap(perso_s *play);
void loose(perso_s *play);
bool wallcratec(char c);
