#include "Paint_board.h"
#include <iostream>
#include <fstream>
#include "LinkedList.h"
#include "Grid.h"
#include "Gridnode.h"
#include "Basenode.h"

using namespace std;

void Paint_board::Paint(Gridnode* head, LinkedList* List){

    int print_counter = 1;
    Gridnode* fake = head;  // use something that doesn't move head

    // decide weather the pen is up or down
    char up_down = 'u';

    // decide which character to start out with
    char character = '*';
    char pen_command;

    while (List != nullptr){

        char direc;     // get the direction we need to go
        direc = List->getDirection();
        pen_command = List->getPen();    // get the command from our structure

        int moving_spaces;
        moving_spaces = List->getSpaces();   // get the number of spaces we need to move


            // based on the command figure out if its bold or unbold
            if (pen_command =='B'){
                character = '#';
            }   else if (pen_command == 'b'){
                character = '*';
            }

            // based on the command figure find out if the pen is up or down
            if (pen_command == '1'){
                up_down = 'u';
            }   else if (pen_command == '2'){
                up_down = 'd';
            }

            if (pen_command == '4'){
                cout << "here is the " << print_counter << " time we are outputting" << endl;
                print_counter++;
                cout << head;
                cout << endl << endl;
            }

            // we start off with pen up so that means that they will have white spaces
            // based on the direction we need to move a certain way
            if (direc == 'S'){

                if (up_down == 'u'){
                    // just move don't print
                    for (int i = 0; i < moving_spaces; i++){
                        fake = fake->getDown();
                    }

                }   else {

                    // move and print
                    for (int i = 0; i < moving_spaces; i++){
                        fake = fake->getDown();

                        if (fake->getCharacter() == '#'){
                            // dont do anything
                        }   else {

                            fake->setCharacter(character);

                        }

                    }

                }

                // create an if statement for if the input is telling us to go east
            }   else if(direc == 'E'){

                if (up_down == 'u'){
                    // just move don't print
                    for (int i = 0; i < moving_spaces; i++){
                        fake = fake->getRight();
                    }

                }   else {

                    // move and print
                    for (int i = 0; i < moving_spaces; i++){
                        fake = fake->getRight();

                        if (fake->getCharacter() == '#'){
                            // dont do anything
                        }   else {

                            fake->setCharacter(character);

                        }

                    }

                }

                // create an if statement for if the input file tells us that it wants to go west
            }   else if(direc == 'W'){

                if (up_down == 'u'){
                    // just move don't print
                    for (int i = 0; i < moving_spaces; i++){
                        fake = fake->getLeft();
                    }

                }   else {

                    // move and print
                    for (int i = 0; i < moving_spaces; i++){
                        fake = fake->getLeft();

                        if (fake->getCharacter() == '#'){
                            // dont do anything
                        }   else {

                            fake->setCharacter(character);

                        }

                    }

                }

                // create an if statement to see if the input wants us to move up(north)
            }   else if(direc == 'N'){

                if (up_down == 'u'){
                    // just move don't print
                    for (int i = 0; i < moving_spaces; i++){
                        fake = fake->getUp();
                    }

                }   else {

                    // move and print
                    for (int i = 0; i < moving_spaces; i++){
                        fake = fake->getUp();

                        if (fake->getCharacter() == '#'){
                            // dont do anything
                        }   else {

                            fake->setCharacter(character);

                        }

                    }

                }

            }

        // move heads position over one so that we can get the next node in the list
        List = List->getNext();
        }
}
