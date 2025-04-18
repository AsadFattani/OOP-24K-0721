#include "LabCourse.h"
#include <iostream>
using namespace std;

LabCourse::LabCourse(string code, int credits, double lab, double project)
    : Course(code, credits), labScore(lab), projectScore(project) {
}

double LabCourse::calculateGrade() {
    return (labScore * 0.4) + (projectScore * 0.6);
}

void LabCourse::displayInfo() {
    cout << "Lab Course: " << getCourseCode() << endl;
    cout << "Credits: " << getCredits() << endl;
    cout << "Lab Score: " << labScore << endl;
    cout << "Project Score: " << projectScore << endl;
    cout << "Final Grade: " << calculateGrade() << endl;
}
 



