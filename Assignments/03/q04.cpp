#include <iostream>
#include <cmath>

// using macros for constant values. I could also use const variables but this looks better
#define OBJECTS 2
#define DRONE_FLIGHT_LIMIT_ERROR "FLIGHT_LIMIT: Drone has reached maximum flight time"
#define DRONE_SIGNAL_ERROR "NO_SIGNAL: Drone out of range"

using namespace std;

float objects[OBJECTS][3] = {
    {0.f, 0.f, 0.f},
    {10.f, 12.f, 20.f}
};

class Drone {
protected:
    float pos_lat, pos_long, altitude, speed;
public:
    Drone(float latitude, float longitude, float altitude, float speed) 
        : pos_lat(latitude), pos_long(longitude), altitude(altitude), speed(speed) {}

    void adjustAltitude(float altitude) { this->altitude = altitude; }
    void setSpeed(float speed) { this->speed = speed; }

    virtual void start() = 0;
};

class Flyable {
public:
    virtual void takeoff() = 0;
    virtual void land() = 0;
    virtual void navigateTo(float latitude, float longitude, float altitude) = 0;
};

class Scannable {
public:
    virtual void scanArea(float radius) = 0;
};

class ReconDrone : public Drone, public Flyable, public Scannable {
private:
    float max_flight_time, flight_time;
    int camera_resolution;

    float distance(float x, float y, float z) { return sqrt(x*x + y*y + z*z); }
public:
    ReconDrone(float latitude, float longitude, float altitude, float speed, float flight_time, int camera_res)
        : Drone(latitude, longitude, altitude, speed), flight_time(0), max_flight_time(flight_time), camera_resolution(camera_res) {}
    
    void start() override {
        cout << "ReconDrone powered on" << endl;
        cout << "Drone Camera Resolution [" << this->camera_resolution << "p]" << endl;
        cout << "Drone Max Flight Time [" << this->max_flight_time << "s]" << endl << endl;
    }

    void takeoff() override { this->altitude = 10.f; }
    void land() override { this->altitude = 0.f; }
    void navigateTo(float latitude, float longitude, float altitude) override {
        try {
            if (flight_time >= max_flight_time)
                throw "Drone has reached maximum flight time";
            float dx = latitude - this->pos_lat;
            float dy = longitude - this->pos_long;
            float dz = altitude - this->altitude;

            float time = this->distance(dx, dy, dz) / this->speed;
            cout << "Navigating to (" << latitude << ", " << longitude << ", " << altitude << ") -- ETA: " << time << "s" << endl;
            this->flight_time += time, this->pos_lat = latitude, this->pos_long = longitude, this->altitude = altitude;
        } catch(const char *error) {
            cout << error << endl;
        }
    }

    void scanArea(float radius) override {
        try {
            if (flight_time >= max_flight_time)
                throw DRONE_FLIGHT_LIMIT_ERROR;
            if (this->distance(pos_lat, pos_long, altitude) >= 20.f)
                throw DRONE_SIGNAL_ERROR;
            
            cout << "Scanning area within " << radius << "m radius" << endl;
            for (int i = 0; i < OBJECTS; ++i) {
                float dx = objects[i][0] - this->pos_lat;
                float dy = objects[i][1] - this->pos_long;
                float dz = objects[i][2] - this->altitude;

                if (this->distance(dx, dy, dz) <= radius)
                    cout << "Object detected: (" << objects[i][0] << ", " << objects[i][1] << ", " << objects[i][2] << ")" << endl;
            }
            flight_time += 5.f;
        } catch(const char *error) {
            cout << error << endl;
        }
    }
};

int main() {
    ReconDrone r_drone(0.f, 0.f, 0.f, 10.f, 12.f, 720);
    r_drone.start();
    r_drone.takeoff();
    
    r_drone.scanArea(10.f);
    r_drone.navigateTo(8.f, 10.f, 13.f);
    r_drone.scanArea(10.f);
    
    r_drone.navigateTo(20.f, 30.f, 40.f);
    r_drone.scanArea(10.f);
    r_drone.navigateTo(0.f, 0.f, 0.f);

    return 0;
}