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
	
	int temp;
	// We break down the number into individual pieces, we accomplish this
	// by finding mod 1000 first, which finds the first 3 digits then we 
	// advance by removing 3 peices by dividing by 1000. we can then store
	// temp in array list
	while(n > 0)
	{                
		temp = n%1000;
		n /= 1000; 
		list->addFirst(temp);
	}
}


bigInt::bigInt(const bigInt &big)
{
	
}

bigInt::~bigInt()
{

}

/*
 * Reads a string of digits from a given 
 * input stream
 */
void bigInt::readNumber(ifstream &in)
{

}

int bigInt::size()
{
	int size = 0;
	iter = new Iterator(list);
	while(iter->hasNext()) {
		size++;                           
	}
	return size;
}

void bigInt::printReverse()
{
	iter = new Iterator(list);
	int temp;
	bool first = true;
	// While we get each value, check to see if there are any leading
	// 0's that need to be printed. None are printed if its the first
	// iteration becasue its not needed.
	while(iter->hasNext()) {
		temp = iter->get()->getNum();
		if(!first && temp < 9) {
			cout << "00" << temp ;
		} else if (!first && temp < 99) {
			cout << "0" << temp;
		} else {
			cout << temp;
		}
		first = false;
		iter->advance();                             
	}
	cout<<endl;
}

void bigInt::print()
{
	printReverse();
}

bigInt bigInt::add(const bigInt &big2)
{	
	//bigInt big;
	int carry = 0;
	iter = new Iterator(list);
	Iterator* iter2 = new Iterator(this->getList());

	while(iter->hasNext() && iter2->hasNext()) {
		int num1 = iter->get()->getNum();
		int num2 = iter->get()->getNum();

		int result = num1 + num2 + carry;

		if(result >= 1000) {
			result -= 1000;
			carry = 1;
		} else {
			carry = 0;
		}
		this->getList()->addFirst(result);
		iter->advance();
		iter2->advance();               
	}
	return *this;	
	/*List* list2 = big2.getList();
	bigInt newBig = bigInt();
	List* newlist = newBig.getList();

	list2->reset();
	list->reset();

	while(list->getCurItem()->getNext() != NULL ||
				list2->getCurItem()->getNext() != NULL) {
		if(list->getCurItem() == NULL) {
			newlist->addFirst(list2->getCurItem()->getNum());
		} else if(list2->getCurItem() == NULL) {
			newlist->addFirst(list->getCurItem()->getNum());
		} else {
			newlist->addFirst(list2->getCurItem()->getNum() +
												list->getCurItem()->getNum());
		}
	}
	while(checkOverFlow(newlist)!=0) {};
	return newBig;
	*/
}

bigInt bigInt::operator+(const bigInt &big2)
{
	return add(big2);
}

bigInt bigInt::multiply(bigInt &big2)
{

}

List* bigInt::getList() {
	return list;
}

/*int bigInt::checkOverFlow(List* newlist){
	int count = 0;
	int temp = 0;
	newlist->reset();
	while(newlist->getCurItem()->getNext() != NULL) {
		if(newlist->getCurItem()->getNum() > 999) {
			temp = newlist->getCurItem()->getNum()/1000;
			newlist->getCurItem()->getNext()->setNum(
					newlist->getCurItem()->getNext()->getNum() + temp);
			newlist->getCurItem()->setNum(
					newlist->getCurItem()->getNum() - (temp*1000));
			count++;
		}
		newlist->setCur(newlist->getCurItem()->getNext());
	}
	return count;
}*/
