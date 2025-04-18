#ifndef COURSE_H
#define COURSE_H

#include <iostream>
using namespace std;

class Course {
protected:
    string courseCode;
    int credits;

public:
    Course(const string&code, int creds) : courseCode(code), credits(creds) {}
    
    string getCourseCode() {
         return courseCode; 
    }
    
    int getCredits() { 
        return credits; 
    }
    
    virtual double calculateGrade() = 0;
    virtual void displayInfo() = 0;
};

#endif