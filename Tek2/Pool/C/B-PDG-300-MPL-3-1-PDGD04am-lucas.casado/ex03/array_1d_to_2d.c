/*
** EPITECH PROJECT, 2022
** B-PDG-300-MPL-3-1-PDGD04am-lucas.casado
** File description:
** array_1d_to_2d
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void array_1d_to_2d (const int *array,size_t height,size_t width,int ***res) 
{
    *res = malloc(sizeof(int *) * (height + 1));
    
    for (int a = 0; a <= height; a++) {
        (*res)[a] = malloc(sizeof(int) * (width + 1));
        for (int b = 0; b <= width; b++)
            (*res)[a][b] = array[a * width + b];
    }
}

void array_2d_free (int ** array, size_t height, size_t width) 
{
    free(array);
}