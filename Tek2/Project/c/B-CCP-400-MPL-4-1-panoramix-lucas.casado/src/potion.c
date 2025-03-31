/*
** EPITECH PROJECT, 2022
** B-CCP-400-MPL-4-1-panoramix-lucas.casado
** File description:
** potion
*/

#include "../include/include.h"

pot_t *init_pot(panoramix_t *panoramix)
{
    pot_t *potiop = malloc(sizeof(pot_t));
    sem_init(&potiop->sem_druid, 0, 0);
    sem_init(&potiop->sem_vil, 0, 0);
    pthread_mutex_init(&potiop->mutex, NULL);
    potiop->remp = panoramix->pot_s;
    potiop->re = panoramix->refill;

    return (potiop);
}
