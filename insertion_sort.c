#include <stdio.h>

void insertion_sort(int array[], int size)
{

    int i, j, temp;

    for (i = 1; i < size; ++i)
    {
        temp = array[i];
        j = i - 1;

        while (j >= 0 && array[j] > temp)
        {
            array[j + 1] = array[j];
            j--;
        }

        array[j + 1] = temp;
    }
}



