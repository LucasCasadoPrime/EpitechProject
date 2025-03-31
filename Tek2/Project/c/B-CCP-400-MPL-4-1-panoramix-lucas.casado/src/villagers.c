/*
** EPITECH PROJECT, 2022
** B-CCP-400-MPL-4-1-panoramix-lucas.casado
** File description:
** villagers
*/

#include "../include/include.h"

static pot_t pot;

int error_input(int ac, char **av)
{
    if (ac != 5)
        return (84);
    for (int i = 0; i < ac;i++) {
        if (!isCompatible(atoi(av[i]), int))
            return (84);
    }
    return (0);
}

void config_value(panoramix_t *panoramix, char **av)
{
    panoramix->nb_v = atoi(av[1]);
    panoramix->pot_s = atoi(av[2]);
    panoramix->fight = atoi(av[3]);
    panoramix->refill = atoi(av[4]);
}

void config_villagers(panoramix_t *panoramix)
{
    vil_t *vil[panoramix->nb_v];

    for (int i = 0; i < panoramix->nb_v;i++){
        vil[i] = init_villager(panoramix, i);
        pthread_create(&vil[i]->v, NULL, villagers, (void *) vil[i]);
    }
    for (int i = 0; i < panoramix->nb_v;i++){
        pthread_join(vil[i]->v, NULL);
    }
}

vil_t *init_villager(panoramix_t *panoramix, int i)
{
    vil_t *new_villager = malloc(sizeof(vil_t));
    new_villager->id = i;
    new_villager->kombat = panoramix->fight;

    return (new_villager);
}
