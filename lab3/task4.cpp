#include<iostream>
using namespace std;
class Laptop{
    string brand;
    string model;
    string processor;
    int Ram;
    int storage;
    bool powerStatus;
    public:
   Laptop(string br,string mod,string proc,int ram,int store){
    brand=br;
    model=mod;
    processor=proc;
    Ram=ram;
    storage=store;
    powerStatus=false;


   }
   void turnOn() {
        if (!powerStatus) {
            powerStatus = true;
            cout << brand << " " << model << " is now ON." << endl;
        } else {
            cout << brand << " " << model << " is already ON." << endl;
        }
    }
    void turnOff() {
        if (powerStatus) {
            powerStatus = false;
            cout << brand << " " << model << " is now OFF." << endl;
        } else {
            cout << brand << " " << model << " is already OFF." << endl;
        }
    }
     void checkSpec() {
        cout << "Details of " << brand << " " << model << ":" << endl;
        cout << "Processor: " << processor << endl;
        cout << "Ram: " << Ram << " GB" << endl;
        cout << "Storage: " << storage << " GB" << endl;
        cout << "Power Status: " << (powerStatus ? "ON" : "OFF") << endl;
    }
    void runProgram(string programName) {
        if (powerStatus) {
            cout << "Running " << programName << " on " << brand << " " << model << "..." << endl;
        } else {
            cout << "Please turn on " << brand << " " << model << " before running any programs." << endl;
        }
    }

};

int main(){
    Laptop bl("Dell", "XPS 15", "Intel i7", 16, 512);
    Laptop al("HP", "Spectre x360", "Intel i5", 8, 256);
    bl.checkSpec();
    al.checkSpec();

    al.turnOn();
    al.runProgram("vscode");
    bl.turnOn();
    bl.runProgram("vscode");
    al.turnOff();
    bl.turnOff();




    return 0;
}
