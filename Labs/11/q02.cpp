#include <iostream>

using namespace std;

class Account {
protected:
    unsigned account_number;
    double balance;

    static unsigned account_count;
public:
    Account() : account_number(Account::account_count++), balance(0.f) {}

    virtual void deposit(double amount) = 0;
    virtual double withdraw(double amount) = 0;
    virtual double calculateInterest() = 0;

    unsigned getAccountNumber() const { return this->account_number; }
    double getBalance() const { return this->balance; }
};

class SavingsAccount : public Account {
private:
    double interest_rate;
public:
    SavingsAccount(double interest_rate) : interest_rate(interest_rate) {}

    void deposit(double amount) override { this->balance += amount; }
    double withdraw(double amount) override {
        if (this->balance < amount) {
            cout << "Insufficient balance" << endl;
            return 0.f;
        }

        this->balance -= amount;
        return amount;
    }
    double calculateInterest() override {
        // interest for one year
        return this->balance * this->interest_rate;
    }
};

class CurrentAccount : public Account {
private:
    double overdraft_limit;
public:
    CurrentAccount(double overdraft) : overdraft_limit(overdraft) {}

    void deposit(double amount) override { this->balance += amount; }
    double withdraw(double amount) override {
        if (this->overdraft_limit < amount) {
            cout << "Overdraft limit reached" << endl;
            return 0.f;
        }

        return amount;
    }
    double calculateInterest() override {
        // no interest
        return 0.f; 
    }
};

unsigned Account::account_count = 0;