/*
 * Creator: Fasih Hasan Khan 23K0018
 */

#include <iostream>

using namespace std;

class Smartphone {
private:
    string brand, model, res;
    int ram, rom, storage;
public:
    string get_brand() const {
        return brand;
    }

    string get_model() const {
        return model;
    }

    string get_resolution() const {
        return res;
    }

    int get_ram() const {
        return ram;
    }

    int get_rom() const {
        return rom;
    }

    int get_storage() const {
        return storage;
    }

    void set_brand(string new_brand) {
        brand = new_brand;
    }

    void set_model(string new_model) {
        model = new_model;
    }

    void set_resolution(string new_res) {
        res = new_res;
    }

    void set_ram(int new_ram) {
        ram = new_ram;
    }

    void set_rom(int new_rom) {
        rom = new_rom;
    }

    void set_storage(int new_storage) {
        storage = new_storage;
    }

    void make_call(string contact) {
        cout << "called " << contact << endl;
    }

    void send_message(string message) {
        cout << "sent message" << endl;
        cout << message << endl;
    }

    void connect_to_wifi(string wifi) {
        cout << "connected to " << wifi << endl;
    }

    void browse_internet() {
        cout << "internet browsed" << endl;
    }
};

int main()
{
    Smartphone phone1, phone2;
    phone1.set_brand("apple");
    phone1.set_model("5");
    phone1.set_ram(1);
    phone1.set_rom(4);
    phone1.set_storage(16);

    phone2.set_brand("samsung");
    phone2.set_model("galaxy s20");
    phone2.set_ram(8);
    phone2.set_rom(128);
    phone2.set_storage(256);

    cout << phone1.get_brand() << endl;
    cout << phone1.get_model() << endl;
    cout << phone1.get_ram() << endl;
    cout << phone1.get_rom() << endl;
    cout << phone1.get_storage() << endl;
    phone1.connect_to_wifi("wifi1");
    phone1.send_message("hello world!");

    cout << endl;

    cout << phone2.get_brand() << endl;
    cout << phone2.get_model() << endl;
    cout << phone2.get_ram() << endl;
    cout << phone2.get_storage() << endl;
    cout << phone2.get_rom() << endl;
    phone2.browse_internet();
    phone2.make_call("phone1");

    return 0;
}
