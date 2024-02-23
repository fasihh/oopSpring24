#include <iostream>

using namespace std;

class RollerCoaster {
public:
	string name;
	unsigned height, length, currentNumRiders, capacity;
	int speed;
	bool rideInProgress;

	RollerCoaster() : name("roller coaster"), height(500), length(200), capacity(20), speed(0), rideInProgress(false) {}

	RollerCoaster(string name, unsigned height, unsigned length, unsigned capacity) 
	   : name(name), height(height), length(length), speed(0), rideInProgress(false) 
	{
		this->capacity = capacity%3 == 0 || capacity%2 == 0 ? capacity : capacity-1;
   	}

	// getter and setters
    string getName() { return name; }
    void setName(string name) { this->name = name; }

    unsigned getHeight() { return height; }
    void setHeight(unsigned height) { this->height = height; }

    unsigned getLength() { return length; }
    void setLength(unsigned length) { this->length = length; }

    unsigned getSpeed() { return speed; }
    void setSpeed(unsigned speed) { this->speed = speed; }

    unsigned getCapacity() { return capacity; }
    void setCapacity(unsigned capacity) { this->capacity = capacity%3 == 0 || capacity%2 == 0 ? capacity : capacity-1; }

    unsigned getCurrentNumRiders() { return currentNumRiders; }
    void setCurrentNumRiders(unsigned currentNumRiders) { this->currentNumRiders = currentNumRiders; }

    bool isRideInProgress() { return rideInProgress; }
    void setRideInProgress(bool rideInProgress) { this->rideInProgress = rideInProgress; }

    unsigned seatRiders(unsigned riders) {
    	if (rideInProgress) {
    		cout << "Ride in progress" << endl;
    		return capacity;
    	}

    	this->setCurrentNumRiders(riders > capacity ? capacity : riders);
    	return riders >= capacity ? riders - capacity : 0;
    }

    int start() {
    	if (rideInProgress) {
    		cout << "Ride in progress" << endl;
    		return -1;
    	}

    	this->setRideInProgress(true);
    	return currentNumRiders != capacity ? capacity - currentNumRiders : 0;
    }

    void stop() { if (rideInProgress) this->setRideInProgress(false); }

    void unloadRiders() { if (!rideInProgress) this->setCurrentNumRiders(0); }

    void accelerate(string roll) {
    	for (auto it = roll.end()-1; it >= roll.begin(); it--) {
    		if (*it == '0') continue;
    		this->setSpeed(speed + (*it-'0'));
    		return;
    	}
    }

    void decelerate(string roll) {
    	for (auto it = roll.begin(); it < roll.end(); it++) {
    		if (*it == '0') continue;
    		this->setSpeed(speed - (*it-'0'));
    		return;
    	}
    }
};

int main()
{
	RollerCoaster obj1;
	RollerCoaster obj2("best roller coaster", 800, 1500, 31);

	cout << obj2.getName() << " " << obj2.getCapacity() << endl;

	obj2.start();
	obj2.seatRiders(27);
	obj2.stop();

	cout << "Riders not seated: " << obj2.seatRiders(39) << endl;
	cout << "Current riders: " << obj2.getCurrentNumRiders() << endl;
	cout << "Not occupied seats: " << obj2.start() << endl;

	obj2.accelerate("0018");
	cout << "Speed: " << obj2.getSpeed() << endl;
	for (int i = 0; i < 8; i++) obj2.decelerate("0018");
	cout << "Speed: " << obj2.getSpeed() << endl;
	
	obj2.stop();
	cout << "Ride status: " << obj2.isRideInProgress() << endl;
	obj2.unloadRiders();
	cout << "Current riders: " << obj2.getCurrentNumRiders() << endl;

	return 0;
}