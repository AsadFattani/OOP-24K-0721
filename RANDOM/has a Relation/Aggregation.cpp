#include <iostream>
using namespace std;

class Employee {
    public:
        string name;
        int id;
        
        Employee(string namep, int IDp) : name(namep), id(IDp) {}

        void display() const{
            cout << "Employee ID: " << id << ", Name: " << name << endl;
        }
};

class Department {
    private:
        string deptName;
        Employee* employees[10];
        int employeeCount = 0;
    
    public:
        Department(string namep, Employee* empp) : deptName(namep) {
            employees[employeeCount++] = empp;
        }

        void addEmployee(Employee* emp) {
            employees[employeeCount++] = emp;
        }

        void displayDepartment() const {
            cout << "Department: " << deptName << endl;
            for (int i = 0; i < employeeCount; i++) {
                employees[i]->display();
            }
        }
};

int main(){
    Employee e1("Ahmed", 1);
    Employee e2("Salman", 2);
    Employee e3("Amir", 3);

    Department d1("IT", &e1);
    d1.addEmployee(&e2);
    d1.addEmployee(&e3);

    d1.displayDepartment();
    return 0;
}


