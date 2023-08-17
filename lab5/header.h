#ifndef HEADER_H_
#define HEADER_H_

//Preprocessor Directives 
#include <iostream>
#include <iomanip>
using namespace std;

int intArray[8] = {4, 1, 7, 12, 8, 13, 9, 21};
int key;

//Prototypes
void InsertionSort(int int_array[]);
int SequentialSearch(int int_array[], int key);
int BinarySearch(int int_array[], int key);
void OutputArray(int int_array[]);

#endif /* HEADER_H_ */