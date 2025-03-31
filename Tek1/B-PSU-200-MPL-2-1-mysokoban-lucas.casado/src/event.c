/*
** EPITECH PROJECT, 2021
** B-PSU-200-MPL-2-1-mysokoban-lucas.casado
** File description:
** event
*/

#include "../include/include.h"

void move_up(perso_s *play, int key)
{
    if (key == KEY_UP) {
        if (blocker(play, play->player.x, play->player.y - 1) == false) {
            if (iscrate(play, play->player.x, play->player.y - 1) == true)
                move_up_crate(play);
            else {
                objectset(play, play->player.x, play->player.y, ' ');
                objectset(play, play->player.x, play->player.y - 1, 'P');
            }
        }
    }
}

void move_down(perso_s *play, int key)
{
    if (key == KEY_DOWN) {
        if (blocker(play, play->player.x, play->player.y + 1) == false) {
            if (iscrate(play, play->player.x, play->player.y + 1) == true)
                move_down_crate(play);
            else {
                objectset(play, play->player.x, play->player.y, ' ');
                objectset(play, play->player.x, play->player.y + 1, 'P');
            }
        }
    }
}

void move_left(perso_s *play, int key)
{
    if (key == KEY_LEFT) {
        if (blocker(play, play->player.x - 1, play->player.y) == false) {
            if (iscrate(play, play->player.x - 1, play->player.y) == true)
                move_left_crate(play);
            else {
                objectset(play, play->player.x, play->player.y, ' ');
                objectset(play, play->player.x - 1, play->player.y, 'P');
            }
        }
    }
}

void move_right(perso_s *play, int key)
{
    if (key == KEY_RIGHT) {
        if (blocker(play, play->player.x + 1, play->player.y) == false) {
            if (iscrate(play, play->player.x + 1, play->player.y) == true)
                move_rigth_crate(play);
            else {
                objectset(play, play->player.x, play->player.y, ' ');
                objectset(play, play->player.x + 1, play->player.y, 'P');
            }
        }
    }
}

void event(perso_s *play, int key)
{
    extrakeys(key, play);
    move_up(play, key);
    move_down(play, key);
    move_left(play, key);
    move_right(play, key);
}
