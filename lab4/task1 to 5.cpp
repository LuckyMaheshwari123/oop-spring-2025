#include <iostream>
using namespace std;
class Book{
    string title;
    double price;
    int *stock=new int;
    public:
    Book(){
        title="unknnown";
        price=0.0;
        *stock=30;
    }
    int trackrecord(){
      return *stock;
    }
    void update(string ti,double p,int st){
        title=ti;
        price=p;
        *stock=st;
    }
    void purchaseBook(int books){

        if(books>*stock){
        cout<<"Not enough stock"<<endl ;
        return; 
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
    Book(string ti,double p,int st){
        title=ti;
        price=p;
        *stock=st;

    }
    void applyDiscount(int books){
        if(books>=5){
            price=price-(price*0.05);
            
        }
        else if(books>=10){
            price=price-(price*0.05);
        }
    }
    void stockValidation(int books){
        if(books>*stock){
            cout<<"Not enough stock"<<endl;
        }
    

    }
    

    Book(const Book& other) {
        title = other.title;
        price = other.price;
        stock = other.stock;

    }

    ~Book() {
        cout << "Book '" << title <<   " is being destroyed.\n";
    }


    void calculatePrice(int quantity) {
        double basePrice = price;
        applyDiscount(quantity);
        if (quantity > 5) {
            cout << "Applied discount. New price: $" << price << endl;
        }
        if (quantity > 10) {
            cout << "Applied bulk discount. New price: $" << price << endl;
        }
    }

void displayBookDetails() {
        cout << "Title: " << title << endl;
        cout << "Price: $" << price << endl;
        cout << "Stock: " << *stock << " units\n";
    }

    string getTitle() { return title; }
    double getPrice() { return price; }
    int getStock() { return *stock; }



};
int main() {
    Book book1;
    book1.displayBookDetails();
    cout<<endl;
    book1.update("How to program",1000,50);
    book1.displayBookDetails();
    cout<<endl;
    Book book2("rich dad poor dad",8000,80);
    book2.displayBookDetails();

    book1.purchaseBook(10);
    cout<<endl;
    book1.purchaseBook(50);
    cout<<endl;
    book1.applyDiscount(6);
    cout<<endl;
    Book book3=book2;
    book3.displayBookDetails();
    cout<<endl;

    book3.update("C++ Best Practices", 19.99, 50);
    cout << "\nModified Book 3 Details (After Modification):\n";
    book3.displayBookDetails();
    cout << "\nBook 2 Details (Unchanged):\n";
    book2.displayBookDetails();
    book2.calculatePrice(12);

    book1.displayBookDetails();
    book2.displayBookDetails();
    book3.displayBookDetails();



    return 0;
}
