/*
** EPITECH PROJECT, 2020
** my_print_revalpha
** File description:
** print revert alphabet
*/

int my_putchar(char c);

int my_print_revalpha(void)
{
    int i;
    i = 122;
    while (i >= 97) {
        my_putchar(i);
        i = i - 1;
    }
    return (0);
}
