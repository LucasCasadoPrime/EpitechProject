/*
** EPITECH PROJECT, 2020
** my_printf
** File description:
** c prog
*/

#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "my.h"

#define ARRAY_SIZE 10

typedef struct funct_s {
    char c;
    void (*function)(va_list);
} funct_t;

void put_char(va_list ap);
void put_nbr(va_list ap);
void put_str(va_list ap);
void put_octal(va_list ap);
void put_a_short(va_list ap);
void put_hexa(va_list ap);
void put_unnbr(va_list ap);
void put_hexamaj(va_list ap);

static funct_t func[] = {
{'c', put_char},
{'d', put_nbr},
{'i', put_nbr},
{'b', put_octal},
{'o', put_octal},
{'s', put_str},
{'u', put_unnbr},
{'h', put_a_short},
{'x', put_hexa},
{'X', put_hexamaj}
}; 

int my_printf(char *str, ...)
{
    va_list ap;

    va_start(ap, str);
    for (int i = 0; str[i]; i += 1) {
        if (str[i] == '%' && str[i+1] != '\0') {
            i += 1;
            for (int a = 0; a < ARRAY_SIZE; a += 1) {
                if (str[i] == func[a].c)
                    func[a].function(ap);
            }
            if (str[i] == '%') 
                my_putchar('%');
        } else {
            my_putchar(str[i]);
        }
    }
    va_end(ap);
    return (0);
}
