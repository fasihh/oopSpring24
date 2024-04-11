#include <iostream>

using namespace std;

class Employee {
protected:
    int id;
    string name;
public:
    Employee(int id, string name) : id(id), name(name) {}

    virtual double calculatePay() const { return 0.f; }
    virtual void displayDetails() const { cout << "Employee ID: " <<  id << ", Name: " << name << endl; }
};

class FullTimeEmployee : public Employee {
private:
    double monthly_salary;
public:
    FullTimeEmployee(int id, string name, float salary) : Employee(id, name), monthly_salary(salary) {}

    double calculatePay() const { return monthly_salary; }
    void displayDetails() const {
        Employee::displayDetails();
        cout << "Type: Full-Time, Monthly Salary: " << monthly_salary << endl;
    }
};

class PartTimeEmployee : public Employee {
private:
    double hourly_salary, hours;
public:
    PartTimeEmployee(int id, string name, float wage, float hours) 
        : Employee(id, name), hourly_salary(wage), hours(hours) {}

    double calculatePay() const { return hourly_salary*hours; }
    void displayDetails() const {
        Employee::displayDetails();
        cout << "Type: Part-Time, Hourly Wage: " << hourly_salary << " Hours Worked: " << hours << endl;
    }
};

int main() {
    Employee *full = new FullTimeEmployee(101, "AAA", 5000.f), *part = new PartTimeEmployee(102, "BBB", 15.f, 40.f);

    cout << "Displaying Details:\n";
    full->displayDetails();
    part->displayDetails();

    cout << "\nCalculating Pay:\n";
    cout << "Full-time Employee Pay: $" << full->calculatePay() << endl;
    cout << "Part-time Employee Pay: $" << part->calculatePay() << endl;
    return 0;
}