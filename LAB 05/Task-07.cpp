#include <iostream>
using namespace std;

class Product {
    public:
        int id;
        string name;
        int quantity;
    
        Product(int id, string name, int quantity) : id(id), name(name), quantity(quantity) {}
};

class Inventory {
    private:
        Product* products[100];
        int productCount;

    public:
        Inventory() : productCount(0) {}

        void addProduct(int id, string name, int quantity) {
            products[productCount++] = new Product(id, name, quantity);
        }

        void sortProductsByName() {
            for (int i = 0; i < productCount - 1; ++i) {
                for (int j = i + 1; j < productCount; ++j) {
                    if (products[i]->name > products[j]->name) {
                        Product* temp = products[i];
                        products[i] = products[j];
                        products[j] = temp;
                    }
                }
            }
        }

        void searchProductById(int id) {
            for (int i = 0; i < productCount; ++i) {
                if (products[i]->id == id) {
                    cout << "Product found! ID: " << products[i]->id << ", Name: " << products[i]->name << ", Quantity: " << products[i]->quantity << endl;
                    return;
                }
            }
            cout << "Product not found." << endl;
        }

        void displayProducts() {
            for (int i = 0; i < productCount; ++i) {
                cout << "ID: " << products[i]->id << ", Name: " << products[i]->name << ", Quantity: " << products[i]->quantity << endl;
            }
        }
};

int main() {
    Inventory inventory;
    inventory.addProduct(1, "Chair", 50);
    inventory.addProduct(2, "Laptop", 30);
    inventory.addProduct(3, "Apple", 100);

    cout << "Products before sorting:" << endl;
    inventory.displayProducts();

    inventory.sortProductsByName();
    cout << endl << "Products after sorting by name:" << endl;
    inventory.displayProducts();

    cout << endl << "Searching for product with ID 2:" << endl;
    inventory.searchProductById(2);

    return 0;
}




