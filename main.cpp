/*
 * Name: Dylan Wilcox, Nicholas Gustafson
 * Date: November 3rd, 2016
 * File: main.cpp
 * Description: Driver class for bigInt Project
 */
#include <iostream>
#include "bigint.h"

int main()
{
	bigInt* big = new bigInt();
	bigInt* big2 = new bigInt(23);
	bigInt* big3 = new bigInt(129493);
	bigInt* big4 = new bigInt(1234);
	bigInt* big5 = new bigInt(123456789);

	big2->printReverse();
	big3->printReverse();
	big4->printReverse();
	big5->printReverse();
}
