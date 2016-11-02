#ifndef BIGINT_H
#define BIGINT_H

#include <fstream.h>

class bigInt {
public:
	// Contructors
    bigInt();
    bigInt(int big);
    ~bigInt();

    // required operators
    void readNumber(ifstream);
    int size();
    void printReverse();
    void print()
    bigInt* add(bigInt);
    bigInt* operator+(bigInt);
    bigInt* multiply(bigInt);

    // List operators
    void setNext(bigInt*);
	bigInt* getItem();
    bigInt* getNext();

private:
    int big;
    bigInt* next;
};

#endif
