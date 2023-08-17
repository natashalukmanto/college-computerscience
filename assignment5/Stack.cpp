#include "Stack.h"

StackList::StackList() {
    head = NULL;
    stackCount = 0;
}

StackList::~StackList() {
    DVDNode *dvdPtr = head;

    while (dvdPtr != NULL) {
        head = head -> next;
        delete dvdPtr;
        dvdPtr = head;
    }
}

void StackList::Push(DVDNode newDVD) {
    DVDNode *dvdPtr = new DVDNode;
    *dvdPtr = newDVD;

    dvdPtr -> next = head;
    head = dvdPtr;
}

DVDNode StackList::Pop() {
    DVDNode *dvdPtr;

    dvdPtr = head;
    head = dvdPtr -> next;
    delete dvdPtr;
    dvdPtr = NULL;

    return *head;
}

bool StackList::IsEmpty() const {
    return (head == NULL); 
}

DVDNode StackList::Peek() const {
    return *head -> next;
}

int StackList::Size() const {
    return stackCount;
}