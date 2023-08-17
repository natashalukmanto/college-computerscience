#include "header.h"

void OutputArray(int int_array[]) {
    const int size = 8;

    for (int i = 0; i < size; i++) {
        cout << "Index #" << i << ": ";
        cout << int_array[i] << endl;
    }
}