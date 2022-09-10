/* 
 * PriorityQueue.cpp
 * Class Invariant:  Always uses a minimum Binary Heap
 * 
 * Author: Michael Fischer 301310859
 *
 * Last Modification: March 25 2022
 *
 */  

#include "PriorityQueue.h"

// Default Constructor
template <class ElementType>
PriorityQueue<ElementType>::PriorityQueue(): elementCount(0){
    elements = new BinaryHeap<ElementType>();
}

// Destructor
// Postcondition: deletes heap allocated memory
template <class ElementType>
PriorityQueue<ElementType>::~PriorityQueue(){
    delete elements;
}

// Description: Returns "true" if this Priority Queue is empty, otherwise "false".
// Postcondition: This Priority Queue is unchanged by this operation.
// Time Efficiency: O(1)
template <class ElementType>
bool PriorityQueue<ElementType>::isEmpty() const{
    return elements->isEmpty();
}

// Description: Inserts newElement in this Priority Queue and 
//              returns "true" if successful, otherwise "false".
template <class ElementType>
bool PriorityQueue<ElementType>::enqueue(ElementType& newElement){
    return elements->insert(newElement); 
}

// Description: Removes (but does not return) the element with the next
//              "highest" priority value from the Priority Queue.
// Precondition: This Priority Queue is not empty.
// Exception: Throws EmptyDataCollectionException if Priority Queue is empty.
template <class ElementType>
void PriorityQueue<ElementType>::dequeue(){
    if (elements->isEmpty())
        throw(EmptyDataCollectionException("dequeue() failed as BinaryHeap is empty."));

    elements->remove();
}

// Description: Returns (but does not remove) the element with the next 
//              "highest" priority from the Priority Queue.
// Precondition: This Priority Queue is not empty.
// Postcondition: This Priority Queue is unchanged by this operation.
// Exception: Throws EmptyDataCollectionException if this Priority Queue is empty.
template <class ElementType>
ElementType& PriorityQueue<ElementType>::peek() const{
    if (elements->isEmpty())
        throw (EmptyDataCollectionException("peek() failed as BinaryHeap is empty."));

    return elements->retrieve();
    
}

// Description: printsPriorityQueue
template <class ElementType>
void PriorityQueue<ElementType>::printPriorityQueue() const{
    elements->printBinaryHeap();
}


