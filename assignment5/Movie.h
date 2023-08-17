#ifndef MOVIE_H_
#define MOVIE_H_

#include "Stack.h"

class MovieList : public StackList {
    public:
    /*********************************
    *** CONSTRUCTOR / DESTRUCTOR ****
    *********************************/
    MovieList();    // CONSTRUCTOR
    ~MovieList();   // DESTRUCTOR   

    void CreateList(string inputFileName);          // Method to create a linked list of movies from the given input file.
    void DisplayList(string outputFileName) const;  // Method to display the list of movies in the given output file.

    private:
    string WordWrap(string plot) const;         // Helper method to wrap the movie plot text to a specific width.
    string TitleString(string title) const;     // Helper method to truncate movie titles to a specific width.
    void PrintHeader (ostream &oFile) const;    // Helper method to print the header information in the output file.
};

#endif