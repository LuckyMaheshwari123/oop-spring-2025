#include<iostream>
using namespace std;
class Account{
protected:
int accountNumber;
float balance;
public:
Account(int accountNumber,float balance):accountNumber(accountNumber),balance(balance){}
void display(){
cout<<"Account Number: "<<accountNumber<<endl;
cout<<"Balance: "<<balance<<endl;
}


};

class Saving: Account{
protected:
float intrestrate;
public:
Saving(int accountNumber,float balance,float intrestrate):Account(accountNumber,balance),intrestrate(intrestrate){}
void display(){
Account::display();
cout<<"Intest rate is "<< intrestrate<<endl;
}


};

class checking:public Account{
protected:
float limit;
public:
checking(int accountNumber,float balance,float limit):Account(accountNumber,balance),limit(limit){}
void display(){
Account::display();
cout<<"Account Limit: "<< limit<<endl;
}


};

int main(){
Saving s1(240,1000.0,8);
s1.display();

checking c1(240,1000.0,800000.0);
c1.display();
}
