

#ifndef LINKED_QUEUE_
#define LINKED_QUEUE_

#include "Node.h"
#include "QueueADT.h"
#include <iostream>
using namespace std;
template <typename T>
class LinkedQueue:public QueueADT<T>
{
private :
	Node<T>* backPtr; // rear (backPtr)
	Node<T>* frontPtr; // frontPtr (frontPtr)
	int Count;
public :
	LinkedQueue();	
	bool isEmpty() const ;
	bool enqueue(const T& newEntry);
	bool dequeue(T& frntEntry);  
	bool peek(T& frntEntry)  const;	
	void Print();
	int GetCount() const;
	~LinkedQueue();
};
/////////////////////////////////////////////////////////////////////////////////////////
//
///*
//Function: Queue()
//The constructor of the Queue class.
//
//*/
//
template <typename T>
LinkedQueue<T>::LinkedQueue()
{
	Count = 0;
	backPtr=nullptr;
	frontPtr=nullptr;

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
	Node<T>* newNodePtr = new Node<T>(newEntry);
	// Insert the new Node
	if (isEmpty())	//special case if this is the first Node to insert
	{
		frontPtr = newNodePtr; // The queue is empty
	}
	else
	{
		backPtr->setNext(newNodePtr);
		// The queue was not empty
	}
	backPtr = newNodePtr; // New Node is the last Node now
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
bool LinkedQueue<T>::dequeue(T& frntEntry)  
{
	if(isEmpty())
		return false;

	Node<T>* nodeToDeletePtr = frontPtr;
	frntEntry = frontPtr->getItem();
	frontPtr = frontPtr->getNext();

	if (nodeToDeletePtr == backPtr)	 // Special case: last Node in the queue
		backPtr = nullptr;	

	// Free memory reserved for the dequeued Node
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
bool LinkedQueue<T>::peek(T& frntEntry) const 
{
	if(isEmpty())
		return false;

	frntEntry = frontPtr->getItem();
	return true;

}
///////////////////////////////////////////////////////////////////////////////////
template<typename T>
 void LinkedQueue<T>::Print()
{
	 if (frontPtr == NULL) {
		 return;
	 }
	 else
	 {
		 Node<T>* temp = frontPtr;
		 cout << temp->getItem();
		 while (temp->getNext())
		 {
			 cout <<", "<< temp->getNext()->getItem();
			 temp = temp->getNext();
		 }
	 }



}
 ///////////////////////////////////////////////////////////////////////////////////



 template<typename T>
 int LinkedQueue<T>::GetCount() const {
	 return Count;
 }


template <typename T>
LinkedQueue<T>::~LinkedQueue()
{
	//Note that the cout statements here is just for learning purpose
	//They should be normally removed from the destructor
	/*
	cout<<"\nStarting LinkedQueue destructor...";
	cout<<"\nFreeing all nodes in the queue...";
	*/
	//Free all nodes in the queue
	T temp;
	while(dequeue(temp));
		
	/*cout<<"\n Is LinkedQueue Empty now?? ==> "<<boolalpha<<isEmpty();
	cout<<"\nEnding LinkedQueue destructor..."<<endl;*/
}

#endif