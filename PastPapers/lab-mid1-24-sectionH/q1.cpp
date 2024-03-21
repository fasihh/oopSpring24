#include <iostream>

using namespace std;

class Employee {
private:
    string name;

    static int nextEmployeeID;
    int id;

    const float MAX_SALARY = 2000.f;
    float salary;
public:
    Employee(string name) : id(Employee::generateEmployeeID()), name(name) {}

    int getID() { return id; }
    void setSalary(float salary) { this->salary = salary >= MAX_SALARY ? MAX_SALARY : salary; }

    static int generateEmployeeID() { return ++nextEmployeeID; }

    void displayEmployeeInfo() {
        cout << "Employee #" << id << "\n";
        cout << "Name: " << name << "\n";
        cout << "Salary: " << salary << "\n";
    }
};

int Employee::nextEmployeeID = 0;

int main() {
    Employee obj1("Fasih"), obj2("Ali");

    obj1.setSalary(1999.f);    
    obj2.setSalary(2001.f);

    obj1.displayEmployeeInfo();
    cout << endl;
    obj2.displayEmployeeInfo();

    return 0;
}