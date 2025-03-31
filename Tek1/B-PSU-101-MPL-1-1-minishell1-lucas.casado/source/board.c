/*
** EPITECH PROJECT, 2021
** B-PSU-101-MPL-1-1-minishell1-lucas.casado
** File description:
** board
*/

#include "sh.h"

node *search(node **head, void *value, int nb)
{
    for (node *tmp = (*head); tmp != NULL; tmp = tmp->next)
        if (my_strncmp(tmp->value, value, nb) == 0)
            return (tmp);
    return (NULL);
}

int cmd(char **command)
{
    if (my_strncmp(command[0], "exit", 4) == 0) {
        exit(0);
        return (1);
    }
    return (0);
}

int reco(node **env, char **command)
{
    node *path = search(env, "PATH=", 5);
    char tmp[2000];
    char **content;
    struct stat sb;
    int swap = 0;
    
    my_strcpy(tmp, path->value);
    content = my_str_to_word_array(&tmp[5], ":");
    for (int i = 0; content[i]; i++) {
        content[i] = my_strcat(my_strcat(content[i], "/") , command[0]);
        if (stat(content[i], &sb) != -1) {
            exe(content[i], command, env);
            swap = 1;
            break;
        }
    }
    cmd(command);
    if (swap == 0) {
        my_putstr(command[0]);
        write (2, ": Command not found\n", 20);
    }
    return (0);
}


int board(node **env, char **av, char *buf)
{
    (void) av;
    char **temp = my_str_to_word_array(buf, "\n");
    char **buff;
    
    for (int i = 0; temp[i]; i += 1) {
        buff = my_str_to_word_array(temp[i], " \t");
        reco(env, buff);
    }
    return (0);
}