#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

const int CITIES = 4;
const int DAYS = 28;

void collectDate(int AQI[CITIES][DAYS]){
    for (int i = 0; i < CITIES; i++){
        cout << "\n---AQI for city " << i + 1 << "---" << endl;
        for (int j = 0; j < DAYS; j++){
            int value;
            do {
                cout << "Enter the AQI for day " << j + 1 << " (0-500): ";
                cin >> value;
                if (value < 0 || value > 500) {
                    cout << "Invalid AQI value. Please enter a value between 0 and 500." << endl;
                }
            } while (value < 0 || value > 500);
            AQI[i][j] = value;
        }
    }
}

void generateRandomAQI(int AQI[CITIES][DAYS]) {
    srand(time(0));
    for (int i = 0; i < CITIES; i++) {
        for (int j = 0; j < DAYS; j++) {
            AQI[i][j] = rand() % 491 + 10; // Random value between 10 and 500
        }
    }
}

void averageAQI(int AQI[CITIES][DAYS]){
    cout << "\n--Average AQI for each city--" << endl;
    int sum = 0, average = 0, highestAQI = 0, city = 0;
    for (int i = 0; i < CITIES; i++){
        sum = 0;
        for (int j = 0; j < DAYS; j++){
            sum += AQI[i][j];
        }
        average = sum / DAYS;
        cout << "Average AQI for city " << i + 1 << ": " << average << endl;
        if (average > highestAQI){
            highestAQI = average;
            city = i + 1;
        }
    }
    cout << "City with the worst air quality is city " << city << " with an average AQI of " << highestAQI << endl;
}

void criticalPollutionDays(int AQI[CITIES][DAYS]) {
    cout << "\n--Critical Pollution Days (AQI > 150)--" << endl;
    for (int i = 0; i < CITIES; i++) {
        cout << "City " << i + 1 << ": ";
        bool hasCriticalDays = false;
        bool first = true;
        for (int j = 0; j < DAYS; j++) {
            if (AQI[i][j] > 150) {
                if (first) {
                    cout << "Day " << j + 1;
                    first = false;
                } else {
                    cout << ", Day " << j + 1;
                }
                hasCriticalDays = true;
            }
        }
        if (!hasCriticalDays) {
            cout << "None";
        }
        cout << endl;
    }
}

void visualizeAQI(int AQI[CITIES][DAYS]) {
    cout << "\n--AQI Visualization--" << endl;
    for (int i = 0; i < CITIES; i++) {
        cout << "City " << i + 1 << ": ";
        for (int j = 0; j < DAYS; j++) {
            if (j != 0) {
                cout << " | ";
            }
            int stars = AQI[i][j] / 50;
            for (int k = 0; k < stars; k++) {
                cout << "*";
            }
        }
        cout << endl;
    }
}

void monthlyAverageAQI(int AQI[CITIES][DAYS]) {
    cout << "\n--Monthly Average AQI for each city--" << endl;
    for (int i = 0; i < CITIES; i++) {
        int sum = 0;
        for (int j = 0; j < DAYS; j++) {
            sum += AQI[i][j];
        }
        int average = sum / DAYS;
        cout << "Monthly average AQI for city " << i + 1 << ": " << average << endl;
    }
}

void mostImprovedCity(int AQI[CITIES][DAYS]) {
    cout << "\n--City with Most Improved Air Quality--" << endl;
    int maxImprovement = 0;
    int improvedCity = 0;
    for (int i = 0; i < CITIES; i++) {
        int firstWeekSum = 0, lastWeekSum = 0;
        for (int j = 0; j < 7; j++) {
            firstWeekSum += AQI[i][j];
            lastWeekSum += AQI[i][DAYS - 7 + j];
        }
        int firstWeekAvg = firstWeekSum / 7;
        int lastWeekAvg = lastWeekSum / 7;
        int improvement = firstWeekAvg - lastWeekAvg;
        if (improvement > maxImprovement) {
            maxImprovement = improvement;
            improvedCity = i + 1;
        }
    }
    cout << "City with the most improved air quality is city " << improvedCity << " with an improvement of " << maxImprovement << " AQI points." << endl;
}

void generateReport(int AQI[CITIES][DAYS]) {
    cout << "\n--AQI Report--" << endl;
    cout << "\n--Weekly Averages for Each City--" << endl;
    for (int i = 0; i < CITIES; i++) {
        cout << "City " << i + 1 << ":" << endl;
        for (int week = 0; week < 4; week++) {
            int sum = 0;
            for (int day = 0; day < 7; day++) {
                sum += AQI[i][week * 7 + day];
            }
            int average = sum / 7;
            cout << "  Week " << week + 1 << ": " << average << endl;
        }
    }

    cout << "\n--Critical Pollution Days for Each City--" << endl;
    for (int i = 0; i < CITIES; i++) {
        cout << "City " << i + 1 << ": ";
        bool hasCriticalDays = false;
        bool first = true;
        for (int j = 0; j < DAYS; j++) {
            if (AQI[i][j] > 150) {
                if (first) {
                    cout << "Day " << j + 1;
                    first = false;
                } else {
                    cout << ", Day " << j + 1;
                }
                hasCriticalDays = true;
            }
        }
        if (!hasCriticalDays) {
            cout << "None";
        }
        cout << endl;
    }

    cout << "\n--Highest and Lowest AQI Values Recorded During the Month--" << endl;
    for (int i = 0; i < CITIES; i++) {
        int highestAQI = AQI[i][0];
        int lowestAQI = AQI[i][0];
        for (int j = 1; j < DAYS; j++) {
            if (AQI[i][j] > highestAQI) {
                highestAQI = AQI[i][j];
            }
            if (AQI[i][j] < lowestAQI) {
                lowestAQI = AQI[i][j];
            }
        }
        cout << "City " << i + 1 << ": Highest AQI = " << highestAQI << ", Lowest AQI = " << lowestAQI << endl;
    }
}

int main(){
    int AQI[CITIES][DAYS];

    generateRandomAQI(AQI);

    // collectDate(AQI);
    averageAQI(AQI);
    criticalPollutionDays(AQI);
    visualizeAQI(AQI);
    monthlyAverageAQI(AQI);
    mostImprovedCity(AQI);
    generateReport(AQI);

    return 0;
}




