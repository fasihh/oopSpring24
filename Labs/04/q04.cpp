/*
 * Creator: Fasih Hasan Khan 23K-0018
 */

#include <iostream>

using namespace std;

class Office {
public:
    string Location, Furniture[3] = { "" };
    unsigned short SeatingCapacity;

    Office(
        string location = "Karachi", unsigned short seatingCapacity = 0,
        string furniture1 = "", string furniture2 = "", string furniture3 = ""
    ) : 
        Location(location), SeatingCapacity(seatingCapacity),
        Furniture({ furniture1, furniture2, furniture3 }) 
    {}

    void show() {
        cout << "Location: " << Location << endl
             << "Seating Capacity: " << SeatingCapacity << endl
             << "Furniture:" << endl;
        for (string furniture : Furniture)
            cout << furniture << endl;
        cout << endl;
    }
};

int main()
{
    Office office1;
    Office office2("Lahore", 2, "Chairs", "Sofa");
    Office office3("Islamabad", 1, "Table");

    office1.show();
    office2.show();
    office3.show();

    return 0;
}
