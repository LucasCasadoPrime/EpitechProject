/*
** EPITECH PROJECT, 2021
** B-PSU-200-MPL-2-1-mysokoban-lucas.casado
** File description:
** checker2
*/

#include "../include/include.h"

bool wallcratec(char c)
{
    if (c == 'X' || c == '#')
        return (0);
    return (1);
}