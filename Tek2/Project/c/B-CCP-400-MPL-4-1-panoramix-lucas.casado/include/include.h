/*
** EPITECH PROJECT, 2022
** B-CCP-400-MPL-4-1-panoramix-lucas.casado
** File description:
** include
*/

#ifndef INCLUDE_H_
#define INCLUDE_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <stdbool.h>
#include <semaphore.h>

#define isCompatible(x, type) _Generic(x, type: true, default: false)

typedef struct panoramix_s
{
    int pot_s;
    int nb_v;
    int refill;
    int fight;
} panoramix_t;

typedef struct pot_s
{
    pthread_mutex_t mutex;
    sem_t sem_vil;
    sem_t sem_druid;
    int remp;
    int re;
} pot_t;

typedef struct vil_s
{
    pthread_t v;
    int kombat;
    int id;
} vil_t;

void *villagers(vil_t *vil);
vil_t *init_villager(panoramix_t *panoramix, int i);
int error_input(int ac, char **av);
void config_value(panoramix_t *panoramix, char **av);
void config_villagers(panoramix_t *panoramix);
pot_t *init_pot(panoramix_t *panoramix);

#endif /* !INCLUDE_H_ */
