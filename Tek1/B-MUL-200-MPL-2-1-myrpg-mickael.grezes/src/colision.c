/*
** EPITECH PROJECT, 2021
** colision
** File description:
** check if colision or nah
*/

#include "my.h"

int check_top(rpg_t *rpg)
{
    sfVector2f pos = sfSprite_getPosition(rpg->game->smap);
    int x = pos.x - 900;
    int y = pos.y - 500;

    if (-y/48 <= 1)
        return (0);
    if (rpg->map[-y/48 - 1][-x/48] == '0')
        return (0);
    return (1);
}

int check_left(rpg_t *rpg)
{
    sfVector2f pos = sfSprite_getPosition(rpg->game->smap);
    int x = pos.x - 900;
    int y = pos.y - 500;

    if (-x/48 <= 1)
        return (0);
    if (rpg->map[-y/48][-x/48 - 1] == '0')
        return (0);
    return (1);
}

int check_down(rpg_t *rpg)
{
    sfVector2f pos = sfSprite_getPosition(rpg->game->smap);
    int x = pos.x - 900;
    int y = pos.y - 500;

    if (-y/48 >= 99)
        return (0);
    if (rpg->map[-y/48 + 1][-x/48] == '0')
        return (0);
    return (1);
}

int check_right(rpg_t *rpg)
{
    sfVector2f pos = sfSprite_getPosition(rpg->game->smap);
    int x = pos.x - 900;
    int y = pos.y - 500;

    if (-x/48 >= 99)
        return (0);
    if (rpg->map[-y/48][-x/48 + 1] == '0')
        return (0);
    return (1);
}