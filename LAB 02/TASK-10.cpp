#include <iostream>
using namespace std;

int*** allocate3DArray(int row, int col, int depth) {
    int*** arr = new int**[depth];
    for (int i = 0; i < depth; i++) {
        arr[i] = new int*[row];
        for (int j = 0; j < row; j++) {
            arr[i][j] = new int[col];
        }
    }
    return arr;
}

void input3DArray(int*** arr, int row, int col, int depth) {
    cout << "---ARRAY INPUTS---" << endl;
    for (int i = 0; i < depth; i++) {
        cout << "3D Array " << i + 1 << endl;
        for (int j = 0; j < row; j++) {
            for (int k = 0; k < col; k++) {
                cout << "Enter element for row " << j + 1 << " column " << k + 1 << ": ";
                cin >> arr[i][j][k];
            }
        }
    }
}

void display3DArray(int*** arr, int row, int col, int depth) {
    for (int i = 0; i < depth; i++) {
        cout << "3D Array " << i + 1 << endl;
        for (int j = 0; j < row; j++) {
            for (int k = 0; k < col; k++) {
                cout << arr[i][j][k] << " ";
            }
            cout << endl;
        }
    }
}

void free3DArray(int*** arr, int row, int depth) {
    for (int i = 0; i < depth; i++) {
        for (int j = 0; j < row; j++) {
            delete[] arr[i][j];
        }
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
    cout << "Enter the number of depths: ";
    int depth;
    cin >> depth;

    int*** arr = allocate3DArray(row, col, depth);
    input3DArray(arr, row, col, depth);
    display3DArray(arr, row, col, depth);
    free3DArray(arr, row, depth);
    return 0;
}

