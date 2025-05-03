#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

int main(){
    ofstream outFile("./LAB 10/data_records.txt");
    if (!outFile) {
        cerr << "Error opening file!" << endl;
        return 1;
    }
    outFile << "Record 1\n";
    outFile << "Record 2\n";
    outFile << "Record 3\n";
    outFile << "Record 4\n";
    outFile.close();

    ifstream inFile("./LAB 10/data_records.txt");
    if (!inFile) {
        cerr << "Error opening file!" << endl;
        return 1;
    }

    inFile.seekg(20, ios::beg);
    string line;
    getline(inFile, line);
    cout << "Read from file: " << line << endl;

    inFile.close();

}