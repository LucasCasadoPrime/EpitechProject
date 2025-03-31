/*
** EPITECH PROJECT, 2022
** B-PSU-400-MPL-4-1-nmobjdump-lucas.casado
** File description:
** main
*/

#include "objdump.h"

Elf64_Ehdr *is_elf(Elf64_Ehdr *elf)
{
    if (elf->e_ident[EI_MAG0] == 0x7f && elf->e_ident[EI_MAG1] == 'E' && \
    elf->e_ident[EI_MAG2] == 'L' && elf->e_ident[EI_MAG3] == 'F')
        return (elf);
    return (NULL);
}

Elf64_Ehdr *file_checker(char const *filename)
{
    void *buffer;
    int f;
    Elf64_Ehdr *elf;
    struct stat s;

    f = open(filename, O_RDONLY);
    if (f != -1) {
        fstat(f, &s);
        buffer = mmap(NULL, s.st_size, PROT_READ, MAP_PRIVATE, f, 0);
        close(f);
        if (buffer != (void *) -1) {
            elf = buffer;
            return (elf);
        }
    }
    return (NULL);
}

unsigned int gflags(Elf64_Ehdr *elf)
{
    unsigned int flags = NO_FLAGS;

    if (elf->e_type == ET_EXEC)
        flags += EXEC_P + D_PAGED;
    else if (elf->e_type == ET_DYN)
        flags += DYNAMIC + D_PAGED;
    else if (elf->e_type == ET_REL)
        flags += HAS_RELOC;
    flags += has_syms(elf);
    return (flags);
}

void pheader(const char *file, Elf64_Ehdr *elf)
{
    unsigned int flags = gflags(elf);

    printf("\n%s:     file format elf64-x86-64\n", file);
    printf("architecture: i386:x86-64, flags 0x%08x:\n", flags);
    pflags(flags);
    printf("start address 0x%016lx\n\n", elf->e_entry);
}

int main(int argc, char const * const *argv)
{
    char const *file;
    Elf64_Ehdr *elf;

    file = ((argc >= 2) ? (argv[1]) : ("a.out"));
    elf = file_checker(file);
    if (elf->e_ident[EI_CLASS] != 2)
        exit(0);
    if (!elf) {
        fprintf(stderr, "objdump: '%s': No such file\n", file);
        return (84);
    }
    elf = is_elf(elf);
    if (!elf) {
        fprintf(stderr, \
        "objdump: '%s': File format not recognized\n", file);
        return (84);
    }
    pheader(file, elf);
    objdump(elf, file);
    return (0);
}