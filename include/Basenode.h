#ifndef BASENODE_H
#define BASENODE_H


class Basenode
{
private:
    int row;
    int column;
    char character;

public:

    Basenode(); // constructor
    Basenode(int, int, char);   // overloaded constructor
    virtual ~Basenode();

    // accessors
    int getRow(){return row;}
    int getColumn(){return column;}
    char getCharacter(){return character;}

    // mutators
    void setRow(int r){row = r;}
    void setColum(int c){column = c;}
    void setCharacter(char ch){character = ch;}
};

#endif // BASENODE_H
