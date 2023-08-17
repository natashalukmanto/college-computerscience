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
ENQUEUE is assigned the value 1
DEQUEUE is assigned the value 2
ISEMPTY is assigned the value 3
FRONT is assigned the value 4
SIZE is assigned the value 5
CLEARQUEUE is assigned the value 6
*/
enum MenuOptions {
    EXIT,       //0
    ENQUEUE,    //1
    DEQUEUE,    //2
    ISEMPTY,    //3
    FRONT,      //4
    SIZE,       //5
    CLEARQUEUE  //6
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
void Enqueue(PersonNode *&head);
void Dequeue(PersonNode *&head);
void IsEmpty(PersonNode *&head);
void Front(PersonNode *&head);
void Size(PersonNode *&head);
void ClearQueue (PersonNode *&head);

//void OutputList(PersonNode *head);
void PrintHeading();
void GetAndValidateInput();

#endif