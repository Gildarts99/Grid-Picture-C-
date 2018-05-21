#include "LinkedList.h"
#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

LinkedList::LinkedList()
{
    pen = ' ';
    direction = ' ';
    spaces = 0;
    next = nullptr;
}

LinkedList::~LinkedList()
{
    delete next;
    next = nullptr;
}

LinkedList* LinkedList::get_and_order(LinkedList* head){

    // open the input file
    fstream input("commands.txt", ios::in);

    while (!input.eof()){
        // create a newnode
        LinkedList* newNode = new LinkedList;

        // get all the other info for the newNode
        command(input, newNode);

        // if the linked list is empty
        if (head == nullptr){

            head = newNode;

        }   else {

            LinkedList* ptr1 = new LinkedList;
            //LinkedList* ptr2 = new LinkedList;

            ptr1 = head;
            //ptr2 = head->next;

            while (ptr1->next != nullptr){
                ptr1 = ptr1->next;
                //ptr2 = ptr2->next;
            }

            ptr1->next = newNode;
        }

    }

    input.close();

    return head;
}

// just used to see all out info
void LinkedList::testing(LinkedList* head){

    LinkedList* ptr1 = head;

    while (ptr1 != nullptr){
        cout << ptr1->getPen() << ",";
        cout << ptr1->getDirection() << ",";
        cout << ptr1->getSpaces() << endl;

        ptr1 = ptr1->next;

    }

}

void LinkedList::command(fstream &input, LinkedList* &trying){

    string line;    // get the whole line
    int spaces; // find number of spaces
    char p; // get what command it wants us to do
    char d; // get what direction the command wants us to go
    int string_length;  // gets how long the string we are manipulating is


    getline(input,line);    // get the whole line in the input file
    string_length = line.length();
    char* cstr = new char[string_length + 2];   // create a c string
    strcpy(cstr, line.c_str()); // copy the line into the c-string we made

    p = *cstr;  // get the command
    trying->setPen(p);  // put the command into its specific grid node

    // if pen is 3 than get all the other information
    if(p == '3'){

        cstr += 2;
        d = *cstr;  // gets the direction
        trying->setDirection(d);    // sets direction
        cstr += 2;
        spaces = atoi(cstr);    // gets how many spaces to move
        trying->setSpaces(spaces);  // sets how many spaces to move


    }   else {

        // auto sets the other information
        trying->setDirection(' ');
        trying->setSpaces(0);

    }
    // delete and deallocate the memory
    delete cstr;
    cstr = nullptr;
}

LinkedList* LinkedList::delete_head(LinkedList* &head){

    // create a pointer to point at head so we can manipulate head
    LinkedList* ptr1 = head;

    // create the same variables that we are using in our structure
    int space;
    char pen;
    char direct;

    // create integers to keep track of weather we are out of bounds or not
    int east_west = 0;
    int north_south = 0;

    // make a while loop to go all the way through the structure
    while (ptr1 != nullptr){

        // find out if the structure we are looking at makes us move or not
        pen = ptr1->getPen();

        if (pen == '3'){

            space = ptr1->getSpaces();  // get how many spaces the command wants us to move
            direct = ptr1->getDirection();  // gets the direction the command wants us to go

            if (direct == 'N'){

                // increment the north south counter
                north_south -= space;

                // if the north south counter is less than 0 or more than 50 than delete that node
                if (north_south < 0){

                    LinkedList* ptr2 = head;
                    LinkedList* hold = head->getNext();

                    // move hold to where it is in the ptr1 position
                    while (hold != ptr1){
                        ptr2 = ptr2->getNext();
                        hold = hold->getNext();
                    }

                    hold = hold->getNext(); // move hold over one list page

                    ptr2->setNext(hold);    // link the two ends together
                    ptr1->setNext(nullptr); // delete the command that would have taken us out of bounds

                    // reset the north south counter to what it was
                    north_south += space;

                    ptr1 = ptr2;    // move the pointer back into the list

                    //testing(head);
                }

            }   else if (direct == 'S'){

                // same thing as north
                north_south += space;

                if (north_south >= 50){

                    LinkedList* ptr2 = head;
                    LinkedList* hold = head->getNext();

                    while (hold != ptr1){
                        ptr2 = ptr2->getNext();
                        hold = hold->getNext();
                    }

                    hold = hold->getNext();

                    ptr2->setNext(hold);
                    ptr1->setNext(nullptr);

                    // reset the north south counter to what it was
                    north_south -= space;

                    ptr1 = ptr2;

                    //testing(head);
                }
            }


               else if (direct == 'E'){

                //same thing as north just for east and west
                east_west += space;

                if (east_west >= 50){



                    LinkedList* ptr2 = head;
                    LinkedList* hold = head->getNext();

                    while (hold != ptr1){
                        ptr2 = ptr2->getNext();
                        hold = hold->getNext();
                    }

                    hold = hold->getNext();

                    ptr2->setNext(hold);
                    ptr1->setNext(nullptr);

                    // reset the east west counter to what it was
                    east_west -= space;

                    ptr1 = ptr2;

                    //testing(head);

                }

            }   else if (direct == 'W'){

                // same thing as north just for east and west
                east_west -= space;

                if (east_west < 0){



                    LinkedList* ptr2 = head;
                    LinkedList* hold = head->getNext();

                    while (hold != ptr1){
                        ptr2 = ptr2->getNext();
                        hold = hold->getNext();
                    }

                    hold = hold->getNext();

                    ptr2->setNext(hold);
                    ptr1->setNext(nullptr);

                    // reset the east west counter to what it was
                    east_west += space;

                    ptr1 = ptr2;

                    //testing(head);

                }
            }
        }

        ptr1 = ptr1->next;  // move ptr1 over to the next command
    }

    return head;
}
