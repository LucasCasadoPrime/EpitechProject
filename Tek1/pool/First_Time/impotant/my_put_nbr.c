/*
** EPITECH PROJECT, 2020
** Day03Task07
** File description:
** displays the number given as a parameter
*/

int absolute_n(int i);
void my_putchar(char);
int is_zero(int nb, int new);

int my_put_nbr(int nb)
{
    static int new = 1;
    int init = nb/10;
    int result = nb%10;

    if (is_zero(nb, new))
        return (0);
    new = 0;
    my_putchar(nb < 0 && !init ? 45 : 0);
    if (nb) {
        nb/=10;
        my_put_nbr(nb);
    }
    if (result) {
        my_putchar(absolute_n(result) + '0');
        new = 1;
        return (0);
    }
    my_putchar(init ? 48 : 0);
    new = 1;
    return (1);
}

int absolute_n(int i)
{
    return i >= 0 ? i : i *-1;
}

int is_zero(int nb, int new)
{
    if (nb == 0 && new) {
        my_putchar(48);
        return 1;
    }
    return 0;
}
