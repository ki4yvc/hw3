/*
 * Name: Dylan Wilcox Nicholas Gustafson
 * Date: 3 November 2016
 * File: node.cpp
 * Description: The class that controls each node in a linked list
 */
#include "node.h"

#include <cstring>

/*
 * Default Node constructor.
 * Hint: the member variables need to be initialized to NULL.
 */
Node::Node()
{
	item = NULL;
	next = NULL;
}

/*
 * Specialized constructor.
 * Hint: still need to initialize member variables, but one of them
 *       will be set to the constructor argument.
 */
Node::Node(void* itm)
{
	item = itm;
	next = NULL;
}

/*
 * Node Destructor
 */
Node::~Node()
{
    // left blank intentionally.
}

/*
 * Returns the next node.
 */
Node* Node::getNext()
{
    return next;
}

/*
 * Returns the Node's item.
 */
void* Node::getItem()
{
    return item;
}

/*
 * Sets the Node's next variable.
 */
void Node::setNext(Node* n)
{
	next = n;
}
