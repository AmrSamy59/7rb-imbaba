

#ifndef DENDED_QUEUE
#define DENDED_QUEUE

#include "DoubleNode.h"
#include "QueueADT.h"
#include <iostream>

using namespace std;

template <typename T>
class DEndedQueue
{
private:
	DoubleNode<T>* backPtr; // rear (backPtr)
	DoubleNode<T>* frontPtr; // frontPtr (frontPtr)
	int Count;
public :
	DEndedQueue();
	bool isEmpty() const;
	bool enqueue(const T& newEntry);
	bool dequeue(T& frntEntry);
	bool peek(T& frntEntry)  const;
	bool dequeue_back(T& backEntry);
	bool peek_back(T& backEntry) const;
	bool enqueue_front(const T& newEntry);
	void Print();
	int GetCount() const;
	~DEndedQueue();
};
/////////////////////////////////////////////////////////////////////////////////////////





template <typename T>
DEndedQueue<T>::DEndedQueue()
{
	backPtr = nullptr;
	frontPtr = nullptr;
	Count = 0;

}

///////////////////////////////////////////////////////////////////////////////////////////
//
/*
Function: isEmpty
Sees whether this queue is empty.

Input: None.
Output: True if the queue is empty; otherwise false.
*/
template <typename T>
bool DEndedQueue<T>::isEmpty() const
{
	return (frontPtr == nullptr);
}

/////////////////////////////////////////////////////////////////////////////////////////

/*Function:enqueue
Adds newEntry to the backPtr of the queue.

Input: newEntry .
Output: True if the operation is successful; false otherwise.
*/

template <typename T>
bool DEndedQueue<T>::enqueue(const T& newEntry)
{
	DoubleNode<T>* newNodePtr = new DoubleNode<T>(newEntry);
	// Insert the new DoubleNode
	if (isEmpty())	//special case if this is the first DoubleNode to insert
	{
		frontPtr = newNodePtr; // The queue is empty
	}
	else
	{
		backPtr->setNext(newNodePtr);
		newNodePtr->setPrevious(backPtr);
		// The queue was not empty
	}
	backPtr = newNodePtr; // New DoubleNode is the last DoubleNode now
	++Count;
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
bool DEndedQueue<T>::dequeue(T& frntEntry)
{
	if (isEmpty())
		return false;

	DoubleNode<T>* nodeToDeletePtr = frontPtr;
	frntEntry = frontPtr->getItem();
	frontPtr = frontPtr->getNext();

	if (frontPtr)
		frontPtr->setPrevious(nullptr);

	if (nodeToDeletePtr == backPtr)	 // Special case: last DoubleNode in the queue
		backPtr = nullptr;

	// Free memory reserved for the dequeued DoubleNode
	delete nodeToDeletePtr;
	--Count;
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
bool DEndedQueue<T>::peek(T& frntEntry) const
{
	if (isEmpty())
		return false;

	frntEntry = frontPtr->getItem();
	return true;

}

template <typename T>
bool DEndedQueue<T>::dequeue_back(T& backEntry)
{
	if (isEmpty())
		return false;

	DoubleNode<T>* nodeToDeletePtr = backPtr;
	backEntry = backPtr->getItem();
	backPtr = backPtr->getPrevious();

	if (backPtr)
		backPtr->setNext(nullptr);

	if (nodeToDeletePtr == frontPtr)	 // Special case: last DoubleNode in the queue
		frontPtr = nullptr;

	// Free memory reserved for the dequeued DoubleNode
	delete nodeToDeletePtr;
	--Count;
	return true;
}

template <typename T>
bool DEndedQueue<T>::peek_back(T& backEntry) const
{
	if (isEmpty())
		return false;

	backEntry = backPtr->getItem();
	return true;
}

template<typename T>
inline bool DEndedQueue<T>::enqueue_front(const T& newEntry)
{
	DoubleNode<T>* newNodePtr = new DoubleNode<T>(newEntry);
	// Insert the new DoubleNode
	if (isEmpty())	//special case if this is the first DoubleNode to insert
	{
		backPtr = newNodePtr;
	}
	else{
		newNodePtr->setNext(frontPtr);
		frontPtr->setPrevious(newNodePtr);
	}

	newNodePtr->setPrevious(nullptr);
	frontPtr = newNodePtr; // The queue is empty
	++Count;

	return true;
}

template<typename T>
 void DEndedQueue<T>::Print()
 {
	 if (frontPtr == NULL) {
		 return;
 }
	 else
	 {
		 DoubleNode<T>* temp = frontPtr;
		 while (temp->getNext()) {
			 cout << temp->getItem()<< " , ";
			 temp = temp->getNext();
		 }
		 cout << temp->getItem();
	 }

}

 template<typename T>
 int DEndedQueue<T>::GetCount() const {
	 return Count;
 }

template <typename T>
DEndedQueue<T>::~DEndedQueue()
{
	//Note that the cout statements here is just for learning purpose
	//They should be normally removed from the destructor
	//cout << "\nStarting DEndedQueue destructor...";
	//cout << "\nFreeing all nodes in the queue...";

	//Free all nodes in the queue
	T temp;
	while (dequeue(temp));
	/*
	cout << "\n Is DEndedQueue Empty now?? ==> " << boolalpha << isEmpty();
	cout << "\nEnding DEndedQueue destructor..." << endl;
	**/
	}

#endif