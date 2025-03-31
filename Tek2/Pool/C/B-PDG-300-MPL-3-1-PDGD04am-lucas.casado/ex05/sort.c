/*
** EPITECH PROJECT, 2022
** B-PDG-300-MPL-3-1-PDGD04am-lucas.casado
** File description:
** sort
*/

#include <stddef.h>
#include <stdio.h>

void sort_int_array (int *array, size_t nmemb)
{
    int temp = 0;
    for (int i = 0; i < nmemb; i++) {
        for (int j = 0;j < nmemb; j++) {
            if (array[i] < array[j]){
                temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }
}