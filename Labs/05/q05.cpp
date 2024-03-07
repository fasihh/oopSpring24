#include <iostream>

using namespace std;

class Engine{
public:
    string model;
    int year;

    Engine(string model, int year){
        this->model = model;
        this->year = year;
    }
};

class Wheel {
public:
    int size;

    Wheel(int size) : size(size) {}
};

class Headlights {
public:
    int brightness;
    bool onStatus;

    Headlights(int b) : brightness(b), onStatus(false) {}
};

class Steering {
public:
    string type;

    Steering(string type) : type(type) {}
};

class Car{
private:
    Engine e;
    Wheel w;
    Headlights *h;
    Steering *s;
public:
    string model;
    int id;

    Car(
        string model,
        int id,
        Engine e,
        Wheel w,
        Headlights *h,
        Steering *s
    ) : e(e), w(w), model(model), id(id) {
        this->h = h;
        this->s = s;
    }

    void display() {
        cout << "Car Model: " << model << endl;
        cout << "Car id: " << id << endl;
        cout << "Engine Model: " << e.model << endl;
        cout << "Engine Year: " << e.year << endl;
        cout << "Wheel Size: " << w.size << endl;
        cout << "Headlights Brightness: " << h->brightness << endl;
        cout << "Headlights Status: " << (h->onStatus ? "On" : "Off") << endl;
        cout << "Steering Type: " << s->type << endl;
    }
};

int main() {
    Engine engine("V8", 2022);
    Wheel wheel(18);
    Headlights headlights(100);
    Steering steering("Power");

    Car car("Toyota Camry", 1234, engine, wheel, &headlights, &steering);

    car.display();

    return 0;
}
