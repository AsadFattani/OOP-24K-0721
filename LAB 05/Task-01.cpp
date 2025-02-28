#include <iostream>
#include <cstring>

using namespace std;

class Apartment {
private:
    int id;
    string address;
    char* ownerName;

public:
    Apartment(int id, string address, char* ownerName) : id(id), address(address) {
        this->ownerName = new char[strlen(ownerName) + 1];
        strcpy(this->ownerName, ownerName);
    }

    Apartment(Apartment& apt) : id(apt.id), address(apt.address) {
        this->ownerName = new char[strlen(apt.ownerName) + 1];
        strcpy(this->ownerName, apt.ownerName);
    }

    ~Apartment() {
        delete[] ownerName;
    }

    void display() {
        cout << "--------------------------------" << endl;
        cout << "Apartment ID: " << id << endl;
        cout << "Address: " << address << endl;
        cout << "Owner's Name: " << ownerName << endl;
    }
};

int main() {
    Apartment apt1(101, "jamshed rod", "amir");
    Apartment apt2(102, "kashmir road", "salman");
    Apartment apt3 = apt1;

    cout << "Apartment 1 details:" << endl;
    apt1.display();
    cout << endl;

    cout << "Apartment 2 details:" << endl;
    apt2.display();
    cout << endl;

    cout << "Apartment 3 details (copy of Apartment 1):" << endl;
    apt3.display();
    cout << endl;

    return 0;
}
