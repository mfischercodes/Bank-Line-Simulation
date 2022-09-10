/* 
 * BinaryHeap.cpp
 *
 * NOTE: You can replace/modify the code in the body of the methods fond in this file.
 *       If you decide to keep the code, make sure it works as expected.
 *
 * To do: fill in the two blank spaces below
 * Blank space 1: The choices are "minimum" or "maximum" 
 *                   
 * Blank space 2: Refer to our lecture notes for the data structure used as CDT.
 * Description: min Binary Heap data collection ADT class. 
 *              array implementation.
 *
 * Class Invariant:  Always a min Binary Heap
 * 
 * Author: Michael Fischer 301310859
 *
 * Last Modification: March 25 2022
 *
 */  

#include "BinaryHeap.h"  // Header file


// Private methods

// Swaps a child and parent element
template <class ElementType>
void BinaryHeap<ElementType>::swap(unsigned int indexOfParent, unsigned int indexOfBottom){
	Event temp = elements[indexOfParent];
	elements[indexOfParent] = elements[indexOfBottom];
	elements[indexOfBottom] = temp;
}


// Description: Double array capacity
template <class ElementType>
bool BinaryHeap<ElementType>::doubleElements(){
	ElementType* newElements = new Event[capacity * 2];
	if (newElements == NULL) return false;

	for (unsigned int i = 0; i < capacity; i++)
		newElements[i] = elements[i];
	
	delete [] elements;
	
	capacity *= 2;
	elements = newElements;
	return true;
}


// Default Constructor
template <class ElementType>
BinaryHeap<ElementType>::BinaryHeap():elementCount(0), capacity(5) {
   elements = new Event[capacity];
} // end of default constructor


// Description: Destructor
// PostCondition: Removes heap allocated memory
template <class ElementType>
BinaryHeap<ElementType>::~BinaryHeap(){
	delete [] elements;
}


// Description: Returns true if the Binary Heap is empty
// Postcondition:  The Binary Heap is unchanged by this operation.
// Time Efficiency: O(1)
template <class ElementType>
bool BinaryHeap<ElementType>::isEmpty(){
	return elementCount == 0;
}

// Description: Returns the number of elements in the Binary Heap.
// Postcondition:  The Binary Heap is unchanged by this operation.
// Time Efficiency: O(1)
template <class ElementType>
unsigned int BinaryHeap<ElementType>::getElementCount() const {
   return elementCount;
}  // end getElementCount


// Description: Inserts newElement into the Binary Heap.
//              It returns "true" if successful, otherwise "false".        
// Postcondition: Remains a minimum Binary Heap after the insertion.
// Time Efficiency: O(log2 n)
template <class ElementType>
bool BinaryHeap<ElementType>::insert(ElementType& newElement) {
	// double capacity here
	if (elementCount == capacity)
		if (!doubleElements()){
			return false;
		}

	elements[elementCount] = newElement;
	reHeapUp(elementCount);
	elementCount++;

    return true;

} // end insert


// Utility method - Recursively put the array back into a minimum Binary Heap.
template <class ElementType>
void BinaryHeap<ElementType>::reHeapUp(unsigned int indexOfBottom) {

    unsigned int indexOfRoot = 0;
	// if elements has a parent
    if (indexOfBottom > indexOfRoot){
		
		unsigned int indexOfParent = (indexOfBottom - 1) / 2;
		// child < parent
		if ( ! (elements[indexOfParent] <= elements[indexOfBottom])){
			swap(indexOfParent, indexOfBottom);
			reHeapUp(indexOfParent);
		}
	}

	return;
	
} // end reHeapUp


// Description: Removes (but does not return) the element located at the root.
// Precondition: This Binary Heap is not empty.
// Postcondition: Remains a minimum Binary Heap after the removal.	
// Exceptions: Throws EmptyDataCollectionException if this Binary Heap is empty.
// Time Efficiency: O(log2 n)
template <class ElementType>
void BinaryHeap<ElementType>::remove() {

    if (isEmpty())
		throw (EmptyDataCollectionException("remove() called with an empty BinaryHeap."));

	elements[0] = elements[elementCount - 1];
	elementCount--;

	if (!isEmpty()){
		reHeapDown(0);
	}
	
	
	return;
	
}  // end remove


// Utility method - Recursively put the array back into a minimum Binary Heap.
template <class ElementType>
void BinaryHeap<ElementType>::reHeapDown(unsigned int indexOfRoot) {
	
	unsigned int indexOfMinChild = indexOfRoot;
	// Find indices of children.
	unsigned int indexOfLeftChild = 2*indexOfRoot+1;
	unsigned int indexOfRightChild = 2*indexOfRoot+2;

    // Base case: elements[indexOfRoot] is a leaf as it has no children
	if (indexOfLeftChild > elementCount-1) return;
	
	// If we need to swap, select the smallest child
    if ( !(elements[indexOfRoot] <= elements[indexOfLeftChild]) )
    	indexOfMinChild = indexOfLeftChild;

    // Check if there is a right child, is it the smallest?
    if (indexOfRightChild < elementCount) {
		if ( ! (elements[indexOfMinChild] <= elements[indexOfRightChild]) )
		    indexOfMinChild = indexOfRightChild;
	}

	// Swap parent with smallest of children.
	if (indexOfMinChild != indexOfRoot) {
		
	   Event temp = elements[indexOfRoot];
	   elements[indexOfRoot] = elements[indexOfMinChild];
	   elements[indexOfMinChild] = temp;
	   
	   // Recursively put the array back into a heap
	   reHeapDown(indexOfMinChild);
    }

	return;
	
} // end reHeapDown


// Description: Retrieves (but does not remove) the element located at the root.
// Precondition: This Binary Heap is not empty.
// Postcondition: This Binary Heap is unchanged.
// Exceptions: Throws EmptyDataCollectionException if this Binary Heap is empty.
// Time Efficiency: O(1) 
template <class ElementType>
ElementType& BinaryHeap<ElementType>::retrieve() const {
   
   // Enforce precondition
   if ( elementCount > 0 )
      return elements[0];
   else
      throw(EmptyDataCollectionException("retrieve() called with an empty BinaryHeap.")); 

}  // end retrieve


// For Testing Purposes
// Description: Prints the content of "rhs".
template <class ElementType>
void BinaryHeap<ElementType>::printBinaryHeap() const {
	for ( unsigned int i = 0; i < elementCount; i++ )
		cout << elements[i] << endl;
}

ostream& operator<<(ostream & os, const BinaryHeap<Event>& rhs) {
	
	for ( unsigned int index = 0; index < rhs.elementCount; index++ )
		os << rhs.elements[index]; // Print data

	return os;
} // end of operator <<


//  End of implementation file.