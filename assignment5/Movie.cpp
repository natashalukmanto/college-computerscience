#include "Movie.h"
#include "Stack.h"

MovieList::MovieList() {}

MovieList::~MovieList() {}

void MovieList::CreateList(string inputFileName) {
    DVDNode *dvdPtr = new DVDNode;

    ifstream inFile;
    inFile.open(inputFileName.c_str());

    while (inFile) {
        getline(inFile, dvdPtr -> title);
        getline(inFile, dvdPtr -> leadingActor);
        getline(inFile, dvdPtr -> supportingActor);
        getline(inFile, dvdPtr -> genre);
        getline(inFile, dvdPtr -> alternateGenre);
        inFile >> dvdPtr -> year;
        inFile >> dvdPtr -> rating;
        inFile.ignore(10000, '\n');
        getline(inFile, dvdPtr -> synopsis);
        inFile.ignore(10000, '\n');

        cout << "Name: " << dvdPtr -> title << endl;

        Push(*dvdPtr);
    }
    delete dvdPtr;
    dvdPtr = NULL;
    inFile.close();
}

void MovieList::DisplayList(string outputFileName) const {
    DVDNode *dvdPtr = head;
    MovieList tempMovie;
    int count = 1;
    ofstream oFile;
    oFile.open(outputFileName.c_str(), ios::app);

    PrintHeader(oFile);

    cout << "\nWriting output file " << outputFileName << endl;

    while (dvdPtr != NULL) {
        oFile << "***************************************************************************\n";
        oFile << "MOVIE #:" << setw(2) << count << "        Title: " << TitleString(dvdPtr -> title) << endl;
        oFile << "---------------------------------------------------------------------------\n";
        oFile << "Year: " << dvdPtr -> year << "        Rating: " << dvdPtr -> rating << endl;
        oFile << "---------------------------------------------------------------------------\n";
        oFile << left << setw(18) << "Leading Actor:" << setw(25) << dvdPtr -> leadingActor << "Genre 1: " << dvdPtr -> genre << endl;
        oFile << setw(18) << "Supporting Actor:" << setw(25) << dvdPtr -> supportingActor << "Genre 2: " << dvdPtr -> alternateGenre << right << endl;
        oFile << "---------------------------------------------------------------------------\n";
        oFile << "PLOT:" << endl << WordWrap(dvdPtr -> synopsis) << endl;
        oFile << "***************************************************************************\n";
        oFile << endl << endl;

        count++;
        dvdPtr = dvdPtr -> next;
    }
    oFile.close();
}

string MovieList::WordWrap(string plot) const {
    const int MAX_CHAR = 75;

    ostringstream stream;
    string word = "", line = "";

    for (unsigned int i = 0; i < plot.length(); i++) {
        if (plot[i] != ' ') {
            word = word + plot[i];
        } else {
            if (line.length() + word.length() > MAX_CHAR) {
                stream << line << endl;
                line = "";
            }
            line = line + word+ ' ';
            word = "";
        }
    }

    stream << line;
    if (line.length() + word.length() > MAX_CHAR) {
        stream << endl;
    }
    stream << word;
    return stream.str();
}

string MovieList::TitleString(string title) const {
    const int MAX_CHAR = 50;

    if (title.length() > MAX_CHAR) {
        title = title.substr(0, MAX_CHAR - 3) + "...";
    }
    return title;
}

void MovieList::PrintHeader (ostream &oFile) const {
    const char PROGRAMMER[30] = "Natasha Lukmanto";
	const char CLASS[5] = "CS1B";
	const char SECTION[25] = "M-Th: 5:00p - 7:20p";
	const int LAB_NUM = 0 - 7;
	const char LAB_NAME[50] = "Assignment #5 - OOP - DVD Movie List";
	// OUTPUT – Class Heading
	oFile << left;
	oFile << "**************************************************";
	oFile << "\n* PROGRAMMED BY : " << PROGRAMMER;
	oFile << "\n* " << setw(14) << "CLASS" << ": " << CLASS;
	oFile << "\n* " << setw(14) << "SECTION" << ": " << SECTION;
	oFile << "\n* LAB #" << setw(9) << LAB_NUM << ": " << LAB_NAME;
	oFile << "\n**************************************************\n\n";
	oFile << right;
}