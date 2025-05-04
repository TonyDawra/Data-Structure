#include "Course.h"
#include "DoublyLinkedList.h"
#include "LListWithDummyNode.h"
#include "Student.h"
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

// Function prototypes
void displayMenu();
/*------------------------------------------------------------------------------
  Display Menu

  Precondition: None
  Post-Condition: Menu is displayed.
-------------------------------------------------------------------------------*/

void handleUserInput(int choice, DoublyLinkedList& nonRegisteredStudents,
    DoublyLinkedList& RegisteredStudents,
    LListWithDummyNode& offeredCourses);
/*------------------------------------------------------------------------------
  Handles user input

  Precondition: None
  Post-Condition: Desired action of user is executed
-------------------------------------------------------------------------------*/

void displayListOfNonRegisteredStudents(
    DoublyLinkedList& nonRegisteredStudents);
/*------------------------------------------------------------------------------
  Display list of non-registered students

  Precondition: None
  Post-Condition: List of non-registered students is displayed
-------------------------------------------------------------------------------*/

void displayListOfOfferedCourses(LListWithDummyNode& offeredCourses);
/*------------------------------------------------------------------------------
  Display list of offered courses

  Precondition: None
  Post-Condition: List of offered courses is displayed
-------------------------------------------------------------------------------*/

void displayRegisteredStudentsWithCourses(DoublyLinkedList& RegisteredStudents);
/*------------------------------------------------------------------------------
  Display Registered Students with their respective Courses

  Precondition: None
  Post-Condition: List of Registered Students with their respective Courses is
                  displayed.
-------------------------------------------------------------------------------*/

void displayCoursesWithRegisteredStudents(LListWithDummyNode& offeredCourses);
/*------------------------------------------------------------------------------
  Display Courses with their respective registered Students

  Precondition: None
  Post-Condition: List of courses with their respective registered Students is
                  displayed.
------------------------------------------------------------------------------*/

void displayRegisteredCoursesForStudent(DoublyLinkedList& RegisteredStudents);
/*------------------------------------------------------------------------------
  Display registered Courses for a given student

  Precondition: None
  Post-Condition: List of registered courses for a given Student is displayed.
-------------------------------------------------------------------------------*/

void displayStudentsInCourse(LListWithDummyNode& offeredCourses);
/*------------------------------------------------------------------------------
  Display list of students registered in a given course

  Precondition: None
  Post-Condition: List of Students registered in a given Course is displayed.
 -------------------------------------------------------------------------------*/

void displayStudentInfo(DoublyLinkedList& RegisteredStudents);
/*------------------------------------------------------------------------------
  Display Registered Students with their respective Courses

  Precondition: None
  Post-Condition: List of Registered Students with their respective Courses is
                  displayed.
 -------------------------------------------------------------------------------*/

void registerStudent(DoublyLinkedList& nonRegisteredStudents,
    DoublyLinkedList& RegisteredStudents,
    LListWithDummyNode& offeredCourses);
/*------------------------------------------------------------------------------
  Register a student in given course(s)

  Precondition: None
  Post-Condition: Student is moved from list of non-registered students to list
                  of registered students; and is registered in given course(s).
 -------------------------------------------------------------------------------*/

void addOrDropStudent(DoublyLinkedList& nonRegisteredStudents, DoublyLinkedList& RegisteredStudents,
    LListWithDummyNode& offeredCourses);
/*------------------------------------------------------------------------------
  Add or Drop given Student from given course(s)

  Precondition: None
  Post-Condition: Given course(s) are added/dropped for a given student.
-------------------------------------------------------------------------------*/

