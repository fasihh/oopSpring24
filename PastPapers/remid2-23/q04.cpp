#include <iostream>

using namespace std;

const int avg_weight = 18;

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
        float time = length/speed;

        if (currWeight < 5) speed *= 2;
        else if (currWeight > 50) speed /= 2;
    }

    operator IndustrialBelt() const {
        return IndustrialBelt(avg_weight, false, length, width, speed, capacity);
    }

    float getLength() const { return length; }
    float getWidth() const { return width; }
    float getSpeed() const { return speed; }
    float getCapacity() const { return capacity; }
};

class Escalator : public Stairs, public ConveyorBelt {
private:
    char direction;
    int currentLocation;
public:
    static int escalatorCount;
    Escalator(char dir, int current, int steps, float height, float width, string location, float speed, float cap)
        : direction(dir), currentLocation(current), Stairs(steps, height, width, location), ConveyorBelt(speed, cap) {}

    void moveUp(int weight) {
        if (weight >= avg_weight) return;

        direction = 'U';
        if (weight >= 0.8f*avg_weight)
            speed -= 5;
    }

    void moveDown(int weight) {
        if (weight >= avg_weight && currentLocation > 0) return;

        direction = 'D';
        if (weight >= 0.8f*avg_weight)
            speed *= 1.1f;
    }
    
    char getDirection() { return direction; }
    int getCurrentLocation() { return currentLocation; }

    int operator++() {
        if (currentLocation < numSteps)
            currentLocation++;
        return numSteps - currentLocation;
    }

    int operator--() {
        if (currentLocation > 0)
            currentLocation--;
        return currentLocation;
    }
};

class IndustrialBelt : public ConveyorBelt {
private:
    float minWeight;
    bool operable;
public:
    IndustrialBelt(float min_weight, bool status, float len, float width, float speed, float cap)
        : minWeight(min_weight), operable(status), ConveyorBelt(len, width, speed, cap) {}

    bool checkWeight(int currWeight) {
        operable = currWeight >= minWeight;
        return operable;
    }

    void operateBelt(int currWeight) {
        if (checkWeight(currWeight))
            ConveyorBelt::operateBelt(currWeight);
    }

    void operateBelt(int currWeight, int speed) {
        if (checkWeight(currWeight)) {
            this->speed = speed;
            ConveyorBelt::operateBelt(currWeight);
        }
    }

    IndustrialBelt& operator=(ConveyorBelt obj) {
        return *this;
    }
};

int Escalator::escalatorCount = 0, ConveyorBelt::conveyerBeltCount = 0, Stairs::stairsCount = 0;

int main() {
    ConveyorBelt cb = ConveyorBelt(100.00,2.00,5.55,500.00);
    IndustrialBelt ib = cb;
    
    return 0;
}