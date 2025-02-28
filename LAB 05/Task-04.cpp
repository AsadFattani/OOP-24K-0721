#include <iostream>
using namespace std;

class AlarmSystem {
private:
    string securityLevel;

public:
    AlarmSystem(const string& level) : securityLevel(level) {
        cout << "AlarmSystem created with security level: " << securityLevel << endl;
    }

    ~AlarmSystem() {
        cout << "AlarmSystem destroyed" << endl;
    }

    void display() const {
        cout << "Alarm System Security Level: " << securityLevel << endl;
    }
};

class SmartHome {
private:
    AlarmSystem alarmSystem;

public:
    SmartHome(const string& alarmLevel) : alarmSystem(alarmLevel) {
        cout << "SmartHome created" << endl;
    }

    ~SmartHome() {
        cout << "SmartHome destroyed" << endl;
    }

    void display() const {
        cout << "SmartHome Details:" << endl;
        alarmSystem.display();
    }
};

int main() {
    SmartHome myHome("High");
    myHome.display();
    return 0;
}