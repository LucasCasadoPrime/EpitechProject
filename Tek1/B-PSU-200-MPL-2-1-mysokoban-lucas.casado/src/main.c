/*
** EPITECH PROJECT, 2021
** B-PSU-200-MPL-2-1-mysokoban-lucas.casado
** File description:
** main
*/

#include "../include/include.h"

int help(void)
{
    my_putstr("USAGE\n");
    my_putstr("\t/my_sokoban map\n");
    my_putstr("DESCRIPTION\n");
    my_putstr("\tmap  file representing the ");
    my_putstr("warehouse map, containing ‘#’ for walls,\n");
    my_putstr("\t     ‘P’ for the player, ‘X’ ");
    my_putstr("for boxes and ‘O’ for storage locations.\n");
    return (0);
}

int main(int ac, char **av)
{
    if (ac == 2) {
        if (av[1][0] == '-' && av[1][1] == 'h') {
            help();
            return (0);
        }
        if (goodfile(av[1]) != 84) {
            start(av[1]);
            return (0);
        }
    } else
            return (84);
    return (0);
}