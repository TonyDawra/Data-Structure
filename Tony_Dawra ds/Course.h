/*  Course.h
----------------------------------------------------------------------------------------------------------
    By Amir El Chakif
 
    This header file defines the data fields and member functions of class Course
 
 *  Basic operations:
 *  no-arg contructor: Constructs a default course object.
 *  with-arg contructor: Constructs a parameterized course object.
 *  copy constructor: Constructs a new course object equivalent to the pre-existing course object.
 *  setCode: Setter method to set the course code.
 *  setTitle: Setter method to set the course title.
 *  setCapacity: Setter method to set the course capacity.
 *  setCredits: Setter method to set the course credits.
 *  getCode: Getter method to retrieve the course code.
 *  getTitle: Getter method to retrieve the course title.
 *  getCapacity: Getter method to retrieve the course capacity.
 *  getCredits: Getter method to retrieve the course credits.
 *  getEnrolled: Getter method to retrieve the course enrolled number of students in a course.
 *  addStudent: Method to add a student to the list of enrolled students in the course.
 *  dropStudent: Method to drop a student from the list of enrolled students in the course.
 *  isFull: Checks if the course is full (reached its maximum capacity of students).
 *  operator==: Overloaded equality operator to compare two Course objects.
 *  displayCourse: Method to display course object with its data fields.
 *  displayRegisteredStudents: Method to display the list of registered students in the course on the output.
-----------------------------------------------------------------------------------------------------------
 */

#ifndef COURSE_H
#define COURSE_H

#include "Student.h"
#include <iostream>
#include <istream>
#include <string>
#include <vector>

using namespace std;

/*
 * Class Course
 * Represents a course with information such as code, title, credits, capacity, and a list of enrolled students.
 */
class Course {
public: //Member methods
    /*
     * Purpose: Default constructor for the Course class.
     * Pre-conditions None.
     * Post-conditions A Course object is created with default values.
     */
    Course();

    /*
     * Purpose: Constructor with all parameters: code, title, credits, capacity.
     * Pre-conditions: Parameter input should be of valid values.
     * Post-conditions: A Course object is created with the specified values, value of enrolled is set to default 0.
     */
    Course(char *, string, int, int);

    /*
     * Purpose: Copy constructor for the Course class, creates a deep copy of another Course object, takes another course object as argument.
     * Pre-conditions: None.
     * Post-conditions: A Course object is created as a copy of the provided Course object.
     */
    Course(const Course &course);

    /*
     * Purpose: Setter method to set the course code.
     * Pre-conditions: The input code array must have a length of at least 7 characters.
     * Post-conditions: The course code is set to the provided value.
     */
    void setCode(char[7]);

    /*
     * Purpose: Setter method to set the course title.
     * Pre-conditions: None.
     * post-conditions: The course title is set to the provided value.
     */
    void setTitle(string);

    /*
     * Purpose: Setter method to set the course capacity.
     * Pre-conditions: The input capacity must be a non-negative integer, and not less than the number of enrolled students.
     * Post-conditions: The course capacity is set to the provided value.
     */
    void setCapacity(int);

    /*
     * Purpose: Setter method to set the course credits.
     * Pre-conditions: The input credits must be greater than zero.
     * Post-conditions: The course credits are set to the provided value.
     */
    void setCredits(int);

    /*
     * Purpose: Getter method to retrieve the course code.
     * Pre-conditions: None.
     * Post-conditions: The course code is returned.
     */
    string getCode() const;

    /*
     * Purpose: Getter method to retrieve the course title.
     * Pre-conditions: None.
     * Post-conditions: The course title is returned.
     */
    string getTitle() const;

    /*
     * Purpose: Getter method to retrieve the course capacity.
     * Pre-conditions: None.
     * Post-conditions: The course capacity is returned.
     */ 
    int getCapacity() const;

    /*
     * Purpose: Getter method to retrieve the course credits.
     * Pre-conditions: None.
     * Post-conditions: The course credits are returned.
     */
    int getCredits() const;

    /*
     * Purpose: Getter method to retrieve the number of students enrolled in the course.
     * Pre-conditions: None.
     * Post-condition: The number of enrolled students is returned.
     */
    int getEnrolled() const;

    /*
     * Purpose: Method to add a student to the list of enrolled students in the course.
     * Pre-conditions: The input student pointer must not be nullptr, must point to a student object.
     * Post-conditions: The student is added to the list of enrolled students.
     */
    void addStudent(Student *);

    /*
     * Purpose: Method to drop a student from the list of enrolled students in the course.
     * Pre-conditions: The input student pointer must not be nullptr, must point to a student object.
     * Post-conditions: The student is removed from the list of enrolled students.
     */
    void dropStudent(Student *);

    /*
     * Purpose: Checks if the course is full (reached its maximum capacity of students).
     * Pre-conditions: None.
     * Post-conditions: Returns true if the course is full, false otherwise.
     */
    bool isFull() const;

    /*
     * Purpose: Overloaded equality operator to compare two Course objects.
     * Pre-conditions: Course object is passed as an argument for comparison.
     * Post-conditions: Returns true if the courses are equal, false otherwise.
     */
    bool operator==(const Course &other);

    /*
     * Purpose: Method to display a course object.
     * Pre-conditions: the ostream out is open and ready for output.
     * Post-conditions: Course information is displayed on the output stream.
     */
    ostream &displayCourse(ostream &) const;

    /*
     * Purpose: Method to display the list of registered students in a course object, takes ostream as parameter,
       returns a reference to the output stream.
     * Pre-conditions: the ostream out is open and ready for output.
     * Post-conditions: The list of registered students is displayed on the output stream.
     */
    ostream &displayRegisteredStudents(ostream &) const;

private: //Course data fields
    char code[8]; // Course code
    string title; // Course title
    int credits; // Credit hours
    int enrolled; // Number of enrolled students
    int capacity; // Maximum capacity of students
    vector<Student *> enrolledStudents; // List of enrolled students
};

#endif /* COURSE_H */

/*
 * Purpose: Overloaded output stream operator to display course information.
 * Pre-conditions: The output stream, Course object to be displayed.
 * Post-conditions: Course information is displayed on the output stream.
 */
ostream &operator<<(ostream &, Course &);

/*
 * Purpose: Overloaded input stream operator to read course information, returns a reference to the input stream.
 * Pre-conditions: None.
 * Post-conditions: Course information is read from the input stream and stored in the Course object.
 */
istream &operator>>(istream &, Course &);
