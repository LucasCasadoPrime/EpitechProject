/*
** EPITECH PROJECT, 2021
** B-PSU-200-MPL-2-1-mysokoban-lucas.casado
** File description:
** print
*/

#include "../include/include.h"

int mapsize(perso_s *play, int dir)
{
    int i = 0;

    if (dir == 0)
        for (; play->map[i]; i++);
    else
        for (; play->map[0][i]; i++);
    return (i);
}

void printchar(perso_s *play, char c, int i , int j)
{
    if (play->save[i][j] == 'O' && play->map[i][j] != 'P' && \
    play->map[i][j] != 'X')
        printw("O");
    else
        printw("%c", c);
}

void printmap(perso_s *play)
{
    for (int i = 0; play->map[i]; i++) {
        for (int j = 0; play->map[i][j]; j++)
            printchar(play, play->map[i][j], i, j);
        if (i != mapsize(play, 0) - 1)
            printw("\n");
    }
}

int printresize(perso_s *play, int row, int col)
{
    if (row < mapsize(play, 0) || col < mapsize(play, 1)) {
        if (col / 2 - 19 >= 0)
            mvprintw(row / 2, col / 2 - 19, "Your screen is small "\
            "please resize you window.\n");
        else
            mvprintw(row / 2, 0, "Your screen is small" \
            "please resize you window.\n");
        return (1);
    }
    return (0);
}