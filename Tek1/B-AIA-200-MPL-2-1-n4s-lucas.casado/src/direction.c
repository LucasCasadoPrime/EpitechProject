/*
** EPITECH PROJECT, 2021
** B-AIA-200-MPL-2-1-n4s-lucas.casado
** File description:
** direction
*/



#include "include.h"

int return_dir(double wheel, const char *str)
{
    const char *wheel_command = "wheels_dir:";
    char *line = NULL;

    my_put_str(wheel_command);
    if (wheel < 0)
        my_put_char('-');
    my_put_str(str);
    line = lread();
    if (line == NULL)
        return (false);
    if (end_run(line) == true)
        return (true);
    return (false);
}

int dconvert(char **content, double dir)
{
    double val = atof(content[1]) - atof(content[31]);
    int val_return = false;

    if (dir >= 1500)
        val_return = return_dir(val, "0.005\n");
    else if (dir >= 1000)
        val_return = return_dir(val, "0.05\n");
    else if (dir >= 600)
        val_return = return_dir(val, "0.15\n");
    else if (dir >= 400)
        val_return = return_dir(val, "0.25\n");
    else if (dir >= 200)
        val_return = return_dir(val, "0.35\n");
    else
        val_return = return_dir(val, "0.55\n");
    return (val_return);
}

int dir(void)
{
    char *line = NULL;
    char **content = NULL;
    double dir;

    my_put_str(GET_INFO_COMMAND);
    line = lread();
    if (line == NULL)
        return (2);
    end_run(line);
    line = manage_str(line);
    content = my_str_to_word_array(line, ":");
    if (content == NULL)
        return (2);
    dir = atof(content[DIRECTION_POS]);
    if (dconvert(content, dir) == true)
        return (true);
    free(line);
    return (false);
}