#include <iostream>
using namespace std;

class TemplateClass {

    public:
        template <typename T, typename U>

        void printValue(T a, U b) {
            cout << "Addition: " << a + b << endl;
        }
};

int main(){
    TemplateClass t1;

    t1.printValue<int, double>(20, 15.4);
}


