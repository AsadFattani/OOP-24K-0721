#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ofstream outfile("large_log.txt");
    if (!outfile) {
        cerr << "Error creating file." << endl;
        return 1;
    }
    outfile << "This is the first part of the log.\n";
    outfile << "This is the second part of the log.\n";
    outfile << "And the third part.\n";
    outfile.close();

    ifstream infile("./LAB 10/large_log.txt");
    if (!infile) {
        cerr << "Error opening file." << endl;
        return 1;
    }

    char buffer[11] = {0};
    infile.read(buffer, 10);
    cout << "Read: " << buffer << endl;
    cout << "Current position after first read: " << infile.tellg() << endl;

    infile.read(buffer, 10);
    cout << "Read: " << buffer << endl;
    cout << "Current position after second read: " << infile.tellg() << endl;

    infile.close();

    return 0;
}




