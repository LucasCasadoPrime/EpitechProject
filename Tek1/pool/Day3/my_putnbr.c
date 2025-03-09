#include <unistd.h>

int my_putchar(char c)
{
    write(1, &c, 1);
    return 0;
}

int my_putnbr(int n)
{
    unsigned int nb = n;

    if (n < 0)
    {
        my_putchar('-');
        nb = -n;
    }

    if (nb > 9)
    {
        my_putnbr(nb / 10);
        my_putnbr(nb % 10);
    }
    else
        my_putchar(nb + '0');
    return 0;
}

int main(void)
{
    my_putnbr(56);
    return 0;
}