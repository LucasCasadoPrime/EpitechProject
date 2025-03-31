/*
** EPITECH PROJECT, 2021
** B-PSU-101-MPL-1-1-bsminishell1-lucas.casado
** File description:
** main
*/

#include "sh.h"

int start(node **env, char **av)
{
    int buff_size = 1000;
    char buff[buff_size];
    int fd;

    while ((fd = read(0, buff, buff_size)) > 0) {
        if (fd == buff_size) {
            write(2, "too much argument\n", 19);
            continue;
        }
        buff[fd] = 0;
        board(env, av, buff);
        write(1, "$ > ", 4);
    }
    return (0);
}

int main(int ac, char **av, char **base_env)
{
    (void) ac;
    node *env = NULL;
    for (int i = 0; base_env[i]; i += 1)
        push_back(&env, my_strdup(base_env[i]));
    if (isatty(0) != 0)
        write(1, "$ > ", 4);
    start(&env, av);
    return (0);
}