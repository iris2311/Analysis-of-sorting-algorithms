#include <stdio.h>

void bubble_sort_optimized2(int array[], int size)
{

    int i, j, temp, ind;

    i = size - 1;

    while (i > 0)
    {
        ind = -1;
        for (j = 0; j < i; ++j)
        {
            if (array[j] > array[j + 1])
            {
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
                ind = j;
            }
        }

        i = ind;
    }
}
