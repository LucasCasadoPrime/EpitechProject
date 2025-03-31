/*
** EPITECH PROJECT, 2021
** B-CPE-200-MPL-2-1-matchstick-lucas.casado
** File description:
** geet_nbr
*/

#include "../include/include.h"

int my_strlen(char const *str)
{
    int i;
    
    for (i = 0; str[i]; i++);
    return i;
}

void convert_to_number(char c, int *number)
{
    char array_digits[10] = "0123456789";

    for (int is = 0; is <= 9; is++) {
        if (c == array_digits[is]) {
            *number = 10 * *number + is;
            return;
        }
    }
}

int is_number(char c)
{
    char array_digits[10] = "0123456789";

    for (int i = 0; i <= 9; i++) {
        if (c == array_digits[i])
            return (1);
    }
    return (0);
}

void neg_task(char c, int *isneg)
{
    if (c == '-')
        *isneg *= -1;
}

int my_getnbr(char const *str)
{
    int number = 0;
    int isneg = 1;

    for (int index = 0 ; index <= my_strlen(str) ; index++) {
        neg_task(str[index], &isneg);
        if (number == 214748364 && str[index] == '8' && isneg == -1)
            return -2147483648;
        convert_to_number(str[index], &number);
        if (str[index] != '-' && str[index] != '+' && !is_number(str[index]))
            return (number < 0 ? 0 : number * isneg);
    }
    if (number < 0)
        return 0;
    return (number * isneg);
}