#include "Gridnode.h"

Gridnode::Gridnode() {
    up = nullptr;
    down = nullptr;
    left = nullptr;
    right = nullptr;
}

Gridnode::~Gridnode() {
    up = nullptr;
    down = nullptr;
    left = nullptr;
    right = nullptr;
}

void Gridnode::setUp(Gridnode *u) {
    up = u;
}

void Gridnode::setDown(Gridnode *d) {
    down = d;
}

void Gridnode::setRight(Gridnode *r) {
    right = r;
}

void Gridnode::setLeft(Gridnode *l) {
    left = l;
}
