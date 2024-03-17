#include <iostream>

using namespace std;

class Course {
public:
    string code, name;
    int credit_hours;

    Course(string code = "", string name  = "", int ch = 0) : code(code), name(name), credit_hours(ch) {}
};

class Student {
private:
    string id, name;
    Course *courses;
    int num_courses;
public:
    Student(string id, string name) : id(id), name(name), courses(nullptr), num_courses(0) {}

    void enroll(const Course& course) {
        Course *new_courses = new Course[++num_courses];
        // copy courses
        for (int i = 0; i < num_courses-1; i++)
            new_courses[i] = courses[i];
        // delete prev
        delete[] courses;
        // replace with new
        courses = new_courses;
        // assign at end
        courses[num_courses-1] = course;
    }

    void drop(const Course& course) {
        Course *new_courses = new Course[num_courses-1];
        for (int i = 0, j = 0; i < num_courses; i++, j++) {
            if (courses[i].code == course.code) {
                j--;
                continue;
            }
            new_courses[j] = courses[j];
        }
        delete[] courses;
        courses = new_courses;
        --num_courses;
    }

    int getTotalCreditHours() {
        int ch = 0;
        for (int i = 0; i < num_courses; i++)
            ch += courses[i].credit_hours;
        return ch;
    }

    void printEnrolledCourses() {
        for (int i = 0; i < num_courses; i++) {
            cout << "Course[" << i+1 << "]\n";
            cout << "Code: " << courses[i].code << "\n"; 
            cout << "Name: " << courses[i].name << "\n";
            cout << "Credit Hours: " << courses[i].credit_hours << "\n\n";
        }
    }
};

int main() {
    Course pf("1", "Programming Fundamentals", 3);
    Course oop("2", "Object Oriented Programming", 3);
    Course ew("3", "Expository Writing", 2);

    Student student("1", "Fasih");

    student.enroll(pf);
    student.enroll(oop);
    student.enroll(ew);

    student.printEnrolledCourses();
    student.drop(oop);
    cout << "Total Credit Hours: " << student.getTotalCreditHours() << endl;

    cout << endl;
    student.printEnrolledCourses();

    return 0;
}