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

int main(void)
{

    int size = 10;
    int max_array_size = 1000000;
    int i, tmp;
    int k = 1;
    time_t t;
    srand((unsigned)time(&t));
    clock_t time;

    while (k <= 5) // generiramo nizove velicine 10^k
    {
        // vrijeme za jedno izvodenje
        double time_insertion, time_selection, time_bubble, time_bubble1, time_bubble2;
        // ukupno vrijeme slučajno generiranim nizovima
        double insertion = 0, selection = 0, bubble = 0, bubble1 = 0, bubble2 = 0;
        // ukupno vrijeme na vec uzlazno sortiranim nizovima
        double sinsertion = 0, sselection = 0, sbubble = 0, sbubble1 = 0, sbubble2 = 0;
        int count = 0;
        while (count < 100) // generiramo 100 nizova
        {

            int random_array_s[size], random_array_i[size], random_array_b1[size],
                random_array_b2[size], random_array_b[size]; // nizovi generirani na slučajan način

            for (i = 0; i < size; i++)
            {
                tmp = rand();
                random_array_s[i] = tmp;
                random_array_i[i] = tmp;
                random_array_b[i] = tmp;
                random_array_b1[i] = tmp;
                random_array_b2[i] = tmp;
            }

            // vrijeme trajanja algoritama na slučajno generiranim nizovima

            time = clock();
            selection_sort(random_array_s, size);
            time = clock() - time;
            time_selection = 1000 * ((double)time) / CLOCKS_PER_SEC; // vrijeme u milisekundama

            time = clock();
            insertion_sort(random_array_i, size);
            time = clock() - time;
            time_insertion = 1000 * ((double)time) / CLOCKS_PER_SEC; // vrijeme u milisekundama

            time = clock();
            bubble_sort(random_array_b, size);
            time = clock() - time;
            time_bubble = 1000 * ((double)time) / CLOCKS_PER_SEC; // vrijeme u milisekundama

            time = clock();
            bubble_sort_optimized(random_array_b1, size);
            time = clock() - time;
            time_bubble1 = 1000 * ((double)time) / CLOCKS_PER_SEC; // vrijeme u milisekundama

            time = clock();
            bubble_sort_optimized2(random_array_b2, size);
            time = clock() - time;
            time_bubble2 = 1000 * ((double)time) / CLOCKS_PER_SEC; // vrijeme u milisekundama

            bubble += time_bubble;
            selection += time_selection;
            insertion += time_insertion; // ukupno vrijeme na slučajno generiranim nizovima
            bubble1 += time_bubble1;
            bubble2 += time_bubble2;

            // vrijeme na nizovima već sortiranim uzlazno
            time = clock();
            selection_sort(random_array_s, size); // random_array_s je već sortiran uzlazno jer je na njega
                                                  // prije primjenjen algoritam za sortiranje
            time = clock() - time;
            time_selection = 1000 * ((double)time) / CLOCKS_PER_SEC; // vrijeme u milisekundama

            time = clock();
            insertion_sort(random_array_i, size);
            time = clock() - time;
            time_insertion = 1000 * ((double)time) / CLOCKS_PER_SEC; // vrijeme u milisekundama

            time = clock();
            bubble_sort(random_array_b, size);
            time = clock() - time;
            time_bubble = 1000 * ((double)time) / CLOCKS_PER_SEC; // vrijeme u milisekundama

            time = clock();
            bubble_sort_optimized(random_array_b1, size);
            time = clock() - time;
            time_bubble1 = 1000 * ((double)time) / CLOCKS_PER_SEC; // vrijeme u milisekundama

            time = clock();
            bubble_sort_optimized2(random_array_b2, size);
            time = clock() - time;
            time_bubble2 = 1000 * ((double)time) / CLOCKS_PER_SEC; // vrijeme u milisekundama

            sbubble += time_bubble;
            sselection += time_selection;
            sinsertion += time_insertion; // ukupno vrijeme na već uzlazno sortiranim nizovima
            sbubble1 += time_bubble1;
            sbubble2 += time_bubble2;

            count++;
        }

        printf("Ukupno vrijeme za k=%d \n", k);

        printf("Selection sort: %f \n", selection);
        printf("Insertion sort: %f \n", insertion);
        printf("Bubble sort: %f \n", bubble);
        printf("Bubble sort1: %f \n", bubble1);
        printf("Bubble sort2: %f \n \n", bubble2);

        printf("Ukupno vrijeme na sortiranim nizovima za k=%d \n", k);

        printf("Selection sort: %f \n", sselection);
        printf("Insertion sort: %f \n", sinsertion);
        printf("Bubble sort: %f \n", sbubble);
        printf("Bubble sort1: %f \n", sbubble1);
        printf("Bubble sort2: %f \n \n", sbubble2);
        size = size * 10;
        k++;
    }

    return 0;
}