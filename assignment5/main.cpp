/**************************************************
* PROGRAMMED BY : Natasha Lukmanto
* CLASS         : CS1B
* SECTION       : M-Th: 5:00p - 7:20p
* LAB #-7       : Assignment #5 - OOP - DVD Movie List
**************************************************/

#include "Header.h"
#include "Stack.h"
#include "Movie.h"

int main() {
    const char PROGRAMMER[30] = "Natasha Lukmanto";
	const char CLASS[5] = "CS1B";
	const char SECTION[25] = "M-Th: 5:00p - 7:20p";
	const int LAB_NUM = 0 - 7;
	const char LAB_NAME[50] = "Assignment #5 - OOP - DVD Movie List";
	// OUTPUT – Class Heading
	cout << left;
	cout << "**************************************************";
	cout << "\n* PROGRAMMED BY : " << PROGRAMMER;
	cout << "\n* " << setw(14) << "CLASS" << ": " << CLASS;
	cout << "\n* " << setw(14) << "SECTION" << ": " << SECTION;
	cout << "\n* LAB #" << setw(9) << LAB_NUM << ": " << LAB_NAME;
	cout << "\n**************************************************\n\n";
	cout << right;

    MovieList movie; // VAR – create an instance of the MovieList class
    string inFileName, outFileName; // IN – variables to store input and output file names

    //PROCESSING: Prompt user for input file name
    cout << "What input file would you like to use? ";
    getline(cin, inFileName);
    
    //PROCESSING: Prompt user for output file name
    cout << "What output file would you like to use? ";
    getline(cin, outFileName);

    cout << endl;
    
    movie.CreateList(inFileName);   //PROCESSING: Create the linked list of movies from the input file
    movie.DisplayList(outFileName); //PROCESSING: Display the list of movies in the output file

    return 0;
}