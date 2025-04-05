#include <iostream>
using namespace std;

class Account {
    private:
        int accountNumber;
        double balance;

    public:
        Account(int accNum, double bal) : accountNumber(accNum), balance(bal) {}

        friend class Manager;

        friend void transferFunds(Account &from, Account &to, double amount);
};

void transferFunds(Account &from, Account &to, double amount) {
    if (from.balance >= amount) {
        from.balance -= amount;
        to.balance += amount;
        cout << "Transfer successful! New balance of sender: " << from.balance << endl;
    } else {
        cout << "Insufficient funds for transfer!" << endl;
    }
}

class Manager {
    public:
        void displayAccountDetails(const Account &acc) {
            cout << "Account Number: " << acc.accountNumber << ", Balance: " << acc.balance << endl;
        }

        void updateBalance(Account &acc) {
            char choice;
            double amount;
            cout << "Do you want to deposit (d) or withdraw (w)? ";
            cin >> choice;

            if (choice == 'd' || choice == 'D') {
                cout << "Enter amount to deposit: ";
                cin >> amount;
                acc.balance += amount;
                cout << "Deposit successful! New balance: " << acc.balance << endl;
            } else if (choice == 'w' || choice == 'W') {
                cout << "Enter amount to withdraw: ";
                cin >> amount;
                if (acc.balance >= amount) {
                    acc.balance -= amount;
                    cout << "Withdrawal successful! New balance: " << acc.balance << endl;
                } else {
                    cout << "Insufficient funds for withdrawal!" << endl;
                }
            } else {
                cout << "Invalid choice!" << endl;
            }
        }
};

int main() {
    Account acc1(101, 500.0);
    Account acc2(102, 300.0);

    Manager manager;

    cout << "Initial account details:" << endl;
    manager.displayAccountDetails(acc1);
    manager.displayAccountDetails(acc2);

    cout << "\nUpdating balance for Account 1:" << endl;
    manager.updateBalance(acc1);

    cout << "\nUpdating balance for Account 2:" << endl;
    manager.updateBalance(acc2);

    cout << "\nTransferring 300 from Account 1 to Account 2:" << endl;
    transferFunds(acc1, acc2, 300.0);

    cout << "\nFinal account details:" << endl;
    manager.displayAccountDetails(acc1);
    manager.displayAccountDetails(acc2);

    return 0;
}







