

#ifndef LINKED_QUEUE_
#define LINKED_QUEUE_

#include "../../DoubleNode.h"
#include "QueueADT.h"
using namespace std;
template <typename T>
class LinkedQueue:public QueueADT<T>
{
private :
	DoubleNode<T>* tail; // rear (tail)
	DoubleNode<T>* head; // head (front)
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
	tail=nullptr;
	head=nullptr;

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
	return (head==nullptr);
}

/////////////////////////////////////////////////////////////////////////////////////////

/*Function:enqueue
Adds newEntry at the back of this queue.

Input: newEntry .
Output: True if the operation is successful; otherwise false.
*/

template <typename T>
bool LinkedQueue<T>::enqueue( const T& newEntry)
{
	DoubleNode<T>* newNodePtr = new DoubleNode<T>(newEntry);
	// Insert the new DoubleNode
	if (isEmpty())	//special case if this is the first DoubleNode to insert
	{
		head = newNodePtr; // The queue is empty
		newNodePtr->setPrevious(NULL);

	}
	else
	{
		tail->setNext(newNodePtr);
		newNodePtr->setPrevious(tail);

		
		// The queue was not empty
	}
	tail = newNodePtr; // New DoubleNode is the last DoubleNode now
	return true ;
} // end enqueue


/////////////////////////////////////////////////////////////////////////////////////////////////////////

/*Function: dequeue
Removes the front of this queue. That is, removes the item that was added
earliest.

Input: None.
Output: True if the operation is successful; otherwise false.
*/

template <typename T>
bool LinkedQueue<T>:: dequeue(T& frntEntry)  
{
	if(isEmpty())
		return false;

	DoubleNode<T>* nodeToDeletePtr = head;
	frntEntry = head->getItem();
	head = head->getNext();
	head->setPrevious(NULL);
	// Queue is not empty; remove front
	if (nodeToDeletePtr == tail)	 // Special case: last DoubleNode in the queue
		tail = nullptr ;	
	// Free memory reserved for the dequeued DoubleNode
	delete nodeToDeletePtr;

	return true;
}



/////////////////////////////////////////////////////////////////////////////////////////

/*
Function: peek
copies the front of this queue to the passed param. The operation does not modify the queue.

Input: None.
Output: The front of the queue.
*/

template <typename T>
bool LinkedQueue<T>:: peek(T& frntEntry) const 
{
	if(isEmpty())
		return false;

	frntEntry = head->getItem();
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