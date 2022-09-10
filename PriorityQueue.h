/* 
 * PriorityQueue.h
 *
 * Class Invariant:  Always uses a minimum Binary Heap
 * 
 * Author: Michael Fischer 301310859
 *
 * Last Modification: March 25 2022
 *
 */  

#pragma once

#include "EmptyDataCollectionException.h"
#include "BinaryHeap.h"

template <class ElementType>
class PriorityQueue{

private:
    BinaryHeap<ElementType>* elements;
    unsigned int elementCount;

public:

    PriorityQueue();

    ~PriorityQueue();
/******* Start of Priority Queue Public Interface *******/

   // Description: Returns "true" if this Priority Queue is empty, otherwise "false".
   // Postcondition: This Priority Queue is unchanged by this operation.
   // Time Efficiency: O(1)
   bool isEmpty() const;

   // Description: Inserts newElement in this Priority Queue and 
   //              returns "true" if successful, otherwise "false".
   bool enqueue(ElementType& newElement);

   // Description: Removes (but does not return) the element with the next
   //              "highest" priority value from the Priority Queue.
   // Precondition: This Priority Queue is not empty.
   // Exception: Throws EmptyDataCollectionException if Priority Queue is empty.
   void dequeue();
   
   // Description: Returns (but does not remove) the element with the next 
   //              "highest" priority from the Priority Queue.
   // Precondition: This Priority Queue is not empty.
   // Postcondition: This Priority Queue is unchanged by this operation.
   // Exception: Throws EmptyDataCollectionException if this Priority Queue is empty.
    ElementType& peek() const; 


    void printPriorityQueue() const;
   
/*******  End of Priority Queue Public Interface *******/
}; // end of PriorityQueue

#include "PriorityQueue.cpp"
