/* 
 * Queue.h
 *
 * Description: Implementation of an template based Queue
 * Class Invariant: FIFO or LILO order
 *
 * Author: Michael Fischer 301310859
 * Date: Mar 17 2022
 */

/******* Start of Queue Public Interface *******/
// Class Invariant:  FIFO or LILO order
#include "Queue.h"
#include <iostream>

using namespace std;

// Private methods

// Description: Resizes elements array
// Postcondition: resizes elements array either allocating or deallocing heap memory
template <class ElementType>
void Queue<ElementType>::resize(ElementType* newElements){
    
    for (unsigned int i = 0; i < elementCount; i++){
        newElements[i] = elements[(i + frontIndex) % capacity];
    }

    delete [] elements;
    elements = newElements;
    frontIndex = 0;
    backIndex = elementCount;
    
}

// Description:  Constructor
// Postcondition: Creates dynamically stored memory
template <class ElementType>
Queue<ElementType>::Queue(): elementCount(0), capacity(INITIAL_CAPACITY), frontIndex(0), backIndex(0){
    elements = new ElementType[INITIAL_CAPACITY];
}

// Description: Destructor
// Postcondition: Deletes dynamically stored memory
template <class ElementType>
Queue<ElementType>::~Queue(){
    delete [] elements;
    elements = nullptr;
}

// Description: Inserts newElement at the "back" of this Queue 
//              (not necessarily the "back" of its data structure) and 
//              returns "true" if successful, otherwise "false".
// Time Efficiency: O(1)
template <class ElementType>
bool Queue<ElementType>::enqueue(ElementType& newElement){
    if (elementCount == capacity){
        ElementType* newElementsData = new ElementType[capacity*2];
        if (newElementsData == NULL) return false;
        resize(newElementsData);
        capacity *= 2;
        
    } 

    elementCount++;
    elements[backIndex] = newElement;
    backIndex = (backIndex + 1) % capacity;
    return true;
}

// Description: Removes (but does not return) the element at the "front" of this Queue 
//              (not necessarily the "front" of its data structure).
// Precondition: This Queue is not empty.
// Exception: Throws EmptyDataCollectionException if this Queue is empty.   
// Time Efficiency: O(1)
template <class ElementType>
void Queue<ElementType>::dequeue(){
    if (isEmpty())
        throw EmptyDataCollectionException("dequeue() failed as queue is empty.");
    
    if (elementCount <= capacity / 4 && capacity / 2  >= INITIAL_CAPACITY){
        ElementType* newElements = new ElementType[capacity/2];
        resize(newElements);
        capacity /= 2;
    }
    // elements[frontIndex] = 0;
    elementCount--;
    frontIndex = (frontIndex + 1) % capacity;
}
   
// Description: Returns (but does not remove) the element at the "front" of this Queue
//              (not necessarily the "front" of its data structure).
// Precondition: This Queue is not empty.
// Postcondition: This Queue is unchanged by this operation.
// Exception: Throws EmptyDataCollectionException if this Queue is empty.
// Time Efficiency: O(1)
template <class ElementType>
ElementType& Queue<ElementType>::peek() const{
    if (isEmpty())
        throw EmptyDataCollectionException("peek() failed as queue is empty.");
    return elements[frontIndex];
}

// Description: Returns "true" if this Queue is empty, otherwise "false".
// Postcondition: This Queue is unchanged by this operation.
// Time Efficiency: O(1)
template <class ElementType>
bool Queue<ElementType>::isEmpty() const{
    return elementCount == 0;
}

// Description: Prints the content of "this"
ostream& operator<<(ostream& os, const Queue<int>& rhs){
    cout << "front: " << rhs.frontIndex << "    back: " << rhs.backIndex << "    ";
    for (unsigned int i = 0; i < rhs.elementCount; i++){
        cout << rhs.elements[(i + rhs.frontIndex) % rhs.capacity] << " ";
    }
    cout << endl;
    return os;
}

 // end of Queue
/******* End of Queue Public Interface *******/

