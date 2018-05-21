#include "Grid.h"
#include "Gridnode.h"
#include <iostream>

using namespace std;

Grid::Grid()
{

    Gridnode *r1, *r2, *p;

    //create first node on row 1
    r1 = new Gridnode;
    r1->setRow(1);
    r1->setColum(1);
    head = r1;

    //create rest of row 1
    for (int i = 2; i <= 50; i++ )
    {
        r2 = new Gridnode;

        //link left and right pointers
        r2->setLeft(r1);
        r1->setRight(r2);

        //initialize row and column
        r2->setRow(1);
        r2->setColum(i);

        //move r1 forward
        r1 = r2;
    }

    //reset r1 to beginning of row
    r1 = head;

    //create remaining rows
    for (int i = 2; i <= 50; i++)
    {
        r2 = new Gridnode;

        //link up and down
        r2->setUp(r1);
        r1->setDown(r2);

        //initialize row and column
        r2->setRow(i);
        r2->setColum(1);

        //move r1 down to hold beginning of row
        r1 = r2;

        //create rest of row
        for (int j = 2; j <= 50; j++)
        {
            p = new Gridnode;

            //initialize row and column
            p->setRow(i);
            p->setColum(j);

            //link to node on the left
            p->setLeft(r2);
            r2->setRight(p);

            //link to node above
            r2 = r2->getUp();
            r2 = r2->getRight();
            p->setUp(r2);
            r2->setDown(p);

            //move r2 forward
            r2 = p;
        }
    }

}

ostream &operator << (ostream &strm, Gridnode *head){

    // make a pointer we can manipulate
    Gridnode *fake = head;
    Gridnode *fake2 = nullptr;

    while (fake){
        fake2 = fake;
        fake = fake->getDown();

        while (fake2){
            strm << fake2->getCharacter();
            fake2 = fake2->getRight();
        }
        strm << endl;
    }
        return strm;
}

Grid::~Grid()
{
    // point to the upper left most grid node
    Gridnode *fake = head;
    Gridnode *fake2 = nullptr;  // used later
    Gridnode *current_node = nullptr;   // used later

    // go down the whole grid and deallocate the memory
    while (fake){
        fake2 = fake;
        fake = fake->getDown(); // move a pointer down a row to keep our grid available

        // while there are still grid nodes in the row deallocate their memory
        while (fake2){
            current_node = fake2;
            fake2 = fake2->getRight();
            current_node->setUp(nullptr);
            current_node->setDown(nullptr);
            current_node->setRight(nullptr);
            current_node->setLeft(nullptr);
        }
    }
    //delete head;
}
