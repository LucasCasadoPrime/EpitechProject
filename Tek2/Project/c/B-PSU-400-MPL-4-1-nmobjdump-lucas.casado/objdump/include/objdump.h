/*
** EPITECH PROJECT, 2018
** nm
** File description:
** nm
*/

#ifndef DUMP_H_
#define DUMP_H_

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
    #include <stdbool.h>

    #define NO_FLAGS (0x0000)
    #define DYNAMIC (0x0040)
    #define HAS_LOCALS (0x0020)
    #define EXEC_P (0x0002)
    #define HAS_RELOC (0x0001)
    #define HAS_DEBUG (0x0008)
    #define D_PAGED (0x0100)
    #define HAS_SYMS (0x0010)

    void objdump(Elf64_Ehdr *, const char *file);
    void pheader(const char *file, Elf64_Ehdr *elf);
    void phexa_char(Elf64_Ehdr *elf, Elf64_Shdr shdr, unsigned int i);
    void pchar(Elf64_Ehdr *elf, Elf64_Shdr shdr, unsigned int i);
    void phexa(unsigned int i);
    void psection(unsigned int i);
    unsigned int gflags(Elf64_Ehdr *elf);
    void pheader(const char *file, Elf64_Ehdr *elf);
    void pflags(unsigned int flags);
    unsigned int has_syms(Elf64_Ehdr *elf);
    int is_tab(const char *section);
    void phexa(unsigned int i);
    void pnumeric_val(Elf64_Ehdr *elf, Elf64_Shdr shdr, unsigned int i);
    Elf64_Ehdr *file_checker(char const *filename);
    void dump_section(Elf64_Ehdr *elf, Elf64_Shdr shdr);
    Elf64_Ehdr *is_elf(Elf64_Ehdr *elf);
    void psection(unsigned int i);
    void pchar(Elf64_Ehdr *elf, Elf64_Shdr shdr, unsigned int i);
    void phexa_char(Elf64_Ehdr *elf, Elf64_Shdr shdr, unsigned int i);

#endif