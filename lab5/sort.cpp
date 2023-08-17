#include "header.h"

void InsertionSort(int int_array[]) {
    const int size = 8;

    for (int i = 1; i < size; ++i) {
        int temp = int_array[i];
        int j = i-1;
        while (j >= 0 && int_array[j] > temp) {
            int_array[j+1] = int_array[j];
            j = j-1;
        }
        int_array[j+1]= temp;
    }
}