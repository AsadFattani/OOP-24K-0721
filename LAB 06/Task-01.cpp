#include <iostream>
using namespace std;

class Employee {
    protected:
        string name;
        float salary;

    public:
        Employee (string name, float salary) : name(name), salary(salary) {}

        void displayDetails(){
            cout << "------------------------" << endl;
            cout << "Employee name: " << name << endl;
            cout << "Salary: " << salary << endl;
        }
};

class manager : public Employee{
    protected:
        float bonus;

    public:
        manager(string name, float salary, float bonus) 
        : Employee(name, salary), bonus(bonus) {}

        void displayDetails(){
            Employee::displayDetails();
            cout << "Bonus: " << bonus << endl;
        }
};

int main(){
    manager m("Amir", 100000, 50000);
    m.displayDetails();
}