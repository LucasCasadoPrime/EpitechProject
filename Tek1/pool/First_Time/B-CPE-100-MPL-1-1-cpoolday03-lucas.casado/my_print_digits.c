/*
** EPITECH PROJECT, 2020
** my_print_digits
** File description:
** print number from 1 to 9
*/

int my_putchar(char c);

int my_print_digits(void)
{
    int i;
    i = 48;
    while (i <= 57) {
        my_putchar(i);
        i = i + 1;
    }
    return(0);
}
       
