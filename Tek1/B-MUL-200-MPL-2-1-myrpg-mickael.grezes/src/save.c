/*
** EPITECH PROJECT, 2021
** B-MUL-200-MPL-2-1-myrpg-mickael.grezes
** File description:
** save
*/

#include "my.h"

void auto_save(rpg_t *rpg)
{
    int fd = open("save.txt", O_CREAT | O_TRUNC | O_RDWR, 0644);

    for (int i = 0; rpg->game->save[i] != 0; i += 1) {
        write(fd, rpg->game->save[i], my_strlen(rpg->game->save[i]));
        write(fd, "\n", 1);
    }
}

void save(rpg_t *rpg)
{
    sfVector2f pos = sfSprite_getPosition(rpg->game->smap);
    char *x = my_itoa((int)pos.x);
    char *y = my_itoa((int)pos.y);
    char *save = open_file("save.txt");
    char *tmp;

    rpg->game->save = my_str_to_word_array2(save, "\n");
    free(save);
    tmp = malloc(my_strlen(x) + my_strlen(y) + 2);
    if (!tmp)
        return;
    my_strcpy(tmp, x);
    my_strcat(tmp, ".");
    my_strcat(tmp, y);
    rpg->game->save[1] = tmp;
    free(x);
    free(y);
    rpg->game->save[5] = my_itoa(add_xp(0));
}