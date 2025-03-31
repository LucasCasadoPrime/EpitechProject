/*
** EPITECH PROJECT, 2022
** B-PDG-300-MPL-3-1-PDGD05-lucas.casado
** File description:
** string
*/


#ifndef STRING_H_
#define STRING_H_

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct string_s {
    char *str;
    void (*assign_s)(string_t *, const string_t *);
    void (*assign_c)(string_t *, const char *);
} string_t;

void string_init (string_t *this, const char *s);
void string_destroy (string_t *this);
void assign_s (string_t *this, const string_t *str);
void assign_c (string_t *this, const char *s);
void append_s (string_t *this, const string_t *ap);
void append_c (string_t *this, const char *ap);


#endif /* !STRING_H_ */
