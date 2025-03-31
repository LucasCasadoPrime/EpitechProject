/*
** EPITECH PROJECT, 2020
** my.h
** File description:
** include all folders
*/
#include <stdio.h>
#include <stdlib.h>

void my_putchar(char c);

int my_putstr(char const *str);

int my_strlen(char const *str);

int my_strcmp(char const *s1, char const *s2);

int my_strncmp(char const *s1, char const *s2, int n);

char *my_strstr(char *str, char const *to_find);

char *my_strcat(char *s1, char *s2);

char *my_revstr(char *str);

int my_getnbr(char const *str);

int my_put_nbr(int nb);
