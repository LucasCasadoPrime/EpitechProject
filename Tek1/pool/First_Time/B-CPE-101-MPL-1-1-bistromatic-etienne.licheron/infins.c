/*
** EPITECH PROJECT, 2020
** BistroMatic
** File description:
** Infins
*/

#include <stdio.h>

long long my_getnbr(char const *str);

char *my_itoa(long long nb);

char *infin_add(char *expr_one, char *expr_two)
{
    long long term_one = my_getnbr(expr_one);
    long long term_two = my_getnbr(expr_two);
    long long result = term_one + term_two;
    char *final_result = my_itoa(result);

    return (final_result);
}

char *infin_sub(char *expr_one, char *expr_two)
{
    long long term_one = my_getnbr(expr_one);
    long long term_two = my_getnbr(expr_two);
    long long result = term_one - term_two;
    char *final_result = my_itoa(result);

    return (final_result);
}

char *infin_mul(char *expr_one, char *expr_two)
{
    long long term_one = my_getnbr(expr_one);
    long long term_two = my_getnbr(expr_two);
    long long result = term_one * term_two;
    char *final_result = my_itoa(result);

    return (final_result);
}

char *infin_div(char *expr_one, char *expr_two)
{
    long long term_one = my_getnbr(expr_one);
    long long term_two = my_getnbr(expr_two);
    long long result = term_one / term_two;
    char *final_result = my_itoa(result);

    return (final_result);
}

char *infin_mod(char *expr_one, char *expr_two)
{
    long long term_one = my_getnbr(expr_one);
    long long term_two = my_getnbr(expr_two);
    long long result = term_one % term_two;
    char *final_result = my_itoa(result);

    return (final_result);
}