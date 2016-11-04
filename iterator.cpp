#include "iterator.h"

#include <cstring>

/*
 * Default Iterator constructor.
 * Hint: set all member variables to NULL.
 */
Iterator::Iterator()
{
	list = new List();
	current = new Node();
}

/*
 * Specialized Iterator constructor.
 * Hint: Use the constructor argument to initialize the Iterator.
 */
Iterator::Iterator(List* l)
{
	list = l;
	current = list->getHead();
}

/*
 * Iterator destructor.
 */
Iterator::~Iterator()
{
    // left blank intentionally.
}

/*
 * Advances the iterator to the Node's next.
 * Hint: same concept as the C version.
 */
void Iterator::advance()
{
	current = current->getNext();
}

/*
 * Returns true if the current Node's next is not NULL.
 * Hint: similar to C version, except we are looking at
 * the current's next not current.
 */
bool Iterator::hasNext()
{
    if(current)
    {
    	return true;
    }
    else
    {
    	return false;
    }
}

/*
 * Returns the current Node.
 */
Node* Iterator::get()
{
    return current;
}

void Iterator::reset() {
	current = list->getHead();
}
