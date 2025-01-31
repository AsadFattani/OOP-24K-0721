#include <iostream>
using namespace std;

int** dynamicAllocation(int row, int col) {
    int** arr = new int*[row];
    for (int i = 0; i < row; i++) {
        arr[i] = new int[col];
    }
    return arr;
}

void inputArrays(int** arr, int row, int col) {
    cout << "---ARRAY INPUTS---" << endl;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cout << "Enter element for row " << i + 1 << " column " << j + 1 << endl;
            cin >> arr[i][j];
        }
    }
}

void displayArray(int** arr, int row, int col) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

void freeArray(int** arr, int row) {
    for (int i = 0; i < row; i++) {
        delete[] arr[i];
    }
    delete[] arr;
}

int main() {
    int row = 3, col = 3;
    int** arr = dynamicAllocation(row, col);
    inputArrays(arr, row, col);
    displayArray(arr, row, col);
    freeArray(arr, row);
    return 0;
}
