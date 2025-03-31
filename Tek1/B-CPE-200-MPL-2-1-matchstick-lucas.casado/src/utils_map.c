/*
** EPITECH PROJECT, 2021
** B-CPE-200-MPL-2-1-matchstick-lucas.casado
** File description:
** utils_map
*/

#include "../include/include.h"

int good_line(char *line, all *all)
{
    int new_line = 0;

    if (line[1] == '\0') {
        my_putstr("Error: invalid input (positive number expected)\n");
        return (0);
    }
    if (my_atoi(line) != - 1) {
        new_line = my_atoi(line);
        if (new_line > allline || new_line < 1) {
            my_putstr("Error: this line is out of range\n");
            return (0);
        }
    } else {
        my_putstr("Error: this line is out of range\n");
        return (0);
    }
    return (1);
}

int good_match(char *match, all *all, int match_left)
{
    int new_match = 0;

    if (match[1] == '\0') {
        my_putstr("Error: invalid input (positive number expected)\n");
        return (0);
    }
    if (my_atoi(match) != - 1) {
        new_match = my_atoi(match);
        if (new_match > all->max) {
            my_putstr("Error: you cannot remove more than ");
            my_putnbr(all->max);
            my_putstr(" matches per turn\n");
            return (0);
        }
        if (new_match > match_left) {
            my_putstr("Not enough matches\n");
            return (0);
        }
    } else {
        my_putstr("Error: this line is out of range\n");
        return (0);
    }
    return (1);
}

void removed(all *all, int match, int line, int n)
{
    if (n == 1) {
        my_putstr("Player removed ");
        my_putnbr(match);
        my_putstr(" match(es) from line ");
        my_putnbr(line);
        my_putstr("\n");
        return;
    }
    my_putstr("AI removed ");
    my_putnbr(1);
    my_putstr(" match(es) from line ");
    my_putnbr(all->ai);
    my_putchar('\n');
    return;
}

void remove_match(all *all, int line, int match, int n)
{
    int pos = 0;

    for (int i = 0; all->map[line - 1][i]; i += 1) {
        if (all->map[line][i] == '*' && all->map[line][i - 1] == '|') {
            pos = i - 1;
            break;
        }
        if (all->map[line][i] == ' ' && all->map[line][i - 1] == '|') {
            pos = i - 1;
            break;
        }
    }
    for (int x = 0; x != match; x += 1)
        all->map[line][pos - x] = ' ';
    removed(all, match, line, n);
    return;
}

int nb_matches2(all *all)
{
    int count = 0;
    int i;
    int line = 0;

    for (; all->map[line]; line++) {
        for (i = 0; all->map[line][i] != '\0'; i++) {
            if (all->map[line][i] == '|')
                count++;
        }
    }
    return (count);
}