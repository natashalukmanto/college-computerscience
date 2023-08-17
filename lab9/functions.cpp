#include "header.h"

/* Stack Implementation */

//This function adds an element to the top of the stack
void Push(PersonNode *&head) {
    PersonNode *perPtr = new PersonNode;

    cout << endl << "Who would you like to add?" << endl << endl;
    cout << left;
    cout << setw(14) << "Enter Name:";
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, perPtr -> name);
    cout  << setw(14) << "Enter Gender:";
    cin.get(perPtr -> gender);
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << setw(14) << "Enter Age:";
    cin >> perPtr -> age;
    cout << right;

    perPtr -> next = head;
    head = perPtr;
    perPtr = NULL;
}

//This function removes an element from the top of the stack
void Pop(PersonNode *&head) {
	PersonNode *perPtr = head;
	if (head == NULL) {
		cout << endl << "Can't POP from an empty stack!" << endl;
	} else {
		cout << left;
		cout << endl << "POPPING" << endl;
        cout << setw(8) << "Name:" << perPtr -> name << endl;
		cout << setw(8) << "Gender:" << perPtr -> gender << endl;
        cout << setw(8) << "Age:" << perPtr -> age << endl;
        cout << right;

		head = perPtr -> next;
		perPtr = NULL;
		delete perPtr;
	}
	
}

//This function determines whether the stack is empty or not
void IsEmpty(PersonNode *&head) {
	if (head == NULL) { cout << endl << "Yes, the stack is empty." << endl; }
	else { cout << endl << "The stack is NOT empty." << endl; }
}

//This function examines the element on top of the stack
void Peek(PersonNode *&head) {
	PersonNode *perPtr = head; 
	if (head == NULL) {
		cout << endl << "There is nobody to PEEK at!!" << endl;
	} else {
		cout << left;
		cout << endl << "PEEKING at" << endl;
        cout << setw(8) << "Name:" << perPtr -> name << endl;
		cout << setw(8) << "Gender:" << perPtr -> gender << endl;
        cout << setw(8) << "Age:" << perPtr -> age << endl;
        cout << right;
	}
	perPtr = NULL;
	delete perPtr;
}

//This function determines the number of elements in a stack
void Size(PersonNode *&head) {
    int size = 0;
    PersonNode *perPtr = head;

    while (perPtr != nullptr) {
        size += 1;
        perPtr = perPtr->next;
    }

    if (size == 0) {
        cout << endl << "Nobody is on the stack!" << endl;
    } else if (size == 1) {
        cout << endl << "There is " << size << " person on the stack." << endl;
    } else {
        cout << endl << "There are " << size << " people on the stack." << endl;
    }
}

/* Others */

/*
This code defines a function called GetAndValidateInput 
that presents a menu to the user and validates their input.

Then, it calls the corresponding function.
*/
void GetAndValidateInput() {
	int option; bool invalid = true;
	while (invalid) {
		cout << "STACK MENU:" << endl;
		cout << "1 – Add a person (PUSH)" << endl;
		cout << "2 – Remove a person (POP)" << endl;
		cout << "3 – Is the stack empty? (ISEMPTY)" << endl;
		cout << "4 – Who is on top? (PEEK)" << endl;
		cout << "5 – How many people are there? (SIZE)" << endl;
		cout << "0 – to Exit" << endl;
		cout << "Enter a command? ";

		if (!(cin >> option)) {
			cout << "**** Please input a NUMBER between 0 and 5 ****" << endl << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		} else if (option < 0  || option > 5) {
			cout << endl;
			cout << "**** The number 12 is an invalid entry     ****" << endl;
			cout << "**** Please input a number between 0 and 5 ****" << endl << endl;
		} else {
			menu = MenuOptions(option);
			switch (menu) {
				case EXIT:
					invalid = false;
					cout << endl;
					break;
				case PUSH:
					Push(people);
					cout << endl;
					break;
				case POP:
					Pop(people);
					cout << endl;
					break;
				case ISEMPTY:
					IsEmpty(people);
					cout << endl;
					break;
				case PEEK:
					Peek(people);
					cout << endl;
					break;
				case SIZE:
					Size(people);
					cout << endl;
					break;
			}
		}
	}
}

/*
void OutputList(PersonNode *head) {
    PersonNode *perPtr = head;
    while (perPtr != NULL) {
        cout << left;
        cout << endl << setw(7) << "Name:" << perPtr -> name << endl;
		cout << endl << setw(7) << "Gender:" << perPtr -> gender << endl;
        cout << setw(7) << "Age:" << perPtr -> age << endl;
        cout << right;
        perPtr = perPtr -> next;
    }
}
*/

//This function prints the heading in the output
void PrintHeading() {
    const char PROGRAMMER[30] = "Natasha Lukmanto";
	const char CLASS[5] = "CS1B";
	const char SECTION[25] = "M-Th: 5:00p - 7:20p";
	const int LAB_NUM = 0 - 7;
	const char LAB_NAME[50] = "Lab #9 - Implement a Stack";
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