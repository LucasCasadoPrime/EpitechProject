/*
** EPITECH PROJECT, 2021
** B-MUL-200-MPL-2-1-myrpg-mickael.grezes
** File description:
** menu
*/

#include "my.h"
#include <stdio.h>

void game_menu(rpg_t *rpg)
{
    rpg->menu->time = sfClock_getElapsedTime(rpg->menu->clock);
    rpg->menu->seconds = rpg->menu->time.microseconds / 1000000.0;
    if (rpg->menu->seconds > 0.5) {
        rpg->menu->rectbg.left += 1920;
        if (rpg->menu->rectbg.left == 3840)
            rpg->menu->rectbg.left = 0;
        sfSprite_setTextureRect(rpg->menu->sfirstbg, rpg->menu->rectbg);
        sfClock_restart(rpg->menu->clock);
    }
    sfRenderWindow_drawSprite(rpg->window, rpg->menu->sfirstbg, NULL);
}

void destroy_menu(rpg_t *rpg)
{
    sfTexture_destroy(rpg->menu->tfirstbg);
    sfSprite_destroy(rpg->menu->sfirstbg);
    sfClock_destroy(rpg->menu->clock);
    sfTexture_destroy(rpg->menu->tbg);
    sfSprite_destroy(rpg->menu->sbg);
    sfTexture_destroy(rpg->menu->t_play);
    sfSprite_destroy(rpg->menu->s_play);
    sfTexture_destroy(rpg->menu->t_continue);
    sfSprite_destroy(rpg->menu->s_continue);
    sfTexture_destroy(rpg->menu->t_settings);
    sfSprite_destroy(rpg->menu->s_settings);
    sfTexture_destroy(rpg->menu->t_exit);
    sfSprite_destroy(rpg->menu->s_exit);
}

void destroy_entity(rpg_t *rpg)
{
    sfClock_destroy(rpg->link->c_fight);
    sfClock_destroy(rpg->effect->clock);
    sfTexture_destroy(rpg->link->t_fight);
    sfTexture_destroy(rpg->effect->texture);
    sfSprite_destroy(rpg->link->s_fight);
    sfSprite_destroy(rpg->fights->lifebar);
    sfSprite_destroy(rpg->s_fight);
    sfSprite_destroy(rpg->effect->sprite);
    sfText_destroy(rpg->fights->atk);
    sfText_destroy(rpg->fights->heal);
    sfText_destroy(rpg->fights->magic);
    sfText_destroy(rpg->fights->escape);
}