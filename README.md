# Student Registration System

This project implements a basic command-line application for advisors to manage student registration, developed in the context of **CSIS216 Data Structures** (Fall 2023-2024). The application leverages custom linked list implementations:

* **DoublyLinkedList** for managing students
* **LListWithDummyNode** for managing courses

## Features

* **Load Data**:

  * Read non-registered students from `students.txt` into a `DoublyLinkedList<Student>` named `nonRegisteredStudents`.
  * Read offered courses from `courses.txt` into both an array and `LListWithDummyNode<Course>` named `offeredCourses`.

* **Interactive Menu**: Presents the advisor with options to:

  1. Display non-registered students
  2. Display offered courses
  3. Display registered students with their courses
  4. Display offered courses with enrolled students
  5. Display registered courses for a specific student
  6. Display the list of students registered in a specific course
  7. Display detailed information for a specific student
  8. Register a student in one or more courses
  9. Add or drop courses for an already registered student
  10. Quit the application

* **User-Friendly Prompts**: Clear instructions guide the advisor through registration, error handling, and menu navigation.

## Design & Implementation

### Classes

#### `Student`

* **Fields**: `id` (string), `firstName` (string), `lastName` (string), `gpa` (double), `status` (enum AcademicStatus: `Regular` or `Probation`)
* **Member Functions**: Constructors, getters/setters, `print()` overloads

#### `Course`

* **Fields**: `code` (string), `title` (string), `credits` (int), `capacity` (int), `enrolled` (int)
* **Member Functions**: Constructors, getters/setters, `print()`, enrollment management

#### `LListWithDummyNode<Course>`

* **Data Fields**: `myFirst` (pointer to dummy `Node`), `mySize` (int)
* **Nested `Node`**: Holds `Course` data and pointer to next node
* **Operations**: `insert()`, `remove()`, `find()`, `isEmpty()`, iterator support, overloads for `operator>>` and `operator<<`

#### `DoublyLinkedList<Student>`

* **Data Fields**: `myFirst` (pointer to first `DNode`), `mySize` (int)
* **Nested `DNode`**: Holds `Student` data, pointers to next and previous nodes
* **Operations**: `insert()`, `remove()`, `find()`, `isEmpty()`, iterator support, overloads for `operator>>` and `operator<<`

## Input File Formats

### `students.txt`

```
<number_of_students>
<studentID> <firstName> <lastName> <GPA>
... (one per line)
```

**Example:**

```
10
A2101324 Bilal Issa 3.5
A2101444 John Dow 2.7
... etc.
```

### `courses.txt`

```
<number_of_courses>
<courseCode> <title (spaces allowed)> <credits> <capacity>
... (one per line)
```

**Example:**

```
6
CSIS200 Introduction to programming 3 10
ENGL101 English 6 25
... etc.
```

## Build & Run Instructions

1. **Compile** (assuming GNU g++ and C++11 support):

   ```bash
   g++ -std=c++11 -o registration \
     main.cpp \
     Student.cpp Student.h \
     Course.cpp Course.h \
     LListWithDummyNode.cpp LListWithDummyNode.h \
     DoublyLinkedList.cpp DoublyLinkedList.h
   ```

2. **Execute**:

   ```bash
   ./registration
   ```

3. **Follow On-Screen Menu** to perform registration tasks.

## Sample Run

A sample interaction is provided at the end of the project specification (`CSIS216 Project Fall 23-24.pdf`). It demonstrates menu navigation, handling invalid inputs, and viewing registration summaries.

## Project Structure

```
├── students.txt         # Input file for student data
├── courses.txt          # Input file for course data
├── Student.h / Student.cpp
├── Course.h / Course.cpp
├── LListWithDummyNode.h / LListWithDummyNode.cpp
├── DoublyLinkedList.h / DoublyLinkedList.cpp
└── main.cpp             # Driver and menu implementation
```

## Author

* Tony Dawra

---
