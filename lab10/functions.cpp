#include "header.h"

Person* head = nullptr;
Person* tail = nullptr;

//This function creates a linked list adding each node in alphabetical order. Read from input file.
//This function takes in three paramters:
//  1.) a string name for perPtr -> name
//  2.) a char gender for perPtr -> gender
//  3.) an int age for perPtr -> age 
//This function has no return data type.
void CreateList(string name, char gender, int age) {
    Person* newNode = new Person;
    newNode->name = name;
    newNode->gender = gender;
    newNode->age = age;
    newNode->prev = nullptr;
    newNode->next = nullptr;

    if (head == nullptr) {
        head = newNode;
        tail = newNode;
    }
    else {
        Person* current = head;
        while (current != nullptr && current->name < name) {
            current = current->next;
        }

        if (current == head) {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        else if (current == nullptr) {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        else {
            newNode->prev = current->prev;
            current->prev->next = newNode;
            newNode->next = current;
            current->prev = newNode;
        }
    }
    cout << "Adding : " << name << endl;
}

//This function displays the linked-list in the format described in the expected input/output section.
//This function takes in no parameter and no return data type.
void DisplayList() {
    if (head == nullptr) {
        cout << endl << "Can't display an empty list." << endl;
    }
    else {
        cout << endl;
        Person* current = head;
        int count = 1;
        cout << "   #    NAME              GENDER  AGE" << endl;
        cout << "------- ----------------- ------ -----" << endl;
        while (current != nullptr) {
            if (count < 10) {
                cout << "   " << count << "     " << left << setw(18) << current->name;
            } else {
                cout << "   " << count << "    " << left << setw(18) << current->name;
            }
            
            cout << "  " << current->gender << "   ";
            cout << "  " << current->age << "  "<< endl;
            current = current->next;
            count++;
            cout << right;
        }
    }
}

//This function provides an appropriate response indicating if the list is empty or not.
//This function takes in no parameter
//Returns a boolean value, either true if the list is empty or false if the list is not empty.
bool IsEmpty() {
    return head == nullptr;
}

//This function allows the user to input a name and will output the node as described.
//This function takes in a paramter:
//  1.) a string name_search for the name to be found.
//This function returns a Person Node with the name equivalent to name_search.
Person *Search(string name_search) {
    Person* current = head;
    while (current != nullptr) {
        if (current->name == name_search) {
            return current;
        }
        current = current->next;
    }
    return nullptr;
}

//This function allows the user to input a name and removes the node from the list.
//Takes in a parameter: string name_remove to find which string to be removed, returns nothing
void Remove(string name_remove) {
    Person* nodeToRemove = Search(name_remove);
    if (nodeToRemove != nullptr) {
        if (nodeToRemove == head) {
            head = head->next;
            if (head != nullptr) {
                head->prev = nullptr;
            }
            else {
                tail = nullptr;
            }
        }
        else if (nodeToRemove == tail) {
            tail = tail->prev;
            tail->next = nullptr;
        }
        else {
            nodeToRemove->prev->next = nodeToRemove->next;
            nodeToRemove->next->prev = nodeToRemove->prev;
        }
        cout << endl << "Removing " << nodeToRemove->name << "!" << endl;
        delete nodeToRemove;
    }
    else {
        cout << endl << "I'm sorry, \"" << name_remove << "\" was NOT found!" << endl;
    } 
}

//This function deletes all the nodes in the linked list.
//Returns nothing and takes no output
void Clear() {
    if (IsEmpty()) {
        cout << endl << "The list has been cleared!" << endl;
    }
    else {
        cout << endl << "CLEARING LIST:" << endl;
        Person* current = head;
        while (current != nullptr) {
            Person* nextNode = current->next;
            cout << "Removing " << current->name << "!" << endl;
            delete current;
            current = nextNode;
        }
        head = nullptr;
        tail = nullptr;
    }
}

//This function prints the heading in the output
//Takes no paramters and returns nothing
void PrintHeading() {
    const char PROGRAMMER[30] = "Natasha Lukmanto";
	const char CLASS[5] = "CS1B";
	const char SECTION[25] = "M-Th: 5:00p - 7:20p";
	const int LAB_NUM = 0 - 7;
	const char LAB_NAME[50] = "Lab #10 - Creating an Ordered List";
	// OUTPUT – Class Heading
	cout << left;
	cout << "**************************************************";
	cout << "\n* PROGRAMMED BY : " << PROGRAMMER;
	cout << "\n* " << setw(14) << "CLASS" << ": " << CLASS;
	cout << "\n* " << setw(14) << "SECTION" << ": " << SECTION;
	cout << "\n* LAB #" << setw(9) << LAB_NUM << ": " << LAB_NAME;
	cout << "\n**************************************************\n\n";
	cout << right;
}