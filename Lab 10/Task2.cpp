#include<iostream>

#include<fstream>

#include<string>

#include<sstream>

using namespace std;

class Read{

    ifstream file;

    string filename;

    public:

    Read(string filename):filename(filename){

        file.open(filename);

    }

    bool isOpen(){

        return file.is_open();

    }

    void display(){

        string line;

        while(getline(file,line)){

            istringstream iss(line);

            string type,id,name,year,data,certification;

        getline(iss, type, ',');

    getline(iss, id, ',');

    getline(iss, name, ',');

    getline(iss, year, ',');

    getline(iss, data, ',');

    getline(iss, certification, ',');

            cout<<type<<endl;

            cout<<id<<endl;

            cout<<name<<endl;

            cout<<year<<endl;

            cout<<data<<endl;

            cout<<certification<<endl;

    

        }

    }

    ~Read(){

        if(file.is_open()){

            file.close();

        }

    }

    

};

int main(){

    Read r1("vehicles.txt");

    if(r1.isOpen()){

        r1.display();

    }

    else{

        cout<<"File Not found"<<endl;

    }

    return 0;

}
