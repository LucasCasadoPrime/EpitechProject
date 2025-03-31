/*
** EPITECH PROJECT, 2021
** B-MUL-100-MPL-1-1-myhunter-lucas.casado
** File description:
** id
*/

#include "my_hunter.h"

struct game_s init(void)
{
    struct game_s obj;

    obj.swap = 0;
    obj.mode = (sfVideoMode){1280, 720, 32};
    obj.window = sfRenderWindow_create(obj.mode, "SFML window", \
    sfResize | sfClose, NULL);
    obj.bmtexture = sfTexture_createFromFile("./asset/ppa.png", NULL);
    obj.bgtexture = sfTexture_createFromFile("./asset/Stage.png", NULL);
    obj.bmsprite = sfSprite_create();
    obj.bgsprite = sfSprite_create();
    obj.bmclock = sfClock_create();
    obj.rect = (sfIntRect){0, 0, 1280, 720};
    obj.bgrect = (sfIntRect){0, 0, 1280, 720};
    obj.bmmusic = sfMusic_createFromFile("./asset/menu.ogg");
    obj.snew_game = sfSprite_create();
    obj.tnew_game = sfTexture_createFromFile("./asset/play.png", NULL);
    set_struct(obj);
    return (obj);
};

void set_struct(struct game_s obj)
{
    sfMusic_setLoop(obj.bmmusic, sfFalse);
    sfMusic_setVolume(obj.bmmusic, 1);
    sfMusic_play(obj.bmmusic);
    sfSprite_setTexture(obj.bmsprite, obj.bmtexture, sfTrue);
    sfSprite_setTexture(obj.bgsprite, obj.bgtexture, sfTrue);
    sfSprite_setTextureRect(obj.bmsprite, obj.rect);
    sfSprite_setTextureRect(obj.bgsprite, obj.bgrect);
    sfRenderWindow_setMouseCursorVisible(obj.window, sfFalse);
    sfSprite_setTexture(obj.snew_game, obj.tnew_game, sfTrue);
    sfSprite_setPosition(obj.snew_game, (sfVector2f){425, 550});
}

struct bird_s form(void)
{
    struct bird_s status;

    status.texture = sfTexture_createFromFile("./asset/duck.png", NULL);
    status.sprite = sfSprite_create();
    status.rect = (sfIntRect){0, 0, 110, 110};
    sfSprite_setTexture(status.sprite, status.texture, sfTrue);
    sfSprite_setTextureRect(status.sprite, status.rect);
    status.clock = sfClock_create();
    status.pos = sfSprite_getPosition(status.sprite);
    sfSprite_setPosition(status.sprite, (sfVector2f){-110, rand() %300});
    status.grect = (sfIntRect){0, 0, 1280, 720};
    status.gtexture = sfTexture_createFromFile("./asset/game_over.png", NULL);
    status.gsprite = sfSprite_create();
    sfSprite_setTexture(status.gsprite, status.gtexture, sfTrue);
    sfSprite_setTextureRect(status.gsprite, status.grect);
    status.gclock = sfClock_create();
    return (status);
};

struct cursor_s initialize(void)
{
    struct cursor_s curs;

    curs.pos = (sfVector2f){0, 0};
    curs.sprite = sfSprite_create();
    curs.texture = sfTexture_createFromFile("./asset/cursor.png", NULL);
    sfSprite_setTexture(curs.sprite, curs.texture, sfTrue);
    sfSprite_setPosition(curs.sprite, curs.pos);
    return (curs);
};