// Main function
int main() {

    // Declare and initialize lists for nonRegisteredStudents, RegisteredStudents, and offeredCourses
    DoublyLinkedList nonRegisteredStudents;
    DoublyLinkedList RegisteredStudents;
    LListWithDummyNode offeredCourses;

    // Input file streams for student.txt and course.txt data
    ifstream inputFileStudent, inputFileCourse;
    ofstream outputFile;

    // Opening the student.txt
    inputFileStudent.open("student.txt");

    // Checking if it did open if not send error message
    if (inputFileStudent.fail()) {
        cerr << "student.txt could not open\n";
        return 1;
    }

    // Opening the couses.txt
    inputFileCourse.open("courses.txt");

    // Checking if it did open if not send error message
    if (inputFileCourse.fail()) {
        cerr << "course.txt could not open\n";
        return 1;
    }

    // Reading the first line from student.txt and declare and initialize numberOfStudents
    int numberOfStudents;
    inputFileStudent >> numberOfStudents;
    for (int i = 0; i < numberOfStudents; ++i) {
        Student* student = new Student();
        inputFileStudent >> *student;
        nonRegisteredStudents.insertAtEnd(student);
    }
    inputFileStudent.close();

    // Reading the first line from student.txt and declare and initialize numberOfCourses
    int numberOfCourses;
    inputFileCourse >> numberOfCourses;
    for (int j = 0; j < numberOfCourses; ++j) {
        Course* course = new Course();
        inputFileCourse >> *course;
        offeredCourses.insertAtEnd(course);
    }
    inputFileCourse.close();

    int choice = 0;

    // DisplayMenu and handleUserInput until the users decides to quit
    do {
        displayMenu();
        cin >> choice;
        cout << "\n";
        handleUserInput(choice, nonRegisteredStudents, RegisteredStudents,
            offeredCourses);
    } while (0 < choice && choice < 10);
    return 0;
}

// Function display menu
void displayMenu() {
    cout << "1. Display the list of non-registered students.\n";
    cout << "2. Display the list of offered courses.\n";
    cout << "3. Display the list of registered students with the registered "
        "courses.\n";
    cout << "4. Display the list of offered courses with the registered "
        "students.\n";
    cout << "5. Display the registered courses for a student.\n";
    cout << "6. Display the list of students registered in a course.\n";
    cout << "7. Display the information related to a specific student.\n";
    cout << "8. Register a student.\n";
    cout << "9. Choose a student to add/drop a course for him/her.\n";
    cout << "10. Quit the application.\n\n";
    cout << "Enter your choice: ";
}

// Function to handle user input and his executes the choice of the user
void handleUserInput(int choice, DoublyLinkedList& nonRegisteredStudents,
    DoublyLinkedList& RegisteredStudents,
    LListWithDummyNode& offeredCourses) {



    switch (choice) {
    case 1:
        displayListOfNonRegisteredStudents(nonRegisteredStudents);
        break;
    case 2:
        displayListOfOfferedCourses(offeredCourses);
        break;
    case 3:
        displayRegisteredStudentsWithCourses(RegisteredStudents);
        break;
    case 4:
        displayCoursesWithRegisteredStudents(offeredCourses);
        break;
    case 5:
        displayRegisteredCoursesForStudent(RegisteredStudents);
        break;
    case 6:
        displayStudentsInCourse(offeredCourses);
        break;
    case 7:
        displayStudentInfo(RegisteredStudents);
        break;
    case 8:
        registerStudent(nonRegisteredStudents, RegisteredStudents, offeredCourses);
        break;
    case 9:
        addOrDropStudent(nonRegisteredStudents, RegisteredStudents, offeredCourses);
        break;
    case 10:
        break;
    default:
        cout << "Invalid choice. Choose a valid option from the menu";
        return;
    }
}

// Function to display the list of non-registered students
void displayListOfNonRegisteredStudents(
    DoublyLinkedList& nonRegisteredStudents) {

    cout << "Students that did not register yet:" << endl;
    // Checking if nonRegisteredStudents isEmpty
    if (nonRegisteredStudents.isEmpty()) {
        cout << "All students are registered" << endl;
        return;
    }
    cout << "ID\t\t"
        << "Name\t\t"
        << "GPA\t"
        << "Academic Status" << endl;

    nonRegisteredStudents.display(cout);
}

// Function to display the list of offered courses
void displayListOfOfferedCourses(LListWithDummyNode& offeredCourses) {

// Checking if offeredCourses isEmpty if not display error message
    if (offeredCourses.isEmpty()) {
        cout << "No course are being offered" << endl;
        return;
    }
    int nbOfOfferedCourses = offeredCourses.getmySize();
    cout << "Code\t"
        << "Title\t\t\t\t"
        << "#Credits\t"
        << "Enrolled\t"
        << "Capacity" << endl;

    offeredCourses.display(cout);
}

// Function to display the list of registered students with their registered courses
void displayRegisteredStudentsWithCourses(
    DoublyLinkedList& RegisteredStudents) {
    for (int i = 0; i < RegisteredStudents.size(); i++) {
        Student* student = RegisteredStudents.at(i);
        student->displayStudentWithCourse(cout);
        cout << endl;
    }
}

