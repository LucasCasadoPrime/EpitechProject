/*
** EPITECH PROJECT, 2021
** B-MUL-200-MPL-2-1-myrpg-mickael.grezes
** File description:
** fight
*/

#include "my.h"

int turn(int id)
{
    static int turn = 1;

    if (id == 1 || id == 2)
        turn = id;
    return (turn);
}

void link_anim(rpg_t *rpg)
{
    sfTime time = sfClock_getElapsedTime(rpg->link->c_fight);
    float seconds = time.microseconds / 1000000.0;

    if (seconds > 0.1) {
        rpg->link->r_fight.left += 288;
        if (rpg->link->r_fight.left >= 5184)
            rpg->link->r_fight.left = 0;
        sfSprite_setTextureRect(rpg->link->s_fight, rpg->link->r_fight);
        sfClock_restart(rpg->link->c_fight);
    }
    sfRenderWindow_drawSprite(rpg->window, rpg->link->s_fight, NULL);
    return;
}

void draw_enemy(rpg_t *rpg, enemy_s *enemy)
{
    sfTime time = sfClock_getElapsedTime(rpg->link->c_fight);
    float seconds = time.microseconds / 1000000.0;
    int width = enemy->rect.width;
    int max_width = enemy->rect.width * enemy->tile_nb;

    if (seconds > 0.1) {
        enemy->rect.left += width;
        if (enemy->rect.left >= max_width)
            enemy->rect.left = 0;
        sfSprite_setTextureRect(enemy->sprite, enemy->rect);
    }
    sfRenderWindow_drawSprite(rpg->window, enemy->sprite, NULL);
}

void print_boss_hp(rpg_t *rpg, enemy_s *enemy)
{
    sfTexture *lb = sfTexture_createFromFile("assets/lifebar.png", NULL);
    sfSprite *ls = sfSprite_create();

    if (enemy == NULL)
        return;
    sfSprite_setTexture(ls, lb, sfTrue);
    sfSprite_setTextureRect(ls, (sfIntRect){0, 0, 293, 37});
    sfSprite_setOrigin(ls, (sfVector2f){293, 0});
    sfSprite_setPosition(ls, (sfVector2f){1895, 25});
    sfSprite_setScale(ls, (sfVector2f){enemy->pv / 100.0, 1});
    sfRenderWindow_drawSprite(rpg->window, ls, NULL);
    sfSprite_destroy(ls);
    sfTexture_destroy(lb);
    fight_potion(rpg);
}

void fight(rpg_t *rpg, enemy_s *enemy)
{
    if (enemy == NULL)
        return;
    print_ui(rpg);
    print_life(rpg);
    print_boss_hp(rpg, enemy);
    if (enemy->pv > 0)
        draw_enemy(rpg, enemy);
    if (rpg->link->pv <= 0)
        fight_lose(rpg);
    if (enemy->pv <= 0) {
        fight_win(rpg);
        return;
    }
    if (turn(0) == 2) {
        rpg->link->pv -= enemy->damages;
        turn(1);
    }
    link_anim(rpg);
    return;
}