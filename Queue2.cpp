/* 
 * Queue.h
 *
 * Description: Implementation of an template based Queue
 * Class Invariant: FIFO or LILO order
 *
 * Author: Michael Fischer 301310859
 * Date: Mar 16 2022
 */

/******* Start of Queue Public Interface *******/
// Class Invariant:  FIFO or LILO order
#include "Queue.h"

// TODO: fix enqueue and dequque % capacity answers on midterm practice

// Private methods
template <class ElementType>
void Queue::doubleElements(ElementType* newElements){
    
    for (int i = 0; i < capacity; i++){
        newElements[i] = elements[(i + frontIndex) % capacity];
    }
    // for (int j = 0, i = frontindex; i < frontindex + capacity; i++, j++){
    //     newElements[j] = elements [i % capacity];
    // }
    delete [] elements;
    elements = newElements;
    frontIndex = 0;
    backIndex = elementCount;
    
}

// Description:  Constructor
// Postcondition: Creates dynamically stored memory
template <class ElementType>
Queue::Queue(): elementCount(0), capacity(INITIAL_CAPACITY), frontIndex(0), backIndex(0){
    elements = new ElementType[INITIAL_CAPACITY];
}

// Description: Destructor
// Postcondition: Deletes dynamically stored memory
template <class ElementType>
Queue::~Queue(){
    delete [] elements;
    elements = nullptr;
}

// Description: Inserts newElement at the "back" of this Queue 
//              (not necessarily the "back" of its data structure) and 
//              returns "true" if successful, otherwise "false".
// Time Efficiency: O(1)
template <class ElementType>
bool Queue::enqueue(ElementType& newElement){
    if (elementCount == capacity){
        ElementType* newElementsData = new ElementType[capacity*2];
        if (newElementsData == NULL) return false;
        doubleElements(newElementsData)
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
void Queue::dequeue(); 
    if (this->isEmpty())
        throw (EmptyDataCollectionException("dequeue() failed because queue is empty"));
    if (elementCount*4 <= capacity && capacity >= INITIAL_CAPACITY*2){
        int* newElements = new int[capacity/2];
        createNewElements(newElements);
        capacity /= 2;
    }
    elements[frontIndex] = 0;
    elementCount--;
    frontindex = (frontIndex + 1) % capacity;
}
// Description: Returns (but does not remove) the element at the "front" of this Queue
//              (not necessarily the "front" of its data structure).
// Precondition: This Queue is not empty.
// Postcondition: This Queue is unchanged by this operation.
// Exception: Throws EmptyDataCollectionException if this Queue is empty.
// Time Efficiency: O(1)
template <class ElementType>
ElementType& Queue::peek() const{
    return elements[frontIndex];
}
// Description: Returns "true" if this Queue is empty, otherwise "false".
// Postcondition: This Queue is unchanged by this operation.
// Time Efficiency: O(1)
// template <class ElementType>
bool Queue::isEmpty() const{
    return elementCount == 0;
}

 // end of Queue
/******* End of Queue Public Interface *******/

