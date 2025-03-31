/*
** EPITECH PROJECT, 2021
** B-MUL-200-MPL-2-1-myrpg-mickael.grezes
** File description:
** init_enemies
*/

#include "my.h"

void init_enemy1(enemy_s *enemy1)
{
    if (enemy1 == NULL)
        enemy1 = malloc(sizeof(*enemy1));
    sfTexture *texture = sfTexture_createFromFile("assets/enemy1.png", NULL);

    enemy1->sprite = sfSprite_create();
    sfSprite_setTexture(enemy1->sprite, texture, sfTrue);
    sfSprite_setPosition(enemy1->sprite, (sfVector2f){1600, 740});
    enemy1->pv = 200;
    enemy1->damages = 5;
    enemy1->rect = (sfIntRect){0, 0, 148, 192};
    enemy1->tile_nb = 4;
}

void init_boss(enemy_s *boss)
{
    sfTexture *texture = sfTexture_createFromFile("assets/boss.png", NULL);

    boss->sprite = sfSprite_create();
    sfSprite_setTexture(boss->sprite, texture, sfTrue);
    sfSprite_setScale(boss->sprite, (sfVector2f){3, 3});
    sfSprite_setPosition(boss->sprite, (sfVector2f){1400, 570});
    boss->pv = 450;
    boss->damages = 20;
    boss->rect = (sfIntRect){0, 0, 148, 140};
    boss->tile_nb = 25;
}