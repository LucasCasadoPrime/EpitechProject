/*
** EPITECH PROJECT, 2021
** B-MUL-200-MPL-2-1-myrpg-mickael.grezes
** File description:
** init
*/

#include "my.h"

void init_music(rpg_t *rpg)
{
    rpg->music->menu = sfMusic_createFromFile("assets/menu.ogg");
    rpg->music->game = sfMusic_createFromFile("assets/music.ogg");
    rpg->music->currentMusic = sfMusic_createFromFile("assets/menu.ogg");
    link_init(rpg);
    init_effect(rpg);
    init_fight(rpg);
    init_enemy1(rpg->enemy1);
    init_boss(rpg->boss);
    init_quest(rpg);
    init_spawn(rpg);
}

void init_map(rpg_t *rpg)
{
    char *content = open_file("assets/test.txt");
    sfTexture *fight = sfTexture_createFromFile("assets/fight.png", NULL);

    rpg->map = my_str_to_word_array(content, "\n");
    free(content);
    rpg->fight = 0;
    rpg->s_fight = sfSprite_create();
    sfSprite_setPosition(rpg->link->s_fight, (sfVector2f){50.0, 650.0});
    sfSprite_setTexture(rpg->s_fight, fight, sfTrue);
    rpg->fights->clock = sfClock_create();
}

void init_game(rpg_t *rpg)
{
    rpg->menu->s_continue = sfSprite_create();
    rpg->menu->t_continue = sfTexture_createFromFile("assets/cont.png", NULL);
    sfSprite_setTexture(rpg->menu->s_continue, rpg->menu->t_continue, sfFalse);
    sfSprite_setPosition(rpg->menu->s_continue, (sfVector2f){740.0, 425.0});
    rpg->game->tmap = sfTexture_createFromFile("assets/map.png", NULL);
    rpg->game->smap = sfSprite_create();
    sfSprite_setTexture(rpg->game->smap, rpg->game->tmap, sfTrue);
    sfSprite_setScale(rpg->game->smap, (sfVector2f){3, 3});
    sfSprite_setPosition(rpg->game->smap, (sfVector2f){-500, -500});
    rpg->game->sinter = sfSprite_create();
    rpg->game->tinter = sfTexture_createFromFile("assets/inter.png", NULL);
    sfSprite_setTexture(rpg->game->sinter, rpg->game->tinter, sfTrue);
    sfSprite_setPosition(rpg->game->sinter, (sfVector2f){900, 450});
    rpg->game->save = malloc(sizeof(char *) * 2);
    rpg->game->sinv = sfSprite_create();
    rpg->game->tinv = sfTexture_createFromFile("assets/inventory.png", NULL);
    sfSprite_setTexture(rpg->game->sinv, rpg->game->tinv, sfTrue);
    rpg->game->inv = 0;
    init_music(rpg);
    init_map(rpg);
}

void init2(rpg_t *rpg)
{
    rpg->menu->sbg = sfSprite_create();
    rpg->menu->tbg = sfTexture_createFromFile("assets/bg.png", NULL);
    sfSprite_setTexture(rpg->menu->sbg, rpg->menu->tbg, sfTrue);
    rpg->menu->s_play = sfSprite_create();
    rpg->menu->t_play = sfTexture_createFromFile("assets/play.png", NULL);
    sfSprite_setTexture(rpg->menu->s_play, rpg->menu->t_play, sfFalse);
    sfSprite_setPosition(rpg->menu->s_play, (sfVector2f){740.0, 250.0});
    rpg->menu->s_settings = sfSprite_create();
    rpg->menu->t_settings = \
    sfTexture_createFromFile("assets/settings.png", NULL);
    sfSprite_setTexture(rpg->menu->s_settings, rpg->menu->t_settings, \
    sfFalse);
    sfSprite_setPosition(rpg->menu->s_settings, (sfVector2f){740.0, 600.0});
    rpg->menu->s_exit = sfSprite_create();
    rpg->menu->t_exit = sfTexture_createFromFile("assets/exit.png", NULL);
    sfSprite_setTexture(rpg->menu->s_exit, rpg->menu->t_exit, sfFalse);
    sfSprite_setPosition(rpg->menu->s_exit, (sfVector2f){740.0, 774.0});
    init_game(rpg);
}

void init(rpg_t *rpg)
{
    sfVideoMode mode = {WIDTH, HEIGHT, 32};
    rpg->window = sfRenderWindow_create(mode, "My rpg", sfFullscreen, NULL);
    sfRenderWindow_setFramerateLimit(rpg->window, 30);
    sfRenderWindow_clear(rpg->window, sfWhite);
    rpg->menu->sfirstbg = sfSprite_create();
    rpg->menu->tfirstbg = sfTexture_createFromFile("assets/firstbg.png", NULL);
    rpg->menu->rectbg = (sfIntRect){0, 0, 1920, 1080};
    sfSprite_setTexture(rpg->menu->sfirstbg, rpg->menu->tfirstbg, sfTrue);
    sfSprite_setTextureRect(rpg->menu->sfirstbg, rpg->menu->rectbg);
    rpg->menu->clock = sfClock_create();
    rpg->scene = 1;
    rpg->game->clock = sfClock_create();
    rpg->game->soverlay = sfSprite_create();
    rpg->game->toverlay = sfTexture_createFromFile("assets/overlay.png", NULL);
    sfSprite_setTexture(rpg->game->soverlay, rpg->game->toverlay, sfTrue);
    sfSprite_setScale(rpg->game->soverlay, (sfVector2f){3, 3});
    sfSprite_setPosition(rpg->game->soverlay, (sfVector2f){-500, -500});
    init2(rpg);
}