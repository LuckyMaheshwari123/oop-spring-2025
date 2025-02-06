#include <iostream>
#include <string>

using namespace std;

class Planner {
private:
    
    string tasks[12][31];

public:
    // Constructor to initialize the tasks array to empty strings
    Planner() {
        for (int i = 0; i < 12; ++i) {
            for (int j = 0; j < 31; ++j) {
                tasks[i][j] = "";
            }
        }
    }

    // Method to add a task for a specific day of a month (1-based index for month and day)
    void addTask(int month, int day, string task) {
        if (month < 1 || month > 12 || day < 1 || day > 31) {
            cout << "Invalid month or day!" << endl;
            return;
        }
        tasks[month - 1][day - 1] = task;
        cout << "Task added for month " << month << ", day " << day << ": " << task << endl;
    }

    //  remove a task for a specific day
    void removeTask(int month, int day) {
        if (month < 1 || month > 12 || day < 1 || day > 31) {
            cout << "Invalid month or day!" << endl;
            return;
        }
        tasks[month - 1][day - 1] = "";  // Clear 
        cout << "Task removed for month " << month << ", day " << day << "." << endl;
    }

    //  display all tasks monthly 
    void displayMonthTasks(int month) {
        if (month < 1 || month > 12) {
            cout << "Invalid month!" << endl;
            return;
        }

        cout << "Tasks for month " << month << ":" << endl;
        bool anyTask = false;
        for (int day = 0; day < 31; day++) {
            if (!tasks[month - 1][day].empty()) {
                cout << "Day " << (day + 1) << ": " << tasks[month - 1][day] << endl;
                anyTask = true;
            }
        }

        if (!anyTask) {
            cout << "No tasks scheduled for this month." << endl;
        }
    }

    // Method to display all tasks for all months
    void displayAllTasks() {
        cout << "Displaying all tasks for all months:" << endl;
        bool anyTask = false;
        for (int month = 0; month < 12; ++month) {
            for (int day = 0; day < 31; ++day) {
                if (!tasks[month][day].empty()) {
                    cout << "Month " << (month + 1) << ", Day " << (day + 1) << ": " << tasks[month][day] << endl;
                    anyTask = true;
                }
            }
        }

        if (!anyTask) {
            cout << "No tasks scheduled for any month." << endl;
        }
    }
};

int main() {
    Planner weddingPlanner;

 
    weddingPlanner.addTask(2, 15, "Wedding at Grand Venue");
    weddingPlanner.addTask(3, 22, "Bride's dress fitting");
    weddingPlanner.addTask(5, 10, "Venue inspection for wedding");

    // Display tasks for a specific month
    weddingPlanner.displayMonthTasks(2);  // February

    // Remove a task
    weddingPlanner.removeTask(2, 15);

    // Display all tasks
    weddingPlanner.displayAllTasks();

    return 0;
}
