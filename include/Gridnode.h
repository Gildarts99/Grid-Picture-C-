#ifndef GRIDNODE_H
#define GRIDNODE_H
#include "Basenode.h"
#include <iostream>
using namespace std;

class Gridnode: public Basenode
{
private:

    Gridnode *up;
    Gridnode *down;
    Gridnode *right;
    Gridnode *left;

public:
    Gridnode();
    ~Gridnode();

    //accessors
    Gridnode* getLeft(){return left;}
    Gridnode* getRight(){return right;}
    Gridnode* getUp(){return up;}
    Gridnode* getDown(){return down;}

    // mutator
    void setUp(Gridnode* );
    void setDown(Gridnode* );
    void setRight(Gridnode* );
    void setLeft(Gridnode* );

    //friend functions
    friend ostream &operator << (ostream&, Gridnode *);
};

#endif // GRIDNODE_H
