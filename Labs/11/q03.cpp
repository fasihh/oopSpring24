#include <iostream>

using namespace std;

class Vehicle {
protected:
    string make, model;
    int speed;
public:
    Vehicle(string model, string make) : make(make), model(model), speed(0) {}

    virtual void accelerate() = 0;
    virtual void brake() = 0;
    virtual double calculateFuelEfficiency() = 0;

    string getMake() const { return this->make; }
    string getModel() const { return this->model; }
    int getSpeed() const { return this->speed; }
};

class Car : public Vehicle {
private:
    double fuel_capacity;
public:
    Car(string model, string make, double fuel_capacity) : Vehicle(model, make), fuel_capacity(fuel_capacity) {}

    void accelerate() override { this->speed += 10; }
    void brake() override { this-> speed -= 5; }

    // fuel efficiency for 100km on full tank
    double calculateFuelEfficiency() override { return this->fuel_capacity / 100.f; }
};

class Truck : public Vehicle {
private:
    double cargo_capacity;
public:
    Truck(string model, string make, double cargo_capacity) : Vehicle(model, make), cargo_capacity(cargo_capacity) {}

    void accelerate() override { this->speed += 6; }
    void brake() override { this-> speed -= 5; }
    // assumed fuel efficiency
    double calculateFuelEfficiency() override { return 0.6f; }
};

int main() {
    return 0;
}