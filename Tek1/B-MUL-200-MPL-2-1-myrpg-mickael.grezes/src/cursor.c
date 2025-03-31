/*
** EPITECH PROJECT, 2021
** B-MUL-200-MPL-2-1-myrpg-mickael.grezes
** File description:
** cursor
*/

#include "my.h"

void cursor(rpg_t *rpg)
{
    if (rpg->game->inv == 1 || rpg->fight == 1 || rpg->fight == 2)
        sfRenderWindow_setMouseCursorVisible(rpg->window, sfTrue);
    else
        sfRenderWindow_setMouseCursorVisible(rpg->window, sfFalse);
}