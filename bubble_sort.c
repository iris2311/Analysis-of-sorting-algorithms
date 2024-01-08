#include <stdio.h>


void bubble_sort(int array[], int size){

    int i, j, temp;

    for (i=1; i<size; ++i){
        for(j=0; j<size-i; ++j){
            if(array[j]>array[j+1]){
                temp=array[j];
                array[j]=array[j+1];
                array[j+1]=temp;
            }
        }
    }
}







