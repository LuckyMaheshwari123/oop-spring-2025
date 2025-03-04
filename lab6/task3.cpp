#include<iostream>
using namespace std;
class Person{
    protected:
    string name;
    int age;
    public:
    Person(string name,int age):name(name),age(age){};
    void display(){
     cout<<"Name: "<<name<<endl;
     cout<<"Age: "<<age<<endl;
    }
};
class Teacher:public Person{
    protected:
    string subject;
    public:
    Teacher(string name,int age,string subject):Person(name,age),subject(subject){}
    void display(){
    Person::display();
    cout<<"Subject:"<<subject<<endl;
    }
};

class Researcher:public Teacher{
    protected:
    string researchArea;
    public:
    Researcher(string name,int age,string subject,string researchArea):Teacher(name,age,subject),researchArea(researchArea){}
    void display(){
    Teacher::display();
    cout<<"reserachArea:"<<researchArea<<endl;
    }
};


class Professor:public Researcher{
    protected:
    int publications;
    public:
    Professor(string name,int age,string subject,string researchArea,int publications):Researcher(name,age,subject,researchArea),publications(publications){}
    void display(){
    Researcher::display();
    cout<<"No of publication is:"<<publications<<endl;
    }
};

int main(){
    Professor p1("Lucky",30,"computer science","AI",10);
    p1.display();

}
