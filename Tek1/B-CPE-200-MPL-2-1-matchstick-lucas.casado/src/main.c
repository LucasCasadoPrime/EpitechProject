/*
** EPITECH PROJECT, 2021
** B-PSU-200-MPL-2-1-mysokoban-lucas.casado
** File description:
** main
*/

#include "../include/include.h"

void player(all *all)
{
    char *line = NULL;
    char *match = NULL;
    int match_remain = 0;
    size_t size = 0; 

    my_putstr("Your turn:\n");
    do {
        do {
            my_putstr("Line: ");
            if (getline(&line, &size, stdin) == -1)
                return;
        } while (good_line(line, all) == 0);
        my_putstr("Matches: ");
        if (getline(&match, &size, stdin) == -1)
            return;
        match_remain = nb_matches(my_getnbr(line), all);
    } while (good_match(match, all, match_remain) == 0);
    remove_match(all, my_atoi(line), my_atoi(match), 1);
    return;
}

void ai(all *all)
{
    my_putstr("AI's turn...\n");
    ia_turn(all);
    return;
}

void loop_start(all *all)
{
    for (int nb_match = nb_matches2(all); \
    nb_match != 0; nb_match = nb_matches2(all)) {
        player(all);
        if (nb_matches2(all) == 0) {
            print_map(all, 2);
            my_putstr("You lost, too bad...\n");
            all->scene = 2;
            break;
        }
        print_map(all, 1);
        ai(all);
        if (nb_matches2(all) == 0) {
            print_map(all, 2);
            my_putstr("I lost... snif... but I'll get you next time!!\n");
            all->scene = 1;
            break;
        }
        print_map(all, 1);
    }
}

void start(char **av, all *all)
{
    all->line = my_getnbr(av[1]);
    all->max = my_getnbr(av[2]);
    create_map(all);
    put_matches(all);
    print_map(all, 1);
    loop_start(all);
    return;
}

int main(int ac, char **av)
{
    all all;
    if (ac != 3)
        return (84);
    if (my_getnbr(av[1]) <= 1 || my_getnbr(av[1]) >= 100)
        return (84);
    if (my_getnbr(av[2]) == 0 && my_getnbr(av[2]) < 1)
        return (84);
    start(av, &all);
    return (all.scene);
}