#include <iostream>
#include <string>
using namespace std;


struct Student {
    string name;
    int rollNumber;
    float marks[5];  
    float average;
    char grade;
};


void inputStudentDetails(Student &student) {
    cout << "Enter Name: ";
    cin.ignore();  
    getline(cin, student.name);

    cout << "Enter Roll Number: ";
    cin >> student.rollNumber;

   
    float total = 0;
    for (int i = 0; i < 5; i++) {
        cout << "Enter marks for subject " << i + 1 << ": ";
        cin >> student.marks[i];
        total += student.marks[i];
    }

   
    student.average = total / 5;

    
    if (student.average >= 90) {
        student.grade = 'A';
    } 
    else if (student.average >= 80) {
        student.grade = 'B';
    }
    else if (student.average >= 70) {
        student.grade = 'C';
    }
    else if (student.average >= 60) {
        student.grade = 'D';
    }
    else if (student.average >= 50) {
        student.grade = 'E';
    }
    else {
        student.grade = 'F';
    }
}


void displayStudentDetails(Student* students, int numStudents) {
    cout << "\nStudent Results:\n";
    for (int i = 0; i < numStudents; ++i) {
        cout << "\nStudent Name: " << students[i].name << "\n";
        cout << "Roll Number: " << students[i].rollNumber << "\n";
        cout << "Average Marks: " << students[i].average << "\n";
        cout << "Grade: " << students[i].grade << "\n";
    }
}

int main() {
    int numStudents;


    cout << "Enter the number of students: ";
    cin >> numStudents;

  
    Student* students = new Student[numStudents];

  
    for (int i = 0; i < numStudents; ++i) {
        cout << "\nEnter details for student " << i + 1 << ":\n";
        inputStudentDetails(students[i]);
    }

 
    displayStudentDetails(students, numStudents);

 
    delete[] students;

    return 0;
}
