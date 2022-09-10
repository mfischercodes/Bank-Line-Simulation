/* 
 * Queue.cpp
 *
 * Description: Implementation of an int sequence with enqueue/dequeue ...
 * Class Invariant: ... in FIFO order using a circular array
 *
 * Author: Michael Fischer 301310859
 * Date: Feb 18 2022
 */
 
#include "QueueRef.h"


// private method
void Queue::createNewElements(int* newElements){
    for (int j = 0, i = frontindex; i < frontindex + capacity; i++, j++){
        newElements[j] = elements [i % capacity];
    }
    delete [] elements;
    elements = newElements;
    frontindex = 0;
    backindex = elementCount;
}

// Description:  Constructor
// Postcondition: Creates dynamically stored memory
Queue::Queue() : elementCount(0), capacity(INITIAL_CAPACITY), frontindex(0), backindex(0) {
    elements = new int[capacity];
} 

// Description: Destructor
// Postcondition: Deletes dynamically stored memory
Queue::~Queue(){
    delete [] elements;
    elements = nullptr;
}

// Description:  Inserts element x at the back (O(1))
void Queue::enqueue(int x) {
    if (elementCount == capacity){
        int* newElements = new int[capacity*2];
        createNewElements(newElements);
        capacity *= 2;
    } 
    elementCount++;
    elements[backindex] = x;
    backindex = (backindex + 1) % capacity;
} 


// Description:  Removes the frontmost element (O(1))
// Precondition:  Queue not empty
void Queue::dequeue() {
    if (this->isEmpty()) return;
    if (elementCount*4 <= capacity && capacity >= INITIAL_CAPACITY*2){
        int* newElements = new int[capacity/2];
        createNewElements(newElements);
        capacity /= 2;
    }
    elements[frontindex] = 0;
    elementCount--;
    frontindex = (frontindex + 1) % capacity;
} 


// Description:  Returns a copy of the frontmost element (O(1))
// Precondition:  Queue not empty
int Queue::peek() const {
    return elements[frontindex];
} 


// Description:  Returns true if and only if queue empty (O(1))
bool Queue::isEmpty() const {
    return elementCount == 0;
}


