/*
** EPITECH PROJECT, 2021
** B-MUL-200-MPL-2-1-myrpg-mickael.grezes
** File description:
** fight_rand
*/

#include "my.h"

void fight_rand(rpg_t *rpg)
{
    if (rand() % 10 <= 5)
        rpg->fight = 1;
    return;
}