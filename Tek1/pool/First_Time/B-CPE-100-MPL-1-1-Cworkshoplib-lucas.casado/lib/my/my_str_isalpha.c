/*
** EPITECH PROJECT, 2020
** lib
** File description:
** my_str_isalpha
*/
#include <unistd.h>

void my_putchar(char c);
int my_put_nbr(int nb);

int my_str_isalpha(char const *str)
{
    int i = 0;
    while (str[i] != '\0') {
        if ((str[i] >= 65 && str[i] <= 90) || (str[i] >= 97 && str[i] <= 122)) {
            i++;
        } else {
            return (0);
        }
    }
    return (1);
}
