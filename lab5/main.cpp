/***********************************************************
 * AUTHOR		: Natasha Lukmanto
 * STUDENT ID	: 1253798
 * LAB #     	: Assignment #1 – Functions and Arrays
 * CLASS 		: CS 1B
 * SECTION 		: M-Th : 5p - 7:20p
 * DUE DATE 	: Fri Jun 16, 2023 11:59pm
 **********************************************************/

#include "header.h"
#include "sort.cpp"
#include "search.cpp"
#include "output.cpp"

int main() {
    const char PROGRAMMER[30] = "Natasha Lukmanto";
	const char CLASS[6] = "CS 1B";
	const char SECTION[25] = "M-Th: 5:00p - 7:20p";
	const int LAB_NUM = 0 - 7;
	const char LAB_NAME[50] = "Lab #5 - Binary Search";
	cout << left;
	cout << "**************************************************";
	cout << "\n* PROGRAMMED BY : " << PROGRAMMER;
	cout << "\n* " << setw(14) << "CLASS" << ": " << CLASS;
	cout << "\n* " << setw(14) << "SECTION" << ": " << SECTION;
	cout << "\n* LAB #" << setw(9) << LAB_NUM << ": " << LAB_NAME;
	cout << "\n**************************************************\n\n";
	cout << right;

    OutputArray(intArray);
    cout << endl;
    for (int i = 0; i < 4; i++) {
        cout << "Enter an integer to search for: ";
        cin >> key;
        int answer = SequentialSearch(intArray, key);
        if (answer != -1) { cout << "The integer " << key << " was found in index #" << answer << "." << endl << endl; }
        else { cout << key << " was not Found!" << endl << endl; }
    }

    cout << "Performing Insertion Sort" << endl << endl;
    InsertionSort(intArray);

    OutputArray(intArray);
    
    cout << endl;
    for (int i = 0; i < 4; i++) {
        cout << "Enter an integer to search for: ";
        cin >> key;
        int answer = BinarySearch(intArray, key);
        if (answer != -1) { cout << "The integer " << key << " was found in index #" << answer << "." << endl << endl; }
        else { cout << key << " was not Found!" << endl << endl; }
    }
}