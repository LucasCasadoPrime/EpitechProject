#include <unistd.h>

int my_putchar(char c)
{
    write(1, &c, 1);
    return 0;
}

int my_print_comb(void)
{
    for (int a = 0; a < 10; ++a)
    {
        for (int b = a + 1; b < 10; ++b)
        {
            for (int c = b + 1; c < 10; ++c)
            {

                my_putchar(48 + a);
                my_putchar(48 + b);
                my_putchar(48 + c);
                if (a != 7)
                {
                    my_putchar(',');
                    my_putchar(' ');
                }
            }
        }
    }
    return 0;
}

int main(void)
{
    my_print_comb();
    return 0;
}