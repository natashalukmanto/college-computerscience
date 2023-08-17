#ifndef STACK_H_
#define STACK_H_

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

struct DVDNode {
    string title; // store movie's title
    string leadingActor; // store leading actor/actress
    string supportingActor; // store supporting actor/actress
    string genre; // store movie’s genre
    string alternateGenre; // store movie’s alternate genre
    int year; // store movie’s release year
    int rating; // store movie’s rating
    string synopsis; // store movie’s synopsis
    DVDNode *next; // linked list next pointer
};

class StackList { // Base Class - Using linked list implementation
    public:
    /*********************************
    *** CONSTRUCTOR / DESTRUCTOR ****
    *********************************/
    StackList ();   // constructor
    ~StackList ();  //destructor

    /******************
    **** MUTATORS ****
    ******************/
    void Push(DVDNode newDVD);  // create a DVDNode, add a
                                // DVDNode in the stack, by adding
                                // to the front of the linked List
    DVDNode Pop();  // return the DVDNode in the top of
                    // the stack, remove the DVDNode
                    // from the stack, delete the DVDNode

    /******************
    **** ACCESSORS ****
    ******************/
    bool IsEmpty() const;   // check if stack is empty
    DVDNode Peek() const;   // return the DVDNode at the top of the stack
    int Size() const;       // return the number of people in the stack

    protected:
    DVDNode *head;          // head pointer for stack
    int stackCount;         // total number of persons in the stack
    };

#endif