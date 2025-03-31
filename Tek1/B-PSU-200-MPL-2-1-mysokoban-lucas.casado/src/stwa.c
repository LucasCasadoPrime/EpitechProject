/*
** EPITECH PROJECT, 2021
** B-PSU-200-MPL-2-1-mysokoban-lucas.casado
** File description:
** stwa
*/

#include "../include/include.h"

char *my_strncpy(char *dest, char *src, int n)
{
    int i = 0;

    while (src[i] != '\0' && i < n) {
        dest[i] = src[i];
        i = i + 1;
    }
    if (i == n) {
        dest[i] = '\0';
    }
    return dest;
}

int my_is_sep(const char c, const char *separator)
{
    int is_sep = 0;

    for (int j = 0; separator[j] != 0; j++) {
        if (c == separator[j]) {
            is_sep = 1;
            break;
        }
    }
    return (is_sep);
}

int get_nb_words(char *str, const char *separator)
{
    int is_sep = 0;
    int nb_words = 0;
    int nb_chars = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        is_sep = my_is_sep(str[i], separator);
        if (is_sep == 0)
            nb_chars += 1;
        if ((is_sep == 1 && nb_chars > 0) || (is_sep == 0 && str[i+1] == 0)) {
            nb_words += 1;
            nb_chars = 0;
        }
    }
    return (nb_words);
}

char **my_str_to_word_array(char *str, const char *separator)
{
    char **array = malloc(sizeof(char *) * (get_nb_words(str, separator) + 1));
    int is_sep = 0;
    int row = 0;
    int nb_chars = 0;
    int to = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        is_sep = my_is_sep(str[i], separator);
        nb_chars = (is_sep == 0) ? nb_chars + 1 : nb_chars;
        if ((is_sep == 1 && nb_chars > 0) || (is_sep == 0 && str[i+1] == 0)) {
            array[row] = malloc(sizeof(char) * nb_chars + 1);
            if (is_sep == 0)
                to = 1;
            array[row] = my_strncpy(array[row], &str[i-nb_chars+to], nb_chars);
            row++;
            nb_chars = 0;
        }
    }
    array[get_nb_words(str, separator)] = 0;
    return (array);
}