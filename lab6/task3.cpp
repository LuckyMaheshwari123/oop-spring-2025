/*
Classes & Members
1. Base Class: Person
o Data Members: name (string), age (int)
o Member Functions: displayDetails()
2. Derived Class: Teacher
o Data Member: subject (string)
o Member Functions: displayDetails()
3. Derived Class: Researcher
o Data Member: researchArea (string)
o Member Functions: displayDetails()
4. Derived Class: Professor
o Data Member: publications (int)
o Member Functions: displayDetails()
*/
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
    cout<<subject<<endl;
    }
};


int main(){

}
