/*
** EPITECH PROJECT, 2020
** B-MUL-100-MPL-1-1-myhunter-lucas.casado
** File description:
** bird_anim
*/

#include "my_hunter.h"

struct bird_s game_over_display(struct game_s obj, struct bird_s status)
{
    sfTime time;
    float seconds;
    time = sfClock_getElapsedTime(status.gclock);
    seconds = time.microseconds / 1000000.0;
    if (seconds > 0.5) {
        status.grect.left += 1280;
        if (status.grect.left == 2560)
            status.grect.left = 0;
        sfSprite_setTextureRect(status.gsprite, status.grect);
        sfClock_restart(status.gclock);
    }
    sfRenderWindow_drawSprite(obj.window, status.gsprite, NULL);
    return (status);
}

void game_status_destroy(struct bird_s status)
{
    sfSprite_destroy(status.gsprite);
    sfMusic_destroy(status.gmusic);
}

struct bird_s birds_anim(struct bird_s status, struct game_s obj)
{
    sfTime time;
    float seconds;
    time = sfClock_getElapsedTime(status.clock);
    seconds = time.microseconds / 1000000.0;
    if (seconds > 0.07) {
        status.rect.left += 110;
        if (status.rect.left == 330)
            status.rect.left = 0;
        sfSprite_setTextureRect(status.sprite, status.rect);
        sfSprite_move(status.sprite, (sfVector2f){20, 0});
        sfClock_restart(status.clock);
    }
    if (sfSprite_getPosition(status.sprite).x > 1480) {
        status = game_over_display(obj, status);
    }
    sfRenderWindow_drawSprite(obj.window, status.sprite, NULL);
    return (status);
}

void destroy_bird(struct bird_s status)
{
    sfSprite_destroy(status.sprite);
    sfTexture_destroy(status.texture);
    sfClock_destroy(status.clock);
}