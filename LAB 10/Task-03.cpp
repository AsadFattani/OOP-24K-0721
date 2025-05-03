#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

class FileHandler {
    ifstream inFile;
    string fileName;
    istringstream iss;

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
                istringstream iss(line);
                string type, id, name, year, extraData, certification;
                int intyear;

                getline(iss, type, ',');
                getline(iss, id, ',');
                getline(iss, name, ',');
                getline(iss, year, ',');
                getline(iss, extraData, ',');
                getline(iss, certification, ',');

                try { // to avoid errors
                    intyear = stoi(year);
                    cout << "Year in integer: " << intyear << endl;
                } catch (invalid_argument& e) {
                    cerr << "Invalid year format!" << endl;
                    continue;
                }
            }    
        }
};

int main() {
    FileHandler file("./LAB 10/vehicles.txt");
    file.readData();

    return 0;
}



