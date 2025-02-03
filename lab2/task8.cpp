#include <iostream>
#include <string>
#include <iomanip> // for formatting output
using namespace std;

// Structure to store product information
struct Product {
    int productID;
    string name;
    int quantity;
    double price;
};


void addProduct(Product *&products, int &size) {
    Product newProduct;

    // Input product details
    cout << "Enter product ID: ";
    cin >> newProduct.productID;
    cin.ignore(); 

    cout << "Enter product name: ";
    getline(cin, newProduct.name);

    cout << "Enter product quantity: ";
    cin >> newProduct.quantity;

    cout << "Enter product price: ";
    cin >> newProduct.price;

   
    Product *temp = new Product[size + 1]; 
    for (int i = 0; i < size; ++i) {
        temp[i] = products[i];
    }

    temp[size] = newProduct; 

    delete[] products; 
    products = temp; 
    size++;
}


void removeProduct(Product *&products, int &size, int productID) {
    int index = -1;
    // Find the product index by ID
    for (int i = 0; i < size; ++i) {
        if (products[i].productID == productID) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        cout << "Product with ID " << productID << " not found!" << endl;
        return;
    }

    // Create a new array with one less element
    Product *temp = new Product[size - 1];
    for (int i = 0, j = 0; i < size; ++i) {
        if (i != index) {
            temp[j++] = products[i];
        }
    }

    delete[] products; 
    products = temp; 
    size--; 
}


void updateProduct(Product *products, int size, int productID) {
    int index = -1;
    // Find the product index by ID
    for (int i = 0; i < size; ++i) {
        if (products[i].productID == productID) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        cout << "Product with ID " << productID << " not found!" << endl;
        return;
    }

    cout << "Updating product with ID: " << productID << endl;
    cout << "Enter new product name: ";
    cin.ignore();
    getline(cin, products[index].name);

    cout << "Enter new product quantity: ";
    cin >> products[index].quantity;

    cout << "Enter new product price: ";
    cin >> products[index].price;
}

// Function to display the inventory
void displayInventory(Product *products, int size) {
    cout << fixed << setprecision(2); 
    cout << "Inventory:\n";
    cout << "-----------------------------------------\n";
    cout << "ID\tName\t\tQuantity\tPrice\tTotal Value\n";
    cout << "-----------------------------------------\n";
    for (int i = 0; i < size; ++i) {
        double totalValue = products[i].quantity * products[i].price;
        cout << products[i].productID << "\t" << products[i].name << "\t\t"
             << products[i].quantity << "\t\t" << products[i].price << "\t" << totalValue << endl;
    }
    cout << "-----------------------------------------\n";
}


double totalInventoryValue(Product *products, int size) {
    double totalValue = 0;
    for (int i = 0; i < size; ++i) {
        totalValue += products[i].quantity * products[i].price;
    }
    return totalValue;
}

int main() {
    Product *products = nullptr; 
    int size = 0; 
    int choice, productID;

    while (true) {
        cout << "\nInventory Management System\n";
        cout << "1. Add Product\n";
        cout << "2. Remove Product\n";
        cout << "3. Update Product\n";
        cout << "4. Display Inventory\n";
        cout << "5. Total Inventory Value\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addProduct(products, size);
                break;
            case 2:
                cout << "Enter product ID to remove: ";
                cin >> productID;
                removeProduct(products, size, productID);
                break;
            case 3:
                cout << "Enter product ID to update: ";
                cin >> productID;
                updateProduct(products, size, productID);
                break;
            case 4:
                displayInventory(products, size);
                break;
            case 5:
                cout << "Total inventory value: $" << totalInventoryValue(products, size) << endl;
                break;
            case 6:
                // Deallocate memory and exit
                delete[] products;
                cout << "Exiting program..." << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
