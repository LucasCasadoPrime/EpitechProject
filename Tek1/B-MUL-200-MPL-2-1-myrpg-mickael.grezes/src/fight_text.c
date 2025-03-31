/*
** EPITECH PROJECT, 2021
** B-MUL-200-MPL-2-1-myrpg-mickael.grezes
** File description:
** fight_text
*/

#include "my.h"

void fight_potion(rpg_t *rpg)
{
    sfText *txt = sfText_create();
    sfFont *font = sfFont_createFromFile("./assets/font.ttf");
    char *ptr = my_itoa(rpg->link->nb_potions);

    sfText_setFont(txt, font);
    sfText_setPosition(txt, (sfVector2f){85, 1015});
    sfText_setCharacterSize(txt, 50);
    sfText_setString(txt, ptr);
    sfRenderWindow_drawText(rpg->window, txt, NULL);
    sfText_destroy(txt);
    sfFont_destroy(font);
    free(ptr);
}