#include <iostream>
using namespace std;

struct Student {
    string name;
    int rollNumber;
    int marks[3];
};

void allocateStudents(Student **s, int num){
    *s = new Student[num];
}

void inputValues (Student *s, int num){
    for (int i = 0; i < num; i++){
        cout << "---Details of the student " << i + 1 << "---" << endl;
        cout << "Enter the name of the student: ";
        cin >> s[i].name;
        cout << "Enter the roll number of the student: ";
        cin >> s[i].rollNumber;
        for (int j = 0; j < 3; j++){
            cout << "Enter the marks of the student for subject " << j + 1 << ": ";
            cin >> s[i].marks[j];
        }
    }
}

void calculateAverage(Student *s, int num){
    for (int i = 0; i < num; i++){
        int sum = 0;
        for (int j = 0; j < 3; j++){
            sum += s[i].marks[j];
        }
        cout << "Average marks of " << s[i].name << " is: " << sum / 3 << endl;
    }
}

void freeMemory(Student *s){
    delete [] s;
}

int main (){
    int num;
    Student *s;
    
    cout << "Enter the number of students: ";
    cin >> num;

    allocateStudents(&s, num);
    inputValues(s, num);
    calculateAverage(s, num);
    freeMemory(s);

}


