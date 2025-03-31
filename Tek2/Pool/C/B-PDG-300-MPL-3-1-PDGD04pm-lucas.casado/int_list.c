/*
** EPITECH PROJECT, 2022
** B-PDG-300-MPL-3-1-PDGD04pm-lucas.casado
** File description:
** int_list
*/

#include "int_list.h"
#include <string.h>
#include <stdbool.h>


unsigned int int_list_get_size (int_list_t list)
{
    int count = 0;

    while (list!=NULL) {
        count++;
        list = list->next;
    }
    return(count);
}

bool int_list_is_empty (int_list_t list)
{
    if (list != NULL)
        return (true);
    else
        return (false);
}

void int_list_dump (int_list_t list) 
{
    while (list != NULL) {
        printf("%f", list->value);
        list = list->next;
    }
}
