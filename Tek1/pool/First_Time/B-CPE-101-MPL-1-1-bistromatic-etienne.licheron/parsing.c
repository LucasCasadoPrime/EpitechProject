/*
** EPITECH PROJECT, 2020
** EvalExpr
** File description:
** Parsing function
*/

#include <stdlib.h>

void push_result(char *result, char *to_push)
{
    int last = 0;
    int push_size = 0;
    int i = 0;

    for (; result[last] != '\0'; last++);
    for (; to_push[push_size] != '\0'; push_size++);
    for (; i < push_size; i++) {
        result[last + i] = to_push[i];
    }
    result[last + i] = 32;
}

void parse_expression(const char **expr, char *result);

void parse_term(const char **expr, char *result);

void parse_factor(const char **ptr, char *result);

char *parsing(char const *expr)
{
    char *result = malloc(sizeof(char) * 256);

    parse_expression(&expr, result);
    return (result);
}

void parse_factor(const char **ptr, char *result)
{
    char number[512];
    const char *expr = *ptr;
    int i = 0;

    if (**ptr == '(') {
        *ptr += 1;
        parse_expression(ptr, result);
        *ptr += 1;
    }
    else {
        while (expr[i] >= '0' && expr[i] <= '9') {
            number[i] = expr[i];
            i++;
        }
        number[i] = '\0';
        *ptr = expr + i;
        push_result(result, number);
    }
}

void parse_term(const char **expr, char *result)
{
    parse_factor(expr, result);
    if (**expr == '*') {
        *expr += 1;
        parse_term(expr, result);
        push_result(result, "*");
    }
    if (**expr == '/') {
        *expr += 1;
        parse_term(expr, result);
        push_result(result, "/");
    }
    if (**expr == '%') {
        *expr += 1;
        parse_term(expr, result);
        push_result(result, "%");
    }
}

void parse_expression(const char **expr, char *result)
{
    parse_term(expr, result);
    if (**expr == '+') {
        *expr += 1;
        parse_expression(expr, result);
        push_result(result, "+");
    }
    if (**expr == '-') {
        *expr += 1;
        parse_expression(expr, result);
        push_result(result, "-");
    }
}