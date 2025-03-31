/*
** EPITECH PROJECT, 2020
** B-MUL-100-MPL-1-1-myhunter-lucas.casado
** File description:
** my_hunter
*/

#ifndef my_hunt
#define my_hunt

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <SFML/System.h>
#include <stdio.h>
#include <stdlib.h>
#include <SFML/System/Vector2.h>
#include <SFML/Window/Export.h>
#include <SFML/Window/Types.h>

typedef struct game_s
{
    float vol;
    float seconds;
    int swap;
    int swap2;
    sfVideoMode mode;
    sfRenderWindow *window;
    sfMusic *bmmusic;
    sfSprite *bmsprite;
    sfClock *bmclock;
    sfTexture *bmtexture;
    sfSprite *bgsprite;
    sfTexture *bgtexture;
    sfIntRect rect;
    sfIntRect bgrect;
    sfVector2f pos;
    sfTime time;
    sfTexture *tnew_game;
    sfSprite *snew_game;
} game_t;

typedef struct bird_s
{
    sfIntRect rect;
    sfSprite *sprite;
    sfTexture *texture;
    sfClock *clock;
    sfVector2f pos;
    sfSprite *gsprite;
    sfClock *gclock;
    sfTexture *gtexture;
    sfIntRect grect;
    sfMusic *gmusic;
} bird_t;

typedef struct cursor_s
{
    sfCursor *curs;
    sfVector2f pos;
    sfSprite *sprite;
    sfTexture *texture;
} cursor_t;

//main.c
int help(char *av);
int main(int ac, char **av);

//struct_+_lauch.c
void launch_game(struct game_s obj, struct bird_s status, \
struct cursor_s curs);
struct game_s manage_event(struct game_s obj, \
struct bird_s status, sfEvent event);
void destroy_all(struct cursor_s curs, struct bird_s status, struct game_s obj);
void lines(void);

//menu.c
void destroy(struct game_s obj);
struct game_s menu_display(struct game_s obj);

//game.c
struct game_s background_game_display(struct game_s obj);
void bgdestroy(struct game_s obj);

//bird_anim.c
struct bird_s birds_anim(struct bird_s status, struct game_s obj);
void destroy_bird(struct bird_s status);

//gogame.c
struct bird_s game_over_display(struct game_s obj, struct bird_s status);
void game_over_destroy(struct bird_s status);

//cursor.c
struct cursor_s cursor(struct cursor_s curs, struct game_s obj);
void display_cursor(struct cursor_s curs, struct game_s obj);
void destroy_cursor(struct cursor_s curs);

// utilities
void my_putchar(char c);
int my_putstr (char const *str);

//id.c
struct cursor_s initialize(void);
struct bird_s form(void);
struct over_s game_over(void);
struct game_s init(void);
void set_struct(struct game_s obj);

#endif /* !HUNTER_H_ */