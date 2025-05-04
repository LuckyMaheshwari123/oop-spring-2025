#include<iostream>

#include<fstream>

#include<string>

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

            cout<<line<<endl;

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
