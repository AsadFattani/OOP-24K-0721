#include <iostream>
using namespace std;

class Doctor {
    private:
        string name;
        string specialization;
        int experience;
    
    public:
        Doctor(string name, string specialization, int experience) 
            :  name(name), specialization(specialization), experience(experience) {}
        
        void display() {
            cout << "Name: " << name << endl;
            cout << "Specialization: " << specialization << endl;
            cout << "Experience: " << experience << " years" << endl;
        }
};

class Hospital {
    private:
        Doctor** doctors;
        int doctorCount;

    public:
        Hospital() : doctorCount(0) {
            doctors = new Doctor*[10];
            for (int i = 0; i < 10; i++) {
                doctors[i] = nullptr;
            }
        }

        ~Hospital() {
            delete[] doctors;
        }

        void addDoctor(Doctor* doctor) {
            if (doctorCount < 10) {
                doctors[doctorCount++] = doctor;
            } else {
                cout << "Hospital is full, cannot add more doctors." << endl;
            }
        }

        void removeDoctor(Doctor* doctor) {
            for (int i = 0; i < doctorCount; i++) {
                if (doctors[i] == doctor) {
                    for (int j = i; j < doctorCount - 1; j++) {
                        doctors[j] = doctors[j + 1];
                    }
                    doctors[--doctorCount] = nullptr;
                    break;
                }
            }
        }

        void display() {
            cout << "Hospital has " << doctorCount << " doctors:" << endl;
            for (int i = 0; i < doctorCount; i++) {
                doctors[i]->display();
            }
        }
};

int main() {
    Hospital hospital;

    Doctor doctor1("Dr. Smith", "Cardiologist", 5);
    Doctor doctor2("Dr. Johnson", "Neurologist", 10);
    Doctor doctor3("Dr. Lee", "Dermatologist", 3);

    hospital.addDoctor(&doctor1);
    hospital.addDoctor(&doctor2);
    hospital.addDoctor(&doctor3);

    hospital.display();

    return 0;
}




