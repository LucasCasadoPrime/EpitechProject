/*
** EPITECH PROJECT, 2020
** my_rpg
** File description:
** main for our rpg game
*/

#include "my.h"

void event(rpg_t *rpg)
{
    for (; sfRenderWindow_pollEvent(rpg->window, &rpg->event);) {
        if (rpg->scene == 1 || rpg->scene == 3)
            menu_event(rpg);
        if (rpg->scene == 2)
            menu2_event(rpg);
        if (rpg->scene == 4)
            game_event(rpg);
    }
}

void free_game(rpg_t *rpg)
{
    free(rpg->link);
    free(rpg->game->save);
    free(rpg->game);
    free(rpg->music);
    free(rpg->menu);
    free(rpg->effect);
    free(rpg->fights);
    free(rpg->enemy1);
    free(rpg->boss);
    free(rpg->inventory);
    free(rpg);
}

void set_seconds(rpg_t *rpg)
{
    sfTime time = sfClock_getElapsedTime(rpg->quest->house);
    sfTime time2 = sfClock_getElapsedTime(rpg->fights->clock);

    sfRenderWindow_clear(rpg->window, sfBlack);
    rpg->link->time = sfClock_getElapsedTime(rpg->link->clock);
    rpg->link->seconds = rpg->link->time.microseconds / 1000000.0;
    rpg->effect->time = sfClock_getElapsedTime(rpg->effect->clock);
    rpg->effect->seconds = rpg->effect->time.microseconds / 1000000.0;
    rpg->quest->time = sfClock_getElapsedTime(rpg->quest->dialog);
    rpg->quest->seconds = rpg->quest->time.microseconds / 1000000.0;
    rpg->quest->seconds2 = time.microseconds / 1000000.0;
    rpg->fights->seconds = time2.microseconds / 1000000.0;
}

void start_game(rpg_t *rpg)
{
    while (sfRenderWindow_isOpen(rpg->window)) {
        event(rpg);
        set_seconds(rpg);
            if (rpg->scene == 1 || rpg->scene == 3)
                game_menu(rpg);
            if (rpg->scene == 2)
                game_menu2(rpg);
            if (rpg->scene == 4 || rpg->scene == 5)
                game_display(rpg);
            if (rpg->scene == 0)
                return;
        sfRenderWindow_display(rpg->window);
    }
    return;
}

int main(void)
{
    rpg_t *rpg = malloc(sizeof(*rpg));

    malloc_structs(rpg);
    init(rpg);
    start_game(rpg);
    auto_save(rpg);
    destroy_menu(rpg);
    destroy_game(rpg);
    destroy_entity(rpg);
    free_game(rpg);
    return (0);
}