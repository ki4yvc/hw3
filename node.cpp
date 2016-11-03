/*
 * Name:
 * Date:
 * File: node.cpp
 * Description:
 */
#include "node.h"

#include <cstring>

/*
 * Default Node constructor.
 * Hint: the member variables need to be initialized to NULL.
 */
Node::Node()
{
	num = 0;
	next = NULL;
}

/*
 * Specialized constructor.
 * Hint: still need to initialize member variables, but one of them
 *       will be set to the constructor argument.
 */
Node::Node(int itm)
{
	num = itm;
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
 * Returns the Node's num.
 */
int Node::getNum()
{
    return num;
}

/*
 * Sets the Node's next variable.
 */
void Node::setNext(Node* n)
{
	next = n;
}

void Node::setNum(int n) {
	num = n;
}
