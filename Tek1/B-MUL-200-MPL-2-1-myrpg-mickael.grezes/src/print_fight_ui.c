/*
** EPITECH PROJECT, 2021
** B-MUL-200-MPL-2-1-myrpg-mickael.grezes
** File description:
** print_fight_ui
*/

#include "my.h"

void print_ui(rpg_t *rpg)
{
    sfRenderWindow_drawSprite(rpg->window, rpg->s_fight, NULL);
    sfRenderWindow_drawText(rpg->window, rpg->fights->atk, NULL);
    sfRenderWindow_drawText(rpg->window, rpg->fights->magic, NULL);
    sfRenderWindow_drawText(rpg->window, rpg->fights->heal, NULL);
    sfRenderWindow_drawText(rpg->window, rpg->fights->escape, NULL);
}