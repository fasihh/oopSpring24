#include <iostream>

typedef struct {
    int math, eng, sci, total;
    float avg;
    char grade;
} Student;

Student get_input() {
    Student student;

    std::cout << "Math: ";
    std::cin >> student.math;
    std::cout << "English: ";
    std::cin >> student.eng;
    std::cout << "Science: ";
    std::cin >> student.sci;

    return student;
}

char get_grade(int marks) {
    if (marks >= 90) {
        return 'A';
    } else if (marks >= 80) {
        return 'B';
    } else if (marks >= 70) {
        return 'C';
    } else if (marks >= 60) {
        return 'D';
    }
    return 'F';
}

int main() {
    int students;

    std::cout << "Enter number of students: ";
    std::cin >> students;

    Student *student_arr = new Student[students];

    for (int i = 0; i < students; i++) {
        std::cout << "Student " << i+1 << std::endl;
        student_arr[i] = get_input();
        std::cout << "\n";

        student_arr[i].total = student_arr[i].math + student_arr[i].eng + student_arr[i].sci;
        student_arr[i].avg = (float)student_arr[i].total / 3;

        student_arr[i].grade = get_grade(student_arr[i].avg);
    }

    for (int i = 0; i < students; i++) {
        std::cout << "Student 1:" << "\nMath: " << student_arr[i].math << "\nEnglish: " << student_arr[i].eng << "\nScience: " << student_arr[i].sci;
        std::cout << "\nTotal marks: " << student_arr[i].total << "\nAverage: " << student_arr[i].avg << "\nGrade: " << student_arr[i].grade;
    }

    return 0;
}
