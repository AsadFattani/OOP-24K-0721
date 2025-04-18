#include <iostream>
using namespace std;

class Patient {
protected:
    string name;
    string id;

public:
    virtual void displayTreatment() = 0; 
    virtual double calculateCost() = 0; 
};

class InPatient : public Patient {
private:
    int daysAdmitted;
    double dailyRate;

public:
    void displayTreatment() {
        cout << "InPatient Treatment Details:\n";
        cout << "Name: " << name << ", ID: " << id << "\n";
        cout << "Admitted for " << daysAdmitted << " days at a daily rate of $" << dailyRate << ".\n";
    }

    double calculateCost() {
        return daysAdmitted * dailyRate;
    }
};

// Derived Class OutPatient
class OutPatient : public Patient {
private:
    int numVisits;
    double costPerVisit;

public:

    void displayTreatment() {
        cout << "OutPatient Treatment Details:\n";
        cout << "Name: " << name << ", ID: " << id << "\n";
        cout << "Number of visits: " << numVisits << " at a cost of $" << costPerVisit << " per visit.\n";
    }

    double calculateCost() {
        return numVisits * costPerVisit;
    }
};

int main() {
    Patient* patient1 = new InPatient();
    Patient* patient2 = new OutPatient();
    
    patient1->displayTreatment();
    cout << "Total Cost: $" << patient1->calculateCost() << "\n\n";

    patient2->displayTreatment();
    cout << "Total Cost: $" << patient2->calculateCost() << "\n";

    return 0;
}