#include <iostream>
using namespace std;

struct Products {
    int productID;
    string name;
    int quantity;
    int price;
};

void allocateArray(Products **array, int size) {
    *array = new Products[size];
}

void inputValues(Products* array, int size) {
    for (int i = 0; i < size; ++i) {
        cout << "---Details of the Product " << i + 1 << "---" << endl;
        cout << "Enter product ID for product " << i + 1 << ": ";
        cin >> array[i].productID;
        cout << "Enter name for product " << i + 1 << ": ";
        cin >> array[i].name;
        cout << "Enter quantity for product " << i + 1 << ": ";
        cin >> array[i].quantity;
        cout << "Enter price for product " << i + 1 << ": ";
        cin >> array[i].price;
    }
}

void valueOfInventory(Products* array, int size) {
    int totalValue = 0;
    for (int i = 0; i < size; ++i) {
        totalValue += array[i].quantity * array[i].price;
    }
    cout << "Total value of inventory is: $" << totalValue << endl;
}

void freeMemory(Products* array, int size) {
    delete[] array;
}

int main() {
    int size;
    Products* array;
    cout << "Enter the total number of products: ";
    cin >> size;

    allocateArray(&array, size);
    inputValues(array, size);
    valueOfInventory(array, size);
    freeMemory(array, size);
    return 0;
}
