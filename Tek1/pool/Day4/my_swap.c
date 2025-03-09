#include <stdio.h>

void my_swap(int *a, int *b)
{
    int tmp;

    tmp = *a;
    *a = *b;
    *b = tmp;
}

int main(void)
{
    int x = 5, y = 10;

    printf("Avant échange : x = %d, y = %d\n", x, y);
    my_swap(&x, &y);
    printf("Après échange : x = %d, y = %d\n", x, y);

    return 0;
}
