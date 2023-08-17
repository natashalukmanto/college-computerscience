/**********************************************************************
 * AUTHOR		: Natasha Lukmanto
 * STUDENT ID	: 1253798
 * LAB #     	: Lab #14 - Inheritance, Overloading, Redefining
 * CLASS 		: CS 1B
 * SECTION 		: M-Th : 5p - 7:20p
 * DUE DATE 	: Sun Jul 30, 2023 11:59pm
**********************************************************************/

#include "header.h"
#include "animal.h"
#include "sheep.h"
#include "pig.h"
#include "functions.cpp"

int main() {
    const char PROGRAMMER[30] = "Natasha Lukmanto";
    const char CLASS[5] = "CS1B";
    const char SECTION[25] = "M-Th: 5:00p - 7:20p";
    const int LAB_NUM = 0 - 7;
    const char LAB_NAME[55] = "Lab #14 - Inheritance, Overloading, Redefining";
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

    int option = 1; bool invalid = true; Sheep sheep[3]; Pig pigs[3];

    while (option != 0) {
        cout << "1 - Initialize Animals" << endl;
        cout << "0 - Exit" << endl;
        cout << "Enter selection: ";

        if (!(cin >> option)) {
            cout << endl << "**** Please input a number between 0 and 1 ****" << endl << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        else if (option < 0 || option > 1) {
            cout << endl;
            cout << "**** The number " << option << " is an invalid entry     ****" << endl;
            cout << "**** Please input a number between 0 and 1 ****" << endl << endl;
        } else if (option == 1) {

            cout << "\nInitializing animals...\n\n";
            ifstream inFile;
            inFile.open("sheep.txt");
            string name_sheep, color;
            int age_sheep, wool_num;
            WoolType wool;

            for (int i = 0; i < 3; i++) {
                getline(inFile, name_sheep);
                inFile >> age_sheep;
                inFile >> wool_num;
                inFile.ignore(numeric_limits<streamsize>::max(), '\n');
                wool = static_cast<WoolType>(wool_num);
                getline(inFile, color);
                sheep[i].modify(name_sheep, age_sheep, wool, color);
            }
            inFile.close();

            inFile.open("pig.txt");
            string name_pig;
            int age_pig, tail_num;
            TailType tail;

            for (int i = 0; i < 3; i++) {
                getline(inFile, name_pig);
                inFile >> age_pig;
                inFile >> tail_num;
                inFile.ignore(numeric_limits<streamsize>::max(), '\n');
                tail = static_cast<TailType>(tail_num);
                pigs[i].modify(name_pig, age_pig, tail);
            }
            inFile.close();
            
            int option2; bool invalid2 = true;
            while (invalid2) {
                cout << "1 – Re-Initialize Sheep" << endl;
                cout << "2 – Re-Initialize Pigs" << endl;
                cout << "3 - Change Age" << endl;
                cout << "4 - Display" << endl;
                cout << "0 - Exit" << endl;
                cout << "Enter selection: ";

                if (!(cin >> option2)) {
                    cout << endl << "**** Please input a number between 0 and 4 ****" << endl << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
                else if (option2 < 0 || option2 > 4) {
                    cout << endl;
                    cout << "**** The number " << option2 << " is an invalid entry     ****" << endl;
                    cout << "**** Please input a number between 0 and 4 ****" << endl << endl;
                } else {
                    switch (option2) {
                        case 0:
                            invalid2 = false;
                            return 0;
                            break;
                        case 1:
                            cout << "\nInitializing sheep...\n\n";
                            inFile.open("sheep.txt"); 
                            for (int i = 0; i < 3; i++) {
                                getline(inFile, name_sheep);
                                inFile >> age_sheep;
                                inFile >> wool_num;
                                inFile.ignore(numeric_limits<streamsize>::max(), '\n');
                                wool = static_cast<WoolType>(wool_num);
                                getline(inFile, color);
                                sheep[i].modify(name_sheep, age_sheep, wool, color);
                            }
                            inFile.close();
                            break;
                        case 2:
                            cout << "\nInitializing pigs...\n\n";
                            inFile.open("pig.txt");
                            for (int i = 0; i < 3; i++) {
                                getline(inFile, name_pig);
                                inFile >> age_pig;
                                inFile >> tail_num;
                                inFile.ignore(numeric_limits<streamsize>::max(), '\n');
                                tail = static_cast<TailType>(tail_num);
                                pigs[i].modify(name_pig, age_pig, tail);
                            }
                            inFile.close();
                            break;
                        case 3:
                            break;
                        case 4:
                            sheep[0].DisplayTable();
                            pigs[0].DisplayTable();
                            break;
                    }
                }
            }
        } else {
            invalid = false;
            break;
        }
    }
    return 0;
}