// Function to display the list of courses with their registered students
void displayCoursesWithRegisteredStudents(LListWithDummyNode& offeredCourses) {
    for (int i = 0; i < offeredCourses.getmySize(); i++) {
        Course* course = offeredCourses.at(i);
        course->displayRegisteredStudents(cout);
    }
}

// Function to display the registered courses for a specific student
void displayRegisteredCoursesForStudent(DoublyLinkedList& RegisteredStudents) {
    string id;
    cout << "Enter the student id: ";
    cin >> id;

    Student* student = nullptr;

    // Search for the student in the RegisteredStudents list
    for (int i = 0; i < RegisteredStudents.size(); ++i) {
        student = RegisteredStudents.at(i);
        if (student->getid() == id) {
            break;
        }
        student = NULL;
    }

    // If the student is not found display an error message
    if (student == NULL) {
        cout << "Student not registered in any courses.\n";
        return;
    }

    student->displayStudentWithCourse(cout);

    cout << endl;
}

// Function to display students enrolled in a specific course
void displayStudentsInCourse(LListWithDummyNode& offeredCourses) {
    char code[8]{};
    cout << "Enter the course: ";

    // Input the course code
    for (int i = 0; i < 7; i++) {
        cin >> code[i];
    }
    code[7] = '\0';

    Course* course = nullptr;

    // Search for the course in the offeredCourses list
    for (int i = 0; i < offeredCourses.getmySize(); ++i) {
        course = offeredCourses.at(i);

        if (course->getCode() == string(code)) {
            break;
        }

        course = NULL;
    }

    // If the course is not found display an error message
    if (course == NULL) {
        cerr << "Course does not exist\n";
        return;
    }
    course->displayRegisteredStudents(cout);
}

// Function to display information about a specific student
void displayStudentInfo(DoublyLinkedList& RegisteredStudents) {
    string id;
    cout << "Enter the student ID: ";
    cin >> id;
    Student s;
    s.setid(id);

    Student* student = nullptr;

    // Search for the student in the RegisteredStudents list
    for (int i = 0; i < RegisteredStudents.size(); ++i) {
        student = RegisteredStudents.at(i);

        if (student->getid() == id) {
            break;
        }

        student = NULL;
    }

    // If the student is not found display an error message
    if (student == NULL) {
        cerr << "Student not found.\n";
        return;
    }

    cout << "Student : \n\tID: " << student->getid()
        << "\n\tName: " << student->getfirstname() << " " << student->getlastname()
        << "\n\tMajor: " << student->getmajor() << "\n\tGPA: " << student->getGPA();

    cout << endl;
}

// Function to register a student in courses
void registerStudent(DoublyLinkedList& nonRegisteredStudents,
    DoublyLinkedList& RegisteredStudents,
    LListWithDummyNode& offeredCourses) {

    string id;
    cout << "Enter the student ID: ";
    cin >> id;

    Student* student = nullptr;

    // Search for the student in the nonRegisteredStudents list
    for (int i = 0; i < nonRegisteredStudents.size(); ++i) {
        student = nonRegisteredStudents.at(i);

        if (student->getid() == id) {
            break;
        }
        student = NULL;
    }

    int pos = nonRegisteredStudents.search(student);
    bool isRegistered = false;

    // If the student is not found in nonRegisteredStudents search in RegisteredStudents
    if (student == NULL) {
        for (int i = 0; i < RegisteredStudents.size(); ++i) {
            student = RegisteredStudents.at(i);

            if (student->getid() == id) {
                break;
            }

            student = NULL;
        }
        isRegistered = true;
        if (student == NULL) {
            cerr << "Student not found\n";
            return;
        }
    }

    // infinite Loop to register the student in one or more courses until the users enter not to continue
    while (true) {

        string code;
        cout << "Enter the course code: ";
        cin >> code;

        Course* course = nullptr;

        // Search for the course in the offeredCourses list
        for (int i = 0; i < offeredCourses.getmySize(); ++i) {
            course = offeredCourses.at(i);

            if (course->getCode() == code) {
                break;
            }
            course = NULL;
        }

        // If the course is not found display an error message
        if (course == NULL) {
            cout << "The course is not offered\n";
            continue;
        }

        // Add the student to the course
        course->addStudent(student);
        cout << "Student registerd.\n" << endl;

        // Ask the user if they want to add more courses
        cout << "Do you need to add more courses [Y] yes or [N] no: ";

        char choice = 'Y';
        cin >> choice;

        // Checking if the user want to continue
        if (choice == 'Y' || choice == 'y') continue;
        if (choice == 'N' || choice == 'n') break;
        cout << "Invalid choice, breaking operation";
        break;
    }

    // If the student was initially non-registered, update the lists
    if (!isRegistered) {
        nonRegisteredStudents.deleteAtPos(pos);

        RegisteredStudents.insertAtEnd(student);
    }
}

