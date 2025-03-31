/*
** EPITECH PROJECT, 2022
** B-PDG-300-MPL-3-1-PDGD04am-lucas.casado
** File description:
** print
*/

#include "print.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void print_normal (const char *str)
{
    printf("%s\n", str);
}

void print_reverse (const char *str)
{
    for (int i = strlen(str); i != -1 ; i--)
        putchar(str[i]);
    printf("\n");
}

void print_upper (const char *str)
{
    for (int i = 0; str[i] ; i++){
        if (str[i] >= 97 && str[i] <= 122){
            putchar(str[i]-32);
        } else {
            putchar(str[i]);
        }
    }
    printf("\n");
}

void print_42 (const char *str)
{
    str = "";
    printf("%s", "42");
}

typedef struct p_s
{
    action_t act;
    void (*ptr)(const char *);
}array_t;

static array_t pointer[] = {
    {PRINT_NORMAL, print_normal},
    {PRINT_REVERSE, print_reverse},
    {PRINT_UPPER, print_upper},
    {PRINT_42, print_42},
};

void do_action(action_t action, const char *str)
{
    for (int i = 0; i != 4; i += 1) {
        if (action == pointer[i].act)
            pointer[i].ptr(str);
    }
}