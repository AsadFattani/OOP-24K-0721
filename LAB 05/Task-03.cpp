#include <iostream>
using namespace std;

class Employee {
public:
    string name;
    string designation;

    Employee(string name, string designation)
        : name(name), designation(designation) {}
};

class Project {
public:
    string title;
    string deadline;
    Employee* assignedEmployees[10]; // 10 employees per project
    int employeeCount;

    Project(string title, string deadline)
        : title(title), deadline(deadline), employeeCount(0) {}

    void addEmployee(Employee* employee) {
        if (employeeCount < 10) {
            assignedEmployees[employeeCount++] = employee;
        } else {
            cout << "Cannot add more employees to the project.\n";
        }
    }

    void displayProjectDetails() {
        cout << "Project Title: " << title << "\n";
        cout << "Deadline: " << deadline << "\n";
        cout << "Assigned Employees:\n";
        for (int i = 0; i < employeeCount; ++i) {
            cout << " - " << assignedEmployees[i]->name << " (" << assignedEmployees[i]->designation << ")\n";
        }
    }
};

int main() {
    Employee emp1("Alice", "Developer");
    Employee emp2("Bob", "Designer");
    Employee emp3("Charlie", "Manager");

    Project proj1("Project Alpha", "31-02-2025");
    Project proj2("Project Beta", "30-06-2025");

    proj1.addEmployee(&emp1);
    proj1.addEmployee(&emp2);
    proj2.addEmployee(&emp2);
    proj2.addEmployee(&emp3);

    proj1.displayProjectDetails();
    cout << endl;
    proj2.displayProjectDetails();
    cout << endl;

    return 0;
}