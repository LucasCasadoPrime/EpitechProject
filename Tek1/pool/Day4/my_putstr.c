#include <unistd.h>

int my_putchar(char c)
{
    write(1, &c, 1);
    return 0;
}

int my_putstr(char const *str)
{
    for (int i = 0; str[i]; ++i)
        my_putchar(str[i]);

    return 0;
}

int main(void)
{
    my_putstr("Salut les bogoss de la night");
}