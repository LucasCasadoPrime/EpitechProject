/*
** EPITECH PROJECT, 2021
** B-MUL-200-MPL-2-1-myrpg-mickael.grezes
** File description:
** event
*/

#include "my.h"

void menu_event(rpg_t *rpg)
{
    if (&rpg->event == sfEvtClosed)
        rpg->scene = 0;
    if (sfKeyboard_isKeyPressed(sfKeyEscape))
        rpg->scene = 0;
    if (sfKeyboard_isKeyPressed(sfKeySpace))
        rpg->scene = 2;
}

void menu2_event2(rpg_t *rpg)
{
    sfFloatRect bound_s = sfSprite_getGlobalBounds(rpg->menu->s_settings);
    sfFloatRect bound_e = sfSprite_getGlobalBounds(rpg->menu->s_exit);

    if (sfFloatRect_contains(&bound_s, rpg->event.mouseButton.x, \
        rpg->event.mouseButton.y))
            rpg->scene = 3;
    if (sfFloatRect_contains(&bound_e, rpg->event.mouseButton.x, \
        rpg->event.mouseButton.y) && rpg->scene == 2)
            rpg->scene = 0;
    if (rpg->scene == 2)
        sfRenderWindow_setMouseCursorVisible(rpg->window, sfTrue);
    return;
}

void menu2_event(rpg_t *rpg)
{
    sfFloatRect bound_p = sfSprite_getGlobalBounds(rpg->menu->s_play);
    sfFloatRect bound_c = sfSprite_getGlobalBounds(rpg->menu->s_continue);

    menu2_event2(rpg);
    if (&rpg->event == sfEvtClosed)
        rpg->scene = 0;
    if (sfFloatRect_contains(&bound_p, rpg->event.mouseButton.x, \
    rpg->event.mouseButton.y)) {
        new_save();
        load_save(rpg);
        add_xp(-1);
        rpg->scene = 4;
    }
    if (sfFloatRect_contains(&bound_c, rpg->event.mouseButton.x, \
    rpg->event.mouseButton.y)) {
        load_save(rpg);
        rpg->scene = 4;
    }
    return;
}

void check_interactions(rpg_t *rpg)
{
    if (check_inter(rpg) == 2 && sfKeyboard_isKeyPressed(sfKeyE))
        rpg->quest->scene = 1;
    if (check_inter(rpg) == 1 && sfKeyboard_isKeyPressed(sfKeyE))
        rpg->quest->scene = 2;
    if (sfKeyboard_isKeyPressed(sfKeyE) == sfTrue && check_inter(rpg) == 3)
        rpg->fight = 2;
}

void game_event(rpg_t *rpg)
{
    sfFloatRect close = (sfFloatRect){1830, 18, 64, 64};

    if (sfKeyboard_isKeyPressed(sfKeyEscape) && rpg->scene == 4) {
        auto_save(rpg);
        rpg->scene = 2;
    }
    link_walk(rpg);
    fight_zone(rpg);
    rpg->link->interact = check_inter(rpg);
    if (sfKeyboard_isKeyPressed(sfKeyI) == sfTrue && rpg->game->inv == 0)
        rpg->game->inv = 1;
    if (sfFloatRect_contains(&close, rpg->event.mouseButton.x, \
    rpg->event.mouseButton.y))
        rpg->game->inv = 0;
    check_interactions(rpg);
    if (rpg->fight == 1)
        fight_events(rpg, rpg->enemy1);
    if (rpg->fight == 2)
        fight_events(rpg, rpg->boss);
}