#include <iostream>
#include <string>
using namespace std;

class MenuItem {
protected:
    string dishName;
    double price;

public:
    MenuItem(string name, double price) : dishName(name), price(price) {}

    virtual void showDetails()  = 0;
    virtual void prepare()  = 0;
};

class Appetizer : public MenuItem {
public:
    Appetizer(string name, double price) : MenuItem(name, price) {}

    void showDetails() {
        cout << "Appetizer: " << dishName << ", Price: $" << price << endl;
    }

    void prepare() {
        cout << "Preparing appetizer: " << dishName << " (e.g., chopping, mixing, plating)." << endl;
    }
};

// Derived Class MainCourse
class MainCourse : public MenuItem {
public:
    MainCourse(string name, double price) : MenuItem(name, price) {}

    void showDetails() {
        cout << "Main Course: " << dishName << ", Price: $" << price << endl;
    }

    void prepare() {
        cout << "Preparing main course: " << dishName << " (e.g., cooking, seasoning, plating)." << endl;
    }
};

int main() {
    MenuItem* item1 = new Appetizer("Bruschetta", 8.99);
    MenuItem* item2 = new MainCourse("Grilled Salmon", 22.99);

    item1->showDetails();
    item1->prepare();


    return 0;
}