// Function to add or drop a student from courses
void addOrDropStudent(DoublyLinkedList& nonRegisteredStudents, DoublyLinkedList& RegisteredStudents,
    LListWithDummyNode& offeredCourses) {
    string id;
    cout << "Enter the student ID: ";
    cin >> id;

    Student* student = nullptr;

    // Search for the student in the nonRegisteredStudents list
    for (int i = 0; i < nonRegisteredStudents.size(); ++i) {
        student = nonRegisteredStudents.at(i);

        if (student->getid() == id) {
            break;
        }
        student = NULL;
    }

    int pos = nonRegisteredStudents.search(student);
    bool isRegistered = false;

    // If the student is not found in nonRegisteredStudents search in RegisteredStudents
    if (student == NULL) {
        for (int i = 0; i < RegisteredStudents.size(); ++i) {
            student = RegisteredStudents.at(i);

            if (student->getid() == id) {
                break;
            }
            student = NULL;
        }
        isRegistered = true;
        if (student == NULL) {
            cerr << "Student not found\n";
            return;
        }
    }

    // Loop to add or drop courses for the student until the uses says otherwise
    while (true) {
        char choice;
        cout << "Add course [A] or Drop course [D]: ";
        cin >> choice;

        // Check if the user choice is to add a course
        if (choice == 'A' || choice == 'a') {
            char code[8];
            cout << "Choose course code: ";
            
            // Input the course code
            for (int i = 0; i < 7; ++i) {
                cin >> code[i];
            }
            code[7] = '\0';

            Course* course = nullptr;

            // Search for the course in the offeredCourses list
            for (int i = 0; i < offeredCourses.getmySize(); ++i) {
                course = offeredCourses.at(i);
                if (course->getCode() == string(code)) {
                    break;
                }
                course = NULL;
            }

            // If the course is not found display an error message
            if (course == NULL) {
                cout << "Course not found." << endl;
                cout << "Do you want to continue [Y] yes or [N] no: ";
                cin >> choice;

                // Checking if the user want to continue
                if (choice == 'Y' || choice == 'y') {
                    continue;
                }
                else {
                    break;
                }
            }

            // Add the student to the course
            course->addStudent(student);
            cout << "Course added successfully." << endl;

            if (!isRegistered) {
                nonRegisteredStudents.deleteAtPos(pos);
                RegisteredStudents.insertAtEnd(student);
            }
        }

        // Check if the user choice is to drop a course
        else if (choice == 'D' || choice == 'd') {
            char code[8];
            cout << "Choose course code: ";

            // Input the course code
            for (int i = 0; i < 7; ++i) {
                cin >> code[i];
            }
            code[7] = '\0';

            Course* course = nullptr;

            // Search for the course in the offeredCourses list
            for (int i = 0; i < offeredCourses.getmySize(); ++i) {
                course = offeredCourses.at(i);

                if (course->getCode() == string(code)) {
                    break;
                }
                course = NULL;
            }

            // If the course is not found display an error message
            if (course == NULL) {
                cout << "Course not found." << endl;
                cout << "Do you want to continue [Y] yes or [N] no: ";
                cin >> choice;

                // Checking if the user want to continue
                if (choice == 'Y' || choice == 'y') {
                    continue;
                }
                else {
                    break;
                }
            }

            // Drop the student from the course
            course->dropStudent(student);

            // Check if the student is no longer registered in any courses
            vector<Course*> registered = student->getregisteredcourse();
            if (registered.empty()) {

                // If not registered update the lists
                pos = RegisteredStudents.search(student);
                RegisteredStudents.deleteAtPos(pos);

                pos = nonRegisteredStudents.size();
                nonRegisteredStudents.insertAtEnd(student);
                isRegistered = false;
            }
        }

        // Ask the user if they want to continue
        cout << "Do you want to continue [Y] yes or [N] no: ";
        cin >> choice;

        if (choice == 'N' || choice == 'n') {
            break;
        }
    }

}