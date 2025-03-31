/*
** EPITECH PROJECT, 2021
** B-AIA-200-MPL-2-1-n4s-lucas.casado
** File description:
** speed
*/


#include "include.h"

int forward(double speed)
{
    const char *go = "car_forward:";
    char *line = NULL;

    my_put_str(go);
    my_put_float(speed);
    my_put_char('\n');
    line = lread();
    if (line == NULL)
        return (false);
    if (end_run(line) == true)
        return (true);
    return (false);
}

int sconvert(double valor)
{
    double speed;
    int fast;

    if (valor >= 2000)
        speed = 1.0;
    else if (valor >= 1500)
        speed = 0.85;
    else if (valor >= 1000)
        speed = 0.75;
    else if (valor >= 600)
        speed = 0.65;
    else if (valor >= 400)
        speed = 0.55;
    else
        speed = 0.35;
    fast = forward(speed);
    return (fast);
}

int speed(void)
{
    char *line = NULL;
    char **content = NULL;
    double speed;

    my_put_str(GET_INFO_COMMAND);
    line = lread();
    if (line == NULL)
        return (2);
    end_run(line);
    line = manage_str(line);
    content = my_str_to_word_array(line, ":");
    if (content == NULL)
        return (2);
    speed = atof(content[SPEED_POS]);
    if (sconvert(speed) == true)
        return (true);
    free(line);
    return (false);
}