/*
 * Name: Dylan Wilcox Nicholas Gustafson
 * Date: 3 November 2016
 * File: list.cpp
 * Description: Contains all the opertions for our list
 */
#include "list.h"
#include <iostream>
#include <cstring>

/*
 * Default List constructor.
 */
List::List()
{
    head = NULL;
    current = NULL;
}

/*
 * Destructor for the List.
 */
List::~List()
{
    if(head != NULL) {
        bigInt* cur = head;
        while(cur != NULL) {
            std::cout << "removing list item" << std::endl;
            bigInt* tmp = cur->getNext();
            delete cur;
            cur = tmp;
        }
    }
}

/*
 * Add a new bigInt to the head of the list.
 */
void List::addFirst(bigInt* big)
{
    bigInt* current = new bigInt(big);
    current->setNext(head);

    head = current;

}

/*
 * Resets the current to the head.
 */
void List::reset()
{
    current = head;
}

/*
 * Retruns the current bigInt's data.
 */
bigInt* List::getCurItem()
{
    return current->getItem();
}

/*
 * Returns the head.
 */
bigInt* List::getHead()
{
    return head;
}
