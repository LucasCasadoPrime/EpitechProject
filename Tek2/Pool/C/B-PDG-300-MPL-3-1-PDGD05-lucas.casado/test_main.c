/*
** EPITECH PROJECT, 2022
** B-PDG-300-MPL-3-1-PDGD05-lucas.casado
** File description:
** test_main
*/

#include "string.h"
#include <string.h>

int main(void)
{
    string_t s ;
    string_init (&s,"HelloWorld");
    printf ("%s",s.str);
    string_destroy(&s);
    return(0);
}