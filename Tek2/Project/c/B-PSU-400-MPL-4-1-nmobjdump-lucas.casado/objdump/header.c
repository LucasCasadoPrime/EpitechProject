/*
** EPITECH PROJECT, 2018
** OBJDUMP
** File description:
** Print Headers
*/

#include "objdump.h"

void pflags(unsigned int flags)
{
    uint16_t tab[8] = {NO_FLAGS, HAS_RELOC, EXEC_P, HAS_DEBUG, HAS_SYMS, \
            HAS_LOCALS, DYNAMIC, D_PAGED};
    char tags[8][10] = {"NO_FLAGS", "HAS_RELOC", "EXEC_P", "HAS_DEBUG", \
    "HAS_SYMS", "HAS_LOCALS", "DYNAMIC", "D_PAGED"};
    int first = 0;

    for (int i = 0; i < 8; i++) {
        if (flags & tab[i]) {
            printf("%s%s", first ? ", " : "", tags[i]);
            first++;
            flags -= tab[i];
        }
    }
    printf("\n");
}

unsigned int has_syms(Elf64_Ehdr *elf)
{
    Elf64_Shdr *head = (Elf64_Shdr *) ((char *)elf + elf->e_shoff);

    for (int i = 0; i < elf->e_shnum; i++) {
        if (head[i].sh_type == SHT_SYMTAB)
            return (HAS_SYMS);
    }
    return (0);
}

int is_tab(const char *section)
{
    char tab[4][10] = {".bss", ".shstrtab", ".symtab", ".strtab"};

    for (int i = 0; i < 5; i++)
        if (!section || !strcmp(tab[i], section))
            return (0);
    return (1);
}

void phexa(unsigned int i)
{
    while (i % 16) {
        printf("  ");
        i += 1;
        if (!(i % 4))
            printf(" ");
        if (!(i % 16))
            printf(" ");
    }
}