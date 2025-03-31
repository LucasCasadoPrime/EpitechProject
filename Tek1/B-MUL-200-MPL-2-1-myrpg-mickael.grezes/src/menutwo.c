/*
** EPITECH PROJECT, 2021
** B-MUL-200-MPL-2-1-myrpg-mickael.grezes
** File description:
** menu2
*/

#include "my.h"

void game_menu2(rpg_t *rpg)
{
    update_music(rpg);
    sfRenderWindow_drawSprite(rpg->window, rpg->menu->sbg, NULL);
    sfRenderWindow_drawSprite(rpg->window, rpg->menu->s_play, NULL);
    sfRenderWindow_drawSprite(rpg->window, rpg->menu->s_settings, NULL);
    sfRenderWindow_drawSprite(rpg->window, rpg->menu->s_exit, NULL);
    sfRenderWindow_drawSprite(rpg->window, rpg->menu->s_continue, NULL);
}