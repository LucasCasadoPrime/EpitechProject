/*
** EPITECH PROJECT, 2021
** B-AIA-200-MPL-2-1-n4s-lucas.casado
** File description:
** drive
*/


#include "include.h"

void drive(void)
{
    int appel = 0;

    while (true) {
        appel = speed();
        if (appel == 2)
            continue;
        if (appel == true)
            break;
        appel = dir();
        if (appel == 2)
            continue;
        if (appel == true)
            break;
    }
    exe(STOP_SIMULATION);
}

char *manage_str(char *str)
{
    char *tmp = malloc(sizeof(char) * COMMAND_LIMIT_SIZE);
    int pos = 0;
    int scd = 0;

    if (tmp == NULL)
        return (NULL);
    for (int i = 0; i < 3;)
        if (str[scd++] == ':')
            i++;
    for (; str[scd]; scd++)
        if ((str[scd] >= '0' && str[scd] <= '9') || str[scd] == '.'
            || str[scd] == ':') {
            tmp[pos] = str[scd];
            pos++;
        }
    tmp[pos] = '\0';
    return (tmp);
}

int end_run(char *str)
{
    int i = my_strlen(str) - 1;
    int j = 0;
    char *tmp = malloc(sizeof(char) * (my_strlen(str) + 1));

    if (tmp == NULL)
        return (true);
    for (; str[i] && str[i] != ':'; i--);
    for (i--; str[i] && str[i] != ':'; i--);
    i++;
    for (; str[i] && str[i] != ':';)
        tmp[j++] = str[i++];
    tmp[j] = '\0';
    if (my_strcmp(END_COMMAND, tmp) == 0)
    {
        free(tmp);
        exe(STOP_SIMULATION);
        return (true);
    }
    free(tmp);
    return (false);
}
