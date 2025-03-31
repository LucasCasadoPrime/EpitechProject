/*
** EPITECH PROJECT, 2021
** B-MUL-200-MPL-2-1-myrpg-mickael.grezes
** File description:
** inventory_texts
*/

#include "my.h"

void display_potions(rpg_t *rpg)
{
    sfText *txt = sfText_create();
    sfFont *font = sfFont_createFromFile("./assets/font.ttf");
    char tmp[12];
    char *ptr = my_itoa(rpg->link->nb_potions);

    sfText_setFont(txt, font);
    sfText_setPosition(txt, (sfVector2f){88, 1005});
    my_strcpy(tmp, "Potions : ");
    my_strcat(tmp, ptr);
    sfText_setString(txt, tmp);
    sfRenderWindow_drawText(rpg->window, txt, NULL);
    sfText_destroy(txt);
    sfFont_destroy(font);
    free(ptr);
}

void display_stats(sfText *strength, sfText *speed, sfFont *font, rpg_t *rpg)
{
    char *ptr;
    char tmp[100];

    sfText_setFont(strength, font);
    sfText_setFont(speed, font);
    sfText_setPosition(strength, (sfVector2f){88, 175});
    sfText_setPosition(speed, (sfVector2f){88, 175 + 29});
    ptr = my_itoa(22 + actual_lvl() * 3);
    my_strcat(my_strcpy(tmp, "Damages : "), ptr);
    free(ptr);
    sfText_setString(strength, tmp);
    sfRenderWindow_drawText(rpg->window, strength, NULL);
    ptr = my_itoa(3 + actual_lvl());
    my_strcat(my_strcpy(tmp, "Speed : "), ptr);
    free(ptr);
    sfText_setString(speed, tmp);
    sfRenderWindow_drawText(rpg->window, speed, NULL);
    display_potions(rpg);
}

void display_remaining_exp(sfText *xp_txt, rpg_t *rpg)
{
    char *ptr;
    char tmp[128];
    sfText *txt_strength = sfText_create();
    sfText *txt_speed = sfText_create();
    sfFont *font = sfFont_createFromFile("./assets/font.ttf");

    my_strcpy(tmp, "Needed XP for next level : ");
    ptr = my_itoa(remain_xp());
    my_strcat(tmp, ptr);
    free(ptr);
    my_strcat(tmp, "/");
    ptr = my_itoa(needed_xp());
    my_strcat(tmp, ptr);
    free(ptr);
    sfText_setString(xp_txt, tmp);
    display_stats(txt_strength, txt_speed, font, rpg);
    sfText_destroy(txt_strength);
    sfText_destroy(txt_speed);
    sfFont_destroy(font);
}

void display_experience(rpg_t *rpg)
{
    sfText *level_txt = sfText_create();
    sfText *xp_txt = sfText_create();
    sfFont *font = sfFont_createFromFile("./assets/font.ttf");
    char *tmp_ptr = my_itoa(actual_lvl());
    char tmp[128];

    sfText_setFont(level_txt, font);
    sfText_setFont(xp_txt, font);
    sfText_setPosition(level_txt, (sfVector2f){88, 96});
    sfText_setPosition(xp_txt, (sfVector2f){88, 96 + 29});
    my_strcat(my_strcpy(tmp, "Level : "), tmp_ptr);
    sfText_setString(level_txt, tmp);
    free(tmp_ptr);
    display_remaining_exp(xp_txt, rpg);
    sfRenderWindow_drawText(rpg->window, level_txt, NULL);
    sfRenderWindow_drawText(rpg->window, xp_txt, NULL);
    sfText_destroy(level_txt);
    sfText_destroy(xp_txt);
    sfFont_destroy(font);
}

void display_inventory(rpg_t *rpg)
{
    sfTexture *lb = sfTexture_createFromFile("assets/lifebar.png", NULL);
    sfSprite *ls = sfSprite_create();

    sfRenderWindow_drawSprite(rpg->window, rpg->game->sinv, NULL);
    sfSprite_setTexture(ls, lb, sfTrue);
    sfSprite_setTextureRect(ls, (sfIntRect){0, 0, 293, 37});
    sfSprite_setPosition(ls, (sfVector2f){89, 35});
    sfSprite_setScale(ls, (sfVector2f){rpg->link->pv / 100.0, 1});
    sfRenderWindow_drawSprite(rpg->window, ls, NULL);
    sfSprite_destroy(ls);
    sfTexture_destroy(lb);
    display_experience(rpg);
}