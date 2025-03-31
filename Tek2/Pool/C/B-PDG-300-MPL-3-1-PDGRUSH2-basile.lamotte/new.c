/*
** EPITECH PROJECT, 2022
** B-PDG-300-MPL-3-1-PDGRUSH2-basile.lamotte
** File description:
** new
*/

#include "new.h"
#include "player.h"

Object *va_new(const Class *class, va_list *ap)
{
    Class *new = malloc(class->__size__);

    if (new == NULL) raise("Out of memory");
    memcpy(new, class, class->__size__);

    if (new->__ctor__) {
        new->__ctor__(new, ap);
    }
    return (new);
}

Object *new(const Class *class, ...)
{
    Class *new = NULL;
    va_list ap;
    va_start(ap, class);

    new = va_new(class, &ap);
    return (new);
}

void    delete(Object *ptr)
{
    if (((Class *)ptr) != NULL)
        ((Class *)ptr)->__dtor__(ptr);
    free(ptr);
}