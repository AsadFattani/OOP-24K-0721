#include <iostream>
using namespace std;

// Modes of Inheritance in C++ (public / private / protected)

class Base {
    protected: // only public can be manipulated by derived class
        int a;
        int b;

    public:
        Base (int a, int b) : a(a), b(b) {}

        void display() {
            cout << "a: " << a << ", b: " << b << endl;
        }
};

class Derived : public Base { // sub class 1
    public:
        int c;

        Derived (int a, int b, int c) : Base(a, b), c(c) {}

        void display() {
            cout << "a: " << a << ", b: " << b << endl;
        }
};

class Derived1 : public Base{ // sub class 2

};

int main () {
    // Base b1(1, 2);
    Derived d1(15, 10, 4);
    
    // b1.display();
    d1.display();
    d1.c; // Accessible
    // d1.a; // Not Accessible as it is protected in Base class

    return 0;
}


