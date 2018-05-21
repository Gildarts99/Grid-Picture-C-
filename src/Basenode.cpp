#include "Basenode.h"

Basenode::Basenode()
{
    row = 0;
    column = 0;
    character = ' ';
}

Basenode::Basenode(int r, int c, char ch){
    row = r;
    column = c;
    character = ch;
}

Basenode::~Basenode()
{
    // nothing to delete
}
