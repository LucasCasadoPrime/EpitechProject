/*
** EPITECH PROJECT, 2020
** B-PSU-100-MPL-1-1-myprintf-lucas.casado
** File description:
** my_put_hexadecimalmaj
*/

#include <unistd.h>
#include "my.h"

int my_put_hexadecimalmaj(int nbr)
{
    int div;
    int rest;
    int u = 0;
    int v = 0;
    char hexa[100];
    div = nbr;
    while(div != 0) {
        rest = div % 16;
        if (rest < 10)
            hexa[v++] = 48 + rest;
        else
            hexa[v++] = 87 + rest;
        div = div / 16;
    }
    for (u = v; u >= 0; u--) {
        my_putchar(hexa[u]);
    }
    return 0;
}