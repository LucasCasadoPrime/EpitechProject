/*
** EPITECH PROJECT, 2020
** B-PSU-100-MPL-1-1-myls-lucas.casado
** File description:
** main
*/

#include "my.h"

int no_flags(char **str)
{
    int x = 0;
    for (int i = 0; str[i]; i++) {
        if (str[i][x] == '-')
            return (1);  
    }
    return (0);
}

int find_flag(char **str)
{
    int incr = 0;
    int x = 0;
    int charact = 0;
    for (int i = 0; str[i]; i++) {
        if (str[i][x] == '-') {
            x ++;
            for(int a = 0; a < FARRAY_SIZE; a++) {
                if (str[i][x] == flag[a].c)
                    flag[a].ptr(str);
            }
        }
    }
    return (0);
}

int main(int argc, char **argv)
{
    if (no_flags(argv) == 0)
        my_ls(argv);
    if (no_flags(argv) == 1)
        find_flag(argv);
}