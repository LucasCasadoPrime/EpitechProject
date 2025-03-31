/*
** EPITECH PROJECT, 2022
** B-PSU-400-MPL-4-1-nmobjdump-lucas.casado
** File description:
** objdump
*/

#include "objdump.h"

bool prefix(const char *pre, const char *str)
{
    return (strncmp(pre, str, strlen(pre)) == 0);
}

bool suffix(const char* base, char* str)
{
    int blen = strlen(base);
    int slen = strlen(str);
    if (slen <= blen) {
        return (strcmp(base + blen - slen, str) == 0);
    }
    return false;
}

void conditions(Elf64_Ehdr *elf)
{
    Elf64_Shdr *head = (Elf64_Shdr *) ((char *)elf + elf->e_shoff);
    Elf64_Shdr *sh_strtab = &head[elf->e_shstrndx];
    const char * const sh_strtab_p = ((char *)elf + sh_strtab->sh_offset);

    for (int i = 0; i < elf->e_shnum; i++) {
        if (is_tab(sh_strtab_p + head[i].sh_name) \
        && head[i].sh_size != 0) {
            printf("Contents of section %s:\n",
            sh_strtab_p + head[i].sh_name);
            dump_section(elf, head[i]);
        }
    }
}

void condition(const char *namefile, Elf64_Ehdr *elf)
{
    Elf64_Shdr *head = (Elf64_Shdr *) ((char *)elf + elf->e_shoff);
    Elf64_Shdr *sh_strtab = &head[elf->e_shstrndx];
    const char * const sh_strtab_p = ((char *)elf + sh_strtab->sh_offset);

    if (suffix(namefile, ".o")) {
        for (int i = 0; i < elf->e_shnum; i++) {
            if (is_tab(sh_strtab_p + head[i].sh_name) &&  \
            prefix(".rela", sh_strtab_p + head[i].sh_name) == 0 && \
            prefix(".note.GNU", sh_strtab_p + head[i].sh_name) == 0 \
            && head[i].sh_size != 0) {
                printf("Contents of section %s:\n",
                sh_strtab_p + head[i].sh_name);
                dump_section(elf, head[i]);
            }
        }
    } else {
        conditions(elf);
    }
}

void objdump(Elf64_Ehdr *elf, const char *namefile)
{
    condition(namefile, elf);
}