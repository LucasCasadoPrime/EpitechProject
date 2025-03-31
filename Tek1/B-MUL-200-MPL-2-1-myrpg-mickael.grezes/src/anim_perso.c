/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** anim_perso
*/

#include "my.h"

void link_init(rpg_t *rpg)
{
    rpg->link->texture = sfTexture_createFromFile("assets/link.png", NULL);
    rpg->link->rect = (sfIntRect){0, 6, 22, 25};
    rpg->link->sprite = sfSprite_create();
    sfSprite_setTexture(rpg->link->sprite, rpg->link->texture, sfTrue);
    sfSprite_setTextureRect(rpg->link->sprite, rpg->link->rect);
    sfSprite_setPosition(rpg->link->sprite, (sfVector2f){850, 450});
    sfSprite_setScale(rpg->link->sprite, (sfVector2f){3, 3});
    rpg->link->clock = sfClock_create();
    rpg->link->pv = 100;
    rpg->link->m_damages = 5;
    rpg->link->nb_potions = 5;
    rpg->link->s_fight = sfSprite_create();
    rpg->link->t_fight = sfTexture_createFromFile("assets/link_f.png", NULL);
    sfSprite_setTexture(rpg->link->s_fight, rpg->link->t_fight, sfTrue);
    rpg->link->r_fight = (sfIntRect){0, 0, 288, 288};
    rpg->link->c_fight = sfClock_create();
    rpg->link->interact = 0;
}

void link_walk_top(rpg_t *rpg)
{
    sfSprite_move(rpg->game->smap, (sfVector2f){0, 3 + actual_lvl()});
    sfSprite_move(rpg->game->soverlay, (sfVector2f){0, 3 + actual_lvl()});
    rpg->link->rect.top = 6;
    if (rpg->link->seconds > 0.04) {
        rpg->link->rect.left += 24;
    if (rpg->link->rect.left >= 288)
        rpg->link->rect.left = 0;
    sfSprite_setTextureRect(rpg->link->sprite, rpg->link->rect);
    sfClock_restart(rpg->link->clock);
    }
    sfRenderWindow_drawSprite(rpg->window, rpg->link->sprite, NULL);
}

void link_walk_left(rpg_t *rpg)
{
    sfSprite_move(rpg->game->smap, (sfVector2f){3 + actual_lvl(), 0});
    sfSprite_move(rpg->game->soverlay, (sfVector2f){3 + actual_lvl(), 0});
    rpg->link->rect.top = 102;
    if (rpg->link->seconds > 0.04) {
        rpg->link->rect.left += 24;
    if (rpg->link->rect.left >= 288)
        rpg->link->rect.left = 0;
    sfSprite_setTextureRect(rpg->link->sprite, rpg->link->rect);
    sfClock_restart(rpg->link->clock);
    }
    sfRenderWindow_drawSprite(rpg->window, rpg->link->sprite, NULL);
}

void link_walk_right(rpg_t *rpg)
{
    sfSprite_move(rpg->game->smap, (sfVector2f){-(3 + actual_lvl()), 0});
    sfSprite_move(rpg->game->soverlay, (sfVector2f){-(3 + actual_lvl()), 0});
    rpg->link->rect.top = 38;
    if (rpg->link->seconds > 0.04) {
        rpg->link->rect.left += 24;
    if (rpg->link->rect.left >= 288)
        rpg->link->rect.left = 0;
    sfSprite_setTextureRect(rpg->link->sprite, rpg->link->rect);
    sfClock_restart(rpg->link->clock);
    }
    sfRenderWindow_drawSprite(rpg->window, rpg->link->sprite, NULL);
}

void link_walk_down(rpg_t *rpg)
{
    sfSprite_move(rpg->game->smap, (sfVector2f){0, -(3 + actual_lvl())});
    sfSprite_move(rpg->game->soverlay, (sfVector2f){0, -(3 + actual_lvl())});
    rpg->link->rect.top = 70;
    if (rpg->link->seconds > 0.04) {
        rpg->link->rect.left += 24;
    if (rpg->link->rect.left >= 288)
        rpg->link->rect.left = 0;
    sfSprite_setTextureRect(rpg->link->sprite, rpg->link->rect);
    sfClock_restart(rpg->link->clock);
    }
    sfRenderWindow_drawSprite(rpg->window, rpg->link->sprite, NULL);
}