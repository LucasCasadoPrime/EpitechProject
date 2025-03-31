/*
** EPITECH PROJECT, 2020
** Day04
** File description:
** Sort in  array ascending order
*/

int my_swap(int *a, int *b);

int check_change(int *array, int size)
{
    int c = 0;
    int *a;
    int *b;

    for (int i = 0 ; i < size - 1 ; i++) {
        a = &array[i];
        b = &array[i + 1];
        if (*a > *b) {
            my_swap(a, b);
            c++;
        }
    }
    return (c);
}

void my_sort_int_array(int *array, int size)
{
    int c = 1;

    while (c != 0) {
        c = check_change(array, size);
    }
}
