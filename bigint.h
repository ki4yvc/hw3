#ifndef BIGINT_H
#define BIGINT_H

#include <iostream>
#include <cstring>
#include "bigint.h"
#include "list.h"
#include "iterator.h"
#include <fstream>
#include <string>
#include <cmath>

using namespace std;


class bigInt {
public:
	// Contructors
    bigInt();
    bigInt(int big);
    bigInt(const bigInt&);

    // required operators
    void readNumber(ifstream&);
    int size();
    void printReverse(Iterator*);
    void print();
    bigInt add(const bigInt&);
    bigInt operator+(const bigInt&);
    bigInt multiply(bigInt&);
    List* getList() const;
    int checkOverFlow(List*);

private:
    List* list;
    Iterator* iter;
    bool first;
};

#endif
