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
	//Append items to the list 3 digits at a time to the end of the linked list
	while(n > 0)
	{
		list->addLast(n%1000);
		n = n/1000;
	}
}

// Copy constructor
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
	string line; 
	while (getline(in, line))
	{
		result += line; //checking to see if there are
	}					//multipule lines of numbers
	int i = result.length();
	while(i-3 > 0) { //
		list->addLast(atoi((result.substr(i-3,3).c_str())));
		i= i-3;
	}
	if(i-3<=0) {
		list->addLast(atoi((result.substr(0,i).c_str())));
	}
}

// returns how many elemnts are in the lnked list associated with this big int
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

// Recursive method to print bigInt
void bigInt::printReverse(Iterator *iter)
{
 	int num;
 	// are we at the end of the list yet? if so start back up the chain of 
 	// recursion
 	if (!iter->hasNext())
 	{	
 		first = true;
 		return;
 	}

 	num = iter->get()->getNum();	//Get what our number should be
 	iter->advance();				
 	printReverse(iter);				//Recursion
 	if(!first && num < 9) {			//is this the first number? if so leading
 		cout << "00" << num ;		//0's are not needed.
 	} else if (!first && num < 99) {
 		cout << "0" << num;
 	} else {
 		cout << num;
 	}
 	first = false;
}

// print method calls the reverse method, needed so iterator can be implemented
void bigInt::print()
{
	iter = new Iterator(list);
	printReverse(iter);
}

bigInt bigInt::add(const bigInt& big2)
{
	bigInt ret;
	int remainder = 0;			//In case a 1 needs to be carried
	int result = 0;
	iter = new Iterator(list);
	Iterator* iter2 = new Iterator(big2.getList());

	// While both lists have more in them
	while(iter->hasNext() || iter2->hasNext())
	{	
		// Do both lists have something? If they do we can add them
	 	if(iter->hasNext() && iter2->hasNext())
	 	{
	 		result = iter->get()->getNum() + iter2->get()->getNum()
	 				 + remainder;
	 		iter->advance();		
	 		iter2->advance();
	 	}
		else if(iter->hasNext())			//If the first list has more, just
	 	{									//add the remainer if there is any
	 		result = iter->get()->getNum() + remainder; //and carry over digits
	 		iter->advance();
	 	}
	 	else    // finally if list1 has nothing left check whatever is left
	 	{		// in list2 
	 		result = iter2->get()->getNum() + remainder;
	 		iter2->advance();
	 	}

	 	// If the result is over 1000, theres a remainder. Substract 1000 and
	 	// carry the one.
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
