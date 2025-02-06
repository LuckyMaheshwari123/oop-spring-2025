#include <iostream>
using namespace std;
class TeaMug{
    string brand;
    string color;
    double capacity;
    double currentLevel;
    
    public:
    // Constructor to initialize the mug
    TeaMug(string b, string c, double cap) {
        brand = b;
        color = c;
        capacity = cap;
        currentLevel = cap; // initially the mug is full
    }
    
    void sipTea(double amount){
        if(currentLevel==0 ){
            cout<<"your tea mug is empty.Please refill"<<endl;
            return;
        }
        else if(amount>currentLevel){
            cout<<"You have not enough tea to sip"<<endl;
        }
        else{
            currentLevel-=amount;
            cout<<"sip taken successfully"<<endl;
        }
    }
    
        void refill(){
            if(currentLevel==0){
                currentLevel+=capacity;
                cout<<"Refilled successfully"<<endl;
            }
            else{
                cout<<"your tea mag is not empty"<<endl;
            }
        }
        bool isEmpty() {
        if (currentLevel <= 0) {
            cout << "The mug is empty! Time for a fresh cup of tea!" << endl;
            return true;
        } else {
            return false;
        }
    }

    double checkLevel() {
        return currentLevel;
    }

    void displayDetails() {
        cout << "Mug Brand: " << brand << ", Color: " << color << ", Capacity: " << capacity << "  Current Fill Level: " << currentLevel << "" << endl;
    }
    
    
};

int main()
{
    string braand,coolor;
    double capa,level;
    cout<<"Enter the brand of tea mug:";
    cin>>braand;
    cout<<"Enter the color of tea mug:";
    cin>>coolor;
    cout<<"Enter the capacity of tea mug:";
    cin>>capa;
    TeaMug T1(braand,coolor,capa);
    int choice;
    while(choice!=6){
        cout<<endl<<"Enter 1 for sip tea\nEnter 2  for check the level\nEnter 3 for check if mug is empty or not\nEnter 4 to refill\nEnter 5 for dispaly the details\nEnter 6 for exit\nEnter choice:";
        cin>>choice;
        switch(choice){
            case 1:
            double amount;
            cout<<"enter amount you want to sip the tea"<<endl;
            cin>>amount;
            T1.sipTea(amount);
            break;
            case 2:
            cout<<"The current level is "<<T1.checkLevel()<<endl;
            break;
            case 3:
            if(T1.isEmpty()) cout<<"cup is empty"<<endl;
            else cout<<"cup is not empty"<<endl;
            break;
            case 4:
            T1.refill();
            break;
            case 5:
            T1.displayDetails();
            break;
            case 6:
            cout<<"Exiting....."<<endl;
            break;
            default:
            cout<<"Invalid choice"<<endl;
            
            
        }
    }
    

    return 0;
}
