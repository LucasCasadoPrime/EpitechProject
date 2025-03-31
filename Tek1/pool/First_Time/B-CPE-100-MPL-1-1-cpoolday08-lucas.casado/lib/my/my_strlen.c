/*
** EPITECH PROJECT, 2020
** my_sterlen
** File description:
** print numbers of char
*/

void my_putchar (char);

int my_strlen (char const *str)   
{
    int i = 0;
    for (i = 0; str[i]; i++);    
    return (i);
}
