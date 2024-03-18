#include <iostream>

using namespace std;

class Vehicle {
public:
    string make;
    int model, year;

    Vehicle(string make, int model, int year) : make(make), model(model), year(year) {}
};

class Car : public Vehicle {
public:
    int doors;
    float fuel_efficiency;

    Car(string make, int model, int year, int doors, float efficiency) :
        Vehicle(make, model, year), doors(doors), fuel_efficiency(efficiency) {}
};

class ElectricCar : public Car {
public:
    float battery_life;

    ElectricCar(string make, int model, int year, int doors, float efficiency, float battery) :
        Car(make, model, year, doors, efficiency), battery_life(battery) {}

    void display() {
        cout << "Make: " << make << "\n";
        cout << "Model: " << model << "\n";
        cout << "Year: " << year << "\n";
        cout << "Doors: " << doors << "\n";
        cout << "Fuel Efficiency: " << fuel_efficiency << "%\n";
        cout << "Battery Life: " << battery_life << "%\n";
    }
};

int main() {
    ElectricCar electric_car("Tesla", 101, 2020, 2, 70.f, 90.f);
    electric_car.display();

    return 0;
}