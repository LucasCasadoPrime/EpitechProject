#include <unistd.h>

int my_putchar(char c)
{
    write(1, &c, 1);
    return 0;
}

int my_print_alpha(void)
{
    char c = 'a';
    while (c <= 'z')
    {
        my_putchar(c);
        c++;
    }
    return 0;
}

int main(void)
{
    my_print_alpha();
    return 0;
}