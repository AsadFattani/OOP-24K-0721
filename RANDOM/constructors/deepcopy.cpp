#include <iostream>
using namespace std;

class deepCopy {
    public:
        int *data = new int;

        deepCopy(int num){
            *data = num;
        }

        deepCopy(deepCopy &obj){
            data = new int;
            *data = *(obj.data);
        }

        void display(){
            cout << "Data: " << *data << endl;
            cout << "Addresse " << data << endl;
        }
};

int main(){
    deepCopy s1(5);
    deepCopy s2(s1);

    s1.display();
    s2.display();
    
    return 0;
}