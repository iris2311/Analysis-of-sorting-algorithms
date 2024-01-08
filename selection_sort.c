#include <stdio.h>

void selection_sort(int array[], int size)
{

    int i, j, temp, index, min_element;

    for (i = 0; i <= size - 2; ++i)
    {
        index = i;
        min_element = array[i];

        for (j = i + 1; j < size; ++j)
        {
            if (array[j] < min_element)
            {
                index = j;
                min_element = array[j];
            }
        }
        if (index != i)
        {
            temp = array[i];
            array[i] = array[index];
            array[index] = temp;
        }
    }
}




