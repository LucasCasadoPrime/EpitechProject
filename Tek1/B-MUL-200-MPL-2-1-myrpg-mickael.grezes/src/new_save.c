/*
** EPITECH PROJECT, 2021
** B-MUL-200-MPL-2-1-myrpg-mickael.grezes
** File description:
** new_save
*/

#include "my.h"

void load_save(rpg_t *rpg)
{
    int i = 0;
    int m = 0;
    char *x = 0;
    char *y = 0;
    char *save = open_file("save.txt");

    rpg->game->save = my_str_to_word_array2(save, "\n");
    free(save);
    for (i = 0; rpg->game->save[1][i] != '.'; i += 1);
    for (m = i + 1; rpg->game->save[1][m] != '\n'; m += 1);
    x = my_strncpy(x, rpg->game->save[1], i + 1);
    y = my_strncpy(y, &rpg->game->save[1][i + 1], m);
    sfSprite_setPosition(rpg->game->smap, (sfVector2f){my_atoi(x), my_atoi(y)});
    sfSprite_setPosition(rpg->game->soverlay, \
    (sfVector2f){my_atoi(x), my_atoi(y)});
    add_xp(-1);
    add_xp(my_atoi(rpg->game->save[5]));
}

void new_save(void)
{
    int fd = open("save.txt", O_CREAT | O_TRUNC | O_RDWR, 0644);

    write(fd, "Player pos:\n", 12);
    write(fd, "-999.-2282\n", 11);
    write(fd, "Inventory:\n", 11);
    write(fd, "01.00|02.00|03.00|04.00|05.00|06.00|07.00|08.00|09.00|", 54);
    write(fd, "10.00|11.00|12.00|13.00|14.00|15.00", 35);
    write(fd, "\nXP:\n", 5);
    write(fd, "0\n", 2);
}