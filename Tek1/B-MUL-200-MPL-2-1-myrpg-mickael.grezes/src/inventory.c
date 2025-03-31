/*
** EPITECH PROJECT, 2021
** B-MUL-200-MPL-2-1-myrpg-mickael.grezes
** File description:
** inventory
*/

#include "my.h"

void init_inventory(rpg_t *rpg)
{
    int pos = 0;
    char *save = open_file("save.txt");
    char **str;

    for (; my_strncmp(&save[pos], "01.", 3); pos += 1);
    str = my_str_to_word_array2(&save[pos], "|");
    node_free_all(&rpg->head);
    for (int i = 0; i != 15; i += 1) {
        node_push_back(&rpg->head, str[i]);
    }
}