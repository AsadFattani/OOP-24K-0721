#include <iostream>
using namespace std;

class Account {
    protected:
        string accountNumber;
        float balance;

    public:
        Account(string accountNumber, float balance) : accountNumber(accountNumber), balance(balance) {}

        void displayDetails() {
            cout << "--------------------------------" << endl;
            cout << "Account Number: " << accountNumber << endl;
            cout << "Balance: " << balance << endl;
        }
};

class SavingsAccount : public Account {
    protected:
        float interestRate;

    public:
        SavingsAccount(string accountNumber, float balance, float interestRate) 
        : Account(accountNumber, balance), interestRate(interestRate) {}

        void displayDetails() {
            Account::displayDetails();
            cout << "Interest Rate: " << interestRate << endl;
        }
};

class CurrentAccount : public Account {
    protected:
        float overdraftLimit;

    public:
        CurrentAccount(string accountNumber, float balance, float overdraftLimit) 
        : Account(accountNumber, balance), overdraftLimit(overdraftLimit) {}

        void displayDetails() {
            Account::displayDetails();
            cout << "overdraft Limit: " << overdraftLimit << endl;
        }
};

int main() {
    SavingsAccount s1("SA-001", 1000, 0.05);
    CurrentAccount c1("CA-001", 2000, 500);

    s1.displayDetails();
    c1.displayDetails();

    return 0;
}



