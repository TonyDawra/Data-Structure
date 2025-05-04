#include "LListWithDummyNode.h"
#include "Student.h"
#include <iostream>
#include <ostream>
using namespace std;

//--- Definition of Node constructor
LListWithDummyNode::Node::Node(const ElementType& data) {
    this->data = data;
    next = NULL;
}

LListWithDummyNode::Node::Node() : next(NULL) {}

//--- Definition of class constructor
LListWithDummyNode::LListWithDummyNode() {
    myFirst = new Node();
    myFirst->next = NULL;
    mySize = 0;
}

ElementType LListWithDummyNode::at(int pos) {
    //check if position is accepted
    if (pos >= getmySize() || pos < 0) {
        cerr << "Out of bound";
        return NULL;
    }

    NodePtr tempPtr = myFirst;
    tempPtr = tempPtr->next;

    while (pos--) {
        tempPtr = tempPtr->next;
    }

    return tempPtr->data;
}
//--- Definition of copy constructor
LListWithDummyNode::LListWithDummyNode(const LListWithDummyNode& orig) {
    if (isEmpty()) { // If the original list is empty, create an empty list
        LListWithDummyNode();
    }

    myFirst = new Node(orig.myFirst->data); // // Copy the dummy node
    NodePtr tempPtr = orig.myFirst->next;
    NodePtr loopingNode = myFirst;
//--- Copy each node in the original list
    while (tempPtr != NULL) {
        loopingNode->next = new Node(tempPtr->data);
        tempPtr = tempPtr->next;
        loopingNode = loopingNode->next;
    }
    mySize = orig.mySize;
}
//--- Definition of class destructor
LListWithDummyNode::~LListWithDummyNode() {
    if (!isEmpty()) {
        NodePtr tempPtr = myFirst->next;

//--- Traverse the list and delete each node
        while (tempPtr->next != NULL) {
            myFirst->next = tempPtr->next;
            delete tempPtr;
            tempPtr = myFirst->next;
        }
        delete tempPtr; // delete last node
        mySize = 0;
    }
}

//--- Definition of empty()
bool LListWithDummyNode::isEmpty() const { return myFirst->next == NULL; }

//--- Definition of getmySize()
int LListWithDummyNode::getmySize() const { return mySize; }

//--- Definition of insertAtPosition()
bool LListWithDummyNode::insertAtPosition(const ElementType& course, int pos) {
   //check if position is accepted
    if (pos > mySize || pos < 0) {
        cout << "invalid position";
        return false;
    }
    // If the list is empty and position is 0, insert at the beginning
    if (isEmpty() && pos == 0) {
        NodePtr newPtr = new Node(course);
        myFirst->next = newPtr;
        mySize++;
        return true;
    }
    if (pos == 0) {
        // If position is 0, insert at the beginning
        NodePtr newPtr = new Node(course);
        newPtr->next = myFirst->next;
        myFirst->next = newPtr;
        mySize++;
        return true;
    }
    NodePtr tempPtr = myFirst->next;
    for (int i = 0; i < pos - 1; i++) {
        // Traverse to the node before the specified position
        tempPtr = tempPtr->next;
    }
    NodePtr newPtr = new Node(course);
    newPtr->next = tempPtr->next;
    tempPtr->next = newPtr;
    mySize++; //Increment size
    return true;
}

//--- Definition of insertAtEnd()
bool LListWithDummyNode::insertAtEnd(const ElementType& course) {
    // Insert at the end by using the list size as the position
    return insertAtPosition(course, mySize);
}

//--- Definition of insertAtBrginning()
bool LListWithDummyNode::insertAtBeginning(const ElementType& course) {
    // Insert at beginning
    return insertAtPosition(course, 0);
}

//--- Definition of search()
int LListWithDummyNode::search(const ElementType& course) {
    NodePtr tempPtr = myFirst->next;
    int pos = 0;
    while (tempPtr != NULL) {
        // Traverse the list and compare each element with the specified course
        if (tempPtr->data == course) {
            return pos; //return if found
        }
        tempPtr = tempPtr->next;
        pos++;
    }
    return -1; //return -1 if not found
}

//--- Definition of display()
ostream& LListWithDummyNode::display(ostream& out) const {
    if (isEmpty()) {
        cout << "Empty List";
    }
    else {
        NodePtr current = myFirst->next;
        while (current != NULL) {
            // Display each element in the list
            out << *(current->data) << "\n";
            current = current->next;
        }
        cout << endl;
    }

    return out;
}

//--- Definition of output operator
ostream& operator<<(ostream& out, const LListWithDummyNode& course) {
    return course.display(out);
}

//--- Definition of input operator
istream& operator>>(istream& in, LListWithDummyNode& course) {
    int numCourses;
    cout << "Enter the number of courses you want to add: ";
    in >> numCourses;
    ElementType insertedCourse = new Course();
    for (int i = 0; i < numCourses; i++) {
        in >> *insertedCourse;
        course.insertAtEnd(insertedCourse);
    }
    return in;
}
