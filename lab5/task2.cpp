

#include <iostream>
#include <string>
using namespace std;

class Patient {
private:
    int patientID;       
    string name;      
    double* testResults;  //array with dma
    int numResults;     

public:
    
    Patient(int id, string n, double* results, int num) : patientID(id), name(n), numResults(num) {
        testResults = new double[numResults]; 
        for (int i = 0; i < numResults; i++) {
            testResults[i] = results[i];  
        }
    }

    // Copy constructor 
    Patient(const Patient& other) {
        patientID = other.patientID;
        name = other.name;
        numResults = other.numResults;

        // Allocate new memory 
        testResults = new double[numResults];
        for (int i = 0; i < numResults; i++) {
            testResults[i] = other.testResults[i];
        }
    }

   
    ~Patient() {
        delete[] testResults;  
    }

    
    void displayDetails() const {
        cout << "Patient ID: " << patientID << endl;
        cout << "Name: " << name << endl;
        cout << "Test Results: ";
        for (int i = 0; i < numResults; i++) {
            cout << testResults[i] << " ";
        }
        cout << endl;
    }
};

int main() {
   
    double results1[] = {98.6, 99.1, 97.5, 98.4};

    
    Patient patient1(101, "Lucky", results1, 4);

    cout << "Original Patient Details: " << endl;
    patient1.displayDetails();
    cout << endl;

    
    Patient patient2 = patient1; 

 
    double results2[] = {97.4, 98.3, 96.9, 97.8};
    Patient patient3(102, "kumar", results2, 4); 

    cout << "Copied Patient Details (New): " << endl;
    patient2.displayDetails();
    cout << endl;

    
    cout << "Original Patient Details after copying: " << endl;
    patient1.displayDetails();
    cout << endl;

  
    cout << "Another Patient Details: " << endl;
    patient3.displayDetails();

    return 0;
}
