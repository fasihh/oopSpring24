#include <iostream>

using namespace std;

class BankAccount {
private:
    int accountNumber;
    string accountHolderName;
    double balance;
public:
    BankAccount(int accountNumber = 0, string accountHolderName = "", double balance = 0.f) {
        this->accountNumber = accountNumber;
        this->accountHolderName = accountHolderName;
        this->balance = balance;
    }

    void deposit(double amount) { 
        this->balance += amount; 
        cout << "Deposited" << endl;
    }

    double withdraw(double amount) {
        if (amount > this->balance) {
            cout << "Not enough money" << endl;
            return 0.f;
        }

        this->balance -= amount;
        cout << "Success" << endl;
        return amount; 
    }

    void display() {
        cout << "NUM: " << this->accountNumber << "\n";
        cout << "HOLDER: " << this->accountHolderName << "\n";
        cout << "BALANCE: " << this->balance << "\n";
    }
};

void output(BankAccount accounts[3]) {
    for (int i = 0; i < 3; i++) accounts[i].display();
}

int main() {
    BankAccount accounts[3] = {
        { 1, "Fasih", 500.f },
        { 2, "Abser", 400.f },
        { 4, "Ali", 300.f }
    };

    output(accounts);
    accounts[1].deposit(500.f);
    output(accounts);
    accounts[2].withdraw(200.f);
    output(accounts);

    return 0;
}
