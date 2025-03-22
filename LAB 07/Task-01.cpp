#include <iostream>
using namespace std;

class Device {
    protected:
        int deviceID;
        string deviceName;
        bool status;
        string location;

    public:
        Device(int deviceID, string deviceName, bool status, string location) 
        : deviceID(deviceID), deviceName(deviceName), status(status), location(location) {}

        virtual void turnOn (){
            status = true;
        }
        virtual void turnOff (){
            status = false;
        }
        virtual void getStatus (){
            cout << status? "On" : "Off";
            cout << endl; 
        }
        virtual void displayInfo (){
            cout << "Device ID: " << deviceID << endl;
            cout << "Device Name: " << deviceName << endl;
            cout << "Device Status: " << status? "On" : "Off";
            cout << endl;
            cout << "Device Location: " << location << endl;
        }
};

class Light : public Device {
    protected:
        int brightnessLevel;
        string colorMode;

    public:
        Light(int deviceID, string deviceName, bool status, string location, int bLevel, string colorMode) 
        : Device(deviceID, deviceName, status, location), brightnessLevel(bLevel), colorMode(colorMode) {}

        void displayInfo () {
            Device::displayInfo();
            cout << "Brightness Level: " << brightnessLevel << endl;
            cout << "Color Mode: " << colorMode << endl;
        }
};

class Thermostat : public Device {
    protected:
        int temperature;
        bool mode;
        int targetTemperature;
    
    public:
        Thermostat(int deviceID, string deviceName, bool status, string location, int temperature, bool mode, int targetTemp) 
        : Device(deviceID, deviceName, status, location), temperature(temperature), mode(mode), targetTemperature(targetTemp) {}

        void getStatus (){
            cout << "Current Temperature: " << temperature << endl;
        }

};

class SecurityCamera : public Device {
    protected:
        int resolution;
        bool recordingStatus;
        bool nightVisionEnabled;
    
    public:
        SecurityCamera(int deviceID, string deviceName, bool status, string location, int resolution, bool rStatus, bool nVEnabled) 
        : Device(deviceID, deviceName, status, location), resolution(resolution), recordingStatus(rStatus), nightVisionEnabled(nVEnabled) {}

        void turnOn (){
            recordingStatus = true;
        }

};

class SmartPlug : public Device {
    protected:
        int powerConsumption;
        bool timerSettings;

    public:
        SmartPlug(int deviceID, string deviceName, bool status, string location, int powerConsumption, bool timerSettings) 
        : Device(deviceID, deviceName, status, location), powerConsumption(powerConsumption), timerSettings(timerSettings) {}

        void turnOff() {
            cout << "Logging power usage: " << powerConsumption << endl;
        }
};

int main () {
    Light l1(101, "Philips", true, "Living Room", 8, "RGB");
    l1.displayInfo();
    cout << endl;
    
    Thermostat t1(102, "Haier", false, "Bedroom", 22, true, 25);
    t1.getStatus();
    cout << endl;
    
    SecurityCamera s1(103, "HomeSafe", true, "Garage", 1080, true, true);
    s1.turnOn();
    cout << endl;
    
    SmartPlug p1(104, "TP-Link", true, "Kitchen", 150, true);
    p1.turnOff();
    cout << endl;

    return 0;
}





