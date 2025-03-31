/*
** EPITECH PROJECT, 2022
** B-PDG-300-MPL-3-1-PDGD04am-lucas.casado
** File description:
** mul_div
*/

#include <stdio.h>

void mul_div_long ( int a, int b, int * mul, int * div )
{
    *mul = a * b;
    if (b == 0) {
        *div = 42;
    } else {
        *div = a / b;
    }
}

void mul_div_short ( int *a , int * b )
{
    int nb_a = *a;
    int nb_b = *b;

    *a = nb_a * nb_b;
    if (*b == 0) {
        *b = 42;
    } else {
        *b = nb_a / nb_b;
    }
}