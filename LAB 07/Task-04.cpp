#include <iostream>
using namespace std;

class Person {
    protected:
        string name;
        int age;
        int contactNumber;
        string address;

    public:
        Person(string name, int age, int contactNumber, string address) 
        : name(name), age(age), contactNumber(contactNumber), address(address) {}

        virtual void displayInfo() {
            cout << "Name: " << name << endl;
            cout << "Age: " << age << endl;
            cout << "Contact Number: " << contactNumber << endl;
            cout << "Address: " << address << endl;
        }

        virtual void updateInfo() {
            cout << "Enter Name: ";
            cin >> name;
            cout << "Enter Age: ";
            cin >> age;
            cout << "Enter Contact Number: ";
            cin >> contactNumber;
            cout << "Enter Address: ";
            cin.ignore();
            getline(cin, address);
        }
};

class Patient : public Person {
    protected:
        int patientID;
        string medicalHistory;
        string doctorAssigned;

    public:
        Patient(string name, int age, int contactNumber, string address, int patientID, string medicalHistory, string doctorAssigned) 
        : Person(name, age, contactNumber, address), patientID(patientID), medicalHistory(medicalHistory), doctorAssigned(doctorAssigned) {}

        void displayInfo() {
            cout << "--- Patient Details ---" << endl;
            Person::displayInfo();
            cout << "Patient ID: " << patientID << endl;
            cout << "Medical History: " << medicalHistory << endl;
            cout << "Doctor Assigned: " << doctorAssigned << endl;
        }
    };
    
class Doctor : public Person {
    protected:
        string specialization;
        int consultationFee;
        string patientsList[5];
        int patients = 0;
        
    public:
        Doctor(string name, int age, int contactNumber, string address, string specialization, int fee, string patient) 
        : Person(name, age, contactNumber, address), specialization(specialization), consultationFee(fee) {
            patientsList[patients++] = patient;
        }
        
        void displayInfo() {
            cout << "--- Doctor Details ---" << endl;
            Person::displayInfo();
            cout << "Specialization: " << specialization << endl;
            cout << "Consultation Fee: " << consultationFee << endl;
            for (int i = 0; i < patients; i++) {
                cout << "Patient " << i + 1 << " : " << patientsList[i] << endl;
            }
        }
};

class Nurse : public Person {
    protected:
        string assignedWard;
        string shiftTimings;

    public:
        Nurse(string name, int age, int contactNumber, string address, string assignedWard, string shiftTimings) 
        : Person(name, age, contactNumber, address), assignedWard(assignedWard), shiftTimings(shiftTimings) {}

        void displayInfo() {
            cout << "--- Nurse Details ---" << endl;
            Person::displayInfo();
            cout << "Assigned Ward: " << assignedWard << endl;
            cout << "Shift Timings: " << shiftTimings << endl;
        }
};

class Administrator : public Person {
    protected:
        string department;
        string salary;
    
    public:
        Administrator(string name, int age, int contactNumber, string address, string department, string salary) 
        : Person(name, age, contactNumber, address), department(department), salary(salary) {}

        void updateInfo() {
            cout << "Updating Admin Info..." << endl;
            Person::updateInfo();
            cout << "Enter Department: ";
            cin >> department;
            cout << "Enter Salary: ";
            cin >> salary;
        }
};

int main (){
    Patient patient("John Doe", 25, 123456789, "New York", 101, "None", "Dr. Smith");
    patient.displayInfo();
    cout << endl;

    Doctor doctor("Dr. Smith", 35, 987654321, "Chicago", "Cardiologist", 100, "John Doe");
    doctor.displayInfo();
    cout << endl;

    Nurse nurse("Alice Brown", 30, 456789123, "Los Angeles", "Ward 1", "8:00 AM - 4:00 PM");
    nurse.displayInfo();
    cout << endl;

    Administrator admin("Bob White", 40, 789123456, "Las Vegas", "HR", "$5000");
    admin.updateInfo();
    cout << endl;

    return 0;
}


