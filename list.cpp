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
        Node* cur = head;
        while(cur != NULL) {
            std::cout << "removing list item" << std::endl;
            Node* tmp = cur->getNext();
            delete cur;
            cur = tmp;
        }
    }
}

/*
 * Add a new Node to the head of the list.
 */
void List::addFirst(void* obj)
{
    Node* current = new Node(obj);
    current->setNext(head);
    //node->next = list->head;


    head = current;
    //list->head = node;

}

/*
 * Resets the current to the head.
 */
void List::reset()
{
    current = head;
}

/*
 * Retruns the current Node's data.
 */
void* List::getCurItem()
{
    return current->getItem();
}

/*
 * Returns the head.
 */
Node* List::getHead()
{
    return head;
}
