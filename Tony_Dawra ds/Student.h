/*-- Student.h
---------------------------------------------------------------

By Anwar Fares.

This header file defines the Student data type.
  Basic operations:
    no-arg constructor             : Constructs a default Student
    copy constructor               : Constructs a new Stuendt using existing Student parameter 
    destructor                     : Deletes a Student 
    set/getfirstname			   : Set or Get the first name of a Student
    set/getlastname                : Set or Get the last name of a Student
    set/getid					   : Set or Get the id of a Student
    set/getGPA					   : Set or Get the GPA of a Student 
    set/getAS	                   : Set or Get the academic status of a Student
    set/isreg					   : Set or check if Student is registered at least to 1 course 
    set/getmajor				   : Set or Get the major of a Student
    displayall					   : Display all parameters of a Student
    display						   : Display certain parameters of a Student
    displayStudentWithCourse       : Display registered Students
...
-------------------------------------------------------------------------*/

#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <istream>
#include <ostream>
#include <string>
#include <vector>

using namespace std;

class Course;

class Student {

public:
    // Default constructor
    Student();
    /********************************************************************
            * Purpose: Construct a default Student object.
            * Precondition: None.
            * Postcondition: A Student object is created with default values.
            ********************************************************************/
            
    // Constructor with ID, first name, last name, GPA, and registered status
    Student(const string& id, const string& firstname, const string& lastname,
        double gpa, string major);
    /********************************************************************
            * Purpose: Construct a Student object with specified attributes.
            * Precondition: Valid input values are provided.
            * Postcondition: A Student object is created with the provided attributes.
            ********************************************************************/
    
    // Copy Constructor
    Student(const Student& other);
    /********************************************************************
            * Purpose: Create a copy of an existing Student object.
            * Precondition: A valid Student object is provided.
            * Postcondition: A new Student object is created as a copy of the provided object.
            ********************************************************************/
            
    // Destructor
    virtual ~Student();
    /********************************************************************
            * Purpose: Clean up resources when a Student object is destroyed.
            * Precondition: None.
            * Postcondition: The Student object is destructed, and any allocated resources are released.
            ********************************************************************/
    
    // Getters
    string getfirstname() const;
    string getlastname() const;
    string getid() const;
    double getGPA() const;
    string getAS() const;
    bool isreg() const;
    string getmajor() const;

    // Setters
    void setfirstname(const string&);
    void setlastname(const string&);
    void setid(const string&);
    void setGPA(double);
    /********************************************************************
            * Purpose: Set the GPA of the Student.
            * Precondition: A valid GPA value is provided.
            * Postcondition: The GPA of the Student is updated.
            ********************************************************************/
    
    // Set academic status based on GPA
    void setAS();
    /********************************************************************
            * Purpose: Set the academic status based on the GPA of the Student.
            * Precondition: None.
            * Postcondition: The academic status of the Student is updated.
            ********************************************************************/
    
    // Set registration status
    void setreg(bool);
    /********************************************************************
            * Purpose: Set the registration status of the Student.
            * Precondition: None.
            * Postcondition: The registration status of the Student is updated.
            ********************************************************************/
    
    // Set major
    void setmajor(string);
    /********************************************************************
            * Purpose: Set the major of the Student.
            * Precondition: A valid major value is provided.
            * Postcondition: The major of the Student is updated.
            ********************************************************************/
    
    bool operator==(const Student& other);
    /********************************************************************
            * Purpose: Compare two Student objects for equality.
            * Precondition: Two valid Student objects are provided.
            * Postcondition: Returns true if the objects are equal; otherwise, returns false.
            ********************************************************************/
    
    // Display student information
    ostream& displayall(ostream&) const;
    ostream& display(ostream&) const;
    ostream& displayStudentWithCourse(ostream& out) const;

    // Friend function to overload << operator
    friend ostream& operator<<(ostream&, const Student&);
    
    // Course related functions
    
    // Register for a course
    void registercourse(Course*);
    /********************************************************************
            * Purpose: Register the Student for a course.
            * Precondition: A valid Course object is provided.
            * Postcondition: The Student is registered for the course.
            ********************************************************************/
    
    // Display registered courses
    void displayregisteredcourses(ostream&) const;
    /********************************************************************
            * Purpose: Display information about the courses the Student is registered for.
            * Precondition: None.
            * Postcondition: Information about the registered courses is displayed.
            ********************************************************************/
    
    // Drop a course
    void dropcourse(Course*);
    /********************************************************************
            * Purpose: Drop a course that the Student is registered for.
            * Precondition: The Student is already registered for the course.
            * Postcondition: The Student is no longer registered for the course.
            * The list of registered courses is appropriately updated.
            ********************************************************************/
    
    // Get vector of registered courses
    vector<Course*> getregisteredcourse();
    /********************************************************************
            * Purpose: Get a vector containing pointers to the courses the Student is registered for.
            * Precondition: None.
            * Postcondition: Returns a vector containing pointers to registered courses.
            ********************************************************************/
    
private:
    static int nbOfstds;
    string id;
    string firstname;
    string lastname;
    double gpa;
    bool reg;
    string major;
    string academicstatus;
    // course class data fields
    vector<Course*> registeredcourses;
};

istream& operator>>(istream&, Student&);

#endif

