#include <iostream>
#include <stdexcept>

using namespace std;

class AccountException : public exception {
    public:
        string message;

        AccountException(string msg) : message(msg) {}

        const char* what() noexcept { // can use virtual what here
            return message.c_str();
        }
};

class InvalidAcoountNumber : public AccountException {
    public:
        InvalidAcoountNumber(string msg) : AccountException(msg) {}
};

class InsufficientFunds : public AccountException {
    public:
        InsufficientFunds(string msg) : AccountException(msg) {}
};

class InvalidAccount : public AccountException {
    public:
        InvalidAccount(string msg) : AccountException(msg) {}
};

class BankAccount {
    private:
        string accountNumber;
        double balance;

    public:
        BankAccount(string accNum, double initialBalance) : accountNumber(accNum), balance(initialBalance) {
            if (accountNumber < "10000" || accountNumber > "99999") {
                throw InvalidAcoountNumber("Invalid account number!!");
            }
            if (balance < 0) {
                throw InsufficientFunds("Initial balance cannot be negative!!");
            }
        }

        void deposit(double amount) {
            if (amount <= 0) {
                throw InvalidAccount("Deposit amount must be positive!!");
            }
            balance += amount;
            cout << "Deposited: $" << amount << "| New balance: $" << balance << endl;
        }

        void withdraw(double amount) {
            if (amount <= 0) {
                throw InvalidAccount("Withdrawal amount must be positive!!");
            }
            if (amount > balance) {
                throw InsufficientFunds("Insufficient funds for withdrawal!!");
            }
            balance -= amount;
            cout << "Withdrawn: $" << amount << "| New balance: $" << balance << endl;
        }


};        

int main() {
    try {
        BankAccount account("12345", 1000.0);
        account.deposit(50000.0);
        account.deposit(-50.0);
    } catch (AccountException &e) {
        cout << "Exception: " << e.what() << endl;
    }

    try {
        BankAccount account("12345", 1000.0);
        account.withdraw(2000.0);
        account.withdraw(-50.0);
    } catch (AccountException &e) {
        cout << "Exception: " << e.what() << endl;
    }
}