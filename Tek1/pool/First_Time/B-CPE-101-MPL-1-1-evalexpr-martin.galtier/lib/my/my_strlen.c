/*
** EPITECH PROJECT, 2020
** strlen
** File description:
** retruns number of characters
*/

int my_strlen(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        i++;
    }
    return (i);
}
