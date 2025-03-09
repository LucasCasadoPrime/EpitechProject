int my_compute_power_it(int nb, int p)
{
    int result = 1;
    if (p < 0)
        return 0;
    for (int i = 0; i < p; i++)
        result *= nb;
    return result;
}

int main(void)
{
    my_compute_power_it(5, 3);
    return 0;
}