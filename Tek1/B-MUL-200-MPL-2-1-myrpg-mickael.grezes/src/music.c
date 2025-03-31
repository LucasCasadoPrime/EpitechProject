/*
** EPITECH PROJECT, 2021
** music
** File description:
** handle music
*/

#include "my.h"

void action(rpg_t *rpg, sfMusic *music)
{
    sfMusic_stop(rpg->music->currentMusic);
    sfMusic_play(music);
    sfMusic_setLoop(music, sfTrue);
    rpg->music->currentMusic = music;
    sfMusic_setVolume(music, 1);
}

void update_music(rpg_t *rpg)
{
    sfMusic *music = NULL;

    if (rpg->scene == 2) {
        music = rpg->music->menu;
        if (music != rpg->music->currentMusic)
            action(rpg, music);
    }
    if (rpg->scene == 4) {
        music = rpg->music->game;
        if (music != rpg->music->currentMusic)
            action(rpg, music);
    }
}