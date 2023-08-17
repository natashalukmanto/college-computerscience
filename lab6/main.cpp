/***********************************************************
 * AUTHOR		: Natasha Lukmanto
 * STUDENT ID	: 1253798
 * LAB #     	: Lab #6 - Structs
 * CLASS 		: CS 1B
 * SECTION 		: M-Th : 5p - 7:20p
 * DUE DATE 	: Fri Jun 16, 2023 11:59pm
 **********************************************************/

#include "header.h"
#include "functions.cpp"

/***********************************************************
 *
 * Lab #6 - Structs
 *
 * _________________________________________________________
 * eceive from the user as input the name of an input file 
 * and an output file. 
 * 
 * It will then read in a list of:
 *  names,
 *  id #s, 
 *  and balances;
 * from the input file specified
 * and initialized the three parallel arrays. 
 * 
 * The program will execute some tasks using the parallel arrays. 
 * The user will interact with the program 
 * through menu that allows for the user to select the specific
 * tasks to be executed. 
 * _________________________________________________________
 *
 * INPUT:
 * 	inFile: a string of the input file
 *  outFile: a string of the output file
 *  menu_choice: an integer of the selected specific task
 * 
 * OUTPUT:
 *  total: total cost & 
 *  avg_cost: avg cost per kid
 *
 ***********************************************************/

int main() {
    ifstream inFile;
    ofstream outFile;
    string inFileName, outFileName;
    int option; string name; bool found = false;

    PrintHeading(cout);
    cout << left;
    cout << setw(40) << "What input file would you like to use?";
    getline(cin, inFileName);
    cout << setw(40) << "What output file would you like to use?";
    getline(cin, outFileName);

    inFile.open(inFileName.c_str());
    outFile.open(outFileName.c_str());

    PrintHeading(outFile);
    GetInput(AccountOwnersChase, inFile);

/* if needed: to check the array of inputs.
    for (int i = 0; i < 10; i++) {
        cout << names[i] << "\t" << endl;
        cout << ids[i] << "\t" << endl;
        cout << balances[i] << "\t";
    }
*/
    do {
        cout << endl;
        cout << "MENU OPTIONS" << endl << endl;
        cout << "1 - Find the larger balance" << endl;
        cout << "2 – Find the smaller balance" << endl;
        cout << "3 – Obtain the sum of all balances" << endl;
        cout << "4 – Obtain the average of all balances" << endl;
        cout << "5 – Find person" << endl;
        cout << "0 - Exit" << endl;
        cout << "Enter an option (0 to exit): ";
        cin >> option;
        
        switch (option) {
            case 1: 
                cout << endl << "Finding the larger balance..." << endl << endl;
                SearchBalance('L', AccountOwnersChase, outFile);
                break;
            case 2: 
                cout << endl << "Finding the smaller balance.." << endl << endl;
                SearchBalance('S', AccountOwnersChase, outFile);
                break;
            case 3: 
                cout << endl << "Obtaining the sum of all balances..." << endl << endl;
                SumOrAvg('S', AccountOwnersChase, outFile);
                break; 
            case 4: 
                cout << endl << "Obtaining the average of all balances..." << endl << endl;
                SumOrAvg('A', AccountOwnersChase, outFile);
                break;
            case 5: 
                cin.ignore(1000, '\n');
                do {
                    found = false;
                    cout << endl << "Who do you want to search for (enter done to exit): ";
                    getline(cin, name);
                    for (int i = 0; i < 10; i++) {
                        if (name == AccountOwnersChase[i].name) { 
                            cout << "Found." << endl;
                            SearchName(name, AccountOwnersChase, outFile);
                            found = true;
                        }
                    }
                    if (!found && name != "done") {
                            cout << name << " was not found." << endl;
                        } 
                } while (name != "done");
                cout << endl;
                break;
            case 0: 
                cout << endl << "Thank you for using my program." << endl << endl;
                break;
            default:
                cout << endl << "Invalid menu option." << endl << endl;
        }
    } while (option != 0);

    inFile.close();
    outFile.close();
}