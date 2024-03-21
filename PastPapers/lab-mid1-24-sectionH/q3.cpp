#include <iostream>
using namespace std;

class Employee {
protected:
    string name, joining_date;
    int age;
public:
    Employee(string name, int age, string join) : name(name), age(age), joining_date(join) {}

    string getName() { return name; }
    string getDate() { return joining_date; }
    int getAge() { return age; }

    void setName(string name) { this->name = name; }
    void setDate(string date) { this->joining_date = date; }
    void setAge(int age) { this->age = age; }
};

class Debugger : public Employee {
protected:
    string role;
public:
    Debugger(string name, int age, string join, string role) : Employee(name, age, join), role(role) {}
};

class Developer : public Employee {
protected:
    string role;
public:
    Developer(string name, int age, string join, string role) : Employee(name, age, join), role(role) {}
};

class Lead : public Debugger, public Developer {
public:
    Lead(string name, int age, string join, string debugger, string developer) : Debugger(name, age, join, debugger), Developer(name, age, join, developer) {}

    void displayInfoDebugger() {
        cout << "Name: " << Debugger::name << "\n";
        cout << "Age: " << Debugger::age << "\n";
        cout << "Joining Date: " << Debugger::joining_date << "\n";
        cout << "Role: " << Debugger::role << "\n";
    }

    void displayInfoDeveloper() {
        cout << "Name: " << Developer::name << "\n";
        cout << "Age: " << Developer::age << "\n";
        cout << "Joining Date: " << Developer::joining_date << "\n";
        cout << "Role: " << Developer::role << "\n";
    }
};

int main() {
    Lead lead("Fasih", 18, "20-3-24", "Manual Debugger", "Backend");

    lead.displayInfoDebugger();
    lead.displayInfoDeveloper();

    return 0;
}