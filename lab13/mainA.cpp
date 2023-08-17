/**********************************************************************
 * AUTHOR		: Natasha Lukmanto
 * STUDENT ID	: 1253798
 * LAB #     	: Lab #13 - Arrays of Sheep (OOP)
 * CLASS 		: CS 1B
 * SECTION 		: M-Th : 5p - 7:20p
 * DUE DATE 	: Mon Jun 24, 2023 11:59pm
**********************************************************************/

#include "headerA.h"

int main() {
    const char PROGRAMMER[30] = "Natasha Lukmanto";
    const char CLASS[5] = "CS1B";
    const char SECTION[25] = "M-Th: 5:00p - 7:20p";
    const int LAB_NUM = 0 - 7;
    const char LAB_NAME[55] = "Lab #13 - Arrays of Sheep (OOP)";
    // OUTPUT – Class Heading
    cout << left;
    cout << "**********************************************************************";
    cout << "\n* PROGRAMMED BY : " << PROGRAMMER;
    cout << "\n* " << setw(14) << "CLASS"
         << ": " << CLASS;
    cout << "\n* " << setw(14) << "SECTION"
         << ": " << SECTION;
    cout << "\n* LAB #" << setw(9) << LAB_NUM << ": " << LAB_NAME;
    cout << "\n**********************************************************************\n\n";
    cout << right;

    int option; bool invalid = true; FarmList manager;
    while (invalid) {
        cout << "*************************************\n";
        cout << "* WELCOME TO THE SHEEP LIST MANAGER *\n";
        cout << "*************************************\n\n";
        cout << "SHEEP LIST MANAGER\n";
        cout << "1 - Add Sheep\n";
        cout << "2 - Output 1st Sheep\n";
        cout << "3 - Find Sheep\n";
        cout << "4 - List Size\n";
        cout << "5 - Output List\n";
        cout << "6 - Clear List\n";
        cout << "0 - Exit\n";
        cout << "Enter a command: ";

        cin >> option;
        cin.clear(); cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << '\n';

        Sheep newSheep; string sheepName; int sheepAge; //for case 1
        Sheep firstSheep; //for case 2
        Sheep foundSheep; string findSheep; //for case 3
        switch (option) {
        case 0:
            invalid = false;
            break;
        case 1:
            cout << "Sheep Name: ";
            getline(cin, sheepName);
            cout << "Sheep Age: ";
            cin >> sheepAge;
            cin.clear(); cin.ignore(numeric_limits<streamsize>::max(), '\n');
            if (sheepAge < 0 || sheepAge > 9) {
                cout << "\nSheeps are never over 9 years of age!\n\n";
            } else {
                newSheep.SetInitialValues(sheepName, sheepAge);
                manager.AddSheep(newSheep);
                cout << "\nThe sheep...\n";
                cout << "Sheep Name: " << sheepName << endl;
                cout << "Sheep Age:  " << sheepAge << endl;
                cout << "Has been added!\n\n";
            }
            break;
        case 2:
            if (manager.TotalSheep() == 0) {
                cout << "Nobody is in front - the list is empty!\n\n";
            } else {
                firstSheep = manager.GetFirstSheep();
                cout << "NAME           AGE\n";
                cout << "-------------- ---\n";
                cout << left << setw(16) << firstSheep.GetName() << firstSheep.GetAge() << endl << endl;
            }
            break;
        case 3:
            if (manager.TotalSheep() == 0) {
                cout << "There are no sheep to be found!\n\n";
            } else {
                cout << "Who are you looking for? ";
                getline(cin, findSheep);
                foundSheep = manager.FindSheep(findSheep);
                cout << "\nNAME           AGE\n";
                cout << "-------------- ---\n";
                cout << left << setw(16) << foundSheep.GetName() << foundSheep.GetAge() << endl << endl;
                cout << right << "Has been found.\n\n";
            }
            break;
        case 4:
            if (manager.TotalSheep() == 0) {
                cout << "The list is empty!\n\n";
            } else {
                cout << "There are " << manager.TotalSheep() << " sheep in the list!\n\n";
            }
            break;
        case 5:
            if (manager.TotalSheep() == 0) {
                cout << "The list is empty!\n\n";
            } else {
                manager.DisplaySheepTable();
                cout << "There are " << manager.TotalSheep() << " sheep in the list!\n\n";
            }
            break;
        case 6:
            manager.ClearList();
            break;
        default:
            cout << "**** The number " << option << " is an invalid entry      ****\n";
            cout << "**** Please input a number between 0 and 6 ****\n\n";
            break;
        }
    }
}