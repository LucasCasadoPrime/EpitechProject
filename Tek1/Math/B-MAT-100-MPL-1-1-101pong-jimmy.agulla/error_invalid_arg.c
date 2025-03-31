/*
** EPITECH PROJECT, 2020
** pong
** File description:
** update structures
*/

#include "pong.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void error_invalid_arg(int argc, char **argv)
{
    for (int c = 1; c < argc; c++)
        for (int v = 0; argv[c][v] != 0; v++)
            condition_invalid_arg(argc, argv, c, v);
}

void condition_invalid_arg(int argc, char **argv, int c, int v)
{
    if ('0' <= argv[c][v] && argv[c][v] <= '9') {
        return;
    } else if (argv[c][v] == '-' || argv[c][v] == '.' || argv[c][v] == ' ') {
        return;
    }
    else {
        printf("invalid input\n");
        exit(84);
    }
}