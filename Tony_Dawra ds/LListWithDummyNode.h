/*-- LListWithDummyNode.h
---------------------------------------------------------------

Author: Tony Dawra

This header file defines the LListWithDummyNode data type.
  Basic operations:
    no-arg constructor         : Constructs a default LListWithDummyNode
    copy constructor           : Constructs a new LListWithDummyNode using existing LListWithDummyNode parameter 
    destructor                 : Deletes a LListWithDummyNode 
    isEmpty		          : Checks whether or not LListWithDummyNode is empty 
    getmySize                  : gets and return mySize
    search                     : Checks whether inputted data exists in LListWithDummyNode 
    insertAtPosition           : Inserts data at certain position of LListWithDummyNode 
    insertAtEnd                : Inserts data at end of LListWithDummyNode 
    insertAtBeginning	   : Inserts data at beginning of LListWithDummyNode 
    display                    : Displays content of the LListWithDummyNode
    at                         : Retrieve element at a given position
...
-------------------------------------------------------------------------*/
#ifndef LLISTWITHDUMMYNODE_H
#define LLISTWITHDUMMYNODE_H
#include "Course.h"
#include <iostream>
#include <ostream>
using namespace std;
typedef Course* ElementType;
class LListWithDummyNode {
    /*** Node class ***/
private:
    class Node { // Inner class definition of node structure
    public:
        Node(const ElementType&);
        Node();
        ElementType data;
        Node* next;
        // Some Node function members
    };
    typedef Node* NodePtr;
    /*** List's data members ***/
    NodePtr myFirst;
    int mySize;

public:
    /*** List's function members ***/
    /***** No-Arg Constructor *****/
    LListWithDummyNode();
    /********************************************************************
            * Purpose: Construct a LinkedListWithDummy object
            * Precondition: none
            * Postcondition: an empty LinkedListWithDummy object has been
     constructed; mySize=0 ;and myFirst points to a dummy Node with
     myFirst->next pointing to NULL.
            ********************************************************************/
            /***** Copy Constructor *****/
    LListWithDummyNode(const LListWithDummyNode&);
    /********************************************************************
            * Purpose:  Construct a copy of a LinkedListWithDummy object.
            * Precondition: A copy of origList is needed; origList is a const
     reference parameter.
            * Postcondition: A LinkedListWithDummy object is constructed with
     myFirst, mySize and LinkedListWithDummy equal to the parameter's
            ********************************************************************/
            /***** Destructor *****/
    ~LListWithDummyNode();
    /********************************************************************
            * Purpose:  Destroys a LinkedListWithDummy object
            * Precondition: The life of a List object is over.
            * Postcondition: The LinkedListWithDummy is empty;
     myFirst->next points to NULL; and mySize is 0.
            ********************************************************************/
    int getmySize() const;
    /********************************************************************
            * Purpose: Get the current size of the LinkedListWithDummy.
            * Precondition: None.
            * Postcondition: The current size of the LinkedListWithDummy is returned.
            ********************************************************************/
    bool isEmpty() const;
    /********************************************************************
            * Purpose: check if the LinkedListWithDummy is empty.
            * Precondition: none
            * Postcondition: true is returned if the lLinkedListWithDummy is empty ,
     false if not
            ********************************************************************/
    bool insertAtPosition(const ElementType&, int);
    /********************************************************************
            * Purpose: insert a value into the linked list at a valid position
            * Precondition: course is the object to be inserted, and `pos` is the
     position where it should be inserted. The position must satisfy the
     condition 0 <= `pos` < `mySize`.
            * Postcondition: If `pos` is a legal position, the `course` has been
     inserted into the LinkedListWithDummy at the specified position, and true
     is returned. If `pos` is out of bounds, no changes are made to the list,
     and false is returned.
            ********************************************************************/
    bool insertAtEnd(const ElementType&);
    /********************************************************************
            * Purpose: insert a value into the linked list at the end
            * Precondition: course is the object to be inserted
            * Postcondition: The course has been inserted at the end of the LinkedListWithDummy.
            ********************************************************************/
    bool insertAtBeginning(const ElementType&);
    /********************************************************************
            * Purpose: insert a value into the linked list at the beginning
            * Precondition: course is the object to be inserted
            * Postcondition: The course has been inserted at the beginning of the
     LinkedListWithDummy.
            ********************************************************************/
    int search(const ElementType&);
    /********************************************************************
            * Purpose: Search for an element in the LinkedListWithDummy
            * Precondition:  The element to search for in course.
            * Postcondition: Returns the position of the first occurrence of course in
     the LinkedListWithDummy. If not found, it returns -1.
            ********************************************************************/
    ostream& display(ostream&) const;
    /********************************************************************
            * Purpose: display the LinkedListWithDummy
            * Precondition: the ostream out is open and ready for output
            * Postcondition: The courses represented by the LListWithDummy object
     have been inserted into the `out`. The modified `out` stream is returned
     for further use.
            ********************************************************************/

    ElementType at(int pos);
/********************************************************************
            * Purpose: retrieve element at a given position in the LListWithDummy.
            * Precondition: The LListWithDummy is not empty, and the position must satisfy the condition 0 <= `pos` < `mySize`.
            * Postcondition: If the position is valid, the element at that position is returned. 
     If the position is invalid, an error message is printed to cerr, and NULL is returned.
     ********************************************************************/

}; // end of LListWithDummy class

// Prototype of output operator
ostream& operator<<(ostream&, ElementType&);
// Prototype of input operator
istream& operator>>(istream&, ElementType&);

#endif /* ARRAYLIST_H */
