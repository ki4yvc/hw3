#ifndef BIGINT_H
#define BIGINT_H

#include <iostream>
#include <cstring>
#include "bigint.h"
#include "list.h"
#include <fstream>
#include <string>
#include <cmath>


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
    void print();
    bigInt* add(bigInt);
    bigInt* operator+(bigInt);
    bigInt* multiply(bigInt);
    List* getList();

private:
    List* list;
};

#endif
