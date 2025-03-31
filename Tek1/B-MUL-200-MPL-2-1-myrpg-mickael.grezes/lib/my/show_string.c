/*
** EPITECH PROJECT, 2020
** LibMy
** File description:
** show_string
*/

#include <unistd.h>

int string_length(char const *str);

int show_string(char const *str)
{
    return (write(1, str, string_length(str)));
}