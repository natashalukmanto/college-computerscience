#ifndef _HEADER_H_
#define _HEADER_H_

#include <iostream>
#include <iomanip>
#include <fstream>
#include <ios>
#include <limits>
using namespace std;

//Data type MenuOptions for the menu to ask the user
enum MenuOptions {
    EXIT,           //0
    OUTPUT,         //1
    TITLE_SEARCH,   //2
    GENRE_SEARCH,   //3
    ACTOR_SEARCH,   //4
    YEAR_SEARCH,    //5
    RATING_SEARCH   //6
};
MenuOptions menu; //VARIABLE: menu is an enumerated data type of MenuOptions.

//Struct DVD with its members...
struct DVDNode {
    string title;
    string leading_actor;
    string supporting_actor;
    string genre;
    string alt_genre;
    int year;
    int rating;
    string synopsis;
    DVDNode *next;
};
DVDNode *DVDs; //VARIABLE: DVDs is a struct data type (linked list) of DVDNode.

//Prototypes

/*This function searches for a movie by title in a linked list of DVDs. 
It takes the head pointer, search title, and output file stream. 
It traverses the list, outputs the movie information 
if a match is found, and displays a "not found" message otherwise.

Parameters:
    head: A pointer to the head of the linked list representing the first node.
    search_title: A constant reference to a string representing 
                  the title of the movie to search for.
   outFile: A reference to an ofstream object representing the output file stream.

Return Type:
    void.
*/
void SearchTitle(DVDNode *head, const string search_title, ofstream& outFile);

/*This function searches for movies in a linked list based on the specified genre. 
Writes the information about matching movies to the output file.

Parameters:
    head: A pointer to the head of the linked list of DVDNode objects. 
          It represents the starting point of the linked list.
    search_genre: A constant reference to a string that specifies the genre to search for. 
                  It contains the genre for which movies will be searched.
    outFile: A reference to an ofstream object representing the output file stream. 
             It is used to write the information about matching movies to the output file.

Return Type:
    void.
*/
void SearchGenre(DVDNode* head, const string search_genre, ofstream& outFile);

/*This function searches for movies in a linked list based on the specified actor.
Writes the information about matching movies to the output file.

Parameters:
    head: A pointer to the head of the linked list of DVDNode objects.
          It represents the starting point of the linked list.
    search_actor: A constant reference to a string that specifies the actor to search for.
                  It contains the actor's name for which movies will be searched.
    outFile: A reference to an ofstream object representing the output file stream.
             It is used to write the information about matching movies to the output file.
    
Return Type:
    void.
*/
void SearchActor(DVDNode* head, const string search_actor, ofstream& outFile);

/*This function searches for movies in a linked list based on the specified year.
Writes the information about matching movies to the output file.

Parameters:
    head: A pointer to the head of the linked list of DVDNode objects.
          It represents the starting point of the linked list.
    search_year: An integer that specifies the year to search for.
                 It contains the year value for which movies will be searched.
    outFile: A reference to an ofstream object representing the output file stream.
             It is used to write the information about matching movies to the output file.
    
Return Type:
    void.
*/
void SearchYear(DVDNode* head, const int search_year, ofstream& outFile);

/*This function searches for movies in a linked list based on the specified rating.
Writes the information about matching movies to the output file.

Parameters:
    head: A pointer to the head of the linked list of DVDNode objects.
          It represents the starting point of the linked list.
    search_rating: An integer that specifies the rating to search for.
                   It contains the rating value for which movies will be searched.
    outFile: A reference to an ofstream object representing the output file stream.
             It is used to write the information about matching movies to the output file.
    
Return Type:
    void.
*/
void SearchRating(DVDNode* head, const int search_rating, ofstream& outFile);

/* This function creates a linked list of DVDNode objects by reading data from an input file. 
It reads the information for each DVD from the file and creates a new DVDNode object for each DVD. 
The function then links the newly created node to the existing linked list.

Parameters:
    inFile: An ifstream object representing the input file stream. 
    The function reads DVD information from this file.

Return Type:
    DVDNode*: A pointer to the head of the linked list, i.e., the first node in the list.
*/
DVDNode *CreateList(ifstream &inFile);

/*This function outputs the information stored in a linked list of DVDNode objects to an output file. 
It traverses the linked list starting from the head node and writes the DVD information 
for each node to the output file in a specific format.

Parameters:
    head: A pointer to DVDNode representing the head of the linked list. 
          It points to the first node in the list.
    outFile: An ofstream object representing the output file stream.
             The function writes the DVD information to this file.

Return Type:
    void.
*/
void OutputList(DVDNode *head, ofstream &outFile);

/*This function performs word wrapping for a given string of text. 
It ensures that each line of text does not exceed a maximum width of 75 characters. 
If a line exceeds the maximum width, it inserts newline characters 
at appropriate positions to wrap the text to the next line.

Parameters:
    plot: A reference to a string representing the text to be word wrapped.

Return Type:
    void.
*/
void WordWrap(string& plot);

//This function prints the heading in the output.
void PrintHeading();

#endif