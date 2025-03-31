/*
** EPITECH PROJECT, 2022
** B-PSU-400-MPL-4-1-nmobjdump-lucas.casado
** File description:
** main
*/

#include "nm.h"

int my_strcoll(char *s1, char *s2)
{
    char *tmp1 = strdup(s1);
    char *tmp2 = strdup(s2);
    int j = 0;

    for (int i = 0; s1[i]; i++)
        if (isalpha(s1[i]))
            tmp1[j++] = tolower(s1[i]);
    tmp1[j] = '\0';
    j = 0;
    for (int i = 0; s2[i]; i++)
        if (isalpha(s2[i]))
            tmp2[j++] = tolower(s2[i]);
    tmp2[j] = '\0';
    j = strcoll(tmp1, tmp2);
    free(tmp1);
    free(tmp2);
    return (j);
}

symlist_t *sort_sym(symlist_t *l)
{
    symlist_t *tmp = l;
    char *tmp_name;
    Elf64_Sym *tmp_sym;

    while (tmp->next) {
        if (my_strcoll(tmp->name, tmp->next->name) > 0) {
            tmp_name = tmp->name;
            tmp_sym = tmp->sym;
            tmp->name = tmp->next->name;
            tmp->sym = tmp->next->sym;
            tmp->next->name = tmp_name;
            tmp->next->sym = tmp_sym;
            return (sort_sym(l));
        }
        tmp = tmp->next;
    }
    return (l);
}

int main(int ac, char const * const *av)
{
    char const *file = ((ac >= 2) ? (av[1]) : ("a.out"));
    Elf64_Ehdr *elf;
    symlist_t *list = NULL;

    elf = file_checker(file);
    if (elf->e_ident[EI_CLASS] != 2)
        exit(0);
    if (!elf) {
        fprintf(stderr, "nm: '%s': No such file\n", file);
        return (84);
    }
    elf = is_elf(elf);
    if (!elf) {
        fprintf(stderr, "nm: '%s': File format not recognized\n", \
        file);
        return (84);
    }
    list = sort_sym(my_nm(elf, list));
    pdump(list, elf);
    return (0);
}