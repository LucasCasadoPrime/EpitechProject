/*
** EPITECH PROJECT, 2020
** EvalExpr
** File description:
** mathematical expre
*/

#include "lib/my/my.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

char *parse_number(const char **ptr)
{
    char *number = malloc(sizeof(char) * (my_strlen(*ptr) + 1));
    const char *expr = *ptr;
    int i = 0;

    while (expr[i] >= '0' && expr[i] <= '9') {
        number[i] = expr[i];
        i++;
    }
    number[i] = '\0';
    *ptr = expr + i;
    return (number);
}

// int my_operator(const char **expr, int nbr_1, int nbr_2, char *num_2)
// {
//     int result = 0;

//     if (**expr == '*') {
//         *expr += 1;
//         num_2 = parse_number(expr);
//         nbr_2 = my_getnbr(num_2);
//         result = nbr_1 * nbr_2;
//     } else if (**expr == '/') {
//         *expr += 1;
//         num_2 = parse_number(expr);
//         nbr_2 = my_getnbr(num_2);
//         result = nbr_1 / nbr_2;
//     } else if (**expr == '%') {
//         *expr += 1;
//         num_2 = parse_number(expr);
//         nbr_2 = my_getnbr(num_2);
//         result = nbr_1 % nbr_2;
//     }
//     return(result);
// }

int parse_operator(const char **expr)
{
    
    
    int i = 0;
    int result = 0;
    int num1 = 0;
    int numn =0;
    while (expr[i] != '\0') {
        parse_number(expr);
        my_getnbr(parse_number(expr));
        num1 == my_getnbr(parse_number(expr));
        if (**expr == '+'){
            *expr += 1;
            parse_number(expr);
            my_getnbr(parse_number(expr));
            numn = my_getnbr(parse_number(expr));
        }
        result = num1 + numn;
    }
    return (result);
}
    
// char *num_1 = parse_number(expr);
// char *num_2 = NULL;
// int nbr_1 = my_getnbr(num_1);
// int nbr_2 = 0;
// int result = 0;
// if (**expr == '+') {
//     *expr += 1;
//     num_2 = parse_number(expr);
//     nbr_2 = my_getnbr(num_2);
//     result = nbr_1 + nbr_2;
// }
//      else if (**expr == '-') {
//         *expr += 1;
//         num_2 = parse_number(expr);
//         nbr_2 = my_getnbr(num_2);
//         result = nbr_1 - nbr_2;
//     } else {
//         result = my_operator(expr, nbr_1, nbr_2, num_2);
//     }

int eval_expr(const char *expr)
{
    int nb = parse_operator(&expr);
    return (nb);
}

int main(int ac, char **av)
{
    if (ac == 2) {
        my_put_nbr(eval_expr(av[1]));
        my_putchar('\n');
        return (0);
    }
    return (84);
}