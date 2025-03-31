/*
** EPITECH PROJECT, 2021
** B-MUL-200-MPL-2-1-myrpg-mickael.grezes
** File description:
** second_init
*/

#include "my.h"

void init_effect(rpg_t *rpg)
{
    sfTexture *tlifebar = sfTexture_createFromFile("assets/lifebar.png", NULL);

    rpg->effect->sprite = sfSprite_create();
    rpg->fights->lifebar = sfSprite_create();
    rpg->effect->clock = sfClock_create();
    rpg->effect->texture = sfTexture_createFromFile("assets/rain.png", NULL);
    rpg->effect->rect = (sfIntRect){0, 0, 1360, 720};
    rpg->fights->rlifebar = (sfIntRect){0, 0, 293, 37};
    sfSprite_setTexture(rpg->fights->lifebar, tlifebar, sfTrue);
    sfSprite_setTexture(rpg->effect->sprite, rpg->effect->texture, sfTrue);
    sfSprite_setScale(rpg->effect->sprite, (sfVector2f){3, 3});
    sfSprite_setPosition(rpg->effect->sprite, (sfVector2f){0, -220});
    sfSprite_setPosition(rpg->fights->lifebar, (sfVector2f){25, 25});
}

void init_fight2(rpg_t *rpg)
{
    sfText_setCharacterSize(rpg->fights->atk, 59);
    sfText_setCharacterSize(rpg->fights->magic, 59);
    sfText_setCharacterSize(rpg->fights->heal, 59);
    sfText_setCharacterSize(rpg->fights->escape, 59);
    sfText_setPosition(rpg->fights->atk, (sfVector2f){593, 942});
    sfText_setPosition(rpg->fights->magic, (sfVector2f){809, 942});
    sfText_setPosition(rpg->fights->heal, (sfVector2f){1020, 942});
    sfText_setPosition(rpg->fights->escape, (sfVector2f){1202, 942});
}

void init_fight(rpg_t *rpg)
{
    sfFont *font = sfFont_createFromFile("assets/font.ttf");

    rpg->fights->atk = sfText_create();
    rpg->fights->magic = sfText_create();
    rpg->fights->heal = sfText_create();
    rpg->fights->escape = sfText_create();
    sfText_setString(rpg->fights->atk, "ATTACK");
    sfText_setString(rpg->fights->magic, "MAGIC");
    sfText_setString(rpg->fights->heal, "HEAL");
    sfText_setString(rpg->fights->escape, "ESCAPE");
    sfText_setFont(rpg->fights->atk, font);
    sfText_setFont(rpg->fights->magic, font);
    sfText_setFont(rpg->fights->heal, font);
    sfText_setFont(rpg->fights->escape, font);
    init_fight2(rpg);
}

void init_quest(rpg_t *rpg)
{
    sfTexture *twhite = sfTexture_createFromFile("assets/white.png", NULL);

    rpg->quest->white = sfSprite_create();
    rpg->quest->dialog = sfClock_create();
    rpg->quest->house = sfClock_create();
    rpg->quest->tfinn = sfText_create();
    rpg->quest->rect = (sfIntRect){0, 0, 250, 50};
    sfText_setFont(rpg->quest->tfinn, sfFont_createFromFile("assets/font.ttf"));
    sfSprite_setTexture(rpg->quest->white, twhite, sfTrue);
    sfSprite_setTextureRect(rpg->quest->white, rpg->quest->rect);
}

void rain(rpg_t *rpg)
{
    if (rpg->effect->seconds > 0.04) {
        rpg->effect->rect.left += 1360;
        if (rpg->effect->rect.left >= 10880)
            rpg->effect->rect.left = 0;
        sfSprite_setTextureRect(rpg->effect->sprite, rpg->effect->rect);
        sfClock_restart(rpg->effect->clock);
    }
    sfRenderWindow_drawSprite(rpg->window, rpg->effect->sprite, NULL);
}