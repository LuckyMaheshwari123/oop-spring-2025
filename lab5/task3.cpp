#include <iostream>
#include <string>
using namespace std;

class Professor {
private:
    string name;        
    string department;  

public:
    
    Professor(string n, string dept) : name(n), department(dept) {}

    
    void displayDetails() {
        cout << "Professor Name: " << name << endl;
        cout << "Department: " << department << endl;
    }

   
    string getName()  {
        return name;
    }

    string getDepartment()  {
        return department;
    }
};

class University {
private:
    Professor** professors;  //dynamic array
    int totalProfessors;     
    int capacity;           

public:
    
    University(int cap) : totalProfessors(0), capacity(cap) {
        professors = new Professor*[capacity];  
    }

  
    ~University() {
        for (int i = 0; i < totalProfessors; i++) {
            delete professors[i]; 
        }
        delete[] professors; 
    }

    
    void addProfessor(const string& name, const string& department) {
        if (totalProfessors < capacity) {
            professors[totalProfessors] = new Professor(name, department);  
            totalProfessors++;
        } else {
            cout << "University is at full capacity. Cannot add more professors." << endl;
        }
    }

    
    void displayUniversityDetails() const {
        cout << "University Details:" << endl;
        cout << "Total Professors: " << totalProfessors << endl;
        for (int i = 0; i < totalProfessors; i++) {
            professors[i]->displayDetails();  
            cout << "-----------------------------------" << endl;
        }
    }
};

int main() {
    
    University fastUniversity(5);

 
    fastUniversity.addProfessor("Talha Shahid", "AI");
    fastUniversity.addProfessor("Atiya Jokhio", "CS");

   
    fastUniversity.displayUniversityDetails();

    return 0;
}
