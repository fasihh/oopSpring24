#include <iostream>

using namespace std;

class Stairs {
protected:
    int numSteps;
    float stepHeight, stepWidth;
    string location;
public:
    static int stairsCount;
    Stairs(int steps, float height, float width, string location) : numSteps(steps), stepHeight(height), stepWidth(width), location(location) {}
};

class ConveyorBelt {
private:
    float length, width;
protected:
    float speed, capacity;
public:
    static int conveyerBeltCount;
    ConveyorBelt(float length, float width, float speed, float cap)
        : length(length), width(width), speed(speed), capacity(cap) {}
    ConveyorBelt(float speed, float cap) : speed(speed), capacity(cap) {}

    void operateBelt(int currWeight) {
        cout << currWeight << endl;
    }
};

class Escalator : public Stairs, public ConveyorBelt {
private:
    char direction;
    int currentLocation;
public:
    static int escalatorCount;
    Escalator(char dir, int current, int steps, float height, float width, string location, float speed, float cap)
        : direction(dir), currentLocation(current), Stairs(steps, height, width, location), ConveyorBelt(speed, cap) {}
    
    char getDirection() { return direction; }
    int getCurrentLocation() { return currentLocation; }
};

int Escalator::escalatorCount = 0, ConveyorBelt::conveyerBeltCount = 0, Stairs::stairsCount = 0;

int main() {
    
    return 0;
}