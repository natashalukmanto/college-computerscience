#include "header.h"

//Requirement #5: he user should be able to search for a movie by title. Once found the movie title, the
//program should output all the information about the movie formatted as shown in the
//sample output. 
void SearchTitle(DVDNode* head, const string search_title, ofstream& outFile) {
    bool found = false;
    DVDNode* perPtr = head;
    while (!found && perPtr != NULL) {
        if (perPtr->title == search_title) {
            cout << "Found the movie " << search_title << "!";
            outFile << left;
            outFile << "***************************************************************************" << endl;
            outFile << "Title: " << perPtr->title << endl;
            outFile << "---------------------------------------------------------------------------" << endl;
            outFile << "Year: " << setw(12) << perPtr->year << "Rating: " << perPtr->rating << endl;
            outFile << "---------------------------------------------------------------------------" << endl;
            outFile << setw(18) << "Leading Actor:" << setw(30) << perPtr->leading_actor << "Genre 1: " << perPtr->genre << endl;
            outFile << setw(18) << "Supporting Actor:" << setw(30)<< perPtr->supporting_actor << "Genre 2: " << perPtr->alt_genre << endl;
            outFile << "---------------------------------------------------------------------------" << endl;
            outFile << "PLOT:" << endl;
            string wrappedPlot = perPtr->synopsis;
            WordWrap(wrappedPlot);
            outFile << wrappedPlot << endl;
            outFile << "***************************************************************************" << endl << endl << endl;
            outFile << right;
            found = true;
        } else {
            perPtr = perPtr->next;
        }
    }
    if (!found) {
        cout << "Sorry, the movie \"" << search_title << "\" was not found!";
    }
    cout << endl;
}

//Requirement #6: the user should be able to search for a movie by genre.
//All of these searches will be formatted similarly à see the output file for an example.
//-> For genre, the search should output all the movies that have that genre specified for
//either the genre or the alternate genre.
void SearchGenre(DVDNode* head, const string search_genre, ofstream& outFile) {
    bool found = false; int count = 1;
    DVDNode* perPtr = head;
    while (perPtr != NULL) {
        if (perPtr->genre == search_genre || perPtr->alt_genre == search_genre) {
            if (count == 1) {
                outFile << "Search by genre for " << search_genre << " found: " << endl;
                outFile << "MOVIE # " << "TITLE                                                        " << "YEAR " << "RATING " << "GENRE             " << "ALT GENRE         " << "LEAD ACTOR                     " << "SUPPORTING ACTOR    " << endl;
                outFile << "------- " << "------------------------------------------------------------ " << "---- " << "------ " << "----------------- " << "----------------- " << "------------------------------ " << "------------------- " << endl;
            }
            outFile << left;
            outFile << setw(8) << count << setw(61) << perPtr -> title << setw(5) << perPtr -> year << setw(7) << perPtr -> rating << setw(18) << perPtr -> genre << setw(18) << perPtr -> alt_genre  << setw(30) << perPtr -> leading_actor << setw(19) << perPtr -> supporting_actor << endl;
            outFile << right;

            count+=1;
            found = true;
        } perPtr = perPtr -> next;
    } 
    if (found) { cout << "Found "<< count-1 << " movies for the genre " << search_genre << "!" << endl; }
    else { cout << "Sorry, no movies for the genre, " << search_genre << " were found." << endl; }
    outFile << endl << endl;
}

//Requirement #6: the user should be able to search for a movie by actor.
//All of these searches will be formatted similarly à see the output file for an example.
//-> For actor, the search should output all of the movies that have the actor appear either
//in a leading or supporting role.
void SearchActor(DVDNode* head, const string search_actor, ofstream& outFile) {
    bool found = false; int count = 1;
    DVDNode* perPtr = head;
    while (perPtr != NULL) {
        if (perPtr->leading_actor == search_actor || perPtr->supporting_actor == search_actor) {
            if (count == 1) {
                outFile << "Search by actor for " << search_actor << " found: " << endl;
                outFile << "MOVIE # " << "TITLE                                                        " << "YEAR " << "RATING " << "GENRE             " << "ALT GENRE         " << "LEAD ACTOR                     " << "SUPPORTING ACTOR    " << endl;
                outFile << "------- " << "------------------------------------------------------------ " << "---- " << "------ " << "----------------- " << "----------------- " << "------------------------------ " << "------------------- " << endl;
            }
            outFile << left;
            outFile << setw(8) << count << setw(61) << perPtr -> title << setw(5) << perPtr -> year << setw(7) << perPtr -> rating << setw(18) << perPtr -> genre << setw(18) << perPtr -> alt_genre  << setw(30) << perPtr -> leading_actor << setw(19) << perPtr -> supporting_actor << endl;
            outFile << right;

            count+=1;
            found = true;
        } perPtr = perPtr -> next;
    } 
    if (found) { cout << "Found "<< count-1 << " movies for the actor " << search_actor << "!" << endl; }
    else { cout << "Sorry, no movies for the actor, " << search_actor << " were found." << endl; }
    outFile << endl << endl;
}

