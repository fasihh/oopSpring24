#include <iostream>

using namespace std;

class DarazPersonData {
private:
    string firstName, lastName, address, city, state, zip, phone;
public:
    DarazPersonData(string first, string last, string addr, string cty, string st, string zp, string ph)
        : firstName(first), lastName(last), address(addr), city(cty), state(st), zip(zp), phone(ph) {}

    string getFirstName() { return this->firstName; }
    string getLastName() { return this->lastName; }
    string getAddress() { return this->address; }
    string getCity() { return this->city; }
    string getState() { return this->state; }
    string getZip() { return this->zip; }
    string getPhone() { return this->phone; }

    void setFirstName(string first) { this->firstName = first; }
    void setLastName(string last) { this->lastName = last; }
    void setAddress(string addr) { this->address = addr; }
    void setCity(string cty) { this->city = cty; }
    void setState(string st) { this->state = st; }
    void setZip(string zp) { this->zip = zp; }
    void setPhone(string ph) { this->phone = ph; }
};

class DarazCustomerData : public DarazPersonData {
private:
    int customerNumber, loyaltyPoints;
    static int totalCustomers;
public:
    DarazCustomerData(string first, string last, string addr, string cty, string st, string zp, string ph) 
        : DarazPersonData(first, last, addr, cty, st, zp, ph), customerNumber(totalCustomers++), loyaltyPoints(0) {}

    int getCustomerNumber() { return this->customerNumber; }
    int getLoyaltyPoints() { return this->loyaltyPoints; }
    
    void setCustomerNumber(int num) { this->customerNumber = num; }
    void setLoyaltyPoints(int points) { this->loyaltyPoints = points; }
};

int DarazCustomerData::totalCustomers = 0;

class DarazLoyalyProgram {
private:
    DarazCustomerData *customer;
public:
    DarazLoyalyProgram(DarazCustomerData *customer) : customer(customer) {}

    void addLoyaltyPonts(int points) {
        customer->setLoyaltyPoints(customer->getLoyaltyPoints() + points);
    }

    float redeemLoyaltyPoints(int points) {
        int loyaly_points = customer->getLoyaltyPoints();
        if (loyaly_points - points < 0 || points < 0) return -1.f;

        return 0.75f;
    }

    void displayLoyaltyPoints() {
        cout << "Total Loyalty Points: " << customer->getLoyaltyPoints() << endl;
    }
};

void print(DarazCustomerData customer) {
    cout << "Customer ID: " << customer.getCustomerNumber() << "\n";
    cout << "Name: " << customer.getFirstName() + " " + customer.getLastName() << "\n";
    cout << "Address: " << customer.getAddress() << "\n";
    cout << "City: " << customer.getCity() << "\n";
    cout << "Phone: " << customer.getPhone() << "\n";
    cout << "Zip: " << customer.getZip() << "\n";
    cout << "State: " << customer.getState() << "\n";
}

int main() {
    cout << "Fasih Hasan Khan\n23k0018\n\n";
    int loyaltyPoints;
    float item_price;

    DarazCustomerData customer(
       "Fasih",
       "Khan",
       "Johar",
       "Karachi",
       "Street",
       "1001",
       "03XXXXXXX79" 
    );

    print(customer);

    DarazLoyalyProgram loyaltyProgram(&customer);
    loyaltyProgram.addLoyaltyPonts(100);
    loyaltyProgram.displayLoyaltyPoints();

    cout << "Enter item price: ";
    cin >> item_price;

    cout << "Enter amount of points to redeem: ";
    cin >> loyaltyPoints;

    cout << "Original Price: " << item_price << "\n";
    float discount = loyaltyProgram.redeemLoyaltyPoints(loyaltyPoints);

    if (discount == -1) return 1;
    cout << "Discounted Price: " << item_price * discount << "\n";

    return 0;
}