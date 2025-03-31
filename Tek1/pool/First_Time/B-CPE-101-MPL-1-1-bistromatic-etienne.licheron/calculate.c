/*
** EPITECH PROJECT, 2020
** BistroMatic
** File description:
** calculate
*/

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

char **my_str_to_word_array(char const *str);

char *do_calc(char *expr_one, char *expr_two, char *op);

typedef struct node_s {
    char *value;
    struct node_s *prev;
    struct node_s *next;
} node_t;

typedef node_t *list_t;

void add_elem(list_t *my_list, char *value)
{
    list_t start = *my_list;
    node_t *new = malloc(sizeof(node_t));
    new->value = value;
    new->next = NULL;
    new->prev = NULL;
    if (*my_list == NULL)
        *my_list = new;
    else {
        for (start = *my_list; start->next != NULL; start = start->next);
        new->prev = start;
        start->next = new;
    }
}

void create_elems(list_t *my_list, char **values)
{
    for (int i = 0; values[i] != NULL; i++)
        add_elem(my_list, values[i]);
}

int is_value_ops(char value)
{
    if (value == 43)
        return (1);
    if (value == 45)
        return (1);
    if (value == 42)
        return (1);
    if (value == 47)
        return (1);
    if (value == 37)
        return (1);
    return (0);
}

void do_it(list_t tmp)
{
    char *op = tmp->value;
    char *expr_one = tmp->prev->prev->value;
    char *expr_two = tmp->prev->value;
    char *result;

    result = do_calc(expr_one, expr_two, op);
    tmp->prev->prev->value = result;
    tmp->prev->prev->next = tmp->next;
    if (tmp->next != NULL)
        tmp->next->prev = tmp->prev->prev;
}

char *calculate(char *npi)
{
    char **new_npi;
    list_t tmp;
    list_t my_list = NULL;
    char *result;

    new_npi = my_str_to_word_array(npi);
    create_elems(&my_list, new_npi);
    for (tmp = my_list; tmp != NULL; tmp = tmp->next) {
        if (is_value_ops(tmp->value[0]) == 1) {
            do_it(tmp);
            tmp = my_list;
        }
    }
    for (tmp = my_list; tmp->next != NULL; tmp = tmp->next);
    result = tmp->value;
    return (result);
}