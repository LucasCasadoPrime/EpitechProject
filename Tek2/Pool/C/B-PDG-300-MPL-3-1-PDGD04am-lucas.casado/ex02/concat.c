/*
** EPITECH PROJECT, 2022
** B-PDG-300-MPL-3-1-PDGD04am-lucas.casado
** File description:
** concat
*/

#include <string.h>
#include <stdlib.h>
#include "concat.h"

void concat_strings (const char *str1, const char *str2, char **res)
{
    *res = malloc(sizeof(char) * (strlen(str1) + (strlen(str2) + 1)));
    strcpy(*res, str1);
    strcat(*res, str2);
}

void concat_struct (concat_t * str)
{
    concat_strings(str->str1, str->str2, &str->res);
}