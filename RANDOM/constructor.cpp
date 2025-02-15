#include <iostream>
using namespace std;

class BankAccount{
    string name;
    double balance;
    bool isActive = false;
    
    public:
        BankAccount (){
            name = "Unknown";
            balance = 0.0;
        }
        BankAccount (string n, double b){
            name = n;
            balance = b;
        }
        void deposit (double amount){
            if (amount >= 0){
                balance += amount;
            }else{
                cout << "deposit failed!" << endl;
            }
        }
        void withdraw (double amount){
            if (amount >= 0 && amount <= balance){
                balance -= amount;
            }else{
                cout << "Withdraw failed!" << endl;
            }
        }
        void display (){
            cout << "-------------------------------" << endl;
            cout << "Name: " << name << endl;
            cout << "Balance: " << balance << endl;
        }
};

int main(){
    BankAccount Bank1;
    Bank1.display();
    BankAccount Bank2("Amir", 10000.0);
    Bank2.display();
    Bank2.deposit(5000.0);
    Bank2.display();
    Bank2.withdraw(2000.0);
    Bank2.display();
    Bank2.deposit(-150);
    Bank2.display();
    Bank2.withdraw(20000.0);
    Bank2.display();
    return 0;
}


