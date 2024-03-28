#include <iostream>
#define _USE_MATH_DEFINES
#include <cmath>

using namespace std;

class Shape {
public:
    virtual double area() const = 0;
    virtual double perimeter() const = 0;
    virtual void displayProperties() const = 0;
};

class Circle : public Shape {
private:
    double radius;
public:
    Circle(double r) : radius(r) {}

    double area() const { return M_PI*radius*radius; }
    double perimeter() const { return 2*M_PI*radius; }
    void displayProperties() const {
        cout << "Properties of the Circle:\n";
        cout << "- Area: " << this->area() << '\n';
        cout << "- Perimeter: " << this->perimeter() << '\n';
        cout << "- Diameter: " << 2*radius << '\n';
    }
};

class Rectangle : public Shape {
private:
    double length, height;
public:
    Rectangle(double l, double h) : length(l), height(h) {}

    double area() const { return length*height; }
    double perimeter() const { return 2*length + 2*height; }
    void displayProperties() const {
        cout << "- Area: " << this->area() << '\n';
        cout << "- Perimeter: " << this->perimeter() << '\n';
        cout << "- Diagonal: " << sqrt(height*height + length*length) << '\n';
    }
};

class Triangle : public Shape {
private:
    double a, b, c;
public:
    Triangle() = default;
    Triangle(double s1, double s2, double s3) : a(s1), b(s2), c(s3) {}

    double area() const {
        double s = (a + b + c) / 2;
        return sqrt(s*(s - a)*(s - b)*(s - c)); 
    }
    double perimeter() const { return a + b + c; }
    void displayProperties() const {
        cout << "- Area: " << this->area() << '\n';
        cout << "- Perimeter: " << this->perimeter() << '\n';
    }
};

class EquilateralTriangle : public Triangle {
private:
    double side;
public:
    EquilateralTriangle(double s) : side(s) {}

    double area() const {
        // approximation of sqrt(3)/4
        const double constant = 0.43301270189f;
        return constant * side*side;
    }
    double perimeter() const { return 3*side; }
    void displayProperties() const {
        cout << "Equilateral Triangle\n";
        cout << "- Area: " << this->area() << '\n';
        cout << "- Perimeter: " << this->perimeter() << '\n';
    }
};

void display() {
    cout << "Please select a shape:\n"
         << "1. Circle\n"
         << "2. Rectangle\n"
         << "3. Square\n"
         << "4. Triangle\n";
    cout << "Enter your choice: ";
}

int main() {
    Shape *shape;

    int choice;
    bool flag = true;
    while(flag) {
        display();
        cin >> choice;
        cout << endl;

        switch(choice) {
            case 1: {
                double radius;
                cout << "Enter the radius of the circle: ";
                cin >> radius;

                shape = new Circle(radius);
            }
        }

        shape->displayProperties();

        string option;
        cout << "Do you want to calculate properties for another shape? (yes/no): ";
        cin >> option;

        if (option == "yes")
            flag = false;
    }
    display();

    return 0;
}
