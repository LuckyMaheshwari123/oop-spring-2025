#include<iostream>
using namespace std;
class Activity{
    public:
    virtual double calculateCaloriesBurned()=0;
};
class Running:Activity{
    double distance;
    double time;
    public:
    Running(){
        distance=0.0;
        time=0.0;
    }
    Running(double distance,double minutes):distance(distance),time(time){}
    double calculateCaloriesBurned(){
        double calories;
        calories=0.6*(distance/time);
        return calories;
        
    }

};
class Cycling{
double speed;
double time;
public:
Cycling(){
    speed=0.0;
    time=0.0;
}
Cycling(double speed,double time):speed(speed),time(time){};
double calculateCaloriesBurned(){
    double calories;
    calories=0.6*speed*time;
    return calories;
}
};
int main(){
    Running r1(25,10);
    cout<<"The calories burned from Running:"<<r1.calculateCaloriesBurned()<<endl;
    Cycling c1(25,5);
    cout<<"The calories burned from cycling:"<<c1.calculateCaloriesBurned()<<endl;


}
