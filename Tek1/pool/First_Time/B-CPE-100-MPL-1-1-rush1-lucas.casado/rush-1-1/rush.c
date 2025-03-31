/*
** EPITECH PROJECT, 2020
** Rush-1-1
** File description:
** Program rush-1-1
*/

void my_putchar(char);

void my_putstr(char const *str)
{
    for (int i = 0; str[i]; i++)
        my_putchar(str[i]);
}

void rush_print(int j, int x, char c[])
{
    if (j == 1)
        my_putchar(c[0]);
    else if (j == x)
        my_putchar(c[1]);
    else
        my_putchar(c[2]);
}

void rush_set_char(char *array, char firstChar, char lastChar, char midChar)
{
    array[0] = firstChar;
    array[1] = lastChar;
    array[2] = midChar;
}

void rush_check(int i, int y, int j, int x)
{
    char c[3];
    
    if (i == 1) {
        rush_set_char(c, 'o', 'o', '-');
        rush_print(j, x, c);
    } else if (i == y) {
        rush_set_char(c, 'o', 'o', '-');
        rush_print(j, x, c);
    } else {
        rush_set_char(c, '|', '|', ' ');
        rush_print(j, x, c);
    }    
}

void rush(int x, int y)
{
    if (x <= 0 || y <= 0) {
        my_putstr("Invalid size\n");
        return;
    }
    for (int i = 1; i <= y; i++) {
        for (int j = 1; j <= x; j++) {
            rush_check(i, y , j, x);
        }
        my_putchar('\n');
    }
}
