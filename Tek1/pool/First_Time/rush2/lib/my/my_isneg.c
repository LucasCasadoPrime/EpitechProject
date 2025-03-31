/*
** EPITECH PROJECT, 2020
** my_isneg
** File description:
** print N if parameter is negative or P is positive 
*/

int  my_putchar(char c);

int my_isneg(int n)
{
    if (n >= 0) {
        my_putchar('P');
    } else {
        my_putchar('N');
    }
}         
