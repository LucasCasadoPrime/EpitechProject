/*
** EPITECH PROJECT, 2020
** BistroMatic
** File description:
** do calcs
*/

#include <stdio.h>

char *infin_add(char *expr_one, char *expr_two);

char *infin_sub(char *expr_one, char *expr_two);

char *infin_mul(char *expr_one, char *expr_two);

char *infin_div(char *expr_one, char *expr_two);

char *infin_mod(char *expr_one, char *expr_two);

char *do_calc(char *expr_one, char *expr_two, char *op)
{
    char *result;
    if (op[0] == '+')
        result = infin_add(expr_one, expr_two);
    if (op[0] == '-')
        result = infin_sub(expr_one, expr_two);
    if (op[0] == '*')
        result = infin_mul(expr_one, expr_two);
    if (op[0] == '/')
        result = infin_div(expr_one, expr_two);
    if (op[0] == '%')
        result = infin_mod(expr_one, expr_two);
    return (result);
}