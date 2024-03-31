#pragma once
#include"DS/Queues/Node.h"
template<class T>
class DoubleNode:public Node<T>
{
private:
	T item; // A data item
	DoubleNode<T>* next; // Pointer to next DoubleNode
	DoubleNode<T>* prev; // Pointer to previous DoubleNode
public:
	DoubleNode();
	DoubleNode(const T& r_Item);
	DoubleNode(const T& r_Item, DoubleNode<T>* nextNodePtr, DoubleNode<T>* previousNodePtr);
	void setPrevious(DoubleNode<T>* nextNodePtr);
	DoubleNode<T>* getPrevious() const;
};

template < typename T>
DoubleNode<T>::DoubleNode()
{
	next = nullptr;
	prev = nullptr;
}

/////////////////////////////////////////////////////////////
///
/////////////////////////////////////////////////////////////

template < typename T>
DoubleNode<T>::DoubleNode(const T& r_Item)
{
	item = r_Item;
	next = nullptr;
	prev = nullptr;
}

/////////////////////////////////////////////////////////////
///
/////////////////////////////////////////////////////////////

template < typename T>
DoubleNode<T>::DoubleNode(const T& r_Item, DoubleNode<T>* nextNodePtr, DoubleNode<T>* previousNodePtr)
{
	item = r_Item;
	next = nextNodePtr;
	prev = previousNodePtr;
}

/////////////////////////////////////////////////////////////
///
/////////////////////////////////////////////////////////////

template < typename T>
void DoubleNode<T>::setPrevious(DoubleNode<T>* previousNodePtr)
{
	prev = previousNodePtr;
}

/////////////////////////////////////////////////////////////
///
/////////////////////////////////////////////////////////////
template < typename T>
DoubleNode<T>* DoubleNode<T>::getPrevious() const
{
	return prev;
}

