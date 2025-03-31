/*
** EPITECH PROJECT, 2020
** lib
** File description:
** include
*/

#ifndef my_h
#define my_h

#include <dirent.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <time.h>

#define FARRAY_SIZE 2

typedef struct flag_s
{
    char c;
    int (*ptr)(char **str);
}flag_t;

int my_ls_a(char **str);
int my_ls(char **str);
int my_ls_l(char **str);

static flag_t flag[] = {
    {'a', my_ls_a},
    {'l', my_ls_l}
};

//lib
void my_putchar(char c);
int my_isneg(int nb);
int my_put_nbr(int nb);
void my_swap(int *a, int *b);
int my_putstr(char const *str);
int my_strlen(char const *str);
int my_getnbr(char const *str);
void my_sort_int_array(int *tab, int size);
int my_compute_power_rec(int nb, int power);
int my_compute_square_root(int nb);
int my_is_prime(int nb);
int my_find_prime_sup(int nb);
char *my_strcpy(char *dest, char const *src);
char *my_strncpy(char *dest, char const *src, int n);
char *my_revstr(char *str);
char *my_strstr(char *str, char const *to_find);
int my_strcmp(char const *s1, char const *s2);
int my_strncmp(char const *s1, char const *s2, int n);
char *my_strupcase(char *str);
char *my_strlowcase(char *str);
char *my_strcapitalize(char *str);
int my_str_isalpha(char const *str);
int my_str_isnum(char const *str);
int my_str_islower(char const *str);
int my_str_isupper(char const *str);
int my_str_isprintable(char const *str);
int my_showstr(char const *str);
int my_showmem(char const *str, int size);
char *my_strcat(char *dest, char const *src);
char *my_strncat(char *dest, char const *src, int nb);
void my_putchar (char);
int my_putstr (char const *str);
short my_put_unshort(short nb);
unsigned int my_put_unnbr(int nb);
int my_put_octadecimal(int nbr);
int my_put_nbr(int nb);
int my_put_bin(int nbr);
short my_put_a_short(short nb);
int my_put_hexadecimalmaj(int nbr);
int my_put_hexadecimal(int nbr);
int my_printf(char *str, ...);

#endif