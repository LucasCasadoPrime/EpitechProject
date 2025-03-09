#include <unistd.h>

int my_putchar(char c)
{
    write(1, &c, 1);
    return 0;
}

int my_print_digits(void)
{
    for (int i = 48; i <= 57; i++)
        my_putchar(i);
    return 0;
}

int main(void)
{
    my_print_digits();
    return 0;
}