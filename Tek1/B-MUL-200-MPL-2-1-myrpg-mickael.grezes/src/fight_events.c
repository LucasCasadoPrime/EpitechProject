/*
** EPITECH PROJECT, 2021
** B-MUL-200-MPL-2-1-myrpg-mickael.grezes
** File description:
** fight_events
*/

#include "my.h"

void text_hover2(rpg_t *rpg)
{
    sfFloatRect r_magic = sfText_getGlobalBounds(rpg->fights->magic);
    sfFloatRect r_escape = sfText_getGlobalBounds(rpg->fights->escape);
    sfVector2i pos = sfMouse_getPositionRenderWindow(rpg->window);

    if (sfFloatRect_contains(&r_magic, pos.x, pos.y))
        sfText_setColor(rpg->fights->magic, (sfColor){200, 200, 200, 255});
    else
        sfText_setColor(rpg->fights->magic, sfWhite);
    if (sfFloatRect_contains(&r_escape, pos.x, pos.y))
        sfText_setColor(rpg->fights->escape, (sfColor){200, 200, 200, 255});
    else
        sfText_setColor(rpg->fights->escape, sfWhite);
}

void text_hover(rpg_t *rpg)
{
    sfFloatRect r_attack = sfText_getGlobalBounds(rpg->fights->atk);
    sfFloatRect r_heal = sfText_getGlobalBounds(rpg->fights->heal);
    sfVector2i pos = sfMouse_getPositionRenderWindow(rpg->window);

    if (sfFloatRect_contains(&r_attack, pos.x, pos.y))
        sfText_setColor(rpg->fights->atk, (sfColor){200, 200, 200, 255});
    else
        sfText_setColor(rpg->fights->atk, sfWhite);
    if (sfFloatRect_contains(&r_heal, pos.x, pos.y))
        sfText_setColor(rpg->fights->heal, (sfColor){200, 200, 200, 255});
    else
        sfText_setColor(rpg->fights->heal, sfWhite);
    text_hover2(rpg);
}

void print_life(rpg_t *rpg)
{
    float scale = 0;

    scale = rpg->link->pv / 100.0;
    sfSprite_setScale(rpg->fights->lifebar, (sfVector2f){scale, 1});
    sfRenderWindow_drawSprite(rpg->window, rpg->fights->lifebar, NULL);
}

void fight_events2(rpg_t *rpg, enemy_s *enemy)
{
    sfFloatRect bound_a = sfText_getGlobalBounds(rpg->fights->atk);
    sfFloatRect bound_m = sfText_getGlobalBounds(rpg->fights->magic);
    int damage = 15 + actual_lvl() * 10;
    int m_damage = rpg->link->m_damages;

    if (sfFloatRect_contains(&bound_a, rpg->event.mouseButton.x, \
    rpg->event.mouseButton.y) && sfMouse_isButtonPressed(sfMouseLeft)\
    && turn(0) == 1) {
        enemy->pv -= damage;
        turn(2);
    }
    if (sfFloatRect_contains(&bound_m, rpg->event.mouseButton.x, \
    rpg->event.mouseButton.y) && sfMouse_isButtonPressed(sfMouseLeft)\
    && turn(0) == 1) {
        enemy->pv -= m_damage;
        turn(2);
    }
}

void fight_events(rpg_t *rpg, enemy_s *enemy)
{
    sfFloatRect bound_h = sfText_getGlobalBounds(rpg->fights->heal);
    sfFloatRect bound_e = sfText_getGlobalBounds(rpg->fights->escape);

    text_hover(rpg);
    fight_events2(rpg, enemy);
    if (sfFloatRect_contains(&bound_h, rpg->event.mouseButton.x, \
    rpg->event.mouseButton.y) && sfMouse_isButtonPressed(sfMouseLeft)\
    && rpg->link->nb_potions >= 1 && turn(0) == 1) {
        rpg->link->pv += 50.0;
        rpg->link->nb_potions -= 1;
        if (rpg->link->pv > 100)
            rpg->link->pv = 100;
        turn(2);
    }
    if (sfFloatRect_contains(&bound_e, rpg->event.mouseButton.x, \
    rpg->event.mouseButton.y) && sfMouse_isButtonPressed(sfMouseLeft)\
    && turn(0) == 1) {
        rpg->fight = 0;
        sfClock_restart(rpg->fights->clock);
        turn(1);
    }
}