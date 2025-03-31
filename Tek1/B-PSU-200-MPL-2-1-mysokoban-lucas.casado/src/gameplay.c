/*
** EPITECH PROJECT, 2021
** B-PSU-200-MPL-2-1-mysokoban-lucas.casado
** File description:
** gameplay
*/

#include "../include/include.h"

void getp(perso_s *play)
{
    int y = 0;
    int x = 0;

    for (; play->map[y]; y++) {
        for (x = 0; play->map[y][x]; x++) {
            if (play->map[y][x] == 'P') {
                play->player.x = x;
                play->player.y = y;
            }
        }
    }
}

void printgame(perso_s *play, int row, int col)
{
    if (printresize(play, row, col) == 0)
        printmap(play);
}

void display(perso_s *play)
{
    int row;
    int col;

    initscr();
    keypad(stdscr, TRUE);
    while (1) {
        getmaxyx(stdscr, row, col);
        clear();
        getp(play);
        printgame(play, row, col);
        event(play, getch());
        refresh();
        win(play);
        loose(play);
    }
    endwin();
}

int start(char *av)
{
    perso_s play;
    char *content = map_read(av);
    play.map = my_str_to_word_array(map_read(av), "\n");
    play.save = my_str_to_word_array(map_read(av), "\n");

    if (validmap(content, &play) == 84)
        return (84);
    display(&play);
}