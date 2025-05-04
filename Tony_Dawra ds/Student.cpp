#include "Student.h"
#include "Course.h"
#include <algorithm>
#include <istream>
#include <ostream>

int Student::nbOfstds = 0;

// Default Constructor
Student::Student() : id(""), firstname(""), lastname(""), gpa(0.0), major("computer science") {
    nbOfstds++;
}

// Constructor with all parameters: ID, First Name, Last Name, GPA, and Major
Student::Student(const string& id, const string& firstname = "",
    const string& lastname = "", double gpa = 0.0,
    string major = "computer science")
    : id(id), firstname(firstname), lastname(lastname), gpa(gpa), major(major) {
    nbOfstds++;
}

bool Student::operator==(const Student& other) { return id == other.id; }

// Copy Constructor
Student::Student(const Student& other)
    : Student(other.id, other.firstname, other.lastname, other.gpa,
        other.major) {
    nbOfstds++;
}

// Destructor
Student::~Student() {
    for (int i = 0; i < registeredcourses.size(); ++i) {
        delete registeredcourses[i];
    }
    nbOfstds--;
}

// Getter implementations
string Student::getid() const { return id; }

string Student::getfirstname() const { return firstname; }

string Student::getlastname() const { return lastname; }

double Student::getGPA() const { return gpa; }

string Student::getAS() const {
    if (this->gpa < 2) {
        return "Probation";
    }
    return "Regular";
}

bool Student::isreg() const { return reg; }

string Student::getmajor() const { return major; }

// setters implementation

void Student::setid(const string& id) {
    if (id[0] == 'A' ||
        id[0] == 'a' && id.size() == 8) { // checking if the id is format is valid
        // starting with A and has 8 characters
        this->id = id;
    }
    else
        cerr << "invalid id";
}

void Student::setfirstname(const string& firstname) {
    this->firstname = firstname;
}

void Student::setlastname(const string& lastname) { this->lastname = lastname; }

void Student::setGPA(double gpa1) {
    if (gpa1 < 0.0) { // check if gpa is valid
        gpa = 0.0;
    }
    else if (gpa1 > 4.0) {
        gpa = 4.0;
    }
    else
        this->gpa = gpa1;
    setAS();
}

void Student::setAS() {
    if (gpa < 2) {
        this->academicstatus = "probation";
    }
    this->academicstatus = "regular";
}

void Student::setreg(bool choice) { this->reg = choice; }

void Student::setmajor(string maj) { this->major = maj; }

// Display student information implementation
ostream& Student::displayall(ostream& out) const {
    out << getid() << "\t" << getlastname() << ", " << getfirstname() << "\t\t"
        << getGPA() << "    " << getAS() << endl;
    return out;
}

ostream& Student::display(ostream& out) const {
    out << getid() << "  " << getlastname() << "," << getfirstname();
    return out;
}

ostream& Student::displayStudentWithCourse(ostream& out) const {

    out << "Student : " << getid() << "-" << getlastname() << ", "
        << getfirstname() << endl;

    displayregisteredcourses(out);

    return out;
}

ostream& operator<<(ostream& out, const Student& student) {
    out << student.getid() << "\t";
    out << student.getfirstname() << ", " << student.getlastname() << "\t";
    out << student.getGPA() << "\t" << student.getAS();
    return out;
}

// course related functions
void Student::registercourse(Course* course) {
    registeredcourses.push_back(course);
}

void Student::displayregisteredcourses(ostream& out) const {
    for (int i = 0; i < registeredcourses.size(); ++i) {
        out << "-   " << registeredcourses[i]->getCode() << endl;
    }
}

vector<Course*> Student::getregisteredcourse() {
    return registeredcourses;
}


istream& operator>>(istream& in, Student& student) {

    string id;
    string firstName;
    string lastName;
    double gpa;

    in >> id >> firstName >> lastName >> gpa;

    student.setid(id);
    student.setfirstname(firstName);
    student.setlastname(lastName);
    student.setGPA(gpa);
    student.setAS();

    return in;
}

void Student::dropcourse(Course* course) {
    auto it = find(registeredcourses.begin(), registeredcourses.end(), course);
    if (it != registeredcourses.end()) {
        registeredcourses.erase(it);
        cout << "Course dropped successfully" << endl;
    }
    else {
        cout << "Course not found." << endl;
    }
}
