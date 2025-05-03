#include <iostream>
#include <stdexcept>

using namespace std;

class InvalidTemperatureException : public exception {
};

template <typename T>
T convertToFahrenheit(T celsius) {
    if (celsius < -273.15) {
        throw InvalidTemperatureException();
    }
    return (celsius * 9 / 5) + 32;
}

int main() {
    try {
        cout << "Attempting to convert -300C..." << endl;
        double fahrenheit = convertToFahrenheit(-300.0); // This will throw an exception
        cout << "Converted temperature: " << fahrenheit << "F" << endl;
    } catch (InvalidTemperatureException& e) {
        cout << "Caught InvalidTemperatureException - what(): " << e.what() << endl;
    }

    return 0;
}
