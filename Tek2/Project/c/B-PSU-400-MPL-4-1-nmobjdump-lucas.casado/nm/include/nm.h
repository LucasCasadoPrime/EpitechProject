/*
** EPITECH PROJECT, 2022
** B-PSU-400-MPL-4-1-nmobjdump-lucas.casado
** File description:
** nm
*/

#ifndef NM_H_
#define NM_H_

    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <ctype.h>
    #include <fcntl.h>
    #include <stdio.h>
    #include <unistd.h>
    #include <elf.h>
    #include <sys/mman.h>
    #include <sys/stat.h>

    typedef struct symlist_s
    {
        Elf64_Sym *sym;
        Elf64_Shdr *shdr;
        char *name;
        struct symlist_s *next;
    } symlist_t;

    Elf64_Ehdr *file_checker(char const *filename);
    Elf64_Ehdr *is_elf(Elf64_Ehdr *elf);
    symlist_t *my_nm(Elf64_Ehdr *elf, symlist_t *);
    char find_type(Elf64_Sym sym, Elf64_Shdr *shdr, Elf64_Ehdr *elf);
    void pdump(symlist_t *list, Elf64_Ehdr *elf);
    symlist_t *sort_sym(symlist_t *);

#endif