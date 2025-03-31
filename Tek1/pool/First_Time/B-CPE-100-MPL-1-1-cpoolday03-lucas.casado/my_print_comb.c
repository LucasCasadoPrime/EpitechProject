/*
** EPITECH PROJECT, 2020
** my_print_comb
** File description:
** jsplol
*/

int my_putchar(char c);

int my_print_comb(void) {
    int nb = 12;
    int a;
    int b;
    int c;

    while (nb < 1000) {
        a = nb / 100 + 48;
        b = (nb / 100) %10 + 48;
        c = nb %10 + 48;
        if (a < b && b < c) {
            my_putchar(a);
            my_putchar(b);
            my_putchar(c);
            my_putchar(44);
            my_putchar(32);
        }
        nb = nb + 1;
    }
    my_putchar(8);
    my_putchar(8);
}
         
