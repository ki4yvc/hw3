#ifndef LIST_H
#define LIST_H

#include "node.h"

class List {
public:
    List();
    ~List();

    void addFirst(int);
    void addLast(int);
    void reset();
    Node* getCurItem();
    void setCur(Node *);
    Node* getHead();

private:
    Node* head;
    Node* current;
};

#endif
