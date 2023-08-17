/***********************************************************
 * AUTHOR		: Natasha Lukmanto
 * STUDENT ID	: 1253798
 * LAB #     	: Assignment #4 - Recursion Performance
 * CLASS 		: CS 1B
 * SECTION 		: M-Th : 5p - 7:20p
 * DUE DATE 	: Sat Jul 22, 2023 11:59pm
 **********************************************************/

#include "header.h"
#include "functions.cpp"

int main()
{
    PrintHeading();
    int option;          // IN – an option for the user to input which choice
    int number;          // IN – a number from the user
    bool invalid = true; // LCV – to exit the loop when the user wants to exit
    while (invalid)
    {
        // PROCESSING: the menu options
        cout << "MENU OPTIONS:" << endl;
        cout << "1 – Calculate and Display Factorial of a Number" << endl;
        cout << "2 – Calculate and Display Fibonacci Series of a Number" << endl;
        cout << "3 – Compare Performance for Factorial Implementations" << endl;
        cout << "4 – Compare Performance for Fibonacci Series Implementations" << endl;
        cout << "0 - EXIT" << endl;
        cout << "Enter an option (0 to exit): ";

        if (!(cin >> option))
        {
            cout << "**** Please input a NUMBER between 0 and 4 ****" << endl
                 << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        else if (option < 0 || option > 5)
        {
            cout << endl;
            cout << "**** The number " << option << " is an invalid entry     ****" << endl;
            cout << "**** Please input a number between 0 and 4 ****" << endl
                 << endl;
        }
        else
        {
            switch (option)
            {
            case 0:
                invalid = false;
                cout << endl;
                break;
            case 1:
                cout << endl
                     << "Enter a number to calculate the factorial of: ";
                if (!(cin >> number))
                {
                    cout << "**** Please input a NUMBER bigger than 0 ****" << endl
                         << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
                else if (number < 0)
                {
                    cout << endl;
                    cout << "**** The number " << number << " is an invalid entry     ****" << endl;
                    cout << "**** Please input a number bigger than 0 ****" << endl
                         << endl;
                }
                else if (number == 1)
                {
                    cout << endl;
                    cout << "The factorial of n equal 1 is: 0" << endl
                         << endl;
                }
                else
                {
                    cout << "The factorial of n equal " << number << " is: " << RecursiveFactorial(number) << endl
                         << endl;
                }
                cout << endl;
                break;
            case 2:
                cout << endl
                     << "Enter a number to calculate the fibonacci series of: ";
                if (!(cin >> number))
                {
                    cout << "**** Please input a NUMBER bigger than 0 ****" << endl
                         << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
                else if (number < 0)
                {
                    cout << endl;
                    cout << "**** The number " << number << " is an invalid entry     ****" << endl;
                    cout << "**** Please input a number bigger than 0 ****" << endl
                         << endl;
                }
                else if (number == 0)
                {
                    cout << endl;
                    cout << "The the fibonacci series of n equal 0 is: 0" << endl
                         << endl;
                }
                else if (number == 1)
                {
                    cout << endl;
                    cout << "The the fibonacci series of n equal 1 is: 1" << endl
                         << endl;
                }
                else
                {
                    cout << "The Fibonacci Series for n equal " << number << " is: ";

                    for (int i = 0; i <= number; i++)
                    {
                        cout << RecursiveFibonacci(i) << ",";
                    }
                    cout << endl
                         << endl;
                }
                cout << endl;
                break;
            case 3:
            {
                int n;
                cout << endl
                     << "Enter a number to compare factorial computation: ";
                cin >> n;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                auto t1 = chrono::high_resolution_clock::now();
                for (int i = 0; i < 100; i++)
                {
                    RecursiveFactorial(n);
                }
                auto t2 = chrono::high_resolution_clock::now();
                auto duration = chrono::duration_cast<chrono::microseconds>(t2 - t1).count();
                cout << "Recursive Factorial took " << duration << " microseconds" << endl;

                t1 = chrono::high_resolution_clock::now();
                for (int i = 0; i < 100; i++)
                {
                    IterativeFactorial(n);
                }
                t2 = chrono::high_resolution_clock::now();
                duration = chrono::duration_cast<chrono::microseconds>(t2 - t1).count();
                cout << "Iterative Factorial took " << duration << " microseconds" << endl
                     << endl;
            }
            break;
            case 4:
            {

                int n;
                cout << endl << "Enter number to compare Fibonacci series computation: ";
                cin >> n;

                cin.ignore(); 

                auto t1 = chrono::high_resolution_clock::now();
                for (int i = 0; i < 100; i++)
                {
                    RecursiveFibonacci(n);
                }

                auto t2 = chrono::high_resolution_clock::now();
                auto duration = chrono::duration_cast<chrono::microseconds>(t2 - t1).count();
                cout << "Recursive Fibonacci took " << duration << " microseconds" << endl;

                t1 = chrono::high_resolution_clock::now();
                for (int i = 0; i < 100; i++)
                {
                    IterativeFibonacci(n);
                }

                t2 = chrono::high_resolution_clock::now();
                duration = chrono::duration_cast<chrono::microseconds>(t2 - t1).count();
                cout << "Iterative Fibonacci took " << duration << " microseconds" << endl << endl;
            }
            break;
            }
        }
    }
    return 0;
}