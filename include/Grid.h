#ifndef GRID_H
#define GRID_H
#include "Gridnode.h"
#include <iostream>

using namespace std;

//class Gridnode;

class Grid : public Gridnode
{
private:

    Gridnode *head;

public:
    Grid(); //constructor
    Grid(Gridnode* &G){head = G;}   // overloaded constructor
    ~Grid();    // deconstructor

    Gridnode* getHead(){return head;}
    void setHead(Gridnode* &G){head = G;}


};

#endif // GRID_H
