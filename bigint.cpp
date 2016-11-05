/*
 * Name: Dylan Wilcox, Nicholas Gustafson
 * Date: November 3rd, 2016
 * File: bigint.cpp
 * Description: This is the main manager class for the list

 */

#include <iostream>
#include <cstring>
#include "bigint.h"
#include "list.h"
#include <fstream>
#include <string>
#include <cmath>
#include <cstdlib>
#include<sstream>


using namespace std;
/*
 *  Deafault Constructor
 *  Initializes only an empty list
 */
bigInt::bigInt()
{
	list = new List();
}

/*
 *
 */
bigInt::bigInt(int n)
{
	list = new List();
	while(n > 0)
	{
		list->addLast(n%1000);
		n = n/1000;
	}
}


bigInt::bigInt(const bigInt &big)
{
	list = new List();
	iter = new Iterator(this->getList());
	Iterator* newiter = new Iterator(list);
	while(iter->hasNext()) {
		Node* node = new Node(iter->get()->getNum());
		newiter->get()->setNext(node);
		iter->advance();
		newiter->advance();
	}
}

/*
 * Reads a string of digits from a given
 * input stream
 */
void bigInt::readNumber(ifstream &in)
{
	string result; //string to have all the ints
	int i = 0;
	string line;
	while (getline(in, line))
		result += line;
	while(result.length()>i+3) {
		list->addFirst(atoi((result.substr(i,i+3).c_str())));
		i+=3;
	}
	if(i+3 < result.length()) {
		list->addFirst(atoi((result.substr(i).c_str())));
	}
}

int bigInt::size()
{
	int size = 0;
	iter = new Iterator(list);
	while(iter->hasNext()) {
		size++;
		iter->advance();
	}
	return size;
}

void bigInt::printReverse(Iterator *iter)
{
 	int num;
 	first = false;
 	if (!iter->hasNext())
 	{
 		return;
 	}

 	num = iter->get()->getNum();
 	iter->advance();
 	printReverse(iter);
 	if(!first && num < 9) {
 		cout << "00" << num ;
 	} else if (!first && num < 99) {
 		cout << "0" << num;
 	} else {
 		cout << num;
 	}
}


void bigInt::print()
{
	iter = new Iterator(list);
	printReverse(iter);
}

bigInt bigInt::add(const bigInt& big2)
{
	bigInt ret;
	int remainder = 0;
	int result = 0;
	iter = new Iterator(list);
	Iterator* iter2 = new Iterator(big2.getList());

	while(iter->hasNext() || iter2->hasNext())
	{
	 	if(iter->hasNext() && iter2->hasNext())
	 	{
	 		result = iter->get()->getNum() + iter2->get()->getNum()
	 				 + remainder;
	 		iter->advance();
	 		iter2->advance();
	 	}
		else if(iter->hasNext())
	 	{
	 		result = iter->get()->getNum() + remainder;
	 		iter->advance();
	 	}
	 	else
	 	{
	 		result = iter2->get()->getNum() + remainder;
	 		iter2->advance();
	 	}

	 	if (result > 1000) {
	 		result -= 1000;
	 		remainder = 1;
	 	}
	 	else{remainder=0;}
	 	ret.getList()->addLast(result);
	 }

	 // if there is still a 1 that needs to be careied over, do it
	 if (remainder)
	 {
	 	ret.getList()->addLast(1);
	 }

	 return ret;

}

bigInt bigInt::operator+(const bigInt& big2)
{
	return add(big2);
}

List* bigInt::getList() const{
	return list;
}
