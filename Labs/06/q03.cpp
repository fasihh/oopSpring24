#include <iostream>

using namespace std;

class Appointment {
private:
    int time;
    double cost;
public:
    static int appointments;
    static double total;

    Appointment(double cost, int time) : cost(cost), time(time) {
        Appointment::total += cost;
        Appointment::appointments++;
    }

    double getCost() { return cost; }
    double getTime() { return time; }

    static double getAverageCost() { return Appointment::total/Appointment::appointments; }
};

double Appointment::total = 0.f;
int Appointment::appointments = 0;

int main() {
    Appointment first(80, 3);
    cout << first.getTime() << "PM : $" << first.getCost() << "\n";
    Appointment second(70, 4);
    cout << second.getTime() << "PM : $" << second.getCost() << "\n";
    Appointment third(90, 5);
    cout << third.getTime() << "PM : $" << third.getCost() << "\n";
    Appointment fourth(110, 7);
    cout << fourth.getTime() << "PM : $" << fourth.getCost() << "\n";

    cout << Appointment::getAverageCost() << endl;

    return 0;
}