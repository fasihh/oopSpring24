/*
 * Creator: Fasih Hasan Khan 23K-0018
 */

#include <iostream>

using namespace std;

class Office {
public:
    string Location, *Furniture;
    unsigned short SeatingCapacity;

    Office(
        string location = "Karachi", unsigned short seatingCapacity = 0, size_t count = 0
    ) : 
        Location(location), SeatingCapacity(seatingCapacity), Furniture(new string[count])
    {}

    ~Office() {
        delete[] Furniture;
        cout << "Furniture deleted" << endl;
    }
};

int main()
{
    Office *office1 = new Office("Lahore", 5, 3);

    delete office1;

    return 0;
}
