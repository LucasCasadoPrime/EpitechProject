/*
** EPITECH PROJECT, 2020
** architect
** File description:
** translation
*/

#include <stdio.h>
#include "struc.h"
#include <stdlib.h>
#include <math.h>

void print_result_rotate(coord_t coord, float m, main_matrice_t *ma)
{
    printf("Rotation by a %0.0f%s", m, " degree angle\n");
    printf("%.2f %.2f %.2f\n%.2f %.2f %.2f\n%.2f %.2f %.2f\n", \
    ma->i1, ma->i2, ma->i3, ma->j1, ma->j2, ma->j3, ma->k1, ma->k2, ma->k3);
    printf("(%.2f", coord.orix);
    printf(", %.2f", coord.oriy);
    printf(") => (%.2f", coord.resx);
    printf(", %.2f", coord.resy);
    printf(")\n");
}

void modify_ma_rotate(int m, main_matrice_t *ma)
{
    ma->i1 = cos(m);
    ma->i2 = -1 * sin(m);
    ma->j1 = sin(m);
    ma->j2 = cos(m);
}

int rotate(int argc, char **argv, main_matrice_t *ma)
{
    coord_t coord;
    float teta = atof(argv[4]);
    coord.orix = atof(argv[1]);
    coord.oriy = atof(argv[2]);
    coord.resx = 0;
    coord.resy = 0;
    float m = teta / 180;

    coord.resx = cos(m) * ma->i1 - sin(m) * ma->i2;
    coord.resy = sin(m) * coord.orix + cos(m) * coord.oriy;
    modify_ma_rotate(m, ma);
    print_result_rotate(coord, m, ma);
    return (0);
}