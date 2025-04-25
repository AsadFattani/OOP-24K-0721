#include <iostream>
#include <fstream>
using namespace std;


class FileHandler {
    ifstream inFile;
    string fileName;

    public:
    FileHandler(string name) : fileName(name), inFile(name) {
        if (!inFile) {
            cerr << "Error opening file: " << fileName << endl;
            exit(1);    
        }
    }

    void readData() {
        // string line;
        char c;
        // while (getline(inFile, line)) { // line by line
        //     cout << line ;
        // }
        // while (inFile >> line) {// word by word
        //     cout << line << endl;
        // }
        // while (inFile >> c) {// character by character
        //     cout << c << endl;
        // }
        while (inFile.get(c)) { // character by character by all the stuff
            cout << c ;
        }
    }
};

int main() {
    FileHandler file("example.txt");
    file.readData();

    return 0;
}


