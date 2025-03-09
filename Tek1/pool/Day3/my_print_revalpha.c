#include <unistd.h>

int my_putchar(char c)
{
    write(1, &c, 1);
    return 0;
}

int my_print_revalpha(void)
{
    char c = 'z';
    while (c >= 'a')
    {
        my_putchar(c);
        c--;
    }
    return 0;
}

int main(void)
{
    my_print_revalpha();
    return 0;
}