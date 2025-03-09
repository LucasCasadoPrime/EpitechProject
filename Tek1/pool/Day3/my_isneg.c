#include <unistd.h>

int my_putchar(char c)
{
    write(1, &c, 1);
    return 0;
}

int my_isneg(int nbr)
{
    if (nbr >= 0)
    {
        my_putchar('P');
        return 0;
    }

    my_putchar('N');
    return -1;
}

int main(void)
{
    my_isneg(-1);
    my_isneg(1);
    return 0;
}