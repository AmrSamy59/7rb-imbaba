#ifndef _DNODE
#define _DNODE

template <typename T>
class DoubleNode
{
private:
	T item; // A data item
	DoubleNode<T>* next; // Pointer to next node
	DoubleNode<T>* prev; // Pointer to previous DoubleNode
public:
	DoubleNode();
	DoubleNode(const T& r_Item);
	DoubleNode(const T& r_Item, DoubleNode<T>* nextNodePtr);
	DoubleNode(const T& r_Item, DoubleNode<T>* nextNodePtr, DoubleNode<T>* previousNodePtr);
	void setItem(const T& r_Item);
	void setNext(DoubleNode<T>* nextNodePtr);
	T getItem() const;
	DoubleNode<T>* getNext() const;
	void setPrevious(DoubleNode<T>* nextNodePtr);
	DoubleNode<T>* getPrevious() const;
};

template <typename T>
DoubleNode<T>::DoubleNode()
{
	next = nullptr;
	prev = nullptr;
}

template <typename T>
DoubleNode<T>::DoubleNode(const T& r_Item)
{
	item = r_Item;
	prev = nullptr;
}

template <typename T>
DoubleNode<T>::DoubleNode(const T& r_Item, DoubleNode<T>* nextNodePtr)
{
	item = r_Item;
	next = nextNodePtr;
}

template <typename T>
DoubleNode<T>::DoubleNode(const T& r_Item, DoubleNode<T>* nextNodePtr, DoubleNode<T>* previousNodePtr)
{
	item = r_Item;
	next = nextNodePtr;
	prev = previousNodePtr;
}

template <typename T>
void DoubleNode<T>::setItem(const T& r_Item)
{
	item = r_Item;
}

template <typename T>
void DoubleNode<T>::setNext(DoubleNode<T>* nextNodePtr)
{
	next = nextNodePtr;
}

template <typename T>
T DoubleNode<T>::getItem() const
{
	return item;
}

template <typename T>
DoubleNode<T>* DoubleNode<T>::getNext() const
{
	return next;
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


#endif