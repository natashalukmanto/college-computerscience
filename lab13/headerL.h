#ifndef _HEADERL_H_
#define _HEADERL_H_

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
    struct SheepNode {
        Sheep currentSheep; // store class’s name
        SheepNode *next; // linked list next pointer
    };
    SheepNode *head ;
    int sheepCount; // Total number of sheep in the list
};

// Farm List Methods

FarmList::FarmList() {
    head = NULL;
    sheepCount = 0;
}

FarmList::~FarmList() {
    SheepNode *sheepPtr;
    // Clear the list
    sheepPtr = head;
    while(sheepPtr != NULL) {
        head = head -> next;
        delete sheepPtr;
        sheepPtr = head;
    }
}

void FarmList::AddSheep(Sheep newSheep) {
    SheepNode *newSheepNode;
    SheepNode *tail;
    newSheepNode = new SheepNode;
    /*** ADD TO THE TAIL ***/
    // Check if there is memory for the new node
    if (newSheepNode != NULL) {
        newSheepNode->currentSheep.SetInitialValues(newSheep.GetName(), newSheep.GetAge());
        newSheepNode->next = NULL;
        // Check if the list is empty;
        if (head != NULL) {
            tail = head;
            // Find the tail
            while (tail->next != NULL) {
                tail = tail->next;
            }
            tail->next = newSheepNode;
        } else {
            head = newSheepNode;
        }
        // Update the class counter with one more class
        sheepCount++;
    } else {
        cout << "Could not Add Course – out of Memory\n";
    }
}


Sheep FarmList::GetFirstSheep() const {
    return head -> currentSheep;
}

int FarmList::TotalSheep() const {
    return sheepCount;
}

void FarmList::DisplaySheepTable() const {
    SheepNode *sheepPtr;
    cout << "NAME           AGE\n";
    cout << "-------------- ---\n";
    for (sheepPtr = head; sheepPtr != NULL; sheepPtr = sheepPtr -> next) {
        cout << left << setw(16) << sheepPtr -> currentSheep.GetName() << sheepPtr -> currentSheep.GetAge() << endl;
    }
    cout << endl;
}

Sheep FarmList::FindSheep(string sheepName) const {
    SheepNode *sheepPtr; Sheep foundSheep;
    if (sheepCount != 0) {
        for (sheepPtr = head; sheepPtr != NULL; sheepPtr = sheepPtr -> next) {
            if (sheepPtr -> currentSheep.GetName() == sheepName) {
                foundSheep = sheepPtr -> currentSheep;
            }
        }
    }
    return foundSheep;
}

void FarmList::ClearList() {
    if (sheepCount == 0) {
        cout << "The list is empty!\n\n";
    } else {
        sheepCount = 0; head = NULL;
        cout << "The list has been cleared!\n\n";
    }
}

#endif