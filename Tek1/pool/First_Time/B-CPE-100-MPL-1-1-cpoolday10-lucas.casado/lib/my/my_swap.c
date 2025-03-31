/*
** EPITECH PROJECT, 2020
** my_swap
** File description:
** swap two integers
*/

void my_putchar(char c);

void my_swap(int *a , int *b)
{
    int c;
    c = *a;
    *a = *b;
    *b = c;

    return (0);       
}    
