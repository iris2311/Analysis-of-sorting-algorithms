#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "selection_sort.c"
#include "bubble_sort.c"
#include "bubble_sort_1.c"
#include "bubble_sort_2.c"
#include "insertion_sort.c"

void print_array(int array[], int size)
{

    int i;
    for (i = 0; i < size; ++i)
        printf("%d ", array[i]);

    printf("\n");
}

void selection_sort_silazno(int array[], int size) // algoritam pomocu kojeg cemo nizove prvo sortirati silazno
{

    int i, j, temp, index, max_element;

    for (i = 0; i <= size - 2; ++i)
    {
        index = i;
        max_element = array[i];

        for (j = i + 1; j < size; ++j)
        {
            if (array[j] > max_element)
            {
                index = j;
                max_element = array[j];
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

int main(void)
{

    int size = 10;
    int max_array_size = 1000000;
    int i, tmp;
    int k = 1;
    time_t t;
    srand((unsigned)time(&t));
    clock_t time;

    while (k <= 5) // generiramo nizove veličina 10^k
    {

        // vrijeme za jedno izvodenje algoritma
        double time_insertion, time_selection, time_bubble, time_bubble1, time_bubble2;
        // ukupno vrijeme za silazno sortirane nizove kao ulaz
        double insertion = 0, selection = 0, bubble = 0, bubble1 = 0, bubble2 = 0;

        int count = 0;

        while (count < 100) // generiramo 100 nizova
        {

            int array_s[size], array_i[size], array_b1[size],
                array_b2[size], array_b[size], tmp_array[size];

            for (i = 0; i < size; ++i)
            {
                tmp_array[i] = rand();
            }

            selection_sort_silazno(tmp_array, size); // sortiramo generirani niz silazno

            for (i = 0; i < size; i++)
            {
                tmp = tmp_array[i];
                array_s[i] = tmp; // silazno sortirani nizovi
                array_i[i] = tmp;
                array_b[i] = tmp;
                array_b1[i] = tmp;
                array_b2[i] = tmp;
            }

            time = clock();
            selection_sort(array_s, size);
            time = clock() - time;
            time_selection = 1000 * ((double)time) / CLOCKS_PER_SEC; // vrijeme u milisekundama

            time = clock();
            insertion_sort(array_i, size);
            time = clock() - time;
            time_insertion = 1000 * ((double)time) / CLOCKS_PER_SEC; // vrijeme u milisekundama

            time = clock();
            bubble_sort(array_b, size);
            time = clock() - time;
            time_bubble = 1000 * ((double)time) / CLOCKS_PER_SEC; // vrijeme u milisekundama

            time = clock();
            bubble_sort_optimized(array_b1, size);
            time = clock() - time;
            time_bubble1 = 1000 * ((double)time) / CLOCKS_PER_SEC; // vrijeme u milisekundama

            time = clock();
            bubble_sort_optimized2(array_b2, size);
            time = clock() - time;
            time_bubble2 = 1000 * ((double)time) / CLOCKS_PER_SEC; // vrijeme u milisekundama

            bubble += time_bubble;
            selection += time_selection; // ukupno vrijeme
            insertion += time_insertion;
            bubble1 += time_bubble1;
            bubble2 += time_bubble2;

            count++;
        }

        printf("Ukupno vrijeme za k=%d \n", k);

        printf("Selection sort: %f \n", selection);
        printf("Insertion sort: %f \n", insertion);
        printf("Bubble sort: %f \n", bubble);
        printf("Bubble sort1: %f \n", bubble1);
        printf("Bubble sort2: %f \n \n ", bubble2);
        size = size * 10;
        k++;
    }

    return 0;
}