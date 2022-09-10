/* 
 * BinaryHeap.h
 *
 * // To do: fill in the two blank spaces below
 * // Blank space 1: The choices are "minimum" or "maximum" 
 *                  
 * // Blank space 2: Refer to our lecture notes for the data structure used as CDT.
 * Description: minimum Binary Heap data collection ADT class. 
 *              array implementation.
 *
 * Class Invariant:  Always a minimum Binary Heap
 * 
 * Author: Michael Fischer 301310859
 *
 * Last Modification: March 25 2022
 *
 */   
 
#pragma once

#include <iostream>
#include "Event.h"
#include "EmptyDataCollectionException.h" 

using namespace std;

template <class ElementType>
class BinaryHeap {

private:
	
	ElementType* elements;		// array implementation
	unsigned int elementCount;
	unsigned int capacity;
	
	// Utility method - Recursively put the array back into a minimum Binary Heap.
	void reHeapUp(unsigned int indexOfBottom);

	// Utility method - Recursively put the array back into a minimum Binary Heap.
	void reHeapDown(unsigned int indexOfRoot);  

	// Description: Swaps a child and parent element
	void swap(unsigned int indexOfParent, unsigned int indexOfBottom);

	// Description: Double array capacity
	bool doubleElements();

   
public:
	// Default Constructor
	BinaryHeap(); 
	
	// Description: Destructor
	// PostCondition: Removes heap allocated memory
	~BinaryHeap();

	// Description: Returns true if the Binary Heap is empty
    // Postcondition:  The Binary Heap is unchanged by this operation.
	// Time Efficiency: O(1)
	bool isEmpty();

    // Description: Returns the number of elements in the Binary Heap.
    // Postcondition:  The Binary Heap is unchanged by this operation.
	// Time Efficiency: O(1)
    unsigned int getElementCount() const;

	// Description: Inserts newElement into the Binary Heap.
	//              It returns "true" if successful, otherwise "false".        
	// Postcondition: Remains a minimum Binary Heap after the insertion.
	// Time Efficiency: O(log2 n)
	bool insert(ElementType& newElement);
	   
	// Description: Removes (but does not return) the element located at the root.
	// Precondition: This Binary Heap is not empty.
	// Postcondition: Remains a minimum Binary Heap after the removal.	
	// Exceptions: Throws EmptyDataCollectionException if this Binary Heap is empty.
	// Time Efficiency: O(log2 n)
	void remove();

	// Description: Retrieves (but does not remove) the element located at the root.
	// Precondition: This Binary Heap is not empty.
	// Postcondition: This Binary Heap is unchanged.
	// Exceptions: Throws EmptyDataCollectionException if this Binary Heap is empty.
	// Time Efficiency: O(1) 
	ElementType& retrieve() const;

	void printBinaryHeap() const;

	// For Testing Purposes
	// Description: Prints the content of "this". 
	friend ostream & operator<<(ostream & os, const BinaryHeap<Event>& rhs);
   
}; // end BinaryHeap

#include "BinaryHeap.cpp" // 