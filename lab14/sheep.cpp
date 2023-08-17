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
#include "sheep.h"

Sheep sheep[3];

Sheep::Sheep() {}

Sheep::~Sheep() {}

WoolType Sheep::GetWoolType() const { return wool; }
string Sheep::GetWoolColor() const { return woolColor; }

void Sheep::modify(string name, int age, WoolType wool, string woolColor) {
    age = age;
    name = name;
    wool = wool;
    woolColor = woolColor;
}

void Sheep::DisplayTable() const {
    TableHeading();
    for (int i = 0; i < 3; i++) {
        cout << setw(10) << sheep[i].GetName();
        cout << setw(4) << sheep[i].GetAge();
        cout << setw(8) << sheep[i].GetWoolType(); 
        cout << setw(5) << sheep[i].GetWoolColor() << endl;
    }
}

void Sheep::TableHeading() const {
    cout << "THE SHEEP:\n\n";
    cout << "NAME      AGE WOOLTYPE COLOR\n";
    cout << "--------- --- -------- -----\n";
}