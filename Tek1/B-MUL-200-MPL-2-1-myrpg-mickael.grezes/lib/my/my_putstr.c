/*
** EPITECH PROJECT, 2020
** my_putstr
** File description:
** display one bye one charac of a string
*/

void my_putchar(char);

int my_putstr(char const *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        my_putchar(str[i]);
    }
    return (0);
}
