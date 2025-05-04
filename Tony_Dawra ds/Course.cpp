//Implementation file for the members functions of class Course
#include "Course.h"
#include "Student.h"
#include <algorithm>
#include <iostream>
#include <istream>
#include <ostream>
#include <vector>
#include <iomanip>

//Default constructor for the Course class.
Course::Course() {}

//Parameterized constructor which takes course code, title, credits, and capacity.
Course::Course(char cCode[7], string cTitle, int credit, int cap) {
    title = cTitle;
    credits = credit;
    enrolled = 0;
    capacity = cap;
    for (int i = 0; i < 7; i++)
        code[i] = cCode[i];

    code[7] = '\0';
}

//Copy constructor for the Course class.
Course::Course(const Course &orig) {
    title = orig.title;
    credits = orig.credits;
    enrolled = orig.enrolled;
    capacity = orig.capacity;
    for (int i = 0; i < 8; i++)
        code[i] = orig.code[i];
}

//Setter method to set the course code.
void Course::setCode(char code[7]) {
    for (int i = 0; i < 7; i++) {
        this->code[i] = code[i];
    }
    this->code[7] = '\0';
}

//Setter method to set the course title.
void Course::setTitle(string title) {
    this->title = title;
}

//Setter method to set the course credits.
void Course::setCredits(int credits) {
    //Check if the input credits are valid
    if (credits < 0) { 
        cerr << "Credit amount shouldnt be lower or equal to 0.\n";
        return;
    }

    this->credits = credits;
}

//Setter method to set the course capacity.
void Course::setCapacity(int capacity) {
    //Check if the capacity is valid
    if (capacity < enrolledStudents.size()) { 
        cerr << "Can't set capacity to lower than enrolled students.\n";
        return;
    }

    this->capacity = capacity;
}


//Getter method to retrieve the course code.
string Course::getCode() const {
    return code;
}

//Getter method to retrieve the course title.
string Course::getTitle() const {
    return title;
}

//Getter method to retrieve the course capacity.
int Course::getCapacity() const {
    return capacity;
}

//Getter method to retrieve the course credits.
int Course::getCredits() const {
    return credits;
}

//Getter method to retrieve the number of students enrolled in the course.
int Course::getEnrolled() const {
    return enrolledStudents.size();
}

//Overloaded equality operator to compare two Course objects.
bool Course::operator==(const Course &other) {
    for (int i = 0; i < 7; i++) {
        if (other.code[i] != code[i])
            return false;
    }
    return true;
}

//Checks if the course is full (reached its maximum capacity of students).
bool Course::isFull() const {
    return enrolledStudents.size() == capacity;
}

//Method to add a student to the list of enrolled students in the course.
void Course::addStudent(Student *student) {
    //Check if the course is already full
    if (isFull()) {
        cerr << "course is full";
        return;
    }
    //Register the student to the course and add them to the list of enrolled students.
    student->registercourse(this);
    enrolledStudents.push_back(student);
}

//Method to drop a student from the list of enrolled students in the course.
void Course::dropStudent(Student *student) {
    //Find the student in the list of enrolled students.
    auto toRemove =
            find(enrolledStudents.begin(), enrolledStudents.end(), student);

    //Check if the student is not in the course.
    if (toRemove == enrolledStudents.end()) { 
        cerr << "Student not in course";
        return;
    }
    
    //Drop the student from the course and remove them from the list of enrolled students.
    student->dropcourse(this); 
    enrolledStudents.erase(toRemove);
}

//Method to display course information on the output stream.
ostream &Course::displayCourse(ostream &out) const {
    out << getCode() << '\t' << getTitle() << '\t' << getCredits() << '\t'
        << getEnrolled() << '\t' << getCapacity() << endl;
    return out;
}

//Method to display the list of registered students in the course on the output stream.
ostream &Course::displayRegisteredStudents(ostream &out) const {
    out << "Course: " << getCode() << "-" << getTitle() << endl;
    for (Student *s: enrolledStudents) {
        out << s->getid() << " " << s->getlastname() << ", " << s->getfirstname()  << endl;
    }
    return out;
}

//Overloaded input stream operator to read course information.
istream &operator>>(istream &in, Course &course) {
    char code[8];
    for (int i = 0; i < 7; ++i) {
        in >> code[i];
    }

    code[7] = '\0';
    course.setCode(code);

    string title;
    in >> ws;

    while (!isdigit(in.peek())){
        title += (char) in.get();
    }

    course.setTitle(title);

    int credits;
    in >> credits;

    course.setCredits(credits);

    int capacity;
    in >> capacity;

    course.setCapacity(capacity);

    return in;
}

//Overloaded output stream operator to display course information.
ostream& operator<<(ostream& out, Course& course) {
    out << course.getCode() << '\t' << left << setw(25) << course.getTitle() << "\t" << course.getCredits() << "\t\t" << course.getEnrolled()
        << "\t\t" << course.getCapacity();
    return out;
}
