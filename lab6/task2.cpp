#include<iostream>
using namespace std;
class Vehicle{
    string brand;
    int speed;
    public:
    Vehicle(string brand,int speed):brand(brand),speed(speed){};
    void display(){
        cout<<brand<<endl;
        cout<<speed<<endl;
    }
};

class car:public Vehicle{
    int seats;
    public:
    car(string brand ,int speed,int seats):Vehicle(brand,speed),seats(seats){}
    void disp(){
        display();
        cout<<seats<<endl;
    }


};

class ev:public car{
    int life;
    public:
    ev(string brand ,int speed,int seats,int life):car(brand,speed,seats),life(life){}
    void displ(){
       
        disp();
        cout<<life<<endl;
    }


};
int main(){
    ev e1("toyota",200,8,12);
    e1.displ();

}
