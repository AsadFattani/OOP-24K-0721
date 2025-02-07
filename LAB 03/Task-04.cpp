#include <iostream>
using namespace std;

class Car {
    private:
        string brand, model;
        int fuelCapacity, currentFuelLevel;
    public:
        Car(string b, string m, int fc, int cfl) { 
            brand = b;
            model = m;
            fuelCapacity = fc;
            currentFuelLevel = cfl;
        }

        void drive(int distance) {
            int fuelConsumed = distance / 10; // Assuming 10 km per liter
            if (currentFuelLevel >= fuelConsumed) {
                currentFuelLevel -= fuelConsumed;
                cout << "You have driven " << distance << " km. Current fuel level: " << currentFuelLevel << " liters." << endl;
            } else {
                cout << "Not enough fuel to drive " << distance << " km." << endl;
            }
        }

        void refuel(int amount) {
            if (currentFuelLevel + amount <= fuelCapacity) {
                currentFuelLevel += amount;
                cout << "You have refueled " << amount << " liters. Current fuel level: " << currentFuelLevel << " liters." << endl;
            } else {
                cout << "Cannot refuel " << amount << " liters. It exceeds the fuel capacity." << endl;
            }
        }

        void checkFuelStatus() const {
            if (currentFuelLevel < 10) {
                cout << "Warning: Low fuel level. Current fuel level: " << currentFuelLevel << " liters." << endl;
            } else {
                cout << "Current fuel level: " << currentFuelLevel << " liters." << endl;
            }
        }
};

int main (){
    cout << "Enter car brand: ";
    string brand;
    cin >> brand;

    cout << "Enter car model: ";
    string madel;
    cin >> madel;

    cout << "Enter fuel capacity: ";
    int fuelCapacity;
    cin >> fuelCapacity;

    cout << "Enter current fuel level: ";
    int currentFuelLevel;
    cin >> currentFuelLevel;

    Car myCar(brand, madel, fuelCapacity, currentFuelLevel);
    
    while (true) {
        cout << "1. Drive" << endl;
        cout << "2. Refuel" << endl;
        cout << "3. Check Fuel Status" << endl;
        cout << "0. Exit" << endl;
        
        int choice;
        cout << "Enter choice: ";
        cin >> choice;
        
        switch (choice) {
            case 1: {
                int distance;
                cout << "Enter distance to drive: ";
                cin >> distance;
                myCar.drive(distance);
                break;
            }
            case 2: {
                int amount;
                cout << "Enter amount to refuel: ";
                cin >> amount;
                myCar.refuel(amount);
                break;
            }
            case 3:
                myCar.checkFuelStatus();
                break;
            case 0:
                return 0;
            default:
                cout << "Invalid choice" << endl;
                break;
        }
    }
    return 0;
}




