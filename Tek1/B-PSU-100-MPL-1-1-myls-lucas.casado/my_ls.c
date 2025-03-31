/*
** EPITECH PROJECT, 2020
** B-PSU-100-MPL-1-1-myls-lucas.casado
** File description:
** my_ls
*/

#include "my.h"

int my_ls(char **str)
{
    DIR *dirp;
    struct dirent *dp;
    dirp = opendir(".");
    if (str[1] != NULL)
        dirp = opendir(str[1]);
    if (dirp == NULL)
        exit(84);
    while ((dp = readdir(dirp)) != NULL) {
        if (dp->d_name[0] != '.') {
            my_printf("%s", dp->d_name);
            my_printf(" ");
        }
    }
    my_printf("\n");
    (void) closedir(dirp);
    return (EXIT_SUCCESS);
}