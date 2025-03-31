/*
** EPITECH PROJECT, 2020
** lib
** File description:
** headers for everything
*/

#ifndef MY_H_
#define MY_H_

#define WIDTH 1920
#define HEIGHT 1080

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <SFML/Audio/Sound.h>
#include <SFML/System.h>
#include <SFML/Window/Mouse.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

typedef struct node_s {
    void *value;
    struct node_s *next;
} node;

typedef struct enemy_t {
    sfSprite *sprite;
    sfIntRect rect;
    int tile_nb;
    float pv;
    int damages;
}enemy_s;

typedef struct menu {
    sfTime time;
    float seconds;
    sfClock *clock;
    sfSprite *sfirstbg;
    sfTexture *tfirstbg;
    sfSprite *sbg;
    sfTexture *tbg;
    sfIntRect rectbg;
    sfSprite *s_play;
    sfTexture *t_play;
    sfSprite *s_continue;
    sfTexture *t_continue;
    sfSprite *s_settings;
    sfTexture *t_settings;
    sfSprite *s_exit;
    sfTexture *t_exit;
}menu_s;

typedef struct game_t {
    sfSprite *smap;
    sfTexture *tmap;
    sfSprite *linkhouse;
    sfTexture *tlinkhouse;
    sfSprite *sinv;
    sfTexture *tinv;
    sfSprite *soverlay;
    sfTexture *toverlay;
    sfSprite *sinter;
    sfTexture *tinter;
    int inv;
    sfView *view;
    sfClock *clock;
    float seconds;
    sfTime time;
    float scale;
    char **save;
}game_s;

typedef struct music_t {
    sfMusic *game;
    sfMusic *menu;
    sfMusic *currentMusic;
}music_s;

typedef struct link_t {
    sfTime time;
    float seconds;
    sfTexture *texture;
    sfSprite *sprite;
    sfSprite *s_fight;
    sfTexture *t_fight;
    sfIntRect rect;
    sfIntRect r_fight;
    sfClock *c_fight;
    sfTime time_fight;
    float seconds_fight;
    sfClock *clock;
    int interact;
    int pv;
    int m_damages;
    int nb_potions;
}link_s;

typedef struct effect_t {
    sfTime time;
    float seconds;
    sfTexture *texture;
    sfSprite *sprite;
    sfIntRect rect;
    sfClock *clock;
} effect_s;

typedef struct fight_t {
    sfText *atk;
    sfText *heal;
    sfText *magic;
    sfText *escape;
    sfSprite *lifebar;
    sfIntRect rlifebar;
    sfClock *clock;
    float seconds;
} fight_s;

typedef struct items_s {
    sfSprite *sword;
} item_t;

typedef struct inventory_s {
    char **str;
    sfSprite *a_1;
    sfSprite *a_2;
    sfSprite *a_3;
    sfSprite *b_1;
    sfSprite *b_2;
    sfSprite *b_3;
    sfSprite *h_1;
    sfSprite *h_2;
    sfSprite *h_3;
    sfSprite *h_4;
    sfSprite *s_1;
    sfSprite *s_2;
    sfSprite *s_3;
    sfSprite *p;
} inventory_t;

typedef struct quest_t {
    sfTime time;
    float seconds;
    float seconds2;
    int scene;
    sfText *tfinn;
    sfClock *dialog;
    sfClock *house;
    sfSprite *white;
    sfIntRect rect;
} quest_s;

typedef struct rpg_s {
    int fight;
    char **map;
    int scene;
    sfRenderWindow *window;
    sfEvent event;
    menu_s *menu;
    music_s *music;
    game_s *game;
    link_s *link;
    effect_s *effect;
    fight_s *fights;
    quest_s *quest;
    sfSprite *s_fight;
    enemy_s *enemy1;
    enemy_s *boss;
    inventory_t *inventory;
    node *head;
}rpg_t;

void my_putchar(char c);
int my_put_nbr(int nb);
int my_putstr(char const *str);
int my_strlen(char const *str);
int my_getnbr(char const *str);
char *my_itoa(int nb);
int my_atoi(char *str);
char *my_strcat(char *dest, char *src);
void my_sort_int_array(int *tab, int size);
char **my_str_to_word_array(char *str, const char *separator);
char **my_str_to_word_array2(char *str, const char *separator);
char *my_strncpy(char *dest, char const *src, int n);
int my_strcmp(char const *s1, char const *s2);
char *my_strcpy( char *dest, char const *src);
int my_strncmp(char const *s1, char const *s2, int n);

