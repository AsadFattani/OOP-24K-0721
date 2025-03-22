#include <iostream>
using namespace std;

class Base{
    public:
        void display (int x){
            cout << "Base - display : int x : " << x << endl;
        }
        void display (double x){
            cout << "Base - display : double x : " << x << endl;
        }
};

class Derived: public Base{
    public:
        using Base::display;
        void display (const char *c){
            cout << "Derived - class : string c : " << c << endl;
        }
};

int main (){
    Base b1;
    Derived d1;
    b1.display(5);
    b1.display(10.5);

    //d1.display(5); // not possible hidden
    d1.Base::display(10.5);
    d1.display(10.5); // now possible with using keyword
}

