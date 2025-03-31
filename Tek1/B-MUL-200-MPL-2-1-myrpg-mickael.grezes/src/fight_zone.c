/*
** EPITECH PROJECT, 2021
** B-MUL-200-MPL-2-1-myrpg-mickael.grezes
** File description:
** fight_zone
*/

#include "my.h"

int check_top2(rpg_t *rpg)
{
    sfVector2f pos = sfSprite_getPosition(rpg->game->smap);
    int x = pos.x - 900;
    int y = pos.y - 500;

    if (-y/48 <= 1)
        return (0);
    if (rpg->map[-y/48 - 1][-x/48] == '.')
        return (0);
    return (1);
}

int check_left2(rpg_t *rpg)
{
    sfVector2f pos = sfSprite_getPosition(rpg->game->smap);
    int x = pos.x - 900;
    int y = pos.y - 500;

    if (-x/48 <= 1)
        return (0);
    if (rpg->map[-y/48][-x/48 - 1] == '.')
        return (0);
    return (1);
}

int check_down2(rpg_t *rpg)
{
    sfVector2f pos = sfSprite_getPosition(rpg->game->smap);
    int x = pos.x - 900;
    int y = pos.y - 500;

    if (-y/48 >= 99)
        return (0);
    if (rpg->map[-y/48 + 1][-x/48] == '.')
        return (0);
    return (1);
}

int check_right2(rpg_t *rpg)
{
    sfVector2f pos = sfSprite_getPosition(rpg->game->smap);
    int x = pos.x - 900;
    int y = pos.y - 500;

    if (-x/48 >= 99)
        return (0);
    if (rpg->map[-y/48][-x/48 + 1] == '.')
        return (0);
    return (1);
}

void fight_zone(rpg_t *rpg)
{
    if (rpg->fights->seconds > 5.0) {
        if (check_top2(rpg) == 0)
            fight_rand(rpg);
        if (check_down2(rpg) == 0)
            fight_rand(rpg);
        if (check_left2(rpg) == 0)
            fight_rand(rpg);
        if (check_right2(rpg) == 0)
            fight_rand(rpg);
    }
}