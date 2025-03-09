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

int is_number(char c)
{
    return (c >= '0' && c <= '9') ? 1 : 0;
}

int my_getnbr(char const *str)
{
    int res = 0;
    int sign = 1;
    int i = 0;

    while (str[i] == '-' || str[i] == '+')
    {
        sign *= -1;
        i++;
    }

    while (is_number(str[i]) == 1)
    {
        res = res * 10 + (str[i] - '0');
        i++;
    }

    res *= sign;

    if (res < -2147483648 || res > 2147483647)
        return 84;

    my_putnbr(res);
    return res;
}

int main(void)
{
    if (my_getnbr("-----+-34") == 84)
        return 84;
    return 0;
}
