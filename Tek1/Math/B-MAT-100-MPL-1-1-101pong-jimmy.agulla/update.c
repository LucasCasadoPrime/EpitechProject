/*
** EPITECH PROJECT, 2020
** pong
** File description:
** update structures
*/

#include "pong.h"
#include <stdlib.h>

void update_values(int argc, char **argv, values_t *values)
{
    values->x0 = atof(argv[1]);
    values->y0 = atof(argv[2]);
    values->z0 = atof(argv[3]);
    values->x1 = atof(argv[4]);
    values->y1 = atof(argv[5]);
    values->z1 = atof(argv[6]);
    values->n = atof(argv[7]);
}

void update_vectors(vectors_t *vectors, values_t values)
{
    vectors->velocity_vector_x = (values.x1 - values.x0);
    vectors->velocity_vector_y = (values.y1 - values.y0);
    vectors->velocity_vector_z = (values.z1 - values.z0);
}