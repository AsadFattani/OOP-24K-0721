#include <iostream>
#include <fstream>
using namespace std;

class FileHandler {
    ofstream outFile;
    string fileName;

    public:
    FileHandler(string name) : fileName(name), outFile(name) {
        if (!outFile) {
            cerr << "Error opening file: " << fileName << endl;
            exit(1);    
        }
    }

    void writeData (string data) {
        outFile << data << endl;
    }
    
};

int main() {
    FileHandler file("example.txt");
    file.writeData("Hello, World!");
    file.writeData("This is a test.");
    return 0;
}




