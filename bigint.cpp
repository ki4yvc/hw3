/*
 * Name: Dylan Wilcox, Nicholas Gustafson
 * Date: November 3rd, 2016
 * File: bigint.cpp
 * Description:
 */

#include "bigint.h"

bigInt::bigInt()
{
	big = 000;
	next = NULL;
}

bigInt::bigInt(int big2)
{
	big = big2;
	next = NULL;
}

bigInt::bigInt(bigInt &big)
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

}

void bigInt::print()
{

}

bigInt* bigInt::add(bigInt &big2)
{

}

bigInt* bigInt::operator+(bigInt &big2)
{

}

bigInt* bigInt::multiply(bigInt &big2)
{

}

void setNext(bigInt &big2)
{

}