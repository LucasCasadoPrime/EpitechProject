/*
** EPITECH PROJECT, 2021
** B-PSU-101-MPL-1-1-minishell1-lucas.casado
** File description:
** execute
*/

#include "sh.h"

char **transform(node **env)
{
    char **array;
    int i = 0;

    for (node *tmp = (*env); tmp != NULL; tmp = tmp->next)
        i++;
    array = malloc(sizeof(char *) * i + 1);
    i = 0;
    for (node *tmp = (*env); tmp != NULL; tmp = tmp->next) {
        array[i] = my_strdup(tmp->value);
        i++;
    }
    array[i] = 0;
    return (array);
}

int exe(char *content, char **opt, node **env)
{
    int dup = fork();
    int status;
    
    if (dup == 0)
        execve(content, opt, transform(env));
    else
        waitpid(dup, &status, 0);
    return (1);
}