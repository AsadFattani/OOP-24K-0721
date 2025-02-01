#include <iostream>
using namespace std;

void allocateStringArray(string **str, int num){
    *str = new string[num];
}

void inputValues (string *str, int num){
    for (int i = 0; i < num; i++){
        cout << "Enter the string " << i + 1 << ": ";
        cin >> str[i];
    }
}

void sortStrings(string *str, int num){
    for (int i = 0; i < num; i++){
        for (int j = i + 1; j < num; j++){
            if (str[i] > str[j]){
                string temp = str[i];
                str[i] = str[j];
                str[j] = temp;
            }
        }
    }
}

void displayValues (string *str, int num){
    cout << "The sorted strings are: ";
    for (int i = 0; i < num; i++){
        cout << str[i];
        if (i < num - 1) {
            cout << ", ";
        }
    }
}

void freeMemory(string *str){
    delete [] str;
}

int main (){
    int num;
    string *str;

    cout << "Enter the number of strings: ";
    cin >> num;

    allocateStringArray(&str, num);
    inputValues(str, num);
    sortStrings(str, num);
    displayValues(str, num);
    freeMemory(str);
}


