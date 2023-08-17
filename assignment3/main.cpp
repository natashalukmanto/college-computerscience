#include "header.h"
#include "functions.cpp"

int main() {
    PrintHeading();
    ifstream inFile; ofstream outFile;
    string inFileName, outFileName; //IN – String inputs for the input file name and output file name.
    //PROCESSING: Taking inputs for the input file and output file.
    //Requirement #1: allow the user to specify an input and output files. 
    //Allow the user the option to use a default file.
    cout << "Which input file would you like to use(type d for default file)? ";
    cin >> inFileName;
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    if ( inFileName == "d") { inFileName = "inFile.txt"; }
    cout << "Which output file would you like to use(type d for default file)? ";
    cin >> outFileName;
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    if (outFileName == "d") { outFileName = "outFile.txt"; }

    inFile.open(inFileName.c_str());
    outFile.open(outFileName.c_str());

    int option; //IN – The user choose which option they want.
    bool valid = true; //VARIABLE – Keeps asking the user for a CORRECT INPUT & stops when EXIT.
    //PROCESSING: Ask user for which menu until EXIT.

    //VARIABLES associated with the functions
    string search_title, search_genre, search_actor; //IN – for the input string of the key string to be found.
    int search_rating, search_year; //IN – for the input integer of the number to be found.
    bool valid_year, valid_rating; //VAR – for the control loop variable in validating year and rating inputted.

    cout << endl << endl; 
    DVDs = CreateList(inFile);
    while (valid) {
        //Requirement #3: display a menu (see the screen output for specifics) -> loop until the user enters 0.
        cout << "DVD MENU OPTIONS" << endl << endl;
        cout << "1 - Output Entire List" << endl;
        cout << "2 - Title Search" << endl;
        cout << "3 - Genre Search" << endl;
        cout << "4 - Actor Search" << endl;
        cout << "5 - Year Search" << endl;
        cout << "6 - Rating Search (0-9)" << endl;
        cout << "0 - EXIT" << endl;
        cout << "Enter an option (0 to exit): ";

        if (!(cin >> option)) {
            cout << "**** Please input a NUMBER between 0 and 6 ****" << endl << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } else if (option < 0 || option > 6) {
            cout << "**** The number " << option << " is an invalid entry ****" << endl;
            cout << "**** Please input a number between 0 and 6 ****" << endl;
        } else {
            //PROCESSING: Prompt the corresponding function to program.
            menu = MenuOptions(option);
            switch (menu) {
                case EXIT:
                    valid = false;
                    cout << endl;
                    break;
                case OUTPUT:
                    OutputList(DVDs, outFile);
                    cout << endl;
                    break;
                case TITLE_SEARCH:
                    cout << endl << "Which title are you looking for? ";
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    getline(cin, search_title);
                    cout << endl << "Searching for the title " << search_title << endl;
                    SearchTitle(DVDs, search_title, outFile);
                    cout << endl;
                    break;
                case GENRE_SEARCH:
                    cout << endl << "Which genre are you looking for? ";
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    getline(cin, search_genre);
                    cout << endl << "Searching for the genre " << search_genre << endl;
                    SearchGenre(DVDs, search_genre, outFile);
                    cout << endl;
                    break;
                case ACTOR_SEARCH:
                    cout << endl << "Which actor are you looking for? ";
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    getline(cin, search_actor);
                    cout << endl << "Searching for the actor " << search_actor << endl;
                    SearchActor(DVDs, search_actor, outFile);
                    cout << endl;
                    break;
                case YEAR_SEARCH:
                    valid_year = false;
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    while (!valid_year) {
                        cout << endl << "Which year are you looking for? ";
                        if (!(cin >> search_year)) { 
                            cout << "**** Please input a NUMBER between 1878 and 3000 ****" << endl;
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        } 
                        else if (search_year < 1878 || search_year > 3000) {
                            cout << "**** The number " << search_year << " is an invalid entry ****" << endl;
                            cout << "**** Please input a number between 1878 and 3000 ****" << endl;
                        } else {
                            cout << endl << "Searching for the year " << search_year << endl;
                            SearchYear(DVDs, search_year, outFile);
                            valid = true;
                            break;
                        }
                    }
                    cout << endl;
                    break;
                case RATING_SEARCH:
                    valid_rating = false;
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    while (!valid_rating) {
                        cout << endl << "Which rating are you looking for? ";
                        if (!(cin >> search_rating)) { 
                            cout << "**** Please input a NUMBER between 0 and 9 ****" << endl;
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        } 
                        else if (search_rating < 1 || search_rating > 9) {
                            cout << "**** The number " << search_rating << " is an invalid entry ****" << endl;
                            cout << "**** Please input a number between 0 and 9 ****" << endl;
                        } else {
                            cout << endl << "Searching for the rating " << search_rating << endl;
                            SearchRating(DVDs, search_rating, outFile);
                            valid = true;
                            break;
                        }
                    }
                    cout << endl;
                    break;
            }
        }
    }
    inFile.close();
    outFile.close();
    
    return 0;
}