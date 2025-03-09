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

int my_strlen(char const *str)
{
    int len = 0;
    while (str[len] != '\0')
        len++;
    return len;
}

char *my_evil_str(char *str)
{
    int len = my_strlen(str);
    for (int i = 0; i < len / 2; i++)
    {
        char tmp = str[i];
        str[i] = str[len - 1 - i];
        str[len - 1 - i] = tmp;
    }
    return str;
}

int main(void)
{
    char str[] = "abcd";
    my_putstr(my_evil_str(str));
    return 0;
}