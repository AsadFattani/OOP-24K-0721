#include <iostream>
using namespace std;

class Product {
    protected:
        int productID;
        string productName;
        int price;
        int stockQuantity;

    public:
        Product(int productID, string productName, int price, int stockQuantity) 
        : productID(productID), productName(productName), price(price), stockQuantity(stockQuantity) {}

        virtual void applyDiscount(){
            // no discount 0%
            cout << "Discount applied to the product." << endl;
        }
        virtual void calculateTotalPrice(int quantity){
            int totalPrice = price * quantity;
            cout << "Total Price for " << quantity << " units: " << totalPrice << endl;
        }
        virtual void displayProductInfo(){
            cout << "Product ID: " << productID << endl;
            cout << "Product Name: " << productName << endl;
            cout << "Price: " << price << endl;
            cout << "Stock Quantity: " << stockQuantity << endl;
        }
};

class Electronics : public Product {
    protected:
        int warrantyPeriod;
        string brand;

    public:
        Electronics (int productID, string productName, int price, int stockQuantity, int warrantyPeriod, string brand) 
        : Product(productID, productName, price, stockQuantity), warrantyPeriod(warrantyPeriod), brand(brand) {}

        void displayProductInfo(){
            Product::displayProductInfo();
            cout << "Warranty Period: " << warrantyPeriod << endl;
            cout << "Brand: " << brand << endl;
        }
};

class Clothing : public Product {
    protected:
        int size;
        string color;
        string fabricMaterial;
    
    public:
        Clothing (int productID, string productName, int price, int stockQuantity, int size, string color, string fabricMaterial) 
        : Product(productID, productName, price, stockQuantity), size(size), color(color), fabricMaterial(fabricMaterial) {}

        void applyDiscount(){
            price -= price * 0.05; // 5 percent for now
        }
};

class FoodItem : public Product {
    protected:
        string expirationDate;
        int calories;
    
    public:
        FoodItem(int productID, string productName, int price, int stockQuantity, string expirationDate, int calories) 
        : Product(productID, productName, price, stockQuantity), expirationDate(expirationDate), calories(calories) {}

        void calculateTotalPrice(int quantity) {
            int totalPrice = price * quantity;
            if (quantity > 10) {
            totalPrice -= totalPrice * 0.10; // 10% discount for bulk purchase
            }
            cout << "Total Price for " << quantity << " units: " << totalPrice << endl;
        }
};

class Book : public Product {
    protected:
        string author;
        string genre;

    public:
        Book(int productID, string productName, int price, int stockQuantity, string author, string genre) 
        : Product(productID, productName, price, stockQuantity), author(author), genre(genre) {}

        void displayProductInfo() {
            Product::displayProductInfo();
            cout << "Author: " << author << endl;
            cout << "Genre: " << genre << endl;
        }
};

int main() {
    Electronics laptop(101, "Laptop", 50000, 10, 24, "Dell");
    laptop.displayProductInfo();
    cout << endl;
    
    Clothing shirt(201, "Shirt", 1500, 50, 42, "Blue", "Cotton");
    shirt.applyDiscount();
    shirt.displayProductInfo();
    cout << endl;
    
    FoodItem chocolate(301, "Chocolate", 200, 100, "2023-12-31", 250);
    chocolate.calculateTotalPrice(15);
    cout << endl;
    
    Book novel(401, "Novel", 800, 20, "J.K. Rowling", "Fantasy");
    novel.displayProductInfo();
    cout << endl;

    return 0;
}