//Requirement #6: the user should be able to search for a movie by year.
//All of these searches will be formatted similarly à see the output file for an example.
//-> For year, the search should output all movies that were released that year.
void SearchYear(DVDNode* head, const int search_year, ofstream& outFile) {
    bool found = false; int count = 1;
    DVDNode* perPtr = head;
    while (perPtr != NULL) {
        if (perPtr->year == search_year) {
            if (count == 1) {
                outFile << "Search by year for " << search_year << " found: " << endl;
                outFile << "MOVIE # " << "TITLE                                                        " << "YEAR " << "RATING " << "GENRE             " << "ALT GENRE         " << "LEAD ACTOR                     " << "SUPPORTING ACTOR    " << endl;
                outFile << "------- " << "------------------------------------------------------------ " << "---- " << "------ " << "----------------- " << "----------------- " << "------------------------------ " << "------------------- " << endl;
            }
            outFile << left;
            outFile << setw(8) << count << setw(61) << perPtr -> title << setw(5) << perPtr -> year << setw(7) << perPtr -> rating << setw(18) << perPtr -> genre << setw(18) << perPtr -> alt_genre  << setw(30) << perPtr -> leading_actor << setw(19) << perPtr -> supporting_actor << endl;
            outFile << right;

            count+=1;
            found = true;
        } perPtr = perPtr -> next;
    } 
    if (found) { cout << "Found "<< count-1 << " movies for the year " << search_year << "!" << endl; }
    else { cout << "Sorry, no movies for the year, " << search_year << " were found." << endl; }
    outFile << endl << endl;
}

//Requirement #6: the user should be able to search for a movie by rating.
//All of these searches will be formatted similarly à see the output file for an example.
void SearchRating(DVDNode* head, const int search_rating, ofstream& outFile) {
    bool found = false; int count = 1;
    DVDNode* perPtr = head;
    while (perPtr != NULL) {
        if (perPtr->rating == search_rating) {
            if (count == 1) {
                outFile << "Search by rating for " << search_rating << " found: " << endl;
                outFile << "MOVIE # " << "TITLE                                                        " << "YEAR " << "RATING " << "GENRE             " << "ALT GENRE         " << "LEAD ACTOR                     " << "SUPPORTING ACTOR    " << endl;
                outFile << "------- " << "------------------------------------------------------------ " << "---- " << "------ " << "----------------- " << "----------------- " << "------------------------------ " << "------------------- " << endl;
            }
            outFile << left;
            outFile << setw(8) << count << setw(61) << perPtr -> title << setw(5) << perPtr -> year << setw(7) << perPtr -> rating << setw(18) << perPtr -> genre << setw(18) << perPtr -> alt_genre  << setw(30) << perPtr -> leading_actor << setw(19) << perPtr -> supporting_actor << endl;
            outFile << right;

            count+=1;
            found = true;
        } perPtr = perPtr -> next;
    } 
    if (found) { cout << "Found "<< count-1 << " movies for the rating " << search_rating << "!" << endl; }
    else { cout << "Sorry, no movies for the rating, " << search_rating << " were found." << endl; }
    outFile << endl << endl;
}

//Requirement #2: Using a structs and pointers, create a linked list of the movies in the input file 
//(you will need to write a function to create the linked list).
DVDNode* CreateList(ifstream& inFile) {
    DVDNode* head = NULL;
    DVDNode* perPtr = NULL;

    string line;
    while (getline(inFile, line)) {
        if (line.empty()) { continue;  /*Skip empty lines*/ }

        perPtr = new DVDNode;

        perPtr->title = line;
        getline(inFile, perPtr->leading_actor);
        getline(inFile, perPtr->supporting_actor);
        getline(inFile, perPtr->genre);
        getline(inFile, perPtr->alt_genre);
        inFile >> perPtr->year;
        inFile >> perPtr->rating;
        inFile.ignore(numeric_limits<streamsize>::max(), '\n');
        getline(inFile, perPtr->synopsis);
        inFile.ignore(numeric_limits<streamsize>::max(), '\n');

        perPtr->next = head;
        head = perPtr;
    }
    return head;
}

//Requirement #4: the user should be able to output the entire list of movies 
//-> write a function thatoutputs each movie one line at a time (not including the movie plot) 
//-> see the output file for an example 
void OutputList(DVDNode *head, ofstream &outFile) {
    DVDNode *perPtr = head; int count = 1;
    cout << endl << "Listing all movies!" << endl;
    outFile << "COMPLETE MOVIE LISTING" << endl;
    outFile << "MOVIE # " << "TITLE                                                        " << "YEAR " << "RATING " << "GENRE             " << "ALT GENRE         " << "LEAD ACTOR                     " << "SUPPORTING ACTOR    " << endl;
    outFile << "------- " << "------------------------------------------------------------ " << "---- " << "------ " << "----------------- " << "----------------- " << "------------------------------ " << "------------------- " << endl;
        
    while (perPtr != NULL) {
        outFile << left;
        outFile << setw(8) << count << setw(61) << perPtr -> title << setw(5) << perPtr -> year << setw(7) << perPtr -> rating << setw(18) << perPtr -> genre << setw(18) << perPtr -> alt_genre  << setw(30) << perPtr -> leading_actor << setw(19) << perPtr -> supporting_actor << endl;
        outFile << right;

        perPtr = perPtr -> next;
        count+=1;
    }
    outFile << endl << endl;
}

//Requirement #5: Format the output of the plot such that it will word wrap the string (you will
//need to write a function to implement this feature).
void WordWrap(string& plot) {
    const int MAX_WIDTH = 75;
    int pos = 0;

    while (pos + MAX_WIDTH < plot.length()) {
        int spacePos = plot.rfind(' ', pos + MAX_WIDTH);
        if (spacePos == string::npos || spacePos < pos) {
            // No space found within the width, insert a newline at the width limit
            plot.insert(pos + MAX_WIDTH, "\n");
            pos += MAX_WIDTH + 1;
        } else {
            // Insert a newline at the last space within the width
            plot[spacePos] = '\n';
            pos = spacePos + 1;
        }
    }
}

//This function prints the heading in the output.
void PrintHeading() {
    const char PROGRAMMER[30] = "Natasha Lukmanto";
	const char CLASS[5] = "CS1B";
	const char SECTION[25] = "M-Th: 5:00p - 7:20p";
	const int LAB_NUM = 0 - 7;
	const char LAB_NAME[50] = "Assignment #3 - Searching Linked Lists";
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