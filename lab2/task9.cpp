#include <iostream>
#include <string>
using namespace std;


struct Student {
    string name;
    int rollNumber;
    double marks;
};


void displayTopStudent(Student *students, int n) {
    if (n == 0) {
        cout << "No students to display." << endl;
        return;
    }

    Student topStudent = students[0];
    for (int i = 1; i < n; ++i) {
        if (students[i].marks > topStudent.marks) {
            topStudent = students[i];
        }
    }

    cout << "Student with the highest marks:\n";
    cout << "Name: " << topStudent.name << endl;
    cout << "Roll Number: " << topStudent.rollNumber << endl;
    cout << "Marks: " << topStudent.marks << endl;
}

int main() {
    int n;

    cout << "Enter the number of students: ";
    cin >> n;

    Student *students = new Student[n];

   
    for (int i = 0; i < n; ++i) {
        cout << "\nEnter details for student " << i + 1 << endl;
        cout << "Enter name: ";
        cin.ignore(); // To clear the input buffer
        getline(cin, students[i].name);
        cout << "Enter roll number: ";
        cin >> students[i].rollNumber;
        cout << "Enter marks: ";
        cin >> students[i].marks;
    }

    
    displayTopStudent(students, n);

    delete[] students;

    return 0;
}
