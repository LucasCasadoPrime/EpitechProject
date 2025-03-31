/*
** EPITECH PROJECT, 2021
** B-AIA-200-MPL-2-1-n4s-lucas.casado
** File description:
** executable
*/

#include "include.h"

int exe(const char *command)
{
    char *line = NULL;

    printf("%s", command);
    fflush(stdout);
    line = lread();
    if (line == NULL)
        return (false);
    if (end_run(line) == true)
        return (true);
    return (false);
}