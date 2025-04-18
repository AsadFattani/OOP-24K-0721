#include <iostream>
#include "Course.h"
#include "LabCourse.h"
#include "LectureCourse.h"

using namespace std;

int main() {
    Course* lecture = new LectureCourse("CS101", 3, 85, 90, 80);
    Course* lab = new LabCourse("CS102", 4, 25, 35);

    lecture->displayInfo();
    cout << endl;
    lab->displayInfo();

    delete lecture;
    delete lab;

    return 0;
}