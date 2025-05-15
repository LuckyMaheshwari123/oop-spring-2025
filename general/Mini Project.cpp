#include<iostream>
#include<fstream>
using namespace std;
class VehicleManager;//forward deleare
class Tentary{
double fuel;
double consumption;
double speed;
bool status;
public:
Tentary(double fuel,double consumption, double speed,bool status=false):fuel(fuel), consumption(consumption),speed(speed),status(status){};
void display (){
cout<<"Fuel consume:"<<fuel<<endl;
cout<<"consumption rate per hour:"<<consumption<<endl;
cout<<"speed per hour:"<<speed<<endl;
cout<<"Engine status:";
if(status){
cout<<"ON"<<endl;
}
else{
cout<<"OFF"<<endl;
}


}
};
class Vehicle{
protected:
string VehicleId;
string model;
string fuelType;
string currentLocation;
Tentary t1;
public:
Vehicle(double fuel,double consumption, double speed,bool status, string VehicleId,string model, string fuelType, string currentLocation):
t1(fuel, consumption,speed,status),VehicleId(VehicleId),model(model),fuelType(fuelType),currentLocation(currentLocation){};
virtual void display(){
t1.display();
cout<<"Vehicle id is:"<<VehicleId<<endl;
cout<<"Model is:"<<model<<endl;
cout<<"fuel type is:"<<fuelType<<endl;
cout<<"current Location is:"<<currentLocation<<endl;

}
void updateLocation(const string& newLocation){
currentLocation=newLocation;
cout<<"Location updated"<<endl;
}
string getid() const{
return VehicleId;
}
friend class VehicleManager;
};


class VehicleManager {
public:
    void trackVehiceLocation(Vehicle &v){
        cout<<"The Location is:"<<v.currentLocation<<endl;
        cout<<"The id is:"<<v.getid()<<endl;
    }

    void WriteToFile(Vehicle* vehicles[], int size){
        ofstream file("vehicle_info.txt");
        for(int i = 0; i < size; ++i){
            file << vehicles[i]->VehicleId << "," << vehicles[i]->model << "," << vehicles[i]->fuelType
                 << "," << vehicles[i]->currentLocation << endl;
        }
        file.close();
        cout << "Data written to file successfully." << endl;
    }

    void ReadFromFile(){
        ifstream file("vehicle_info.txt");
        string line;
        cout << "\nVehicles in Karachi:\n";
        while(getline(file, line)){
            size_t pos = line.rfind(',');
            if(pos != string::npos){
                string location = line.substr(pos + 1);
                if(location == "Karachi"){
                    cout << line << endl;
                }
            }
        }
        file.close();
    }
};



class MeterReading: public Vehicle{
int capacity;
public:
MeterReading(double fuel,double consumption, double speed,bool status, string VehicleId,string model, string fuelType, string currentLocation,int capacity):
Vehicle(fuel,consumption,speed,status,  VehicleId,model, fuelType,currentLocation),capacity(capacity){};
void display(){
Vehicle:: display ();
cout<<"capacity is:"<<capacity<<endl;
}
};




class Inspection: public Vehicle{
int range;
public:
Inspection(double fuel,double consumption, double speed,bool status, string VehicleId,string model, string fuelType, string currentLocation,int range):
Vehicle(fuel,consumption,speed,status,  VehicleId,model, fuelType,currentLocation), range(range){};
void display(){
Vehicle::display ();
cout<<"Inspection range is:"<<range<<endl;
}
};


class Equipment: public Vehicle{
int ecapacity;
public:
Equipment(double fuel,double consumption, double speed,bool status, string VehicleId,string model, string fuelType, string currentLocation,int  ecapacity):
Vehicle(fuel,consumption,speed,status,  VehicleId,model, fuelType,currentLocation), ecapacity(ecapacity){};
void display(){
Vehicle:: display ();
cout<<"Equipment capacity is:"<<ecapacity<<endl;
}
};
int main(){
MeterReading m1(20,5,60,true,"102","cl","petrol","Karachi",10);
Inspection i1(30,6,70,true,"103","alto","diesel","Lahore",20);
Equipment e1(60,7,70,true,"104","Toyota","petrol","Mithi",30);
VehicleManager Manager;
m1.display();
Manager.trackVehiceLocation(m1);

cout<<"Hello world"<<endl;
}

    
