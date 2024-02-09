#include <iostream>

using namespace std;

class WaterBottle {
private:
    string company, color;
    float water_capacity_l;
    float water_capacity_ml;
public:
    void set_company(string comp) {
        company = comp;
    }
    void set_color(string clr) {
        color = clr;
    }
    void set_water_capacity_l(float water) {
        water_capacity_l = water/1000;
    }
    void set_water_capacity_ml(float water) {
        water_capacity_ml = water;
    }
    string get_company() {
        return company;
    }
    string get_color() {
        return color;
    }
    float get_water_capacity_l() {
        return water_capacity_l;
    }
    float get_water_capacity_ml() {
        return water_capacity_ml;
    }
};

int main(int argc, char const *argv[])
{
    WaterBottle bottle;
    float water_in_ml;
    bottle.set_color("blue");
    bottle.set_company("aqua fina");

    cout << "Enter amount of water consumed";
    cin >> water_in_ml;
    bottle.set_water_capacity_l(water_in_ml);
    bottle.set_water_capacity_ml(water_in_ml);

    cout << "Drunk " << bottle.get_water_capacity_l() << " liters or " << bottle.get_water_capacity_ml() << " mililiters from a " << bottle.get_color() << " bottle of company " << bottle.get_company() << endl;

    return 0;
}
