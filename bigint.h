#ifndef BIGINT_H
#define BIGINT_H

#include <iostream>
#include <cstring>
#include "bigint.h"
#include "list.h"
#include <fstream>
#include <string>
#include <cmath>

using namespace std;


class bigInt {
public:
	// Contructors
    bigInt();
    bigInt(int big);
    ~bigInt();
    bigInt(const bigInt&);

    // required operators
    void readNumber(ifstream&);
    int size();
    void printReverse();
    void print();
    bigInt add(bigInt&);
    bigInt operator+(bigInt&);
    bigInt multiply(bigInt&);
    List* getList();
    int checkOverFlow(List*);

private:
    List* list;

};

#endif
