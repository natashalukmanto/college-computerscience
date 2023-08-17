/**********************************************************************
 * AUTHOR		: Natasha Lukmanto
 * STUDENT ID	: 1253798
 * LAB #     	: Lab #14 - Inheritance, Overloading, Redefining
 * CLASS 		: CS 1B
 * SECTION 		: M-Th : 5p - 7:20p
 * DUE DATE 	: Sun Jul 30, 2023 11:59pm
**********************************************************************/

#include <iostream>
#include "animal.h"

Animal::Animal() {}

Animal::~Animal() {}

void Animal::modify(int age) {
    age = age;
}

void Animal::modify(string name) {
    name = name;
}

void Animal::modify(int age, string name) {
    age = age;
    name = name;
}

string Animal::GetName() const {
    return name;
}

int Animal::GetAge() const {
    return age;
}

void Animal::DisplayTable() const {}

void Animal::TableHeading() const {
    cout << "NAME      AGE\n";
    cout << "--------- ---\n";
}
