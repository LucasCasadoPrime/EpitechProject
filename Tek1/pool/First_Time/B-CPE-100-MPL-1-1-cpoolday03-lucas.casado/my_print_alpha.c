/*
** EPITECH PROJECT, 2020
** my_print_alpha
** File description:
** print alphabet
*/
  
int my_putchar(char c);

int my_print_alpha(void)
{
    int i;
    i = 97;
    while (i <= 122) {
            my_putchar(i);
            i = i + 1;
    }
    return (0);
}

    
    
