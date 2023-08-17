/**********************************************************************
 * AUTHOR		: Natasha Lukmanto
 * STUDENT ID	: 1253798
 * LAB #     	: Lab #14 - Inheritance, Overloading, Redefining
 * CLASS 		: CS 1B
 * SECTION 		: M-Th : 5p - 7:20p
 * DUE DATE 	: Sun Jul 30, 2023 11:59pm
**********************************************************************/

#include <iostream> // Add this line to include iostream
#include <iomanip>
#include "pig.h"

Pig pigs[3];

Pig::Pig() {}

Pig::~Pig() {}

TailType Pig::GetTailType() const {
    return tail;
}

void Pig::modify(string name, int age, TailType tail) {
    age = age;
    name = name;
    tail = tail;
}

void Pig::DisplayTable() const {
    TableHeading();
    for (int i = 0; i < 3; i++) {
        cout << setw(10) << pigs[i].GetName();
        cout << setw(4) << pigs[i].GetAge();
        cout << setw(8) << pigs[i].GetTailType() << endl; 
    }

}

void Pig::TableHeading() const {
    cout << "THE PIG(S):\n\n";
    cout << "NAME      AGE TAILTYPE\n";
    cout << "--------- --- --------\n";
}