/*
** EPITECH PROJECT, 2020
** pong
** File description:
** printf things
*/

#include "pong.h"
#include <stdio.h>
#include <stdlib.h>

void print_help(void)
{
    printf("USAGE\n    ./101pong x0 y0 z0 x1 y1 z1 n\n\n\n");
    printf("DESCRIPTION\n    x0  ball abscissa at time  t - 1\n");
    printf("    y0  ball ordinate at time  t - 1\n");
    printf("    z0  ball altitude at time  t - 1\n");
    printf("    x1  ball abscissa at time t\n");
    printf("    y1  ball ordinate at time t\n");
    printf("    z1  ball altitude at time t\n");
    printf("    n   time shift (greater than or equal to zero, integer)\n");
    exit (84);
}

void print_velocity_vector(vectors_t vectors)
{
    printf("%s", "The velocity vector of the ball is:\n(");
    printf("%0.2f", vectors.velocity_vector_x);
    printf("%s", ", ");
    printf("%0.2f", vectors.velocity_vector_y);
    printf("%s", " ,");
    printf("%0.2f", vectors.velocity_vector_z);
    printf("%s", ")\n");
}

void print_final_vector(vectors_t vectors)
{
    printf("%s", "At time t + 4, ball coordinates will be:\n(");
    printf("%0.2f", vectors.final_vector_x);
    printf("%s", ", ");
    printf("%0.2f", vectors.final_vector_y);
    printf("%s", " ,");
    printf("%0.2f", vectors.final_vector_z);
    printf("%s", ")\n");
}