#include <iostream>
using namespace std;

// Multiple Inheritance
// Not same as multi-level inheritance
// Base1 --> Derived <-- Base2

class Print {
    protected:
         string brand;

    public:
        Print(string brand) : brand(brand) {}

        void print(string document){
            cout << "Printing " << document << "........" << endl;
        }
};

class Scan {
    protected:
        int dpi;

    public:
        Scan(int dpi) : dpi(dpi) {}

        void scan(string document){
            cout << "Scanning " << document << "at " << dpi << " dpi" << "......." << endl;
        }
};

class AllInOnePrinter : public Print, public Scan {
    protected:
        int paperCapacity;

    public:
        AllInOnePrinter(string brand, int dpi, int paperCapacity) : Print(brand), Scan(dpi), paperCapacity(paperCapacity) {}

        void copy(string document){
            scan(document);
            print(document);
            cout << "Paper Capacity: " << paperCapacity << " pages" << endl;
        }
        
};

int main () {
    AllInOnePrinter hp("HP", 300, 100);
    // hp.print("Lab06.pdf");
    // hp.scan("image.jpg");
    hp.copy("image2.jpg");

    return 0;
}

