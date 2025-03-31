/*
** EPITECH PROJECT, 2022
** B-CCP-400-MPL-4-1-panoramix-lucas.casado
** File description:
** main
*/


#include "../include/include.h"

static pot_t *pot;
static int i;

void *druid()
{
    printf("Druid: I’m ready... but sleepy...\n");
    while (pot->re != 0) {
        sem_wait(&pot->sem_vil);
        printf("Druid: Ah!Yes, yes, I’m awake!Working on it!");
        printf("Beware I can only make %d more refills after this one.\n", \
            pot->re-1);
        pot->re--;
        pot->remp = i;
        sem_post(&pot->sem_druid);
    }
    printf("Druid: I’m out of viscum. I’m going back to... zZz\n");
}

void config_druid(void)
{
    pthread_t druidt;
    pthread_create(&druidt, NULL, druid, NULL);
}

void *villagers(vil_t *vil)
{
    int tmp = 0;

    tmp = pot->remp;
    printf("Villager %d: Going into battle!\n", vil->id);
    while (vil->kombat != 0){
        pthread_mutex_lock(&pot->mutex);
        if (pot->remp != 0) {
            printf("Villager %d: I need a drink ... ", vil->id);
            printf("I see %d servings left.\n", pot->remp-1);
            pot->remp--;
            printf("Villager %d: Take that roman scum!", vil->id);
            printf("Only %d left.\n", vil->kombat-1);
            vil->kombat--;
        } else {
            printf("Villager %d: Hey Pano wake up!We need more potion.\n", \
                vil->id);
            sem_post(&pot->sem_vil);
            sem_wait(&pot->sem_druid);
        }
        pthread_mutex_unlock(&pot->mutex);
    }
    printf("Villager %d: I'm going to sleep now.\n", vil->id);
}

int main(int ac, char **av)
{
    panoramix_t panoramix;
    if (error_input(ac, av) == 84)
        return (84);
    config_value(&panoramix, av);
    vil_t vil[panoramix.nb_v];
    pot = init_pot(&panoramix);
    i = panoramix.pot_s;
    config_druid();
    config_villagers(&panoramix);
    return (0);
}
