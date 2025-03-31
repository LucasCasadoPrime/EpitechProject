/*
** EPITECH PROJECT, 2020
** BistroMatic
** File description:
** eval_expr
*/

#include <stdio.h>
#include <stdlib.h>
#include "include/bistromatic.h"

int is_a_digit(char const c, char const *base);

int is_a_ops(char const c, char const *ops);

int my_strlen(char const *str);

int my_putstr(char const *str);

char *convert(const char *num, char const *from, const char *to);

char *parsing(char const *expr);

char *calculate(char *npi);

char **a_alloc(char *expr, char *base, char *ops)
{
    char **pre_array = malloc(sizeof(char) * my_strlen(expr) * 1000);
    char *tmp;
    int row = 0;
    int lengh = 0;

    for (int i = 0; expr[i] != '\0';) {
        if (is_a_digit(expr[i], base)) {
            for (int k = i; is_a_digit(expr[k], base) == 1 ; k++)
                lengh++;
            tmp = malloc(sizeof(char) * lengh);
            for (int j = 0; is_a_digit(expr[i], base) == 1 ; i++) {
                tmp[j] = expr[i];
                j++;
            }
            tmp[lengh] = '\0';
            lengh = my_strlen(convert(tmp, base, "0123456789"));
            pre_array[row] = malloc(sizeof(char) * lengh);
            pre_array[row] = convert(tmp, base, "0123456789");
        } else {
            for (int k = 0; ops[k] != '\0'; k++) {
                if (expr[i] == ops[k])
                    lengh = k;
            }
            pre_array[row] = malloc(sizeof(char) * 1);
            if (lengh == 0)
                pre_array[row] = "(";
            if (lengh == 1)
                pre_array[row] = ")";
            if (lengh == 2)
                pre_array[row] = "+";
            if (lengh == 3)
                pre_array[row] = "-";
            if (lengh == 4)
                pre_array[row] = "*";
            if (lengh == 5)
                pre_array[row] = "/";
            if (lengh == 6)
                pre_array[row] = "%";
            i++;
        }
        row++;
    }
    pre_array[row] = NULL;
    return (pre_array);
}

char *c_alloc(char **pre_array)
{
    int row = 0;
    int to_alloc = 0;
    char *clean;
    int k = 0;

    for (int i = 0; pre_array[i] != NULL; i++)
        row++;
    for (int i = 0; i < row; i++) {
        for (int j = 0; pre_array[i][j] != '\0'; j++)
            to_alloc++;
    }
    clean = malloc(sizeof(char) * to_alloc);
    for (int i = 0; i < row; i++) {
        for (int j = 0; pre_array[i][j] != '\0'; j++) {
            clean[k] = pre_array[i][j];
            k++;
        }
    }
    return (clean);
}

char *eval_expr(char *base, char *ops, \
                char *expr, unsigned int size)
{
    unsigned int i = 0;
    char *result = "0";
    char **pre_array;
    char *new_expr;

    for (; expr[i] != '\0'; i++);
    if (i == size) {
        pre_array = a_alloc(expr, base, ops);
        new_expr = c_alloc(pre_array);
        new_expr = parsing(new_expr);
        result = calculate(new_expr);
        return (result);
    }
    my_putstr(SYNTAX_ERROR_MSG);
    exit(EXIT_READ);
    return (SYNTAX_ERROR_MSG);
}