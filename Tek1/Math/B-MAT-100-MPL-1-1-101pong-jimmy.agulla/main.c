/*
** EPITECH PROJECT, 2020
** pong
** File description:
** pong
*/

#include <stdio.h>
#include <stdlib.h>
#include "pong.h"
#include <math.h>

void get_incidence_angle(vectors_t *vectors)
{
    vectors->incidence_angle = asin(abs(vectors->velocity_vector_z) / \
    sqrt(pow(vectors->velocity_vector_x, 2) + pow(vectors->velocity_vector_y, 2) + \
    pow(vectors->velocity_vector_z, 2)));
    vectors->incidence_angle = (vectors->incidence_angle) * (180 / M_PI);
}

void pong(values_t values, vectors_t vectors)
{
    print_velocity_vector(vectors);
    vectors.final_vector_x = (vectors.velocity_vector_x * \
    (values.n + 1)) + values.x0;
    vectors.final_vector_y = (vectors.velocity_vector_y * \
    (values.n + 1)) + values.y0;
    vectors.final_vector_z = (vectors.velocity_vector_z * \
    (values.n + 1)) + values.z0;
    print_final_vector(vectors);
    if (vectors.final_vector_z <= 0 && values.z1 > 0) {
        get_incidence_angle(&vectors);
        printf("The incidence angle is:\n");
        printf("%0.2f", vectors.incidence_angle);
        printf(" degrees\n");
    }
    else
        printf("The ball won't reach the paddle\n");
}

int main(int argc, char **argv)
{
    values_t values;
    vectors_t vectors;

    error(argc, argv);
    update_values(argc, argv, &values);
    update_vectors(&vectors, values);
    pong(values, vectors);
    return (0);
}

