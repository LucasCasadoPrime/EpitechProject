/*
** EPITECH PROJECT, 2020
** B-PSU-100-MPL-1-1-myprintf-lucas.casado
** File description:
** put_all
*/

#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "my.h"

typedef struct funct_s
{
    char c;
    void (*ptr)(va_list);
}funct_t;

void put_char(va_list ap)
{
    char letter;
    letter = va_arg(ap, int);
    my_putchar(letter);
}
void put_nbr(va_list ap)
{
    int nbr;
    nbr = va_arg(ap, int);
    my_put_nbr(nbr);
}   
void put_str(va_list ap)
{
    char *string;
    string = va_arg(ap, char *);
    my_putstr(string);
} 

void put_octal(va_list ap)
{
    int nbr;
    nbr = va_arg(ap, int);
    my_put_octadecimal(nbr);
}
void put_a_short(va_list ap)
{
    short nbr;
    nbr = va_arg(ap, int);
    my_put_a_short(nbr);
}
void put_bin(va_list ap)
{
    int nbr;
    nbr = va_arg(ap, int);
    my_put_bin(nbr);
}
void put_hexa(va_list ap)
{
    int nbr;
    nbr = va_arg(ap, int);
    my_put_hexadecimal(nbr);
}
void put_unnbr(va_list ap)
{
    int nbr;
    nbr = va_arg(ap, int);
    my_put_unnbr(nbr);
}   
void put_hexamaj(va_list ap)
{
    int nbr;
    nbr = va_arg(ap, int);
    my_put_hexadecimalmaj(nbr);
}