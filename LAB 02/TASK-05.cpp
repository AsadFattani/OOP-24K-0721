#include <iostream>
using namespace std;

void inputArray(int* arr, int n) {
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; ++i) {
        cin >> *(arr + i);
    }
}

void displayArray(int* arr, int n) {
    cout << "Array elements are: ";
    for (int i = 0; i < n; ++i) {
        cout << *(arr + i) << " ";
    }
    cout << endl;
}

int sumArray(int* arr, int n) {
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        sum += *(arr + i);
    }
    return sum;
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    int* arr = new int[n];
    inputArray(arr, n);
    displayArray(arr, n);

    int sum = sumArray(arr, n);
    cout << "Sum of array elements: " << sum << endl;

    delete[] arr;
    return 0;
}






