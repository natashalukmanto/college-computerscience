#ifndef ANIMAL_H
#define ANIMAL_H

#include <string>
using namespace std;

enum WoolType { LONG, MEDIUM, FINE, CARPET };
enum TailType { STRAIGHT, CORKSCREW, CURL_UP, CURL_RIGHT, CURL_LEFT };

class Animal { // base class
public:
    Animal(); // constructor
    ~Animal(); // destructor

    /******************
    *** MUTATORS ***
    ******************/
    void modify(int age); // change the animal's age
    void modify(string name); // change the animal's name
    void modify(int age, string name); // change the animal's age & name

    /*******************
    *** ACCESSORS ***
    *******************/
    string GetName() const; // return the animal’s name
    int GetAge() const; // return the animal's age
    void DisplayTable() const; // print all animal’s details
    void TableHeading() const; // output the table headings

private:
    string name; // animal's name
    int age; // animal's age in years
};


#endif // ANIMAL_H
