/*
** EPITECH PROJECT, 2021
** B-MUL-200-MPL-2-1-myrpg-mickael.grezes
** File description:
** malloc_structs
*/

#include "my.h"

void malloc_structs(rpg_t *rpg)
{
    rpg->menu = malloc(sizeof(*rpg->menu));
    rpg->music = malloc(sizeof(*rpg->music));
    rpg->game = malloc(sizeof(*rpg->game));
    rpg->link = malloc(sizeof(*rpg->link));
    rpg->effect = malloc(sizeof(*rpg->effect));
    rpg->fights = malloc(sizeof(*rpg->fights));
    rpg->enemy1 = malloc(sizeof(*rpg->enemy1));
    rpg->boss = malloc(sizeof(*rpg->boss));
    rpg->inventory = malloc(sizeof(*rpg->inventory));
    rpg->quest = malloc(sizeof(*rpg->quest));
    rpg->head = NULL;
}