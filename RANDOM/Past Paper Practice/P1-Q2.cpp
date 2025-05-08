#include <iostream>
using namespace std;

class Vehicle {
    protected:
        string modelID;

    public:
        Vehicle(string id) : modelID(id) {}

        virtual void assembleVehicle() const {
            cout << "Assembling vehicle with model ID: " << modelID << endl;
        }
};

class Car : virtual public Vehicle {
    private:
        float enginePower;

    public:
        Car(string id, float power) : Vehicle(id), enginePower(power) {}

        void assembleVehicle() const {
            Vehicle::assembleVehicle();
            cout << "Assembling car with engine power: " << enginePower << " HP" << endl;
        }

        float getEnginePower() const {
            return enginePower;
        }

        void setEnginePower(float power) {
            enginePower = power;
        }
};

class Motorcycle : virtual public Vehicle {
    private:
        float torque;

    public:
        Motorcycle(string id, float t) : Vehicle(id), torque(t) {}

        void assembleVehicle() const {
            Vehicle::assembleVehicle();
            cout << "Assembling motorcycle with torque: " << torque << " Nm" << endl;
        }

        float getTorque() const {
            return torque;
        }

        void setTorque(float t) {
            torque = t;
        }
};

class HybridVehicle : public Car, public Motorcycle {
    public:
        HybridVehicle(string id, float power, float t) 
            : Vehicle(id), Car(id, power), Motorcycle(id, t) {}

        void assembleVehicle() const {
            cout << "Assembling Vehicle with Power: " << (Car::getEnginePower() * Motorcycle::getTorque()) << " HP" << endl;
        }
};

class QualityControlSystem {
    public:
        void inspectCar(const Car& car) const {
            car.assembleVehicle();
        }

        void inspectMotorcycle(const Motorcycle& motorcycle) const {
            motorcycle.assembleVehicle();
        }
};

// Non-member functions
void calibrateEngine(Car& car, float newPower) {
    car.setEnginePower(newPower);
    cout << "Calibrated Car Engine Power to: " << newPower << " HP" << endl;
}

void calibrateTorque(Motorcycle& motorcycle, float newTorque) {
    motorcycle.setTorque(newTorque);
    cout << "Calibrated Motorcycle Torque to: " << newTorque << " Nm" << endl;
}

int main() {
    Car car("C123", 150.0);
    Motorcycle motorcycle("M456", 80.0);
    HybridVehicle hybrid("H789", 200.0, 100.0);

    QualityControlSystem qc;

    qc.inspectCar(car);
    qc.inspectMotorcycle(motorcycle);

    calibrateEngine(car, 180.0);
    calibrateTorque(motorcycle, 90.0);

    qc.inspectCar(car);
    qc.inspectMotorcycle(motorcycle);

    hybrid.assembleVehicle();

    return 0;
}


