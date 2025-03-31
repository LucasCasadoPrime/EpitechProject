/*
** EPITECH PROJECT, 2021
** B-MUL-200-MPL-2-1-myrpg-mickael.grezes
** File description:
** spawn
*/

#include "my.h"

void init_spawn(rpg_t *rpg)
{
    rpg->game->linkhouse = sfSprite_create();
    rpg->game->tlinkhouse = sfTexture_createFromFile("assets/house.png", NULL);
    sfSprite_setTexture(rpg->game->linkhouse, rpg->game->tlinkhouse, sfTrue);
    sfSprite_setScale(rpg->game->linkhouse, (sfVector2f){3, 3});
}

void spawn(rpg_t *rpg)
{
    sfRenderWindow_clear(rpg->window, sfBlack);
    sfRenderWindow_drawSprite(rpg->window, rpg->game->linkhouse, NULL);
    sfRenderWindow_drawSprite(rpg->window, rpg->link->sprite, NULL);
    cursor(rpg);
    if (rpg->link->interact != 0)
        sfRenderWindow_drawSprite(rpg->window, rpg->game->sinter, NULL);
    if (rpg->game->inv == 1)
        display_inventory(rpg);
    save(rpg);
}