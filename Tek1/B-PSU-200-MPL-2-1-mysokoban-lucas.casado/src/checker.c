/*
** EPITECH PROJECT, 2021
** B-PSU-200-MPL-2-1-mysokoban-lucas.casado
** File description:
** checker
*/

#include "../include/include.h"

bool blocker(perso_s *play, int x, int y)
{
    if (play->map[y][x] == '#')
        return (true);
    return (false);
}

bool iscrate(perso_s *play, int x, int y)
{
    if (play->map[y][x] == 'X')
        return (true);
    return (false);
}

bool wallcrate(perso_s *play, int x, int y)
{
    if (play->map[y][x] == 'X' || play->map[y][x] == '#')
        return (true);
    return (false);
}

bool issto(perso_s *play, int x, int y)
{
    if (play->map[y][x] == 'O')
        return (true);
    return (false);
}

void objectset(perso_s *play, int x, int y, char c)
{
    play->map[y][x] = c;
}