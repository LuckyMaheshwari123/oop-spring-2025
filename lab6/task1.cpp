#include<iostream>
using namespace std;
class employee{
    string name;
    float salary;
    public:
    employee(string name,float salary):name(name),salary(salary){}
    void display(){
        cout<<"Name:"<<name<<endl;
        cout<<"salary"<<salary<<endl;

    }

};

class Manager:public employee{
    float bonus;
    public:
    Manager(string name,float salary,float bonus):employee(name, salary),bonus(bonus){};
    void details(){
        display();
        cout<<"bonus: "<<bonus<<endl;
    }

};
int main(){
    Manager m1("Lucky",100000,20000);
    m1.details();

}
