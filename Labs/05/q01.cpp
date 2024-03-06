#include <iostream>

using namespace std;

class Square {
public:
    float sideLength, area;
    static float allareas;

    Square(float sideLength = 0.f) : sideLength(sideLength) {}

    float calculateArea() { 
        area = sideLength*sideLength;
        allareas += area;
        return area;
    }

    float getSideLength() { return sideLength; }
    void setSideLength(float side) { sideLength = side; }

    float getArea() { return area; }
    void setArea(float a) { area = a; }

    static float getAllAreas() { return allareas; }
    static void setAllAreas(float all) { allareas = all; }
};

float Square::allareas = 0.f;

int main(int argc, char const *argv[])
{
    Square sq1(2.f), sq2(1.f), sq3;

    sq1.calculateArea();
    cout << sq1.getArea() << " " << sq1.getAllAreas() << "\n";
    sq2.calculateArea();
    cout << sq2.getArea() << " " << sq2.getAllAreas() << "\n";
    sq3.calculateArea();
    cout << sq3.getArea() << " " << sq3.getAllAreas();

    return 0;
}
