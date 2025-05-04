#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

class InventoryItem {
public:
    int itemId;
    char itemName[20];
};

int main() {
    InventoryItem item1;
    item1.itemId = 101;
    strcpy(item1.itemName, "Screwdriver");

    ofstream outFile("inventory.dat", ios::binary);
    outFile.write((char*)&item1, sizeof(item1));
    outFile.close();

    InventoryItem item2;

    ifstream inFile("inventory.dat", ios::binary);
    inFile.read((char*)&item2, sizeof(item2));
    inFile.close();

    cout << "Loaded Item ID: " << item2.itemId << endl;
    cout << "Loaded Item Name: " << item2.itemName << endl;

    return 0;
}
