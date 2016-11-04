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
	//makebigInt* big = new bigInt();
	bigInt* big2 = new bigInt(23);
	bigInt big3(1000933);
	bigInt* big4 = new bigInt(1234);
	bigInt big5(12312789);

	big3.print();

	cout << endl;
	big5.print();

	cout << endl;
	bigInt big6(big3 + big5);
	big6.print();

}
