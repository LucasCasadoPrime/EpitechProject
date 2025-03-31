/*
** EPITECH PROJECT, 2021
** B-PSU-200-MPL-2-1-mysokoban-lucas.casado
** File description:
** verifmap
*/

#include "../include/include.h"

int goodfile(char *av)
{
    struct stat sb;
    int file;

    file = stat(av, &sb);
    if (file == -1 || S_ISREG(sb.st_mode) == 0)
        return (84);
}

char *map_read(char *av)
{
    int fd = open(av, O_RDONLY);
    char *content = NULL;
    struct stat s;
    int error = stat(av, &s);

    content = malloc(s.st_size + 1);
    content[s.st_size] = 0;
    read(fd, content, s.st_size);
    close(fd);
    return (content);
}

int validchar(char c)
{
    if (c == '#' || c == 32 || c == '\n' || c == 'X' || c == 'P' || c == 'O')
        return (0);
    return (-1);
}

int validmap(char *strmap, perso_s *play)
{
    int p = 0;
    int x = 0;
    int o = 0;

    for (int i = 0; strmap[i]; i++) {
        if (strmap[i] == 'P')
            p++;
        if (strmap[i] == 'X')
            x++;
        if (strmap[i] == 'O') {
            o++;
        }
        if (validchar(strmap[i]) == -1)
            return (84);
    }
    if (p > 1 || x != o) {
        write(2, "Invalid Map\n", 12);
        return (84);
    }
    return (0);
}