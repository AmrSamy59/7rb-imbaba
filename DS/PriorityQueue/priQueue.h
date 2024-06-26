#pragma once
#include "priNode.h"

using namespace std;
//This class impelements the priority queue as a sorted list (Linked List)
//The item with highest priority is at the front of the queue
template <typename T>

class priQueue
{
    priNode<T>* head;
    int Count;
public:
    priQueue() : head(nullptr) { Count = 0; }

    ~priQueue() {
        T tmp;
        int p;
        while (dequeue(tmp,p));
    }

    //insert the new node in its correct position according to its priority
    void enqueue(const T& data, int priority) {
        priNode<T>* newNode = new priNode<T>(data, priority);

        if (head == nullptr || priority > head->getPri()) {
            
            newNode->setNext(head);
            head = newNode;
            ++Count;
            return;
        }
       
        priNode<T>* current = head;        
        while (current->getNext() && priority <= current->getNext()->getPri()) {
            current = current->getNext();
        }
        newNode->setNext( current->getNext());
        current->setNext( newNode);  
        ++Count;
    }

    bool dequeue(T& topEntry, int& pri) {
        if (isEmpty())
            return false;

        topEntry = head->getItem(pri);
        priNode<T>* temp = head;
        head = head->getNext();
        delete temp;
        --Count;
        return true;
    }

    bool peek(T& topEntry, int& pri) {
        if (isEmpty())
            return false;

        topEntry = head->getItem(pri); //// Eng :eman it has mistake i have 10 hour to discover it please revise your work best regards (Eng: Amr hany)
        pri = head->getPri();
        return true;
    }

    bool isEmpty() const {
        return head == nullptr;
    }
    void Print() {
        if (head == NULL) {
            return;
        }
        else {
            priNode<T>* temp = head;
            while (temp->getNext()) {
                int pri = 0; // dummey var for the get item fun 
                cout << (temp->getItem(pri))<<", ";
                temp = temp->getNext();
            }
            int pri = 0; // dummey var for the get item fun 
            cout << (temp->getItem(pri));
        
        }
    }
    int GetCount() const {
        return Count;
    }
};
