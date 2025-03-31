/*
** EPITECH PROJECT, 2020
** B-MUL-100-MPL-1-1-myhunter-lucas.casado
** File description:
** cursor
*/

#include "my_hunter.h"

struct cursor_s cursor(struct cursor_s curs, struct game_s obj)
{
    curs.pos.x = sfMouse_getPositionRenderWindow(obj.window).x - 20;
    curs.pos.y = sfMouse_getPositionRenderWindow(obj.window).y - 20;
    sfSprite_setPosition(curs.sprite, curs.pos);
    return (curs);
}

void display_cursor(struct cursor_s curs, struct game_s obj)
{
    sfRenderWindow_drawSprite(obj.window, curs.sprite, NULL);
}

void destroy_cursor(struct cursor_s curs)
{
    sfSprite_destroy(curs.sprite);
    sfTexture_destroy(curs.texture);
}