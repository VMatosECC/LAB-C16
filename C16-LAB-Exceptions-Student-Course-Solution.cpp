// C16-LAB-Exceptions-Student-Course-App.cpp 
#include <iostream>
#include <vector>
#include <stdexcept>
using namespace std;

class Student {
private:
    string name;
    int    id;

public:
    Student(string name, int id) {
        if (id < 5555) {
            throw runtime_error("Error: " + name + " - Student ID must be at least 5555.");
        }
        this->name = name;
        this->id = id;
    }

    void display() const {
        cout << "Student: " << name << " (ID: " << id << ")" << endl;
    }
};

//-----------------------------------------------------------
class Course {
private:
    string name;
    string room;
    vector<Student*> students;    //Aggregation Design

public:
    Course(string name, string room) {
        if (room == "MBA319" || room == "MBA312") {
            throw runtime_error("Error: Room " + room + " is not allowed.");
        }
        this->name = name;
        this->room = room;
    }

    void addStudent(Student* student) {
        students.push_back(student);
    }

    void display() const {
        cout << "\nCourse: " << name << " (Room: " << room << ")\n";
        cout << "Enrolled Students:\n";
        for (const auto& student : students) {
            student->display();
        }
        cout << endl;
    }
};

//-----------------------------------------------------------

int main() {
    //Raw Student Data (better if read from a file)
    vector<string> studentNames = { "Homer Simpson", "Bart Simpson", "Lisa Simpson", "Marge Simpson", "Maggie Simpson" };
    vector<int> studentIds = { 5678, 4444, 8888, 9000, 7777 };

    vector<Student*> vstudents;

    //Try to create the Student objects, save them in a vector (vstudents)
    for (int i = 0; i < studentNames.size(); i++) {
        try {
            Student* s = new Student(studentNames[i], studentIds[i]);
            vstudents.push_back(s);
        }
        catch (const exception& e) {
            cout << e.what() << endl;
        }
    }

    // Raw Course Data (better if read from a file)
    vector<string> courseNames = { "Math101", "CSCI200" };
    vector<string> courseRooms = { "MBA320", "MBA312" };

    //Try to create the Course objects - save them in a vector (vcourses)
    vector<Course> vcourses;
    for (int i = 0; i < courseNames.size(); i++) {
        try {
            Course c(courseNames[i], courseRooms[i]);
            vcourses.push_back(c);
        }
        catch (const exception& e) {
            cout << e.what() << endl;
        }
    }

    //Try to enroll students in first course Math101
    Course c1 = vcourses[0];

    for (int i = 0; i < vstudents.size(); i++) {
        try
        {
            Student* s = vstudents[i];
            c1.addStudent(s);
        }
        catch (const exception&)
        {
            cout << "Unexpected error creating course " << endl;
        }

    }

    //Showing final results
    c1.display();

    //Cleaning up memory
    for (auto s : vstudents) {
        delete s;
    }

    cout << "\nAll done!\n";
}
