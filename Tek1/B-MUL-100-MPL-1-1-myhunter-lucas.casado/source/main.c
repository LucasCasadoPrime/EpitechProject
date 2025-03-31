/*
** EPITECH PROJECT, 2021
** B-MUL-100-MPL-1-1-myhunter-lucas.casado
** File description:
** main
*/

#include "my_hunter.h"

int help(char *av)
{
    if (av[0] == '-' && av[1] == 'h') {
        my_putstr("Welcome to my_hunter !!!\n");
        my_putstr("The controls are:\n");
        my_putstr("Escape to quit\n");
        my_putstr("Press enter to play in the menu\n");
        my_putstr("Enjoy !\n");
        return (0);
    } else
        return (84);
}

int main(int ac, char **av)
{
    if (ac > 1)
        help(av[1]);
    else
        lines();
    return (0);
}

void lines(void)
{
    struct game_s obj = init();
    struct bird_s status = form();
    struct cursor_s curs = initialize();
    launch_game(obj, status, curs);
}