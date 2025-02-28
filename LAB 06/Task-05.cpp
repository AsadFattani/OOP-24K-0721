#include <iostream>
using namespace std;

class Device {
    protected:
        int deviceID;
        bool status;
    
    public:
        Device(int deviceID, bool status) : deviceID(deviceID), status(status) {}

        void displayDetails() {
            cout << "--------------------------------" << endl;
            cout << "Device ID: " << deviceID << endl;
            cout << "Status: " << (status ? "ON" : "OFF") << endl; 
        }
};

class SmartPhone : public Device {
    protected:
        float screenSize;

    public:
        SmartPhone(int deviceID, bool status, float screenSize) 
        : Device(deviceID, status), screenSize(screenSize) {}

        void displayDetails() {
            Device::displayDetails();
            cout << "Screen Size: " << screenSize << " inches" << endl;
        }
};

class SmartWatch : public Device {
    protected:
        bool heartRateMonitor;

    public:
        SmartWatch(int deviceID, bool status, bool heartRateMonitor) 
        : Device(deviceID, status), heartRateMonitor(heartRateMonitor) {}

        void displayDetails() {
            // Device::displayDetails();
            cout << "Heart Rate Monitor: " << (heartRateMonitor ? "YES" : "NO") << endl;
        }
};

class SmartWearable : public SmartPhone, public SmartWatch {
    protected:
        int stepCounter;

    public:
        SmartWearable(int deviceID, bool status, bool heartRateMonitor, float screenSize, int stepCounter)
        : SmartPhone(deviceID, status, screenSize), SmartWatch(deviceID, status, heartRateMonitor), stepCounter(stepCounter) {}

        void displayDetails() {
            SmartPhone::displayDetails();
            SmartWatch::displayDetails();
            cout << "Step Counter: " << stepCounter << " steps" << endl;
        }
};

int main() {
    SmartWearable wearable(123, true, true, 5.5, 1000);
    wearable.displayDetails();
    return 0;
}




