/*
** EPITECH PROJECT, 2018
** nm / objdump
** File description:
** nm
*/

#include "objdump.h"

void pnumeric_val(Elf64_Ehdr *elf, Elf64_Shdr shdr, unsigned int i)
{
    while (i < shdr.sh_size) {
        phexa_char(elf, shdr, i);
        i++;
        if (!(i % 16)) {
            printf("  ");
            return ;
        }
        if (!(i % 4))
            printf(" ");
    }
    if (i >= shdr.sh_size && i % 16)
        phexa(i);
}

void dump_section(Elf64_Ehdr *elf, Elf64_Shdr shdr)
{
    unsigned int addr = shdr.sh_addr;
    unsigned int i = 0;

    while (i < shdr.sh_size) {
        if (!(i % 16)) {
            printf(" %04x ", addr);
            pnumeric_val(elf, shdr, i);
            addr += 16;
        }
        pchar(elf, shdr, i);
        i++;
        if (!(i % 16))
            printf("\n");
    }
    if (i >= shdr.sh_size && i % 16)
        psection(i);
}

void phexa_char(Elf64_Ehdr *elf, Elf64_Shdr shdr, unsigned int i)
{
        printf("%02x", (unsigned char) (((char *) elf) + shdr.sh_offset)[i]);
}

void pchar(Elf64_Ehdr *elf, Elf64_Shdr shdr, unsigned int i)
{
    char c = (unsigned char) (((char *) elf) + shdr.sh_offset)[i];

    if (isprint(c))
        printf("%c", c);
    else
        printf(".");
}

void psection(unsigned int i)
{
    while (i % 16) {
        printf(" ");
        i += 1;
    }
    printf("\n");
}