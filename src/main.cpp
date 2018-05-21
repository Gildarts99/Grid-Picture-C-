#include "Basenode.h"
#include "Gridnode.h"
#include "Grid.h"
#include "LinkedList.h"
#include "Paint_board.h"
#include <iostream>
#include <fstream>

using namespace std;



int main() {

    Gridnode *h = new Gridnode; // create the gridnode
    Grid G1;    // create the grid
    Paint_board P1;
    h = G1.getHead();   // set our head equal to the board so we can manipulate it

    // create a dynamic class
    LinkedList *LL = new LinkedList;

    LL = LL->get_and_order(LL); // make the linked list with all the stuff inside
    LL = LL->delete_head(LL);   // delete anything that makes the paint brush go out of bounds

    P1.Paint(h , LL);   // make the canvas and paint to it

    // print out the final product
    cout << "Here is the final product: " << endl;
    cout << h;

    ofstream output;
    output.open("paint.txt");  // create the output stream

    output << h;    // output the canvas to the output file

    output.close(); // close the output stream

    delete h;   // deallocate the memory
    delete LL;  // deallocate the memory

    return 0;
}

