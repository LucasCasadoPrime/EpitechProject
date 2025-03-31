/*
** EPITECH PROJECT, 2020
** B-CPE-110-MPL-1-1-pushswap-lucas.casado
** File description:
** main
*/

#include "push_swap.h"

void sort(head *chain_a, head *chain_b)
{
    movement nb;
    nb.step = 0;
    for (int i = 1; i == 1;) {
        i = 0;
        for (; (*chain_a->first).next != NULL;) {
            if ((*chain_a->first).value > (*chain_a->first).next->value) {
                swap_list(chain_a, nb);
                nb.step ++;
                i = 1;
            }
            a_to_b(chain_a, chain_b, nb);
            nb.step ++;
        } 
        for (; (chain_b->first) != NULL;) {
            b_to_a(chain_b, chain_a);
            nb.step ++;
        }
    }
}

int main(int argc, char **argv)
{
    head *chain_a = init_head();
    head *chain_b = init_head();    
    for (int i = argc; i > 1; i--)
        push_front(chain_a, my_getnbr(argv[i - 1]));
    sort(chain_a, chain_b);
    my_putchar('\n');
    return (0);
}