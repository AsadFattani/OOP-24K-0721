#ifndef LABCOURSE_H
#define LABCOURSE_H

#include "Course.h"
#include <iostream>
using namespace std;

class LabCourse : public Course {
    private:
        double labScore;
        double projectScore;
    public:
        LabCourse(string code, int credits, double lab, double project);

        double calculateGrade();
        void displayInfo();

};

#endif
