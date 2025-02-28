#include <iostream>
using namespace std;

class Vehicle {
    protected:
        string brand;
        int speed;
    public:
        Vehicle(string brand, int speed) 
        : brand(brand), speed(speed) {}
        void displayDetails(){
            cout << "----------" << endl;
            cout << "Brand: " << brand << endl;
            cout << "speed: " << speed << endl;
        }
};

class Car : public Vehicle{
    protected:
        int seats;
    public:
        Car (string brand, int speed, int seats) 
        : Vehicle(brand, speed), seats(seats){}
        void displayDetails(){
            Vehicle::displayDetails();
            cout << "seats: " << seats << endl;
        }

};

class ElectricCar : public Car {
    protected:
        int batteryLife;

    public:
        ElectricCar(string brand, int speed, int seats, int batteryLife) 
        : Car (brand, speed, seats), batteryLife(batteryLife) {}
    void displayDetails(){
        Car::displayDetails();
        cout << "Battery life: " << batteryLife << endl;
    }

};

int main(){
    ElectricCar e1("tesla", 150, 4, 200);
    e1.displayDetails();
}