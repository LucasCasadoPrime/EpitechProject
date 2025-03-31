/*
** EPITECH PROJECT, 2020
** BistroMatic
** File description:
** handling errors
*/

#include <stdlib.h>
#include "include/bistromatic.h"

#include <stdio.h>

int my_putstr(char const *str);

int is_a_digit(char const c, char const *base);

int is_a_ops(char const c, char const *ops);

static void check_parenthesis(char const *expr, char const *ops)
{
    int calc = 0;

    for (int i = 0; expr[i] != '\0'; i++) {
        if (expr[i] == ops[0])
            calc += 1;
        else if (expr[i] == ops[1])
            calc -= 1;
        if (expr[i] == ops[0] && expr[i + 1] == ops[1]) {
            calc = -1;
            break;
        }
    }
    if (calc != 0) {
        my_putstr(SYNTAX_ERROR_MSG);
        exit(EXIT_OPS);
    }
}

static void check_all_chars(char const *expr, char const *base, char const *ops)
{
    for (int i = 0; expr[i] != '\0'; i++) {
        if (is_a_digit(expr[i], base) == 0 && is_a_ops(expr[i], ops) == 0) {
            my_putstr(SYNTAX_ERROR_MSG);
            exit(EXIT_OPS);
        }
    }
}

static void check_all_expr(char const *expr, char const *base, char const *ops)
{
    (void)expr;
    (void)base;
    (void)ops;
    /*for (int i = 0; expr[i] != '\0'; i++) {
        if (is_a_ops(expr[i], ops) == 1 && is_a_ops(expr[i + 1], ops) == 1) {
            if (expr[i] != ops[1]) {
                my_putstr("1");
                exit(EXIT_OPS);
            }
        }
        if (is_a_ops(expr[i], ops) == 1 && is_a_digit(expr[i + 1], base) == 0) {
            if (expr[i] != ops[1] && expr[i + 1] != ops[0] && expr[i + 1] != '\0') {
                my_putstr("2");
                exit(EXIT_OPS);
            }
        }
        if (is_a_ops(expr[i], ops) == 1 && is_a_digit(expr[i - 1], base) == 0) {
            if (i != 3 && i > 0 && is_a_ops(expr[i - 1], ops) == 0) {
                my_putstr("3");
                exit(EXIT_OPS);
            }
        }
    }*/
}

void check_expr(char const *expr, char const *base, char const *ops)
{
    check_parenthesis(expr, ops);
    check_all_expr(expr, base, ops);
    check_all_chars(expr, base, ops);
}