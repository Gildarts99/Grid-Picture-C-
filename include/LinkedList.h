#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <iostream>
#include <fstream>
#include <string>

using namespace std;


class LinkedList
{
public:
    LinkedList();   // constructor
    ~LinkedList();  // destructor

    // accessors
    char getPen() const {return pen;}
    char getDirection() const {return direction;}
    int getSpaces() const {return spaces;}
    LinkedList* getNext() const {return next;}

    // mutators
    void setPen(char p) {pen = p;}
    void setDirection(char d) {direction = d;}
    void setSpaces(int s) {spaces = s;}
    void setNext(LinkedList *n) {next = n;}

    // functions associated with the linked list
    LinkedList* get_and_order(LinkedList*);   //orders linked list
    void command(fstream &,LinkedList*&); // get all the info for the linked list
    void testing(LinkedList*);  //test to see that i got all the commands
    LinkedList* delete_head(LinkedList*&);   // prototype to deleting structures

private:

    char pen; // need a character to keep track of what the pen is supposed to do
    char direction; // need a character to get the direction if need be from the input file
    int spaces; // need an integer to get the number of spaces if need be that we are supposed to move

    LinkedList* next = nullptr; // change to nullptr

};

#endif // LINKEDLIST_H
