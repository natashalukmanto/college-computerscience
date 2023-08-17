#ifndef _HEADER_H_
#define _HEADER_H_

#include <iostream>
#include <iomanip>
#include <limits>
#include <ios>
using namespace std;

/*
The code declares an enum named MenuOptions, 
which represents a set of menu options for a program.

EXIT is assigned the value 0
PUSH is assigned the value 1
POP is assigned the value 2
ISEMPTY is assigned the value 3
PEEK is assigned the value 4
SIZE is assigned the value 5
*/
enum MenuOptions {
    EXIT,       //0
    PUSH,       //1
    POP,        //2
    ISEMPTY,    //3
    PEEK,       //4
    SIZE        //5
};

/*
The code defines a struct named PersonNode, 
which represents a single node in a linked list for storing information about a person.

name: A string variable that stores the name of the person.
gender: A character variable that stores the gender of the person.
age: An integer variable that stores the age of the person.
next: A pointer to another PersonNode struct, which represents the next node in the linked list.
*/
struct PersonNode {
    string name;
    char gender;
    int age;
    PersonNode *next;
};

MenuOptions menu;
PersonNode *people;

//Functions definition
void Push(PersonNode *&head);
void Pop(PersonNode *&head);
void IsEmpty(PersonNode *&head);
void Peek(PersonNode *&head);
void Size(PersonNode *&head);

//void OutputList(PersonNode *head);
void PrintHeading();
void GetAndValidateInput();

#endif