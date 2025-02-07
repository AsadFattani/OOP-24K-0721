#include <iostream>
using namespace std;

class Wallet {
    private:
        string ownerName = "Saad";
        double totalBalance = 0.0;
        double transactionHistory[100];
        int transactionCount = 0;
    public:
        void addMoney(double amount){
            totalBalance += amount;
            transactionHistory[transactionCount++] = amount;
            cout << "Amount added successfully" << endl;
        }
        void spendMoney(double amount){
            totalBalance -= amount;
            transactionHistory[transactionCount++] = -amount;
            cout << "Amount spent successfully" << endl;
        }
        void printTransactionHistory() {
            cout << "--- Transaction History ---" << endl;
            cout << "Owner Name: " << ownerName << endl;
            for (int i = 0; i < transactionCount; i++) {
                cout << i + 1 << ". " << transactionHistory[i] << endl;
            }
            cout << endl;
        }
};

int main() {
    Wallet myWallet;
    
    while (true) {
        cout << "1. Add Money" << endl;
        cout << "2. Spend Money" << endl;
        cout << "3. Print Transaction History" << endl;
        cout << "0. Exit" << endl;
        
        int choice;
        cout << "Enter choice: ";
        cin >> choice;
        
        switch (choice) {
            case 1: 
                double amount;
                cout << "Enter amount to add: ";
                cin >> amount;
                myWallet.addMoney(amount);
                break;
            case 2: 
                double amount;
                cout << "Enter amount to spend: ";
                cin >> amount;
                myWallet.spendMoney(amount);
                break;
            case 3:
                myWallet.printTransactionHistory();
                break;
            case 0:
                return 0;
            default:
            cout << "Invalid choice" << endl;
        }
    }
    return 0;
}





