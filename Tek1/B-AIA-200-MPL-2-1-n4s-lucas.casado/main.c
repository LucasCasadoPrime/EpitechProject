/*
** EPITECH PROJECT, 2021
** need4stek
** File description:
** main
*/

#include "include.h"

int main(int ac, char **as)
{
    if (ac == 0 || as == NULL)
        return (EXIT_FAIL);
    exe(START_SIMULATION);
    drive();
    return (EXIT_OK);
}
