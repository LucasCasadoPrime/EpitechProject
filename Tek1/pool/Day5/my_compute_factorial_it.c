int my_compute_factorial_it(int nb)
{
    int result = 1;
    if (nb < 0 || nb > 12)
        return 0;
    for (int i = 1; i <= nb; i++)
        result *= i;
    return result;
}

int main(void)
{
    my_compute_factorial_it(5);
    return 0;
}