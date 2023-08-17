#ifndef _HEADERA_H_
#define _HEADERA_H_

#include <iostream>
#include <iomanip>
#include <limits>
using namespace std;

//Sheep Class
class Sheep {
public:
    Sheep();    /*** constructor ***/
    ~Sheep();   /*** destructor ***/
    /******************
    ***   MUTATORS  ***
    ******************/

    /**
     * SetInitialValues
     * Sets the initial values (name and age) for the sheep.
     *
     * @param sheepName The name of the sheep.
     * @param sheepAge The age of the sheep.
     */
    void SetInitialValues(string sheepName, int sheepAge);
    /*******************
    ***   ACCESSORS  ***
    *******************/

    /**
     * GetName
     * Gets the name of the sheep.
     *
     * @return The name of the sheep as a string.
     */
    string GetName() const;

    /**
     * GetAge
     * Gets the age of the sheep.
     *
     * @return The age of the sheep as an integer.
     */
    int GetAge() const;

private:
    string name;
    int age;
};

// Sheep Methods

Sheep::Sheep() {
    name.clear();
    age = 0;
}

Sheep::~Sheep() {}

void Sheep::SetInitialValues(string sheepName, int sheepAge) {
    name = sheepName;
    age = sheepAge;
};

string Sheep::GetName() const {
    return name;
};

int Sheep::GetAge() const {
    return age;
};

//FarmList Class
const int AR_SIZE = 50; // size of the array
class FarmList {
public:
    FarmList();  /*** constructor ***/
    ~FarmList(); /*** destructor ***/
    /******************
    ***   MUTATORS  ***
    ******************/
    // add a new sheep object to the list, increment sheepCount
    void AddSheep(Sheep newSheep);
    void ClearList(); // remove all sheep
    /*******************
    ***   ACCESSORS  ***
    *******************/
    Sheep FindSheep(string sheepName) const; // Search by name–return the object
    Sheep GetFirstSheep() const;             // Return the first Sheep
    int TotalSheep() const;                  // Return the sheep count
    void DisplaySheepTable() const;          // Output sheep objects in table
private:
    Sheep farmArray[AR_SIZE]; // Array of sheep
    int sheepCount;           // Total number of sheep in the list
};

// Farm List Methods

FarmList::FarmList() {
    sheepCount = 0;
}

FarmList::~FarmList() {}

void FarmList::AddSheep(Sheep newSheep) {
    if (sheepCount < AR_SIZE) {
        farmArray[sheepCount] = newSheep;
        sheepCount++;
    } else {
        cout << "Could not add sheep – array is full!\n";
    }
}

Sheep FarmList::GetFirstSheep() const {
    return farmArray[0];
}

int FarmList::TotalSheep() const {
    return sheepCount;
}

void FarmList::DisplaySheepTable() const {
    cout << "NAME           AGE\n";
    cout << "-------------- ---\n";
    for (int index = 0; index < sheepCount; index++) {
        cout << left << setw(16) << farmArray[index].GetName() << farmArray[index].GetAge() << endl;
    }
    cout << endl;
}

Sheep FarmList::FindSheep(string sheepName) const {
    Sheep foundSheep;
    if (sheepCount != 0) {
        for (int index = 0; index < sheepCount; index++) {
            if (farmArray[index].GetName() == sheepName) {
                foundSheep = farmArray[index];
            }
        }
    }
    return foundSheep;
}

void FarmList::ClearList() {
    if (sheepCount == 0) {
        cout << "The list is empty!\n\n";
    } else {
        sheepCount = 0;
        cout << "The list has been cleared!\n\n";
    }
}

#endif