/*
** EPITECH PROJECT, 2020
** architect
** File description:
** header for structs
*/

#ifndef __STRUCT_H__
#define _STRUCT_H__

#include <unistd.h>

typedef struct main_matrice_s {
    float i1;
    float j1;
    float k1;
    float i2;
    float j2;
    float k2;
    float i3;
    float j3;
    float k3;
} main_matrice_t;

typedef struct coord_s {
    float orix;
    float oriy;
    float resx;
    float resy;
} coord_t;

typedef struct transfo_s {
    char param;
    int (*function)(int argc, char **argv, main_matrice_t *ma);
} transfo_t;

void print_help();
int scale(int argc, char **argv, main_matrice_t *ma);
int translation(int argc, char **argv, main_matrice_t *ma);
int rotate(int argc, char **argv, main_matrice_t *ma);

static transfo_t chose_func[] =
{
    {'z', scale},
    {'t', translation},
    {'r', rotate},
    {'0', NULL}
    // {'r'},
    // {'s'},
};


#endif