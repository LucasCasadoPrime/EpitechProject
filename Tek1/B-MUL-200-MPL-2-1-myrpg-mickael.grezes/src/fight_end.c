/*
** EPITECH PROJECT, 2021
** B-MUL-200-MPL-2-1-myrpg-mickael.grezes
** File description:
** fight_end
*/

#include "my.h"

void fight_win(rpg_t *rpg)
{
    rpg->enemy1 = NULL;
    turn(1);
    sfClock_restart(rpg->fights->clock);
    rpg->fight = 0;
    add_xp(75);
}

void fight_lose(rpg_t *rpg)
{
    rpg->enemy1 = NULL;
    turn(1);
    sfClock_restart(rpg->fights->clock);
    rpg->fight = 0;
    rpg->scene = 2;
    add_xp(-1);
}