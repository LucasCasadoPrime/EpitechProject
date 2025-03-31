/*
** EPITECH PROJECT, 2020
** B-MUL-100-MPL-1-1-myhunter-lucas.casado
** File description:
** main
*/

#include "my_hunter.h"

struct game_s manage(struct game_s obj, sfEvent event)
{
    if (sfKeyboard_isKeyPressed(sfKeyEnter))
        obj.swap = 1;
    if (event.mouseButton.button == sfMouseLeft && \
    event.mouseButton.x < sfSprite_getPosition \
    (obj.snew_game).x + 300 && event.mouseButton.y \
    < sfSprite_getPosition(obj.snew_game).y + 300)
        obj.swap = 1;
    return (obj);
}

struct game_s manage_event(struct game_s obj, \
struct bird_s status, sfEvent event)
{
    while (sfRenderWindow_pollEvent(obj.window, &event)) {
        obj = manage(obj, event);
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(obj.window);
        if (event.type == sfEvtKeyPressed && event.key.code == sfKeyEscape)
        sfRenderWindow_close(obj.window);
        if (event.mouseButton.button == sfMouseLeft && \
            event.mouseButton.x < sfSprite_getPosition \
            (status.sprite).x + 110 && event.mouseButton.y \
            < sfSprite_getPosition (status.sprite).y + 110) {
            sfSprite_setPosition(status.sprite, \
            (sfVector2f){-110, rand() %300});
        }
    }
    return (obj);
}

void launch_game(struct game_s obj, struct bird_s status, \
struct cursor_s curs)
{
    sfEvent event;

    while (sfRenderWindow_isOpen(obj.window)) {
        obj = manage_event(obj, status, event);
        curs = cursor(curs, obj);
        if (obj.swap == 1) {
            obj = background_game_display(obj);
            status = birds_anim(status, obj);
        } else
            obj = menu_display(obj);
        display_cursor(curs, obj);
        sfRenderWindow_display(obj.window);
    }
    sfRenderWindow_destroy(obj.window);
    sfMusic_destroy(obj.bmmusic);
}

void destroy_all(struct cursor_s curs, struct bird_s status, struct game_s obj)
{
    destroy_cursor(curs);
    destroy_bird(status);
    bgdestroy(obj);
    destroy(obj);
}