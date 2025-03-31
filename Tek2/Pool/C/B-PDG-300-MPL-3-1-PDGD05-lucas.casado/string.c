/*
** EPITECH PROJECT, 2022
** B-PDG-300-MPL-3-1-PDGD05-lucas.casado
** File description:
** string
*/

#include "string.h"

void string_init(string_t *this, const char *s)
{
    this->str = malloc(sizeof(char) * (strlen(s) + 1));
    this->str[strlen(s)] = '\0';
    this->str = strcpy(this->str, s);
    return;
}

void string_destroy(string_t *this)
{
    free(this->str);
    this->str = NULL;
    return;
}

void assign_s (string_t *this, const string_t *str)
{
    (void) str;
    (void) this;
}

void assign_c (string_t *this, const char *s)
{
    (void) this;
    (void) s;
}

void append_s (string_t *this, const string_t *ap)
{
    (void) this;
    (void) ap;
}

void append_c (string_t *this, const char *ap)
{
    (void) this;
    (void) ap;
}