/*
 * Name:
 * Date:
 * File: list.cpp
 * Description
 */
#include "list.h"
#include <iostream>
#include <cstring>

/*
 * Default List constructor.
 * Hint: set member variables to NULL.
 */
List::List()
{
	head = NULL;
	current = head;
}

/*
 * Destructor for the List.
 * This has already been implemented.
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
 * Hint: same concept as the C version.
 */
void List::addFirst(int num)
{
	Node *node = new Node(num);
	node->setNext(head);
	head = node;
	current = head;
}

/*
 * Resets the current to the head.
 * Hint: same concept as the C version.
 */
void List::reset()
{
	current = head;
}

/*
 * Retruns the current Node's data.
 */
Node* List::getCurItem()
{
    return current;
}

void List::setCur(Node* node) {
  current = node;
}

/*
 * Returns the head.
 */
Node* List::getHead()
{
    return head;
}
