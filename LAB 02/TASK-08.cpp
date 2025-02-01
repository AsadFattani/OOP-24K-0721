#include <iostream>
using namespace std;

void allocateArray(int **array, int size) {
    *array = new int[size];
}


void inputValues (int* array, int size) {
    for (int i = 0; i < size; ++i) {
        cout << "Enter value for element " << i + 1 << ": ";
        cin >> array[i];
    }
}

void displayArray(int* array, int size) {
    cout << "Array elements are: ";
    for (int i = 0; i < size; ++i) {
        cout << array[i];
        if (i < size - 1) {
            cout << ", ";
        }
    }
    cout << endl;
}

void freeMemory(int* array, int size) {
    delete[] array;
}

int main() {
    int size, *array;
    cout << "Enter the size of the array: ";
    cin >> size;
    
    allocateArray(&array, size);
    inputValues(array, size);
    displayArray(array, size);
    freeMemory(array, size);
    return 0;
}






