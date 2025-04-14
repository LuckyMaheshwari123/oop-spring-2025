#include<iostream>
using namespace std;
class PaymentMethod{
    public:
    virtual void processPayment(double amount)=0;
};
class CreditCard:PaymentMethod{
 string cardNumber;
 public:
 CreditCard(){
    cardNumber="unknown";
 }
 CreditCard(string cardNumber):cardNumber(cardNumber){}
 void processPayment(double amount){
    if(amount<=0){
        cout<<"The invalid Amount"<<endl;
    
    }
    else{
        cout<<"Amount has been processed successfully"<<endl;
    }
 }
};
class DigitalWallet:public PaymentMethod{
    double balance;
    public:
    DigitalWallet(){
        balance=0.0;
    }
    DigitalWallet(double balance):balance(balance){}
    void processPayment(double amount){
        if(amount<=0 || amount>balance){
            cout<<"invlaid amount"<<endl;
        }
        else{
            balance-=amount;
            cout<<"Amount has been dectucted successfully"<<endl;
        }
    }

};
int main(){
    CreditCard c1("123456789");
    DigitalWallet d1(50000);
    d1.processPayment(-890);
    c1.processPayment(-980);
    c1.processPayment(2000);
    d1.processPayment(3600);




}
