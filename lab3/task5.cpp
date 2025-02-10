#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
class GroceryStore{
    private:
    static const int maxitems=100;
    struct Item{
        string name;
        double price;

    };
   Item inventory[maxitems];
   int count;
   public:
   GroceryStore(){
    count=0;
   }
   void addItem(const string& Itemname,double Itemprice){
    if(count<maxitems){
        inventory[count].name=Itemname;
        inventory[count].price=Itemprice;
        count++;
        cout << "Item added: " << Itemname << " at price $" << Itemprice << endl;
        } else {
            cout << "Inventory full, can't add more items!" << endl;
        }
    }
     void updatePrice(const string& itemName, double newPrice) {
        
        for (int i = 0; i < count; i++) {
            if (inventory[i].name == itemName) {
                inventory[i].price = newPrice;
                cout << "Price updated for " << itemName << " to $" << newPrice << endl;
                return;
            }
        }
        cout << "Item " << itemName << " not found!" << endl;
    }
    void viewInventory() const {
        cout << "\nInventory:\n";
        for (int i = 0; i < count; i++) {
            cout << "Item: " << inventory[i].name << ", Price: $" << fixed << setprecision(2) << inventory[i].price << endl;
        }
        cout << endl;
    }
    void generateReceipt(const string purchasedItems[], int purchasedCount) {
        double total = 0;
        cout << "\nReceipt:\n";
        cout << "------------------------------------\n";
        for (int i = 0; i < purchasedCount; i++) {
            bool found = false;
            for (int j = 0; j < count; j++) {
                if (inventory[j].name == purchasedItems[i]) {
                    cout << inventory[j].name << " - $" << fixed << setprecision(2) << inventory[j].price << endl;
                    total += inventory[j].price;
                    found = true;
                    break;
                }
            }
            if (!found) {
                cout << "Item " << purchasedItems[i] << " not found in inventory.\n";
            }
        }
        cout << "------------------------------------\n";
        cout << "Total: $" << fixed << setprecision(2) << total << endl;
        cout << "Thank you for shopping at our store!\n";
    }
};
   


int main() {
    GroceryStore store;
    store.addItem("Apple", 1.50);
    store.addItem("Banana", 0.80);
    store.addItem("Milk", 2.20);
    store.addItem("Eggs", 3.00);
    store.viewInventory();

    store.updatePrice("Banana", 0.90);
    store.viewInventory();
    string purchasedItems[] = {"Apple", "Milk", "Eggs"};
    int purchasedCount = 3;
    store.generateReceipt(purchasedItems, purchasedCount);
    return 0;
}
