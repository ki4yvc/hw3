#ifndef LIST_H
#define LIST_H

#include "bigint.h"

class List {
public:
    List();
    ~List();

    void addFirst(bigInt*);
    void reset();
    bigInt* getCurItem();
    bigInt* getHead();

private:
    bigInt* head;
    bigInt* current;
};

#endif
