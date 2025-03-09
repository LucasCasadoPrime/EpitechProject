void my_sort_int_array(int *array, int size)
{
    int i = 0;
    int j = 0;
    int tmp = 0;

    while (i < size)
    {
        j = i + 1;
        while (j < size)
        {
            if (array[i] > array[j])
            {
                tmp = array[i];
                array[i] = array[j];
                array[j] = tmp;
            }
            j++;
        }
        i++;
    }
}

int main(void)
{
    int array[] = {1, 3, 2, 4, 5};
    my_sort_int_array(array, 5);
    return 0;
}