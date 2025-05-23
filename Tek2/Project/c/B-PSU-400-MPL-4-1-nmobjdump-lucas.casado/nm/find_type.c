/*
** EPITECH PROJECT, 2018
** nm objdump
** File description:
** nm
*/

#include "nm.h"

char is_local(char c, Elf64_Sym sym)
{
    if (ELF64_ST_BIND(sym.st_info) == STB_LOCAL && c != '?')
        c += 32;
    return (c);
}

char common_type(char c, Elf64_Sym sym, Elf64_Shdr *shdr, \
Elf64_Ehdr *elf)
{
    if (shdr[sym.st_shndx].sh_type == SHT_PROGBITS && \
    shdr[sym.st_shndx].sh_flags == (SHF_ALLOC | SHF_WRITE))
        c = 'D';
    else if (shdr[sym.st_shndx].sh_type == SHT_PROGBITS && \
    shdr[sym.st_shndx].sh_flags == (SHF_ALLOC | SHF_EXECINSTR))
        c = 'T';
    else {
        if (!shdr->sh_type && elf->e_type == ET_REL)
            c = 'N';
        else
            c = 'T';
    }
    return (is_local(c, sym));
}

char undef_type(char c, Elf64_Sym sym, Elf64_Shdr *shdr, Elf64_Ehdr *elf)
{
    if (ELF64_ST_BIND(sym.st_info) == STB_WEAK && \
    ELF64_ST_TYPE(sym.st_info) == STT_OBJECT) {
        c = 'V';
        if (sym.st_shndx == SHN_UNDEF)
            c = 'v';
    }
    else if (sym.st_shndx == SHN_UNDEF)
        c = 'U';
    else {
        if (shdr[sym.st_shndx].sh_type == SHT_NOBITS && \
        shdr[sym.st_shndx].sh_flags == (SHF_ALLOC | SHF_WRITE))
            c = 'B';
        else if (shdr[sym.st_shndx].sh_type == SHT_PROGBITS && \
        shdr[sym.st_shndx].sh_flags == SHF_ALLOC)
            c = 'R';
        else
            return (common_type(c, sym, shdr, elf));
    }
    return (is_local(c, sym));
}

char find_type(Elf64_Sym sym, Elf64_Shdr *shdr, Elf64_Ehdr *elf)
{
    char c = 0;

    if (ELF64_ST_BIND(sym.st_info) == STB_GNU_UNIQUE)
        c = 'u';
    else if (ELF64_ST_BIND(sym.st_info) == STB_WEAK) {
        c = 'W';
        if (sym.st_shndx == SHN_UNDEF)
            c = 'w';
    }
    else {
        if (sym.st_shndx == SHN_ABS)
            c = 'A';
        else if (sym.st_shndx == SHN_COMMON)
            c = 'C';
        else
            return (undef_type(c, sym, shdr, elf));
    }
    return (is_local(c, sym));
}