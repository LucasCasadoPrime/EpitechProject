/*
** EPITECH PROJECT, 2020
** B-MUL-100-MPL-1-1-myhunter-lucas.casado
** File description:
** my_game
*/

#include "my_hunter.h"

struct game_s menu_display(struct game_s obj)
{
    sfTime time;
    float seconds;
    time = sfClock_getElapsedTime(obj.bmclock);
    seconds = time.microseconds / 1000000.0;
    if (seconds > 0.5) {
        obj.rect.left += 1280;
        if (obj.rect.left == 2560)
            obj.rect.left = 0;
        sfSprite_setTextureRect(obj.bmsprite, obj.rect);
        sfClock_restart(obj.bmclock);
    }
    sfRenderWindow_drawSprite(obj.window, obj.bmsprite, NULL);
    sfRenderWindow_drawSprite(obj.window, obj.snew_game, NULL);
    return (obj);
}

void destroy(struct game_s obj)
{
    sfSprite_destroy(obj.bmsprite);
    sfTexture_destroy(obj.bmtexture);
    sfClock_destroy(obj.bmclock);
}