/*
** EPITECH PROJECT, 2021
** LibMy
** File description:
** dec_to_binary
*/

int dec_to_binary(unsigned int n)
{
    long binary = 0;
    int rem = 1;
    int tmp = 1;

    for (; n != 0; tmp *= 10) {
        rem = n % 2;
        n /= 2;
        binary += rem*tmp;
    }
    return (binary);
}