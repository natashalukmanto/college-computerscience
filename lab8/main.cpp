/***********************************************************
 * AUTHOR		: Natasha Lukmanto
 * STUDENT ID	: 1253798
 * LAB #     	: Lab #8 - Introduction to Pointers
 * CLASS 		: CS 1B
 * SECTION 		: M-Th : 5p - 7:20p
 * DUE DATE 	: Wed Jun 7, 2023 11:59pm
 **********************************************************/

#include "header.h"

int main() {

    const char PROGRAMMER[30] = "Natasha Lukmanto";
	const char CLASS[5] = "CS1B";
	const char SECTION[25] = "M-Th: 5:00p - 7:20p";
	const int LAB_NUM = 0 - 7;
	const char LAB_NAME[50] = "Lab #8 - Introduction to Pointers";
	// OUTPUT – Class Heading
	cout << left;
	cout << "**************************************************";
	cout << "\n* PROGRAMMED BY : " << PROGRAMMER;
	cout << "\n* " << setw(14) << "CLASS" << ": " << CLASS;
	cout << "\n* " << setw(14) << "SECTION" << ": " << SECTION;
	cout << "\n* LAB #" << setw(9) << LAB_NUM << ": " << LAB_NAME;
	cout << "\n**************************************************\n\n";
	cout << right;

    int *num1Ptr = new int; //IN - first integer
    int *num2Ptr = new int; //IN - second integer

    //Processing: asks the user to prompt in numbers until the sentinel value -999
    do {
        cout << left;
        cout << setw(44) << "Input the first value (enter -999 to exit)? ";
        cin >> *num1Ptr;
        //Program terminates if it reaches -999
        if (*num1Ptr == -999) { 
            delete num1Ptr; delete num2Ptr;
            return 0;
        }
        else { 
            cout << setw(44) << "Input the second value? ";
            cin >> *num2Ptr;
        }
        cout << endl;
        cout << setw(16) << "The sum is: " << *num1Ptr + *num2Ptr << endl;
        cout << setw(16) << "The product is: " << *num1Ptr * *num2Ptr << endl << endl;
    } while (true);
}