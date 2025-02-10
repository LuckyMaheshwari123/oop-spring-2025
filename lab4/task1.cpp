#include <iostream>
using namespace std;
class Book{
    string title;
    double price;
    int *stock=new int;
    public:
    Book(){
        title="unknown";
        price=0.0;
        *stock=30;
    }
    Book(string ti,double p,int st){
        title=ti;
        price=p;
        *stock=st;
    }
    void discount(){    
    }
    void update(string ti,double p,int st){
        title=ti;
        price=p;
        *stock=st;
    }
    void trackstock(){
       cout<<"The stock level is "<<*stock<<endl;
    }
    void simulate(int books){
        if(books>*stock){
        cout<<"Not enough stock"<<endl ;  
        return ;      
        } 
        if(*stock<=5){
            cout<<"Low stock warning";
            return;
        }
        else{
        cout<<"books successfully purchased"<<endl;
        *stock-=books;
        }
    }
    void display(){
        cout<<"Book Tittle:"<<title<<endl<<"Book price:"<<price<<endl<<"stock:"<<*stock<<endl;
    }


};
int main() {
    Book b1;
    b1.simulate(50);
   // b1.trackstock();
    b1.update("rich dad poor dad",1000,60);
    b1.simulate(20);
    b1.display();
    return 0;
}
