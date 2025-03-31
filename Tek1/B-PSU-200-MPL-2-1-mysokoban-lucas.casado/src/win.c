/*
** EPITECH PROJECT, 2021
** B-PSU-200-MPL-2-1-mysokoban-lucas.casado
** File description:
** win
*/

#include "../include/include.h"

int x_in_o(perso_s *play, int y)
{
    for (int x = 0; play->save[y][x]; x++){
        if (play->save[y][x] == 'O' && play->map[y][x] != 'X')
            return (0);
    }
    return (1);
}

void win(perso_s *play)
{
    for (int y = 0; play->save[y]; y++) {
        if (x_in_o(play, y) == 0)
            return;
    }
    clear();
    refresh();
    endwin();
    exit(0);
}

int count_o(perso_s *play)
{
    int o = 0;

    for (int y = 0; play->save[y]; y++) {
        for (int x = 0; play->save[y][x]; x++) {
            if (play->save[y][x] == 'O')
                o++;
        }
    }
    return (o);
}

int x_in_corner(perso_s *play)
{
    int equal = 0;

    for (int y = 0; play->map[y]; y++) {
        for (int x = 0; play->map[y][x]; x++) {
            if ((play->map[y][x] == 'X' && play->save[y][x] != 'O') && ( \
            (wallcratec(play->map[y - 1][x]) == 0 && \
            wallcratec(play->map[y][x + 1]) == 0) || \
            (wallcratec(play->map[y - 1][x]) == 0 && \
            wallcratec(play->map[y][x - 1]) == 0) || \
            (wallcratec(play->map[y + 1][x]) == 0 && \
            wallcratec(play->map[y][x + 1]) == 0) || \
            (wallcratec(play->map[y + 1][x]) == 0 && \
            wallcratec(play->map[y][x - 1]) == 0)))
                equal++;
        }
    }
    return (equal);
}

void loose(perso_s *play)
{
    int nb_o = count_o(play);
    int nb_x = x_in_corner(play);

    if (nb_o == nb_x) {
        clear();
        refresh();
        endwin();
        exit(1);
    }
}