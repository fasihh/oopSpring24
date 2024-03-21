#include <iostream>
using namespace std;

class Account {
protected:
    float balance, lastWithdraw;
    string creationDate;
public:
    Account(string date) : creationDate(date), balance(0.f), lastWithdraw(0.f) {}
};

void hello() {
    cout << "Hello" << endl;
}

void hello() {
    cout << "Hello" << endl;
}

int main() {
    hello();
    return 0;
}