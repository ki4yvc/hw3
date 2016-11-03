#ifndef LIST_H
#define LIST_H

#include "node.h"

class List {
public:
    List();
    ~List();

    void addFirst(int);
    void addLast(int);
    int getSize();
    void reset();
    Node* getCurItem();
    void setCur(Node *);
    Node* getHead();
    Node* getTail();

private:
    Node* head;
    Node* tail;
    Node* current;
    int size;
};

#endif
