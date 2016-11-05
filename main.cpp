/*
 * Name: Dylan Wilcox, Nicholas Gustafson
 * Date: November 3rd, 2016
 * File: main.cpp
 * Description: Driver class for bigInt Project
 */
#include <iostream>
#include "bigint.h"
#include <fstream>
#include <cstdlib>


int main()
{	
	// Declaring our big ints
	bigInt big1(23);
	bigInt big2(2400054);
	bigInt big3(56075933);
	bigInt big4(679802844);
	bigInt big5(500000000);

	// Proof of printing
	cout << "----------Print Statements---------- " << endl;
	cout << "big1: ";
	big1.print();
	cout << endl;
	cout << "big2: ";
	big2.print();
	cout << endl;
	cout << "big3: ";
	big3.print();
	cout << endl;
	cout << "big4: ";
	big4.print();
	cout << endl;
	cout << "big5: ";
	big5.print();
	cout << endl;
	cout << endl;

	cout << "----------BigInt Addition-----------" << endl;
	cout << "big1 + big2: ";
	bigInt add1(big1 + big2);
	add1.print();
	cout << endl;
	cout << "big3 + big4: ";
	bigInt add2(big3 + big4);
	add2.print();
	cout << endl;
	cout << "big4 + big5: ";
	bigInt add3(big4 + big5);
	add3.print();
	cout << endl;
	cout << endl;


	cout << "----------Input From File-----------" << endl;
	cout << "opening input.txt" << endl;
	bigInt* big = new bigInt();
	ifstream in;
	in.open("input.txt");
	big->readNumber(in);
	cout << "input.txt = ";
	big->print();

	cout<<endl;

}
