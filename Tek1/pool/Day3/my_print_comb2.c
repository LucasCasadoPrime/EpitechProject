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
    {
        my_putchar(nb + '0');
    }
    return 0;
}

int my_print_comb2(void)
{
    for (int a = 0; a <= 98; ++a)
    {
        for (int b = a + 1; b <= 99; ++b)
        {
            if (a < 10)
                my_putchar('0');
            my_putnbr(a);
            my_putchar(' ');

            if (b < 10)
                my_putchar('0');
            my_putnbr(b);
            if (a != 98 || b != 99) // Évite la dernière virgule et l'espace
            {
                my_putchar(',');
                my_putchar(' ');
            }
        }
    }
    return 0;
}

int main(void)
{
    my_print_comb2();
    return 0;
}