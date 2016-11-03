#ifndef NODE_H
#define NODE_H

class Node {
public:
    Node();
    Node(int);
    ~Node();

    Node* getNext();
    int getNum();
    void setNext(Node*);
    void setNum(int n);

private:
    int num;
    Node* next;
};

#endif
