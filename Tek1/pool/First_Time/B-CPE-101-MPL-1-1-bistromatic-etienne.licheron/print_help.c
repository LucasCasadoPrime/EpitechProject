/*
** EPITECH PROJECT, 2020
** print help
** File description:
** print help for bistro
*/

int my_putstr(char const *str);

int print_help(void)
{
    my_putstr("USAGE\n");
    my_putstr("./calc base operators size_read\n\n");
    my_putstr("DESCRIPTION\n");
    my_putstr("- base: all the symbols of the base\n");
    my_putstr("- operators: the symbols for ");
    my_putstr("the parentheses and the 5 operators\n");
    my_putstr("- size_read: number of characters to be read\n");
    return (0);
}