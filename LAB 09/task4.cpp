#include <iostream>
using namespace std;

class WeatherSensor {
    public:
        virtual void readData () = 0;
        virtual void displayReport () = 0;
};

class Thermometer : public WeatherSensor {
    public:
        void readData () {
            cout << "Reading temperature data..." << endl;
        }
        void displayReport () {
            cout << "Temperature report: 25 degrees Celsius" << endl;
        }
};

class Barometer : public WeatherSensor {
    public:
        void readData () {
            cout << "Reading pressure data..." << endl;
        }
        void displayReport () {
            cout << "Pressure report: 1013 hPa" << endl;
        }
};

int main (){
    WeatherSensor* sensor1 = new Thermometer();
    WeatherSensor* sensor2 = new Barometer();

    sensor1->readData();
    sensor1->displayReport();

    cout << endl;

    sensor2->readData();
    sensor2->displayReport();

    delete sensor1;
    delete sensor2;

    return 0;
}





