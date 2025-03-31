/*
** EPITECH PROJECT, 2020
** lib
** File description:
** my_str_isupper
*/
void my_putchar(char c);
int my_put_nbr(int nb);

int my_isupper(char const *str)
{
    int i = 0;
    while (str[i] != '\0') {
        if (str[i] >= 97 && str[i] <= 122) {
            i++;
        } else {
            return (0);
        }
    }
    return (1);
}
