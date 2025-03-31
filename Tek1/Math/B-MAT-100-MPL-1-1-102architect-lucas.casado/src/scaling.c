/*
** EPITECH PROJECT, 2020
** architect
** File description:
** scale
*/

#include <stdio.h>
#include "struc.h"
#include <stdlib.h>

void print_result_scaling(coord_t coord, float m, float n, main_matrice_t *ma)
{
    printf("Scaling by factors %.0f%s%.0f%c", m, " and ", n, '\n');
    printf("%.2f %.2f %.2f\n%.2f %.2f %.2f\n%.2f %.2f %.2f\n", \
    ma->i1, ma->i2, ma->i3, ma->j1, ma->j2, ma->j3, ma->k1, ma->k2, ma->k3);
    printf("(%.2f", coord.orix);
    printf(", %.2f", coord.oriy);
    printf(") => (%.2f", coord.resx);
    printf(", %.2f", coord.resy);
    printf(")\n");
}

void modify_ma_scale(float m, float n, main_matrice_t *ma)
{
    ma->i1 *= m;
    ma->j2 *= n;
}

int scale(int argc, char **argv, main_matrice_t *ma)
{
    coord_t coord;
    float m = atof(argv[4]);
    float n = atof(argv[5]);
    coord.orix = atof(argv[1]);
    coord.oriy = atof(argv[2]);
    coord.resx = 0;
    coord.resy = 0;

    coord.resx = coord.orix * m;
    coord.resy = coord.oriy * n;
    modify_ma_scale(m, n, ma);
    print_result_scaling(coord, m, n, ma);
    return (0);
}