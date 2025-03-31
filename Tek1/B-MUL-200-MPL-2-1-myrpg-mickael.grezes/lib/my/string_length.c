/*
** EPITECH PROJECT, 2020
** LibMy
** File description:
** string_length
*/

int string_length(char const *str)
{
    int lengh = 0;

    for (; str[lengh]; lengh += 1);
    return (lengh);
}