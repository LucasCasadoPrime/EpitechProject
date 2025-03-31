/*
** EPITECH PROJECT, 2020
** my_putstr
** File description:
** display one bye one charac of a string
*/

void my_putchar(char);

int my_strlen(char const *str)
{
    int i = 0;

    for (i = 0; str[i] != '\0'; i++);
    return (i);
}
