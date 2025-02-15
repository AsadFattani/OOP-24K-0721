#include <iostream>
using namespace std;

class shallowCopy {
    public:
        int *data = new int;

        shallowCopy(int num){
            *data = num;
        }

        shallowCopy(shallowCopy &obj){
            data = obj.data;
        }

        void display(){
            cout << "Data: " << *data << endl;
            cout << "Addresse " << data << endl;
        }
};

int main(){
    shallowCopy s1(5);
    shallowCopy s2(s1);

    s1.display();
    s2.display();
    
    return 0;
}



