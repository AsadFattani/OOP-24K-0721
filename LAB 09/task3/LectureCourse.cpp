#include "LectureCourse.h"
#include <iostream>
using namespace std;

LectureCourse::LectureCourse(string code, int credits, double midterm, double final, double assignment)
    : Course(code, credits), midtermScore(midterm), finalScore(final), assignmentScore(assignment) {
}

double LectureCourse::calculateGrade() {
    return (midtermScore * 0.3) + (finalScore * 0.5) + (assignmentScore * 0.2);
}

void LectureCourse::displayInfo() {
    cout << "Lecture Course: " << getCourseCode() << endl;
    cout << "Credits: " << getCredits() << endl;
    cout << "Midterm Score: " << midtermScore << endl;
    cout << "Final Score: " << finalScore << endl;
    cout << "Assignment Score: " << assignmentScore << endl;
    cout << "Final Grade: " << calculateGrade() << endl;
}

