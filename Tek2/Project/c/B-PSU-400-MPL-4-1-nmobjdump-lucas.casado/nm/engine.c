/*
** EPITECH PROJECT, 2018
** nm / objdump
** File description:
** nm
*/

#include "nm.h"

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

void pdump(symlist_t *l, Elf64_Ehdr *elf)
{
    while (l) {
        if (l->sym->st_value)
            printf("%016lx ", l->sym->st_value);
        else
            printf("                 ");
        printf("%c %s\n", find_type(*(l->sym), l->shdr, \
        elf), l->name);
        l = l->next;
    }
}

symlist_t *symlist_add_elem(symlist_t *l, Elf64_Sym *sym, char *name, \
Elf64_Shdr *shdr)
{
    symlist_t *tmp = l;
    symlist_t *new = malloc(sizeof(symlist_t));

    if (name[0] < 33 || sym->st_info == STT_FILE)
        return (l);
    new->sym = sym;
    new->name = name;
    new->next = NULL;
    new->shdr = shdr;
    if (!l)
        l = new;
    else {
        while (tmp->next)
            tmp = tmp->next;
        tmp->next = new;
    }
    return (l);
}

symlist_t *my_nm(Elf64_Ehdr *elf, symlist_t *l)
{
    Elf64_Shdr *head = (Elf64_Shdr *) ((char *)elf + elf->e_shoff);
    Elf64_Shdr *stb;
    Elf64_Sym *sym;
    Elf64_Shdr *strtb;
    char *symptr;

    for (int i = 0; i < elf->e_shnum; i++) {
        if (head[i].sh_type == SHT_SYMTAB) {
            stb = &head[i];
            symptr = (char *)elf + (&head[i])->sh_offset;
            break;
        }
    }
    for (int j = 0; j < ((int)(stb->sh_size / stb->sh_entsize)); j++) {
        sym = &((Elf64_Sym *) symptr)[j];
        strtb = &head[stb->sh_link];
        l = symlist_add_elem(l, sym, \
        (char *)elf + strtb->sh_offset + sym->st_name, head);
    }
    return (l);
}