#include <iostream>
using namespace std;

class Student {
    private:
        int ID;
        string name;
        int* Score[5];

    public:
        Student(int ID, string name, int Score[5]) : ID(ID), name(name) {
            for (int i = 0; i < 5; i++) {
                this->Score[i] = new int(Score[i]);
            }
        }

        Student(Student& student) : ID(student.ID), name(student.name) {
            for (int i = 0; i < 5; i++) {
                this->Score[i] = new int(*student.Score[i]);
            }
        }

        ~Student() {
            for (int i = 0; i < 5; i++) {
                delete Score[i];
            }
        }

        void display() {
            cout << "--------------------------------" << endl;
            cout << "Student ID: " << ID << endl;
            cout << "Name: " << name << endl;
            cout << "Scores: ";
            for (int i = 0; i < 5; i++) {
                cout << *Score[i] << " ";
            }
            cout << endl;
        }
};

int main (){
    int scores1[5] = {90, 80, 70, 60, 50};
    int scores2[5] = {85, 75, 65, 55, 45};

    Student student1(1, "Ali", scores1);
    Student student2(2, "Ahmed", scores2);
    Student student3 = student1;

    cout << "Student 1 details:" << endl;
    student1.display();
    cout << endl;

    cout << "Student 2 details:" << endl;
    student2.display();
    cout << endl;

    cout << "Student 3 details (copy of Student 1):" << endl;
    student3.display();
    cout << endl;

    return 0;
}






