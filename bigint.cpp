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

using namespace std;
/*
 *  Deafault Constructor
 *  Initializes only an empty list
 */
bigInt::bigInt()
{
	list = new List();
	first = true;
}

/*
 *
 */
bigInt::bigInt(int n)
{
	list = new List();
	// We break down the number into individual pieces, we accomplish this
	// by finding mod 1000 first, which finds the first 3 digits then we
	// advance by removing 3 peices by dividing by 1000. we can then store
	// temp in array list
	while(n > 0)
	{
		list->addFirst(n%1000);
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
	string result;
	int i = 0;

	iter = new Iterator(list);

	string line;
	while (getline(in, line))
		result += line;

	while(result.length()>i+3) {
		Node* node = new Node(atoi(result.substr(i, i+3)));
		iter->get()->setNext(node);
		iter->advance();
		i+=3;
	}
	if(i < result.length()) {
		Node* node = new Node(atoi(result.substr(i)));
		iter->get()->setNext(node);
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
	int count, countholder;
	while(iter->hasNext()) {
		iter->advance();
		count++;
	}
	countholder = count;
	cout << iter->get()->getNum() << " ";

	while(countholder > 0) {
		iter->reset();
		while(count > 0) {
			iter->advance();
			count--;
		}
		num = iter->get()->getNum();
		if(num < 9) {
			cout << "00" << num ;
		} else if (!first && num < 99) {
			cout << "0" << num;
		} else {
			cout << num;
		}
		countholder--;
	}


// 	int num;
//
// 	if (!iter->hasNext())
// 	{
// 		return;
// 	}
// 	if (first)
// 	{
// 		first = false;
// 	}
// 	num = iter->get()->getNum();
// 	iter->advance();
// 	printReverse(iter);
// 	if(!first && num < 9) {
// 		cout << "00" << num ;
// 	} else if (!first && num < 99) {
// 		cout << "0" << num;
// 	} else {
// 		cout << num;
// 	}
// 	first = false;
// }


/*
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
	*/


void bigInt::print()
{
	iter = new Iterator(list);
	printReverse(iter);
}

bigInt bigInt::add(const bigInt& big2)
{
	bigInt* ret = new bigInt();
	int remainder = 0;
	iter = new Iterator(list);
	Iterator* iter2 = new Iterator(big2.getList());

	//int listSize = list->size();
	//int list2Size = big2->size();
	while(iter->hasNext() || iter2->hasNext()) {

		int num1, num2, result;

		if (iter->hasNext() && iter2->hasNext()/* && listSize == list2Size*/)
		{
			num1 = iter->get()->getNum();
			num2 = iter2->get()->getNum();
			cout << "num1 = " << num1 << endl;
			cout << "num2 = " << num2 << endl;
			result = num1 + num2 + remainder;

			//listSize--;
			//list2Size--;

			iter->advance();
			iter2->advance();
		}
		else if (iter->hasNext())
		{
			result = iter->get()->getNum() + remainder;
			iter->advance();
			//listSize--;
		}
		else
		{
			result = iter2->get()->getNum() + remainder;
			iter2->advance();
			//list2Size--;
		}

		// if(result >= 1000) {
		// 	result -= 1000;
		// 	remainder = 1;
		// } else {
		// 	remainder = 0;
		// }
		cout << "Result = " << result << endl;
		ret->getList()->addFirst(result);
	}
	while(checkOverFlow(ret->getList()) != 0) {}
	ret->print();

	return *ret;
}

bigInt bigInt::operator+(const bigInt& big2)
{
	return add(big2);
}

bigInt bigInt::multiply(bigInt &big2)
{

}

List* bigInt::getList() const{
	return list;
}

int bigInt::checkOverFlow(List* newlist){
	int count = 0;
	Iterator* iter = new Iterator(newlist);
	while(iter->hasNext()) {
		if(iter->get()->getNum() > 999) {
			iter->get()->setNum(iter->get()->getNum() - 1000);
			iter->advance();
			iter->get()->setNum(iter->get()->getNum() + 1);
			count++;
		}
	}
	if(iter->get()->getNum() > 999) {
		iter->get()->setNum(iter->get()->getNum() - 1000);
		Node* newNode = new Node(1);
		iter->get()->setNext(newNode);
	}
	return count;
}
