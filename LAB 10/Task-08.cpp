#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

int main() {
    fstream file("config.txt", ios::out);
    if (!file) {
        cerr << "Error creating file." << endl;
        return 1;
    }
    file << "AAAAA" << "BBBBB" << "CCCCC";
    file.close();

    file.open("config.txt", ios::in | ios::out);
    if (!file) {
        cerr << "Error opening file." << endl;
        return 1;
    }

    file.seekp(5, ios::beg);
    if (!file) {
        cerr << "Error seeking position." << endl;
        return 1;
    }

    file << "XXXXX";
    file.close();

    file.open("./LAB 10/config.txt", ios::in);
    if (!file) {
        cerr << "Error reopening file." << endl;
        return 1;
    }

    string content;
    getline(file, content);
    file.close();

    cout << "File content after modification: " << content << endl;

    return 0;
}


