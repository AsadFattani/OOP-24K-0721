#ifndef LECTURE_COURSE_H
#define LECTURE_COURSE_H

#include "Course.h"
#include <iostream>
using namespace std;

class LectureCourse : public Course {
private:
    double midtermScore;
    double finalScore;
    double assignmentScore;

public:
    LectureCourse(string code, int credits, double midterm, double final, double assignment);
    
    double calculateGrade();
    void displayInfo();
    
};

#endif