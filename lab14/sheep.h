/**********************************************************************
 * AUTHOR		: Natasha Lukmanto
 * STUDENT ID	: 1253798
 * LAB #     	: Lab #14 - Inheritance, Overloading, Redefining
 * CLASS 		: CS 1B
 * SECTION 		: M-Th : 5p - 7:20p
 * DUE DATE 	: Sun Jul 30, 2023 11:59pm
**********************************************************************/

#include "animal.h"

class Sheep: public Animal { // derived class
    public:
    Sheep(); // constructor
    ~Sheep(); // destructor

    /*** MUTATORS ***/
    void modify(string name, int age, WoolType wool, string woolColor);
    
    /*** ACCESSORS ***/
    void DisplayTable() const; // print all animal’s details
    void TableHeading() const; // output the table headings
    WoolType GetWoolType() const; string GetWoolColor() const;

    private: // sheep wool details
    WoolType wool; // sheep's wool type (enum.)
    string woolColor; // sheep’s wool color
};

