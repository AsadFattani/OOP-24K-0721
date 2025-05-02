#include <iostream>
using namespace std;


template <typename T, typename U, typename V>
class TemplateHandler {
    T a;
    U b;
    V c;
    
    public:
    TemplateHandler(T x, U y, V z) : a(x), b(y), c(z) {}
    
    void printValues() {
            cout << "Addition of float and int: " << a + b << endl;
        }

        void printDataType() {
            cout << "Value: " << c << endl;
        }
};

template <typename P>
class xyx {
    public: 
        P account;

        xyx(P a) : account(a) {}
};

int main (){
    TemplateHandler<int, double, char> t1(20, 15.4, 'A');
    t1.printValues();
    t1.printDataType();

    xyx<TemplateHandler<int, double, char>> t2(t1);

    return 0;
    
}


