#include <iostream>
using namespace std;

class FitnessTracker {
    private:
        string userName = "Laiba";
        int dailyStepsGoal = 10000, stepsTaken, caloriesBurned = 0;
    
    public:
        void logSteps(int steps) {
            stepsTaken = steps;
            caloriesBurned = stepsTaken / 20;
            cout << "Steps logged successfully" << endl;
        }
        void calculateCaloriesBurned() {
            caloriesBurned += stepsTaken * 0.04; // Assuming 0.04 calories burned per step
            cout << "Calories burned: " << caloriesBurned << endl;
        }
        void printDailyProgress() {
            cout << "--- Daily Progress ---" << endl;
            cout << "User Name: " << userName << endl;
            cout << "Steps Taken: " << stepsTaken << endl;
            cout << "Calories Burned: " << caloriesBurned << endl;
            cout << "Daily Steps Goal: " << dailyStepsGoal << endl;
            cout << "Goal Achieved: " << (stepsTaken >= dailyStepsGoal ? "Yes" : "No") << endl;
            cout << endl;
        }
};

int main() {
    FitnessTracker myTracker;
    
    while (true) {
        cout << "1. Log Steps" << endl;
        cout << "2. Print Daily Progress" << endl;
        cout << "0. Exit" << endl;
        
        int choice;
        cout << "Enter choice: ";
        cin >> choice;
        
        switch (choice) {
            case 1: {
                int steps;
                cout << "Enter steps taken: ";
                cin >> steps;
                myTracker.logSteps(steps);
                break;
            }
            case 2:
                myTracker.printDailyProgress();
                break;
                case 0:
                return 0;
            default:
                cout << "Invalid choice" << endl;
                break;
        }
    }
    return 0;
}

