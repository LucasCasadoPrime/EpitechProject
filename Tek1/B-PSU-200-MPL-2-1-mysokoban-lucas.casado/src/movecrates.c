/*
** EPITECH PROJECT, 2021
** B-PSU-200-MPL-2-1-mysokoban-lucas.casado
** File description:
** movecrates
*/

#include "../include/include.h"

void move_up_crate(perso_s *play)
{
    if (wallcrate(play, play->player.x, play->player.y - 2) == false) {
        objectset(play, play->player.x, play->player.y - 2, 'X');
        objectset(play, play->player.x, play->player.y - 1, 'P');
        objectset(play, play->player.x, play->player.y, ' ');
    }
}

void move_down_crate(perso_s *play)
{
    if (wallcrate(play, play->player.x, play->player.y + 2) == false) {
        objectset(play, play->player.x, play->player.y + 2, 'X');
        objectset(play, play->player.x, play->player.y + 1, 'P');
        objectset(play, play->player.x, play->player.y, ' ');
    }
}

void move_left_crate(perso_s *play)
{
    if (wallcrate(play, play->player.x - 2, play->player.y) == false) {
        objectset(play, play->player.x - 2, play->player.y, 'X');
        objectset(play, play->player.x - 1, play->player.y, 'P');
        objectset(play, play->player.x, play->player.y, ' ');
    }
}

void move_rigth_crate(perso_s *play)
{
    if (wallcrate(play, play->player.x + 2, play->player.y) == false) {
        objectset(play, play->player.x + 2, play->player.y, 'X');
        objectset(play, play->player.x + 1, play->player.y, 'P');
        objectset(play, play->player.x, play->player.y, ' ');
    }
}

void extrakeys(int key, perso_s *play)
{
    int y = 0;
    int x = 0;

    if (key == 27) {
        clear();
        refresh();
        endwin();
        exit(0);
    }
    if (key == 32) {
        for (; play->map[y]; y++) {
            for (x = 0; play->map[y][x]; x++) {
                play->map[y][x] = play->save[y][x];
            }
        }
    }
}