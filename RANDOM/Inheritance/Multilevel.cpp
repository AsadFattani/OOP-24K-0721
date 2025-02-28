#include <iostream>
using namespace std;

// multi-level inheritance
// Base --> Derived1 --> Derived2 --> Derived3

class Vehicle {
    protected:
        string brand;
        int modelYear;

    public:
        Vehicle (string brand, int modelYear) : brand(brand), modelYear(modelYear) {}

        void display() {
            cout << "--------------------------------" << endl;
            cout << "Car Brand: " << brand << endl;
            cout << "Model: " << modelYear << endl;
        }
};

class Car: public Vehicle {
    protected:
        int numDoor;
    
    public:
        // use of Vehicle constructor for initialization
        Car (string brand, int modelYear, int numDoor) : Vehicle(brand, modelYear), numDoor(numDoor) {} 

        void display() {
            Vehicle::display(); // calling display() of Vehicle class using scope resolution operator (::)
            cout << "Number of Doors: " << numDoor << endl;
        }
    
};

class SportsCar : public Car {
    protected:
        int topSpeed;

    public:
        SportsCar (string brand, int modelYear, int numDoor, int topSpeed) : Car(brand, modelYear, numDoor), topSpeed(topSpeed) {}

        void carDisplay() {
            display(); // calling display() of Car class by renaming the current display() function
            cout << "Top Speed: " << topSpeed << " km/h" << endl;
        }
};

// Vehicle (base) --> Car (derived 1) --> SportsCar (derived 2)

// 2 ways for display function 
// line 30 (::) and line 44 (renaming)

int main () {
    SportsCar s1("Koenigsegg", 2021, 2, 400);
    s1.display();

    return 0;
}