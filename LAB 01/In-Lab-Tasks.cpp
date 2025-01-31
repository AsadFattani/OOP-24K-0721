#include <iostream>
using namespace std;

/*------------------TASK-01--------------------*/

const int MAX_SIZE = 5; // constant max size of array(s)

void collectNames (string namesEventOne[], string namesEventTwo[], int sizeOne, int sizeTwo){
    cout << "Enter the names for the first event: " << endl;
    for (int i = 0; i < sizeOne; i++){
        cout << "Enter name " << i + 1 << ": ";
        cin >> namesEventOne[i];
    }
    cout << "Enter the names for the second event: " << endl;
    for (int i = 0; i < sizeTwo; i++){
        cout << "Enter name " << i + 1 << ": ";
        cin >> namesEventTwo[i];
    }
}

/*------------------TASK-02--------------------*/

void attendanceChecker (string namesEventOne[], string namesEventTwo[], int sizeOne, int sizeTwo){
    string name;
    cout << "Enter the name you want to check: ";
    cin >> name;

    for (int i = 0; i < sizeOne; i++){
        if (name == namesEventOne[i]){
            cout << "Present in the first event." << endl;
            return;
        }
    }
    for (int i = 0; i < sizeTwo; i++){
        if (name == namesEventTwo[i]){
            cout << "Present in the second event." << endl;
            return;
        }
    }
}

/*------------------TASK-03--------------------*/

void totalDonations (int sizeOne, int sizeTwo){
    int totalDonation = 10 * (sizeOne + sizeTwo);
    cout << "Total donation is: $" << totalDonation << endl;
}

/*------------------TASK-04--------------------*/

void reverseNamesOrder(string namesEventOne[], string namesEventTwo[], int sizeOne, int sizeTwo){
    cout << "Names of the first event in reverse order: " << endl;
    for (int i = sizeOne - 1; i >= 0; i--){
        cout << namesEventOne[i] << endl;
    }
    cout << "Names of the second event in reverse order: " << endl;
    for (int i = sizeTwo - 1; i >= 0; i--){
        cout << namesEventTwo[i] << endl;
    }
}

/*------------------TASK-05--------------------*/

void eventPopularityBarChart (int sizeOne, int sizeTwo){
    cout << "Event Popularity Bar Chart" << endl;
    cout << "First Event: ";
    for (int i = 0; i < sizeOne; i++){
        cout << "*";
    }
    cout << endl;
    cout << "Second Event: ";
    for (int i = 0; i < sizeTwo; i++){
        cout << "*";
    }
    cout << endl; 

}

int main (){
    int sizeOne, sizeTwo;
    cout << "Enter the number of participants for the first event (max 5): ";
    cin >> sizeOne;
    sizeOne = (sizeOne > MAX_SIZE) ? MAX_SIZE : sizeOne;

    cout << "Enter the number of participants for the second event (max 5): ";
    cin >> sizeTwo;
    sizeTwo = (sizeTwo > MAX_SIZE) ? MAX_SIZE : sizeTwo;

    string namesEventOne[MAX_SIZE]; 
    string namesEventTwo[MAX_SIZE];

    // collectNames(namesEventOne, namesEventTwo, sizeOne, sizeTwo);

    // attendanceChecker(namesEventOne, namesEventTwo, sizeOne, sizeTwo);
    // attendanceChecker(namesEventOne, namesEventTwo, sizeOne, sizeTwo);

    // totalDonations(sizeOne, sizeTwo);
    // reverseNamesOrder(namesEventOne, namesEventTwo, sizeOne, sizeTwo);

    eventPopularityBarChart(sizeOne, sizeTwo);
    return 0;
}
