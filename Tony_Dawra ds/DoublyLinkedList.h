/*-DoublyLinkedList.h--------------------------------------------------------------------

  Author: Kayan Abdelbaki 

    This header file defines the DoublyLinkedList data type.
    Basic operations:
    no-arg constructor         : Constructs a DoublyLinkedList object
    destructor                 : Destroys a DoublyLinkedList object
    copy constructor           : Constructs a new DoublyLinkedList using existing DoublyLinkedList parameter
    isEmpty		               : Checks if a DoublyLinkedList object is empty
    search                     : Checks if inputted data exists in a DoublyLinkedList object
    insertAtPos                : Inserts data at given position
    deleteAtPos                : Deletes data at given position
    insertAtBeginning		   : Inserts data at beginning of DoublyLinkedList object
    insertAtEnd                : Inserts data at end of DoublyLinkedList object
    at                         : Return a value from the DoublyLinkedList at a given position.
    display                    : Displays content of a DoublyLinkedList object
---------------------------------------------------------------------------------------*/

#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H
#include "Student.h"
#include <iostream>
using namespace std;

typedef Student* DLLType;

class DoublyLinkedList {

public:
    /******** Function Members *********/
    /***** No-Arg Constructor *****/
    DoublyLinkedList();
    /*------------------------------------------------------------------------------
      Constructs a new DoublyLinkedList object

      Precondition: None
      Post-Condition: An empty DoublyLinkedList object is constructed;
                      myFirst points to NULL; and mySize is 0.
     -------------------------------------------------------------------------------*/

     /***** Destructor *****/
    virtual ~DoublyLinkedList();
    /*------------------------------------------------------------------------------
       Destroys a DoublyLinkedList object

       Precondition: The life of a DoublyLinkedList object is over.
       Post-Condition: The DoublyLinkedList is empty;
                       myFirst points to NULL; and mySize is 0.
    -------------------------------------------------------------------------------*/

    /***** Copy Constructor *****/
    DoublyLinkedList(const DoublyLinkedList&);

    /*----------------------------------------------------------------------------------
      Construct a copy of a DoublyLinkedList object.

      Precondition: A copy of orig is needed; orig is a const reference
                    parameter.
      Post-Condition: A DoublyLinkedList object is constructed with myFirst, mySize and
                      DoublyNodes equal to the parameter's
    ----------------------------------------------------------------------------------*/

    /***** isEmpty operation *****/
    inline bool isEmpty() const {
        return mySize == 0;
    }
    /*----------------------------------------------------------------------
       Check if a DoublyLinkedList is empty.

       Precondition: None

       Postcondition: true is returned if the list is empty, false otherwise.
    -----------------------------------------------------------------------*/

    /***** insert at position operation *****/
    bool insertAtPos(DLLType&, int);
    /*----------------------------------------------------------------------
       Insert a value into the DoublyLinkedList at a given position.

       Precondition: data is the value to be inserted; pos is the position
                     where data is to be inserted
       Postcondition: true is returned if 0 <= pos <= mySize and  new DNode
                     containing given data has been inserted into the
                     DoublyLinkedList at pos; false is returned otherwise.
    -----------------------------------------------------------------------*/

    /***** delete at position operation *****/
    bool deleteAtPos(int);
    /*----------------------------------------------------------------------
       Remove value from the DoublyLinkedList at a given position.

       Precondition: pos is the position where DNode is to be deleted.
       Postcondition: true is returned if 0 <= pos <= mySize; and DNode at
                     pos is deleted; false is returned otherwise
    ----------------------------------------------------------------------*/

    bool insertAtBeginning(DLLType&);
    /*----------------------------------------------------------------------
      Insert a value into the DoublyLinkedList at the beginning

      Precondition: data is the value to be inserted.
      Postcondition: true is returned and  new DNode containing given data
                    has been inserted into the DoublyLinkedList at pos = 0
   -----------------------------------------------------------------------*/

    bool insertAtEnd(DLLType&);
    /*----------------------------------------------------------------------
      Insert a value into the DoublyLinkedList at the end

      Precondition: data is the value to be inserted.
      Postcondition: true is returned and  new DNode containing given data
                    has been inserted into the DoublyLinkedList at
                    pos = mySize.
   -----------------------------------------------------------------------*/
    DLLType at(int pos);

    /*----------------------------------------------------------------------
       Return a value from the DoublyLinkedList at a given position.

       Precondition: pos is the position where data is to be retrieved from.
       Postcondition: DLLType data at pos is returned
    -----------------------------------------------------------------------*/

    int search(DLLType);

    /*----------------------------------------------------------------------
       Search for a value in the DoublyLinkedList

       Precondition: data is the value to be searched for
       Postcondition: position of first occurence of data is returned if
                      found, -1 is returned otherwise.
    -----------------------------------------------------------------------*/

    int size() const;

    /*----------------------------------------------------------------------
       Return size of the DoublyLinkedList

       Precondition: None
       Postcondition: mySize is returned.
    -----------------------------------------------------------------------*/

    /***** output *****/
    void display(ostream&);
    /*----------------------------------------------------------------------
        Display a DoublyLinkedList.

        Precondition: The ostream out is open.
        Postcondition: The content of DoublyLinkedList is displayed in a
                       well formatted manner.
    -----------------------------------------------------------------------*/

private:
    class DNode { // Inner class definition of node structure
    public:
        DNode(const DLLType&);
        /*----------------------------------------------------------------------
           Constructs a new DNode

           Precondition: data is the content of DNode to be constructed
           Postcondition: new DNode is constructed with next and prev pointing
                          to null and data set to the given
        -----------------------------------------------------------------------*/
        DLLType data; // content of DNode
        DNode* next;  // pointer to the next DNode
        DNode* prev;  // pointer to the previous DNode
    };
    typedef DNode* DNodePtr;

    /********Data Members ********/
    int mySize;       // size of the DoublyLinkedList
    DNodePtr myFirst; // pointer to the first DNode

}; //---- end of List class

//------Prototype of output operator
ostream& operator<<(ostream&, DoublyLinkedList&);
istream& operator>>(istream&, DoublyLinkedList&);
#endif
