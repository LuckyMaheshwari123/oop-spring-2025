#include <iostream>
#include <string>

using namespace std;


struct Employee {
    int employeeID;
    string name;
    string department;
    float salary;
};


void inputEmployeeDetails(Employee &emp) {
    cout << "\nEnter Employee ID: ";
    cin >> emp.employeeID;
    cin.ignore(); //ignore the newline after this

    cout << "Enter Name: ";
    getline(cin, emp.name);

    cout << "Enter Department: ";
    getline(cin, emp.department);

    cout << "Enter Salary: ";
    cin >> emp.salary;
}


void displayEmployees(Employee* employees, int numEmployees) {
    cout << "\nEmployee Details:\n";
    for (int i = 0; i < numEmployees; i++) {
        cout << "\nEmployee ID: " << employees[i].employeeID << "\n";
        cout << "Name: " << employees[i].name << "\n";
        cout << "Department: " << employees[i].department << "\n";
        cout << "Salary: " << employees[i].salary << "\n";
    }
}


void searchEmployeeByID(Employee* employees, int numEmployees, int searchID) {
    int found = 0;
    for (int i = 0; i < numEmployees; ++i) {
        if (employees[i].employeeID == searchID) {
            cout << "\nEmployee Found:\n";
            cout << "Employee ID: " << employees[i].employeeID << "\n";
            cout << "Name: " << employees[i].name << "\n";
            cout << "Department: " << employees[i].department << "\n";
            cout << "Salary: " << employees[i].salary << "\n";
            found = 1;
            break;
        }
    }
    if (!found) {
        cout << "\nEmployee with ID " << searchID << " not found.\n";
    }
}

int main() {
    int numEmployees, searchID;

    
    cout << "Enter the number of employees: ";
    cin >> numEmployees;

   
    Employee* employees = new Employee[numEmployees];

   
    for (int i = 0; i < numEmployees; ++i) {
        cout << "\nEnter details for employee " << (i + 1) << ":\n";
        inputEmployeeDetails(employees[i]);
    }

    
    displayEmployees(employees, numEmployees);

    
    cout << "\nEnter Employee ID to search: ";
    cin >> searchID;
    searchEmployeeByID(employees, numEmployees, searchID);

   
    delete[] employees;

    return 0;
}
