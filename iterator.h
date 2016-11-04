#ifndef ITERATOR_H
#define ITERATOR_H

#include "list.h"
#include "node.h"

class Iterator {
public:
    Iterator();
    Iterator(List*);
    ~Iterator();

    void advance();
    bool hasNext();
    Node* get();
    void reset();

private:
    List* list;
    Node* current;
};

#endif