void malloc_structs(rpg_t *rpg);
void game_menu(rpg_t *rpg);
void game_menu2(rpg_t *rpg);
void start_game(rpg_t *rpg);
void game_display(rpg_t *rpg);
void update_music(rpg_t *rpg);
void cursor(rpg_t *rpg);

void init(rpg_t *rpg);
void link_init(rpg_t *rpg);
void init_boss(enemy_s *boss);
void init_enemy1(enemy_s *enemy1);
void destroy_menu(rpg_t *rpg);
void destroy_game(rpg_t *rpg);
void destroy_entity(rpg_t *rpg);

void new_save(void);
void save(rpg_t *rpg);
void auto_save(rpg_t *rpg);
void load_save(rpg_t *rpg);

void link_walk(rpg_t *rpg);
void link_walk_top(rpg_t *rpg);
void link_walk_left(rpg_t *rpg);
void link_walk_right(rpg_t *rpg);
void link_walk_down(rpg_t *rpg);
int check_top(rpg_t *rpg);
int check_left(rpg_t *rpg);
int check_down(rpg_t *rpg);
int check_right(rpg_t *rpg);
int check_inter(rpg_t *rpg);

void menu_event(rpg_t *rpg);
void menu2_event2(rpg_t *rpg);
void menu2_event(rpg_t *rpg);
void game_event(rpg_t *rpg);

void fight(rpg_t *rpg, enemy_s *enemy);
void init_fight(rpg_t *rpg);
void fight_events(rpg_t *rpg, enemy_s *enemy);

void fight_win(rpg_t *rpg);
void fight_lose(rpg_t *rpg);

void init_effect(rpg_t *rpg);
void rain(rpg_t *rpg);

node *create_map(char *content);
char *map_read(void);

char *open_file(char *filename);

void print_life(rpg_t *rpg);

int turn(int id);

void display_inventory(rpg_t *rpg);
void init_inventory(rpg_t *rpg);

void init_quest(rpg_t *rpg);
void text(rpg_t *rpg);
void text_house(rpg_t *rpg);

void init_spawn(rpg_t *rpg);
void spawn(rpg_t *rpg);


void node_push_front(node **head, void *value);
void node_push_back(node **head, void *value);
node *node_nsearch(node **head, void *value, int nb);
node *node_search(node **head, void *value);
int node_size(node **head);
int node_exists(node **head, node *to_detect);
char **node_to_array(node **head);
void node_free_one(node **head, node *to_del);
void node_free_all(node **head);
node **gc_get_list(void);
__attribute__ ((alloc_size (1))) void *gc_malloc(size_t to_alloc);
void *gc_add_ptr(void *ptr);
__attribute__ ((destructor)) void gc_destroy(void);
int show_string(char const *str);
void show_number(int nb);
char *my_strcpy(char *dest, char const *src);
char *my_strncpy(char *dest, char const *src, int n);
char *my_strdup(const char *s);
char *my_strndup(const char *s, int n);
int my_strcmp(char const *s1, char const *s2);
int my_strncmp(char const *s1, char const *s2, int n);
char *my_strstr(char *str, char const *to_find);
char *reverse_string(char *str);
int string_length(char const *str);
int check_contains(char c, char *to_verify);
int contains(char *str, char *to_verify);
int is_separator(const char c, const char *separators);
void last_word(node **head, char *tmp, const char c, \
const char *separators);
void create_words(node **head, const char *str, const char *separators);
void free_char_array(char **array);
int absolute_number(int nb);
int number_length(int nb);
char *my_itoa(int nb);
int dec_to_binary(unsigned int n);
int is_digit(char c);
int to_number(char const *str);
int is_prime_number(int nb);
void *my_memset(void *ptr, int c, int n);
void *my_calloc(int nb, int size);

int add_xp(int to_add);
int xp_to(int level);
int actual_lvl(void);
int remain_xp(void);
int needed_xp(void);

void fight_zone(rpg_t *rpg);
void fight_rand(rpg_t *rpg);
void print_ui(rpg_t *rpg);

void fight_potion(rpg_t *rpg);

#endif /* !MY_H_ */