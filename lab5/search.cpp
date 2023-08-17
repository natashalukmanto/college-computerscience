#include "header.h"

int SequentialSearch(int int_array[], int key) {
    const int size = 8; 

    for (int i = 0; i < size; i++) {
        
        if (key == int_array[i]) { 
            return i;
        }
    }
    return -1;
}

int BinarySearch(int int_array[], int key) {
    const int size = 8; 
    int bottom = 0, top = size-1, middle;
    bool found = false;

    while (!found && bottom <= top) {
        middle = (bottom + top) / 2;
        if (int_array[middle] == key) { found = true; return middle; }
        else {
            if (int_array[middle] < key) {
                bottom = middle + 1;
            } else {
                top = middle - 1;
            }
        }
    }
    return -1;
}