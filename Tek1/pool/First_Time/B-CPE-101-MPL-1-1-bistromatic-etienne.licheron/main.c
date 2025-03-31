/*
** EPITECH PROJECT, 2020
** Bistromatic
** File description:
** main function
*/

#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "include/bistromatic.h"

int my_putstr(char const *str);

int my_strlen(char const *str);

int my_atoi(char *str);

int print_help(void);

int my_strcmp(char const *s1, char const *s2);

void check_expr(char const *expr, char const *base, char const *ops);

static char *get_expr(unsigned int size)
{
    char *expr;

    if (size <= 0) {
        my_putstr(SYNTAX_ERROR_MSG);
        exit(EXIT_SIZE_NEG);
    }
    expr = malloc(size + 1);
    if (expr == 0) {
        my_putstr(ERROR_MSG);
        exit(EXIT_MALLOC);
    }
    if (read(0, expr, size) != size) {
        my_putstr(ERROR_MSG);
        exit(EXIT_READ);
    }
    expr[size] = 0;
    return (expr);
}

static void check_ops(char const *ops, char const *expr, char const *b)
{
    for (int i = 0; ops[i] != '\0'; i++) {
        for (int j = 0; ops[j] != '\0'; j++) {
            if (ops[i] == ops[j] && i > j) {
                my_putstr(SYNTAX_ERROR_MSG);
                exit(EXIT_BASE);
            }
        }
    }
    if (my_strlen(ops) != 7) {
        my_putstr(SYNTAX_ERROR_MSG);
        exit(EXIT_OPS);
    }
    check_expr(expr, b, ops);
}

static void check_errors(char const *b, char const *ops, char const *expr)
{
    for (int i = 0; b[i] != '\0'; i++) {
        for (int j = 0; ops[j] != '\0'; j++) {
            if (b[i] == ops[j] || my_strlen(b) < 2) {
                my_putstr(SYNTAX_ERROR_MSG);
                exit(EXIT_BASE);
            }
        }
    }
    for (int i = 0; b[i] != '\0'; i++) {
        for (int j = 0; b[j] != '\0'; j++) {
            if (b[i] == b[j] && i > j) {
                my_putstr(SYNTAX_ERROR_MSG);
                exit(EXIT_BASE);
            }
        }
    }
    check_ops(ops, expr, b);
}

int main(int ac, char **av)
{
    unsigned int size;
    char *expr;

    if (ac == 2 && my_strcmp(av[1], "-h") == 0) {
        print_help();
        return (EXIT_SUCCESS);
    }
    if (ac != 4) {
        my_putstr("Usage: ");
        my_putstr(av[0]);
        my_putstr(" base ops\"()+_*/%\" exp_len\n");
        return (EXIT_USAGE);
    }
    size = my_atoi(av[3]);
    expr = get_expr(size);
    check_errors(av[1], av[2], expr);
    my_putstr(eval_expr(av[1], av[2], expr, size));
    return (EXIT_SUCCESS);
}