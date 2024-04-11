#include <iostream>
#define _USE_MATH_CONSTANTS
#include <cmath>

using namespace std;

// M_PI is technically a global constant for 'pi'

class Shape {
public:
    virtual double area() = 0;
    virtual double perimeter() = 0;
    virtual inline void display() = 0;
};

class Circle : public Shape {
private:
    float radius;
public:
    Circle(float radius) : radius(radius) {}

    double area() { return radius*radius; }
    double perimeter() { return 2*M_PI*radius; }
    inline void display() { cout << "Circle\n" << this->area() << '\n' << this->perimeter() << endl; }
};

class Rectangle : public Shape {
private:
    float length, width;
public:
    Rectangle(float length, float width) : length(length), width(width) {}

    double area() { return length*width; }
    double perimeter() { return 2*(length + width); }
    inline void display() { cout << "Rectangle\n" << this->area() << '\n' << this->perimeter() << endl; }
};

class Triangle : public Shape {
private:
    float base, height;
public:
    Triangle(float base, float height) : base(base), height(height) {}

    double area() { return 0.5f*base*height; }
    double perimeter() { return base + height + sqrt(base*base + height*height); }
    inline void display() { cout << "Triangle\n" << this->area() << '\n' << this->perimeter() << endl; }
};

int main() {
    Shape *circle = new Circle(5.f), *rectangle = new Rectangle(5.f, 10.f), *triangle = new Triangle(5.f, 10.f);
    circle->display(), rectangle->display(), triangle->display();

    return 0;
}
