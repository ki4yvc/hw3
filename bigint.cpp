/*
 * Name: Dylan Wilcox, Nicholas Gustafson
 * Date: November 3rd, 2016
 * File: bigint.cpp
 * Description:
 */

#include <iostream>
#include <cstring>
#include "bigint.h"
#include "list.h"
#include <fstream>
#include <string>
#include <cmath>

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



	// std::string s = to_string(n);
	// while(s.length() >= 3) {
	// 	list->addFirst(stoi(s.substr(s.length()-3)));
	// 	s = s.substr(0, s.length()-3);
	// }
	// if(s.length() > 0) {
	// 	list->addFirst(stoi(s));
	// }
}

bigInt::bigInt(const bigInt &big)
{
	list = new List();

}

void bigInt::readNumber(ifstream &in)
{

}

int bigInt::size()
{
	return list->getSize();
}

void bigInt::printReverse()
{
	bool first = true;
	int size = list->getSize();
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
			std::cout << printNum << ",";
			first = false;
		}else if(printNum > 9) {
			std::cout << "0" << printNum << ",";
		}else {
			std::cout << "00" << printNum << ",";
		}
		count++;
		count2 = size - count;
	}
	if(printNum > 99) {
		std::cout << printNum;
	}else if(printNum > 9) {
		std::cout << "0" << printNum;
	}else {
		std::cout << "00" << printNum;
	}

	// int first = list->getCurItem()->getNum();
	// if(first <= 9) {
	// 	std::cout << "00" << first << ",";
	// } else if(first <= 99) {
	// 	std::cout << "0" << first << ",";
	// } else {
	// 	std::cout << first << ",";
	// }
	// while(list->getCurItem() != NULL) {
	// 	std::cout << list->getCurItem()->getNum() << ",";
	// 	list->setCur(list->getCurItem()->getNext());
	// }
	// std::cout << std::endl;
}

void bigInt::print()
{
	printReverse();
}

bigInt* bigInt::add(bigInt &big2)
{
	List list2 = big2->getList();
	bigInt newBig = new bigInt();
	List newlist = newBig->getList();
	while(list->getCurItem()->getNext() != NULL &&
				list2->getCurItem()->getNext() != NULL) {
		list->setCur(list->getCurItem()->getNext());
		list2->setCur(list2->getCurItem()->getNext());
	}

	if(list->getCurItem() != list->getTail()) {
		First(newlist);
	} else if(list2->getCurItem() != list2->getTail()) {
		First(list2, newlist);
	}

	while(list->getCurItem()->getPrevious() != NULL &&
				list2->getCurItem()->getPrevious() != NULL) {
		newlist.addFirst(list->getCurItem()->getNum() +
											list2->getCurItem()->getNum());
		list->setCur(list->getCurItem()->getPrevious());
		list2->setCur(list2->getCurItem()->getPrevious());
	}

	while(checkOverFlow(newlist) != 0) { }

	return newlist;
}

bigInt* bigInt::operator+(bigInt &big2)
{

}

bigInt* bigInt::multiply(bigInt &big2)
{

}

List* bigInt::getList() {
	return list;
}

void bigInt::First(List* newlist) {
	int count = 0;
	while(list->getCurItem()->getNext() != NULL) {
		count++;
	}

	while(count > 0) {
		newlist->addFirst(list->getCurItem()->getNum());
		count--;
		list->setCur(list->getCurItem()->previous());
	}
}

void bigInt::First(List* list2, List* newlist) {
	int count = 0;
	while(list2->getCurItem()->getNext() != NULL) {
		count++;
	}

	while(count > 0) {
		newlist->addFirst(list2->getCurItem()->getNum());
		count--;
		list2->setCur(list2->getCurItem()->previous());
	}
}

int bigInt::checkOverFlow(List* newlist){
	int count = 0;
	int temp = 0;
	newlist->reset();
	while(newlist->getCurItem()->getNext()) {
		if(newlist->getCurItem()->getNum() > 999) {
			temp = newlist->getCurItem()->getNum()/1000;
			newlist->getCurItem()->getNext()->setNum(
					newlist->getCurItem()->getNext()->getNum() + temp);
			newlist->getCurItem()->setNum(
					newlist->getCurItem()->getNum() - (temp*1000));
			count++;
		}
	}
	return count;
}
