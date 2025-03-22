#include <iostream>
using namespace std;

int abc (int x, int y = 0){
    return x + y;
}

float abc (float x, float y){
    return x + y;
}

// int abc(int x){
//     return x;
// }

int main(){
    cout << "abc(): " << abc(5, 6) << endl;
    cout << "abc(): " << abc(5, 10.5) << endl;
    return 0;
}


