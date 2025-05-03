#include <iostream>
#include <fstream>

using namespace std;

class InventoryItem {
    public:
        int itemID;
        char itemName[20];
};

int main() {
    InventoryItem item = {101, "Laptop"};
    ofstream outFile("./LAB 10/inventory.dat", ios::binary);
    outFile.write((char*)&item, sizeof(item));
    outFile.close();
    
    InventoryItem readItem;
    ifstream inFile("./LAB 10/inventory.dat", ios::binary);
    inFile.read((char*)&readItem, sizeof(readItem));
    inFile.close();

    cout << "Item ID: " << readItem.itemID << endl;
    cout << "Item Name: " << readItem.itemName << endl;

    return 0;

}


