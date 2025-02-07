#include <iostream>
using namespace std;

int** allocateMatrix(int row, int col) {
    int** arr = new int*[row];
    for (int i = 0; i < row; i++) {
        arr[i] = new int[col];
    }
    return arr;
}

void inputMatrix(int** arr, int row, int col) {
    cout << "---ARRAY INPUTS---" << endl;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cout << "Enter element for row " << i + 1 << " column " << j + 1 << ": ";
            cin >> arr[i][j];
        }
    }
}

void displayMatrix(int** arr, int row, int col) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

void matrixMultiplication(int** arr1, int** arr2, int** result, int row1, int col1, int col2) {
    for (int i = 0; i < row1; i++) {
        for (int j = 0; j < col2; j++) {
            result[i][j] = 0;
            for (int k = 0; k < col1; k++) {
                result[i][j] += arr1[i][k] * arr2[k][j];
            }
        }
    }
}

void freeMatrix(int** arr, int row) {
    for (int i = 0; i < row; i++) {
        delete[] arr[i];
    }
    delete[] arr;
}

int main() {
    cout << "Enter the number of rows for matrix 1: ";
    int row1;
    cin >> row1;
    cout << "Enter the number of columns for matrix 1: ";
    int col1;
    cin >> col1;

    cout << "Enter the number of rows for matrix 2: ";
    int row2;
    cin >> row2;
    cout << "Enter the number of columns for matrix 2: ";
    int col2;
    cin >> col2;

    if (col1 != row2) {
        cout << "Matrix multiplication not possible with these dimensions." << endl;
        return 1;
    }

    int** arr1 = allocateMatrix(row1, col1);
    int** arr2 = allocateMatrix(row2, col2);
    int** result = allocateMatrix(row1, col2);

    inputMatrix(arr1, row1, col1);
    inputMatrix(arr2, row2, col2);

    cout << "---MATRIX 1---" << endl;
    displayMatrix(arr1, row1, col1);
    cout << "---MATRIX 2---" << endl;
    displayMatrix(arr2, row2, col2);

    matrixMultiplication(arr1, arr2, result, row1, col1, col2);

    cout << "---RESULT MATRIX---" << endl;
    displayMatrix(result, row1, col2);

    freeMatrix(arr1, row1);
    freeMatrix(arr2, row2);
    freeMatrix(result, row1);

    return 0;
}


