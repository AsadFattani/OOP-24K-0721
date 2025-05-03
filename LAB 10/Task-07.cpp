#include <iostream>
#include <fstream>
using namespace std;


int main() {
    ofstream outFile("./LAB 10/sensor_log.txt");
    if (!outFile) {
        cerr << "Error opening file!" << endl;
        return 1;
    }

    outFile << "Sensor 1: 25.5 C\n";
    cout << "Position after first write: " << outFile.tellp() << endl;

    outFile << "Sensor 2: 98.1 %RH\n";
    cout << "Position after second write: " << outFile.tellp() << endl;

    outFile.close();
    cout << "File closed successfully." << endl;

    return 0;
}
