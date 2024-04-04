

#ifndef DENDED_QUEUE
#define DENDED_QUEUE

//#include "Node.h"
#include "LinkedQueue.h"

using namespace std;

template <typename T>
class DEndedQueue : public LinkedQueue<T>
{
public :
	DEndedQueue() : LinkedQueue() {};
	bool dequeue_back(T& backEntry);
	bool peek_back(T& backEntry)  const;
	bool enqueue_front(const T& newEntry);
};
/////////////////////////////////////////////////////////////////////////////////////////



#endif
//
//template <typename T>
//bool DEndedQueue<T>::dequeue_back(T& backEntry)
//{
//	if (isEmpty())
//		return false;
//
//	DoubleNode<T>* nodeToDeletePtr = backPtr;
//	backEntry = backPtr->getItem();
//	backEntry = backPtr->getPrevious();
//
//	if (backEntry)
//		backPtr->setNext(nullptr);
//
//	if (nodeToDeletePtr == frontPtr)	 // Special case: last DoubleNode in the queue
//		frontPtr = nullptr;
//
//	// Free memory reserved for the dequeued DoubleNode
//	delete nodeToDeletePtr;
//
//	return true;
//}
//
//template <typename T>
//bool DEndedQueue<T>::peek_back(T& backEntry) const
//{
//	if (isEmpty())
//		return false;
//
//	backEntry = backPtr->getItem();
//	return true;
//}
//
//template<typename T>
//inline bool DEndedQueue<T>::enqueue_front(const T& newEntry)
//{
//	DoubleNode<T>* newNodePtr = new DoubleNode<T>(newEntry);
//	// Insert the new DoubleNode
//	if (!isEmpty())	//special case if this is the first DoubleNode to insert
//	{
//		frontPtr->setPrevious(newNodePtr);
//	}
//
//	newNodePtr->setNext(frontPtr);
//
//	newNodePtr->setPrevious(nullptr);
//	frontPtr = newNodePtr; // The queue is empty
//
//
//	return true;
//}
