#include <stdio.h>
#include <stdbool.h>


void bubble_sort_optimized(int array[], int size){

    int i, j, temp;
    bool swapped;

    for (i=1; i<size; ++i){
        swapped=false;
        for(j=0; j<size-i; ++j){
            if(array[j]>array[j+1]){
                temp=array[j];
                array[j]=array[j+1];
                array[j+1]=temp;
                swapped=true;
            }
        }

        if(!swapped)
            break;
    }
}








