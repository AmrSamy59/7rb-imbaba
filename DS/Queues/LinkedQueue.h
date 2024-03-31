

#ifndef LINKED_QUEUE_
#define LINKED_QUEUE_

#include "DoubleNode.h"
#include "QueueADT.h"
using namespace std;
template <typename T>
class LinkedQueue:public QueueADT<T>
{
private :
	DoubleNode<T>* backPtr; // rear (backPtr)
	DoubleNode<T>* frontPtr; // frontPtr (frontPtr)
public :
	LinkedQueue();	
	bool isEmpty() const ;
	bool enqueue(const T& newEntry);
	bool dequeue(T& frntEntry);  
	bool peek(T& frntEntry)  const;	
	~LinkedQueue();
};
/////////////////////////////////////////////////////////////////////////////////////////

/*
Function: Queue()
The constructor of the Queue class.

*/

template <typename T>
LinkedQueue<T>::LinkedQueue()
{
	backPtr=nullptr;
	frontPtr=nullptr;

}
/////////////////////////////////////////////////////////////////////////////////////////

/*
Function: isEmpty
Sees whether this queue is empty.

Input: None.
Output: True if the queue is empty; otherwise false.
*/
template <typename T>
bool LinkedQueue<T>::isEmpty() const
{
	return (frontPtr==nullptr);
}

/////////////////////////////////////////////////////////////////////////////////////////

/*Function:enqueue
Adds newEntry to the backPtr of the queue.

Input: newEntry .
Output: True if the operation is successful; false otherwise.
*/

template <typename T>
bool LinkedQueue<T>::enqueue( const T& newEntry)
{
	DoubleNode<T>* newNodePtr = new DoubleNode<T>(newEntry);
	// Insert the new DoubleNode
	if (isEmpty())	//special case if this is the first DoubleNode to insert
	{
		frontPtr = newNodePtr; // The queue is empty
		newNodePtr->setPrevious(nullptr);
	}
	else
	{
		backPtr->setNext(newNodePtr);
		newNodePtr->setPrevious(backPtr);
		// The queue was not empty
	}
	backPtr = newNodePtr; // New DoubleNode is the last DoubleNode now

	return true;
} // end enqueue


/////////////////////////////////////////////////////////////////////////////////////////////////////////

/*Function: dequeue
Removes the frontPtr of this queue. That is, removes the item that was added
earliest.

Input: None.
Output: True if the operation is successful; otherwise false.
*/

template <typename T>
bool LinkedQueue<T>::dequeue(T& frntEntry)  
{
	if(isEmpty())
		return false;

	DoubleNode<T>* nodeToDeletePtr = frontPtr;
	frntEntry = frontPtr->getItem();
	frontPtr = frontPtr->getNext();

	if(frontPtr)
		frontPtr->setPrevious(nullptr);

	if (nodeToDeletePtr == backPtr)	 // Special case: last DoubleNode in the queue
		backPtr = nullptr;	

	// Free memory reserved for the dequeued DoubleNode
	delete nodeToDeletePtr;

	return true;
}



/////////////////////////////////////////////////////////////////////////////////////////

/*
Function: peek
copies the frontPtr of this queue to the passed param. The operation does not modify the queue.

Input: None.
Output: The frontPtr of the queue.
*/

template <typename T>
bool LinkedQueue<T>::peek(T& frntEntry) const 
{
	if(isEmpty())
		return false;

	frntEntry = frontPtr->getItem();
	return true;

}
///////////////////////////////////////////////////////////////////////////////////

template <typename T>
LinkedQueue<T>::~LinkedQueue()
{
	//Note that the cout statements here is just for learning purpose
	//They should be normally removed from the destructor
	cout<<"\nStarting LinkedQueue destructor...";
	cout<<"\nFreeing all nodes in the queue...";

	//Free all nodes in the queue
	T temp;
	while(dequeue(temp));
	
	cout<<"\n Is LinkedQueue Empty now?? ==> "<<boolalpha<<isEmpty();
	cout<<"\nEnding LinkedQueue destructor..."<<endl;
}

#endif