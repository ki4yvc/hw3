#ifndef BIGINT_H
#define BIGINT_H

#include "node.h"

class List {
public:
    List();
    ~List();

    void addFirst(void*);
    void reset();
    void* getCurItem();
    Node* getHead();

private:
    Node* head;
    Node* current;
};

#endif
