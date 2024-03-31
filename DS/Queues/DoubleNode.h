#pragma once
#include "Node.h"

template <typename T>
class DoubleNode : public Node<T>
{
private:
	DoubleNode<T>* prev; // Pointer to previous DoubleNode
public:
	DoubleNode();
	DoubleNode(const T& r_Item);
	DoubleNode(const T& r_Item, DoubleNode<T>* nextNodePtr, DoubleNode<T>* previousNodePtr);
	void setPrevious(DoubleNode<T>* nextNodePtr);
	DoubleNode<T>* getPrevious() const;
};

template <typename T>
DoubleNode<T>::DoubleNode() : Node<T>()
{
	prev = nullptr;
}

template <typename T>
DoubleNode<T>::DoubleNode(const T& r_Item) : Node<T>(r_Item)
{
	prev = nullptr;
}

template <typename T>
DoubleNode<T>::DoubleNode(const T& r_Item, DoubleNode<T>* nextNodePtr, DoubleNode<T>* previousNodePtr) : Node<T>(r_Item, nextNodePtr)
{
	prev = previousNodePtr;
}


template <typename T>
void DoubleNode<T>::setPrevious(DoubleNode<T>* previousNodePtr)
{
	prev = previousNodePtr;
}

template <typename T>
DoubleNode<T>* DoubleNode<T>::getPrevious() const
{
	return prev;
}

