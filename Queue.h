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

#pragma once

#include "EmptyDataCollectionException.h"

template <class ElementType>
class Queue {
	
    private:
        static unsigned const INITIAL_CAPACITY = 6; // Constant INITIAL_CAPACITY
        ElementType* elements;      

        unsigned elementCount;      // Number of elements in the Queue
        unsigned capacity;          // Actual capacity of the data structure                 
        unsigned frontIndex;        // Index the topmost element
        unsigned backIndex;         // Index where the next element will be placed   
        // private methods

        // Description: Resizes elements array
        // Postcondition: resizes elements array either allocating or deallocing heap memory
        void resize(ElementType* newElements);
    public:
        // Description:  Constructor
        // Postcondition: Creates dynamically stored memory
        Queue();

        // Description: Destructor
        // Postcondition: Deletes dynamically stored memory
        ~Queue();

        // Description: Inserts newElement at the "back" of this Queue 
        //              (not necessarily the "back" of its data structure) and 
        //              returns "true" if successful, otherwise "false".
        // Time Efficiency: O(1)
        bool enqueue(ElementType& newElement);

        // Description: Removes (but does not return) the element at the "front" of this Queue 
        //              (not necessarily the "front" of its data structure).
        // Precondition: This Queue is not empty.
        // Exception: Throws EmptyDataCollectionException if this Queue is empty.   
        // Time Efficiency: O(1)
        void dequeue(); 


        // Description: Returns (but does not remove) the element at the "front" of this Queue
        //              (not necessarily the "front" of its data structure).
        // Precondition: This Queue is not empty.
        // Postcondition: This Queue is unchanged by this operation.
        // Exception: Throws EmptyDataCollectionException if this Queue is empty.
        // Time Efficiency: O(1)
        ElementType& peek() const;  


        // Description: Returns "true" if this Queue is empty, otherwise "false".
        // Postcondition: This Queue is unchanged by this operation.
        // Time Efficiency: O(1)
        bool isEmpty() const;

        // For Testing Purposes
        // Description: Prints the content of "this"
        friend ostream & operator<<(ostream & os, const Queue<int>& rhs);

}; // end of Queue

/******* End of Queue Public Interface *******/

#include "Queue.cpp" // A way to make Queue a template
