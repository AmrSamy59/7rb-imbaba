

#ifndef DENDED_QUEUE
#define DENDED_QUEUE

#include "DoubleNode.h"
#include "LinkedQueue.h"

using namespace std;

template <typename T>
class DEndedQueue : public LinkedQueue<T>
{
public :
	DEndedQueue() : LinkedQueue() {};
	bool dequeue_back(T& backEntry);
	bool peek_back(T& backEntry)  const;
};
/////////////////////////////////////////////////////////////////////////////////////////



#endif

template <typename T>
bool DEndedQueue<T>::dequeue_back(T& backEntry)
{
	if (isEmpty())
		return false;

	DoubleNode<T>* nodeToDeletePtr = backPtr;
	backEntry = backPtr->getItem();
	backEntry = backPtr->getPrevious();

	if (backEntry)
		backPtr->setNext(nullptr);

	if (nodeToDeletePtr == frontPtr)	 // Special case: last DoubleNode in the queue
		frontPtr = nullptr;

	// Free memory reserved for the dequeued DoubleNode
	delete nodeToDeletePtr;

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
