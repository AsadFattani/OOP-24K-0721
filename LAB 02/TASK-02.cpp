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

void matrixAddition(int** arr1, int** arr2, int** result, int row, int col) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            result[i][j] = arr1[i][j] + arr2[i][j];
        }
    }
}

void matrixSubtraction(int** arr1, int** arr2, int** result, int row, int col) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            result[i][j] = arr1[i][j] - arr2[i][j];
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
    cout << "Enter the number of rows: ";
    int row;
    cin >> row;
    cout << "Enter the number of columns: ";
    int col;
    cin >> col;
    
    int** arr1 = allocateMatrix(row, col);
    int** arr2 = allocateMatrix(row, col);
    int** result = allocateMatrix(row, col);

    inputMatrix(arr1, row, col);
    inputMatrix(arr2, row, col);

    cout << "---MATRIX 1---" << endl;
    displayMatrix(arr1, row, col);
    cout << "---MATRIX 2---" << endl;
    displayMatrix(arr2, row, col);

    matrixAddition(arr1, arr2, result, row, col);
    cout << "---ADDITION RESULT---" << endl;
    displayMatrix(result, row, col);

    matrixSubtraction(arr1, arr2, result, row, col);
    cout << "---SUBTRACTION RESULT---" << endl;
    displayMatrix(result, row, col);

    freeMatrix(arr1, row);
    freeMatrix(arr2, row);
    freeMatrix(result, row);
    
    return 0;
}


