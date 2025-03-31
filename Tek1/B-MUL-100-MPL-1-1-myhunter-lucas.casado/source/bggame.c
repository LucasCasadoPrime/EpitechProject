/*
** EPITECH PROJECT, 2020
** B-MUL-100-MPL-1-1-myhunter-lucas.casado
** File description:
** game
*/

#include "my_hunter.h"

struct game_s background_game_display(struct game_s obj)
{
    sfRenderWindow_clear(obj.window, sfBlack);
    sfRenderWindow_setFramerateLimit(obj.window, 30);
    sfSprite_setTextureRect(obj.bgsprite, obj.bgrect);
    sfRenderWindow_drawSprite(obj.window, obj.bgsprite, NULL);
    sfMusic_setLoop(obj.bmmusic, sfFalse);
    sfMusic_setVolume(obj.bmmusic, 1);
    sfMusic_play(obj.bmmusic);
    return (obj);
}

void bgdestroy(struct game_s obj)
{
    sfSprite_destroy(obj.bgsprite);
    sfMusic_destroy(obj.bmmusic);
}