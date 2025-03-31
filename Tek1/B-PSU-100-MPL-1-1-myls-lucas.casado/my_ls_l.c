/*
** EPITECH PROJECT, 2020
** B-PSU-100-MPL-1-1-myls-lucas.casado
** File description:
** my_ls_l
*/

#include "my.h"


void print_date(struct stat sb)
{
    char *date = ctime(&sb.st_mtim.tv_sec);

    write(1, &date[4], my_strlen(date) - 13);
    my_printf(" ");
}


void print_long_list(struct stat sb, char **str, struct dirent *dp)
{
    printf("%ld", (long) sb.st_nlink);
    printf("%ld", (long) sb.st_uid);
    printf("%ld", (long) sb.st_gid);
    my_printf("%d", sb.st_size);
    my_printf(" ");
    print_date(sb);
}

int my_ls_l(char **str)
{
    DIR *dirp;
    struct dirent *dp;
    struct stat sb;
    dirp = opendir(".");
    if (str[2] != NULL)
        dirp = opendir(str[2]);
    if (dirp == NULL) {
        exit(84);
    }
    while ((dp = readdir(dirp)) != NULL) {
        if (dp->d_name[0] != '.') {
            print_long_list(sb, str, dp);
            my_printf(" ");
            my_printf("%s", dp->d_name);
            my_printf("\n");
        }
    }
    (void) closedir(dirp);
    return (EXIT_SUCCESS);
}
