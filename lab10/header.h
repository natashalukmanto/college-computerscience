#ifndef _HEADER_H_
#define _HEADER_H_

#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

enum MenuOptions {
    EXIT,
    CREATE,
    DISPLAY,
    ISEMPTY,
    SEARCH,
    REMOVE,
    CLEAR
};

struct Person {
    Person *prev;
    string name;
    char gender;
    int age;
    Person *next;
};

Person *people;
MenuOptions menu;

void CreateList(string name, char gender, int age );
void DisplayList();
bool IsEmpty();
Person* Search(string name_search);
void Remove(string name_remove);
void Clear();

#endif