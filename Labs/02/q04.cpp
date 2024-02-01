/*
 * Creator: Fasih Hasan
 * Date: 1/2/24
 * Desc: A student struct that inherits from Register struct. 
 * Take inputs and display the information
 */

#include <iostream>

#define MAX_STUDENTS 1

using namespace std;

struct Register {
    int courseId;
    string courseName;
};

struct Student : public Register {
    int studentId;
    string firstName;
    string lastName;
    int cellNo;
    string email;
};

void input(Student *arr) {
    for (int i = 0; i < MAX_STUDENTS; i++) {
        cout << "Student " << i+1 << endl << "Enter student ID: ";
        cin >> arr[i].studentId;

        cout << "Enter first name: ";
        cin >> arr[i].firstName;
        
        cout << "Enter last name: ";
        cin >> arr[i].lastName;
        
        cout << "Enter cell number: ";
        cin >> arr[i].cellNo;

        cout << "Enter email address: ";
        cin >> arr[i].email;

        cout << "Enter course ID: ";
        cin >> arr[i].courseId;
        
        cout << "Enter course name: ";
        cin >> arr[i].courseName;
    }
}

void output(Student *arr) {
    for (int i = 0; i < MAX_STUDENTS; i++) {
        cout << "Student " << i+1 << endl;
        cout << "Student ID: " + arr[i].studentId << endl;
        cout << "First name: " + arr[i].firstName << endl;
        cout << "Last name: " + arr[i].lastName << endl;
        cout << "Cell number: " + arr[i].cellNo << endl;
        cout << "Email address: " + arr[i].email << endl;
        cout << "Course ID: " + arr[i].courseId << endl;
        cout << "Course name: " + arr[i].courseName << endl;
    }
}

int main() {
    Student std_arr[MAX_STUDENTS];

    input(std_arr);
    cout << endl;
    output(std_arr);

    return 0;
}
