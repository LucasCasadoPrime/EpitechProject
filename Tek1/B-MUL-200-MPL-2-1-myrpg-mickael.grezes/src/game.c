/*
** EPITECH PROJECT, 2021
** B-MUL-200-MPL-2-1-myrpg-mickael.grezes
** File description:
** game
*/

#include "my.h"

void destroy_game(rpg_t *rpg)
{
    sfMusic_destroy(rpg->music->menu);
    sfMusic_destroy(rpg->music->game);
    sfTexture_destroy(rpg->link->texture);
    sfSprite_destroy(rpg->link->sprite);
    sfClock_destroy(rpg->link->clock);
    sfTexture_destroy(rpg->game->tmap);
    sfSprite_destroy(rpg->game->smap);
    sfTexture_destroy(rpg->game->toverlay);
    sfSprite_destroy(rpg->game->soverlay);
    sfTexture_destroy(rpg->game->tinv);
    sfSprite_destroy(rpg->game->sinv);
    sfTexture_destroy(rpg->game->tinter);
    sfSprite_destroy(rpg->game->sinter);
}

int check_inter(rpg_t *rpg)
{
    sfVector2f pos = sfSprite_getPosition(rpg->game->smap);
    int x = pos.x - 900;
    int y = pos.y - 500;

    if (-y/48 == 57 && -x/48 == 39)
        return (1);
    if (-y/48 == 75 && -x/48 == 59)
        return (2);
    if (-y/48 == 26 && -x/48 == 24 && actual_lvl() >= 5)
        return (3);
    return (0);
}

void link_walk(rpg_t *rpg)
{
    if (rpg->game->inv == 0 && rpg->fight == 0) {
        if (sfKeyboard_isKeyPressed(sfKeyZ) == sfTrue && check_top(rpg) == 1)
            link_walk_top(rpg);
        if (sfKeyboard_isKeyPressed(sfKeyQ) == sfTrue && check_left(rpg) == 1)
            link_walk_left(rpg);
        if (sfKeyboard_isKeyPressed(sfKeyS) == sfTrue && check_down(rpg) == 1)
            link_walk_down(rpg);
        if (sfKeyboard_isKeyPressed(sfKeyD) == sfTrue && check_right(rpg) == 1)
            link_walk_right(rpg);
    }
}

void render_map(rpg_t *rpg)
{
    sfRenderWindow_clear(rpg->window, sfBlack);
    sfRenderWindow_drawSprite(rpg->window, rpg->game->smap, NULL);
    sfRenderWindow_drawSprite(rpg->window, rpg->link->sprite, NULL);
    sfRenderWindow_drawSprite(rpg->window, rpg->game->soverlay, NULL);
}

void game_display(rpg_t *rpg)
{
    update_music(rpg);
    render_map(rpg);
    cursor(rpg);
    rain(rpg);
    if (rpg->link->interact != 0)
        sfRenderWindow_drawSprite(rpg->window, rpg->game->sinter, NULL);
    if (rpg->game->inv == 1)
        display_inventory(rpg);
    if (rpg->enemy1 == NULL)
        init_enemy1(rpg->enemy1);
    if (rpg->fight == 1)
        fight(rpg, rpg->enemy1);
    if (rpg->fight == 2)
        fight(rpg, rpg->boss);
    init_inventory(rpg);
    save(rpg);
    text(rpg);
    text_house(rpg);
}