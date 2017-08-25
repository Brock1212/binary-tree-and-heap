#ifndef HEAP_3358_H_
#define HEAP_3358_H_

// File Name: heap_3358.h
//
// Author: Jill Seaman and Brock Yarbrough
// Date: 4/21/15
// Assignment Number: 6
// CS 3358 Spring 2015
// Instructor: Jill Seaman
//
// A binary heap


#include <cassert>
#include<iostream>
#include<algorithm>

using namespace std;

template<class ItemType>
class Heap_3358 {
public:

    //Constructor
    Heap_3358();

    /****************************
     makeEmpty

     Function: Removes all the items from the heap.
     Postconditions: All the items have been removed/deallocated
     *****************************/
    void makeEmpty();

    /****************************
     insertItem

     Function: Adds newItem to the heap.
     Postconditions: newItem is in the proper position for a heap.
     *****************************/
    void insertItem(const ItemType &);

    /****************************
     findMin

     Function: Finds minimum element in heap.
     Preconditions: heap has at least one node.
     Postconditions: Returns the smallest element in the heap.
     *****************************/
    ItemType findMin();

    /****************************
     deleteMin

     Function: Removes minimum element from heap.
     Preconditions: heap has at least one node.
     Postconditions: Smallest element has been removed from heap, and it's
                     still a heap.
     *****************************/
    void deleteMin();

    /****************************
     display

     Function: for diagnostic purposes, displays the tree like this
     (positions in array are shown):
     1
     2 3
     4 5 6 7
     8 9 10 11 12 13 14 15
     etc.
     *****************************/

    void display();


private:
    int size;
    ItemType array[100];

    // Given a position in the array, percolate that element up into place
    void percolateUp(int);
    // Given a position in the array, percolate that element down into place
    void percolateDown(int);

};

/*******************************
 / Function implementations
 ********************************/

template<class ItemType>
Heap_3358<ItemType>::Heap_3358 ()
{
	size = 0;
	array[0] = 0;
}


template<class ItemType>
void Heap_3358 <ItemType>::makeEmpty()
{
	size = 0;
}


template<class ItemType>
ItemType Heap_3358 <ItemType>::findMin()
{
	assert(size != 0);
	return array[1];
}

template<class ItemType>
void Heap_3358 <ItemType>::insertItem(const ItemType& newItem)
{
    assert(size != 100); // place newItem at end of tree, use percolate up to move to proper place

    ++size;
    array[size] = newItem;
    percolateUp(size);

}

template<class ItemType>
void Heap_3358 <ItemType>::percolateUp(int loc) {


   if (array[loc] > array[loc/2])
   {
	   return;                                    // if array[loc] is greater than its parent: done
   }
   else                                           // else swap array[loc] with parent, repeat on the parent
   {
       swap(array[loc], array[loc/2]);
       percolateUp(loc/2);                // Make this recursive.
   }
}


template<class ItemType>
void Heap_3358 <ItemType>::deleteMin()
{
	assert(size != 0);
   array[1] = array[size]; // move last item to top, use percolate down to move it to proper place
   percolateDown(1);
   --size;
}

template<class ItemType>
void Heap_3358 <ItemType>::percolateDown(int loc) {

    int left = 2*loc;   //calculate index of left child
    int right =  2*loc + 1;  //calculate index of right child

    if (left>size)   // no children
    	return;

    if (left==size) { //one child
       if (array[loc] > array[left]) // compare array[loc] to array[left], swap if needed
			swap(array[loc],array[left]);
                                           //done
    }

    //two children:
    if (array[loc] < array[left] && array[loc] < array[right])
    	return;
    else                                            // if both children are greater than the parent: done
    {
    	  if (array[left] < array[right])        // otherwise, swap the smaller of the two children with the
    	  {
    		  swap(array[loc],array[left]);
    		  percolateDown(left);
    	  }
    	  else
    	  {
    		  swap(array[loc],array[right]);
    	      percolateDown(right);
    	  }
    }
                                                // parent, repeat


}


// Provided:
template<class ItemType>
void Heap_3358 <ItemType>::display () {
    for (int i=1; i<=size; i++) {
        if ((i & (i - 1)) == 0)  // i is a power of 2
            cout << endl;
        cout << array[i] << " " ;
    }
    cout << endl;
}




#endif /* HEAP_3358_H_ */
