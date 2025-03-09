int my_compute_power_rec(int nb, int p)
{
    if (p < 0)
        return 0;
    if (p == 0)
        return 1;
    return nb * my_compute_power_rec(nb, p - 1);
}

int main(void)
{
    my_compute_power_rec(5, 3);
    return 0;
}