/*
** EPITECH PROJECT, 2021
** LibMy
** File description:
** my_memset
*/

void *my_memset(void *ptr, int c, int n)
{
    char *tmp = ptr;

    for (int i = 0; i < n; i++)
        tmp[i] = c;
    return (tmp);
}