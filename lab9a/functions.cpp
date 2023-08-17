#include "header.h"

/* Queue Implementation */

//This function adds an element to the rear of the queue
void Enqueue(PersonNode *&head) {
    PersonNode *perPtr = new PersonNode;
    PersonNode *tail = head;

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

    perPtr -> next = NULL;

    if (head == NULL) {
        head = perPtr;
    } else {
        while (tail -> next != NULL) {
            tail = tail -> next;
        }
        tail -> next = perPtr;
    }
}

//This function removes an element from the front of the queue
void Dequeue(PersonNode *&head) {
	PersonNode *perPtr = head;
	if (head == NULL) {
		cout << endl << "Can't DEQUEUE from an empty list!" << endl;
	} else {
		cout << left;
		cout << endl << "DEQUEUEING" << endl;
        cout << setw(8) << "Name:" << perPtr -> name << endl;
		cout << setw(8) << "Gender:" << perPtr -> gender << endl;
        cout << setw(8) << "Age:" << perPtr -> age << endl;
        cout << right;

		head = perPtr -> next;
		perPtr = NULL;
		delete perPtr;
	}
	
}

//This function determines whether the queue is empty or not
void IsEmpty(PersonNode *&head) {
	if (head == NULL) { cout << endl << "Yes, the QUEUE is empty." << endl; }
	else { cout << endl << "The QUEUE is NOT empty." << endl; }
}

//This function examines the element in front of in the queue
void Front(PersonNode *&head) {
	PersonNode *perPtr = head; 
	if (head == NULL) {
		cout << endl << "Nobody in FRONT, the queue is empty!!" << endl;
	} else {
		cout << left;
		cout << endl << "The first person in the queue is:" << endl;
        cout << setw(8) << "Name:" << perPtr -> name << endl;
		cout << setw(8) << "Gender:" << perPtr -> gender << endl;
        cout << setw(8) << "Age:" << perPtr -> age << endl;
        cout << right;
	}
	perPtr = NULL;
	delete perPtr;
}

//This function determines the number of elements in the queue
void Size(PersonNode *&head) {
    int size = 0;
    PersonNode *perPtr = head;

    while (perPtr != nullptr) {
        size += 1;
        perPtr = perPtr->next;
    }

    if (size == 0) {
        cout << endl << "Nobody is in the queue!" << endl;
    } else if (size == 1) {
        cout << endl << "There is " << size << " person in the queue." << endl;
    } else {
        cout << endl << "There are " << size << " people in the queue." << endl;
    }
}

//This function empties the queue
void ClearQueue (PersonNode *&head) {
    PersonNode *perPtr = head;
    if (head == NULL) {
		cout << endl << "The QUEUE is ALREADY clear!" << endl;
	} else {
        cout << endl << "CLEARING..." << endl;
        while (perPtr != NULL) {
            cout << left;
            cout << perPtr -> name << endl;
            perPtr = perPtr -> next;
            cout << right;
        }
        cout << endl << "The queue has been CLEARED!" << endl;
        head = NULL;
        delete perPtr;
    }

} 
/* Others */

/*
This code defines a function called GetAndValidateInput 
that presents a menu to the user and validates their input.

Then, it calls the corresponding function.
*/
void GetAndValidateInput() {
	int option; bool invalid = false;
    while (!invalid) {
        cout << "QUEUE MENU:" << endl;
		cout << "1 – ENQUEUE (Add a person)" << endl;
		cout << "2 – DEQUEUE (Remove a person)" << endl;
		cout << "3 – ISEMPTY (Is the queue empty?)" << endl;
		cout << "4 – FRONT   (Who is in front?)" << endl;
		cout << "5 – SIZE    (How many people are there?)" << endl;
        cout << "6 – Clear the Queue" << endl;
		cout << "0 – to Exit" << endl;
		cout << "Enter a command? ";

		if (!(cin >> option)) {
			cout << "**** Please input a NUMBER between 0 and 6 ****" << endl << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		} else if (option < 0  || option > 6) {
			cout << endl;
			cout << "**** The number " << option << " is an invalid entry     ****" << endl;
			cout << "**** Please input a number between 0 and 6 ****" << endl << endl;
		} else {
			menu = MenuOptions(option);
			switch (menu) {
				case EXIT:
					invalid = true;
					cout << endl;
					break;
				case ENQUEUE:
					Enqueue(people);
					cout << endl;
					break;
				case DEQUEUE:
					Dequeue(people);
					cout << endl;
					break;
				case ISEMPTY:
					IsEmpty(people);
					cout << endl;
					break;
				case FRONT:
					Front(people);
					cout << endl;
					break;
				case SIZE:
					Size(people);
					cout << endl;
					break;
                case CLEARQUEUE:
                    ClearQueue(people);
                    cout << endl;
                    break;
			}
		}
    }
}

//This function prints the heading in the output
void PrintHeading() {
    const char PROGRAMMER[30] = "Natasha Lukmanto";
	const char CLASS[5] = "CS1B";
	const char SECTION[25] = "M-Th: 5:00p - 7:20p";
	const int LAB_NUM = 0 - 7;
	const char LAB_NAME[50] = "Lab #9A – Implementing a Queue";
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