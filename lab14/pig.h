/**********************************************************************
 * AUTHOR		: Natasha Lukmanto
 * STUDENT ID	: 1253798
 * LAB #     	: Lab #14 - Inheritance, Overloading, Redefining
 * CLASS 		: CS 1B
 * SECTION 		: M-Th : 5p - 7:20p
 * DUE DATE 	: Sun Jul 30, 2023 11:59pm
**********************************************************************/

#include "animal.h"


class Pig: public Animal { // derived class
    public:
    Pig(); // constructor
    ~Pig(); // destructor

    /*** MUTATORS ***/
    void modify(string name, int age, TailType tail);
    
    /*** ACCESSORS ***/
    void DisplayTable() const; // print all animal’s details
    void TableHeading() const; // output the table headings
    TailType GetTailType() const; //return the tail type of the pig

    private: // sheep wool details
    TailType tail; // pig's wool type (enum.)
};

