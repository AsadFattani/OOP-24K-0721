#include <iostream>
using namespace std;

struct Employee {
    string name;
    int hoursWorked;
    float hourlyRate;
};

void allocateEmployees(Employee **e, int num) {
    *e = new Employee[num];
}

void inputValues(Employee *e, int num) {
    for (int i = 0; i < num; i++) {
        cout << "---Details of the employee " << i + 1 << "---" << endl;
        cout << "Enter the name of the employee: ";
        cin >> e[i].name;
        cout << "Enter the hours worked by the employee: ";
        cin >> e[i].hoursWorked;
        cout << "Enter the hourly rate of the employee: ";
        cin >> e[i].hourlyRate;
    }
}

void totalSalary(Employee *e, int num){
    float total = 0;
    cout << "---Total Salary For Each Employee---" << endl;
    for (int i = 0; i < num; i++){
        total += e[i].hoursWorked * e[i].hourlyRate;
        cout << "Total salary of " << e[i].name << " is " << e[i].hoursWorked * e[i].hourlyRate << endl;
    }
}

void freeMemory(Employee *e) {
    delete[] e;
}

int main (){
    int num;
    Employee *e;
    
    cout << "Enter the number of employees: ";
    cin >> num;

    allocateEmployees(&e, num);
    inputValues(e, num);
    totalSalary(e, num);
    freeMemory(e);  
}


