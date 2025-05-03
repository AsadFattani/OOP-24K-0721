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
            string line;
            while (getline(inFile, line)) {
                cout << line << endl;
            }
        }
};

int main() {
    FileHandler file("./LAB 10/vehicles.txt");
    file.readData();

    return 0;
}

