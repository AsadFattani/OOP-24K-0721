#include <iostream>
#include <stdexcept>
#include <string>

using namespace std;

class NegativeStockException : public exception {};

class OverCapacityException : public exception {};

template <typename T>
class InventoryItem {
private:
    T stock;
    T maxStock;

public:
    InventoryItem(T maxStock) : stock(0), maxStock(maxStock) {}

    void setStock(T newStock) {
        if (newStock < 0) {
            throw NegativeStockException();
        }
        if (newStock > maxStock) {
            throw OverCapacityException();
        }
        stock = newStock;
    }

    T getStock() const {
        return stock;
    }
};

int main() {
    try {
        InventoryItem<int> item(100);
        cout << "Attempting to set stock to -5...\n";
        item.setStock(-5);
    } catch (const NegativeStockException& e) {
        cout << "Caught NegativeStockException - what(): " << e.what() << "\n";
    }

    try {
        InventoryItem<int> item(100);
        cout << "Attempting to set stock to 120 (max 100)...\n";
        item.setStock(120);
    } catch (const OverCapacityException& e) {
        cout << "Caught OverCapacityException - what(): " << e.what() << "\n";
    }

    return 0;
}
