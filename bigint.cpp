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

bigInt::bigInt()
{
	list = new List();
}

bigInt::bigInt(int n)
{
	list = new List();
	int test = n;
	int count = 0;
	while(n > 999) {
		while(test > 999) {
			test = test/1000;
			count++;
		}
		list->addFirst(test);
		n = n - test*pow(1000,count);
		test = n;
		count = 0;
	}
	list->addFirst(n);
}

bigInt::bigInt(const bigInt &big)
{
	
}

void bigInt::readNumber(ifstream &in)
{

}

int bigInt::size()
{

}

void bigInt::printReverse()
{
	bool first = true;
	int size = 0;
	list->reset();
	while(list->getCurItem()->getNext() != NULL) {
		size++;
		list->setCur(list->getCurItem()->getNext());
	}
	int count = 0;
	int count2 = size;
	int printNum = list->getCurItem()->getNum();
	while(count2 != 1) {
		list->reset();
		while(count2 != 1) {
			list->setCur(list->getCurItem()->getNext());
			count2--;
		}
		printNum = list->getCurItem()->getNum();
		if(first || printNum > 99) {
			cout << printNum << ",";
			first = false;
		}else if(printNum > 9) {
			cout << "0" << printNum << " ";
		}else {
			cout << "00" << printNum << " ";
		}
		count++;
		count2 = size - count;
	}
	if(printNum > 99) {
		cout << printNum << endl;
	}else if(printNum > 9) {
		cout << "0" << printNum << endl;
	}else {
		cout << "00" << printNum << endl;
	}
}

void bigInt::print()
{
	printReverse();
}

bigInt bigInt::add(bigInt &big2)
{
	List* list2 = big2.getList();
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
}

bigInt bigInt::operator+(bigInt &big2)
{
	return add(big2);
}

bigInt bigInt::multiply(bigInt &big2)
{

}

List* bigInt::getList() {
	return list;
}

int bigInt::checkOverFlow(List* newlist){
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
}
