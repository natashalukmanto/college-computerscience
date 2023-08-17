#ifndef _ANIMAL_H_
#define _ANIMAL_H_

#include <iostream>
#include <iomanip>
#include <limits>
using namespace std;

/***********************************************************************
    * Animal Class
    *   This class represents an animal object. It manages 4 attributes:
    *   name, type, age, value.
***********************************************************************/
class Animal {
public:
    /* CONSTRUCTOR AND DESTRUCTOR */
    Animal();                       //constructor
    ~Animal();                      //destructor

    /* MUTATORS */
    void SetInitialValues(string aName, string aType, int aAge, float aValue); //set the initial values of the animal (name, 
                                                                               //type, age, and value/price)
    void ChangeAge(int aAge);       //change the animal's age
    void ChangeValue(float aValue); //change the value/price of the animal

    /* ACCESSOR */
    void Display() const;           //display the animal's information
    string GetName() const;         //return animal's name
    string GetType() const;         //return animal's type
    int GetAge() const;             //return animal's age
    float GetValue() const;         //return animal's value/price

private:
    string name;    //IN/OUT – the animal's name
    string type;    //IN/OUT – the animal's type
    int age;        //IN/OUT – the animal's age
    float value;    //IN/OUT – the animal's value/price
};

#endif