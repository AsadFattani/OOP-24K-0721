#include <iostream>
using namespace std;

class Car {
    private:
        string model;
        double price;

    public:
        Car(string m, double p) : model(m), price(p) {}

        friend class InventoryManager;

        friend void comparePrices(const Car &car1, const Car &car2);

        string getModel() {
            return model;
        }
};

void comparePrices(const Car &car1, const Car &car2) {
    if (car1.price > car2.price) {
        cout << car1.model << " is more expensive than " << car2.model << endl;
    } else if (car1.price < car2.price) {
        cout << car1.model << " is cheaper than " << car2.model << endl;
    } else {
        cout << car1.model << " and " << car2.model << " have the same price" << endl;
    }
}

class InventoryManager {
    public:
        void displayCarDetails(const Car &car) {
            cout << "Model: " << car.model << ", Price: " << car.price << endl;
        }

        void updatePrice(Car &car, double newPrice) {
            car.price = newPrice;
            cout << "Price updated to: " << car.price << endl;
        }

};

int main (){
    Car car1("Toyota", 20000.0);
    Car car2("Honda", 22000.0);

    InventoryManager manager;
    manager.displayCarDetails(car1);
    manager.displayCarDetails(car2);

    comparePrices(car1, car2);

    double newPrice;
    cout << "Enter new price for " << car1.getModel() << ": ";
    cin >> newPrice;
    manager.updatePrice(car1, newPrice);

    comparePrices(car1, car2);

    return 0;
}




