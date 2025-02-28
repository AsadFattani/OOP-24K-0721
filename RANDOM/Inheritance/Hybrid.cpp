#include <iostream>
using namespace std;

// Hybrid Inheritance
// multiple types in one (multiple, multilevel, single, hierarchical)

// Person --> Student 


class Person {
    protected:
        string name;
        int age;

    public:
        Person (string name, int age) : name(name), age(age) {}

        void display() {
            cout << "--------------------------------" << endl;
            cout << "Name: " << name << endl;
            cout << "Age: " << age << endl;
        }
    };

class Student : public Person {
    protected:
        string universityName;
    double gpa;
    
    public:
        Student (string name, int age, string universityName, double gpa) : Person(name, age), universityName(universityName), gpa(gpa) {}

        void displayStudentDetails() {
            Person::display();
            cout << "University: " << universityName << endl;
            cout << "GPA: " << gpa << endl;
        }
    };
    
class Employee {
        protected:
            int salary;
        
        public:
            Employee (int salary) : salary(salary) {}
            
            void displayEmployeeDetails() {
                // cout << "--------------------------------" << endl;
                cout << "Salary: " << salary << endl;
            }
};

class PartTimeEmployee : public Student, public Employee {
    protected:
        int workingHours;

    public:
        PartTimeEmployee (string name, int age, string universityName, double gpa, int salary, int workingHours) 
        : Student(name, age, universityName, gpa), 
        Employee(salary), workingHours(workingHours) {}

        void displayPartTimeEmployee() {
            displayStudentDetails();
            displayEmployeeDetails();
            cout << "Working Hours: " << workingHours << " hours" << endl;
        }
};

int main (){
    PartTimeEmployee p1("ABC", 24, "XYZ University", 3.8, 20000, 8);
    p1.displayPartTimeEmployee();
}






