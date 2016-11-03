#ifndef NODE_H
#define NODE_H

class Node {
public:
    Node();
    Node(int);
    ~Node();

    Node* getNext();
    Node* getPrevious();
    void setPrevious(Node*);
    int getNum();
    void setNext(Node*);
    void setNum(int n);

private:
    int num;
    Node* next;
    Node* previous;
};

#endif
