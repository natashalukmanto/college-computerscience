#include "header.h"
#include "functions.cpp"

int main() {
    PrintHeading();
    ifstream inFile("inFile.txt");
    string name; char gender; int age; Person* foundNode;
    string name_search, name_remove;

    int choice; bool invalid = false;
    while (!invalid) {
        cout << "LIST MENU:" << endl;
        cout << "1 – Create List" << endl;
        cout << "2 – Display List" << endl;
        cout << "3 - Is the list empty?" << endl;
        cout << "4 - Search by name" << endl;
        cout << "5 - Remove Node" << endl;
        cout << "6 - Clear List" << endl;
        cout << "0 – to Exit" << endl;
        cout << "Enter a command (0 to exit): ";

        if (!(cin >> choice)) {
			cout << endl << "**** Please input a NUMBER between 0 and 6 ****" << endl << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		} else if (choice < 0  || choice > 6) {
			cout << endl;
			cout << "**** The number " << choice << " is an invalid entry     ****" << endl;
			cout << "**** Please input a number between 0 and 6 ****" << endl << endl;
		} else {
            menu = MenuOptions(choice);
            switch (menu) {
                case EXIT:
                    invalid = true;
                    cout << endl;
                    break;
                case CREATE:
                    cout << endl;
                    while (getline(inFile, name)) {
                        inFile.get(gender);
                        inFile >> age;
                        inFile.ignore(numeric_limits<streamsize>::max(), '\n');
                        CreateList(name, gender, age);
                    }
                    cout << endl;
                    break;
                case DISPLAY:
                    DisplayList();
                    cout << endl;
                    break;
                case ISEMPTY:
                    if (IsEmpty()) {
                        cout << endl << "Yes, the list is empty." << endl;
                    }
                    else {
                        cout << endl << "No, the list is NOT empty." << endl;
                    }
                    cout << endl;
                    break;
                case SEARCH:
                    if (IsEmpty()) {
                        cout << endl << "Can't search an empty list." << endl;
                    }
                    else {
                        cout << endl << "Who would you like to search for? ";
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        getline(cin, name_search);
                        foundNode = Search(name_search);
                        if (foundNode != nullptr) {
                            cout << endl << "Searching for " << foundNode->name << "..." << endl << endl;
                            cout << "Name: " << foundNode->name << endl;
                            cout << "Gender: " << foundNode->gender << endl;
                            cout << "Age: " << foundNode->age << endl;
                        }
                        else {
                            cout << endl << "Searching for " << name_search << "..." << endl << endl;
                            cout << "I'm sorry, \"" << name_search << "\" was NOT found!" << endl;
                        }
                    }
                    cout << endl;
                    break;
                case REMOVE:
                    if (IsEmpty()) {
                        cout << endl << "Can't remove from an empty list!" << endl;
                    }
                    else {
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        cout << endl << "Who would you like to remove? ";
                        getline(cin, name_remove);
                        Remove(name_remove);
                    } 
                    cout << endl;
                    break;
                case CLEAR:
                    Clear();
                    cout << endl;
                    break;
            }
        }
    }  
    return 0;
}