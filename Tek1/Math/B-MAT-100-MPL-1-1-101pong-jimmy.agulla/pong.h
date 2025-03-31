/*
** EPITECH PROJECT, 2020
** pong
** File description:
** pong.h
*/

#ifndef __PONG_H__
#define __PONG_H__

typedef struct values_s {
    double x0;
    double y0;
    double z0;
    double x1;
    double y1;
    double z1;
    double n;
    /*double hit_x;
    double hit_y;
    */
} values_t;

typedef struct vectors_s {
    double velocity_vector_x;
    double velocity_vector_y;
    double velocity_vector_z;
    double final_vector_x;
    double final_vector_y;
    double final_vector_z;
    double incidence_angle;
} vectors_t;

void print_final_vector(vectors_t vectors);

void print_velocity_vector(vectors_t vectors);

void error(int argc, char **argv);

void condition_invalid_arg(int argc, char **argv, int c, int v);

void error_invalid_arg(int argc, char **argv);

void error_time_shift(int argc, char **argv);

void get_incidence_angle(vectors_t *vectors);

void print_help(void);

void update_values(int argc, char **argv, values_t *values);

void update_vectors(vectors_t *vectors, values_t values);

#endif