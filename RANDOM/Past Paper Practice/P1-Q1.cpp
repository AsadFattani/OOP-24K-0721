#include <iostream>
using namespace std;

class SamsungSmartAppliance {
    protected:
        string modelName;
        bool powerOn;
        int currentMode;
        int numberOfModes;

    public:
        SamsungSmartAppliance (string name, int num) 
        : modelName(name), powerOn(false), currentMode(0), numberOfModes(num) {}

        void setPower(bool state) {
            powerOn = state;
        }

        bool isPowerOn() const {
            return powerOn;
        }

        virtual void displayStatus() const {
            cout << "Model Name: " << modelName << endl;
            cout << "Power State: " << (powerOn? "On" : "off") << endl;
            if (powerOn) {
                cout << "Mode Index: " << currentMode << endl;
            }
        }

        SamsungSmartAppliance& operator++(){
            if (powerOn) {
                currentMode = (currentMode + 1) % numberOfModes;
            }
            return *this;
        }
};

class SamsungSmartTv : public SamsungSmartAppliance {
    public:
        SamsungSmartTv(string name) : SamsungSmartAppliance(name, 5) {}

        void displayStatus() const {
            cout << "Smart TV" << endl;
            SamsungSmartAppliance::displayStatus();
        };
};

class SamsungWashingMachine : public SamsungSmartAppliance {
    public:
        SamsungWashingMachine(string name) : SamsungSmartAppliance(name, 3) {}

        void displayStatus() const {
            cout << "Washing Machine" << endl;
            SamsungSmartAppliance::displayStatus();
        };
};

int main (){
    SamsungSmartTv tv("Samsung QLED TV 2025");
    SamsungWashingMachine wm("Samsung EcoBubble 2025");

    tv.displayStatus();
    cout << endl;
    wm.displayStatus();
    
    tv.setPower(true);
    wm.setPower(true);
    
    ++tv;
    ++wm;
    ++wm;
    
    cout << endl;
    tv.displayStatus();
    cout << endl;
    wm.displayStatus();

    return 0;
}


