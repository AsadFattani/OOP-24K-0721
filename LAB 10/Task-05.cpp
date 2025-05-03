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
                string type, data, id;
                getline(iss, type, ',');
                getline(iss, id, ',');
                getline(iss, data, ',');
                getline(iss, data, ',');
                getline(iss, data, ',');
                size_t index = line.find(":");
                if (index == string::npos) {
                    cerr << "Error: ':' not found in line: " << line << endl;
                    continue;
                }
                if (type == "AutonomousCar") {
                    float version = stof(line.substr(index + 1));
                    cout << "Vehicle ID: " << id << ", Software Version: " << version << endl;
                } else if (type == "ElectricVehicle") {
                    int battery = stoi(line.substr(index + 1));
                    cout << "Vehicle ID: " << id << ", Battery Capacity: " << battery << endl;
                } else if (type == "HybridTruck") {
                    size_t index = line.find(":");
                    size_t index_2 = line.find("|");
                    if (index == string::npos || index_2 == string::npos) {
                        cerr << "Error: ':' or '|' not found in line: " << line << endl;
                        continue;
                    }
                    int cargo = stoi(line.substr(index + 1, index_2 - index - 1));
                    int battery = stoi(line.substr(index_2 + 9));
                    cout << "Vehicle ID: " << id << ", Cargo Capacity: " << cargo << ", Battery Capacity: " << battery << endl;
                }
            }
        }
};

int main() {
    FileHandler file("./LAB 10/vehicles.txt");
    file.readData();

    return 0;
}



