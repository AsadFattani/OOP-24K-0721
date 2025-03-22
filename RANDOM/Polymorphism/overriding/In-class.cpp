#include <iostream>
using namespace std;

class Base{
    public:
        // virtual is identifier tells compiler that it has been redefined/overridden in derived class
        virtual void display (){
            cout << "From base class" << endl;
        }
};

class Derived: public Base{
    public:
        void display (){
            cout << "From derived class" << endl;
        }
};

int main (){
    Base *ptr, b1;
    Derived d1;

    ptr = &d1;
    ptr->display();

    ptr = &b1;
    ptr->display();
}

