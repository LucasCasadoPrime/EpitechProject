int my_compute_square_root(int nb)
{
    int i = 0;
    int result = 0;

    while (i <= nb)
    {
        if (i * i == nb)
        {
            result = i;
            return (result);
        }
        i++;
    }
    return (0);
}

int main(void)
{
    my_compute_square_root(4);
    return (0);
}